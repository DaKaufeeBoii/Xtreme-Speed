# Xtremespeed – Audit & Plan

## 1. Goal (as inferred from code)
Native (no emulator) PC → Android port of Gen 3 as a **combined Hoenn → Kanto journey**:
- Beat Hoenn, sail S.S. Tidal to Vermilion Port, run a Kanto gym circuit (Surge→Misty→Brock→Erika→Sabrina→Koga→Blaine→Blue@Viridian), level caps 60–78, Red at Indigo (88), post-game "Operation Eclipse".
- Modern QoL (phys/special split, Fairy, indoor run, infinite TMs, level caps, etc.), widescreen, SDL2, touch UI on Android, ROM-ingestion (user supplies ROMs).

**Confirmed by user:** Emerald base, with Kanto content from FireRed placed *inside the Hoenn region*. Option A below is final; Option B (FireRed-only) is dropped.

**Open design decision (Phase 0):** integration model. (M1) Kanto towns/routes/gyms as real maps added to Hoenn's world (own map group, connected via routes/warps, no S.S. Tidal needed); or (M2) Kanto *content* (leaders, trainers, mons, areas) woven into existing Hoenn maps/gyms. Current code is a hybrid of both, which is why leaders and spawns are displaced. Phase 2 importer is the same for both; Phase 3 differs (M1 = map placement + connections; M2 = per-map event/trainer/gym replacement tables).

## 2. What exists
| Part | State |
|---|---|
| `src/pokeemerald-multiplatform` | Emerald decomp + SDL port, 53 modified files, `Makefile_pc`, mods/ runtime patch system. Real engine. |
| `build_kanto_full.py` | Reads **FireRed ROM bytes**, maps FR metatiles → ~15 Emerald metatiles by hand-guessed rules. |
| `extract_kanto_events.py` | Scrapes FR objects/warps from ROM; hardcoded "approx" gym door coords; placeholder NPC text. |
| `engine/` (+ `PokemonGen3.exe`, `libpokegen3.a`) | **~2.7k-line ARM CPU/PPU/APU emulator** + carousel launcher. Contradicts "no emulator"; incomplete. Dead weight / confusion. |
| `ports/android` + `src/.../android` | Two Android trees; APK built. |
| `crash_dump.txt` | Null read AV @ 0x006bfb5c – unresolved. |
| Repo root | 597 MB incl. ROMs, saves, exes, logs, pycache – no git at root. |

## 3. Root causes of reported issues
1. **Weird Kanto maps** – `map_fr_metatile_to_emerald()` collapses FR's 640+ metatiles into a handful of Emerald ones using `General+Petalburg` for every map. Tileset art, palettes, behaviours, and layers are lost. All 37 Kanto layouts use `gTileset_General/gTileset_Petalburg`. Not fixable by tweaking the table – the approach is wrong.
2. **Displaced leaders / spawns** –
   - **107 of 148** Kanto warps fall back to `MAP_KANTO_PALLETTOWN` (unmapped FR map IDs). Interiors (houses, gyms, centers, marts) don't exist as real Kanto maps.
   - Gym warps use hand "approx" coords, and conflict with the extracted ones (Vermilion gym: script says 15,19; events.inc has 14,25).
   - Gym maps (e.g. `PewterCity_Gym`) are stubs: 1 object, 1 warp, `MAN_5` as leader. Coordinates come from the FR layout but tiles come from Emerald art → leader sits in walls/void.
   - FR→Emerald gfx table falls back to `MAN_1`; mis-maps (Poochyena for a dog, Snorlax doll).
   - Object x/y read from FR without accounting for FR's +7 offset convention vs. layout (verify; FR map coords are raw, same as decomp, but border/size mismatches shift after metatile resizing).
3. **Other** – 0 Kanto trainers (no trainer events extracted), NPC text = "Welcome to Kanto!", Kanto wild data only partially in `wild_encounters.json`, Android + PC duplicate codebases, emulator dir.

## 4. Strategy (decision: stop ROM-scraping, port decomp → decomp)
Both Emerald and FireRed have full open decomps with `map.json`, `layouts`, tilesets, scripts, trainers, encounters. Use those as source of truth, not ROM bytes.

**Option A – recommended: Emerald-expansion base + real Kanto import**
- Base: `pokeemerald-expansion` (already has phys/special split, Fairy, many QoL). Keep SDL2 port layer as a thin platform patch.
- Add FR tilesets as new tilesets (`gTileset_FRLG_General`, etc.): copy `tiles.png`, palettes, `metatiles.bin`, convert `metatile_attributes.bin` (FR 32-bit → expansion 32-bit/16-bit per version).
- Import FR maps with a script from pret/pokefirered `data/maps/*/map.json` + `layouts.json`: rename `MAP_X`→`MAP_KANTO_X`, remap tilesets, flags, vars, trainers, object gfx (FR-only sprites copied in), map sections, music.
- Pros: exact maps, interiors, gym puzzles, trainers, text. Cons: engine diff (FR script cmds like `trainerbattle`, `setvaddress` vs Emerald), need dual-palette handling.

*(Option B, FireRed-only, dropped.)*

## 5. Phases
**Phase 0 – Decide & clean (½ day)**
- Choose A or B. Init git at project root; `.gitignore` ROMs, saves, exes, logs, build/, __pycache__.
- Move `engine/`, `PokemonGen3.exe`, carousel into `legacy/` (delete after A/B decision). Keep the carousel only if it launches the native exe.
- Reproduce crash (`crash_dump.txt`) with debug build + addr2line on `pokeemerald.exe`; fix before new work.

**Phase 1 – Reliable PC build baseline (1–2 days)**
- One command build (`make -f Makefile_pc`, MSYS2/MinGW), CI-style smoke test (boot → new game → save → reload).
- Verify existing Hoenn is vanilla-correct before adding Kanto.

**Phase 2 – Real Kanto importer (3–5 days)** *(Option A)*
1. Tileset converter (+ palette slot check: FR uses 6 primary/7 secondary palettes; Emerald same, verify).
2. Map importer from pret/pokefirered JSON: all 37 outdoor + all interiors reachable in the circuit (gyms, centers, marts, houses, Silph Co, Game Corner, Pokémon Tower, Cerulean Cave, E4, Viridian Forest, Mt. Moon, Rock Tunnel, Power Plant, Seafoam, Victory Road, Diglett's Cave, Safari Zone optional).
3. Resolve every warp via map-name table; **fail the build on unresolved warps** (kills the Pallet fallback).
4. Objects: copy FR sprites into object-event graphics; no fallback sprite – error instead.
5. Scripts: translate FR `.inc` scripts (macro mapping table) or rewrite per-map; import text strings from `text.inc`, not ROM decoding.
6. Trainers/parties/encounters: import and then apply level scaling pass (60–88).
7. Validation script: every warp has reverse warp, objects not on collision tiles, player spawn walkable, leaders within gym bounds, connections symmetrical.

**Phase 3 – Story & progression (2–3 days)**
- S.S. Tidal → Vermilion Port arrival warp + spawn; gym order flags/badges 9–16; Blue replaces Giovanni, Red at Summit; level caps table in one data file; Operation Eclipse scripting last.

**Phase 4 – QoL checklist (2–3 days)**
Fairy, phys/special split (expansion), indoor run, auto-run, HM-free, EXP share, level caps, fast-forward, relearner, IV/EV checker, 999 stacks, bag sort, hotkeys, nature colours, repel prompt. Test matrix per feature.

**Phase 5 – PC polish & verification gate**
Widescreen, config/menu, saves/backup, controller, audio. Gate: full playthrough Hoenn→Kanto→Red with no softlocks, QoL checklist signed off, validation script green.

**Phase 6 – Android (only after gate)**
Merge the two Android trees into one, shared C core via SDL2/NDK, portrait + landscape expanded view, floating thumbstick + overlay buttons, in-game settings, haptics, save compat with PC, ROM picker (SAF).

## 6. Immediate next actions
1. Pick integration model M1 or M2.
2. Git init + cleanup + crash repro.
3. Build the warp/object validator first (it will list every current defect precisely).
4. Start tileset converter on Pallet Town + Pewter Gym as the pilot, then scale.