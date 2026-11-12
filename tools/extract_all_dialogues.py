import os, struct, json, glob, re

charmap = {
    0x00: ' ', 0xFE: r'\n', 0xFA: r'\p', 0xFB: r'\l',
    0x1B: 'e', 0xDE: 'f', 0x01: 'A', 0x02: 'B', 0x03: 'C',
    0x5B: r'\l',
    0xAA: '9', 0xA1: '0', 0xA2: '1', 0xA3: '2', 0xA4: '3', 0xA5: '4',
    0xA6: '5', 0xA7: '6', 0xA8: '7', 0xA9: '8',
    0xAB: '!', 0xAC: '?', 0xAD: '.', 0xAE: '-', 0xAF: '・', 0xB0: '…',
    0xB8: ',', 0xBA: '/',
    0xBB: 'A', 0xBC: 'B', 0xBD: 'C', 0xBE: 'D', 0xBF: 'E', 0xC0: 'F',
    0xC1: 'G', 0xC2: 'H', 0xC3: 'I', 0xC4: 'J', 0xC5: 'K', 0xC6: 'L',
    0xC7: 'M', 0xC8: 'N', 0xC9: 'O', 0xCA: 'P', 0xCB: 'Q', 0xCC: 'R',
    0xCD: 'S', 0xCE: 'T', 0xCF: 'U', 0xD0: 'V', 0xD1: 'W', 0xD2: 'X',
    0xD3: 'Y', 0xD4: 'Z',
    0xD5: 'a', 0xD6: 'b', 0xD7: 'c', 0xD8: 'd', 0xD9: 'e', 0xDA: 'f',
    0xDB: 'g', 0xDC: 'h', 0xDD: 'i', 0xDE: 'j', 0xDF: 'k', 0xE0: 'l',
    0xE1: 'm', 0xE2: 'n', 0xE3: 'o', 0xE4: 'p', 0xE5: 'q', 0xE6: 'r',
    0xE7: 's', 0xE8: 't', 0xE9: 'u', 0xEA: 'v', 0xEB: 'w', 0xEC: 'x',
    0xED: 'y', 0xEE: 'z',
    0xF0: ':', 0xB5: "'", 0xB6: "'"
}

cm_path = 'src/pokeemerald-multiplatform/charmap.txt'
if os.path.exists(cm_path):
    with open(cm_path, 'r', encoding='utf-8') as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith('#'): continue
            if '=' in line:
                parts = line.split('=', 1)
                char = parts[0].strip()
                if char.startswith("'") and char.endswith("'") and len(char) >= 2:
                    char = char[1:-1]
                val = parts[1].strip()
                try:
                    code = int(val, 16)
                    if code not in charmap and code < 0xFA:
                        charmap[code] = char
                except:
                    pass

charmap[0x1B] = 'e'
charmap[0x00] = ' '
charmap[0xFE] = r'\n'
charmap[0xFA] = r'\p'
charmap[0xFB] = r'\l'
charmap[0xB5] = "'"
charmap[0xB6] = "'"
charmap[0xAD] = '.'
charmap[0xB8] = ','
charmap[0xAB] = '!'
charmap[0xAC] = '?'
charmap[0xAE] = '-'
charmap[0xBA] = '/'
charmap[0xF0] = ':'

with open('roms/pokemon-firered.gba', 'rb') as f:
    rom = f.read()

def decode_rom_str(ptr):
    off = ptr & 0x1FFFFFF
    if off <= 0 or off >= len(rom): return ""
    res = []
    while off < len(rom):
        b = rom[off]
        off += 1
        if b == 0xFF:
            break
        elif b == 0xFD:
            ctrl = rom[off]; off += 1
            if ctrl == 1: res.append('{PLAYER}')
            elif ctrl == 6: res.append('{RIVAL}')
            elif ctrl == 2: res.append('{STR_VAR_1}')
            elif ctrl == 3: res.append('{STR_VAR_2}')
            elif ctrl == 4: res.append('{STR_VAR_3}')
            continue
        elif b == 0xFC:
            ctrl = rom[off]; off += 1
            if ctrl in (1, 2, 3, 6, 8, 9): off += 1
            elif ctrl == 0x10: off += 2
            continue
        c = charmap.get(b, '')
        res.append(c)
    text = ''.join(res)
    text = text.replace('POKひMON', 'POKeMON').replace('POKéMON', 'POKeMON').replace('ひ', 'e')
    text = text.replace('"', "'")
    return text

VALID_CHARS = set("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .,!?:;-'/\\$()[]{}~\n\l\p")

def is_valid_english_text(text):
    if not text or len(text) < 3: return False
    # Check if there are letters
    letters = sum(1 for ch in text if ch.isalpha())
    if letters < 3: return False
    # Check every char is allowed
    for ch in text:
        if ch not in VALID_CHARS:
            return False
    return True

def scan_script_for_strings(script_ptr, max_len=180):
    off = script_ptr & 0x1FFFFFF
    if off <= 0 or off >= len(rom): return []
    found = []
    for pos in range(off, min(len(rom)-4, off + max_len)):
        val = struct.unpack('<I', rom[pos : pos+4])[0]
        if 0x08000000 <= val < 0x08E00000:
            txt = decode_rom_str(val)
            if is_valid_english_text(txt) and val not in found:
                found.append(val)
    return found

def format_gas_string(text):
    parts = re.split(r'(\\p)', text)
    paras = []
    curr = ''
    for part in parts:
        curr += part
        if part == r'\p':
            paras.append(curr)
            curr = ''
    if curr:
        paras.append(curr)
    
    lines = []
    for p in paras:
        subparts = re.split(r'(\\n|\\l)', p)
        subcurr = ''
        for sp in subparts:
            subcurr += sp
            if sp in (r'\n', r'\l'):
                lines.append(subcurr)
                subcurr = ''
        if subcurr:
            lines.append(subcurr)
            
    res_lines = []
    for i, line in enumerate(lines):
        term = '$' if i == len(lines) - 1 else ''
        res_lines.append(f'\t.string "{line}{term}"')
    return '\n'.join(res_lines)

# Index ROM maps
bank_tbl_ptr = 0x3526a8
rom_maps = []
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
        
        bgs = []
        boff = b_ptr & 0x1FFFFFF
        for bi in range(bg_c):
            bentry = rom[boff + bi*12 : boff + (bi+1)*12]
            bx, by = struct.unpack('<hh', bentry[0:4])
            bkind = bentry[5]
            bscript = struct.unpack('<I', bentry[8:12])[0]
            bgs.append({'x': bx, 'y': by, 'kind': bkind, 'script': bscript})
        
        objs = []
        ooff = o_ptr & 0x1FFFFFF
        for oi in range(obj_c):
            oentry = rom[ooff + oi*24 : ooff + (oi+1)*24]
            ox, oy, oelev = struct.unpack('<hhB', oentry[4:9])
            oscript = struct.unpack('<I', oentry[16:20])[0]
            objs.append({'x': ox, 'y': oy, 'script': oscript})
            
        rom_maps.append({
            'bank': b, 'map': m, 'w': w, 'h': h,
            'obj_c': obj_c, 'warp_c': warp_c, 'bg_c': bg_c,
            'bgs': bgs, 'objs': objs, 'mptr': mptr
        })

print(f'Indexed {len(rom_maps)} ROM maps.')

kanto_maps = glob.glob(r'src/pokeemerald-multiplatform/data/maps/Kanto_*/map.json')
print(f'Found {len(kanto_maps)} Kanto maps.')

total_signs_replaced = 0
total_npcs_replaced = 0

for km in kanto_maps:
    with open(km, 'r', encoding='utf-8') as f:
        kdata = json.load(f)
    
    mname = kdata['name']
    k_objs = kdata.get('object_events', [])
    k_bgs = kdata.get('bg_events', [])
    k_warps = kdata.get('warp_events', [])
    
    candidates = [rm for rm in rom_maps if rm['obj_c'] == len(k_objs) and rm['warp_c'] == len(k_warps) and rm['bg_c'] == len(k_bgs)]
    best_rm = None
    if len(candidates) == 1:
        best_rm = candidates[0]
    elif len(candidates) > 1:
        for rm in candidates:
            if k_bgs:
                all_match = all(any(rm_bg['x'] == k_bg['x'] and rm_bg['y'] == k_bg['y'] for rm_bg in rm['bgs']) for k_bg in k_bgs)
                if all_match:
                    best_rm = rm
                    break
            elif k_objs:
                all_match = all(any(rm_obj['x'] == k_obj['x'] and rm_obj['y'] == k_obj['y'] for rm_obj in rm['objs']) for k_obj in k_objs)
                if all_match:
                    best_rm = rm
                    break
        if not best_rm:
            best_rm = candidates[0]
            
    if not best_rm:
        continue
        
    sp = os.path.join(os.path.dirname(km), 'scripts.inc')
    if not os.path.exists(sp):
        continue
    with open(sp, 'r', encoding='utf-8', errors='ignore') as f:
        scontent = f.read()
        
    orig_scontent = scontent
    
    # 1. Update Signposts (bg_events)
    for k_bg in k_bgs:
        bscript = k_bg.get('script')
        if not bscript or bscript == '0x0': continue
        
        rm_bg = next((b for b in best_rm['bgs'] if b['x'] == k_bg['x'] and b['y'] == k_bg['y']), None)
        if not rm_bg or rm_bg['script'] == 0: continue
        
        strings = scan_script_for_strings(rm_bg['script'], 80)
        if strings:
            text = decode_rom_str(strings[0])
            if len(text) > 1 and 'Exploring KANTO' not in text:
                lbl = f'{bscript}_Text:'
                if lbl in scontent:
                    idx = scontent.find(lbl)
                    # Find following string block
                    str_start = scontent.find('.string', idx)
                    if str_start != -1:
                        # Find the end quote followed by newline or next instruction
                        end_quote = scontent.find('$"', str_start)
                        if end_quote != -1:
                            end_pos = end_quote + 2
                            # Check there isn't another line
                            formatted = format_gas_string(text)
                            scontent = scontent[:str_start] + formatted + scontent[end_pos:]
                            total_signs_replaced += 1
                            
    # 2. Update NPCs (object_events)
    for k_obj in k_objs:
        oscript = k_obj.get('script')
        if not oscript or oscript in ('0x0', 'NULL'): continue
        if any(g in oscript for g in ['LtSurge', 'Sabrina', 'Erika', 'Misty', 'Brock', 'Koga', 'Blaine', 'Giovanni', 'Blue', 'Red', 'OakTrigger']):
            continue
            
        rm_obj = next((o for o in best_rm['objs'] if o['x'] == k_obj['x'] and o['y'] == k_obj['y']), None)
        if not rm_obj or rm_obj['script'] == 0: continue
        
        strings = scan_script_for_strings(rm_obj['script'], 150)
        if strings:
            text = decode_rom_str(strings[0])
            if len(text) > 2:
                lbl = f'{oscript}_Text:'
                if lbl in scontent:
                    idx = scontent.find(lbl)
                    str_start = scontent.find('.string', idx)
                    if str_start != -1:
                        end_quote = scontent.find('$"', str_start)
                        if end_quote != -1:
                            end_pos = end_quote + 2
                            formatted = format_gas_string(text)
                            scontent = scontent[:str_start] + formatted + scontent[end_pos:]
                            total_npcs_replaced += 1
                        
    if scontent != orig_scontent:
        with open(sp, 'w', encoding='utf-8', newline='\n') as f:
            f.write(scontent)

print(f'Done! Successfully updated {total_signs_replaced} signposts and {total_npcs_replaced} NPCs with authentic FireRed dialogue!')

for sp in glob.glob(r'src/pokeemerald-multiplatform/data/maps/Kanto_*/scripts.inc'):
    with open(sp, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    orig = content
    content = content.replace('\\"', "'")
    content = content.replace('\u2019', "'").replace('\u2018', "'").replace('\u2026', '...').replace('\u201c', "'").replace('\u201d', "'").replace('\u2014', '-')
    if content != orig:
        with open(sp, 'w', encoding='utf-8', newline='\n') as f:
            f.write(content)

