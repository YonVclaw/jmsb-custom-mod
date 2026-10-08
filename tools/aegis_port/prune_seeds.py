"""Cut seeds.txt down to the imported classes jmfsb's own addons still name (EGVAR(addon,name) outside the
five import addons), after factions were rebuilt on other mods (2026-10-04: Turkey on TMT, Russia on
2035 Russia, China on the PLA pack). Re-run port.py --seeds, seed_map.py and repoint_factions.py after.

    python tools/aegis_port/prune_seeds.py [--dry]
"""
import json
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
JMFSB = os.path.normpath(os.path.join(HERE, "..", ".."))
TARGETS = {"weapons", "vests", "headware", "uniform", "vehicle"}

m = json.load(open(os.path.join(JMFSB, "work", "aegis_seed_map.json"), encoding="utf-8"))
by_jmfsb = {}
for src, v in m.items():
    by_jmfsb.setdefault((v["addon"], v["name"].lower()), set()).add(src)
used = set()
# the five addons' own files build on imported classes too (headware's FAST-MT paints)
for a in TARGETS:
    for dp, dn, fs in os.walk(os.path.join(JMFSB, "addons", a)):
        dn[:] = [d for d in dn if d != "models"]
        for f in fs:
            if f.endswith((".hpp", ".cpp")) and not f.startswith("imported_"):
                t = open(os.path.join(dp, f), encoding="utf-8", errors="replace").read()
                for nm in re.findall(r"\bQ?GVAR\((\w+)\)", t):
                    used |= by_jmfsb.get((a, nm.lower()), set())
for a in os.listdir(os.path.join(JMFSB, "addons")):
    if a in TARGETS:
        continue
    for dp, dn, fs in os.walk(os.path.join(JMFSB, "addons", a)):
        dn[:] = [d for d in dn if d not in ("models", "data")]
        for f in fs:
            if f.endswith((".hpp", ".cpp", ".sqf")):
                t = open(os.path.join(dp, f), encoding="utf-8", errors="replace").read()
                for ad, nm in re.findall(r"\bQ?EGVAR\((\w+),(\w+)\)", t):
                    used |= by_jmfsb.get((ad, nm.lower()), set())
                for ad, nm in re.findall(r"\bjmfsb_(weapons|vests|headware|uniform|vehicle)_(\w+)", t):
                    used |= by_jmfsb.get((ad, nm.lower()), set())
path = os.path.join(HERE, "seeds.txt")
lines = open(path, encoding="utf-8").read().splitlines()
head = [l for l in lines if l.startswith("#")]
seeds = [l for l in lines if l and not l.startswith("#")]
keep = [s for s in seeds if s in used]
print("seeds %d -> %d" % (len(seeds), len(keep)))
if "--dry" not in sys.argv:
    open(path, "w", encoding="utf-8").write("\n".join(head + ["# pruned 2026-10-04 to what jmfsb still names (prune_seeds.py)"] + keep) + "\n")
