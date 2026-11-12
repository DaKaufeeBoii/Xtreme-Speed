import struct, json, os, glob

# 1. Load Species Constants
species_map = {}
with open('src/pokeemerald-multiplatform/include/constants/species.h', 'r', encoding='utf-8') as f:
    for line in f:
        line = line.strip()
        if line.startswith('#define SPECIES_') and not line.startswith('#define SPECIES_NONE'):
            parts = line.split()
            if len(parts) >= 3:
                name = parts[1]
                try:
                    val = int(parts[2], 0)
                    species_map[val] = name
                except:
                    pass

print(f'Loaded {len(species_map)} species constants.')

# 2. Map FireRed (group, map) to Kanto map ID
# We already matched 256 Kanto maps to ROM maps in extract_all_dialogues!
with open('roms/pokemon-firered.gba', 'rb') as f:
    rom = f.read()

# Load map fingerprinting to map (bank, map) -> MAP_KANTO_*
bank_tbl_ptr = 0x3526a8
rom_maps = {}
for b in range(43):
    bptr = struct.unpack('<I', rom[bank_tbl_ptr + b*4 : bank_tbl_ptr + (b+1)*4])[0] & 0x1FFFFFF
    next_bptr = struct.unpack('<I', rom[bank_tbl_ptr + (b+1)*4 : bank_tbl_ptr + (b+2)*4])[0] & 0x1FFFFFF
    count = (next_bptr - bptr) // 4
    for m in range(count):
        mptr = struct.unpack('<I', rom[bptr + m*4 : bptr + (m+1)*4])[0] & 0x1FFFFFF
        l_ptr, ev_ptr, sc_ptr, co_ptr = struct.unpack('<IIII', rom[mptr : mptr + 16])
        l_off = l_ptr & 0x1FFFFFF
        w, h = struct.unpack('<II', rom[l_off : l_off + 8])
        ev_off = ev_ptr & 0x1FFFFFF
        obj_c, warp_c, coord_c, bg_c, o_ptr, w_ptr, c_ptr, b_ptr = struct.unpack('<BBBBIIII', rom[ev_off : ev_off + 20])
        rom_maps[(b, m)] = {'w': w, 'h': h, 'obj_c': obj_c, 'warp_c': warp_c, 'bg_c': bg_c, 'mptr': mptr}

kanto_maps = glob.glob(r'src/pokeemerald-multiplatform/data/maps/Kanto_*/map.json')
fr_to_kanto = {}
for km in kanto_maps:
    with open(km, 'r', encoding='utf-8') as f:
        kd = json.load(f)
    mid = kd['id']
    k_objs = len(kd.get('object_events', []))
    k_warps = len(kd.get('warp_events', []))
    k_bgs = len(kd.get('bg_events', []))
    for (b, m), rinfo in rom_maps.items():
        if rinfo['obj_c'] == k_objs and rinfo['warp_c'] == k_warps and rinfo['bg_c'] == k_bgs:
            fr_to_kanto[(b, m)] = mid
            break

print(f'Mapped {len(fr_to_kanto)} FireRed maps to Kanto IDs.')

# 3. Read gWildMonHeaders from FireRed ROM
wild_addr = 0x3c9cb8

def scale_level(orig_min, orig_max):
    # Scale from 2-55 to 50-65
    s_min = max(50, min(65, int(50 + (orig_min / 52.0) * 14)))
    s_max = max(s_min, min(65, int(50 + (orig_max / 52.0) * 14)))
    return s_min, s_max

kanto_encounters = []
while True:
    b, m = rom[wild_addr], rom[wild_addr+1]
    if b == 0xFF and m == 0xFF:
        break
    p_land, p_water, p_rock, p_fish = struct.unpack('<IIII', rom[wild_addr+4 : wild_addr+20])
    wild_addr += 20
    
    mid = fr_to_kanto.get((b, m))
    if not mid:
        continue
        
    base_lbl = 'g' + mid[4:].title().replace('_', '')
    enc_entry = {
        'map': mid,
        'base_label': base_lbl
    }
    
    # Land
    if p_land != 0:
        off = p_land & 0x1FFFFFF
        rate = rom[off]
        mons = []
        for i in range(12):
            min_l, max_l, sp_id = struct.unpack('<BBH', rom[off+4+i*4 : off+8+i*4])
            s_min, s_max = scale_level(min_l, max_l)
            sp_name = species_map.get(sp_id, 'SPECIES_PIDGEY')
            mons.append({'min_level': s_min, 'max_level': s_max, 'species': sp_name})
        enc_entry['land_mons'] = {'encounter_rate': rate, 'mons': mons}
        
    # Water
    if p_water != 0:
        off = p_water & 0x1FFFFFF
        rate = rom[off]
        mons = []
        for i in range(5):
            min_l, max_l, sp_id = struct.unpack('<BBH', rom[off+4+i*4 : off+8+i*4])
            s_min, s_max = scale_level(min_l, max_l)
            sp_name = species_map.get(sp_id, 'SPECIES_TENTACOOL')
            mons.append({'min_level': s_min, 'max_level': s_max, 'species': sp_name})
        enc_entry['water_mons'] = {'encounter_rate': rate, 'mons': mons}
        
    # Rock Smash
    if p_rock != 0:
        off = p_rock & 0x1FFFFFF
        rate = rom[off]
        mons = []
        for i in range(5):
            min_l, max_l, sp_id = struct.unpack('<BBH', rom[off+4+i*4 : off+8+i*4])
            s_min, s_max = scale_level(min_l, max_l)
            sp_name = species_map.get(sp_id, 'SPECIES_GEODUDE')
            mons.append({'min_level': s_min, 'max_level': s_max, 'species': sp_name})
        enc_entry['rock_smash_mons'] = {'encounter_rate': rate, 'mons': mons}
        
    # Fishing
    if p_fish != 0:
        off = p_fish & 0x1FFFFFF
        rate = rom[off]
        mons = []
        for i in range(10):
            min_l, max_l, sp_id = struct.unpack('<BBH', rom[off+4+i*4 : off+8+i*4])
            s_min, s_max = scale_level(min_l, max_l)
            sp_name = species_map.get(sp_id, 'SPECIES_MAGIKARP')
            mons.append({'min_level': s_min, 'max_level': s_max, 'species': sp_name})
        enc_entry['fishing_mons'] = {'encounter_rate': rate, 'mons': mons}
        
    kanto_encounters.append(enc_entry)

print(f'Generated {len(kanto_encounters)} Kanto wild encounter entries!')

# 4. Inject into wild_encounters.json
we_path = 'src/pokeemerald-multiplatform/src/data/wild_encounters.json'
with open(we_path, 'r', encoding='utf-8') as f:
    we_data = json.load(f)

# Keep existing Hoenn encounters and remove any old Kanto
existing_hoenn = [e for e in we_data['wild_encounter_groups'][0]['encounters'] if 'KANTO' not in e['map']]
we_data['wild_encounter_groups'][0]['encounters'] = existing_hoenn + kanto_encounters

with open(we_path, 'w', encoding='utf-8', newline='\n') as f:
    json.dump(we_data, f, indent=2)
    f.write('\n')

print('Successfully written updated wild_encounters.json!')
