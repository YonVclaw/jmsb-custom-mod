#!/usr/bin/env python3
"""Write the EXTRA_UNITS a generated faction is missing into it, in place.

    python tools/apply_faction_extras.py [--dry-run]

THE OTHER HALF OF tools/strip_faction_mods.py. That one takes classes OUT of
the generated factions while the ORBAT dump is gone; this one puts the
generator's EXTRA_UNITS IN - the east Falcon, the SwitchBlade tubes, the
demining Pelican - written by gen_us_factions.emit_extras, the same code a
regeneration would run, so the files stay what the generator would have
produced.

WHAT IT DOES, per faction in gen_us_factions.TARGETS whose files carry the
generator's header:

  CfgVehicles.hpp     an extra whose class is not yet defined is emitted at
                      the end of the roster, under the "fielded by this
                      faction" banner (added if absent). Extras already
                      present are left exactly as they are.
  config.cpp          units[] gains the new classes.
  README.md           the unit count in the seeded prose is corrected.

An extra whose base the faction already fields, or whose base is a dropped
mod's, is skipped and said - emit_extras does that.
"""
import argparse
import io
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import gen_us_factions as G
import strip_faction_mods as S


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--dry-run", action="store_true")
    args = ap.parse_args()

    vanilla = G.load_vanilla()
    if vanilla is None:
        print("work/vanilla_vehicles.json is missing - run tools/gen_vanilla_vehicles.py first.")
        return 2

    for addon, _beaut, newfac, _disp, _src in G.TARGETS:
        d = os.path.join(G.ADDONS, addon)
        vp = os.path.join(d, "CfgVehicles.hpp")
        if not os.path.exists(vp) or S.GEN_HDR not in S.read(vp):
            continue
        text = S.read(vp)
        lines = S.split_lines(text)

        # what the faction fields now: our class -> its source
        have = {}
        for m in re.finditer(r"^    class (jmfsb_[A-Za-z0-9_]+): ([A-Za-z0-9_]+) \{", text, re.M):
            have[m.group(1)] = m.group(2)
        new = dict((src, ours) for ours, src in have.items() if not src.startswith("jmfsb_"))
        # men: the source classes that are men, by the generator's own test -
        # a class with a uniform. The generated file does not say, so the
        # vanilla index's backpack/uniform is not available either; the best
        # proxy on disk is "not a vehicle": no crew line written.
        men = []
        for m in re.finditer(r"^    class (jmfsb_[A-Za-z0-9_]+): ([A-Za-z0-9_]+) \{(.*?)^    \};", text, re.M | re.S):
            if "crew = " not in m.group(3) and not m.group(2).startswith("jmfsb_"):
                men.append(m.group(2))

        side_m = re.search(r"^\s*side = (\d);", text, re.M)
        side = int(side_m.group(1)) if side_m else 1

        # emit everything, then keep only what is not already defined
        ex_lines, ex_names = G.emit_extras(newfac, addon, side, new, men, vanilla)
        missing = [n for n in ex_names if n not in have]
        if not missing:
            print("%-20s nothing to add" % addon)
            continue

        # cut the emitted text down to the blocks for the missing classes:
        # a block is `class Fwd;` (optional) + `class X: Y {` .. `    };...`
        keep, i, hdr = [], 0, []
        while i < len(ex_lines) and not ex_lines[i].startswith("    class "):
            hdr.append(ex_lines[i]); i += 1
        while i < len(ex_lines):
            ln = ex_lines[i]
            fwd = None
            if re.match(r"^    class [A-Za-z0-9_]+;$", ln):
                fwd = ln; i += 1; ln = ex_lines[i]
            m = re.match(r"^    class (jmfsb_[A-Za-z0-9_]+): ", ln)
            if not m:
                i += 1; continue
            j = i
            while not ex_lines[j].startswith("    };"):
                j += 1
            block = ([fwd] if fwd else []) + ex_lines[i:j + 1]
            if m.group(1) in missing:
                keep += block
            i = j + 1

        banner_present = any("fielded by this faction, not by its source" in ln for ln in lines)
        out = []
        for ln in lines:
            if ln.strip() == "};" and ln == lines[max(k for k, l in enumerate(lines) if l.strip() == "};")]:
                if not banner_present:
                    out += hdr
                out += keep
                out.append("")
            out.append(ln)
        vtext = "\n".join(S.collapse_blanks(out))

        cp = os.path.join(d, "config.cpp")
        ctext = S.split_lines(S.read(cp))
        for k, ln in enumerate(ctext):
            if ln.strip() == "};" and k > 0 and '"' in ctext[k - 1] and "units[]" in "\n".join(ctext[max(0, k - 400):k]):
                if not ctext[k - 1].rstrip().endswith(","):
                    ctext[k - 1] = ctext[k - 1].rstrip() + ","
                ins = ['            "%s"%s' % (n, "," if q < len(missing) - 1 else "") for q, n in enumerate(missing)]
                ctext[k:k] = ins
                break
        ctext = "\n".join(ctext)

        rp = os.path.join(d, "README.md")
        rtext = S.fix_readme(S.read(rp), len(have) + len(missing)) if os.path.exists(rp) else None

        S.write(vp, vtext, args.dry_run)
        S.write(cp, ctext, args.dry_run)
        if rtext is not None:
            S.write(rp, rtext, args.dry_run)
        print("%-20s +%d: %s%s" % (addon, len(missing), ", ".join(missing), "  [dry run]" if args.dry_run else ""))
    return 0


if __name__ == "__main__":
    sys.exit(main())
