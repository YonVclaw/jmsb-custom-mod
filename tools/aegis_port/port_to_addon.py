#!/usr/bin/env python3
"""Fold a sandbox seed import into ONE new jmfsb addon, leaving the five import addons as they are.

THE ASK (user, 2026-10-06: Russia remade without e22, its soldiers "look in A3_Aegis_Public_Releases for russian uniforms
and loadouts"; asked: "A new addon, uniform_ru", the Gepard's men on the AK-12U). port.py writes into the five addons
(uniform, vests, headware, weapons, vehicle) and replaces what it wrote there before - re-running it on the repo would
undo the hand work done in them since. So the port runs in a sandbox copy with only the new seeds:

    python tools/aegis_port/port.py --seeds rus_seeds.txt              (in the sandbox, e.g. D:/work/ru_port_sandbox)
    python tools/aegis_port/port_to_addon.py D:/work/ru_port_sandbox uniform_ru

and this folds the sandbox's five addons into addons/<target>:
  * a class the repo's addon already defines under the same name is reused (EGVAR(<addon>,X)), not copied;
  * every other class comes over under the target's name, its references to the others rewritten;
  * a path into a sandbox addon's models\\ points at the repo's same file where it exists, else the file is copied
    under <target>\\models\\<addon>\\ - inside configs, materials, model.cfg and the models themselves;
  * SWAP replaces kit in the soldiers' loadouts before anything is read, DROP leaves classes out.
"""
import collections
import os
import re
import shutil
import sys

JMFSB = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
FIVE = ("weapons", "vests", "headware", "uniform", "vehicle")
# the Gepard SMG was taken out of jmfsb (2026-10-06); its men carry the AK-12U and its magazines
SWAP = [("QEGVAR(weapons,SMG_Gepard_blk_ACO_F)", "QEGVAR(weapons,arifle_AK12U_545_aco_F)"),
        ("QEGVAR(weapons,40Rnd_9x21_Gepard_Green_Mag_F)", "QEGVAR(weapons,30Rnd_545x39_AK12_Mag_F)"),
        ("QEGVAR(weapons,40Rnd_9x21_Gepard_Mag_F)", "QEGVAR(weapons,30Rnd_545x39_AK12_Mag_F)")]
DROP = re.compile(r"(?i)gepard")
ASSET = re.compile(r"(?i)\\?z\\jmfsb\\addons\\(%s)\\models\\([\w\\/ .\-]+?\.(?:paa|rvmat|p3d|tga|png|rtm|wss|ogg|wav|jpg|bisurf))" % "|".join(FIVE))
ASSET_B = re.compile(rb"(?i)z\\jmfsb\\addons\\(" + "|".join(FIVE).encode() + rb")\\models\\([\w\\/ .\-]+?)(\.(?:paa|rvmat|p3d|tga|png|rtm|wss|ogg|wav|jpg|bisurf))?(?=[\x00\"'\s;,)}]|$)")
CLASS = re.compile(r"(?m)^([ \t]*)class (GVAR\((\w+)\)|\w+)\s*(?::\s*([\w(),]+))?\s*(\{|;)")


def rd(p):
    return open(p, encoding="utf-8", errors="replace", newline="").read()


def defined(addon_dir):
    """The GVAR names an addon defines anywhere in its configs, lower case."""
    out = set()
    for dp, _dn, fs in os.walk(addon_dir):
        if os.sep + "models" in dp:
            continue
        for f in fs:
            if f.lower().endswith((".hpp", ".cpp")):
                out |= {m.lower() for m in re.findall(r"class GVAR\((\w+)\)\s*[:{]", rd(os.path.join(dp, f)))}
    return out


def mask(text):
    """Strings and comments blanked (same length), so braces in them are not counted."""
    out = list(text)
    for m in re.finditer(r'"(?:[^"]|"")*"|//[^\n]*|/\*.*?\*/', text, re.S):
        for k in range(m.start(), m.end()):
            if out[k] != "\n":
                out[k] = " "
    return "".join(out)


def blocks(text):
    """The top-level pieces of a file, in order: (class token, its GVAR name or None, text). A class is one piece,
    with its trailing newline; the lines between classes are pieces with no token."""
    mt = mask(text)
    out, i, depth, last = [], 0, 0, 0
    starts = {m.start(): m for m in CLASS.finditer(mt)}
    n = len(text)
    while i < n:
        if depth == 0 and i in starts:
            m = starts[i]
            if last < m.start():
                out.append((None, None, text[last:m.start()]))
            if m.group(5) == ";":
                e = mt.find("\n", m.end())
                e = n if e < 0 else e + 1
            else:
                j, d = m.end(), 1
                while d and j < n:
                    d += {"{": 1, "}": -1}.get(mt[j], 0)
                    j += 1
                e = mt.find("\n", j)
                e = n if e < 0 else e + 1
            out.append((m.group(2), m.group(3), text[m.start():e]))
            i = last = e
            continue
        c = mt[i]
        depth += c == "{"
        depth -= c == "}"
        i += 1
    if last < n:
        out.append((None, None, text[last:]))
    return out


def tables(text):
    """An imported_config.hpp / imported_root.hpp: {table: its inner text}; what sits outside any table under None."""
    out = collections.OrderedDict()
    for tok, _plain, body in blocks(text):
        m = re.match(r"\s*class (\w+)\s*\{", body) if tok else None
        if m and tok.lower().startswith("cfg"):
            out.setdefault(tok, []).append(body[body.index("{") + 1:body.rstrip().rindex("}")])
        elif tok or body.strip():
            out.setdefault(None, []).append(body)
    return {k: "\n".join(v) for k, v in out.items()}


def write_config(T, target, new, sandbox_addons):
    """The target's config.cpp: its units and weapons, what the sandbox's five configs required, the files."""
    req = set()
    units, weapons = [], []
    for a in FIVE:
        p = os.path.join(sandbox_addons, a, "config.cpp")
        if not os.path.exists(p):
            continue
        t = rd(p)
        m = re.search(r"requiredAddons\[\]\s*=\s*\{([^}]*)\}", re.sub(r"//[^\n]*", "", t))
        if m:
            req |= set(re.findall(r'"([^"]+)"', m.group(1)))
        for arr, into in (("units", units), ("weapons", weapons)):
            mm = re.search(r"// --- imported %s:[^\n]*\n(.*?)// --- end imported %s" % (arr, arr), t, re.S)
            if mm:
                for x in re.findall(r"Q?GVAR\((\w+)\)", mm.group(1)):
                    if x.lower() in new[a] and x not in into:
                        into.append(x)
    req = sorted(r for r in req if not r.lower().startswith("jmfsb_")) + ["jmfsb_main"] + ["jmfsb_%s" % a for a in FIVE if a != "vehicle"]
    cfg = ['#include "script_component.hpp"', "",
           "// Generated by tools/aegis_port/port_to_addon.py - re-run it rather than hand-edit.",
           "class CfgPatches {", "    class ADDON {", "        name = COMPONENT_NAME;",
           "        units[] = {%s};" % ", ".join("QGVAR(%s)" % u for u in units),
           "        weapons[] = {%s};" % ", ".join("QGVAR(%s)" % w for w in weapons),
           "        requiredVersion = REQUIRED_VERSION;",
           "        requiredAddons[] = {%s};" % ", ".join('"%s"' % r for r in req),
           "        author = QAUTHOR;", "        VERSION_CONFIG;", "    };", "};", "",
           '#include "CfgEventHandlers.hpp"', '#include "imported_root.hpp"', '#include "CfgVehicles.hpp"',
           '#include "CfgWeapons.hpp"', '#include "imported_config.hpp"', ""]
    open(os.path.join(T, "config.cpp"), "w", encoding="utf-8", newline="\n").write("\n".join(cfg))
    return units, weapons


def main(sandbox, target):
    S = os.path.join(sandbox, "addons")
    T = os.path.join(JMFSB, "addons", target)
    real = {a: defined(os.path.join(JMFSB, "addons", a)) for a in FIVE}
    new = {a: set() for a in FIVE}             # sandbox classes that come over (lower case)
    srcs = collections.defaultdict(list)       # table -> [(addon, text)]
    for a in FIVE:
        d = os.path.join(S, a)
        for f, table in (("imported_CfgVehicles_decl.hpp", "CfgVehicles"), ("imported_CfgVehicles.hpp", "CfgVehicles"),
                         ("imported_CfgWeapons_decl.hpp", "CfgWeapons"), ("imported_CfgWeapons.hpp", "CfgWeapons")):
            p = os.path.join(d, f)
            if os.path.exists(p):
                srcs[table].append((a, rd(p)))
        for f in ("imported_config.hpp", "imported_root.hpp"):
            p = os.path.join(d, f)
            if os.path.exists(p):
                for table, inner in tables(rd(p)).items():
                    srcs[table or "<root>"].append((a, inner))
    for table in srcs:
        srcs[table] = [(a, _swap(t)) for a, t in srcs[table]]
    for table, lst in srcs.items():
        for a, t in lst:
            for tok, plain, _body in blocks(t):
                if plain and plain.lower() not in real[a] and not DROP.search(plain):
                    new[a].add(plain.lower())

    def ref(addon, name, quoted):
        """A sandbox reference to (addon, name) -> how the target addon writes it."""
        n = name.lower()
        if n in new.get(addon, ()):
            return ("QGVAR(%s)" if quoted else "GVAR(%s)") % name
        return ("QEGVAR(%s,%s)" if quoted else "EGVAR(%s,%s)") % (addon, name)

    def retext(t, a):
        t = re.sub(r"\bQEGVAR\((\w+),\s*(\w+)\)", lambda m: ref(m.group(1), m.group(2), True) if m.group(1) in FIVE else m.group(0), t)
        t = re.sub(r"(?<![QE])\bEGVAR\((\w+),\s*(\w+)\)", lambda m: ref(m.group(1), m.group(2), False) if m.group(1) in FIVE else m.group(0), t)
        t = re.sub(r"\bQGVAR\((\w+)\)", lambda m: ref(a, m.group(1), True), t)
        t = re.sub(r"(?<![QE])\bGVAR\((\w+)\)", lambda m: ref(a, m.group(1), False), t)
        return ASSET.sub(lambda m: asset(m.group(1), m.group(2), lead=m.group(0).startswith("\\")), t)

    copied, queue = {}, []

    def asset(addon, rest, lead=True):
        repo = os.path.join(JMFSB, "addons", addon, "models", *rest.replace("/", "\\").split("\\"))
        if os.path.exists(repo):
            return "%sz\\jmfsb\\addons\\%s\\models\\%s" % ("\\" if lead else "", addon, rest)
        src = os.path.join(S, addon, "models", *rest.replace("/", "\\").split("\\"))
        rel = os.path.join(addon, *rest.replace("/", "\\").split("\\"))
        if os.path.exists(src) and rel.lower() not in copied:
            copied[rel.lower()] = (src, os.path.join(T, "models", rel))
            queue.append(rel.lower())
        return "%sz\\jmfsb\\addons\\%s\\models\\%s\\%s" % ("\\" if lead else "", target, addon, rest)

    # the classes, by table, the target's own name on each; a class defined twice (two addons restating one
    # base-game skeleton) once
    out = collections.OrderedDict()
    for table, lst in srcs.items():
        seen, parts = set(), []
        for a, t in lst:
            for tok, plain, body in blocks(t):
                if plain and (plain.lower() in real[a] or DROP.search(plain)):
                    continue
                key = (tok or "").lower() if not plain else "gvar:" + plain.lower()
                if tok is None:
                    parts.append(body)
                    continue
                if key in seen:
                    continue
                seen.add(key)
                parts.append(retext(body, a))
        out[table] = parts
    # the files those name, and the files those name in turn
    while queue:
        rel = queue.pop()
        src, dst = copied[rel]
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        lo = src.lower()
        if lo.endswith((".p3d",)):
            data = open(src, "rb").read()

            def sub(m):
                ext = (m.group(3) or b"").decode("latin1")
                rest = m.group(2).decode("latin1") + (ext or ".p3d")
                new_path = asset(m.group(1).decode("latin1"), rest, lead=False)
                return (new_path[:-4] if not ext else new_path).encode("latin1")
            open(dst, "wb").write(ASSET_B.sub(sub, data))
        elif lo.endswith((".rvmat", ".cfg", ".bisurf")):
            open(dst, "w", encoding="utf-8", newline="").write(
                ASSET.sub(lambda m: asset(m.group(1), m.group(2), lead=m.group(0).startswith("\\")), rd(src)))
        else:
            shutil.copy2(src, dst)
        # the model.cfg of a model's folder and those above it, up to the addon's models\
        if lo.endswith(".p3d"):
            d = os.path.dirname(src)
            top = os.path.join(S, rel.split(os.sep)[0], "models")
            while len(d) >= len(top):
                mc = os.path.join(d, "model.cfg")
                if os.path.exists(mc):
                    mrel = os.path.relpath(mc, os.path.join(S)).replace("models" + os.sep, "", 1)
                    if mrel.lower() not in copied:
                        copied[mrel.lower()] = (mc, os.path.join(T, "models", mrel))
                        queue.append(mrel.lower())
                d = os.path.dirname(d)
    # the addon's files
    hdr = ["// Generated by tools/aegis_port/port_to_addon.py from a seed import - re-run it rather than hand-edit.",
           "// Imported from the public Aegis sources (APL-SA); every class keeps its author."]
    # DROP inside the tables too: the gesture states and the moves that name a left-out class
    head = re.compile(r"(?m)^[ \t]*class ([\w(),]+)\s*(?::\s*([\w(),]+))?\s*(\{|;)")

    def strip(text):
        while True:
            m = next((m for m in head.finditer(text) if DROP.search(m.group(1))), None)
            if not m:
                break
            if m.group(3) == ";":
                e = text.find("\n", m.end()) + 1 or len(text)
            else:
                j, d = m.end(), 1
                while d:
                    d += {"{": 1, "}": -1}.get(text[j], 0)
                    j += 1
                e = text.find("\n", j) + 1 or len(text)
            text = text[:text.rfind("\n", 0, m.start()) + 1] + text[e:]
        return "".join(line for line in text.splitlines(True)
                       if not (DROP.search(line) and line.rstrip().endswith(";") and not line.lstrip().startswith("class ")))
    out = collections.OrderedDict((t2, [strip(b) for b in body]) for t2, body in out.items())
    # a parent reused from the repo's addon is declared at the top of its table
    for table, body in out.items():
        if table == "<root>":
            continue
        here = {m.group(1).lower() for b in body for m in [CLASS.match(b.lstrip("\n"))] if m}
        ext = []
        for b in body:
            m = CLASS.match(b.lstrip("\n"))
            if m and m.group(4) and m.group(4).startswith("EGVAR(") and m.group(4).lower() not in here and m.group(4) not in ext:
                ext.append(m.group(4))
        out[table] = ["    class %s;\n" % e for e in ext] + body
    # root declarations the addon's text does not use
    rest = "\n".join(b for t2, body in out.items() for b in body if not re.match(r"\s*class \w+;\s*$", b))
    root_kept = []
    for b in out.get("<root>", []):
        m = re.match(r"\s*class (\w+);\s*$", b)
        if m and not re.search(r"\b%s\b" % re.escape(m.group(1)), rest):
            continue
        root_kept.append(b)
    out["<root>"] = root_kept
    for table, fn in (("CfgVehicles", "CfgVehicles.hpp"), ("CfgWeapons", "CfgWeapons.hpp")):
        body = out.pop(table, [])
        # the arctic twins tools/camo/ru_kit_colours.py writes, inside the table (an empty file until it runs)
        extra = os.path.join(T, "arctic_" + fn)
        if not os.path.exists(extra):
            open(extra, "w", encoding="utf-8", newline="\n").write("// written by tools/camo/ru_kit_colours.py\n")
        open(os.path.join(T, fn), "w", encoding="utf-8", newline="\n").write(
            "\n".join(hdr + ["class %s {" % table] + [b.rstrip("\r\n") for b in body] + ['    #include "arctic_%s"' % fn, "};", ""]))
    root = out.pop("<root>", [])
    cfg_tables = ["\n".join(hdr)]
    for table, body in out.items():
        cfg_tables.append("class %s {\n%s\n};" % (table, "\n".join(b.rstrip("\r\n") for b in body)))
    open(os.path.join(T, "imported_config.hpp"), "w", encoding="utf-8", newline="\n").write("\n\n".join(cfg_tables) + "\n")
    open(os.path.join(T, "imported_root.hpp"), "w", encoding="utf-8", newline="\n").write(
        "\n".join(hdr + [b.rstrip("\r\n") for b in root] + [""]))
    units, weapons = write_config(T, target, new, S)
    localise(T)
    # the base-game skeletons the sandbox restated for classes that were reused rather than copied: what nothing uses
    sys.path.insert(0, os.path.join(JMFSB, "tools"))
    import cdlc_split
    cdlc_split.prune_unused()
    print("classes: %s" % {a: len(v) for a, v in new.items()})
    print("units %d, weapons %d" % (len(units), len(weapons)))
    print("assets copied: %d (%d MB)" % (len(copied), sum(os.path.getsize(s) for s, _d in copied.values()) // 2 ** 20))
    return new


def localise(T):
    """A reference to one of the five repo addons for a class the target addon itself defines -> GVAR.

    ref() writes EGVAR(<addon>,X) when the repo's addon had X at port time. Classes have moved since: uniform_ru
    defines its own AK-12s, Luchniks, chest rigs and tactical vest, but its soldiers still named them
    EGVAR(uniform,X) - jmfsb_uniform_X, a class nobody defines - so every soldier inheriting that kit spawned
    without it (found 2026-10-07, aligning Russia's vests). The class the target defines is the one meant.
    """
    files = [os.path.join(T, f) for f in os.listdir(T) if f.lower().endswith(".hpp")]
    defined = set()
    for p in files:
        defined |= {n.lower() for n in re.findall(r"class GVAR\((\w+)\)", rd(p))}
    pat = re.compile(r"\b(Q?)EGVAR\((%s),\s*(\w+)\)" % "|".join(FIVE))
    for p in files:
        t = rd(p)
        n = pat.sub(lambda m: "%sGVAR(%s)" % (m.group(1), m.group(3)) if m.group(3).lower() in defined else m.group(0), t)
        if n != t:
            open(p, "w", encoding="utf-8", newline="").write(n)


def _swap(t):
    for a, b in SWAP:
        t = t.replace(a, b)
    return t


if __name__ == "__main__":
    main(sys.argv[1], sys.argv[2])
    # 2040 PEER ARMOUR. This rewrites files tools/peer_vests.py edits; put its protection and vest swaps back.
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    import peer_vests
    peer_vests.main()
