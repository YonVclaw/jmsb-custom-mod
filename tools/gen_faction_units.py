#!/usr/bin/env python3
"""Sync every faction addon's CfgPatches units[] with the classes it defines.

    python tools/gen_faction_units.py

WHY THIS IS ITS OWN STEP. Three generators write classes into one addon -
drones.hpp, vehicles.hpp, maaws.hpp - and none of them can know what the others
produced. Each one rewriting units[] would mean the last to run wins and the
other two vanish from it. So units[] is derived once, at the end, from what is
actually on disk.

A CLASS THAT IS NOT IN units[] IS NOT USABLE IN ZEUS. The engine reads the
addon's class list from CfgPatches; a scope-2 class missing from it exists in
config, shows up in the editor, and cannot be curated. HEMTT calls that out as
L-C15-NOT-IN-PATCHES, and with four hundred generated classes it called it out
four hundred times.

SCOPE 0 CLASSES ARE DELIBERATELY LEFT OUT. remove.hpp hides other people's
vehicles by setting scope = 0; they are not ours to declare, and listing them
would claim this addon ships the Ram 1500 it just took away.
"""
import io
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ADDONS = os.path.join(ROOT, "addons")

# EVERY .hpp IN THE ADDON, not a list of filenames. A fixed list is a list
# somebody forgets to add to: it silently emptied MFRC's units[] when its
# classes turned out to live in CfgVehicles.hpp, and silently dropped HIMF's
# two aircraft when they turned out to live in aircraft.hpp. The regex below
# only matches OUR classes, so scanning everything costs nothing and cannot
# miss a file that has not been invented yet.
def pieces(addon_dir):
    return sorted(f for f in os.listdir(addon_dir) if f.lower().endswith(".hpp"))


# units[] declares CfgVehicles classes and nothing else. A faction entry and a
# group entry are `class jmfsb_x: base {` too, so a file that declares one of
# those config roots is skipped outright rather than filtered class by class -
# MFRC's four factions turned up in its units[] the first time this scanned
# every file.
OTHER_ROOTS = ("CfgFactionClasses", "CfgGroups", "CfgWeapons", "CfgMagazines")

# `class jmfsb_x: base {` - ours, and public enough to need declaring. The
# scope check happens on the body that follows.
CLASS = re.compile(r"^\s*class\s+(jmfsb_\w+)\s*:\s*\w+\s*\{(.*?)^\s*\};",
                   re.M | re.S)


def crlf_write(path, text):
    io.open(path, "w", encoding="utf-8", newline="").write(text)


def public_classes(addon_dir):
    found = []
    for piece in pieces(addon_dir):
        p = os.path.join(addon_dir, piece)
        if not os.path.isfile(p):
            continue
        s = io.open(p, encoding="utf-8", newline="").read()
        if any(root in s for root in OTHER_ROOTS):
            continue
        for name, body in CLASS.findall(s):
            # scope = 0 is a class we are hiding, not one we ship.
            if re.search(r"scope\s*=\s*0\s*;", body):
                continue
            found.append(name)
    # order is stable so a re-run produces no diff
    return sorted(set(found), key=str.lower)


def main():
    total = 0
    for comp in sorted(os.listdir(ADDONS)):
        d = os.path.join(ADDONS, comp)
        cfg = os.path.join(d, "config.cpp")
        if not comp.startswith("faction_") or not os.path.isfile(cfg):
            continue

        names = public_classes(d)
        s = io.open(cfg, encoding="utf-8", newline="").read()

        if not names:
            new = "        units[] = {};"
        else:
            rows = ",\r\n".join('            "%s"' % n for n in names)
            new = "        units[] = {\r\n%s\r\n        };" % rows

        # match whatever units[] looks like now - one line or a block
        pat = re.compile(r"^        units\[\] = \{.*?\};", re.M | re.S)
        if not pat.search(s):
            print("  %-24s no units[] line - skipped" % comp)
            continue
        s = pat.sub(lambda _: new, s, count=1)
        crlf_write(cfg, s)

        print("  %-24s %d class(es)" % (comp, len(names)))
        total += len(names)

    print("")
    print("%d class(es) declared across the faction addons" % total)
    return 0


if __name__ == "__main__":
    sys.exit(main())
