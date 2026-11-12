#ifdef _WIN32
#include <windows.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>
#endif
#include <stdbool.h>
#include <stdio.h>

#include "soh_menu.h"
#include "global.h"
#include "main.h"
#include "platform.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/heal_locations.h"
#include "constants/map_groups.h"
#include "constants/species.h"
#include "constants/pokedex.h"
#include "pokemon.h"
#include "pokedex.h"
#include "item.h"
#include "money.h"
#include "overworld.h"
#include "event_data.h"

#ifdef _WIN32

// Global Cheats & Enhancements
bool8 gCheatWalkThroughWalls = FALSE;
bool8 gCheat100PercentCatch = FALSE;
bool8 gEnhanceInstantText = TRUE;
bool8 gEnhanceAutoRun = TRUE;

// External engine variables from sdl2.c
extern bool paused;
extern double timeScale;
extern bool speedUp;
extern SDL_AudioDeviceID sdlAudioDevice;
extern void DoSoftReset(void);
extern void Platform_StoreSaveFile(void);
extern void HealPlayerParty(void);

// Menu Command IDs
#define ID_GAME_PAUSE               1001
#define ID_GAME_SPEED_1X            1002
#define ID_GAME_SPEED_2X            1003
#define ID_GAME_SPEED_4X            1004
#define ID_GAME_SPEED_8X            1005
#define ID_GAME_QUICKSAVE           1006
#define ID_GAME_RESET               1007
#define ID_GAME_EXIT                1008

#define ID_GFX_BORDER_TOGGLE        2001
#define ID_GFX_INTEGER_SCALE        2002
#define ID_GFX_SCALE_2X             2003
#define ID_GFX_SCALE_3X             2004
#define ID_GFX_SCALE_4X             2005
#define ID_GFX_SCALE_5X             2006
#define ID_GFX_FULLSCREEN           2007
#define ID_GFX_VSYNC                2008

#define ID_AUDIO_VOL_100            3001
#define ID_AUDIO_VOL_75             3002
#define ID_AUDIO_VOL_50             3003
#define ID_AUDIO_VOL_25             3004
#define ID_AUDIO_VOL_MUTE           3005

#define ID_ENH_INSTANT_TEXT         4001
#define ID_ENH_AUTORUN              4002
#define ID_ENH_100CATCH             4003
#define ID_ENH_HIDE_MENU            4004

#define ID_CHEAT_GHOST_MODE         5001
#define ID_CHEAT_MAX_MONEY          5002
#define ID_CHEAT_GIVE_RARE_CANDY    5003
#define ID_CHEAT_GIVE_MASTER_BALL   5004
#define ID_CHEAT_HEAL_PARTY         5005
#define ID_CHEAT_MAX_IVS_EVS        5006
#define ID_CHEAT_ALL_HOENN_BADGES   5007
#define ID_CHEAT_ALL_KANTO_BADGES   5008
#define ID_CHEAT_COMPLETE_POKEDEX   5009
#define ID_CHEAT_EVENT_TICKETS      5010
#define ID_CHEAT_SET_GAME_CLEAR     5011

#define ID_WARP_LITTLEROOT          6001
#define ID_WARP_PETALBURG           6002
#define ID_WARP_RUSTBORO            6003
#define ID_WARP_DEWFORD             6004
#define ID_WARP_SLATEPORT           6005
#define ID_WARP_MAUVILLE            6006
#define ID_WARP_LAVARIDGE           6007
#define ID_WARP_FALLARBOR           6008
#define ID_WARP_FORTREE             6009
#define ID_WARP_LILYCOVE            6010
#define ID_WARP_MOSSDEEP            6011
#define ID_WARP_SOOTOPOLIS          6012
#define ID_WARP_EVER_GRANDE         6013
#define ID_WARP_BATTLE_FRONTIER     6014

#define ID_WARP_SLATEPORT_HARBOR    6101
#define ID_WARP_LILYCOVE_HARBOR     6102
#define ID_WARP_SS_TIDAL            6103
#define ID_WARP_SS_TIDAL_ROOMS      6104
#define ID_WARP_BIRTH_ISLAND        6105
#define ID_WARP_NAVEL_ROCK          6106
#define ID_WARP_FARAWAY_ISLAND      6107
#define ID_WARP_SOUTHERN_ISLAND     6108
#define ID_WARP_VERMILION_PORT      6109
#define ID_WARP_VIRIDIAN_GYM        6110
#define ID_WARP_INDIGO_SUMMIT       6111

#define ID_WARP_KANTO_PALLET        6120
#define ID_WARP_KANTO_VIRIDIAN      6121
#define ID_WARP_KANTO_PEWTER        6122
#define ID_WARP_KANTO_CERULEAN      6123
#define ID_WARP_KANTO_VERMILION     6124
#define ID_WARP_KANTO_LAVENDER      6125
#define ID_WARP_KANTO_CELADON       6126
#define ID_WARP_KANTO_FUCHSIA       6127
#define ID_WARP_KANTO_SAFFRON       6128
#define ID_WARP_KANTO_CINNABAR      6129
#define ID_WARP_KANTO_INDIGO        6130

#define ID_WARP_PEWTER_GYM          6131
#define ID_WARP_CERULEAN_GYM        6132
#define ID_WARP_VERMILION_GYM       6133
#define ID_WARP_CELADON_GYM         6134
#define ID_WARP_FUCHSIA_GYM         6135
#define ID_WARP_SAFFRON_GYM         6136
#define ID_WARP_CINNABAR_GYM        6137

#define ID_CHALLENGE_BLUE           6201
#define ID_CHALLENGE_RED            6202
#define ID_CHALLENGE_BROCK          6203
#define ID_CHALLENGE_MISTY          6204
#define ID_CHALLENGE_SURGE          6205
#define ID_CHALLENGE_ERIKA          6206
#define ID_CHALLENGE_KOGA           6207
#define ID_CHALLENGE_SABRINA        6208
#define ID_CHALLENGE_BLAINE         6209

#define ID_HELP_CONTROLS            7001
#define ID_HELP_ABOUT               7002

static HWND sHwnd = NULL;
static HMENU sMainMenu = NULL;
static WNDPROC sOrigWndProc = NULL;
static bool sIsMenuVisible = true;

void Soh_SetSpeed(double scale)
{
    timeScale = scale;
    if (scale > 1.0)
    {
        speedUp = true;
        SDL_PauseAudioDevice(sdlAudioDevice, 1);
    }
    else
    {
        speedUp = false;
        SDL_PauseAudioDevice(sdlAudioDevice, 0);
    }
}

static void Soh_UpdateMenuChecks(void)
{
    if (!sMainMenu)
        return;

    // Game
    CheckMenuItem(sMainMenu, ID_GAME_PAUSE, paused ? MF_CHECKED : MF_UNCHECKED);
    CheckMenuRadioItem(sMainMenu, ID_GAME_SPEED_1X, ID_GAME_SPEED_8X,
        (timeScale >= 7.9) ? ID_GAME_SPEED_8X :
        (timeScale >= 3.9) ? ID_GAME_SPEED_4X :
        (timeScale >= 1.9) ? ID_GAME_SPEED_2X : ID_GAME_SPEED_1X,
        MF_BYCOMMAND);

    // Graphics
    CheckMenuItem(sMainMenu, ID_GFX_BORDER_TOGGLE, Platform_GetSetting(PLATFORM_SETTING_BORDER) ? MF_CHECKED : MF_UNCHECKED);
    CheckMenuItem(sMainMenu, ID_GFX_INTEGER_SCALE, Platform_GetSetting(PLATFORM_SETTING_INTEGER_SCALE) ? MF_CHECKED : MF_UNCHECKED);
    u8 winScale = Platform_GetSetting(PLATFORM_SETTING_WINDOW_SCALE);
    CheckMenuRadioItem(sMainMenu, ID_GFX_SCALE_2X, ID_GFX_SCALE_5X,
        (winScale == 2) ? ID_GFX_SCALE_2X :
        (winScale == 3) ? ID_GFX_SCALE_3X :
        (winScale == 5) ? ID_GFX_SCALE_5X : ID_GFX_SCALE_4X,
        MF_BYCOMMAND);
    CheckMenuItem(sMainMenu, ID_GFX_FULLSCREEN, Platform_GetSetting(PLATFORM_SETTING_FULLSCREEN) ? MF_CHECKED : MF_UNCHECKED);
    CheckMenuItem(sMainMenu, ID_GFX_VSYNC, Platform_GetSetting(PLATFORM_SETTING_VSYNC) ? MF_CHECKED : MF_UNCHECKED);

    // Audio
    u8 vol = Platform_GetSetting(PLATFORM_SETTING_VOLUME);
    CheckMenuRadioItem(sMainMenu, ID_AUDIO_VOL_100, ID_AUDIO_VOL_MUTE,
        (vol >= 10) ? ID_AUDIO_VOL_100 :
        (vol >= 7)  ? ID_AUDIO_VOL_75  :
        (vol >= 5)  ? ID_AUDIO_VOL_50  :
        (vol >= 2)  ? ID_AUDIO_VOL_25  : ID_AUDIO_VOL_MUTE,
        MF_BYCOMMAND);

    // Enhancements
    CheckMenuItem(sMainMenu, ID_ENH_INSTANT_TEXT, gEnhanceInstantText ? MF_CHECKED : MF_UNCHECKED);
    CheckMenuItem(sMainMenu, ID_ENH_AUTORUN, gEnhanceAutoRun ? MF_CHECKED : MF_UNCHECKED);
    CheckMenuItem(sMainMenu, ID_ENH_100CATCH, gCheat100PercentCatch ? MF_CHECKED : MF_UNCHECKED);

    // Cheats
    CheckMenuItem(sMainMenu, ID_CHEAT_GHOST_MODE, gCheatWalkThroughWalls ? MF_CHECKED : MF_UNCHECKED);
}

static bool IsSafeToWarp(void)
{
    if (gSaveBlock1Ptr == NULL)
        return false;
    if (gMain.callback2 != CB2_Overworld)
        return false;
    return true;
}

static void TriggerWarpHeal(u8 healLocId, const char *locationName)
{
    if (!IsSafeToWarp())
    {
        MessageBoxA(sHwnd, "Warps are only available while walking in the Overworld!\nPlease enter the game first.", "Warp Notice", MB_OK | MB_ICONINFORMATION);
        return;
    }
    SetWarpDestinationToHealLocation(healLocId);
    WarpIntoMap();
    SetMainCallback2(CB2_LoadMap);
}

#define GET_MAP_GROUP(map) ((s8)(((map) >> 8) & 0xFF))
#define GET_MAP_NUM(map)   ((u8)((map) & 0xFF))

static void TriggerWarpMap(u16 map, s8 x, s8 y, const char *locationName)
{
    if (!IsSafeToWarp())
    {
        MessageBoxA(sHwnd, "Warps are only available while walking in the Overworld!\nPlease enter the game first.", "Warp Notice", MB_OK | MB_ICONINFORMATION);
        return;
    }
    SetWarpDestination(GET_MAP_GROUP(map), GET_MAP_NUM(map), WARP_ID_NONE, x, y);
    WarpIntoMap();
    SetMainCallback2(CB2_LoadMap);
}

static LRESULT CALLBACK Soh_WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (msg == WM_COMMAND)
    {
        int id = LOWORD(wParam);
        switch (id)
        {
        // --- GAME ---
        case ID_GAME_PAUSE:
            paused = !paused;
            break;
        case ID_GAME_SPEED_1X:
            Soh_SetSpeed(1.0);
            break;
        case ID_GAME_SPEED_2X:
            Soh_SetSpeed(2.0);
            break;
        case ID_GAME_SPEED_4X:
            Soh_SetSpeed(4.0);
            break;
        case ID_GAME_SPEED_8X:
            Soh_SetSpeed(8.0);
            break;
        case ID_GAME_QUICKSAVE:
            Platform_StoreSaveFile();
            MessageBoxA(sHwnd, "Game saved successfully to pokeemerald.sav!", "Quick Save", MB_OK | MB_ICONINFORMATION);
            break;
        case ID_GAME_RESET:
            DoSoftReset();
            break;
        case ID_GAME_EXIT:
            {
                SDL_Event ev;
                ev.type = SDL_QUIT;
                SDL_PushEvent(&ev);
            }
            break;

        // --- GRAPHICS ---
        case ID_GFX_BORDER_TOGGLE:
            Platform_SetSetting(PLATFORM_SETTING_BORDER, !Platform_GetSetting(PLATFORM_SETTING_BORDER));
            break;
        case ID_GFX_INTEGER_SCALE:
            Platform_SetSetting(PLATFORM_SETTING_INTEGER_SCALE, !Platform_GetSetting(PLATFORM_SETTING_INTEGER_SCALE));
            break;
        case ID_GFX_SCALE_2X:
            Platform_SetSetting(PLATFORM_SETTING_WINDOW_SCALE, 2);
            break;
        case ID_GFX_SCALE_3X:
            Platform_SetSetting(PLATFORM_SETTING_WINDOW_SCALE, 3);
            break;
        case ID_GFX_SCALE_4X:
            Platform_SetSetting(PLATFORM_SETTING_WINDOW_SCALE, 4);
            break;
        case ID_GFX_SCALE_5X:
            Platform_SetSetting(PLATFORM_SETTING_WINDOW_SCALE, 5);
            break;
        case ID_GFX_FULLSCREEN:
            Platform_SetSetting(PLATFORM_SETTING_FULLSCREEN, !Platform_GetSetting(PLATFORM_SETTING_FULLSCREEN));
            break;
        case ID_GFX_VSYNC:
            Platform_SetSetting(PLATFORM_SETTING_VSYNC, !Platform_GetSetting(PLATFORM_SETTING_VSYNC));
            break;

        // --- AUDIO ---
        case ID_AUDIO_VOL_100:
            Platform_SetSetting(PLATFORM_SETTING_VOLUME, 10);
            break;
        case ID_AUDIO_VOL_75:
            Platform_SetSetting(PLATFORM_SETTING_VOLUME, 8);
            break;
        case ID_AUDIO_VOL_50:
            Platform_SetSetting(PLATFORM_SETTING_VOLUME, 5);
            break;
        case ID_AUDIO_VOL_25:
            Platform_SetSetting(PLATFORM_SETTING_VOLUME, 3);
            break;
        case ID_AUDIO_VOL_MUTE:
            Platform_SetSetting(PLATFORM_SETTING_VOLUME, 0);
            break;

        // --- ENHANCEMENTS ---
        case ID_ENH_INSTANT_TEXT:
            gEnhanceInstantText = !gEnhanceInstantText;
            break;
        case ID_ENH_AUTORUN:
            gEnhanceAutoRun = !gEnhanceAutoRun;
            break;
        case ID_ENH_100CATCH:
            gCheat100PercentCatch = !gCheat100PercentCatch;
            break;
        case ID_ENH_HIDE_MENU:
            Soh_ToggleMenuBar();
            return 0;

        // --- CHEATS ---
        case ID_CHEAT_GHOST_MODE:
            gCheatWalkThroughWalls = !gCheatWalkThroughWalls;
            break;
        case ID_CHEAT_MAX_MONEY:
            if (gSaveBlock1Ptr && gSaveBlock2Ptr)
            {
                SetMoney(&gSaveBlock1Ptr->money, 999999);
                MessageBoxA(sHwnd, "Player money set to $999,999!", "Cheats", MB_OK | MB_ICONINFORMATION);
            }
            break;
        case ID_CHEAT_GIVE_RARE_CANDY:
            if (gSaveBlock1Ptr)
            {
                AddBagItem(ITEM_RARE_CANDY, 99);
                MessageBoxA(sHwnd, "Added 99x Rare Candies to your Bag!", "Cheats", MB_OK | MB_ICONINFORMATION);
            }
            break;
        case ID_CHEAT_GIVE_MASTER_BALL:
            if (gSaveBlock1Ptr)
            {
                AddBagItem(ITEM_MASTER_BALL, 99);
                MessageBoxA(sHwnd, "Added 99x Master Balls to your Bag!", "Cheats", MB_OK | MB_ICONINFORMATION);
            }
            break;
        case ID_CHEAT_HEAL_PARTY:
            if (gSaveBlock1Ptr)
            {
                HealPlayerParty();
                MessageBoxA(sHwnd, "All party Pokémon have been fully healed!", "Cheats", MB_OK | MB_ICONINFORMATION);
            }
            break;
        case ID_CHEAT_MAX_IVS_EVS:
            if (gSaveBlock1Ptr)
            {
                u8 maxIv = 31;
                u8 maxEv = 252;
                for (int i = 0; i < PARTY_SIZE; i++)
                {
                    if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
                    {
                        SetMonData(&gPlayerParty[i], MON_DATA_HP_IV, &maxIv);
                        SetMonData(&gPlayerParty[i], MON_DATA_ATK_IV, &maxIv);
                        SetMonData(&gPlayerParty[i], MON_DATA_DEF_IV, &maxIv);
                        SetMonData(&gPlayerParty[i], MON_DATA_SPEED_IV, &maxIv);
                        SetMonData(&gPlayerParty[i], MON_DATA_SPATK_IV, &maxIv);
                        SetMonData(&gPlayerParty[i], MON_DATA_SPDEF_IV, &maxIv);
                        SetMonData(&gPlayerParty[i], MON_DATA_HP_EV, &maxEv);
                        SetMonData(&gPlayerParty[i], MON_DATA_ATK_EV, &maxEv);
                        SetMonData(&gPlayerParty[i], MON_DATA_DEF_EV, &maxEv);
                        SetMonData(&gPlayerParty[i], MON_DATA_SPEED_EV, &maxEv);
                        SetMonData(&gPlayerParty[i], MON_DATA_SPATK_EV, &maxEv);
                        SetMonData(&gPlayerParty[i], MON_DATA_SPDEF_EV, &maxEv);
                        CalculateMonStats(&gPlayerParty[i]);
                    }
                }
                MessageBoxA(sHwnd, "All party Pokémon IVs set to 31 and EVs set to 252!", "Cheats", MB_OK | MB_ICONINFORMATION);
            }
            break;
        case ID_CHEAT_ALL_HOENN_BADGES:
            if (gSaveBlock1Ptr)
            {
                for (int i = FLAG_BADGE01_GET; i <= FLAG_BADGE08_GET; i++)
                    FlagSet(i);
                MessageBoxA(sHwnd, "Unlocked all 8 Hoenn Gym Badges!", "Cheats", MB_OK | MB_ICONINFORMATION);
            }
            break;
        case ID_CHEAT_ALL_KANTO_BADGES:
            if (gSaveBlock1Ptr)
            {
                for (int i = FLAG_BADGE_BOULDER_GET; i <= FLAG_BADGE_EARTH_GET; i++)
                    FlagSet(i);
                MessageBoxA(sHwnd, "Unlocked all 8 Kanto Gym Badges!", "Cheats", MB_OK | MB_ICONINFORMATION);
            }
            break;
        case ID_CHEAT_COMPLETE_POKEDEX:
            if (gSaveBlock1Ptr)
            {
                FlagSet(FLAG_SYS_POKEDEX_GET);
                FlagSet(FLAG_SYS_NATIONAL_DEX);
                for (int i = 1; i <= NATIONAL_DEX_COUNT; i++)
                {
                    GetSetPokedexFlag(i, FLAG_SET_SEEN);
                    GetSetPokedexFlag(i, FLAG_SET_CAUGHT);
                }
                MessageBoxA(sHwnd, "National Pokédex Completed!\nAll 386 Pokémon registered as seen & caught.", "Cheats", MB_OK | MB_ICONINFORMATION);
            }
            break;
        case ID_CHEAT_EVENT_TICKETS:
            if (gSaveBlock1Ptr)
            {
                AddBagItem(ITEM_AURORA_TICKET, 1);
                AddBagItem(ITEM_MYSTIC_TICKET, 1);
                FlagSet(FLAG_ENABLE_SHIP_BIRTH_ISLAND);
                FlagSet(FLAG_ENABLE_SHIP_NAVEL_ROCK);
                MessageBoxA(sHwnd, "Added Aurora Ticket & Mystic Ticket!\nBirth Island & Navel Rock unlocked at port.", "Cheats", MB_OK | MB_ICONINFORMATION);
            }
            break;
        case ID_CHEAT_SET_GAME_CLEAR:
            if (gSaveBlock1Ptr)
            {
                FlagSet(FLAG_SYS_GAME_CLEAR);
                MessageBoxA(sHwnd, "Game Clear flag activated!\nPost-Game Kanto Ferry voyage unlocked at Slateport & Lilycove harbors.", "Cheats", MB_OK | MB_ICONINFORMATION);
            }
            break;

        // --- WARPS: HOENN ---
        case ID_WARP_LITTLEROOT:
            TriggerWarpHeal(HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE, "Littleroot Town");
            break;
        case ID_WARP_PETALBURG:
            TriggerWarpHeal(HEAL_LOCATION_PETALBURG_CITY, "Petalburg City");
            break;
        case ID_WARP_RUSTBORO:
            TriggerWarpHeal(HEAL_LOCATION_RUSTBORO_CITY, "Rustboro City");
            break;
        case ID_WARP_DEWFORD:
            TriggerWarpHeal(HEAL_LOCATION_DEWFORD_TOWN, "Dewford Town");
            break;
        case ID_WARP_SLATEPORT:
            TriggerWarpHeal(HEAL_LOCATION_SLATEPORT_CITY, "Slateport City");
            break;
        case ID_WARP_MAUVILLE:
            TriggerWarpHeal(HEAL_LOCATION_MAUVILLE_CITY, "Mauville City");
            break;
        case ID_WARP_LAVARIDGE:
            TriggerWarpHeal(HEAL_LOCATION_LAVARIDGE_TOWN, "Lavaridge Town");
            break;
        case ID_WARP_FALLARBOR:
            TriggerWarpHeal(HEAL_LOCATION_FALLARBOR_TOWN, "Fallarbor Town");
            break;
        case ID_WARP_FORTREE:
            TriggerWarpHeal(HEAL_LOCATION_FORTREE_CITY, "Fortree City");
            break;
        case ID_WARP_LILYCOVE:
            TriggerWarpHeal(HEAL_LOCATION_LILYCOVE_CITY, "Lilycove City");
            break;
        case ID_WARP_MOSSDEEP:
            TriggerWarpHeal(HEAL_LOCATION_MOSSDEEP_CITY, "Mossdeep City");
            break;
        case ID_WARP_SOOTOPOLIS:
            TriggerWarpHeal(HEAL_LOCATION_SOOTOPOLIS_CITY, "Sootopolis City");
            break;
        case ID_WARP_EVER_GRANDE:
            TriggerWarpHeal(HEAL_LOCATION_EVER_GRANDE_CITY_POKEMON_LEAGUE, "Pokémon League");
            break;
        case ID_WARP_BATTLE_FRONTIER:
            TriggerWarpHeal(HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST, "Battle Frontier");
            break;

        // --- WARPS: POST-GAME & EVENT ISLANDS ---
        case ID_WARP_SLATEPORT_HARBOR:
            TriggerWarpMap(MAP_SLATEPORT_CITY_HARBOR, 8, 11, "Slateport Harbor");
            break;
        case ID_WARP_LILYCOVE_HARBOR:
            TriggerWarpMap(MAP_LILYCOVE_CITY_HARBOR, 8, 11, "Lilycove Harbor");
            break;
        case ID_WARP_SS_TIDAL:
            TriggerWarpMap(MAP_SS_TIDAL_CORRIDOR, 1, 10, "S.S. Tidal Corridor");
            break;
        case ID_WARP_SS_TIDAL_ROOMS:
            TriggerWarpMap(MAP_SS_TIDAL_ROOMS, 13, 15, "S.S. Tidal Cabins");
            break;
        case ID_WARP_BIRTH_ISLAND:
            TriggerWarpMap(MAP_BIRTH_ISLAND_EXTERIOR, 15, 24, "Birth Island (Deoxys)");
            break;
        case ID_WARP_NAVEL_ROCK:
            TriggerWarpMap(MAP_NAVEL_ROCK_EXTERIOR, 10, 18, "Navel Rock (Ho-Oh / Lugia)");
            break;
        case ID_WARP_FARAWAY_ISLAND:
            TriggerWarpMap(MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38, "Faraway Island (Mew)");
            break;
        case ID_WARP_SOUTHERN_ISLAND:
            TriggerWarpHeal(HEAL_LOCATION_SOUTHERN_ISLAND_EXTERIOR, "Southern Island");
            break;
        case ID_WARP_VERMILION_PORT:
            TriggerWarpMap(MAP_KANTO_SSANNE_EXTERIOR, 31, 6, "Vermilion Port");
            break;
        case ID_WARP_VIRIDIAN_GYM:
            TriggerWarpMap(MAP_KANTO_VIRIDIAN_CITY_GYM, 16, 21, "Viridian City Gym");
            break;
        case ID_WARP_INDIGO_SUMMIT:
            TriggerWarpMap(MAP_KANTO_INDIGO_PLATEAU_EXTERIOR, 11, 7, "Indigo Plateau Summit");
            break;

        // --- WARPS: KANTO OVERLAND CITIES ---
        case ID_WARP_KANTO_PALLET:
            TriggerWarpMap(MAP_KANTO_PALLET_TOWN, 6, 8, "Pallet Town");
            break;
        case ID_WARP_KANTO_VIRIDIAN:
            TriggerWarpMap(MAP_KANTO_VIRIDIAN_CITY, 26, 27, "Viridian City");
            break;
        case ID_WARP_KANTO_PEWTER:
            TriggerWarpMap(MAP_KANTO_PEWTER_CITY, 17, 26, "Pewter City");
            break;
        case ID_WARP_KANTO_CERULEAN:
            TriggerWarpMap(MAP_KANTO_CERULEAN_CITY, 22, 20, "Cerulean City");
            break;
        case ID_WARP_KANTO_VERMILION:
            TriggerWarpMap(MAP_KANTO_VERMILION_CITY, 15, 7, "Vermilion City");
            break;
        case ID_WARP_KANTO_LAVENDER:
            TriggerWarpMap(MAP_KANTO_LAVENDER_TOWN, 6, 6, "Lavender Town");
            break;
        case ID_WARP_KANTO_CELADON:
            TriggerWarpMap(MAP_KANTO_CELADON_CITY, 48, 12, "Celadon City");
            break;
        case ID_WARP_KANTO_FUCHSIA:
            TriggerWarpMap(MAP_KANTO_FUCHSIA_CITY, 25, 32, "Fuchsia City");
            break;
        case ID_WARP_KANTO_SAFFRON:
            TriggerWarpMap(MAP_KANTO_SAFFRON_CITY, 24, 39, "Saffron City");
            break;
        case ID_WARP_KANTO_CINNABAR:
            TriggerWarpMap(MAP_KANTO_CINNABAR_ISLAND, 14, 12, "Cinnabar Island");
            break;
        case ID_WARP_KANTO_INDIGO:
            TriggerWarpMap(MAP_KANTO_INDIGO_PLATEAU_EXTERIOR, 11, 7, "Indigo Plateau");
            break;

        // --- WARPS: KANTO GYMS ---
        case ID_WARP_PEWTER_GYM:
            TriggerWarpMap(MAP_KANTO_PEWTER_CITY_GYM, 5, 13, "Pewter Gym");
            break;
        case ID_WARP_CERULEAN_GYM:
            TriggerWarpMap(MAP_KANTO_CERULEAN_CITY_GYM, 7, 17, "Cerulean Gym");
            break;
        case ID_WARP_VERMILION_GYM:
            TriggerWarpMap(MAP_KANTO_VERMILION_CITY_GYM, 4, 18, "Vermilion Gym");
            break;
        case ID_WARP_CELADON_GYM:
            TriggerWarpMap(MAP_KANTO_CELADON_CITY_GYM, 5, 17, "Celadon Gym");
            break;
        case ID_WARP_FUCHSIA_GYM:
            TriggerWarpMap(MAP_KANTO_FUCHSIA_CITY_GYM, 6, 20, "Fuchsia Gym");
            break;
        case ID_WARP_SAFFRON_GYM:
            TriggerWarpMap(MAP_KANTO_SAFFRON_CITY_GYM, 13, 22, "Saffron Gym");
            break;
        case ID_WARP_CINNABAR_GYM:
            TriggerWarpMap(MAP_KANTO_CINNABAR_ISLAND_GYM, 24, 22, "Cinnabar Gym");
            break;

        // --- BOSS CHALLENGES ---
        case ID_CHALLENGE_BROCK:
            if (!IsSafeToWarp()) { MessageBoxA(sHwnd, "Please enter the overworld map before initiating the challenge!", "Challenge Notice", MB_OK | MB_ICONINFORMATION); break; }
            { extern const u8 PewterCity_Gym_EventScript_Leader[]; extern void ScriptContext_SetupScript(const u8 *ptr);
              FlagClear(FLAG_BADGE_BOULDER_GET); FlagClear(FLAG_DEFEATED_KANTO_BROCK); FlagClear(TRAINER_FLAGS_START + 855);
              ScriptContext_SetupScript(PewterCity_Gym_EventScript_Leader); } break;
        case ID_CHALLENGE_MISTY:
            if (!IsSafeToWarp()) { MessageBoxA(sHwnd, "Please enter the overworld map before initiating the challenge!", "Challenge Notice", MB_OK | MB_ICONINFORMATION); break; }
            { extern const u8 CeruleanCity_Gym_EventScript_Leader[]; extern void ScriptContext_SetupScript(const u8 *ptr);
              FlagClear(FLAG_BADGE_CASCADE_GET); FlagClear(FLAG_DEFEATED_KANTO_MISTY); FlagClear(TRAINER_FLAGS_START + 856);
              ScriptContext_SetupScript(CeruleanCity_Gym_EventScript_Leader); } break;
        case ID_CHALLENGE_SURGE:
            if (!IsSafeToWarp()) { MessageBoxA(sHwnd, "Please enter the overworld map before initiating the challenge!", "Challenge Notice", MB_OK | MB_ICONINFORMATION); break; }
            { extern const u8 VermilionCity_Gym_EventScript_Leader[]; extern void ScriptContext_SetupScript(const u8 *ptr);
              FlagClear(FLAG_BADGE_THUNDER_GET); FlagClear(FLAG_DEFEATED_KANTO_SURGE); FlagClear(TRAINER_FLAGS_START + 857);
              ScriptContext_SetupScript(VermilionCity_Gym_EventScript_Leader); } break;
        case ID_CHALLENGE_ERIKA:
            if (!IsSafeToWarp()) { MessageBoxA(sHwnd, "Please enter the overworld map before initiating the challenge!", "Challenge Notice", MB_OK | MB_ICONINFORMATION); break; }
            { extern const u8 CeladonCity_Gym_EventScript_Leader[]; extern void ScriptContext_SetupScript(const u8 *ptr);
              FlagClear(FLAG_BADGE_RAINBOW_GET); FlagClear(FLAG_DEFEATED_KANTO_ERIKA); FlagClear(TRAINER_FLAGS_START + 858);
              ScriptContext_SetupScript(CeladonCity_Gym_EventScript_Leader); } break;
        case ID_CHALLENGE_KOGA:
            if (!IsSafeToWarp()) { MessageBoxA(sHwnd, "Please enter the overworld map before initiating the challenge!", "Challenge Notice", MB_OK | MB_ICONINFORMATION); break; }
            { extern const u8 FuchsiaCity_Gym_EventScript_Leader[]; extern void ScriptContext_SetupScript(const u8 *ptr);
              FlagClear(FLAG_BADGE_SOUL_GET); FlagClear(FLAG_DEFEATED_KANTO_KOGA); FlagClear(TRAINER_FLAGS_START + 859);
              ScriptContext_SetupScript(FuchsiaCity_Gym_EventScript_Leader); } break;
        case ID_CHALLENGE_SABRINA:
            if (!IsSafeToWarp()) { MessageBoxA(sHwnd, "Please enter the overworld map before initiating the challenge!", "Challenge Notice", MB_OK | MB_ICONINFORMATION); break; }
            { extern const u8 SaffronCity_Gym_EventScript_Leader[]; extern void ScriptContext_SetupScript(const u8 *ptr);
              FlagClear(FLAG_BADGE_MARSH_GET); FlagClear(FLAG_DEFEATED_KANTO_SABRINA); FlagClear(TRAINER_FLAGS_START + 860);
              ScriptContext_SetupScript(SaffronCity_Gym_EventScript_Leader); } break;
        case ID_CHALLENGE_BLAINE:
            if (!IsSafeToWarp()) { MessageBoxA(sHwnd, "Please enter the overworld map before initiating the challenge!", "Challenge Notice", MB_OK | MB_ICONINFORMATION); break; }
            { extern const u8 CinnabarIsland_Gym_EventScript_Leader[]; extern void ScriptContext_SetupScript(const u8 *ptr);
              FlagClear(FLAG_BADGE_VOLCANO_GET); FlagClear(FLAG_DEFEATED_KANTO_BLAINE); FlagClear(TRAINER_FLAGS_START + 861);
              ScriptContext_SetupScript(CinnabarIsland_Gym_EventScript_Leader); } break;

        // --- BOSS CHALLENGES ---
        case ID_CHALLENGE_BLUE:
            if (!IsSafeToWarp())
            {
                MessageBoxA(sHwnd, "Please enter the overworld map before initiating the challenge!", "Challenge Notice", MB_OK | MB_ICONINFORMATION);
                break;
            }
            {
                extern const u8 Kanto_ViridianCity_Gym_EventScript_Giovanni[];
                extern void ScriptContext_SetupScript(const u8 *ptr);
                FlagClear(FLAG_BADGE_EARTH_GET);
                FlagClear(FLAG_DEFEATED_KANTO_BLUE);
                FlagClear(TRAINER_FLAGS_START + 853); // TRAINER_BLUE
                ScriptContext_SetupScript(Kanto_ViridianCity_Gym_EventScript_Giovanni);
            }
            break;
        case ID_CHALLENGE_RED:
            if (!IsSafeToWarp())
            {
                MessageBoxA(sHwnd, "Please enter the overworld map before initiating the challenge!", "Challenge Notice", MB_OK | MB_ICONINFORMATION);
                break;
            }
            {
                extern const u8 Kanto_IndigoPlateau_Exterior_EventScript_Red[];
                extern void ScriptContext_SetupScript(const u8 *ptr);
                FlagClear(FLAG_DEFEATED_KANTO_RED);
                FlagClear(TRAINER_FLAGS_START + 851); // TRAINER_RED
                ScriptContext_SetupScript(Kanto_IndigoPlateau_Exterior_EventScript_Red);
            }
            break;

        // --- HELP ---
        case ID_HELP_CONTROLS:
            MessageBoxA(sHwnd,
                "XTREME-SPEED CONTROLS:\n\n"
                "Movement: Arrow Keys or W / A / S / D\n"
                "A Button (Interact/Confirm): Z or C\n"
                "B Button (Cancel/Run): X or V\n"
                "Start Button (In-Game Menu): Enter\n"
                "Select Button: Backspace\n"
                "L Shoulder: Q\n"
                "R Shoulder: E\n\n"
                "SHIP OF HARKINIAN MENU BAR:\n"
                "F1 or ` (Tilde): Toggle Menu Bar\n"
                "Space (Hold): Fast Forward (Turbo)\n"
                "Ctrl+P: Pause / Resume\n"
                "Ctrl+R: Soft Reset\n"
                "F11: Toggle Fullscreen",
                "Controls & Hotkeys", MB_OK | MB_ICONINFORMATION);
            break;
        case ID_HELP_ABOUT:
            MessageBoxA(sHwnd,
                "XTREME-SPEED\n"
                "Ship of Harkinian Enhanced Native PC Port\n\n"
                "- Native C/C++ engine compiled directly for Windows x86\n"
                "- 60 FPS full speed with zero emulation overhead\n"
                "- Full Kanto Region Remake with 11 Cities & 25 Routes\n"
                "- 8 Kanto Gym Leaders with Dedicated Gym Badge Flags\n"
                "- Complete Gen 6+ Fairy-Type Engine & Physical/Special Split\n"
                "- Parallel Hoenn & Kanto Post-Game Systems",
                "About Xtreme-Speed", MB_OK | MB_ICONINFORMATION);
            break;
        }

        Soh_UpdateMenuChecks();
        return 0;
    }

    return CallWindowProc(sOrigWndProc, hwnd, msg, wParam, lParam);
}

static HMENU Soh_BuildMenuBar(void)
{
    HMENU hMenu = CreateMenu();

    // 1. Game Submenu
    HMENU hGame = CreatePopupMenu();
    AppendMenuA(hGame, MF_STRING, ID_GAME_PAUSE, "Pause / Resume\tCtrl+P");
    AppendMenuA(hGame, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hGame, MF_STRING, ID_GAME_SPEED_1X, "Speed: 1x (Normal)");
    AppendMenuA(hGame, MF_STRING, ID_GAME_SPEED_2X, "Speed: 2x (Fast)");
    AppendMenuA(hGame, MF_STRING, ID_GAME_SPEED_4X, "Speed: 4x (Turbo)");
    AppendMenuA(hGame, MF_STRING, ID_GAME_SPEED_8X, "Speed: 8x (Blazing)");
    AppendMenuA(hGame, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hGame, MF_STRING, ID_GAME_QUICKSAVE, "Quick Save\tCtrl+S");
    AppendMenuA(hGame, MF_STRING, ID_GAME_RESET, "Soft Reset\tCtrl+R");
    AppendMenuA(hGame, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hGame, MF_STRING, ID_GAME_EXIT, "Exit\tAlt+F4");
    AppendMenuA(hMenu, MF_POPUP, (UINT_PTR)hGame, "&Game");

    // 2. Graphics Submenu
    HMENU hGfx = CreatePopupMenu();
    AppendMenuA(hGfx, MF_STRING, ID_GFX_BORDER_TOGGLE, "Border Frame (Off / On)");
    AppendMenuA(hGfx, MF_STRING, ID_GFX_INTEGER_SCALE, "Integer Scaling (Off = Fit 3:2 / On = Integer)");
    AppendMenuA(hGfx, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hGfx, MF_STRING, ID_GFX_SCALE_2X, "Window Size: 2x (480x320)");
    AppendMenuA(hGfx, MF_STRING, ID_GFX_SCALE_3X, "Window Size: 3x (720x480)");
    AppendMenuA(hGfx, MF_STRING, ID_GFX_SCALE_4X, "Window Size: 4x (960x640 - Default)");
    AppendMenuA(hGfx, MF_STRING, ID_GFX_SCALE_5X, "Window Size: 5x (1200x800)");
    AppendMenuA(hGfx, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hGfx, MF_STRING, ID_GFX_FULLSCREEN, "Fullscreen\tF11");
    AppendMenuA(hGfx, MF_STRING, ID_GFX_VSYNC, "VSync");
    AppendMenuA(hMenu, MF_POPUP, (UINT_PTR)hGfx, "&Graphics");

    // 3. Audio Submenu
    HMENU hAudio = CreatePopupMenu();
    AppendMenuA(hAudio, MF_STRING, ID_AUDIO_VOL_100, "Volume: 100%");
    AppendMenuA(hAudio, MF_STRING, ID_AUDIO_VOL_75, "Volume: 75%");
    AppendMenuA(hAudio, MF_STRING, ID_AUDIO_VOL_50, "Volume: 50%");
    AppendMenuA(hAudio, MF_STRING, ID_AUDIO_VOL_25, "Volume: 25%");
    AppendMenuA(hAudio, MF_STRING, ID_AUDIO_VOL_MUTE, "Volume: Mute (0%)");
    AppendMenuA(hMenu, MF_POPUP, (UINT_PTR)hAudio, "&Audio");

    // 4. Enhancements Submenu
    HMENU hEnh = CreatePopupMenu();
    AppendMenuA(hEnh, MF_STRING, ID_ENH_INSTANT_TEXT, "Instant Text Speed");
    AppendMenuA(hEnh, MF_STRING, ID_ENH_AUTORUN, "Auto-Run Shoes (No B Needed)");
    AppendMenuA(hEnh, MF_STRING, ID_ENH_100CATCH, "100% Catch Rate (All Balls)");
    AppendMenuA(hEnh, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hEnh, MF_STRING, ID_ENH_HIDE_MENU, "Hide Menu Bar\tF1");
    AppendMenuA(hMenu, MF_POPUP, (UINT_PTR)hEnh, "&Enhancements");

    // 5. Cheats Submenu
    HMENU hCheats = CreatePopupMenu();
    AppendMenuA(hCheats, MF_STRING, ID_CHEAT_GHOST_MODE, "Walk Through Walls (Ghost Mode)");
    AppendMenuA(hCheats, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hCheats, MF_STRING, ID_CHEAT_MAX_MONEY, "Max Money ($999,999)");
    AppendMenuA(hCheats, MF_STRING, ID_CHEAT_GIVE_RARE_CANDY, "Give 99x Rare Candies");
    AppendMenuA(hCheats, MF_STRING, ID_CHEAT_GIVE_MASTER_BALL, "Give 99x Master Balls");
    AppendMenuA(hCheats, MF_STRING, ID_CHEAT_HEAL_PARTY, "Heal Entire Party");
    AppendMenuA(hCheats, MF_STRING, ID_CHEAT_MAX_IVS_EVS, "Max Party IVs & EVs (31/252)");
    AppendMenuA(hCheats, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hCheats, MF_STRING, ID_CHEAT_ALL_HOENN_BADGES, "Unlock All 8 Hoenn Badges");
    AppendMenuA(hCheats, MF_STRING, ID_CHEAT_ALL_KANTO_BADGES, "Unlock All 8 Kanto Badges");
    AppendMenuA(hCheats, MF_STRING, ID_CHEAT_COMPLETE_POKEDEX, "Complete National Pokédex");
    AppendMenuA(hCheats, MF_STRING, ID_CHEAT_EVENT_TICKETS, "Give Aurora & Mystic Tickets");
    AppendMenuA(hCheats, MF_STRING, ID_CHEAT_SET_GAME_CLEAR, "Unlock Post-Game (Game Clear)");
    AppendMenuA(hMenu, MF_POPUP, (UINT_PTR)hCheats, "&Cheats");

    // 6. Warps Submenu
    HMENU hWarps = CreatePopupMenu();

    HMENU hHoennWarps = CreatePopupMenu();
    AppendMenuA(hHoennWarps, MF_STRING, ID_WARP_LITTLEROOT, "Littleroot Town");
    AppendMenuA(hHoennWarps, MF_STRING, ID_WARP_PETALBURG, "Petalburg City");
    AppendMenuA(hHoennWarps, MF_STRING, ID_WARP_RUSTBORO, "Rustboro City");
    AppendMenuA(hHoennWarps, MF_STRING, ID_WARP_DEWFORD, "Dewford Town");
    AppendMenuA(hHoennWarps, MF_STRING, ID_WARP_SLATEPORT, "Slateport City");
    AppendMenuA(hHoennWarps, MF_STRING, ID_WARP_MAUVILLE, "Mauville City");
    AppendMenuA(hHoennWarps, MF_STRING, ID_WARP_LAVARIDGE, "Lavaridge Town");
    AppendMenuA(hHoennWarps, MF_STRING, ID_WARP_FALLARBOR, "Fallarbor Town");
    AppendMenuA(hHoennWarps, MF_STRING, ID_WARP_FORTREE, "Fortree City");
    AppendMenuA(hHoennWarps, MF_STRING, ID_WARP_LILYCOVE, "Lilycove City");
    AppendMenuA(hHoennWarps, MF_STRING, ID_WARP_MOSSDEEP, "Mossdeep City");
    AppendMenuA(hHoennWarps, MF_STRING, ID_WARP_SOOTOPOLIS, "Sootopolis City");
    AppendMenuA(hHoennWarps, MF_STRING, ID_WARP_EVER_GRANDE, "Ever Grande City (League)");
    AppendMenuA(hHoennWarps, MF_STRING, ID_WARP_BATTLE_FRONTIER, "Battle Frontier");
    AppendMenuA(hWarps, MF_POPUP, (UINT_PTR)hHoennWarps, "Hoenn Locations");

    HMENU hKantoWarps = CreatePopupMenu();
    AppendMenuA(hKantoWarps, MF_STRING, ID_WARP_SLATEPORT_HARBOR, "Slateport Harbor (S.S. Tidal)");
    AppendMenuA(hKantoWarps, MF_STRING, ID_WARP_LILYCOVE_HARBOR, "Lilycove Harbor (S.S. Tidal)");
    AppendMenuA(hKantoWarps, MF_STRING, ID_WARP_SS_TIDAL, "S.S. Tidal Corridor");
    AppendMenuA(hKantoWarps, MF_STRING, ID_WARP_SS_TIDAL_ROOMS, "S.S. Tidal Passenger Cabins");
    AppendMenuA(hKantoWarps, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hKantoWarps, MF_STRING, ID_WARP_BIRTH_ISLAND, "Birth Island (Deoxys)");
    AppendMenuA(hKantoWarps, MF_STRING, ID_WARP_NAVEL_ROCK, "Navel Rock (Ho-Oh & Lugia)");
    AppendMenuA(hKantoWarps, MF_STRING, ID_WARP_FARAWAY_ISLAND, "Faraway Island (Mew)");
    AppendMenuA(hKantoWarps, MF_STRING, ID_WARP_SOUTHERN_ISLAND, "Southern Island (Latios & Latias)");
    AppendMenuA(hWarps, MF_POPUP, (UINT_PTR)hKantoWarps, "Post-Game & Event Islands");

    HMENU hKantoCities = CreatePopupMenu();
    AppendMenuA(hKantoCities, MF_STRING, ID_WARP_KANTO_PALLET, "Pallet Town");
    AppendMenuA(hKantoCities, MF_STRING, ID_WARP_KANTO_VIRIDIAN, "Viridian City");
    AppendMenuA(hKantoCities, MF_STRING, ID_WARP_KANTO_PEWTER, "Pewter City");
    AppendMenuA(hKantoCities, MF_STRING, ID_WARP_KANTO_CERULEAN, "Cerulean City");
    AppendMenuA(hKantoCities, MF_STRING, ID_WARP_KANTO_VERMILION, "Vermilion City");
    AppendMenuA(hKantoCities, MF_STRING, ID_WARP_KANTO_LAVENDER, "Lavender Town");
    AppendMenuA(hKantoCities, MF_STRING, ID_WARP_KANTO_CELADON, "Celadon City");
    AppendMenuA(hKantoCities, MF_STRING, ID_WARP_KANTO_FUCHSIA, "Fuchsia City");
    AppendMenuA(hKantoCities, MF_STRING, ID_WARP_KANTO_SAFFRON, "Saffron City");
    AppendMenuA(hKantoCities, MF_STRING, ID_WARP_KANTO_CINNABAR, "Cinnabar Island");
    AppendMenuA(hKantoCities, MF_STRING, ID_WARP_KANTO_INDIGO, "Indigo Plateau");
    AppendMenuA(hWarps, MF_POPUP, (UINT_PTR)hKantoCities, "Kanto Cities & Towns");

    HMENU hKantoGyms = CreatePopupMenu();
    AppendMenuA(hKantoGyms, MF_STRING, ID_WARP_PEWTER_GYM, "Pewter Gym (Brock - Boulder Badge)");
    AppendMenuA(hKantoGyms, MF_STRING, ID_WARP_CERULEAN_GYM, "Cerulean Gym (Misty - Cascade Badge)");
    AppendMenuA(hKantoGyms, MF_STRING, ID_WARP_VERMILION_GYM, "Vermilion Gym (Lt. Surge - Thunder Badge)");
    AppendMenuA(hKantoGyms, MF_STRING, ID_WARP_CELADON_GYM, "Celadon Gym (Erika - Rainbow Badge)");
    AppendMenuA(hKantoGyms, MF_STRING, ID_WARP_FUCHSIA_GYM, "Fuchsia Gym (Koga - Soul Badge)");
    AppendMenuA(hKantoGyms, MF_STRING, ID_WARP_SAFFRON_GYM, "Saffron Gym (Sabrina - Marsh Badge)");
    AppendMenuA(hKantoGyms, MF_STRING, ID_WARP_CINNABAR_GYM, "Cinnabar Gym (Blaine - Volcano Badge)");
    AppendMenuA(hKantoGyms, MF_STRING, ID_WARP_VIRIDIAN_GYM, "Viridian Gym (Blue - Earth Badge)");
    AppendMenuA(hKantoGyms, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hKantoGyms, MF_STRING, ID_WARP_INDIGO_SUMMIT, "Indigo Plateau Summit (Champion Red)");
    AppendMenuA(hWarps, MF_POPUP, (UINT_PTR)hKantoGyms, "Kanto Gyms & Summit");

    HMENU hKantoCircuit = CreatePopupMenu();
    AppendMenuA(hKantoCircuit, MF_STRING, ID_WARP_VERMILION_PORT, "Vermilion Port (Kanto Gateway)");
    AppendMenuA(hWarps, MF_POPUP, (UINT_PTR)hKantoCircuit, "Kanto Ferry Gateway");

    HMENU hBosses = CreatePopupMenu();
    AppendMenuA(hBosses, MF_STRING, ID_CHALLENGE_BROCK, "Battle Brock (Boulder Badge)");
    AppendMenuA(hBosses, MF_STRING, ID_CHALLENGE_MISTY, "Battle Misty (Cascade Badge)");
    AppendMenuA(hBosses, MF_STRING, ID_CHALLENGE_SURGE, "Battle Lt. Surge (Thunder Badge)");
    AppendMenuA(hBosses, MF_STRING, ID_CHALLENGE_ERIKA, "Battle Erika (Rainbow Badge)");
    AppendMenuA(hBosses, MF_STRING, ID_CHALLENGE_KOGA, "Battle Koga (Soul Badge)");
    AppendMenuA(hBosses, MF_STRING, ID_CHALLENGE_SABRINA, "Battle Sabrina (Marsh Badge)");
    AppendMenuA(hBosses, MF_STRING, ID_CHALLENGE_BLAINE, "Battle Blaine (Volcano Badge)");
    AppendMenuA(hBosses, MF_STRING, ID_CHALLENGE_BLUE, "Battle Blue (Earth Badge)");
    AppendMenuA(hBosses, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hBosses, MF_STRING, ID_CHALLENGE_RED, "Battle Champion Red (Indigo Summit)");
    AppendMenuA(hWarps, MF_POPUP, (UINT_PTR)hBosses, "Kanto Gym Leaders & Champions");

    AppendMenuA(hMenu, MF_POPUP, (UINT_PTR)hWarps, "&Warps");

    // 7. Help Submenu
    HMENU hHelp = CreatePopupMenu();
    AppendMenuA(hHelp, MF_STRING, ID_HELP_CONTROLS, "Controls & Hotkeys...");
    AppendMenuA(hHelp, MF_STRING, ID_HELP_ABOUT, "About Xtreme-Speed...");
    AppendMenuA(hMenu, MF_POPUP, (UINT_PTR)hHelp, "&Help");

    return hMenu;
}

void Soh_Init(void *sdlWindow, void *sdlRenderer)
{
    SDL_SysWMinfo wmInfo;
    SDL_VERSION(&wmInfo.version);
    if (SDL_GetWindowWMInfo((SDL_Window *)sdlWindow, &wmInfo))
    {
        sHwnd = wmInfo.info.win.window;
        sMainMenu = Soh_BuildMenuBar();
        sIsMenuVisible = true;
        SetMenu(sHwnd, sMainMenu);
        DrawMenuBar(sHwnd);
        Soh_UpdateMenuChecks();
        sOrigWndProc = (WNDPROC)SetWindowLongPtr(sHwnd, GWLP_WNDPROC, (LONG_PTR)Soh_WndProc);
    }
}

void Soh_ToggleMenuBar(void)
{
    if (!sHwnd || !sMainMenu)
        return;

    if (sIsMenuVisible)
    {
        SetMenu(sHwnd, NULL);
        sIsMenuVisible = false;
    }
    else
    {
        SetMenu(sHwnd, sMainMenu);
        sIsMenuVisible = true;
        Soh_UpdateMenuChecks();
    }
    DrawMenuBar(sHwnd);
}

bool Soh_IsMenuBarVisible(void)
{
    return sIsMenuVisible;
}

#else

// Stubs for non-Windows platforms
bool8 gCheatWalkThroughWalls = FALSE;
bool8 gCheat100PercentCatch = FALSE;
bool8 gEnhanceInstantText = TRUE;
bool8 gEnhanceAutoRun = TRUE;

void Soh_Init(void *sdlWindow, void *sdlRenderer) {}
void Soh_ToggleMenuBar(void) {}
bool Soh_IsMenuBarVisible(void) { return false; }
void Soh_SetSpeed(double scale) {}

#endif
