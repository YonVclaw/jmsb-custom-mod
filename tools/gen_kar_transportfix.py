"""KAR_FDF35_V declares its TransportMagazines cargo with `name =`, but that is the
TransportItems key -- the engine reads `.magazine`, finds nothing, and logs
`creating magazine  with scope=private` for every entry on every affected vehicle.

IMPORTANT: reopening a config class MERGES rather than replaces, so the override
has to reuse each ORIGINAL subclass name. An earlier version of this generator
named the subclass after the magazine (_xx_KAR_FDF35_RK_MAG) while KAR had named
it after the rifle (_xx_KAR_FDF35_RIFLE_RK62M2); the broken original therefore
survived alongside the fix, still erroring and double-loading the cargo.

Item entries (FirstAidKit / Medikit / ToolKit) are mis-filed in TransportMagazines
and are already declared correctly in the same vehicle's TransportItems. They
cannot simply be dropped -- the broken subclass would remain -- so they are
overridden in place with a valid magazine at count 0, which contributes nothing.

Emits addons/kar_fdf35/CfgVehicles.hpp.
"""
import io
import re

SRC = r"C:\Users\jwise\play\fin\KAR_FDF35_V\config.cpp"
OUT = r"o:\GIT\jmfsb\addons\kar_fdf35\CfgVehicles.hpp"
ITEMS = ("FirstAidKit", "Medikit", "ToolKit")   # not magazines; live in TransportItems
FILLER = "SmokeShell"                           # valid magazine, used at count 0

s = io.open(SRC, encoding="utf-8", errors="replace").read()

found = []
for m in re.finditer(r"\n\tclass (\w+)\s*:\s*(\w+)\s*\n\t\{", s):
    start = m.end()
    nxt = s.find("\n\tclass ", start)
    body = s[start: nxt if nxt > 0 else len(s)]
    tm = re.search(r"class TransportMagazines\s*\{(.*?)\n\t\t\};", body, re.S)
    if not tm or not re.search(r"name\s*=", tm.group(1)):
        continue
    # keep the subclass name -- that is what has to be overridden
    entries = re.findall(
        r'class (_xx_\w+)\s*\{\s*name\s*=\s*"([^"]+)"\s*;\s*count\s*=\s*(\d+)\s*;',
        tm.group(1).replace("\n", " ").replace("\t", " "))
    if entries:
        found.append((m.group(1), m.group(2), entries))

out = [
    "// KAR_FDF35_V declares its TransportMagazines entries with `name =`, which is",
    "// the TransportItems key -- the engine reads `.magazine`, gets nothing, and",
    "// logs `creating magazine  with scope=private` for each one.",
    "//",
    "// Each override below reuses the ORIGINAL subclass name: reopening a class",
    "// merges, so renaming the subclass would leave KAR's broken one in place.",
    "class CfgVehicles {",
]
seen = set()
for i, (name, parent, entries) in enumerate(found):
    if parent not in seen:
        out.append("    class %s;" % parent)
        seen.add(parent)
    out.append("    class %s: %s {" % (name, parent))
    out.append("        class TransportMagazines {")
    for sub, mag, cnt in entries:
        out.append("            class %s {" % sub)
        if mag in ITEMS:
            out.append("                // mis-filed item; the real one is in TransportItems")
            out.append('                magazine = "%s";' % FILLER)
            out.append("                count = 0;")
        else:
            out.append('                magazine = "%s";' % mag)
            out.append("                count = %s;" % cnt)
        out.append("            };")
    out.append("        };")
    out.append("    };")
    if i < len(found) - 1:
        out.append("")
out.append("};")

io.open(OUT, "w", encoding="utf-8", newline="\n").write("\n".join(out) + "\n")
print("%d classes patched, %d cargo entries overridden"
      % (len(found), sum(len(e) for _, _, e in found)))
