@echo off
title Build Pokemon: Xtreme-Speed Android APK
cd /d "%~dp0"
echo =================================================================
echo   Building Pokemon: Xtreme-Speed Android APK (libpokegen3 NDK)...
echo   True 20:9 Widescreen • Floating Dynamic D-Pad • Haptics
echo =================================================================

set "ANDROID_HOME=C:\Users\user\AppData\Local\Android\Sdk"
set "GRADLE_BIN=C:\Users\user\.gradle\wrapper\dists\gradle-8.11.1-bin\bpt9gzteqjrbo1mjrsomdt32c\gradle-8.11.1\bin\gradle.bat"
if exist "%GRADLE_BIN%" (
    call "%GRADLE_BIN%" assembleDebug
) else (
    echo Gradle binary not found at default cache path. Running gradle...
    gradle assembleDebug
)

echo.
echo Build complete. Output APK located at: app\build\outputs\apk\debug\app-debug.apk
pause
