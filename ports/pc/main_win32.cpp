/**
 * Pokémon Gen 3 - Native PC Desktop Port
 * True 16:9 Widescreen • Startup Carousel • DirectSound Audio • Debug Menu (F1)
 * Built with native Win32 / GDI / WaveOut (Zero External Dependencies)
 */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <shellapi.h>
#include <mmsystem.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include "pokegen3.h"

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")

// Window Dimensions (Default 16:9 Widescreen)
#define WINDOW_WIDTH  1280
#define WINDOW_HEIGHT 720

// State
static PokeEngine* g_engine = NULL;
static bool g_running = true;
static bool g_fullscreen = false;
static RECT g_window_rect;
static bool g_show_debug = false;
static bool g_show_qol = false;
static HWND g_hwnd = NULL;

// Double Buffering State (Eliminates Glitches & Flickering)
static HDC     g_memDC   = NULL;
static HBITMAP g_memBmp  = NULL;
static HBITMAP g_oldBmp  = NULL;
static int     g_memW    = 0;
static int     g_memH    = 0;

// Pre-Created GDI Fonts (Cached for smooth 60 FPS rendering)
static HFONT   g_hTitleFont = NULL;
static HFONT   g_hGameFont  = NULL;
static HFONT   g_hSubFont   = NULL;
static HFONT   g_hNavFont   = NULL;
static HFONT   g_hBadgeFont = NULL;

// ROM Path Configuration
static const char* g_rom_paths[5] = {
    "roms/pokemon-emerald.gba",
    "roms/pokemon-emerald.gba",
    "roms/pokemon-firered.gba",
    "roms/pokemon-ruby.gba",
    "roms/pokemon-sapphire.gba"
};

static const char* g_rom_names[5] = {
    "Pokemon Combined Journey (Emerald + FireRed)",
    "Pokemon Emerald Version",
    "Pokemon FireRed Version",
    "Pokemon Ruby Version",
    "Pokemon Sapphire Version"
};

static bool check_rom_exists(int idx) {
    if (idx < 0 || idx >= 5) return false;
    FILE* f = fopen(g_rom_paths[idx], "rb");
    if (f) {
        fclose(f);
        return true;
    }
    return false;
}

static void prompt_dump_rom(HWND hwnd, int idx) {
    char msg[600];
    snprintf(msg, sizeof(msg),
        "Legal ROM Ingestion & Asset Setup Required\n\n"
        "To play %s and extract authentic game assets, please dump your legally obtained "
        "GBA cartridge and place the ROM file into:\n\n"
        "  -> %s\n\n"
        "Expected Rom Names:\n"
        "  * pokemon-emerald.gba\n"
        "  * pokemon-firered.gba\n"
        "  * pokemon-ruby.gba\n"
        "  * pokemon-sapphire.gba\n\n"
        "Would you like to open the 'roms' folder now to place your ROM?",
        g_rom_names[idx], g_rom_paths[idx]
    );
    int res = MessageBoxA(hwnd, msg, "Pokemon Gen 3 Port - ROM Asset Ingestion", MB_ICONINFORMATION | MB_YESNO);
    if (res == IDYES) {
        CreateDirectoryA("roms", NULL);
        ShellExecuteA(NULL, "open", "roms", NULL, NULL, SW_SHOWNORMAL);
    }
}

// Audio Streaming (WaveOut 48kHz Stereo)
#define AUDIO_BUF_COUNT 4
#define AUDIO_BUF_SIZE  1024
static HWAVEOUT g_hWaveOut = NULL;
static WAVEHDR  g_waveHeaders[AUDIO_BUF_COUNT];
static int16_t  g_audioBuffers[AUDIO_BUF_COUNT][AUDIO_BUF_SIZE * 2];
static int      g_currentAudioBuf = 0;

static void init_audio(void) {
    WAVEFORMATEX wfx;
    memset(&wfx, 0, sizeof(wfx));
    wfx.wFormatTag = WAVE_FORMAT_PCM;
    wfx.nChannels = 2;
    wfx.nSamplesPerSec = POKE_AUDIO_SAMPLERATE;
    wfx.wBitsPerSample = 16;
    wfx.nBlockAlign = wfx.nChannels * (wfx.wBitsPerSample / 8);
    wfx.nAvgBytesPerSec = wfx.nSamplesPerSec * wfx.nBlockAlign;

    if (waveOutOpen(&g_hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL) == MMSYSERR_NOERROR) {
        for (int i = 0; i < AUDIO_BUF_COUNT; ++i) {
            memset(&g_waveHeaders[i], 0, sizeof(WAVEHDR));
            g_waveHeaders[i].lpData = (LPSTR)g_audioBuffers[i];
            g_waveHeaders[i].dwBufferLength = AUDIO_BUF_SIZE * 2 * sizeof(int16_t);
            waveOutPrepareHeader(g_hWaveOut, &g_waveHeaders[i], sizeof(WAVEHDR));
        }
    }
}

static void update_audio(void) {
    if (!g_hWaveOut || !g_engine) return;

    WAVEHDR* hdr = &g_waveHeaders[g_currentAudioBuf];
    if (hdr->dwFlags & WHDR_DONE || !(hdr->dwFlags & WHDR_PREPARED)) {
        float float_samples[AUDIO_BUF_SIZE * 2];
        size_t read_count = poke_get_audio_samples(g_engine, float_samples, AUDIO_BUF_SIZE * 2);

        int16_t* dst = g_audioBuffers[g_currentAudioBuf];
        for (size_t i = 0; i < AUDIO_BUF_SIZE * 2; ++i) {
            if (i < read_count) {
                float s = float_samples[i];
                if (s > 1.0f) s = 1.0f;
                if (s < -1.0f) s = -1.0f;
                dst[i] = (int16_t)(s * 32767.0f);
            } else {
                dst[i] = 0;
            }
        }

        waveOutWrite(g_hWaveOut, hdr, sizeof(WAVEHDR));
        g_currentAudioBuf = (g_currentAudioBuf + 1) % AUDIO_BUF_COUNT;
    }
}

static void toggle_fullscreen(HWND hwnd) {
    g_fullscreen = !g_fullscreen;
    if (g_fullscreen) {
        GetWindowRect(hwnd, &g_window_rect);
        SetWindowLong(hwnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);
        int w = GetSystemMetrics(SM_CXSCREEN);
        int h = GetSystemMetrics(SM_CYSCREEN);
        SetWindowPos(hwnd, HWND_TOP, 0, 0, w, h, SWP_FRAMECHANGED);
    } else {
        SetWindowLong(hwnd, GWL_STYLE, WS_OVERLAPPEDWINDOW | WS_VISIBLE);
        SetWindowPos(hwnd, HWND_TOP, g_window_rect.left, g_window_rect.top,
                     g_window_rect.right - g_window_rect.left,
                     g_window_rect.bottom - g_window_rect.top, SWP_FRAMECHANGED);
    }
}

// Win32 Message Handler
static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static uint16_t key_mask = 0;

    switch (msg) {
        case WM_ERASEBKGND:
            return 1; // Prevent window background repaint flicker

        case WM_KEYDOWN: {
            switch (wParam) {
                case VK_UP:    case 'W': key_mask |= POKE_KEY_UP; break;
                case VK_DOWN:  case 'S': key_mask |= POKE_KEY_DOWN; break;
                case VK_LEFT:  case 'A':
                    if (g_engine && poke_get_active_game(g_engine) == POKE_GAME_NONE) {
                        poke_carousel_prev(g_engine);
                    }
                    key_mask |= POKE_KEY_LEFT;
                    break;
                case VK_RIGHT: case 'D':
                    if (g_engine && poke_get_active_game(g_engine) == POKE_GAME_NONE) {
                        poke_carousel_next(g_engine);
                    }
                    key_mask |= POKE_KEY_RIGHT;
                    break;
                case 'X':      case 'K': key_mask |= POKE_KEY_A; break;
                case 'Z':      case 'J': key_mask |= POKE_KEY_B; break;
                case VK_RETURN: case VK_SPACE:
                    if (g_engine && poke_get_active_game(g_engine) == POKE_GAME_NONE) {
                        int sel = poke_carousel_get_selected_index(g_engine);
                        if (!check_rom_exists(sel)) {
                            prompt_dump_rom(hwnd, sel);
                            return 0;
                        }
                        ShellExecute(NULL, "open", "pokeemerald.exe", NULL, NULL, SW_SHOWNORMAL);
                        g_running = false;
                        PostQuitMessage(0);
                        return 0;
                    }
                    key_mask |= POKE_KEY_START;
                    break;
                case VK_BACK:  case VK_SHIFT: key_mask |= POKE_KEY_SELECT; break;
                case 'Q':                 key_mask |= POKE_KEY_L; break;
                case 'E':                 key_mask |= POKE_KEY_R; break;

                case VK_F1:
                case VK_OEM_3: // Tilde ~
                    g_show_debug = !g_show_debug;
                    break;

                case VK_F2: // Legal ROM Dump / Asset Folder Prompt
                    if (g_engine) {
                        int sel = poke_carousel_get_selected_index(g_engine);
                        prompt_dump_rom(hwnd, sel);
                    }
                    break;

                case 'P': // Port Ferry Trigger
                    if (g_engine) {
                        PokeRegion next_reg = (poke_get_current_region(g_engine) == POKE_REGION_HOENN) ?
                                              POKE_REGION_KANTO : POKE_REGION_HOENN;
                        poke_transfer_region(g_engine, next_reg, true);
                    }
                    break;

                case VK_F11:
                    toggle_fullscreen(hwnd);
                    break;

                case VK_ESCAPE:
                    // Return to Carousel or exit
                    if (poke_get_active_game(g_engine) != POKE_GAME_NONE) {
                        poke_create(); // Return to carousel
                    }
                    break;
            }
            if (g_engine) poke_set_input(g_engine, key_mask);
            return 0;
        }

        case WM_KEYUP: {
            switch (wParam) {
                case VK_UP:    case 'W': key_mask &= ~POKE_KEY_UP; break;
                case VK_DOWN:  case 'S': key_mask &= ~POKE_KEY_DOWN; break;
                case VK_LEFT:  case 'A': key_mask &= ~POKE_KEY_LEFT; break;
                case VK_RIGHT: case 'D': key_mask &= ~POKE_KEY_RIGHT; break;
                case 'X':      case 'K': key_mask &= ~POKE_KEY_A; break;
                case 'Z':      case 'J': key_mask &= ~POKE_KEY_B; break;
                case VK_RETURN:          key_mask &= ~POKE_KEY_START; break;
                case VK_BACK:  case VK_SHIFT: key_mask &= ~POKE_KEY_SELECT; break;
                case 'Q':                 key_mask &= ~POKE_KEY_L; break;
                case 'E':                 key_mask &= ~POKE_KEY_R; break;
            }
            if (g_engine) poke_set_input(g_engine, key_mask);
            return 0;
        }

        case WM_DESTROY:
            g_running = false;
            PostQuitMessage(0);
            return 0;

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    timeBeginPeriod(1); // 1ms timer precision

    // Register Window Class
    WNDCLASSEX wc;
    memset(&wc, 0, sizeof(wc));
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = "PokemonGen3PCClass";
    RegisterClassEx(&wc);

    // Calculate Client Rect for 1280x720 16:9 Window
    RECT wr = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

    HWND hwnd = CreateWindowEx(
        0, "PokemonGen3PCClass",
        "Pokemon: Xtreme-Speed - Native PC Port (Combined / Emerald / FireRed / Ruby / Sapphire)",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT,
        wr.right - wr.left, wr.bottom - wr.top,
        NULL, NULL, hInstance, NULL
    );
    g_hwnd = hwnd;

    // Create Pre-Cached GDI Fonts
    g_hTitleFont = CreateFontA(36, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Segoe UI");
    g_hGameFont  = CreateFontA(28, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Segoe UI");
    g_hSubFont   = CreateFontA(18, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Segoe UI");
    g_hNavFont   = CreateFontA(16, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Segoe UI");
    g_hBadgeFont = CreateFontA(14, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Segoe UI");

    // Create Engine Instance
    g_engine = poke_create();
    poke_set_aspect_ratio(g_engine, POKE_ASPECT_WIDESCREEN_16_9);

    // Load BIOS
    poke_load_bios_file(g_engine, "gba_bios/gba_bios.bin");

    // Register All 4 ROMs
    poke_register_rom_file(g_engine, POKE_GAME_EMERALD,  "roms/pokemon-emerald.gba");
    poke_register_rom_file(g_engine, POKE_GAME_FIRERED,  "roms/pokemon-firered.gba");
    poke_register_rom_file(g_engine, POKE_GAME_RUBY,     "roms/pokemon-ruby.gba");
    poke_register_rom_file(g_engine, POKE_GAME_SAPPHIRE, "roms/pokemon-sapphire.gba");
    poke_register_rom_file(g_engine, POKE_GAME_COMBINED, "roms/pokemon-emerald.gba");

    // If game requested directly from command line, launch native source port directly
    if (lpCmdLine && strlen(lpCmdLine) > 0) {
        if (strstr(lpCmdLine, "emerald") || strstr(lpCmdLine, "combined") || strstr(lpCmdLine, "firered") || strstr(lpCmdLine, "ruby") || strstr(lpCmdLine, "sapphire")) {
            ShellExecute(NULL, "open", "pokeemerald.exe", NULL, NULL, SW_SHOWNORMAL);
            return 0;
        }
    }

    init_audio();

    HDC hdc = GetDC(hwnd);

    // GDI Bitmap Info for 426x240 Framebuffer
    BITMAPINFO bmi;
    memset(&bmi, 0, sizeof(bmi));
    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth = POKE_WIDE_16_9_WIDTH;
    bmi.bmiHeader.biHeight = -POKE_WIDE_16_9_HEIGHT; // Top-down
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biCompression = BI_RGB;

    LARGE_INTEGER freq, last_time, cur_time;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&last_time);
    double target_frame_time = 1.0 / 59.73; // Authentic GBA framerate

    const char* names[5] = {
        "[ Pokemon Xtreme-Speed: Combined Journey ]",
        "[ Pokemon Emerald Version ]",
        "[ Pokemon FireRed Version ]",
        "[ Pokemon Ruby Version ]",
        "[ Pokemon Sapphire Version ]"
    };
    const char* subs[5] = {
        "Hoenn -> Vermilion Port Kanto Circuit (Surge -> Blue -> Red) * Dynamic Level Caps",
        "Rayquaza & Battle Frontier - Modern QoL Suite - Native 60 FPS Widescreen",
        "Kanto Classic Journey - Sevii Islands & Team Rocket Campaign",
        "Groudon & Team Magma - Authentic Hoenn Region Campaign",
        "Kyogre & Team Aqua - Authentic Hoenn Region Campaign"
    };

    MSG msg;
    while (g_running) {
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) g_running = false;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        // Run Engine Frame
        poke_run_frame(g_engine);
        update_audio();

        // Render Framebuffer to Screen via Smooth Double-Buffering
        const uint32_t* fb = poke_get_framebuffer(g_engine);
        if (fb) {
            RECT cr;
            GetClientRect(hwnd, &cr);
            int win_w = cr.right - cr.left;
            int win_h = cr.bottom - cr.top;

            if (win_w > 0 && win_h > 0) {
                // Ensure Memory DC & Bitmap match window dimensions
                if (!g_memDC) {
                    g_memDC = CreateCompatibleDC(hdc);
                }
                if (win_w != g_memW || win_h != g_memH || !g_memBmp) {
                    if (g_memBmp) {
                        SelectObject(g_memDC, g_oldBmp);
                        DeleteObject(g_memBmp);
                    }
                    g_memW = win_w;
                    g_memH = win_h;
                    g_memBmp = CreateCompatibleBitmap(hdc, win_w, win_h);
                    g_oldBmp = (HBITMAP)SelectObject(g_memDC, g_memBmp);
                }

                // 1. Stretch Framebuffer into Memory Backbuffer
                SetStretchBltMode(g_memDC, COLORONCOLOR);
                StretchDIBits(
                    g_memDC,
                    0, 0, win_w, win_h,
                    0, 0, POKE_WIDE_16_9_WIDTH, POKE_WIDE_16_9_HEIGHT,
                    fb, &bmi, DIB_RGB_COLORS, SRCCOPY
                );

                // 2. Draw Typography & Overlays onto Backbuffer (Zero Flicker)
                if (poke_get_active_game(g_engine) == POKE_GAME_NONE) {
                    SetBkMode(g_memDC, TRANSPARENT);
                    
                    // Main Header with Drop Shadow
                    SelectObject(g_memDC, g_hTitleFont);
                    RECT headShadow = {2, 32, win_w + 2, 77};
                    SetTextColor(g_memDC, RGB(2, 6, 23));
                    DrawTextA(g_memDC, "POK\xC9MON: XTREME-SPEED", -1, &headShadow, DT_CENTER | DT_SINGLELINE);
                    RECT headRect = {0, 30, win_w, 75};
                    SetTextColor(g_memDC, RGB(255, 255, 255));
                    DrawTextA(g_memDC, "POK\xC9MON: XTREME-SPEED", -1, &headRect, DT_CENTER | DT_SINGLELINE);

                    int sel = poke_carousel_get_selected_index(g_engine);
                    bool rom_exists = check_rom_exists(sel);

                    // Selected Game Name
                    SelectObject(g_memDC, g_hGameFont);
                    RECT selShadow = {2, win_h - 178, win_w + 2, win_h - 138};
                    SetTextColor(g_memDC, RGB(10, 15, 30));
                    DrawTextA(g_memDC, names[sel], -1, &selShadow, DT_CENTER | DT_SINGLELINE);
                    RECT selRect = {0, win_h - 180, win_w, win_h - 140};
                    SetTextColor(g_memDC, RGB(251, 191, 36)); // Warm Gold
                    DrawTextA(g_memDC, names[sel], -1, &selRect, DT_CENTER | DT_SINGLELINE);

                    // Subtitle / Features
                    SelectObject(g_memDC, g_hSubFont);
                    RECT subShadow = {1, win_h - 139, win_w + 1, win_h - 104};
                    SetTextColor(g_memDC, RGB(2, 6, 23));
                    DrawTextA(g_memDC, subs[sel], -1, &subShadow, DT_CENTER | DT_SINGLELINE);
                    RECT subRect = {0, win_h - 140, win_w, win_h - 105};
                    SetTextColor(g_memDC, RGB(148, 163, 184)); // Slate text
                    DrawTextA(g_memDC, subs[sel], -1, &subRect, DT_CENTER | DT_SINGLELINE);

                    // Navigation & ROM Ingestion Status Prompt
                    SelectObject(g_memDC, g_hNavFont);
                    RECT navShadow = {1, win_h - 51, win_w + 1, win_h - 17};
                    SetTextColor(g_memDC, RGB(2, 6, 23));
                    if (rom_exists) {
                        DrawTextA(g_memDC, "[ENTER / SPACE] Launch Game  *  [A / D] Browse  *  [F1] Debug & QoL  *  [F2] Dump/Asset Folder", -1, &navShadow, DT_CENTER | DT_SINGLELINE);
                        RECT navRect = {0, win_h - 52, win_w, win_h - 18};
                        SetTextColor(g_memDC, RGB(226, 232, 240));
                        DrawTextA(g_memDC, "[ENTER / SPACE] Launch Game  *  [A / D] Browse  *  [F1] Debug & QoL  *  [F2] Dump/Asset Folder", -1, &navRect, DT_CENTER | DT_SINGLELINE);
                    } else {
                        DrawTextA(g_memDC, "[!] ROM MISSING: Press [ENTER] or [F2] to Dump Legally Obtained ROM into 'roms/' folder", -1, &navShadow, DT_CENTER | DT_SINGLELINE);
                        RECT navRect = {0, win_h - 52, win_w, win_h - 18};
                        SetTextColor(g_memDC, RGB(239, 68, 68)); // Warning Red
                        DrawTextA(g_memDC, "[!] ROM MISSING: Press [ENTER] or [F2] to Dump Legally Obtained ROM into 'roms/' folder", -1, &navRect, DT_CENTER | DT_SINGLELINE);
                    }
                }

                // 3. Atomic Single BitBlt to Screen (Hardware Backbuffer Flip)
                BitBlt(hdc, 0, 0, win_w, win_h, g_memDC, 0, 0, SRCCOPY);
            }
        }

        // Frame Rate Limiter (60 FPS)
        QueryPerformanceCounter(&cur_time);
        double elapsed = (double)(cur_time.QuadPart - last_time.QuadPart) / (double)freq.QuadPart;
        if (elapsed < target_frame_time) {
            DWORD sleep_ms = (DWORD)((target_frame_time - elapsed) * 1000.0);
            if (sleep_ms > 0) Sleep(sleep_ms);
        }
        QueryPerformanceCounter(&last_time);
    }

    // Cleanup Double-Buffering
    if (g_memDC) {
        if (g_memBmp) {
            SelectObject(g_memDC, g_oldBmp);
            DeleteObject(g_memBmp);
        }
        DeleteDC(g_memDC);
    }

    // Cleanup GDI Fonts
    if (g_hTitleFont) DeleteObject(g_hTitleFont);
    if (g_hGameFont)  DeleteObject(g_hGameFont);
    if (g_hSubFont)   DeleteObject(g_hSubFont);
    if (g_hNavFont)   DeleteObject(g_hNavFont);
    if (g_hBadgeFont) DeleteObject(g_hBadgeFont);

    ReleaseDC(hwnd, hdc);
    if (g_hWaveOut) waveOutClose(g_hWaveOut);
    poke_destroy(g_engine);
    timeEndPeriod(1);
    return 0;
}
