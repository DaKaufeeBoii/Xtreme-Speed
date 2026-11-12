#include <jni.h>
#include <android/log.h>
#include <GLES3/gl3.h>
#include <EGL/egl.h>
#include <cstring>
#include <cstdlib>

#include "pokegen3.h"

#define TAG "PokeGen3Native"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)

static PokeEngine* g_engine = nullptr;
static GLuint g_textureId = 0;
static GLuint g_programId = 0;

static const char* vertexShaderSource = R"(#version 300 es
layout(location = 0) in vec2 aPosition;
layout(location = 1) in vec2 aTexCoord;
out vec2 vTexCoord;
void main() {
    gl_Position = vec4(aPosition, 0.0, 1.0);
    vTexCoord = aTexCoord;
}
)";

static const char* fragmentShaderSource = R"(#version 300 es
precision mediump float;
in vec2 vTexCoord;
out vec4 fragColor;
uniform sampler2D uTexture;
void main() {
    fragColor = texture(uTexture, vTexCoord);
}
)";

static GLuint compileShader(GLenum type, const char* src) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);
    return shader;
}

extern "C" {

JNIEXPORT void JNICALL
Java_com_pokemon_gen3port_MainActivity_nativeInit(JNIEnv* env, jobject thiz, jstring biosPath, jstring romPath) {
    if (g_engine) poke_destroy(g_engine);
    g_engine = poke_create();

    // Default to True Widescreen (20:9) for Android
    poke_set_aspect_ratio(g_engine, POKE_ASPECT_WIDESCREEN_20_9);

    const char* c_bios = env->GetStringUTFChars(biosPath, nullptr);
    const char* c_rom = env->GetStringUTFChars(romPath, nullptr);

    poke_load_bios_file(g_engine, c_bios);
    poke_register_rom_file(g_engine, POKE_GAME_COMBINED, c_rom);
    poke_register_rom_file(g_engine, POKE_GAME_EMERALD, c_rom);

    env->ReleaseStringUTFChars(biosPath, c_bios);
    env->ReleaseStringUTFChars(romPath, c_rom);

    LOGI("libpokegen3 native engine initialized for Android (True 20:9 Widescreen)");
}

JNIEXPORT void JNICALL
Java_com_pokemon_gen3port_MainActivity_nativeInitGL(JNIEnv* env, jobject thiz) {
    GLuint vs = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
    GLuint fs = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

    g_programId = glCreateProgram();
    glAttachShader(g_programId, vs);
    glAttachShader(g_programId, fs);
    glLinkProgram(g_programId);

    glGenTextures(1, &g_textureId);
    glBindTexture(GL_TEXTURE_2D, g_textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, POKE_WIDE_20_9_WIDTH, POKE_WIDE_20_9_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
}

JNIEXPORT void JNICALL
Java_com_pokemon_gen3port_MainActivity_nativeRenderFrame(JNIEnv* env, jobject thiz) {
    if (!g_engine) return;

    poke_run_frame(g_engine);

    const uint32_t* fb = poke_get_framebuffer(g_engine);
    if (!fb) return;

    glViewport(0, 0, POKE_WIDE_20_9_WIDTH, POKE_WIDE_20_9_HEIGHT);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(g_programId);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, g_textureId);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, POKE_WIDE_20_9_WIDTH, POKE_WIDE_20_9_HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, fb);

    static const float vertices[] = {
        // x, y, u, v
        -1.0f,  1.0f, 0.0f, 0.0f,
        -1.0f, -1.0f, 0.0f, 1.0f,
         1.0f,  1.0f, 1.0f, 0.0f,
         1.0f, -1.0f, 1.0f, 1.0f
    };

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), vertices);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), &vertices[2]);
    glEnableVertexAttribArray(1);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

JNIEXPORT void JNICALL
Java_com_pokemon_gen3port_MainActivity_nativeSetInput(JNIEnv* env, jobject thiz, jint keyMask) {
    if (g_engine) {
        poke_set_input(g_engine, (uint16_t)keyMask);
    }
}

JNIEXPORT void JNICALL
Java_com_pokemon_gen3port_MainActivity_nativeSelectGame(JNIEnv* env, jobject thiz, jint gameType) {
    if (g_engine) {
        poke_select_game(g_engine, (PokeGameType)gameType);
    }
}

JNIEXPORT void JNICALL
Java_com_pokemon_gen3port_MainActivity_nativeTransferRegion(JNIEnv* env, jobject thiz, jint targetRegion, jboolean downscale) {
    if (g_engine) {
        poke_transfer_region(g_engine, (PokeRegion)targetRegion, (bool)downscale);
    }
}

JNIEXPORT void JNICALL
Java_com_pokemon_gen3port_MainActivity_nativeDebugHeal(JNIEnv* env, jobject thiz) {
    if (g_engine) {
        poke_debug_heal_party(g_engine);
    }
}

JNIEXPORT void JNICALL
Java_com_pokemon_gen3port_MainActivity_nativeDestroy(JNIEnv* env, jobject thiz) {
    if (g_engine) {
        poke_destroy(g_engine);
        g_engine = nullptr;
    }
    if (g_textureId) {
        glDeleteTextures(1, &g_textureId);
        g_textureId = 0;
    }
    if (g_programId) {
        glDeleteProgram(g_programId);
        g_programId = 0;
    }
}

} // extern "C"
