# Xtreme-Speed — Cross-Platform Native Engine (PC & Android)

**Native Decompilation • 60 FPS Widescreen Presentation • Enhanced Quality-of-Life • 100% Offline**

**Xtreme-Speed** is a high-performance, native cross-platform port running the decompiled Generation 3 monster-catching RPG engine directly on **PC (Windows / Linux)** and **Android (ARM64 / ARMv7)** using SDL2 hardware presentation.

> **Zero generic emulators. Zero web/network dependencies.**  
> Compiles directly to native host machine code for instantaneous load times, smooth 60 FPS presentation, scalable windowing, and widescreen camera framing.

---

## 🌟 Engine Features & Modern Overhaul

### 1. Seamless Two-Region Progression & Geographical Circuit
The engine unites the dual regions into an organic post-game adventure. Arriving via sea transport at the southern harbor port unlocks an inward-outward regional circuit:
- **Port-First Progression**: Begins at the southern port and spirals across metropolitan, northern mountain, western cycling, and coastal routes.
- **Gym Leaders & Scaled Boss Rosters**: 8 regional Gym Leaders re-calibrated with modern coverage, strategic AI, and elevated level curves for seasoned teams.
- **Summit Challenge**: Reach the highest mountain peak to face the legendary master trainer with a high-level apex team.
- **Authentic Town Dialogue & Encounters**: Full NPC interactions, region-specific wild encounter distributions, and functional warp networks.

### 2. Modern Battle Mechanics & Quality-of-Life Suite
- **Physical / Special Move Split**: Move categories dynamically categorized by individual move attributes rather than raw elemental type.
- **Modern Typing Additions**: Built-in modern typing support (including Fairy-type relationships and moves).
- **Reusable Machine Items**: Infinite TM usage for streamlined squad building and experimentation.
- **Indoor Running**: Unrestricted movement shoes inside buildings, gyms, and centers.
- **Developer & Enhancement Menu (`F1` / `~`)**:
  - In-game diagnostics, toggleable challenges, dynamic level caps, and Nuzlocke presets.
  - Shiny rate and experience multipliers.
  - Quick warp navigation and party health management.

### 3. Display & Audio Engine
- **Aspect-Ratio-Preserving 3:2 Rendering**: Centered viewport with scalable border frames and selectable background canvas options (`BG`, `BG 1`, etc.).
- **Float Audio Pipeline**: SDL2 floating-point audio output at 42,060 Hz with clipping protection and sanitized sample processing.
- **Native Save Storage**: Direct file-based game save read/write support (`pokeemerald.sav`) without save-state tampering or battery-RAM volatility.

### 4. Android Mobile Port (`ports/android/`)
- **Floating Dynamic Thumbstick**: Virtual D-pad anchors wherever the player touches on the left half of the display.
- **Micro-Haptics**: Tactile vibration feedback on button presses.
- **Native Gradle & CMake Pipeline**: Direct C++/NDK compilation targeting Android devices with low input latency.

---

## 🚀 Running on PC (Windows)

Launch using the direct native executable or launcher script:

- [**Play Xtreme-Speed (Native PC).bat**](file:///d:/Kaufee/projects/personal/pc-port/Play%20Xtreme-Speed%20(Native%20PC).bat) — Launches the native PC game.
- [**pokeemerald.exe**](file:///d:/Kaufee/projects/personal/pc-port/pokeemerald.exe) — The direct native Windows executable.

### PC Controls

| Action | Primary Key | Secondary Key | Controller |
|---|---|---|---|
| **D-Pad / Movement** | **Arrow Keys** | **W / A / S / D** | D-Pad / Left Stick |
| **A Button** (Interact / Confirm) | **Z** | **C** | **A** Button |
| **B Button** (Cancel / Run) | **X** | **V** | **B** Button |
| **Start** | **Enter** | **Return** | Start |
| **Select** | **Backslash (`\`)** | **Shift** | Select |
| **L Shoulder** | **Q** | **A** | **LB** |
| **R Shoulder** | **E** | **S** | **RB** |
| **Enhancement Menu** | **F1** | **`~` (Tilde)** | — |
| **Fast Forward** | **Space** | — | — |
| **Soft Reset** | **Ctrl + R** | — | — |
| **Pause Game** | **Ctrl + P** | — | — |

---

## 🛠️ Building from Source

### Windows (MSYS2 / MinGW)
Requirements: 32-bit MinGW toolchain, SDL2, and make:
```sh
cd src/pokeemerald-multiplatform
make -f Makefile_pc NODEP=1 -j4
```
Ensure `SDL2.dll` is located alongside the generated executable.

### Linux
Requires a 32-bit C toolchain and 32-bit SDL2 development packages:
```sh
cd src/pokeemerald-multiplatform
make -f Makefile_pc linux -j4
./pokeemerald
```

### Android
Requires Android SDK, NDK, CMake, and a compatible JDK:
```sh
cd ports/android
./gradlew :app:assembleDebug
```
The debug package will be generated under `app/build/outputs/apk/debug/`.

---

## ⚖️ Legal & Disclaimer

This project is an independent educational and research decompilation port. All original game concepts, characters, creature designs, trade names, and underlying assets remain the property of their respective trademark holders and copyright owners. 

This repository contains no commercial game ROMs, proprietary BIOS binaries, or copyrighted assets. Users must supply and dump their own legally acquired game data. This project is not affiliated with, sponsored by, or endorsed by any console manufacturer or game publisher.
