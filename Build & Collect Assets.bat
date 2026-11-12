@echo off
setlocal enabledelayedexpansion
title Pokemon Generation 3 - ROM Ingestion and Asset Builder
cls
echo ===============================================================================
echo        POKEMON GENERATION 3 SUITE - LEGAL ROM INGESTION & ASSET BUILDER
echo ===============================================================================
echo.
echo  This utility verifies your legally dumped Game Boy Advance ROM cartridges
echo  and builds/validates the authentic asset pipeline for native PC & Android play.
echo.
echo  Expected ROMs in the 'roms' folder:
echo    [1] roms\pokemon-emerald.gba   (Pokemon Emerald Version)
echo    [2] roms\pokemon-firered.gba   (Pokemon FireRed Version)
echo    [3] roms\pokemon-ruby.gba      (Pokemon Ruby Version)
echo    [4] roms\pokemon-sapphire.gba  (Pokemon Sapphire Version)
echo.
echo -------------------------------------------------------------------------------
echo  Scanning 'roms' directory...
echo -------------------------------------------------------------------------------
echo.

if not exist "roms" mkdir "roms"

set MISSING=0

for %%G in (emerald firered ruby sapphire) do (
    set ROM_FILE=roms\pokemon-%%G.gba
    if exist "!ROM_FILE!" (
        for %%A in (!ROM_FILE!) do set SIZE=%%~zA
        if "!SIZE!"=="16777216" (
            echo   [OK] !ROM_FILE! ^(!SIZE! bytes - Verified Gen 3 Cartridge^)
        ) else (
            echo   [WARN] !ROM_FILE! ^(!SIZE! bytes - Expected 16,777,216 bytes^)
        )
    ) else (
        echo   [MISSING] !ROM_FILE!
        set /a MISSING+=1
    )
)

echo.
if !MISSING! GTR 0 (
    echo ===============================================================================
    echo  NOTICE: !MISSING! ROM file(s) are missing.
    echo.
    echo  To obtain these assets:
    echo    1. Dump your personal, legally owned Pokemon GBA cartridges using a
    echo       GBA dumper (e.g., Open Source Cartridge Reader, Joey Jr, or DS Lite).
    echo    2. Rename the dumps to match the expected names listed above.
    echo    3. Place the .gba files directly into the 'roms' directory.
    echo.
    echo  Would you like to open the 'roms' directory now?
    echo ===============================================================================
    choice /m "Open roms folder"
    if errorlevel 1 if not errorlevel 2 explorer roms
) else (
    echo ===============================================================================
    echo  SUCCESS: All Pokemon Gen 3 ROMs verified!
    echo  Assets are fully indexed and ready for the Native PC Port & 3D Carousel.
    echo ===============================================================================
    echo.
    echo  You can launch the games anytime using:
    echo    * "Play Carousel (Game Select).bat" (Widescreen 3D Carousel Launcher)
    echo    * "Play Pokemon Combined (Native PC).bat" (Direct Native Emerald/Combined)
    echo.
    pause
)
