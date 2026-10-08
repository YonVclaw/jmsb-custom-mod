"""Textures in the mod that nothing references, and references with no texture.

The camo pipeline writes into `addons/<faction>/data`; a scheme that changes, a faction that is renamed or a
vehicle that is dropped leaves the old sheets behind. This lists both directions:

  orphans  - a .paa under addons/ that no config names
  missing  - a config path that has no file (that one is also caught by hemtt, this is the wider sweep)

    python tools/camo/orphan_textures.py            # report
    python tools/camo/orphan_textures.py --delete    # report, then delete the orphans
"""
import glob
import io
import os
import re
import sys

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
ADDONS = os.path.join(ROOT, "addons")
BS = chr(92)
LIT = re.compile(r'"' + re.escape(BS + "z" + BS + "jmfsb" + BS + "addons" + BS) + r'([^"]+?\.\w+)"', re.I)
MAC = re.compile(r"\bQ?PATHTOE?F\(\s*([^)]*?)\s*\)")
ART = (".paa", ".p3d", ".ogg", ".wss", ".jpg", ".rtm")


def referenced():
    """Every file under addons/ that a config or script names, as a lower-case relative path."""
    out = set()
    for f in glob.glob(os.path.join(ADDONS, "*", "**", "*.*"), recursive=True):
        if not f.lower().endswith((".hpp", ".cpp", ".sqf", ".inc")):
            continue
        addon = os.path.relpath(f, ADDONS).split(os.sep)[0]
        t = io.open(f, encoding="utf-8", errors="replace").read()
        for rel in LIT.findall(t):
            out.add(rel.replace("/", BS).lower())
        for arg in MAC.findall(t):
            parts = [x.strip() for x in arg.split(",")]
            if len(parts) == 2:
                out.add((parts[0] + BS + parts[1]).replace("/", BS).lower())
            elif parts and parts[0]:
                out.add((addon + BS + parts[0]).replace("/", BS).lower())
    return out


def main():
    refs = referenced()
    on_disk, orphans = 0, []
    for f in glob.glob(os.path.join(ADDONS, "*", "**", "*.*"), recursive=True):
        if not f.lower().endswith(ART):
            continue
        on_disk += 1
        rel = os.path.relpath(f, ADDONS).replace("/", BS)
        if rel.lower() not in refs:
            orphans.append((os.path.getsize(f), rel))
    missing = sorted(r for r in refs if r.endswith(ART) and not os.path.exists(os.path.join(ADDONS, r.replace(BS, os.sep))))
    print("art files under addons/: %d   referenced: %d" % (on_disk, len(refs)))
    print()
    print("ORPHANS - on disk, nothing names them: %d (%.1f MB)"
          % (len(orphans), sum(s for s, _ in orphans) / 1048576.0))
    by_addon = {}
    for size, rel in orphans:
        a = rel.split(BS)[0]
        by_addon.setdefault(a, [0, 0])
        by_addon[a][0] += 1
        by_addon[a][1] += size
    for a in sorted(by_addon, key=lambda k: -by_addon[k][1]):
        n, sz = by_addon[a]
        print("   %-26s %4d files  %6.1f MB" % (a, n, sz / 1048576.0))
    for size, rel in sorted(orphans, reverse=True)[:12]:
        print("      %6.2f MB  %s" % (size / 1048576.0, rel))
    print()
    print("MISSING - named by a config, not on disk: %d" % len(missing))
    for r in missing[:12]:
        print("   %s" % r)
    if "--delete" in sys.argv and orphans:
        for _s, rel in orphans:
            os.remove(os.path.join(ADDONS, rel.replace(BS, os.sep)))
        print()
        print("deleted %d orphan files" % len(orphans))


if __name__ == "__main__":
    main()
