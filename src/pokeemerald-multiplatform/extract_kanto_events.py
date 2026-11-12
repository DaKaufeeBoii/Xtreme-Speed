import struct
import json
import os

rom_path = 'roms/pokemon-firered.gba' if os.path.exists('roms/pokemon-firered.gba') else '../../roms/pokemon-firered.gba'
with open(rom_path, 'rb') as f:
    rom = f.read()

bank3_off = 0x3522f4

# Mapping from FireRed Bank 3 index to our Kanto map directory and ID
kanto_map_indices = {
    0: ('Kanto_PalletTown', 'MAP_KANTO_PALLETTOWN'),
    1: ('Kanto_ViridianCity', 'MAP_KANTO_VIRIDIANCITY'),
    2: ('Kanto_PewterCity', 'MAP_KANTO_PEWTERCITY'),
    3: ('Kanto_CeruleanCity', 'MAP_KANTO_CERULEANCITY'),
    4: ('Kanto_LavenderTown', 'MAP_KANTO_LAVENDERTOWN'),
    5: ('Kanto_VermilionCity', 'MAP_KANTO_VERMILIONCITY'),
    6: ('Kanto_CeladonCity', 'MAP_KANTO_CELADONCITY'),
    7: ('Kanto_FuchsiaCity', 'MAP_KANTO_FUCHSIACITY'),
    8: ('Kanto_CinnabarIsland', 'MAP_KANTO_CINNABARISLAND'),
    9: ('Kanto_IndigoPlateau', 'MAP_KANTO_INDIGOPLATEAU'),
    10: ('Kanto_SaffronCity', 'MAP_KANTO_SAFFRONCITY'),
    19: ('Kanto_Route1', 'MAP_KANTO_ROUTE1'),
    20: ('Kanto_Route2', 'MAP_KANTO_ROUTE2'),
    21: ('Kanto_Route3', 'MAP_KANTO_ROUTE3'),
    22: ('Kanto_Route4', 'MAP_KANTO_ROUTE4'),
    23: ('Kanto_Route5', 'MAP_KANTO_ROUTE5'),
    24: ('Kanto_Route6', 'MAP_KANTO_ROUTE6'),
    25: ('Kanto_Route7', 'MAP_KANTO_ROUTE7'),
    26: ('Kanto_Route8', 'MAP_KANTO_ROUTE8'),
    27: ('Kanto_Route9', 'MAP_KANTO_ROUTE9'),
    28: ('Kanto_Route10', 'MAP_KANTO_ROUTE10'),
    29: ('Kanto_Route11', 'MAP_KANTO_ROUTE11'),
    30: ('Kanto_Route12', 'MAP_KANTO_ROUTE12'),
    31: ('Kanto_Route13', 'MAP_KANTO_ROUTE13'),
    32: ('Kanto_Route14', 'MAP_KANTO_ROUTE14'),
    33: ('Kanto_Route15', 'MAP_KANTO_ROUTE15'),
    34: ('Kanto_Route16', 'MAP_KANTO_ROUTE16'),
    35: ('Kanto_Route17', 'MAP_KANTO_ROUTE17'),
    36: ('Kanto_Route18', 'MAP_KANTO_ROUTE18'),
    37: ('Kanto_Route19', 'MAP_KANTO_ROUTE19'),
    38: ('Kanto_Route20', 'MAP_KANTO_ROUTE20'),
    39: ('Kanto_Route21_North', 'MAP_KANTO_ROUTE21_NORTH'),
    40: ('Kanto_Route21_South', 'MAP_KANTO_ROUTE21_SOUTH'),
    41: ('Kanto_Route22', 'MAP_KANTO_ROUTE22'),
    42: ('Kanto_Route23', 'MAP_KANTO_ROUTE23'),
    43: ('Kanto_Route24', 'MAP_KANTO_ROUTE24'),
    44: ('Kanto_Route25', 'MAP_KANTO_ROUTE25')
}

# Mapping FireRed sprite ID to Emerald OBJ_EVENT_GFX_* constant
fr_to_emerald_gfx = {
    16: "OBJ_EVENT_GFX_LITTLE_BOY",
    17: "OBJ_EVENT_GFX_LITTLE_GIRL",
    18: "OBJ_EVENT_GFX_BOY_1",
    19: "OBJ_EVENT_GFX_BOY_2",
    20: "OBJ_EVENT_GFX_BUG_CATCHER",
    22: "OBJ_EVENT_GFX_LASS",
    23: "OBJ_EVENT_GFX_WOMAN_1",
    24: "OBJ_EVENT_GFX_BEAUTY",
    25: "OBJ_EVENT_GFX_MAN_1",
    26: "OBJ_EVENT_GFX_MAN_3",
    27: "OBJ_EVENT_GFX_FAT_MAN",
    28: "OBJ_EVENT_GFX_WOMAN_2",
    29: "OBJ_EVENT_GFX_BEAUTY",
    30: "OBJ_EVENT_GFX_MAN_2",
    31: "OBJ_EVENT_GFX_WOMAN_3",
    32: "OBJ_EVENT_GFX_OLD_MAN",
    33: "OBJ_EVENT_GFX_OLD_MAN",
    36: "OBJ_EVENT_GFX_SWIMMER_M",
    39: "OBJ_EVENT_GFX_SWIMMER_F",
    40: "OBJ_EVENT_GFX_SWIMMER_M",
    41: "OBJ_EVENT_GFX_SWIMMER_F",
    43: "OBJ_EVENT_GFX_SAILOR",
    44: "OBJ_EVENT_GFX_FISHERMAN",
    45: "OBJ_EVENT_GFX_SCIENTIST_1",
    47: "OBJ_EVENT_GFX_GENTLEMAN",
    49: "OBJ_EVENT_GFX_BLACK_BELT",
    52: "OBJ_EVENT_GFX_CAMPER",
    53: "OBJ_EVENT_GFX_PICNICKER",
    54: "OBJ_EVENT_GFX_MAN_5",
    55: "OBJ_EVENT_GFX_WOMAN_5",
    56: "OBJ_EVENT_GFX_SWIMMER_M",
    57: "OBJ_EVENT_GFX_SWIMMER_F",
    60: "OBJ_EVENT_GFX_MANIAC",
    62: "OBJ_EVENT_GFX_HIKER",
    68: "OBJ_EVENT_GFX_CYCLING_TRIATHLETE_M",
    71: "OBJ_EVENT_GFX_SCIENTIST_1",
    72: "OBJ_EVENT_GFX_BOY_3",
    73: "OBJ_EVENT_GFX_MAN_4",
    92: "OBJ_EVENT_GFX_ITEM_BALL",
    95: "OBJ_EVENT_GFX_BIG_SNORLAX_DOLL",
    108: "OBJ_EVENT_GFX_CUTTABLE_TREE",
    109: "OBJ_EVENT_GFX_BREAKABLE_ROCK",
    112: "OBJ_EVENT_GFX_AZUMARILL",
    114: "OBJ_EVENT_GFX_WINGULL",
    117: "OBJ_EVENT_GFX_WINGULL",
    119: "OBJ_EVENT_GFX_WINGULL",
    127: "OBJ_EVENT_GFX_WINGULL",
    128: "OBJ_EVENT_GFX_SKITTY",
    129: "OBJ_EVENT_GFX_POOCHYENA",
    130: "OBJ_EVENT_GFX_POOCHYENA",
    135: "OBJ_EVENT_GFX_BIG_RHYDON_DOLL",
    240: "OBJ_EVENT_GFX_ITEM_BALL"
}

# FireRed movement types to Emerald MOVEMENT_TYPE_*
fr_to_emerald_mov = {
    0: "MOVEMENT_TYPE_NONE",
    1: "MOVEMENT_TYPE_LOOK_AROUND",
    2: "MOVEMENT_TYPE_WANDER_AROUND",
    7: "MOVEMENT_TYPE_FACE_DOWN",
    8: "MOVEMENT_TYPE_FACE_UP",
    9: "MOVEMENT_TYPE_FACE_LEFT",
    10: "MOVEMENT_TYPE_FACE_RIGHT"
}

# Known gym warp targets
gym_warps = {
    'Kanto_PewterCity': ('MAP_PEWTER_CITY_GYM', 16, 17), # approx door coords
    'Kanto_CeruleanCity': ('MAP_CERULEAN_CITY_GYM', 30, 19),
    'Kanto_VermilionCity': ('MAP_VERMILION_CITY_GYM', 15, 19),
    'Kanto_CeladonCity': ('MAP_CELADON_CITY_GYM', 18, 29),
    'Kanto_FuchsiaCity': ('MAP_FUCHSIA_CITY_GYM', 8, 27),
    'Kanto_SaffronCity': ('MAP_SAFFRON_CITY_GYM', 34, 14),
    'Kanto_CinnabarIsland': ('MAP_CINNABAR_ISLAND_GYM', 18, 9),
    'Kanto_ViridianCity': ('MAP_VIRIDIAN_CITY_GYM', 32, 7),
}

total_objs = 0
total_warps = 0
total_bgs = 0

for idx, (map_dir, map_id) in kanto_map_indices.items():
    mptr = struct.unpack('<I', rom[bank3_off + idx*4 : bank3_off + (idx+1)*4])[0]
    moff = mptr & 0x1FFFFFF
    layout_ptr, events_ptr, scripts_ptr, conn_ptr = struct.unpack('<IIII', rom[moff : moff + 16])
    ev_off = events_ptr & 0x1FFFFFF
    obj_count, warp_count, coord_count, bg_count, obj_ptr, warp_ptr, coord_ptr, bg_ptr = struct.unpack('<BBBBIIII', rom[ev_off : ev_off + 20])

    map_json_path = f'data/maps/{map_dir}/map.json'
    scripts_path = f'data/maps/{map_dir}/scripts.inc'

    if not os.path.exists(map_json_path):
        continue

    with open(map_json_path, 'r', encoding='utf-8') as f:
        map_json = json.load(f)

    # 1. Extract Objects
    object_events = []
    script_lines = [f"{map_dir}_MapScripts::\n\t.byte 0\n"]

    o_off = obj_ptr & 0x1FFFFFF
    for i in range(obj_count):
        b = rom[o_off + i*24 : o_off + (i+1)*24]
        lid = b[0]
        gid = b[1]
        x, y = struct.unpack('<hh', b[4:8])
        elevation = b[8]
        mtype = b[9]
        mrange = b[10]

        gfx_name = fr_to_emerald_gfx.get(gid, "OBJ_EVENT_GFX_MAN_1")
        mov_name = fr_to_emerald_mov.get(mtype, "MOVEMENT_TYPE_LOOK_AROUND")

        script_name = f"{map_dir}_EventScript_NPC_{i+1}"
        object_events.append({
            "graphics_id": gfx_name,
            "x": x,
            "y": y,
            "elevation": 3,
            "movement_type": mov_name,
            "movement_range_x": 1 if mov_name == "MOVEMENT_TYPE_WANDER_AROUND" else 0,
            "movement_range_y": 1 if mov_name == "MOVEMENT_TYPE_WANDER_AROUND" else 0,
            "trainer_type": "TRAINER_TYPE_NONE",
            "trainer_sight_or_berry_tree_id": "0",
            "script": script_name,
            "flag": "0"
        })

        # Add generic pleasant dialogue
        script_lines.append(f"{script_name}::\n\tmsgbox {map_dir}_Text_NPC_{i+1}, MSGBOX_NPC\n\tend\n")
        script_lines.append(f"{map_dir}_Text_NPC_{i+1}:\n\t.string \"Welcome to Kanto!\\nIt's great to meet trainers from HOENN!$\"\n")

    # 2. Extract Warps
    warp_events = []
    w_off = warp_ptr & 0x1FFFFFF
    for i in range(warp_count):
        x, y, elev, wid, mnum, mgrp = struct.unpack('<hhBBBB', rom[w_off + i*8 : w_off + (i+1)*8])
        # Check if this city has a Gym warp
        dest_map = "MAP_KANTO_PALLETTOWN" # fallback
        dest_warp = "0"

        if map_dir in gym_warps:
            gmap, gx, gy = gym_warps[map_dir]
            if abs(x - gx) <= 1 and abs(y - gy) <= 1:
                dest_map = gmap
                dest_warp = "0"
            elif map_dir == 'Kanto_IndigoPlateau':
                dest_map = "MAP_INDIGO_PLATEAU_SUMMIT"
                dest_warp = "0"

        # If it's a general door warp, keep player on outdoor or link to Gym
        warp_events.append({
            "x": x,
            "y": y,
            "elevation": 0,
            "dest_map": dest_map,
            "dest_warp_id": dest_warp
        })

    # 3. Extract BG Events
    bg_events = []
    b_off = bg_ptr & 0x1FFFFFF
    for i in range(bg_count):
        b = rom[b_off + i*12 : b_off + (i+1)*12]
        x, y = struct.unpack('<hh', b[0:4])
        kind = b[5]
        sign_script = f"{map_dir}_EventScript_Sign_{i+1}"
        bg_events.append({
            "type": "sign",
            "x": x,
            "y": y,
            "elevation": 0,
            "player_facing_dir": "BG_EVENT_PLAYER_FACING_ANY",
            "script": sign_script
        })
        script_lines.append(f"{sign_script}::\n\tmsgbox {map_dir}_Text_Sign_{i+1}, MSGBOX_SIGN\n\tend\n")
        script_lines.append(f"{map_dir}_Text_Sign_{i+1}:\n\t.string \"{map_dir.replace('Kanto_', '').replace('_', ' ')}\\nKANTO REGION$\"\n")

    map_json["object_events"] = object_events
    map_json["warp_events"] = warp_events
    map_json["bg_events"] = bg_events

    with open(map_json_path, 'w', encoding='utf-8') as f:
        json.dump(map_json, f, indent=2)

    with open(scripts_path, 'w', encoding='utf-8') as f:
        f.writelines(script_lines)

    total_objs += len(object_events)
    total_warps += len(warp_events)
    total_bgs += len(bg_events)

print(f"Extraction complete! Injected {total_objs} NPCs, {total_warps} Warps, {total_bgs} Signs across 37 maps.")
