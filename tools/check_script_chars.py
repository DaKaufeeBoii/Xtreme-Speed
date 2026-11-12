import glob, re

invalid_chars = set()
bad_files = []

# Allowed ASCII characters in pokeemerald .string
ALLOWED = set("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .,!?:;-'/\\$()[]{}")

for sp in glob.glob(r'src/pokeemerald-multiplatform/data/maps/Kanto_*/scripts.inc'):
    for i, line in enumerate(open(sp, encoding='utf-8', errors='ignore')):
        if '.string' in line:
            m = re.search(r'"(.*)"', line)
            if m:
                s = m.group(1)
                for ch in s:
                    if ch not in ALLOWED:
                        invalid_chars.add(ch)
                        bad_files.append((sp, i+1, ch, line.strip()))

print('Invalid chars found:', invalid_chars)
print(f'Total bad lines: {len(bad_files)}')
for b in bad_files[:25]:
    print(b)
