#!/usr/bin/env python3
"""Port the futureAmmo mod into jmfsb as fa_* addons.

    python tools/port_futureammo.py [--src D:/Git/futureAmmo] [--force] [--only rearma_us ...]

futureAmmo ships as its own mod under the `jmfsbfa` prefix. This copies it in
under jmfsb's prefix so the ammunition travels with the mod that depends on it,
rather than being a second thing a server has to remember to load.

WHAT CHANGES, AND ONLY THIS:

  z\\jmfsbfa\\addons\\X          ->  z\\jmfsb\\addons\\fa_X
  #define COMPONENT X           ->  #define COMPONENT fa_X
  the jmfsbfa main headers      ->  jmfsb's own main headers
  "jmfsbfa_Y" in requiredAddons ->  "jmfsb_fa_Y"
  EGVAR/EFUNC(Y, ...)           ->  EGVAR/EFUNC(fa_Y, ...)   Y another futureAmmo addon
  jmfsbfa_Y[] (a hand-spelled   ->  jmfsb_fa_Y[]
    magazine-well array key)

CLASSNAMES ARE NOT TOUCHED. FA_MRAWS_HE448_AB is FA_MRAWS_HE448_AB in both
mods, and jmfsb's own configs already reference those names - the MAAWS gunner
carries two of them. Renaming them would be a rename of the thing this port
exists to keep.

fa_main IS NOT THE MACRO SOURCE ANY MORE. Every ported addon includes jmfsb's
script_mod/script_macros instead, so there is one PREFIX, one version number
and one author string in the built mod. fa_main survives as an ordinary addon
carrying futureAmmo's own functions, data and stringtable.

SETTING_OVERRIDE_HOOK is the one macro futureAmmo defines that jmfsb does not;
it is re-declared in the ported fa_main and the three users are pointed at it.
"""
import argparse
import io
import os
import re
import shutil
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ADDONS = os.path.join(ROOT, "addons")
B = chr(92)

TEXT_EXT = {".cpp", ".hpp", ".sqf", ".inc", ".xml", ".txt", ".ext", ""}

# EGVAR / QEGVAR / EFUNC / QEFUNC / QQEGVAR ... naming a module, unless it is already fa_.
CROSS = re.compile(r"\b(Q{0,2}E(?:GVAR|FUNC))\((?!fa_)(\w+),")
# futureAmmo's addon names, filled from the source tree in main().
FA_COMPONENTS = {"main"}


def is_text(path):
    return os.path.splitext(path)[1].lower() in TEXT_EXT


def port_text(s, name):
    # paths
    s = s.replace("z" + B + "jmfsbfa" + B + "addons" + B + "main",
                  "z" + B + "jmfsb" + B + "addons" + B + "fa_main")
    s = s.replace("z" + B + "jmfsbfa" + B + "addons" + B,
                  "z" + B + "jmfsb" + B + "addons" + B + "fa_")
    # CfgPatches dependency names
    s = re.sub(r'"jmfsbfa_([a-z0-9_]+)"', r'"jmfsb_fa_\1"', s)
    # This addon's component name. \s* before the line end, because these files
    # are CRLF and `$` in a multiline match sits before the \n with the \r still
    # in the way - which silently matched nothing on the first run.
    s = re.sub(r"^#define COMPONENT (\w+)\s*$", r"#define COMPONENT fa_\1", s, flags=re.M)

    # fa_main stops being a prefix of its own: ONE PREFIX in the built mod, so
    # CfgPatches comes out jmfsb_fa_x rather than jmfsbfa_fa_x.
    s = s.replace("#define PREFIX jmfsbfa", "#define PREFIX jmfsb")
    s = s.replace('#define QPREFIX "jmfsbfa"', '#define QPREFIX "jmfsb"')

    # ...and one version number, jmfsb's, so a ported PBO reports the build it
    # actually shipped in rather than futureAmmo's own.
    s = s.replace('#include "script_version.hpp"',
                  '#include "' + B + "z" + B + "jmfsb" + B + "addons" + B + "main" + B +
                  'script_version.hpp"')
    # Another futureAmmo addon, where this one reaches for it - main included.
    # EGVAR(antidrone,AD_params) is TRIPLES(PREFIX,antidrone,AD_params), which is
    # jmfsb_antidrone_AD_params; the ported addon's COMPONENT is fa_antidrone, so it
    # publishes jmfsb_fa_antidrone_AD_params. Left alone, every `isNil
    # QEGVAR(antidrone,...)` guard quietly exits and the round never registers; hemtt
    # only notices the EFUNC half (L-S29). Only futureAmmo's own addon names are
    # touched: EFUNC(notify,...) is jmfsb's.
    s = CROSS.sub(lambda m: "%s(fa_%s," % (m.group(1), m.group(2))
                  if m.group(2).lower() in FA_COMPONENTS else m.group(0), s)
    # A magazine-well array spelled out by hand rather than through ADDON - the rearma
    # addons share `jmfsbfa_rearma_ugl[]` on purpose, one key for the same list - is
    # outside every macro and every quote above. Comments that merely mention an addon
    # have no `[]` and stay as written, like the rest of the port's comments.
    s = re.sub(r"\bjmfsbfa_(\w+)\[\]", r"jmfsb_fa_\1[]", s)
    return s


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--src", default=r"D:\Git\futureAmmo")
    ap.add_argument("--force", action="store_true")
    ap.add_argument("--only", nargs="+", metavar="ADDON",
                    help="port just these futureAmmo addons (their futureAmmo names, e.g. rearma_us)")
    args = ap.parse_args()

    src_addons = os.path.join(args.src, "addons")
    if not os.path.isdir(src_addons):
        print("no %s" % src_addons)
        return 1

    FA_COMPONENTS.update(n.lower() for n in os.listdir(src_addons)
                         if os.path.isdir(os.path.join(src_addons, n)))
    made = skipped = 0
    only = {n.lower() for n in args.only} if args.only else None
    if only:
        absent = sorted(n for n in only if not os.path.isdir(os.path.join(src_addons, n)))
        if absent:
            print("not in %s: %s" % (src_addons, ", ".join(absent)))
            return 1
    for name in sorted(os.listdir(src_addons)):
        s_dir = os.path.join(src_addons, name)
        if not os.path.isdir(s_dir) or (only and name.lower() not in only):
            continue
        d_dir = os.path.join(ADDONS, "fa_" + name)

        if os.path.isdir(d_dir):
            if not args.force:
                skipped += 1
                continue
            shutil.rmtree(d_dir)

        shutil.copytree(s_dir, d_dir)

        for base, _, files in os.walk(d_dir):
            for f in files:
                p = os.path.join(base, f)
                if f == "$PBOPREFIX$":
                    io.open(p, "w", encoding="utf-8", newline="").write(
                        "z" + B + "jmfsb" + B + "addons" + B + "fa_" + name + "\r\n")
                    continue
                if not is_text(p):
                    continue
                try:
                    txt = io.open(p, encoding="utf-8", newline="").read()
                except (OSError, UnicodeDecodeError):
                    continue
                io.open(p, "w", encoding="utf-8", newline="").write(port_text(txt, name))

        made += 1
        print("  fa_%-22s ported" % name)

    print("")
    print("%d addon(s) ported, %d already present" % (made, skipped))
    if skipped:
        print("re-run with --force to overwrite the ones already there")
    return 0


if __name__ == "__main__":
    sys.exit(main())
