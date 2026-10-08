"""Rewrite an addon's own class names as CBA macros: GVAR / QGVAR / ADDON.

user, 2026-09-22: "no do not make new ones use the ace ones", "why did you not do it for the whole mod".

A class the addon DECLARES is written through GVAR; a class it only inherits from stays literal, because that one
belongs to somebody else. The addon's identity is its faction class (the `jmfsb_X: NO_CATEGORY` in
CfgFactionClasses), and the suffix is the declared name with that root stripped, so
`jmfsb_EUDF_des_B_D_MRAP_01_F` in `addons/faction_eudf_des` becomes `GVAR(B_D_MRAP_01_F)`.

GVAR pastes PREFIX and COMPONENT, so the class is RENAMED to `jmfsb_faction_eudf_des_B_D_MRAP_01_F`. That is what
the ACE macros give; nothing else about the class changes.

    python tools/to_gvar.py <addon> [<addon> ...]
    python tools/to_gvar.py --all-factions
"""
import glob
import io
import os
import re
import sys

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
ADDONS = os.path.join(ROOT, "addons")
CRLF = chr(13) + chr(10)
LF = chr(10)
DECL = re.compile(r"^\s*class\s+(jmfsb_\w+)\s*(?::|\{)", re.M)
FACTION_DECL = re.compile(r"^\s*class\s+(jmfsb_\w+)\s*:\s*NO_CATEGORY", re.M)


def files_of(addon):
    base = os.path.join(ADDONS, addon)
    return [f for f in sorted(glob.glob(os.path.join(base, "*.hpp")) + glob.glob(os.path.join(base, "*.cpp")))
            if os.path.basename(f) != "script_component.hpp"]


def declared(addon):
    names = set()
    for f in files_of(addon):
        names.update(DECL.findall(io.open(f, encoding="utf-8", errors="replace").read()))
    return names


def faction_classes(addon):
    """The faction classes this addon declares: its identity, and the root of every class it owns."""
    p = os.path.join(ADDONS, addon, "CfgFactionClasses.hpp")
    if not os.path.exists(p):
        return []
    return FACTION_DECL.findall(io.open(p, encoding="utf-8", errors="replace").read())


def common_prefix(facs):
    """The root the addon's faction classes share: jmfsb_faction_jmsb_ from jmfsb_faction_jmsb_tna and jmfsb_faction_jmsb_ocp."""
    if not facs:
        return None
    if len(facs) == 1:
        return facs[0] + "_"
    parts = [f.split("_") for f in sorted(facs)]
    first, last = parts[0], parts[-1]
    i = 0
    while i < min(len(first), len(last)) and first[i] == last[i]:
        i += 1
    return "_".join(first[:i]) + "_" if i else None


def convert(addon):
    facs = faction_classes(addon)
    pre = common_prefix(facs)
    if not pre:
        return addon, 0, 0, None
    names = {n for n in declared(addon) if n.startswith(pre)}
    done = left = 0
    for f in files_of(addon):
        raw = io.open(f, encoding="utf-8", newline="").read()
        nl = CRLF if CRLF in raw else LF
        s = raw.replace(CRLF, LF)
        for n in sorted(names, key=len, reverse=True):
            suffix = n[len(pre):]
            if not suffix:
                continue
            s = re.sub(r"(?<![\w(])%s(?![\w])" % re.escape(n), "GVAR(%s)" % suffix, s)
            s = s.replace('"GVAR(%s)"' % suffix, "QGVAR(%s)" % suffix)
        for fac in sorted(facs, key=len, reverse=True):
            tail = fac[len(pre):]
            mac = "ADDON" if not tail else "GVAR(%s)" % tail
            qmac = "QUOTE(ADDON)" if not tail else "QGVAR(%s)" % tail
            s = re.sub(r"(" + LF + r"\s*class )%s(\s*(?::|\{))" % re.escape(fac),
                       lambda m, mm=mac: "%s%s%s" % (m.group(1), mm, m.group(2)), s)
            s = s.replace('"%s"' % fac, qmac)
        if s != raw.replace(CRLF, LF):
            io.open(f, "w", encoding="utf-8", newline="").write(s.replace(LF, nl))
        done += s.count("GVAR(")
        left += len(re.findall(r"(?<![\w(])%s\w*" % re.escape(pre), s))
    return addon, done, left, pre


def main():
    args = sys.argv[1:]
    if not args:
        raise SystemExit(__doc__)
    if args[0] == "--all-factions":
        args = [os.path.basename(d) for d in sorted(glob.glob(os.path.join(ADDONS, "faction_*"))) if os.path.isdir(d)]
    for addon in args:
        a, done, left, pre = convert(addon)
        print("%-24s prefix %-22s macros %5d  literals left %d" % (a, pre or "-", done, left))


if __name__ == "__main__":
    main()
