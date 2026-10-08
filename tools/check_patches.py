#!/usr/bin/env python3
"""CfgPatches units[] and weapons[] must match what the addon actually defines.

    python tools/check_patches.py

TWO FAILURES, which HEMTT names separately:

  L-C15-NOT-IN-PATCHES  a public class the addon defines that units[] does not
                        list. It exists, but Zeus cannot place it and nothing
                        enumerating the addon's content will find it.
  L-C15-MISSING-CLASS   a name in units[] that is defined nowhere. It points at
                        nothing, silently.

Both come from the same drift between the list and the classes. It has happened
in this repo three times: 414 classes missing at once, a MAAWS gunner listed and
never defined, and six HIMF men whose classes were written `GVAR(x)` - which
expands to `jmfsb_faction_atlas_blu_h_f_x` - while units[] said
`jmfsb_atlas_blu_h_f_x`. That last one is why this resolves macros rather than
comparing raw text.

MACROS ARE EXPANDED the way the preprocessor builds them: GVAR(x) becomes
PREFIX_COMPONENT_x, with PREFIX from addons/main/script_mod.hpp and COMPONENT
from each addon's script_component.hpp.

ENTRIES ARE RARELY QUOTED IN THE SOURCE. The house style is
`units[] = { QGVAR(vs17_item) };` - QGVAR produces the quoted string at
preprocess time, so the file contains a bare macro call. A reader that collects
only "..." literals sees an empty list and reports every class in the addon as
unlisted; the first version of this check did exactly that, 483 times, all
false.

ONLY PUBLIC CLASSES ARE REQUIRED IN units[]. scope 0 and 1 are base classes and
squad-internal units - HEMTT does not ask for those and neither does this.
"""
import io
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ADDONS = os.path.join(ROOT, "addons")

INCLUDE = re.compile(r'^[ \t]*#include\s+"([^"]+)"', re.M)
NAME = r"\w+(?:\s*\([^)]*\))?"
DEFN = re.compile(r"^[ \t]*class\s+(" + NAME + r")\s*(?::\s*(" + NAME + r")\s*)?\{")
ROOTS = ("CfgVehicles", "CfgWeapons")


def read(p):
    return io.open(p, encoding="utf-8", errors="replace").read()


def strip_comments(t):
    t = re.sub(r"/\*.*?\*/", "", t, flags=re.S)
    t = re.sub(r"//[^\n]*", "", t)
    return re.sub(r"^[ \t]*#define\b(?:[^\n]*\\\r?\n)*[^\n]*", "", t, flags=re.M)


def prefix():
    p = os.path.join(ADDONS, "main", "script_mod.hpp")
    if os.path.isfile(p):
        m = re.search(r"^\s*#define\s+PREFIX\s+(\w+)", read(p), re.M)
        if m:
            return m.group(1)
    return "jmfsb"


def component(addon_dir):
    p = os.path.join(addon_dir, "script_component.hpp")
    if os.path.isfile(p):
        m = re.search(r"^\s*#define\s+COMPONENT\s+(\w+)", read(p), re.M)
        if m:
            return m.group(1)
    return os.path.basename(addon_dir)


def expand(name, pre, comp):
    """GVAR(x) and friends, as the preprocessor would build them."""
    name = re.sub(r"\s+", "", name)
    m = re.match(r"^Q*GVAR\(\s*(\w+)\s*\)$", name)
    if m:
        return "%s_%s_%s" % (pre, comp, m.group(1))
    m = re.match(r"^Q*EGVAR\(\s*(\w+)\s*,\s*(\w+)\s*\)$", name)
    if m:
        return "%s_%s_%s" % (pre, m.group(1), m.group(2))
    m = re.match(r"^DOUBLES\(\s*(\w+)\s*,\s*(\w+)\s*\)$", name)
    if m:
        return "%s_%s" % (m.group(1), m.group(2))
    m = re.match(r"^TRIPLES\(\s*(\w+)\s*,\s*(\w+)\s*,\s*(\w+)\s*\)$", name)
    if m:
        return "%s_%s_%s" % (m.group(1), m.group(2), m.group(3))
    return name


def flatten(path, seen, out):
    real = os.path.normcase(os.path.abspath(path))
    if real in seen or not os.path.isfile(path):
        return
    seen.add(real)
    base = os.path.dirname(path)
    for line in strip_comments(read(path)).split("\n"):
        m = INCLUDE.match(line)
        if m:
            t = m.group(1)
            if not t.startswith("\\"):
                flatten(os.path.join(base, t.replace("\\", "/")), seen, out)
            continue
        out.append(line)


def braced(text, start):
    """Contents of the { } opening at `start`, by brace counting."""
    i, d = start, 1
    while i < len(text) and d:
        if text[i] == "{":
            d += 1
        elif text[i] == "}":
            d -= 1
        i += 1
    return text[start:i - 1]


def scan(addon_dir):
    cfg = os.path.join(addon_dir, "config.cpp")
    if not os.path.isfile(cfg):
        return None
    lines = []
    flatten(cfg, set(), lines)
    pre, comp = prefix(), component(addon_dir)

    public = dict((r, set()) for r in ROOTS)
    listed = dict((r, set()) for r in ROOTS)
    body = {}

    # ---- what CfgPatches claims ------------------------------------------
    #
    # ONLY INSIDE class CfgPatches. `weapons[] = {...}` is not a CfgPatches
    # idiom - units carry one, and so do gear pools:
    # addons/insurgents/CfgInsurgentGear.hpp holds a list of 100+ rifle names
    # that belongs to a loadout table. Matching the property name anywhere in
    # the addon read all of those as CfgPatches entries and reported every one
    # as an undefined class.
    whole = "\n".join(lines)
    patches = ""
    for m in re.finditer(r"^[ \t]*class\s+CfgPatches\s*\{", whole, re.M):
        patches += braced(whole, m.end()) + "\n"

    for key, prop in (("CfgVehicles", "units"), ("CfgWeapons", "weapons")):
        for m in re.finditer(r"\b" + prop + r"\[\]\s*\+?=\s*\{", patches):
            for tok in braced(patches, m.end()).split(","):
                tok = tok.strip().strip('"').strip()
                if tok:
                    listed[key].add(expand(tok, pre, comp).lower())

    # ---- what the addon defines -------------------------------------------
    # A root+depth stack, so only top-level classes count: a Turrets block
    # inside a vehicle is not a placeable unit.
    stack, depth_of = [], []
    for line in lines:
        m = DEFN.match(line)
        if m:
            nm = expand(m.group(1), pre, comp)
            scope = tuple(stack)
            if len(scope) == 1 and scope[0] in ROOTS:
                body[(scope[0], nm)] = []
            stack.append(nm)
            depth_of.append(line.count("{") - line.count("}"))
            if depth_of[-1] <= 0:
                stack.pop()
                depth_of.pop()
            continue
        if len(stack) == 2 and (stack[0], stack[1]) in body:
            body[(stack[0], stack[1])].append(line)
        net = line.count("{") - line.count("}")
        if net and depth_of:
            depth_of[-1] += net
            while depth_of and depth_of[-1] <= 0:
                depth_of.pop()
                if stack:
                    stack.pop()

    # PUBLIC means the class declares scope 2 in its own body. An inherited
    # scope is the parent's business and is not visible from here.
    for (root, nm), b in body.items():
        m = re.search(r"^\s*scope\s*=\s*(\d+)\s*;", "\n".join(b), re.M)
        if m and int(m.group(1)) == 2:
            public[root].add(nm.lower())

    defined = dict((r, set(n.lower() for (rr, n) in body if rr == r)) for r in ROOTS)
    return public, listed, defined


def main():
    bad = 0
    checked = 0
    for d in sorted(os.listdir(ADDONS)):
        path = os.path.join(ADDONS, d)
        if not os.path.isdir(path):
            continue
        got = scan(path)
        if got is None:
            continue
        checked += 1
        public, listed, defined = got

        pre = prefix().lower()
        problems, notes = [], []
        for root, label in (("CfgVehicles", "units"), ("CfgWeapons", "weapons")):
            for nm in sorted(public[root] - listed[root]):
                # A class NOT carrying our prefix is an override of somebody
                # else's - addons/medical_treatment redeclares ACE_morphine to
                # reword it, and ACE already lists that class in its own
                # CfgPatches. Claiming it in ours would claim ownership of it.
                # Whether HEMTT counts that as L-C15 is not something this can
                # settle, so it is reported and not failed on.
                if nm.startswith(pre + "_") or nm.startswith("jmfsb_"):
                    problems.append("%s is public but not in %s[]" % (nm, label))
                else:
                    notes.append("%s overrides a class from another mod and is "
                                 "not in %s[]" % (nm, label))
            for nm in sorted(listed[root] - defined[root]):
                problems.append("%s[] names %s, which this addon does not define"
                                % (label, nm))
        if problems or notes:
            print("%s:" % d)
            for p in problems:
                print("    %s" % p)
            for n in notes:
                print("    note: %s" % n)
            bad += len(problems)
            print("")

    print("%d addon(s) checked" % checked)
    if bad:
        print("%d mismatch(es) between CfgPatches and the classes" % bad)
        print("")
        print("A public class missing from units[] cannot be placed in Zeus.")
        print("A units[] entry with no class points at nothing.")
        return 1
    print("every public class is listed, and every listed class exists")
    return 0


if __name__ == "__main__":
    sys.exit(main())
