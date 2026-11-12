import urllib.request, re, os, json

headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64)'}
os.makedirs(r'd:\Kaufee\projects\personal\pc-port\covers', exist_ok=True)

targets = [
    ('firered', 'https://en.wikipedia.org/wiki/Pok%C3%A9mon_FireRed_and_LeafGreen'),
    ('ruby_sapphire', 'https://en.wikipedia.org/wiki/Pok%C3%A9mon_Ruby_and_Sapphire'),
    ('emerald', 'https://en.wikipedia.org/wiki/Pok%C3%A9mon_Emerald')
]

for tag, url in targets:
    try:
        req = urllib.request.Request(url, headers=headers)
        html = urllib.request.urlopen(req).read().decode('utf-8', errors='ignore')
        matches = re.findall(r'src="(//upload\.wikimedia\.org/wikipedia/[^"]+\.(?:png|jpg|jpeg))"', html)
        print(f"[{tag}] found images:")
        for m in matches[:5]:
            print("  https:" + m)
    except Exception as e:
        print(f"Error {tag}: {e}")
