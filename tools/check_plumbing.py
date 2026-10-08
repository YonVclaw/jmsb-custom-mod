"""Every knob must have a reader. Fails the build when one does not.

    python tools/check_plumbing.py

The failure mode this exists for: a module attribute or CBA setting that is
declared, documented and shown to the mission maker - and read by NOTHING.
Four of the old Site module's eight types were exactly that, and they were
found by a person tripping over them. This finds them mechanically.

Two sweeps:

  1. MODULE ATTRIBUTES. Every `expression = ... setVariable ['name' ...]` in a
     CfgVehicles.hpp writes a variable onto the module logic. The quoted name
     must appear in at least one .sqf under addons/ - via getVariable, a
     format-key list, anything. A name no script ever mentions is a dead knob.

  2. CBA SETTINGS. Every QGVAR(name) declared in an initSettings.inc.sqf must
     be read somewhere: as GVAR(name) / QGVAR(name) in its own addon or as the
     full jmfsb_<addon>_name string anywhere.

  3. XEH SCRIPTS. Every script a CfgEventHandlers.hpp references
     (COMPILE_FILE/COMPILE_SCRIPT, any init key) must exist as a file. The
     engine only reports this at mission start, as a warning box - a restored
     config referencing per-locality files that were consolidated shipped
     exactly that way once.

  5. PER-FRAME HANDLERS. CBA calls a PFH with [args, handle], so a function
     wired as one must accept an ARRAY first. uas wired topUp - whose first
     param is a Side - and it threw on every tick for a whole mission while
     the fleet silently never topped up. The engine reports it as a params
     type error in a file that looks innocent.

  4. VEHICLE CLASSES AND MODULE CATEGORIES. Every literal `vehicleClass` and
     every module `category` must name a class that exists: one this repo
     defines in CfgVehicleClasses / CfgFactionClasses, or a vanilla one on the
     known list. Two props carried vehicleClass = "jmfsb", which is the
     FACTION class - the engine cannot read a displayName off it and warned
     three times per mission start. Every module in the mod had the same
     defect at the same time: they claimed "jmfsb_modules" and
     "jmfsb_ambient_modules" and NEITHER was defined, so every one of them
     filed itself under a category with no name. Both fields are only ever
     strings, so nothing else checks them.

Names that are intentionally write-only (consumed by an external mod, or a
public mission-maker override) go in the allowlist WITH A REASON.
"""
import io
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ADDONS = os.path.join(ROOT, "addons")

# Base-game CfgVehicleClasses this mod files things under. Short on purpose:
# anything not here has to be a class the repo defines itself, which is the
# whole point of the sweep.
VANILLA_VEHICLE_CLASSES = {
    "Items", "ItemsHeadgear", "ItemsUniform", "ItemsVest", "Modules", "Static",
    "WeaponAccessories", "Autonomous", "Air", "Car", "Men", "MenRecon", "Ship", "Support",
}

# name -> why it legitimately has no jmfsb reader
ALLOW = {
    "route_name": "read lazily by buildRoutes via getVariable at table-build time",
}

# Attribute writes come in two shapes: a hand-written class with an explicit
# expression, and an AEDIT/ABOOL/APICK macro invocation whose expression lives
# in the #define (which itself contains the literal 'NAME' - skipped).
# Only an `expression = ...` line actually writes an attribute. A setVariable
# appearing in a tooltip is documentation for the mission maker (the intel
# spot's Init example writes 'cache'), not a knob this file declares.
ATTR = re.compile(r"expression\s*=\s*[^;]*?setVariable \[(?:ARR_2\()?'(\w+)'")
ATTR_MACRO = re.compile(r"^\s*(?:AEDIT|ABOOL|APICK)\((\w+),", re.M)
ATTR_ROLE = re.compile(r"^\s*DEF_ROLE\((\w+),", re.M)
SETTING = re.compile(r"^\s*QGVAR\((\w+)\),", re.M)


def read(p):
    try:
        return io.open(p, encoding="utf-8", errors="replace").read()
    except OSError:
        return ""


def shown_of(path):
    return os.path.relpath(path, ROOT).replace("\\", "/")


def main():
    # every .sqf, one big haystack per addon plus a global one
    sqf_all = []
    sqf_by_addon = {}
    for dirpath, _dirs, files in os.walk(ADDONS):
        addon = os.path.relpath(dirpath, ADDONS).replace("\\", "/").split("/")[0]
        for f in files:
            if f.endswith(".sqf"):
                t = read(os.path.join(dirpath, f))
                sqf_all.append(t)
                sqf_by_addon.setdefault(addon, []).append(t)
    hay = "\n".join(sqf_all)

    # CfgVehicleClasses entries this repo defines, macro form resolved
    defined_vc = set()
    defined_cat = set()
    for dirpath, _dirs, files in os.walk(ADDONS):
        for f in files:
            if not f.endswith((".hpp", ".cpp")):
                continue
            t = read(os.path.join(dirpath, f))
            for m in re.finditer(r"class\s+CfgVehicleClasses\s*\{(.*?)\n\};", t, re.S):
                for c in re.finditer(r"class\s+(\w+)", m.group(1)):
                    defined_vc.add(c.group(1).replace("PREFIX##", "jmfsb"))
            # module categories are CfgFactionClasses entries, and jmfsb writes
            # some of them through DOUBLES(PREFIX,name)
            for m in re.finditer(r"class\s+CfgFactionClasses\s*\{(.*?)\n\};", t, re.S):
                for c in re.finditer(r"class\s+(?:DOUBLES\(PREFIX,(\w+)\)|(\w+))", m.group(1)):
                    defined_cat.add("jmfsb_" + c.group(1) if c.group(1) else c.group(2))

    dead_attrs = []
    dead_settings = []
    dead_xeh = []
    bad_vc = []
    bad_pfh = []

    # LINKFUNC(name) wired straight into a per-frame handler
    # non-greedy to the call, and stopping at a statement end: the argument
    # list contains its own brackets ([LINKFUNC(x), TICK, []] call ...), so a
    # bracket-counting pattern misses every real case.
    PFH = re.compile(r"LINKFUNC\((\w+)\)[^;]*?CBA_fnc_addPerFrameHandler")
    for dirpath, _dirs, files in os.walk(ADDONS):
        addon = os.path.relpath(dirpath, ADDONS).replace("\\", "/").split("/")[0]
        for f in files:
            if not f.endswith(".sqf"):
                continue
            path = os.path.join(dirpath, f)
            t = read(path)
            for m in PFH.finditer(t):
                fn = os.path.join(ADDONS, addon, "functions", "fnc_%s.sqf" % m.group(1))
                if not os.path.isfile(fn):
                    continue
                # the FIRST declared param decides it: CBA hands over an array
                pm = re.search(r"^params\s*\[\s*(.+)$", read(fn), re.M)
                if not pm:
                    continue                      # takes nothing - always safe
                first = pm.group(1).lstrip()
                if first.startswith('"'):
                    continue                      # untyped, e.g. params ["_args"]
                ty = re.match(r'\[\s*"\w+"\s*,[^,]+,\s*(\[\[?\]?\])', first)
                if ty and ty.group(1) in ("[[]]", "[]"):
                    continue                      # declares an array - correct
                n = t[:m.start()].count("\n") + 1
                bad_pfh.append("%s:%d  %s (first param is not an array)"
                               % (shown_of(path), n, m.group(1)))

    for dirpath, _dirs, files in os.walk(ADDONS):
        addon = os.path.relpath(dirpath, ADDONS).replace("\\", "/").split("/")[0]
        for f in files:
            path = os.path.join(dirpath, f)
            shown = os.path.relpath(path, ROOT).replace("\\", "/")

            if f.endswith(".hpp") and "CfgVehicles" in f:
                t = read(path)
                writes = []
                for m in ATTR.finditer(t):
                    if m.group(1) != "NAME":            # the macro body itself
                        writes.append((m.group(1), m.start()))
                for m in ATTR_MACRO.finditer(t):
                    writes.append((m.group(1), m.start()))
                for m in ATTR_ROLE.finditer(t):         # DEF_ROLE writes a pair
                    writes.append((m.group(1) + "_classes", m.start()))
                    writes.append((m.group(1) + "_count", m.start()))
                for name, pos in writes:
                    if name in ALLOW:
                        continue
                    # the quoted name anywhere in any script counts - readers
                    # use getVariable ["name"...], format-key lists, publics
                    if ('"%s"' % name) not in hay and ("'%s'" % name) not in hay:
                        n = t[:pos].count("\n") + 1
                        dead_attrs.append("%s:%d  %s" % (shown, n, name))

            if f.endswith((".hpp", ".cpp")):
                t = read(path)
                for m in re.finditer(r'vehicleClass\s*=\s*"([^"]+)"', t):
                    name = m.group(1)
                    if name in VANILLA_VEHICLE_CLASSES or name in defined_vc:
                        continue
                    n = t[:m.start()].count("\n") + 1
                    bad_vc.append("%s:%d  vehicleClass %s" % (shown, n, name))

                # ## DOES NOT CONCATENATE INSIDE QUOTE. Arma's stringiser
                # expands macro arguments but leaves the paste operator as
                # literal text, so QUOTE(PREFIX##_Vehicles) produced the string
                # "jmfsb##_Vehicles" - a class name that cannot exist, and only
                # an RPT warning to say so. Use a concatenating macro instead:
                # QUOTE(DOUBLES(PREFIX,Vehicles)) gives "jmfsb_Vehicles",
                # because DOUBLES is expanded as a macro CALL before the
                # stringiser sees it. Inside a #define body ##PARAM## is
                # ordinary parameter pasting and is left alone.
                for i, line in enumerate(t.split("\n")):
                    if line.rstrip().endswith("\\") or line.lstrip().startswith("#define"):
                        continue
                    if re.search(r"QUOTE\([^)]*##", line):
                        bad_vc.append("%s:%d  ## inside QUOTE - use DOUBLES/TRIPLES"
                                      % (shown, i + 1))

                # A CONFIG STRING IS NOT A C STRING. Backslashes in an Arma
                # path are literal, so "\\A3\\..." asks the engine for a file
                # whose name really does contain doubled separators. It shipped
                # that way on six modules at once because a generator escaped
                # the paths as if it were writing C, and the only sign was one
                # "Cannot load texture" per module at every mission start.
                for i, line in enumerate(t.split("\n")):
                    if line.rstrip().endswith("\\") or line.lstrip().startswith("#define"):
                        continue
                    if re.search(r'=\s*"[^"]*\\\\', line):
                        bad_vc.append("%s:%d  doubled backslash in a config path"
                                      % (shown, i + 1))

                # A module's category is a CfgFactionClasses entry. Only jmfsb's
                # own are checked: base-game and other mods' categories are
                # legitimate targets and are not this repo's to verify.
                for m in re.finditer(r'category\s*=\s*"(jmfsb\w*)"', t):
                    name = m.group(1)
                    if name in defined_cat:
                        continue
                    n = t[:m.start()].count("\n") + 1
                    bad_vc.append("%s:%d  category %s" % (shown, n, name))

            if f == "CfgEventHandlers.hpp":
                t = read(path)
                for m in re.finditer(r"COMPILE_(?:SCRIPT|FILE)\((\w+)\)", t):
                    sqf = os.path.join(dirpath, m.group(1) + ".sqf")
                    if not os.path.isfile(sqf):
                        n = t[:m.start()].count("\n") + 1
                        dead_xeh.append("%s:%d  %s.sqf" % (shown, n, m.group(1)))

            if f == "initSettings.inc.sqf":
                t = read(path)
                local = "\n".join(sqf_by_addon.get(addon, []))
                for m in SETTING.finditer(t):
                    name = m.group(1)
                    if name in ALLOW:
                        continue
                    full = "jmfsb_%s_%s" % (addon, name)
                    if ("GVAR(%s)" % name) not in local and full not in hay:
                        n = t[:m.start()].count("\n") + 1
                        dead_settings.append("%s:%d  %s" % (shown, n, name))

    print("Validating plumbing (every knob has a reader)")
    print("------")

    ok = True
    if dead_attrs:
        ok = False
        print("MODULE ATTRIBUTES READ BY NOTHING (%d)" % len(dead_attrs))
        print("  Declared in Eden, shown to the mission maker, consumed by no script.")
        print("  Wire it or delete it; allowlist only with a reason.")
        for s in dead_attrs:
            print("    " + s)
        print("")

    if dead_settings:
        ok = False
        print("CBA SETTINGS READ BY NOTHING (%d)" % len(dead_settings))
        for s in dead_settings:
            print("    " + s)
        print("")

    if dead_xeh:
        ok = False
        print("XEH SCRIPTS THAT DO NOT EXIST (%d)" % len(dead_xeh))
        print("  The engine finds these as warning boxes at mission start.")
        for s in dead_xeh:
            print("    " + s)
        print("")

    if bad_vc:
        ok = False
        print("VEHICLE CLASSES / MODULE CATEGORIES THAT DO NOT EXIST (%d)" % len(bad_vc))
        print("  Eden files an object by its vehicleClass; a missing one warns")
        print("  about the class, its displayName and an empty path, every start.")
        for s in bad_vc:
            print("    " + s)
        print("")

    if bad_pfh:
        ok = False
        print("PER-FRAME HANDLERS WIRED TO THE WRONG FUNCTION (%d)" % len(bad_pfh))
        print("  CBA calls a PFH with [args, handle] - the function must take an array.")
        for s in bad_pfh:
            print("    " + s)
        print("")

    if not ok:
        print("plumbing check FAILED")
        return 1

    print("all declared attributes and settings have readers")
    return 0


if __name__ == "__main__":
    sys.exit(main())
