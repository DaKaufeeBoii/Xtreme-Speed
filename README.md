# Xtreme-Speed — Cross-Platform Native Source Port (PC & Android)
### Pokémon Emerald • Pokémon FireRed • Pokémon Ruby • Pokémon Sapphire
**True Native Decompilation • 60 FPS Widescreen • Startup Carousel • Floating Dynamic Thumbstick**

**Xtreme-Speed** is a high-performance, 100% native cross-platform port running Pokémon Generation 3 games directly on **PC (Windows)** and **Android (ARM64 / ARMv7)** using the decompiled C engine with SDL2 hardware presentation.

> **Zero generic emulators (no mGBA, no VBA). Zero web/network dependencies.**  
> Compiles directly to native host machine code for instantaneous load times, 60 FPS presentation, and true widescreen camera expansions.

---

## 🌟 Key Features

### 1. The Vermilion Geographical Circuit (Kanto Gym Progression)
When sailing from Hoenn (Slateport / Lilycove) to Kanto via the S.S. Tidal, the ship docks at **Vermilion City Harbor**. The classic Pallet Town/Pewter starting sequence is replaced by a continuous geographical circuit flowing outward from the landing port:

| Gym # | Leader | City / Location | Level Cap | Badge |
|:---:|---|---|:---:|:---:|
| **1** | **Lt. Surge** | **Vermilion City** *(Port Arrival)* | **60** | **Thunder Badge** |
| **2** | **Misty** | **Cerulean City** | **62** | **Cascade Badge** |
| **3** | **Brock** | **Pewter City** | **64** | **Boulder Badge** |
| **4** | **Erika** | **Celadon City** | **66** | **Rainbow Badge** |
| **5** | **Sabrina** | **Saffron City** | **68** | **Marsh Badge** |
| **6** | **Koga** | **Fuchsia City** | **71** | **Soul Badge** |
| **7** | **Blaine** | **Cinnabar Island** | **74** | **Volcano Badge** |
| **8** | **Blue** *(New Viridian Leader)* | **Viridian City** | **78** | **Earth Badge** |
| **🏆** | **Red** *(Summit Champion)* | **Indigo Plateau** | **88** | **League Champion** |

> **Giovanni Replaced by Blue**: Following the collapse of Team Rocket, **Blue** has taken over as the Viridian Gym Leader with an all-around powerhouse team (Pidgeot, Alakazam, Rhydon, Gyarados, Exeggutor, Arcanine).  
> **Champion Red**: The final summit of Indigo Plateau features legendary trainer **Red** with his iconic summit team (Pikachu @ Light Ball, Espeon, Snorlax @ Leftovers, Venusaur, Charizard, Blastoise).

### 2. 3D Cover Flow Carousel with Official Box Art
- Built into [`PokemonGen3.exe`](file:///d:/Kaufee/projects/personal/pc-port/PokemonGen3.exe) and launched via [`Play Xtreme-Speed (Game Select).bat`](file:///d:/Kaufee/projects/personal/pc-port/Play%20Xtreme-Speed%20(Game%20Select).bat).
- Renders **authentic official box art** for every title with perspective card scaling, active card glow, and atmospheric depth dimming:
  - 🌟 **Xtreme-Speed: Combined Journey**: Custom fusion artwork featuring Rayquaza & Charizard with inter-regional travel.
  - 🌿 **Pokémon Emerald Version**: Official Emerald box art featuring Rayquaza.
  - 🔥 **Pokémon FireRed Version**: Official FireRed box art featuring Charizard.
  - 🔴 **Pokémon Ruby Version**: Official Ruby box art featuring Groudon.
  - 🔵 **Pokémon Sapphire Version**: Official Sapphire box art featuring Kyogre.
- **Flicker-Free Double-Buffered Typography**: GDI text rendering is composited off-screen on a hardware memory DC and blitted atomically, eliminating visual tearing and glitching.

### 3. Legal ROM Ingestion & Asset Collection Wizard
- Automated asset detection pipeline via [`Build & Collect Assets.bat`](file:///d:/Kaufee/projects/personal/pc-port/Build%20&%20Collect%20Assets.bat) and in-launcher hotkey `[F2]`.
- Checks for user-supplied dumped cartridges in `roms/`:
  - `roms/pokemon-emerald.gba`
  - `roms/pokemon-firered.gba`
  - `roms/pokemon-ruby.gba`
  - `roms/pokemon-sapphire.gba`
- If any ROM is missing, the launcher prompts the user with cartridge dumping instructions and opens the folder with one click.

### 4. Post-Game Expansion Storyline: "Operation Eclipse"
- Exiled remnants of **Team Magma** and **Team Aqua** have fled Hoenn and allied with **Team Rocket's** underground cells in Kanto.
- Interpol Detective **Looker** and former Champion **Steven Stone** intercept the player at Vermilion Port to investigate Cerulean Cave and the celestial enigma at Birth Island.
- Awards the **Aurora Ticket**, **Mystic Ticket**, and uninhibited inter-regional transit.

### 5. Developer Debug Menu (`F1` / `~`) & Modern QoL Suite
- Press **`F1`** or **`~`** (Tilde) at any point to open the in-game Debug, Challenges, and QoL Dashboard.
- Features:
  - **Physical / Special Move Split**
  - **Infinite TMs** (reusable like Gen 5+)
  - **Indoor Running**
  - **Modern Fairy Types & Moves**
  - **Dynamic Level Caps & Nuzlocke Rules**
  - **Shiny Multipliers & EXP Multipliers**
  - **Full Party Heals, Item Dispensing, & Map Warps**

### 6. Android Mobile Port (`ports/android/`)
- **Floating Dynamic Thumbstick**: Virtual D-pad anchors anywhere the player touches on the left half of the display.
- **Micro-Haptics**: Tactile vibration feedback on button presses.
- Output APK generated at [`ports/android/app/build/outputs/apk/debug/app-debug.apk`](file:///d:/Kaufee/projects/personal/pc-port/ports/android/app/build/outputs/apk/debug/app-debug.apk).

---

## 🚀 Running on PC (Windows)

Double-click any launcher:

- [**Play Xtreme-Speed (Game Select).bat**](file:///d:/Kaufee/projects/personal/pc-port/Play%20Xtreme-Speed%20(Game%20Select).bat) — Interactive 3D Game Selector with box art & double-buffering.
- [**Play Xtreme-Speed (Native PC).bat**](file:///d:/Kaufee/projects/personal/pc-port/Play%20Xtreme-Speed%20(Native%20PC).bat) — Launches Xtreme-Speed natively.
- [**Build & Collect Assets.bat**](file:///d:/Kaufee/projects/personal/pc-port/Build%20&%20Collect%20Assets.bat) — Legal ROM verification and asset extraction wizard.
- [**pokeemerald.exe**](file:///d:/Kaufee/projects/personal/pc-port/pokeemerald.exe) — The direct native executable.

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
| **Developer Debug Menu** | **F1** | **`~` (Tilde)** | — |
| **Legal ROM Dump Wizard** | **F2** | — | — |
| **Fast Forward** | **Space** | — | — |
| **Soft Reset** | **Ctrl + R** | — | — |
| **Pause Game** | **Ctrl + P** | — | — |
