#!/usr/bin/env python3
"""Every parent a config inherits from must be present, in scope, BEFORE its use.

    python tools/check_externals.py

WHY THIS EXISTS. `class A: B {}` where B is defined in a DIFFERENT addon is not
an inheritance - the engine builds A with no parent, silently, and A gets none
of B's values. HEMTT catches it as L-C04, but only when someone runs HEMTT, and
HEMTT is not on every machine that touches this repo.

The fix is always the same: a forward declaration, `class B;`, ahead of the
class that inherits from it. That declares B external - "defined elsewhere,
resolve it at bind time" - and costs nothing.

THREE THINGS ARE CHECKED, and the first two are not enough on their own:

  1. The parent is present in the same addon - declared or defined.
  2. It appears BEFORE the class that uses it. A declaration further down the
     file is not visible to a class above it.
  3. It is in scope - lexically, or through what the enclosing class inherits.

WHAT IS NOT CHECKED. `class Turrets: Turrets` inherits the same-named member of
whatever the enclosing class descends from. Where that is an external class -
a base game vehicle, a helmet from another mod - the body is not in this config
and the members cannot be listed from here. The idiom is correct and universal,
and only the engine, holding every config at once, can judge it.

  4. It is in an enclosing scope. `class CfgAmmo { class X; }` declares
     nothing for `class CfgMagazines` - different root - but a name declared at
     the root of a dialog file IS visible to a control nested inside it,
     because the engine resolves a parent by walking outward.

INCLUDE ORDER IS FOLLOWED, not filename order. The config the engine sees is
config.cpp with its #includes expanded in the order written, so that is what is
walked. Checking files individually would pass a config whose declarations sit
in a file included after the one that needs them.
"""
import io
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ADDONS = os.path.join(ROOT, "addons")

INCLUDE = re.compile(r'^[ \t]*#include\s+"([^"]+)"', re.M)
# CLASS NAMES CAN BE MACRO CALLS. Half this repo declares `class GVAR(name):
# Base {`, and a pattern that only accepts \w+ does not see those lines at all -
# so the scope stack never pushes them, AND the brace on that line is credited
# to the enclosing class, which corrupts every depth after it.
NAME = r"\w+(?:\s*\([^)]*\))?"
DECL = re.compile(r"^[ \t]*class\s+(" + NAME + r")\s*;")
DEFN = re.compile(r"^[ \t]*class\s+(" + NAME + r")\s*(?::\s*(" + NAME + r")\s*)?\{")


def strip_comments(t):
    t = re.sub(r"/\*.*?\*/", "", t, flags=re.S)
    t = re.sub(r"//[^\n]*", "", t)
    # MACRO BODIES ARE NOT CONFIG. `#define HEARING(C) class C: ItemCore {...}`
    # names a parent that resolves wherever the macro is expanded, not here -
    # judging it against this addon's classes reports a problem that isn't one.
    # A #define runs to the first line not ending in a backslash.
    return re.sub(r"^[ \t]*#define\b(?:[^\n]*\\\r?\n)*[^\n]*", "", t, flags=re.M)


def expand(path, seen, out):
    """config.cpp with its #includes inlined, in the order they are written."""
    real = os.path.normcase(os.path.abspath(path))
    if real in seen or not os.path.isfile(path):
        return
    seen.add(real)
    base = os.path.dirname(path)
    rel = os.path.relpath(path, ROOT).replace(os.sep, "/")
    text = strip_comments(io.open(path, encoding="utf-8", errors="replace").read())
    for lineno, line in enumerate(text.split("\n"), 1):
        m = INCLUDE.match(line)
        if m:
            target = m.group(1)
            # Absolute PBO paths (\z\jmfsb\...) are somebody else's file and
            # are not resolvable from here; local includes are.
            if not target.startswith("\\"):
                expand(os.path.join(base, target.replace("\\", "/")), seen, out)
            continue
        out.append((rel, lineno, line))


def check(addon_dir):
    """(missing, late) for one addon's preprocessed config."""
    cfg = os.path.join(addon_dir, "config.cpp")
    if not os.path.isfile(cfg):
        return [], []

    flat = []
    expand(cfg, set(), flat)

    # Walk with a class-path stack so a declaration is only credited to the
    # root it actually sits in.
    stack = []
    known = {}          # (scope_path, name) -> position it became visible
    base_of = {}        # scope_path of a class -> the name it inherits from
    missing, late = [], []
    depth_of_open = []

    cache = {}

    def find_path(scope, name, guard=0):
        """Full path of `name` as seen from `scope`, or None.

        SCOPE RESOLUTION IS RECURSIVE, and this is the part two earlier versions
        of this check got wrong. `class jmfsb_moduleQRF: Module_F` puts
        Module_F's members in scope - but `AttributesBase` is one of them, so
        `class Attributes: AttributesBase` can only be judged after Module_F
        itself has been resolved. Walking enclosing braces alone, or following
        one inheritance hop without resolving the base first, calls every module
        and every retextured vehicle in this repo broken. Both did.
        """
        key = (scope, name)
        if key in cache:
            return cache[key]
        if guard > 64:
            return None
        cache[key] = None          # cycle guard while we work
        found = None
        cur = scope
        while found is None:
            if (cur, name) in known:
                found = cur + (name,)
                break
            # then through the inheritance chain of the class AT cur, each link
            # resolved from its own enclosing scope
            path, hops = cur, 0
            while path and hops < 32:
                hops += 1
                b = base_of.get(path)
                if not b:
                    break
                bpath = find_path(path[:-1], b, guard + 1)
                if not bpath:
                    break
                if (bpath, name) in known:
                    found = bpath + (name,)
                    break
                path = bpath
            if found is not None or not cur:
                break
            cur = cur[:-1]
        cache[key] = found
        return found

    for pos, (rel, lineno, line) in enumerate(flat):
        stripped = line.strip()
        if not stripped:
            continue

        m = DECL.match(line)
        if m:
            known.setdefault((tuple(stack), m.group(1)), pos)
            cache.clear()
            continue

        m = DEFN.match(line)
        if m:
            name, parent = m.group(1), m.group(2)
            scope = tuple(stack)
            if parent:
                # Macro-built names resolve at preprocess time; nothing here
                # can judge them.
                # `class Turrets: Turrets` INHERITS THE SAME-NAMED MEMBER of
                # whatever the enclosing class inherits from. When that is an
                # external class - a base game vehicle, a helmet from another
                # mod - its body is not in this config and its members cannot
                # be enumerated from here. The idiom is correct and universal;
                # only the engine, with every config loaded, can judge it.
                self_named = parent == name
                if not (parent.isupper() or parent == "ADDON" or self_named):
                    # SCOPE RESOLVES OUTWARD. `class RscText;` at the root of a
                    # dialog file is visible to a control nested three deep
                    # inside it - the engine walks enclosing scopes looking for
                    # the name. Checking only the immediate scope reported a
                    # hundred correct configs as broken.
                    found = find_path(scope, parent)
                    at = known.get((found[:-1], parent)) if found else None
                    if at is None:
                        missing.append((parent, name, rel, lineno))
                    elif at > pos:
                        late.append((parent, name, rel, lineno))
            known.setdefault((scope, name), pos)
            cache.clear()
            if parent:
                base_of.setdefault(scope + (name,), parent)
            stack.append(name)
            depth_of_open.append(line.count("{") - line.count("}"))
            # a one-line class body opens and closes on the same line
            if depth_of_open[-1] <= 0:
                stack.pop()
                depth_of_open.pop()
            continue

        # Track braces for bodies that span lines.
        net = line.count("{") - line.count("}")
        if net and depth_of_open:
            depth_of_open[-1] += net
            while depth_of_open and depth_of_open[-1] <= 0:
                depth_of_open.pop()
                if stack:
                    stack.pop()

    return missing, late


def main():
    if not os.path.isdir(ADDONS):
        print("no %s" % ADDONS)
        return 1

    bad = 0
    checked = 0
    for d in sorted(os.listdir(ADDONS)):
        path = os.path.join(ADDONS, d)
        if not os.path.isdir(path):
            continue
        checked += 1
        missing, late = check(path)

        # One line per parent, not per use - a parent used by forty tracer
        # variants is one missing declaration, not forty problems.
        groups = {}
        for parent, child, rel, lineno in missing:
            groups.setdefault(("missing", parent), []).append((child, rel, lineno))
        for parent, child, rel, lineno in late:
            groups.setdefault(("late", parent), []).append((child, rel, lineno))

        if groups:
            print("%s:" % d)
            for (kind, parent) in sorted(groups):
                child, rel, lineno = groups[(kind, parent)][0]
                extra = ""
                n = len(groups[(kind, parent)])
                if n > 1:
                    extra = " (and %d more)" % (n - 1)
                if kind == "missing":
                    print("    class %s;   MISSING - needed by %s at %s:%d%s"
                          % (parent, child, rel, lineno, extra))
                else:
                    print("    class %s;   DECLARED TOO LATE for %s at %s:%d%s"
                          % (parent, child, rel, lineno, extra))
                bad += 1
            print("")

    print("%d addon(s) checked" % checked)
    if bad:
        print("%d parent(s) not in scope where they are used" % bad)
        print("")
        print("Each one is a class built with NO parent at run time, and none of")
        print("the values it was supposed to inherit. HEMTT reports these as L-C04.")
        return 1
    print("every inherited parent is in scope, in the right config root, before use")
    return 0


if __name__ == "__main__":
    sys.exit(main())
