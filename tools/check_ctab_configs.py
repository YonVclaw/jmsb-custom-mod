"""Structural checks for the ctab_devices configs.

Written when the addon shipped unrapified and `hemtt check` never opened these
files at all, so "Undefined base class" and "Member already defined" - both of
which have killed the game at launch - could only be found by launching.

RAPIFY IS ON AGAIN as of 2026-08-06 (see the addon's addon.toml), so hemtt now
catches those two itself. What is left here is what hemtt does NOT check:

    idc_dupes    two controls in one display sharing an idc - silently
                 unreachable, no error anywhere
    textures     every texture path named in the configs OR the sqf exists
    layout_hooks the deviceLayout hook is the last control in its block
    scan/parents/root_dupes  kept as belt and braces, and because they name the
                 specific failure better than the rapifier does

Run after any edit to the addon:

    python tools/check_ctab_configs.py

Exit code 1 if anything is wrong.
"""

import io
import os
import re
import sys

ADDON = os.path.join(os.path.dirname(os.path.abspath(__file__)),
                     "..", "addons", "ctab_devices")

FILES = ["CfgWeapons.hpp", "ui_s23.hpp", "ui_tablet.hpp", "ui_fbcb4.hpp", "config.cpp"]


def scan(path):
    bad = 0
    stack = [("<root>", set(), set())]   # (class name, member names, child class names)
    for n, raw in enumerate(io.open(path, encoding="utf-8").read().split("\n"), 1):
        line = raw.split("//")[0].strip()
        m = re.match(r"class\s+([A-Za-z_0-9()]+)", line)
        if m and "{" in line:
            name = m.group(1)
            if name in stack[-1][2]:
                print("%s:%d DUPLICATE CLASS %s in %s" % (path, n, name, stack[-1][0]))
                bad += 1
            stack[-1][2].add(name)
            stack.append((name, set(), set()))
            if line.count("}") >= line.count("{"):
                stack.pop()
            continue
        if m and line.endswith(";"):
            continue                      # a forward declaration
        p = re.match(r"([A-Za-z_0-9]+)(\[\])?\s*=", line)
        if p:
            key = p.group(1).lower()
            if key in stack[-1][1]:
                print("%s:%d DUPLICATE MEMBER %s in class %s" % (path, n, p.group(1), stack[-1][0]))
                bad += 1
            stack[-1][1].add(key)
        for ch in line:
            if ch == "{" and not m:
                stack.append(("<anon>", set(), set()))
            if ch == "}" and len(stack) > 1:
                stack.pop()
    return bad


def parents(paths):
    """Every parent class the ui files inherit from must be forward-declared
    at config.cpp root - a missing one is the other hard crash."""
    used = set()
    local = set()
    for p in paths:
        if not p.startswith("ui_"):
            continue
        text = io.open(os.path.join(ADDON, p), encoding="utf-8").read()
        for m in re.finditer(r"class\s+[A-Za-z_0-9()]+\s*:\s*([A-Za-z_0-9()]+)", text):
            used.add(m.group(1))
        # a bare `class X;` inside a patch declares the parent in that scope -
        # the menuContainer patch does this for cTab's btnTextonoff
        local |= set(re.findall(r"class\s+([A-Za-z_0-9()]+)\s*;", text))
        # and a class defined in a ui file can parent a later one
        local |= set(re.findall(r"class\s+([A-Za-z_0-9()]+)\s*[:{]", text))
    cfg = io.open(os.path.join(ADDON, "config.cpp"), encoding="utf-8").read()
    declared = set(re.findall(r"^class\s+([A-Za-z_0-9()]+)\s*[;{]", cfg, re.M))
    declared |= set(re.findall(r"class\s+([A-Za-z_0-9()]+)\s*;", cfg))
    declared |= local
    missing = {u for u in used
               if u not in declared and not u.startswith("GVAR(")}
    for m in sorted(missing):
        print("MISSING ROOT DECLARATION: class %s;" % m)
    return len(missing)


def layout_hooks(paths):
    """The deviceLayout hook must be the LAST control in its controls block.

    Controls are created in declaration order and onLoad fires as each one is
    made, so a hook declared above the controls it positions runs while they
    are still controlNull - every placement silently does nothing and the
    layout's once-per-display guard blocks the pass that would have worked.
    Everything then sits at its config position, which looks exactly like the
    layout code was never written. Three rounds of "the changes aren't in the
    build" came from this, so it is checked rather than remembered.
    """
    bad = 0
    for p in paths:
        text = io.open(os.path.join(ADDON, p), encoding="utf-8").read()

        # every `class controls {` block, brace-matched so nested groups and
        # the separate RscTitles scope cannot be confused for one another
        for opener in re.finditer(r"class\s+controls\s*\{", text):
            depth = 0
            i = opener.end() - 1
            start = i + 1
            while i < len(text):
                if text[i] == "{":
                    depth += 1
                elif text[i] == "}":
                    depth -= 1
                    if depth == 0:
                        break
                i += 1
            block = text[start:i]

            # the block's own direct children, in declaration order
            children = []
            depth = 0
            for m in re.finditer(r"class\s+([A-Za-z_0-9()]+)|\{|\}", block):
                tok = m.group(0)
                if tok == "{":
                    depth += 1
                elif tok == "}":
                    depth -= 1
                elif depth == 0:
                    children.append((m.group(1), m.start()))

            # a child's body runs to the next child - NOT to the next "};",
            # which a colorBackground[] = {0,0,0,0}; line already contains
            names = [n for n, _ in children]
            bounds = [s for _, s in children] + [len(block)]
            hooks = [i for i in range(len(children))
                     if "deviceLayout" in block[bounds[i]:bounds[i + 1]]]
            if not hooks:
                continue
            last = hooks[-1]
            if last != len(children) - 1:
                after = names[last + 1:]
                print("LAYOUT HOOK NOT LAST in %s: %s is followed by %d "
                      "control(s) (%s...) that will be controlNull when it runs"
                      % (p, names[last], len(after), after[0]))
                bad += 1
    return bad


def root_dupes(paths):
    """Root-level class names declared in more than one file.

    scan() checks each file on its own, but config.cpp #includes all the ui
    files into ONE root scope - so a template declared once per device file is
    three declarations at the same level, which is "Member already defined" and
    a hard crash at launch. That is exactly how GVAR(toolKey) got in.
    """
    bad = 0
    seen = {}
    for f in paths:
        path = os.path.join(ADDON, f)
        depth = 0
        for n, raw in enumerate(io.open(path, encoding="utf-8").read().split("\n"), 1):
            line = raw.split("//")[0].strip()
            m = re.match(r"class\s+([A-Za-z_0-9()]+)", line)
            if m and "{" in line and depth == 0:
                seen.setdefault(m.group(1), []).append("%s:%d" % (f, n))
            depth += line.count("{") - line.count("}")
            depth = max(depth, 0)
    for name, where in sorted(seen.items()):
        if len(where) > 1:
            print("ROOT CLASS %s declared %d times: %s" % (name, len(where), ", ".join(where)))
            bad += 1
    return bad


def idc_dupes(paths):
    """Two controls in the SAME display sharing an idc.

    `displayCtrl` returns the first match, so the second control is simply
    unreachable - it never moves, never shows, never takes a click, and nothing
    anywhere errors. Three of these have shipped (467811, 467393, 467813) and
    each was found by noticing a control had stopped working.

    Scoped per DISPLAY, not per file: ui_s23.hpp holds both the dialog and the
    held-up HUD, and the same idc appearing once in each is correct - they are
    different displays. A file-wide check calls that a duplicate and cries wolf.
    """
    bad = 0
    for f in paths:
        if not f.startswith("ui_"):
            continue
        text = io.open(os.path.join(ADDON, f), encoding="utf-8").read()

        display = None
        depth = 0
        seen = {}
        for n, raw in enumerate(text.split("\n"), 1):
            line = raw.split("//")[0]

            m = re.match(r"\s*class\s+([A-Za-z_0-9()]+)", line)
            if m and depth == 0 and "{" in line:
                display = m.group(1)
                seen = {}

            for hit in re.finditer(r"\bidc\s*=\s*(-?\d+)\s*;", line):
                idc = int(hit.group(1))
                if idc == -1 or display is None:
                    continue
                if idc in seen:
                    print("%s:%d DUPLICATE IDC %d in display %s (also line %d)"
                          % (f, n, idc, display, seen[idc]))
                    bad += 1
                else:
                    seen[idc] = n

            depth += line.count("{") - line.count("}")
            depth = max(depth, 0)
            if depth == 0:
                display = None
    return bad


def textures(paths):
    """Every texture the addon names must actually be on disk.

    A missing one is not a crash - it is a black rectangle where a glyph should
    be, or nothing at all, which is the kind of thing that survives a build and
    is found in a screenshot. `hemtt check` would catch it for any other addon;
    it never opens these files. The SQF is scanned too, because half this
    addon's art is set with ctrlSetText at runtime.

    Only jmfsb's own paths are resolved. cTab's and ACE's live in mods this
    repo does not contain, so they are nobody's business here.
    """
    bad = 0
    root = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "addons")
    files = list(paths) + [os.path.join("functions", f)
                           for f in sorted(os.listdir(os.path.join(ADDON, "functions")))
                           if f.endswith(".sqf")]
    for f in files:
        text = io.open(os.path.join(ADDON, f), encoding="utf-8").read()
        wanted = set()
        # QPATHTOF(data\x_ca.paa) - this addon's own data folder
        for m in re.finditer(r"Q?PATHTOF\(([^)]+)\)", text):
            wanted.add(os.path.join(ADDON, m.group(1).replace("\\", os.sep)))
        # a full path written out, to this or any other jmfsb addon
        for m in re.finditer(r"\\z\\jmfsb\\addons\\([^\"']+\.(?:paa|jpg|png))", text, re.I):
            wanted.add(os.path.join(root, m.group(1).replace("\\", os.sep)))
        for w in sorted(wanted):
            # a format string builds the name at runtime (the weather glyphs
            # are icon_wx_%1_cloud_ca.paa) - there is nothing to look up
            if "%" in w:
                continue
            if not os.path.isfile(w):
                print("MISSING TEXTURE in %s: %s" % (f, os.path.normpath(w)))
                bad += 1
    return bad


def main():
    # THE ADDON IS GONE. ctab_devices was archived to backups/ctab on
    # 2026-08-10 when jmfsb_messaging replaced the cTab suite, and this walked
    # straight into a FileNotFoundError on its first file and took check_all
    # down with it. Nothing to check is not a failure; it is the addon not
    # being here. Left in place rather than deleted because the checks below
    # are the only ones that ever caught these faults, and the archived copy
    # can be dropped back under addons/ to run them again.
    if not os.path.isdir(ADDON):
        print("check_ctab_configs: SKIPPED - addons/ctab_devices is not present")
        return

    bad = 0
    for f in FILES:
        bad += scan(os.path.join(ADDON, f))
    bad += root_dupes(FILES)
    bad += parents(FILES)
    bad += layout_hooks(FILES)
    bad += idc_dupes(FILES)
    bad += textures(FILES)
    print("check_ctab_configs:", "OK" if bad == 0 else "%d PROBLEMS" % bad)
    sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
