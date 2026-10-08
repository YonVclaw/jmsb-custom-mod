"""Write what port.py planned: the classes, the declarations they need, the files, and the wiring.

Called by port.py; see its docstring for the ask and README.md beside it for the decisions.

THE PASSES
  names     every class that comes in gets its jmfsb name: the mod prefix off, GVAR on, and a
            number on the end only when that name is already taken in the same addon.
  ancestry  what each imported class inherits by name has to be visible in the addon's config,
            or HEMTT fails it (L-C04). HEMTT resolves a nested parent the way the engine does -
            the enclosing classes outward, each with what it inherits - but only through classes
            the config itself writes, so the base-game ancestor that holds the member is restated
            with a declaration of it: `class H_X: H_Y { class ItemInfo; };`. Restated with its
            real parent, in the spelling it is defined with (L-C05), declarations before the
            classes that use them, and only as deep as needed - the way addons/naval does it by
            hand.
  classes   every class is written from the parsed tree, value by value. Stringtable keys become
            their text, references to classes that came in become their jmfsb names, references to
            classes that did not are removed, crews become the base game's, and every path into
            the sources becomes a path into jmfsb.
  additions the base-game classes the sources add to - a magazine well that takes their
            magazines, a rail slot that takes their optics, the action that plays their reload -
            get the same additions, naming the imported classes.
  files     the models, materials, textures, sounds and animations those paths name, then what the
            models and materials name in turn, then every texture beside each model (the ask: all
            textures for any asset imported), copied under models/ with their own paths rewritten.
  wiring    each addon's config gets its includes, its CfgPatches lists and its requiredAddons.
"""
import collections
import io
import json
import math
import os
import re
import shutil
import struct
from decimal import Decimal

import source_config as S

HERE = os.path.dirname(os.path.abspath(__file__))
ADDONS = os.path.join(os.path.normpath(os.path.join(HERE, "..", "..")), "addons")
SRC = S.SRC
TARGETS = ["weapons", "vests", "headware", "uniform", "vehicle"]
ASSETS = "models"
STRIP = re.compile(r"(?i)^(?:aegis|atlas|opf)_")
INNER_STRIP = re.compile(r"(?i)(^|_)(?:aegis|atlas|opf)_")
MODEL_KEYS = {"model", "modeloptics", "uimodel", "modelspecial", "modelmagazine"}
ANY_EXTS = (".paa", ".rvmat", ".p3d", ".wss", ".ogg", ".wav", ".rtm", ".jpg")
CREW_KEYS = {"crew", "typicalcargo", "gunnertype", "drivertype", "commandertype"}
TRANSPORT_REF = {"transportweapons": "weapon", "transportmagazines": "magazine", "transportitems": "name",
                 "transportbackpacks": "backpack", "linkeditems": "item"}
G = ("cfggesturesmale", "states")
M = ("cfgmovesmalesdr", "states")
A = ("cfgmovesbasic", "actions")
W = ("cfgweapons",)
DROP = object()
SEEDS = []          # port.py --seeds: set by port.main
FULL = set()        # port.py --full: the full import's roots (lower names) - public, folded one per type
# Files a model names that the public sources no longer ship, and what the model is pointed at instead.
# Aegis withdrew its M4A1 M203 textures in January 2025 (74aca1a9) - not restored from git history -
# and Atlas's FAMAS GL models dress their launcher in them; the FAMAS family is in the factions'
# hands (user, 2026-10-01), so the launcher gets a plain dark finish rather than a missing texture.
WITHDRAWN = {
    rb"a3_aegis\weapons_f_aegis\rifles\m4a1\data\m203_co.paa": rb"#(argb,8,8,3)color(0.1,0.1,0.09,1,co)",
    rb"a3_aegis\weapons_f_aegis\rifles\m4a1\data\m203.rvmat": rb"a3\data_f\default.rvmat",
}
CREWS = {
    1: {"uav": "B_UAV_AI", "fighter": "B_Fighter_Pilot_F", "heli": "B_Helipilot_F", "pilot": "B_Pilot_F",
        "crew": "B_crew_F", "diver": "B_diver_F", "soldier": "B_Soldier_F"},
    0: {"uav": "O_UAV_AI", "fighter": "O_Fighter_Pilot_F", "heli": "O_helipilot_F", "pilot": "O_Pilot_F",
        "crew": "O_crew_F", "diver": "O_diver_F", "soldier": "O_Soldier_F"},
    2: {"uav": "I_UAV_AI", "fighter": "I_Fighter_Pilot_F", "heli": "I_helipilot_F", "pilot": "I_pilot_F",
        "crew": "I_crew_F", "diver": "I_diver_F", "soldier": "I_soldier_F"},
    3: {"uav": "C_UAV_AI_F", "fighter": "C_man_pilot_F", "heli": "C_man_pilot_F", "pilot": "C_man_pilot_F",
        "crew": "C_man_1", "diver": "C_man_1", "soldier": "C_man_1"},
}
MPATH = re.compile(rb"(?i)a3_(?:aegis|atlas|opf)\\[\w\\/ .\-]+?\.(?:paa|rvmat|p3d|tga|png|rtm|wss|ogg|jpg|bisurf)")
# A proxy in a model: the selection `proxy:a3_aegis\air_f_aegis\heli_attack_04\Main_Rotor_Blur_F.001`
# names a model without its extension, so MPATH never saw it - the rotors pointed into Aegis and
# their models were never copied.
PPROXY = re.compile(rb"(?i)(?<=proxy:)\\?a3_(?:aegis|atlas|opf)\\[\w\\/ \-]+?(?=\.\d{3}\x00)")
# A material names its textures by their source files; BI's packer writes .paa there, HEMTT does
# not, and the game cannot load a material whose texture is a .tga.
RVMAT_TEX = re.compile(r'(?i)(\btexture\s*=\s*"[^"#\r\n]+)\.(?:tga|png)(")')
TPATH = re.compile(r"(?i)\\?a3_(?:aegis|atlas|opf)\\[^\"';,{}\[\]\r\n]*")
TPATH_EXT = re.compile(r"(?i)\\?a3_(?:aegis|atlas|opf)\\[\w\\/ .\-]+?\.(?:paa|rvmat|p3d|tga|png|rtm|wss|ogg|wav|jpg|bisurf)")
# A Western Sahara class name (its weapons, magazines and factions end or start with lxWS). That
# DLC's configs are encrypted, so none of them is in the base-game cache - and none can be loaded.
LXWS_NAME = re.compile("(?i)(^|_)lxws(_|$)")
# A name with the mods' own prefix. OPF_ is left alone: the game names its OPFOR factions that way.
MOD_NAME = re.compile(r"(?i)^(?:aegis|atlas)_\w+$")
MOD_SCRIPT = re.compile(r"(?i)\b(?:aegis|atlas|opf)_(?:fnc_|rsc)")
# User, 2026-09-13: "all the factiosn you just imported, replace them with jmfsb_blue, jmfsb_red and
# jmfsb_green" - every imported vehicle and soldier, whatever faction the sources filed it under
# (theirs or the game's), by side; civilians go to the game's own Civilians. The three are defined
# in the vehicle addon, with the base game's side art (as tools/gen_us_factions.py uses it).
JMFSB_FACTIONS = {1: "jmfsb_blue", 0: "jmfsb_red", 2: "jmfsb_green", 3: "CIV_F"}
# What a camo suffix in a texture's file name means, for a paint added to a vehicle's appearance menu.
PAINT_WORDS = {"rukhk": "Russian Khaki", "chdkz": "ChDKZ", "paramilitary": "Paramilitary", "para": "Paramilitary",
               "hex": "Hex", "ghex": "Green Hex", "whex": "Woodland Hex", "grn": "Green", "blk": "Black",
               "khk": "Khaki", "snd": "Sand", "oli": "Olive", "tna": "Tropic", "wdl": "Woodland", "ard": "Arid",
               "uno": "UN", "un": "UN", "sfia": "SFIA", "aaf": "AAF"}
PAINT_PARTS = {"body", "body2", "turret", "ext", "hull", "co", "ca", "base", "tex", "data", "f"}
JMFSB_FACTION_DEFS = [
    ("jmfsb_blue", "JMSB Blue", 1, r"\A3\Data_F\cfgFactionClasses_BLU_ca.paa", r"\A3\Data_F\Flags\flag_NATO_CO.paa"),
    ("jmfsb_red", "JMSB Red", 0, r"\A3\Data_F\cfgFactionClasses_OPF_ca.paa", r"\A3\Data_F\Flags\flag_CSAT_CO.paa"),
    ("jmfsb_green", "JMSB Green", 2, r"\A3\Data_F\cfgFactionClasses_IND_ca.paa", r"\A3\Data_F\Flags\flag_AAF_CO.paa"),
]
# selections and inner class names: a mod prefix there names nothing outside the class
NOT_REF_KEYS = {"hiddenselections", "texturelist", "animationlist", "modes", "muzzles", "sounds", "selection"}
# A path into a creator DLC's data: nothing jmfsb loads can answer it.
CDLC_PATH = re.compile(r"(?i)^\\?(?:lxws|rf|ef|vn|gm|csla|ww2|spe)\\")
# HEMTT's parser refuses a no-break space, and the stringtables write "5.7 mm" with one.
ODD_SPACES = re.compile("[\u00a0\u2007\u2009\u202f]")


def rd(p):
    return io.open(p, encoding="utf-8", errors="replace", newline="").read()


def wr(p, t):
    os.makedirs(os.path.dirname(p), exist_ok=True)
    io.open(p, "w", encoding="utf-8", newline="\n").write(t)


# The sources write some scopes as words their lowercase macros never matched (`scope = Public;`
# beside `#define public 2`). Copied as a quoted "Private", the game cannot read the number and logs
# "Error in expression <Private>" at every start.
SCOPE_WORDS = {"private": 0, "protected": 1, "public": 2}
SCOPE_KEYS = {"scope", "scopecurator", "scopearsenal"}


def num(v):
    if isinstance(v, (int, float)):
        return v
    if isinstance(v, tuple):
        try:
            return int(v[1]) if re.match(r"^-?\d+$", v[1].strip()) else float(v[1])
        except ValueError:
            return SCOPE_WORDS.get(v[1].strip().lower())
    return None


def same_file(a, b):
    if os.path.getsize(a) != os.path.getsize(b):
        return False
    with open(a, "rb") as fa, open(b, "rb") as fb:
        return fa.read() == fb.read()


def kind_folder(pbo):
    """air_f_aegis -> air, characters_f_atlas -> characters: the source addon, minus the mod."""
    return re.sub(r"(?i)_f(?:_(?:aegis|atlas|opf))?(?:_\w+)?$", "", pbo).lower() or pbo.lower()


# HEMTT's reading of a quoted value as math (hemtt_common::math::eval, 1.21.0), ported token for
# token. Its L-C12 flags every quoted string this evaluates - under any key but the four it
# ignores, and only when the string holds + - * or / unless the key is one it forces - and says
# the quotes could come off. The port writes the number instead, as HEMTT would store it.
MATH_FUNCS = {"acos": math.acos, "asin": math.asin, "atan": math.atan, "atg": math.atan, "cos": math.cos,
              "deg": math.degrees, "rad": math.radians, "sin": math.sin, "tan": math.tan, "tg": math.tan}
MATH_OPS = {"+": (1, "L"), "-": (1, "L"), "*": (2, "L"), "/": (2, "L"), "^": (3, "R"), "%": (2, "L")}
MATH_IGNORE = {"text", "name", "displayname", "icontext"}
MATH_FORCED = {"initspeed", "ambient", "diffuse", "forceddiffuse", "emmisive", "specular", "specularpower"}
# Words a player reads stay words, whatever HEMTT would make of them: "7.62-51" is a caliber.
TEXT_KEY = re.compile(r"^(?:display|description|tooltip|author|text|name|lib|readme|title|hint|short)")
THIS_CALL = re.compile(r"(?<!\w)_this call ")


def hemtt_math(expr):
    """The value HEMTT's evaluator gives expr, or None where it gives none."""
    digits = "0123456789."
    tokens, num, ident = [], [], []

    def end_num():
        tokens.append(("n", float("".join(num))))
        num.clear()

    def end_ident():
        word = "".join(ident)
        ident.clear()
        if word == "pi":
            tokens.append(("n", math.pi))
        elif word in MATH_FUNCS:
            tokens.append(("f", word))
        else:
            raise ValueError(word)
    try:
        for i, c in enumerate(expr):
            if c in digits:
                if ident:
                    end_ident()
                num.append(c)
            elif "a" <= c <= "z" or "A" <= c <= "Z" or c == "_":
                if num:
                    end_num()
                ident.append(c)
            else:
                if num:
                    end_num()
                if ident:
                    end_ident()
                if c in "+*/^%":
                    tokens.append(("o", c))
                elif c == "(":
                    tokens.append(("(", None))
                elif c == ")":
                    tokens.append((")", None))
                elif c == "-":
                    if not tokens or tokens[-1][0] in ("o", "(", "f"):
                        nxt = expr[i + 1] if i + 1 < len(expr) else ""
                        if nxt and nxt in digits:
                            num.append(c)
                        else:
                            tokens.append(("u", None))
                    else:
                        tokens.append(("o", c))
                elif c != " ":
                    return None
        if num:
            end_num()
        if ident:
            end_ident()
    except ValueError:
        return None
    out, stack = [], []
    for tok in tokens:
        kind = tok[0]
        if kind == "n":
            out.append(tok)
        elif kind == "o":
            prec, assoc = MATH_OPS[tok[1]]
            while stack and stack[-1][0] == "o":
                top = MATH_OPS[stack[-1][1]][0]
                if (assoc == "L" and prec <= top) or (assoc == "R" and prec < top):
                    out.append(stack.pop())
                    continue
                break
            stack.append(tok)
        elif kind in ("f", "u", "("):
            stack.append(tok)
        else:
            hit = False
            while stack:
                top = stack.pop()
                if top[0] == "(":
                    hit = True
                    break
                out.append(top)
            if not hit:
                return None
            if stack and stack[-1][0] == "f":
                out.append(stack.pop())
    while stack:
        out.append(stack.pop())
    vals = []
    try:
        for kind, v in out:
            if kind == "n":
                vals.append(v)
            elif kind == "o":
                if len(vals) < 2:
                    return None
                r, l = vals.pop(), vals.pop()
                vals.append({"+": lambda: l + r, "-": lambda: l - r, "*": lambda: l * r, "/": lambda: l / r,
                             "^": lambda: math.pow(l, r), "%": lambda: math.fmod(l, r)}[v]())
            elif kind == "f":
                if not vals:
                    return None
                vals.append(MATH_FUNCS[v](vals.pop()))
            elif kind == "u":
                if not vals:
                    return None
                vals.append(-vals.pop())
            else:
                return None
    except (ZeroDivisionError, OverflowError, ValueError):
        return None                  # HEMTT gets inf or NaN there: nothing worth writing
    return vals[-1] if vals else None


def hemtt_number(v):
    """v as HEMTT stores it: a whole number as an integer, anything else as a 32-bit float, written
    in the fewest digits that read back as the same float."""
    if not math.isfinite(v) or abs(v) >= 2 ** 63:
        return None
    if v == int(v):
        return str(int(v))
    try:
        f = struct.unpack("f", struct.pack("f", v))[0]
    except OverflowError:
        return None
    for p in range(1, 10):
        s = "%.*g" % (p, f)
        if struct.unpack("f", struct.pack("f", float(s)))[0] == f:
            break
    return format(Decimal(s), "f")


MODELCFG_TABLES = ("cfgskeletons", "cfgmodels")
CFG_CLASS = re.compile(r"\s*class\s+(\w+)\s*(?::\s*(\w+))?\s*([{;])")


def cfg_items(t):
    """The items of a config body, in order: (kind, name, text), kind class, decl or other."""
    items, i, n = [], 0, len(t)
    while i < n:
        m = CFG_CLASS.match(t, i)
        if m:
            if m.group(3) == ";":
                items.append(("decl", m.group(1), t[i:m.end()].strip()))
                i = m.end()
                continue
            depth, j = 1, m.end()
            while j < n and depth:
                if t[j] == '"':
                    k = t.find('"', j + 1)
                    j = n if k < 0 else k + 1
                    continue
                depth += {"{": 1, "}": -1}.get(t[j], 0)
                j += 1
            k = j
            while k < n and t[k] in " \t\r\n":
                k += 1
            if k < n and t[k] == ";":
                j = k + 1
            items.append(("class", m.group(1), t[i:j].strip()))
            i = j
            continue
        j = t.find("\n", i)
        j = n if j < 0 else j + 1
        if t[i:j].strip():
            items.append(("other", None, t[i:j].rstrip()))
        i = j
    return items


def merge_model_cfgs(sources, models, log):
    """One model.cfg with every skeleton and model the sources [(mod, text)] define, first come
    first kept. A shared class two mods write differently (Aegis's ArmaMan is not Atlas's) is kept
    once per mod: the later mod's copy, and every use of it in that mod's classes, gets the mod's
    name on the end. A model class is named after its .p3d and is never renamed."""
    norm = lambda s: re.sub(r"\s+", "", s).lower()
    inner = lambda s: s[s.index("{") + 1:s.rindex("}")]
    pre, tables, kept = [], collections.OrderedDict(), {}
    for mod, text in sources:
        t = S.strip_comments(text)
        clash = set()
        for kind, name, txt in cfg_items(t):
            if kind == "class" and name.lower() in MODELCFG_TABLES:
                for k2, n2, t2 in cfg_items(inner(txt)):
                    key = (name.lower(), n2.lower() if n2 else None)
                    if k2 == "class" and key in kept and norm(kept[key]) != norm(t2):
                        if n2.lower() in models:
                            log["model.cfg: a model two mods define differently, the first kept"].append("%s (%s)" % (n2, mod))
                        else:
                            clash.add(n2)
        for c in sorted(clash):
            t = re.sub(r"\b%s\b" % re.escape(c), "%s_%s" % (c, mod), t)
            log["model.cfg: a shared class two mods define differently, kept once per mod"].append("%s_%s" % (c, mod))
        top = cfg_items(t)
        chunk = "\n".join(x[2] for x in top if x[0] == "other")
        if chunk.strip() and norm(chunk) not in {norm(p) for p in pre}:
            pre.append(chunk)
        for kind, name, txt in top:
            if kind == "other":
                continue
            if kind == "decl" or name.lower() not in MODELCFG_TABLES:
                key = ("", name.lower())
                if key not in kept:
                    kept[key] = txt
                    tables.setdefault(("", name.lower()), [txt])
                continue
            table = tables.setdefault(name.lower(), [name])
            for k2, n2, t2 in cfg_items(inner(txt)):
                if k2 == "other":
                    continue
                key = (name.lower(), n2.lower())
                if key not in kept:
                    kept[key] = t2
                    table.append(t2)
    out = list(pre)
    for key, body in tables.items():
        if isinstance(key, tuple):
            out.append(body[0])
        else:
            out.append("class %s\n{\n%s\n};" % (body[0], "\n".join("\t" + b.replace("\n", "\n\t") for b in body[1:])))
    return "\n".join(out) + "\n"


def load_strings():
    out = {}

    def unesc(s):
        return (s.replace("&lt;", "<").replace("&gt;", ">").replace("&quot;", '"')
                 .replace("&apos;", "'").replace("&amp;", "&"))
    for mod in S.MODS:
        base = os.path.join(SRC, mod)
        for d in os.listdir(base):
            p = os.path.join(base, d, "stringtable.xml")
            if d.lower().startswith("language_f") and os.path.exists(p):
                # not well-formed XML (a mismatched tag half-way down), so a tolerant scan
                for m in re.finditer(r'<Key\s+ID="([^"]+)"\s*>(.*?)</Key>', rd(p), re.S):
                    e = re.search(r"<Original>(.*?)</Original>", m.group(2), re.S) or \
                        re.search(r"<English>(.*?)</English>", m.group(2), re.S)
                    if e:
                        out.setdefault(m.group(1).lower(), unesc(e.group(1).strip()))
    for k, v in json.load(io.open(os.path.join(HERE, "vanilla_strings.json"), encoding="utf-8")).items():
        out.setdefault(k.lower(), v)
    return out


def own_files(addon):
    base = os.path.join(ADDONS, addon)
    for r, dirs, fs in os.walk(base):
        dirs[:] = [d for d in dirs if d != ASSETS]
        for f in fs:
            if f.lower().endswith((".hpp", ".cpp")) and not f.startswith("imported_"):
                yield os.path.join(r, f)


CLASS_TOK = re.compile(r'"(?:[^"\n]|"")*"|\bclass\s+(\w+)\s*(?::\s*[\w(),]+\s*)?(\{|;)|\{|\}')


def own_classes(addon):
    """What the addon's own files write, per table (lower name, "" for the config root):
    "def" the classes given a body, "decl" the bare declarations. A fragment - a file that opens
    no Cfg block, like acp_full_holder_externs.hpp, included inside CfgVehicles - lands under "*",
    because it counts wherever it is included."""
    out = collections.defaultdict(lambda: {"def": set(), "decl": set()})
    for path in own_files(addon):
        t = S.strip_comments(rd(path))
        block_file = os.path.basename(path).lower() == "config.cpp" or re.search(r"(?m)^\s*class\s+Cfg\w+\s*(:\s*\w+\s*)?\{", t)
        stack = []
        for m in CLASS_TOK.finditer(t):
            tok = m.group(0)
            if tok.startswith('"'):
                continue
            if m.group(1):
                lo = m.group(1).lower()
                kind = "def" if m.group(2) == "{" else "decl"
                if not stack:
                    if not (block_file and lo.startswith("cfg")):
                        out["" if block_file else "*"][kind].add(lo)
                elif len(stack) == 1 and stack[0]:
                    out[stack[0].lower() if block_file else "*"][kind].add(lo)
                if m.group(2) == "{":
                    stack.append(m.group(1))
            elif tok == "{":
                stack.append(None)
            elif tok == "}" and stack:
                stack.pop()
    return out


class Ctx:
    __slots__ = ("addon", "ns", "name", "kind", "side", "hide")

    def __init__(self, addon, ns, name, kind="dep", side=None, hide=False):
        self.addon, self.ns, self.name, self.kind, self.side, self.hide = addon, ns, name, kind, side, hide


def s_has(node, rp):
    n = node
    for seg in rp:
        if n is None:
            return False
        n = n.kids.get(seg.lower())
    return n is not None


def v_has(node, rp):
    n = node
    for seg in rp:
        if n is None:
            return False
        n = n.c.get(seg.lower())
    return n is not None


def parents_in(node):
    out = set()
    for kid in node.kids.values():
        if kid.parent:
            out.add(kid.parent.lower())
        if not kid.decl:
            out |= parents_in(kid)
    return out


def overlay(base, top):
    """A nested class as the sources' edit of a base-game ancestor wrote it, with the child's own
    changes laid over it - for a child whose `class X: X` has nothing in the game to inherit."""
    out = S.C(top.name)
    out.decl = False
    out.parent = base.parent if base.parent and base.parent.lower() != base.name.lower() else ""
    out.props = dict(base.props)
    out.props.update(top.props)
    out.kids = dict(base.kids)
    for k, v in top.kids.items():
        if k in out.kids and not v.decl and not out.kids[k].decl:
            out.kids[k] = overlay(out.kids[k], v)
        elif k not in out.kids or not v.decl:
            out.kids[k] = v
    return out


def topo(entries):
    """(key, parent key, lines) - parents first, otherwise as given."""
    keys = {k for k, _, _ in entries}
    done, out = set(), []
    pending = list(entries)
    while pending:
        progress = False
        rest = []
        for e in pending:
            if e[1] is None or e[1] not in keys or e[1] in done or e[1] == e[0]:
                out.append(e)
                done.add(e[0])
                progress = True
            else:
                rest.append(e)
        if not progress:
            out += rest
            break
        pending = rest
    return [l for _, _, lines in out for l in lines]


class Emitter:
    def __init__(self, w, p):
        self.w, self.p = w, p
        self.strings = load_strings()
        self.names = {}                                   # (ns, lower) -> (addon or None, jmfsb name)
        self.by_source = {}                               # lower source name -> (ns, lower)
        self.asset_owner = dict(p.assets)                 # real -> addon
        self.asset_path = {}                              # real -> game path, no leading backslash
        self.path_real = {}                               # lower game path -> the real file written there
        self.modelcfg = set()                             # (real, owner)
        self.renamed = []
        self.collapsed = {}                               # (ns, lower) of a vehicle folded into its type -> the class kept
        self.own = {a: own_classes(a) for a in TARGETS}
        # A name jmfsb's own files already spell. HEMTT matches a parent's case against any class of
        # that name in the addon, so the game's `default` cursor meets XtdGear's `Default`.
        self.own_spelling = {}
        for a in TARGETS:
            for path in own_files(a):
                for m in re.finditer(r"\bclass\s+(\w+)", S.strip_comments(rd(path))):
                    self.own_spelling.setdefault(m.group(1).lower(), m.group(1))
        self.reset()
        self.name_all()

    def reset(self):
        self.needs = collections.defaultdict(dict)        # (addon, ns) -> lower -> name, for `class X;`
        self.stubs = collections.defaultdict(dict)        # (addon, ns) -> lower -> {name, kids, props}
        self.inject = collections.defaultdict(dict)       # (ns, lower top) -> lower -> name, declared in its body
        self.flatten = collections.defaultdict(dict)      # (ns, lower top) -> rp tuple -> source node
        self.orphan = collections.defaultdict(set)        # (ns, lower top) -> rp tuples written without a parent
        self.keep = collections.defaultdict(set)          # (ns, lower top) -> rp tuples of declarations a child relies on
        self.sibling = collections.defaultdict(lambda: collections.defaultdict(dict))  # (ns, lower top) -> relpath -> lower -> name
        self.blocks = collections.defaultdict(list)       # (addon, ns) -> [(key, parent key, lines)]
        self.takeover = collections.defaultdict(set)      # (addon, table) -> bare declarations moved into the import
        self.cross = collections.defaultdict(set)
        self.cba = collections.defaultdict(bool)
        self.log = collections.defaultdict(list)
        self.crews = collections.Counter()

    def own_sets(self, addon, ns):
        o = self.own[addon]
        frag = o["*"]["def"] | o["*"]["decl"]
        if len(ns) > 1:
            return set(), set(), set()
        t = o[ns[0]] if ns else o[""]
        return t["def"], t["decl"], frag

    def owned(self, addon, ns):
        """Written by the addon itself - never restated, never declared again."""
        d, _dc, f = self.own_sets(addon, ns)
        return d | f

    def declared(self, addon, ns):
        """Bare declarations in the addon's own block: the import's declarations take them over."""
        return self.own_sets(addon, ns)[1]

    def vname(self, ns, name):
        """A base-game class in the spelling it is defined with: HEMTT holds a parent to that case."""
        if name.lower() in self.own_spelling:
            return self.own_spelling[name.lower()]
        v = self.w.vnode(ns, name)
        return v.n if v is not None else name

    # ------------------------------------------------------------ names
    def name_all(self):
        own_defs = {}
        for a in TARGETS:
            s = set()
            for path in own_files(a):
                s |= {m.lower() for m in re.findall(r"class\s+GVAR\((\w+)\)\s*[:{]", rd(path))}
            own_defs[a] = s
        taken = collections.defaultdict(set)
        public_first = sorted(self.p.items.items(),
                              key=lambda kv: num(self.w.value(kv[1]["ns"], kv[1]["name"], "scope")) != 2)
        for key, it in public_first:
            ns, name, addon = it["ns"], it["name"], it["addon"]
            self.by_source.setdefault(name.lower(), key)
            if ns == ("cfgnonaivehicles",):
                self.names[key] = (None, name)            # a proxy's class name is its model's file name
                continue
            base = STRIP.sub("", name) or name
            cand, i = base, 2
            while cand.lower() in taken[(addon, ns)] or cand.lower() in own_defs[addon]:
                cand = "%s_%d" % (base, i)
                i += 1
            self.names[key] = (addon, cand)
            taken[(addon, ns)].add(cand.lower())
            if cand != base:
                self.renamed.append("%s -> %s" % (name, cand))

    def ref(self, ns, name, from_addon, quoted):
        addon, n = self.names[(ns, name.lower())]
        if addon is None:
            return '"%s"' % n if quoted else n
        if addon == from_addon:
            return ("QGVAR(%s)" if quoted else "GVAR(%s)") % n
        return ("QEGVAR(%s,%s)" if quoted else "EGVAR(%s,%s)") % (addon, n)

    # ------------------------------------------------------------ values
    @staticmethod
    def quote(s):
        return '"%s"' % ODD_SPACES.sub(" ", s).replace('"', '""')

    def literal(self, s, key, escape):
        """A string value the way HEMTT's help lints want it written. `_this call f` is `call f`
        when every _this in it is one (L-C13): call hands on the caller's _this either way. Quoted
        math HEMTT can work out is the number it works out to (L-C12)."""
        n = len(THIS_CALL.findall(s))
        if n and n == s.count("_this"):
            s = THIS_CALL.sub("call ", s)
        k = (key or "").lower()
        if k not in MATH_IGNORE and not TEXT_KEY.match(k) and (k in MATH_FORCED or any(c in s for c in "+-*/")):
            v = hemtt_math(s)
            if v is not None:
                written = hemtt_number(v)
                if written is not None:
                    return written
        return self.quote(s) if escape else '"%s"' % s

    def conv(self, v, ctx, key):
        if isinstance(v, list):
            out = []
            for x in v:
                c = self.conv(x, ctx, key)
                if c is not DROP:
                    out.append(c)
            return "{" + ", ".join(out) + "}"
        kind, t = v
        if key in SCOPE_KEYS and t.strip().lower() in SCOPE_WORDS:
            return str(SCOPE_WORDS[t.strip().lower()])
        if kind == "n":
            return t
        if kind == "b" and t.startswith("$"):
            # an author field can be two keys run together by a macro: $STR_A_POLPOX$STR_A_Toadie2k
            parts = []
            for key_ in [x for x in t.split("$") if x.strip()]:
                s = self.strings.get(key_.strip().lower())
                if s is None:
                    k = key_.strip()
                    if k.upper().startswith("STR_LXWS_FACTION_"):
                        # Western Sahara's stringtable is not loaded; its faction keys name the faction
                        s = k[len("STR_LXWS_FACTION_"):].replace("_", " ")
                    elif key == "author" and k.upper().startswith("STR_LXWS"):
                        return DROP                   # the author the parent class carries stands
                    else:
                        self.log["kept as its key: stringtable entry not found"].append("$" + key_)
                        s = k
                parts.append(s)
            return self.quote(", ".join(parts))
        if kind == "b" and '"' in t:
            self.log["kept as written: an expression"].append("%s %s = %s" % (ctx.name, key, t))
            return t
        r = self.class_value(ctx, key, t.strip())
        if r is not None:
            return r
        if kind == "s" and MOD_SCRIPT.search(t):
            self.log["removed: a script that calls the mods' functions or interface"].append("%s %s = %s" % (ctx.name, key, t[:90]))
            return DROP
        if kind == "s":
            return self.literal(ODD_SPACES.sub(" ", self.rewrite_string(t, key, ctx)), key, False)
        return self.literal(self.rewrite_string(t, key, ctx), key, True)

    def class_value(self, ctx, key, tok):
        if not tok or not re.match(r"^\w+$", tok):
            return None
        if key in CREW_KEYS:
            if self.w.vnode(("cfgvehicles",), tok) is None:
                return '"%s"' % self.crew_for(tok, ctx)
            return None
        if key == "faction" and ctx.ns == ("cfgvehicles",):
            f = self.faction_for(ctx)
            if f is not None:
                return '"%s"' % f
        tns = self.p.lookup(key, tok)
        if tns is None:
            # Not a class the sources define - but a name with the mods' prefix is still theirs: a
            # sight overlay (Aegis_RscOptics_Punisher), a base weapon or uniform that was never
            # written. Without the mods it points at nothing, so it goes.
            if SEEDS and LXWS_NAME.search(tok) and not MOD_NAME.match(tok):
                # --seeds: Western Sahara's own classes (its desert uniforms, backpacks, pointers) stay
                # named - jmfsb's factions already build on that DLC being loaded
                return None
            if (MOD_NAME.match(tok) or LXWS_NAME.search(tok)) and key not in NOT_REF_KEYS and self.w.vnode(("cfgweapons",), tok) is None                     and self.w.vnode(("cfgvehicles",), tok) is None:
                self.log["removed: names a mod class or interface that did not come in"].append("%s %s = %s" % (ctx.name, key, tok))
                return DROP
            return None
        if (tns, tok.lower()) in self.names:
            return self.ref(tns, tok, ctx.addon, True)
        twin = self.p.twin.get((tns, tok.lower()))
        if twin is not None and twin[0] == "own":
            # jmfsb's own class of the same name, which the imported copy gave way to
            return ("QGVAR(%s)" % twin[2]) if twin[1] == ctx.addon else ("QEGVAR(%s,%s)" % (twin[1], twin[2]))
        if twin is not None and twin in self.names:
            return self.ref(twin[0], twin[1], ctx.addon, True)      # a dropped duplicate: the copy kept
        self.log["removed: a reference to a class that did not come in"].append("%s %s = %s" % (ctx.name, key, tok))
        return DROP

    def crew_for(self, tok, ctx):
        lo = tok.lower()
        m = re.match(r"(?i)^(?:aegis_|atlas_|opf_)?([boic])_", tok)
        side = {"b": 1, "o": 0, "i": 2, "c": 3}[m.group(1).lower()] if m else ctx.side
        if side not in CREWS:
            side = 1
        role = ("uav" if "uav_ai" in lo else "fighter" if "fighter_pilot" in lo else
                "heli" if ("helipilot" in lo or "heli_pilot" in lo) else "pilot" if "pilot" in lo else
                "crew" if "crew" in lo else "diver" if "diver" in lo else "soldier")
        out = CREWS[side][role]
        if self.w.vnode(("cfgvehicles",), out) is None:
            out = CREWS[side]["soldier"]
        self.crews[(tok, out)] += 1
        return out

    def faction_for(self, ctx):
        f = JMFSB_FACTIONS.get(ctx.side)
        if f is None:
            self.log["faction: side not readable, faction left as the sources had it"].append(ctx.name)
        return f

    def rewrite_string(self, s, key, ctx):
        st = s.strip()
        if TPATH.fullmatch(st):
            real = self.w.resolve_src(st, (".p3d",) if key in MODEL_KEYS else ANY_EXTS)
            if real is None:
                self.log["emptied: a path to a file the public sources do not have"].append("%s %s = %s" % (ctx.name, key, st))
                return ""
            new = self.target(real, ctx.addon)
            if not os.path.splitext(st)[1]:
                new = os.path.splitext(new)[0]           # the source left the extension off
            if key == "mat":
                # Damage/Wounds materials are written the way the game writes them, with no leading
                # backslash: "\z\jmfsb\...rvmat" in mat[] logs "Cannot load material file" for a file
                # the model itself loads fine by the same path without it.
                return new
            return "\\" + new
        if CDLC_PATH.match(st) and not (SEEDS and st.lstrip("\\").lower().startswith("lxws\\")):
            self.log["emptied: a path into a creator DLC"].append("%s %s = %s" % (ctx.name, key, st))
            return ""
        if "a3_" not in s.lower():
            return s

        def sub(m):
            path = m.group(0)
            real = self.w.resolve_src(path, ())
            if real is None:
                self.log["kept: a path inside a script that the public sources do not have"].append("%s: %s" % (ctx.name, path))
                return path
            return ("\\" if path.startswith("\\") else "") + self.target(real, ctx.addon)
        return TPATH_EXT.sub(sub, s)

    # ------------------------------------------------------------ files
    def owner_for(self, real, default):
        parts = os.path.relpath(real, SRC).replace("\\", "/").lower().split("/")
        if len(parts) > 3 and parts[1].startswith("characters_f"):
            sub = {"uniforms": "uniform", "vests": "vests", "headgear": "headware"}.get(parts[2])
            if sub:
                return sub
        if len(parts) > 2 and parts[1].startswith(("weapons_f", "anims_f")):
            return "weapons"
        return default

    def target(self, real, default_owner):
        got = self.asset_path.get(real)
        if got:
            return got
        owner = self.owner_for(real, self.asset_owner.get(real, default_owner))
        self.asset_owner[real] = owner
        _mod, pbo, rest = os.path.relpath(real, SRC).replace("\\", "/").split("/", 2)
        kind = kind_folder(pbo)
        for i in range(1, 50):
            k = kind if i == 1 else "%s%d" % (kind, i)
            path = "z\\jmfsb\\addons\\%s\\%s\\%s\\%s" % (owner, ASSETS, k, rest.replace("/", "\\"))
            other = self.path_real.get(path.lower())
            if other is None:
                self.path_real[path.lower()] = real
                break
            if other == real or same_file(other, real):
                break
        self.asset_path[real] = path
        return path

    def own_asset_refs(self):
        """Files jmfsb's own configs already point at under models/ - headware's FAST-MT paints use
        Aegis's icons, repointed there on the first run. Nothing imported may name them any more,
        so they are asked for here, or a re-run would leave those paths pointing at nothing."""
        pat = re.compile(r"(?i)z\\jmfsb\\addons\\(\w+)\\" + ASSETS + r"\\([a-z]+)\d*\\([^\"';,}\r\n]+)")
        for addon in TARGETS:
            for path in own_files(addon):
                for m in pat.finditer(rd(path)):
                    kind, rest = m.group(2).lower(), m.group(3).strip()
                    for mod in S.MODS:
                        cand = "%s\\%s_f_%s\\%s" % (mod, kind, mod.split("_", 1)[1].lower(), rest)
                        real = self.w.resolve_src(cand, ())
                        if real is not None:
                            self.asset_owner.setdefault(real, m.group(1).lower())
                            break
                    else:
                        self.log["an own file names a models/ path with no source file"].append(
                            "%s: %s" % (os.path.basename(path), m.group(0)))

    def trace(self):
        """What the models and materials name, every texture beside each model, and model.cfg."""
        queue = list(self.asset_owner)
        seen = set()
        while queue:
            real = queue.pop()
            if real in seen:
                continue
            seen.add(real)
            owner = self.owner_for(real, self.asset_owner[real])
            self.asset_owner[real] = owner
            lo = real.lower()
            if lo.endswith((".p3d", ".rvmat")):
                with open(real, "rb") as fh:
                    data = fh.read()
                named = set()
                for m in MPATH.finditer(data):
                    ref = m.group(0).decode("latin1")
                    r2 = self.w.resolve_src(ref, ())
                    if r2 is None:
                        # a model names its texture once per face: report each file once per model
                        if ref.lower() not in named:
                            named.add(ref.lower())
                            self.log["a model or material names a file the public sources do not have"].append(
                                "%s: %s" % (os.path.relpath(real, SRC), ref))
                        continue
                    if r2 not in self.asset_owner:
                        self.asset_owner[r2] = owner
                        queue.append(r2)
                for m in (PPROXY.finditer(data) if lo.endswith(".p3d") else ()):
                    ref = m.group(0).decode("latin1")
                    r2 = self.w.resolve_src(ref + ".p3d", ())
                    if r2 is None:
                        if ref.lower() not in named:
                            named.add(ref.lower())
                            self.log["a model's proxy names a model the public sources do not have"].append(
                                "%s: %s" % (os.path.relpath(real, SRC), ref))
                        continue
                    if r2 not in self.asset_owner:
                        self.asset_owner[r2] = owner
                        queue.append(r2)
            if lo.endswith(".p3d"):
                d = os.path.dirname(real)
                if len(os.path.relpath(d, SRC).split(os.sep)) >= 3:
                    for r, _ds, fs in os.walk(d):
                        for f in fs:
                            if f.lower().endswith((".paa", ".rvmat")):
                                r2 = os.path.join(r, f)
                                if r2 not in self.asset_owner:
                                    self.asset_owner[r2] = owner
                                    queue.append(r2)
                cur = d
                while len(os.path.relpath(cur, SRC).split(os.sep)) >= 2:
                    mc = os.path.join(cur, "model.cfg")
                    if os.path.exists(mc):
                        self.modelcfg.add((mc, owner))
                    cur = os.path.dirname(cur)

    def rewrite_bytes(self, data, owner):
        for gone, stand_in in WITHDRAWN.items():
            data = re.sub(re.escape(gone), lambda _m, s=stand_in: s, data, flags=re.I)
        def sub(m):
            s = m.group(0).decode("latin1")
            r2 = self.w.resolve_src(s, ())
            if r2 is None:
                return m.group(0)
            new = self.target(r2, owner)
            return (os.path.splitext(new)[0] + os.path.splitext(s)[1]).encode("latin1")

        def proxy(m):
            s = m.group(0).decode("latin1")
            r2 = self.w.resolve_src(s + ".p3d", ())
            if r2 is None:
                return m.group(0)
            return (("\\" if s.startswith("\\") else "") + os.path.splitext(self.target(r2, owner))[0]).encode("latin1")
        return PPROXY.sub(proxy, MPATH.sub(sub, data))

    def rewrite_text_file(self, t, owner):
        def sub(m):
            s = m.group(0)
            r2 = self.w.resolve_src(s, ())
            if r2 is None:
                return s
            new = self.target(r2, owner)
            return ("\\" if s.startswith("\\") else "") + os.path.splitext(new)[0] + os.path.splitext(s)[1]

        def gone_include(m):
            # Atlas's FAMAS GL model.cfg includes Aegis's M4A1 m203anim.inc, withdrawn with the M203
            # textures (see WITHDRAWN): the launcher keeps its model and loses only those animations
            if self.w.resolve_src(m.group(2), ()) is not None:
                return m.group(0)
            return "%s// withdrawn from the public sources: %s" % (m.group(1), m.group(2))
        t = re.sub(r'(?im)^([ \t]*)#include\s+"(\\?a3_(?:aegis|atlas|opf)\\[^"]+)"', gone_include, t)
        return TPATH_EXT.sub(sub, t)

    # ------------------------------------------------------------ ancestry
    def need_decl(self, addon, ns, name):
        name = self.vname(ns, name)
        self.needs[(addon, ns)].setdefault(name.lower(), name)
        if name.lower().startswith(("asdg_", "cba_")):
            self.cba[addon] = True

    def expose_ext(self, addon, ns, cls, rp):
        """Restate base-game class cls in this addon, declaring the nested path rp inside it. The
        nested names keep the spelling of the imported class that asked, since that class's
        `class Turrets: Turrets` is what HEMTT compares them with."""
        cls = self.vname(ns, cls)
        st = self.stubs[(addon, ns)].setdefault(cls.lower(), {"name": cls, "kids": {}, "props": []})
        node = st
        for seg in rp:
            node = node["kids"].setdefault(seg.lower(), {"name": seg, "kids": {}, "props": []})
        if cls.lower().startswith(("asdg_", "cba_")):
            self.cba[addon] = True
        return node

    def v_lineage_has(self, ns, cls, path):
        for cns, c in self.w.ancestry_ns(ns, cls)[0]:
            if v_has(self.w.vnode(cns, c), path):
                return True
        return False

    def expose_at(self, addon, ns, cls, rp, via=None, top=None):
        """Declare rp on the nearest base-game class. When the addon's own files define that class,
        it cannot be restated (L-C03), so the declaration goes into the imported class just below
        it instead - an inherited member declared in the child is the same member."""
        if cls.lower() in self.owned(addon, ns):
            if via is not None and len(rp) == 1:
                self.inject[via][rp[0].lower()] = rp[0]
                return
            self.log["unresolved: the addon defines this class itself, so it is not restated"].append(
                "%s: %s / %s" % (top, cls, "/".join(rp)))
            return
        self.expose_ext(addon, ns, cls, rp)

    def ported_has(self, ns, cls, path):
        """Whether an imported class's own body carries path. When the last step is only a
        declaration (`class WeaponSlotsInfo;`), a child relies on it: body() keeps it."""
        n = self.w.snode(ns, cls)
        for seg in path:
            if n is None:
                return False
            n = n.kids.get(seg.lower())
        if n is None:
            return False
        if n.decl:
            self.keep[(ns, cls.lower())].add(tuple(s.lower() for s in path))
        return True

    def found_in_lineage(self, addon, ns, top, rp):
        """`class X: X` at rp inside top: X from what top inherits at that depth, or failing that
        from an enclosing level - the engine's outward walk (Wheeled_APC_F declares CommanderOptics
        at its top for a turret three levels down)."""
        w = self.w
        chain = w.ancestry_ns(ns, top)[0]
        seg = rp[-1]
        paths = [list(rp)] + [list(rp[:k]) + [seg] for k in range(len(rp) - 2, -1, -1)]
        for pi, path in enumerate(paths):
            via = None
            for i, (cns, cls) in enumerate(chain):
                if i == 0 and pi == 0:
                    continue                              # the class being written is not its own parent
                if (cns, cls.lower()) in self.names:
                    if self.ported_has(cns, cls, path):
                        return
                    via = (cns, cls.lower())
                    continue
                if self.v_lineage_has(cns, cls, path):
                    self.expose_at(addon, cns, cls, path, via, top)
                    return
                break
        # Nothing in the game has it: the sources' own edit of a base-game ancestor may - Aegis
        # adds its paint schemes to the game's vehicles. That edit is not imported, so the child
        # carries the whole class.
        for cns, cls in chain[1:]:
            if (cns, cls.lower()) in self.names:
                continue
            rn = w.R.get(*cns, cls) if cns else w.R.get(cls)
            if rn is not None and not rn.decl and s_has(rn, rp):
                node = rn
                for s_ in rp:
                    node = node.kids[s_.lower()]
                self.flatten[(ns, top.lower())][tuple(x.lower() for x in rp)] = node
                self.log["written out in full: inherited from the sources' edit of a base-game class"].append("%s: %s" % (top, "/".join(rp)))
                return
        self.orphan[(ns, top.lower())].add(tuple(x.lower() for x in rp))
        self.log["written without a parent: nothing above defines it"].append("%s: %s" % (top, "/".join(rp)))

    def resolve_named(self, addon, ns, top, relpath, parent, external=False):
        """A nested parent with another name: the lineage at each level out, then the tables."""
        w = self.w
        chain = w.ancestry_ns(ns, top)[0]
        for level in range(len(relpath), -1, -1):
            path = list(relpath[:level]) + [parent]
            via = None
            for i, (cns, cls) in enumerate(chain):
                if not external and (cns, cls.lower()) in self.names:
                    if self.ported_has(cns, cls, path):
                        if i > 0:
                            self.declare_here(ns, top, relpath[:level], parent)
                        return
                    via = (cns, cls.lower())
                    continue
                if self.v_lineage_has(cns, cls, path):
                    if external:
                        self.expose_at(addon, cns, cls, path, via, top)
                    else:
                        # declared in the imported body that uses it, which satisfies HEMTT and
                        # tools/check_externals.py both; a restated ancestor would only carry an
                        # unused copy (L-C14)
                        self.declare_here(ns, top, relpath[:level], parent)
                    return
                break
        for sns in w.SCOPES.get(ns, [ns]) + [()]:
            key = (sns, parent.lower())
            if key in self.names:
                if self.names[key][0] not in (None, addon):
                    self.cross[addon].add(self.names[key][0])
                return
            if w.vnode(sns, parent) is not None:
                if parent.lower() not in self.owned(addon, sns):
                    self.need_decl(addon, sns, parent)
                return
        self.log["kept, unverified: a nested parent found nowhere"].append("%s: %s -> %s" % (top, "/".join(relpath), parent))

    def declare_here(self, ns, top, relpath, name):
        """Declare an inherited nested parent in the imported body that uses it, too:
        tools/check_externals.py looks for it in lexical scope, and a declaration of an inherited
        member is the same member."""
        self.sibling[(ns, top.lower())][tuple(s.lower() for s in relpath)].setdefault(name.lower(), name)

    def requirements(self, it):
        w = self.w
        ns, name, addon = it["ns"], it["name"], it["addon"]
        node = w.snode(ns, name)
        if node.parent:
            pns = w.parent_ns(ns, node.parent)
            if pns is not None:
                pk = (pns, node.parent.lower())
                if pk in self.names:
                    if self.names[pk][0] not in (None, addon):
                        self.cross[addon].add(self.names[pk][0])
                elif node.parent.lower() not in self.owned(addon, pns):
                    self.need_decl(addon, pns, node.parent)
        self.nested_reqs(addon, ns, name, node, [])

    def nested_reqs(self, addon, ns, top, node, relpath, stack=()):
        stack = tuple(stack) + (node,)
        for kid in node.kids.values():
            rp = relpath + [kid.name]
            if kid.decl:
                continue                                  # declares the member right there
            p = kid.parent.lower() if kid.parent else ""
            if p and p == kid.name.lower():
                if not self.via_enclosing(addon, ns, stack, kid.name):
                    self.found_in_lineage(addon, ns, top, rp)
            elif p and not any(p in enc.kids for enc in stack):
                if not self.via_enclosing(addon, ns, stack, kid.parent):
                    self.resolve_named(addon, ns, top, relpath, kid.parent)
            self.nested_reqs(addon, ns, top, kid, rp, stack)

    def via_enclosing(self, addon, ns, stack, name):
        """A name the enclosing nested class inherits from a differently named parent - a fire
        mode's sound classes come from Mode_FullAuto, or from the sibling mode it extends:
        `class FullAuto_medium: FullAuto { class StandardSound: BaseSoundModeType {} }`."""
        if len(stack) < 2:
            return False
        enc, outer = stack[-1], stack[-2]
        p = enc.parent
        if not p or p.lower() == enc.name.lower():
            return False
        seen = set()
        while p and p.lower() not in seen:
            seen.add(p.lower())
            sib = outer.kids.get(p.lower())
            if sib is not None and not sib.decl:
                if name.lower() in sib.kids:
                    return True
                p = sib.parent if sib.parent.lower() != sib.name.lower() else ""
                continue
            for sns in self.w.SCOPES.get(ns, [ns]) + [()]:
                if (sns, p.lower()) in self.names:
                    return True
                if self.w.vnode(sns, p) is not None:
                    if not self.v_lineage_has(sns, p, [name]):
                        return False
                    self.expose_at(addon, sns, p, [name])
                    return True
            return False
        return False

    def render_stub(self, addon, ns, st, pad):
        w = self.w
        cls = st["name"]
        v = w.vnode(ns, cls)
        par = v.p if v is not None else ""
        if par:
            pns = w.parent_ns(ns, par) or ns
            par = self.vname(pns, par)
            if par.lower() not in self.stubs.get((addon, pns), {}) and par.lower() not in self.owned(addon, pns):
                self.need_decl(addon, pns, par)
        lines = [pad + "class %s%s {" % (cls, (": " + par) if par else "")]
        lines += [pad + "    " + l for l in st["props"]]
        lines += self.render_stub_kids(addon, ns, cls, v, st["kids"], [], pad + "    ")
        lines.append(pad + "};")
        return lines

    def render_stub_kids(self, addon, ns, cls, vlevel, req, relpath, pad):
        decls, bodies = [], []
        for lo, sub in list(req.items()):
            seg = sub["name"]
            rp = relpath + [seg]
            vk = vlevel.c.get(lo) if vlevel is not None else None
            if not sub["kids"] and not sub["props"]:
                decls.append(pad + "class %s;" % seg)     # before anything that inherits from it
                continue
            if vk is not None and vk.b:
                p = vk.p
                if p and p.lower() == lo:
                    self.stub_same_name(addon, ns, cls, rp)
                    p = seg
                elif p:
                    self.resolve_named(addon, ns, cls, relpath, p, external=True)
                head = "class %s%s {" % (seg, (": " + p) if p else "")
            else:
                # only declared here, or not here at all: it is the parent's, opened on the parent's
                self.stub_same_name(addon, ns, cls, rp)
                head = "class %s: %s {" % (seg, seg)
            bodies.append(pad + head)
            bodies += [pad + "    " + l for l in sub["props"]]
            bodies += self.render_stub_kids(addon, ns, cls, vk, sub["kids"], rp, pad + "    ")
            bodies.append(pad + "};")
        return decls + bodies

    def stub_same_name(self, addon, ns, cls, rp):
        """`class X: X` inside a restated base-game class: X from its parent at the same depth,
        or from its own lineage one level out and further."""
        w = self.w
        par = w.parent(ns, cls)
        pns = w.parent_ns(ns, par) if par else None
        if pns is not None and self.v_lineage_has(pns, par, rp):
            self.expose_at(addon, pns, par, rp, None, cls)
            return
        seg = rp[-1]
        for k in range(len(rp) - 2, -1, -1):
            path = list(rp[:k]) + [seg]
            if self.v_lineage_has(ns, cls, path):
                self.expose_at(addon, ns, cls, path, None, cls)
                return
        self.log["kept, unverified: restated a nested class with no parent to take it from"].append("%s: %s" % (cls, "/".join(rp)))

    # ------------------------------------------------------------ one vehicle per type
    def collapse_vehicles(self):
        """One placeable vehicle of each type in each jmfsb faction (user, 2026-09-14: "in jmfsb_red/
        blue/green only have one of each type of vechicle and make sure all the textures are avaiable in
        the vechicle customation").

        A TYPE is what a mission maker cannot change from Eden: the model, the nearest base class, the
        hull and turret weapons, and the pylon slots. Paint, crew, cargo and the default pylon loadout
        can be changed there, so classes that differ only in those fold into one. The class with the
        plainest name is kept; the rest stay in the config - faction addons build on them - but hidden
        (scope 1), and any paint of theirs the kept class does not already offer is added to its
        TextureSources, so Eden's appearance menu lists every camo the folded classes wore. Civilians
        (CIV_F) are not jmfsb's factions and are left as they are."""
        w, V = self.w, ("cfgvehicles",)
        groups = collections.defaultdict(list)
        for it in self.p.items.values():
            ns, name = it["ns"], it["name"]
            if ns != V or w.kind(ns, name) != "vehicle" or num(w.value(ns, name, "scope")) != 2:
                continue
            if SEEDS and name.lower() not in FULL:
                continue                     # a faction's hidden base, not one of the import's units
            faction = JMFSB_FACTIONS.get(num(w.value(ns, name, "side")))
            if faction not in ("jmfsb_red", "jmfsb_blue", "jmfsb_green"):
                continue
            groups[(faction,) + self.vehicle_type(name)].append(name)
        for gkey, names in sorted(groups.items(), key=lambda kv: (kv[0][0], min(n.lower() for n in kv[1]))):
            keep = min(names, key=lambda n: (len(STRIP.sub("", n)), STRIP.sub("", n).lower()))
            folded = sorted((n for n in names if n != keep), key=str.lower)
            for n in folded:
                self.collapsed[(V, n.lower())] = keep
            added = self.add_paints(keep, folded)
            self.log["one vehicle per type: kept <- hidden (+ paints added)"].append(
                "%s %s <- %s%s" % (gkey[0], keep, ", ".join(folded) or "-", (" (+%s)" % ", ".join(added)) if added else ""))

    def vehicle_type(self, name):
        w, V = self.w, ("cfgvehicles",)
        chain = [n for n in w.ancestry(V, name)[0] if w.is_new(V, n)]
        base = next((n for n in chain[1:] if "base" in n.lower()), "")
        model = w.value(V, name, "model")
        model = (model[1] if isinstance(model, tuple) else (model or "")).strip().lstrip("\\").lower()
        guns, pylons = {}, set()

        def walk(node, path):
            for lo, kid in node.kids.items():
                if kid.decl:
                    continue
                for k in ("weapons", "magazines"):
                    if k in kid.props:
                        guns[(path + "/" + lo, k)] = repr(kid.props[k][2])
                walk(kid, path + "/" + lo)
        for n in reversed(chain):
            node = w.snode(V, n)
            for k in ("weapons", "magazines"):
                if k in node.props:
                    guns[("", k)] = repr(node.props[k][2])
            if "turrets" in node.kids:
                walk(node.kids["turrets"], "")
            py = node.get("Components", "TransportPylonsComponent", "Pylons")
            if py is not None:
                pylons |= {lo for lo, kid in py.kids.items() if not kid.decl}
        return model, base.lower(), tuple(sorted(guns.items())), tuple(sorted(pylons))

    def add_paints(self, keep, folded):
        """Every hiddenSelectionsTextures the kept class and its folded twins wear, as a TextureSources
        entry on the kept class unless one it already has starts with the same textures (a paint that
        also sets the camo net and slat cage still matches a scheme that only sets the hull)."""
        w, V = self.w, ("cfgvehicles",)

        def norm(tex):
            return tuple(x[1].strip().lstrip("\\").lower() for x in tex)
        offered, labels = [], set()
        for n in reversed([x for x in w.ancestry(V, keep)[0] if w.is_new(V, x)]):
            ts = w.snode(V, n).kids.get("texturesources")
            for kid in (ts.kids.values() if ts is not None else ()):
                if kid.decl:
                    continue
                tex = kid.props.get("textures")
                if tex is not None and isinstance(tex[2], list):
                    offered.append(norm([x for x in tex[2] if isinstance(x, tuple)]))
                dn = kid.props.get("displayname")
                if dn is not None and isinstance(dn[2], tuple):
                    labels.add(dn[2][1].lower())
        node = w.snode(V, keep)
        pbo = node.pbos[-1] if node.pbos else ""
        added = []
        for n in [keep] + folded:
            hst = w.value(V, n, "hiddenselectionstextures")
            tex = [x for x in hst if isinstance(x, tuple) and x[1].strip()] if isinstance(hst, list) else []
            mine = norm(tex)
            if not mine or any(s and mine[:len(s)] == s[:len(mine)] for s in offered):
                continue
            offered.append(mine)
            ts = node.kid("TextureSources")
            if ts.decl:
                ts.decl, ts.parent = False, "TextureSources"
            label = self.paint_label(n, mine, labels)
            labels.add(label.lower())
            entry = ts.kid("jmfsb_" + (STRIP.sub("", n) or n))
            entry.decl = False
            entry.props["displayname"] = ("displayName", "=", ("s", label), pbo)
            author = w.value(V, n, "author")
            if isinstance(author, tuple):
                entry.props["author"] = ("author", "=", author, pbo)
            entry.props["textures"] = ("textures", "[]=", tex, pbo)
            entry.props["factions"] = ("factions", "[]=", [], pbo)       # every faction may wear it
            added.append(label)
        return added

    def paint_label(self, name, tex, taken):
        """A readable name for a paint: the camo suffix of its first texture, else the class's name."""
        model = self.w.value(("cfgvehicles",), name, "model")
        model = model[1] if isinstance(model, tuple) else (model or "")
        drop = set(os.path.splitext(model.replace("/", "\\").split("\\")[-1])[0].lower().split("_")) | PAINT_PARTS
        words = [t for t in os.path.splitext(tex[0].split("\\")[-1])[0].split("_") if t and not t.isdigit() and t not in drop]
        shown = self.w.value(("cfgvehicles",), name, "displayname")
        shown = shown[1] if isinstance(shown, tuple) else str(shown or name)
        if shown.startswith("$"):
            shown = self.strings.get(shown[1:].lower(), shown)
        label = " ".join(PAINT_WORDS.get(t, t.capitalize()) for t in words) or shown
        if label.lower() in taken:
            label = "%s (%s)" % (label, shown)
        return label

    # ------------------------------------------------------------ classes
    def emit_item(self, it):
        w = self.w
        ns, name, addon = it["ns"], it["name"], it["addon"]
        node = w.snode(ns, name)
        kind = self.p.ctx_of(it)
        side = num(w.value(ns, name, "side")) if ns == ("cfgvehicles",) else None
        hide = (kind == "man" and num(w.value(ns, name, "scope")) == 2) or (ns, name.lower()) in self.collapsed or             (bool(SEEDS) and ns == ("cfgvehicles",) and w.kind(ns, name) == "vehicle" and num(w.value(ns, name, "scope")) == 2
             and name.lower() not in FULL)   # a faction's base, not a unit
        ctx = Ctx(addon, ns, name, kind, side, hide)
        header = self.ref(ns, name, addon, False)
        par, pkey = "", None
        if node.parent:
            pns = w.parent_ns(ns, node.parent)
            if pns is not None and (pns, node.parent.lower()) in self.names:
                par = self.ref(pns, node.parent, addon, False)
                owner = self.names[(pns, node.parent.lower())][0]
                pkey = par.lower() if owner == addon else None
                if owner not in (None, addon):
                    # a parent another import addon carries (a vehicle's cargo grenade on the weapons
                    # addon's): HEMTT sees one addon at a time, so it is declared here
                    self.needs[(addon, ns)].setdefault(par.lower(), par)
                    self.cross[addon].add(owner)
            else:
                par = self.vname(pns, node.parent) if pns is not None else node.parent
                pkey = par.lower()
        lines = ["class %s%s {" % (header, (": " + par) if par else "")]
        lines += self.body(node, ctx, 1, top=True, key=(ns, name.lower()))
        lines.append("};")
        self.blocks[(addon, ns)].append((header.lower(), pkey, lines))

    def nested_parent(self, par, ctx, stack):
        """A nested class's parent: a sibling or an enclosing class's member as it is spelled
        there, an imported class by its jmfsb name, a base-game one as the game defines it."""
        lo = par.lower()
        for enc in reversed(stack):
            k = enc.kids.get(lo)
            if k is not None:
                return k.name
        for sns in self.w.SCOPES.get(ctx.ns, [ctx.ns]) + [()]:
            if (sns, lo) in self.names:
                return self.ref(sns, par, ctx.addon, False)
            if self.w.vnode(sns, par) is not None:
                return self.vname(sns, par)
        return par

    def body(self, node, ctx, depth, top=False, key=None, relpath=(), stack=()):
        pad = "    " * depth
        lines = []
        stack = tuple(stack) + (node,)
        for k, (pkey, op, val, _pbo) in node.props.items():
            if top and ctx.hide and k in ("scope", "scopecurator", "scopearsenal"):
                continue
            if top and ctx.kind == "man" and k == "vehicleclass":
                continue                                  # a hidden soldier is filed nowhere in the editor
            if k == "dlc":
                lines.append(pad + "dlc = QUOTE(PREFIX);")
                continue
            c = self.conv(val, ctx, k)
            if c is DROP:
                continue
            if isinstance(val, list):
                lines.append("%s%s[] %s %s;" % (pad, pkey, "+=" if op == "[]+=" else "=", c))
            else:
                lines.append("%s%s = %s;" % (pad, pkey, c))
        if top and ctx.ns == ("cfgvehicles",) and ctx.kind in ("vehicle", "man") and "faction" not in node.props:
            # a vehicle that only inherits its faction - from a base-game class - is filed by side too
            f = self.faction_for(ctx)
            if f is not None:
                lines.append('%sfaction = "%s";' % (pad, f))
        if top and ctx.hide:
            # the soldier a uniform needs, not a unit to place: Aegis's own rosters were not asked for.
            # Or a vehicle folded into the one kept for its type (collapse_vehicles).
            lines += [pad + "scope = 1;", pad + "scopeCurator = 0;"]
        elif top and ctx.ns == ("cfgvehicles",) and num(self.w.value(ctx.ns, ctx.name, "scope")) == 2 and any(
                (ctx.ns, a.lower()) in self.collapsed for a in self.w.ancestry(ctx.ns, ctx.name)[0][1:]):
            # A public vehicle built on a folded one would inherit its scope 1 and vanish from Eden
            # with it: the values it had are written out.
            for k, spelled in (("scope", "scope"), ("scopecurator", "scopeCurator")):
                if k not in node.props:
                    v = num(self.w.value(ctx.ns, ctx.name, k))
                    if v is not None:
                        lines.append("%s%s = %d;" % (pad, spelled, v))
        if top and key in self.inject:
            for lo, nm in sorted(self.inject[key].items()):
                if lo not in node.kids:
                    lines.append("%sclass %s;" % (pad, nm))
        refkey = TRANSPORT_REF.get(node.name.lower())
        inherited = parents_in(node)
        tkey = (ctx.ns, ctx.name.lower())
        used = set()
        decls, bodies = [], []
        for lo, nm in sorted(self.sibling.get(tkey, {}).get(tuple(relpath), {}).items()):
            if lo not in node.kids:
                decls.append("%sclass %s;" % (pad, nm))
        for kid in node.kids.values():
            kname = kid.name
            rp = tuple(relpath) + (kid.name.lower(),)
            if refkey:
                p = kid.props.get(refkey)
                if p is not None and isinstance(p[2], tuple) and self.class_value(ctx, refkey, p[2][1].strip()) is DROP:
                    continue
                short = INNER_STRIP.sub(r"\1", kname)
                if short and short.lower() not in used and short.lower() not in node.kids:
                    kname = short
            used.add(kname.lower())
            if kid.decl:
                # a declaration nothing below inherits from is dead weight, and HEMTT says so (L-C14)
                if kid.name.lower() in inherited or rp in self.keep.get(tkey, ()):
                    decls.append("%sclass %s;" % (pad, kname))
                continue
            src = kid
            if rp in self.flatten.get(tkey, {}):
                src = overlay(self.flatten[tkey][rp], kid)
                par = src.parent
            elif rp in self.orphan.get(tkey, ()):
                par = ""
            else:
                par = kid.parent
                if par:
                    par = kid.name if par.lower() == kid.name.lower() else self.nested_parent(par, ctx, stack)
            bodies.append("%sclass %s%s {" % (pad, kname, (": " + par) if par else ""))
            bodies += self.body(src, ctx, depth + 1, relpath=rp, stack=stack)
            bodies.append(pad + "};")
        return lines + decls + bodies

    # ------------------------------------------------------------ additions to base-game classes
    def additions(self):
        w = self.w
        for cls, disp, side, icon, flag in JMFSB_FACTION_DEFS:
            self.blocks[("vehicle", ("cfgfactionclasses",))].append((cls, None, [
                "class %s {" % cls, '    displayName = "%s";' % disp, "    priority = 1;", "    side = %d;" % side,
                '    icon = "%s";' % icon, '    flag = "%s";' % flag, "};"]))
        ma = w.R.get("CfgMovesBasic", "ManActions")
        acts = w.R.get("CfgMovesBasic", "Actions")
        for (ns, lo), (addon, n) in list(self.names.items()):
            if ns not in (G, M):
                continue
            src = self.w.snode(ns, lo).name
            if ma is not None and lo in ma.props:
                val = self.conv(ma.props[lo][2], Ctx(addon, ("cfgmovesbasic",), "ManActions"), "reloadaction")
                if val is not DROP:
                    self.expose_ext(addon, ("cfgmovesbasic",), "ManActions", [])["props"].append(
                        "%s = %s;" % (self.ref(ns, src, addon, False), val))
            for anode in (acts.kids.values() if acts is not None else ()):
                if anode.decl or w.is_new(A, anode.name) or lo not in anode.props:
                    continue
                _key, _op, val, _pbo = anode.props[lo]
                c = self.conv(val, Ctx(addon, A, anode.name), "reloadaction")
                if c is DROP:
                    continue
                arr = "[]" if isinstance(val, list) else ""
                self.expose_ext(addon, A, anode.name, [])["props"].append("%s%s = %s;" % (self.ref(ns, src, addon, False), arr, c))
        wells = w.R.get("CfgMagazineWells")
        for wn in (wells.kids.values() if wells is not None else ()):
            if wn.decl or w.is_new(("cfgmagazinewells",), wn.name):
                continue
            per = collections.defaultdict(list)
            for _key, _op, val, _pbo in wn.props.values():
                for x in (val if isinstance(val, list) else [val]):
                    mk = (("cfgmagazines",), x[1].strip().lower()) if isinstance(x, tuple) else None
                    if mk in self.names and x[1].strip() not in per[self.names[mk][0]]:
                        per[self.names[mk][0]].append(x[1].strip())
            for addon, mags in per.items():
                self.expose_ext(addon, ("cfgmagazinewells",), wn.name, [])["props"].append(
                    "GVAR(magazines)[] = {%s};" % ", ".join(self.ref(("cfgmagazines",), m, addon, True) for m in mags))
        # A base-game weapon the sources hand their magazines to - `class rockets_Skyfire: RocketPods
        # { magazines[] += {PylonRack_20Rnd_Rocket_80mm}; }` - gets the same, naming the imported
        # magazine; without it the pylon rack names a weapon that refuses it.
        cw = w.R.kids.get("cfgweapons")
        for wn in (cw.kids.values() if cw is not None else ()):
            mp = wn.props.get("magazines")
            if wn.decl or w.is_new(W, wn.name) or mp is None or mp[1] != "[]+=":
                continue
            per = collections.defaultdict(list)
            for x in (mp[2] if isinstance(mp[2], list) else [mp[2]]):
                mk = (("cfgmagazines",), x[1].strip().lower()) if isinstance(x, tuple) else None
                if mk in self.names and x[1].strip() not in per[self.names[mk][0]]:
                    per[self.names[mk][0]].append(x[1].strip())
            for addon, mags in per.items():
                self.expose_ext(addon, W, wn.name, [])["props"].append(
                    "magazines[] += {%s};" % ", ".join(self.ref(("cfgmagazines",), m, addon, True) for m in mags))
        for rn in w.R.kids.values():
            if rn.decl or rn.name.lower().startswith("cfg") or w.is_new((), rn.name):
                continue
            if "slotinfo" not in {a.lower() for a in w.ancestry((), rn.name)[0]}:
                continue
            ci = rn.kids.get("compatibleitems")
            per = collections.defaultdict(list)
            if ci is not None and not ci.decl:
                for key in (p[0] for p in ci.props.values()):
                    if (W, key.lower()) in self.names:
                        per[self.names[(W, key.lower())][0]].append(key)
                for addon, items in per.items():
                    node = self.expose_ext(addon, (), rn.name, ["compatibleItems"])
                    node["props"] += ["%s = 1;" % self.ref(W, i, addon, False) for i in items]
            elif "compatibleitems" in rn.props and isinstance(rn.props["compatibleitems"][2], list):
                for x in rn.props["compatibleitems"][2]:
                    if isinstance(x, tuple) and (W, x[1].strip().lower()) in self.names:
                        per[self.names[(W, x[1].strip().lower())][0]].append(x[1].strip())
                # The source's array form only works where the game's slot has an array. Where the
                # game writes compatibleItems as a class (PointerSlot_Pistol), `+=` logs "Cannot update
                # non array from array" and adds nothing, so the items go in as class entries.
                as_class = self.game_items_class(rn.name)
                for addon, items in per.items():
                    if as_class:
                        node = self.expose_ext(addon, (), rn.name, ["compatibleItems"])
                        node["props"] += ["%s = 1;" % self.ref(W, i, addon, False) for i in items]
                    else:
                        self.expose_ext(addon, (), rn.name, [])["props"].append(
                            "compatibleItems[] += {%s};" % ", ".join(self.ref(W, i, addon, True) for i in items))

    def game_items_class(self, slot):
        """Whether the game's own slot (or the nearest parent that defines one) writes compatibleItems
        as a class rather than an array."""
        seen, v = set(), self.w.vnode((), slot)
        while v is not None and v.n.lower() not in seen:
            seen.add(v.n.lower())
            if "compatibleitems" in v.c:
                return True
            v = self.w.vnode((), v.p) if v.p else None
        return False

    # ------------------------------------------------------------ rendering
    def cname(self, ns):
        v, r = self.w.V, self.w.R
        for p in ns:
            v = v.c.get(p) if v is not None else None
            r = r.kids.get(p) if r is not None else None
        return v.n if v is not None else (r.name if r is not None else ns[-1])

    def cparent(self, ns):
        if len(ns) != 1:
            return ""
        v = self.w.V.c.get(ns[0])
        return v.p if v is not None else ""

    def scopes_of(self, addon):
        out = set()
        for d in (self.needs, self.stubs, self.blocks):
            for (a, ns) in d:
                if a == addon:
                    for i in range(len(ns) + 1):
                        out.add(ns[:i])
        return out

    def stub_entries(self, addon, ns, pad, own):
        entries = []
        # a snapshot: restating one class can ask for its parent in this same scope, which render()
        # picks up on its next round
        for lo, st in list(self.stubs.get((addon, ns), {}).items()):
            if lo in own:
                continue
            v = self.w.vnode(ns, st["name"])
            entries.append((lo, v.p.lower() if v is not None and v.p else None, self.render_stub(addon, ns, st, pad)))
        return entries

    def render_scope(self, addon, ns, pad, all_scopes):
        own = self.owned(addon, ns)
        stubs = self.stubs.get((addon, ns), {})
        lines = [pad + "class %s;" % nm for lo, nm in sorted(self.needs.get((addon, ns), {}).items())
                 if lo not in stubs and lo not in own]
        entries = self.stub_entries(addon, ns, pad, own)
        entries += [(key, pkey, [pad + l for l in blines]) for key, pkey, blines in self.blocks.get((addon, ns), [])]
        lines += topo(entries)
        if ns:
            for child in sorted(s for s in all_scopes if len(s) == len(ns) + 1 and s[:len(ns)] == ns):
                lines += self.render_container(addon, child, pad, all_scopes)
        return lines

    def render_split(self, addon, ns, pad):
        """For a table the addon already opens: the declarations and restated classes that go at
        the top of its block, and the imported classes that go after the addon's own."""
        own, decl = self.owned(addon, ns), self.declared(addon, ns)
        take = self.takeover[(addon, ns[0])]
        stubs = self.stubs.get((addon, ns), {})
        early = []
        for lo, nm in sorted(self.needs.get((addon, ns), {}).items()):
            if lo in stubs or lo in own:
                continue
            if lo in decl:
                take.add(lo)
            early.append(pad + "class %s;" % nm)
        # a restated class whose parent the addon defines has to come after that definition
        late = set()
        changed = True
        while changed:
            changed = False
            for lo, st in stubs.items():
                v = self.w.vnode(ns, st["name"])
                p = v.p.lower() if v is not None and v.p else ""
                if lo not in late and lo not in own and p and (p in own or p in late):
                    late.add(lo)
                    changed = True
        early_e, late_e = [], []
        for e in self.stub_entries(addon, ns, pad, own):
            if e[0] in decl:
                take.add(e[0])
            (late_e if e[0] in late else early_e).append(e)
        late_e += [(key, pkey, [pad + l for l in blines]) for key, pkey, blines in self.blocks.get((addon, ns), [])]
        return early + topo(early_e), topo(late_e)

    def render_container(self, addon, ns, pad, all_scopes):
        par = self.cparent(ns)
        head = pad + "class %s%s {" % (self.cname(ns), (": " + par) if par else "")
        return [head] + self.render_scope(addon, ns, pad + "    ", all_scopes) + [pad + "};"]

    def signature(self, addon):
        return json.dumps([{"%s" % (k,): v for k, v in self.stubs.items() if k[0] == addon},
                           {"%s" % (k,): sorted(v) for k, v in self.needs.items() if k[0] == addon}],
                          sort_keys=True, default=str)

    def render(self, addon):
        """{file name: text}, and the addon's own blocks the inner files go into."""
        existing = self.existing_blocks(addon)
        files, outer = {}, []
        for _rnd in range(20):                            # restating a class can ask for more
            before = self.signature(addon)
            all_scopes = self.scopes_of(addon)
            files, outer = {}, []
            root = self.render_scope(addon, (), "", all_scopes)
            tops = sorted({s[0] for s in all_scopes if s}, key=lambda t: (t != "cfgmovesbasic", t))
            for top in tops:
                name = self.cname((top,))
                if top in existing:
                    d, c = self.render_split(addon, (top,), "    ")
                    if d:
                        files["imported_%s_decl.hpp" % name] = d
                    if c:
                        files["imported_%s.hpp" % name] = c
                else:
                    par = self.cparent((top,))
                    if par and par.lower() not in tops and par.lower() not in self.owned(addon, ()):
                        outer.append("class %s;" % par)
                    outer += self.render_container(addon, (top,), "", all_scopes)
            if before == self.signature(addon):
                break
        else:
            self.log["unsettled: restating kept asking for more after 20 rounds"].append(addon)
        head = ("// Generated by tools/aegis_port - do not hand-edit; change the generator and re-run.\n"
                "// Imported from the public Aegis, Atlas and OpF sources (APL-SA).\n\n")
        out = {}
        if root:
            out["imported_root.hpp"] = head + "\n".join(root) + "\n"
        for fn, lines in files.items():
            out[fn] = head + "\n".join(lines) + "\n"
        if outer:
            out["imported_config.hpp"] = head + "\n".join(outer) + "\n"
        return out, existing

    def existing_blocks(self, addon):
        """Top-level Cfg blocks the addon's own .hpp files open: lower name -> file."""
        found = {}
        base = os.path.join(ADDONS, addon)
        for f in sorted(os.listdir(base)):
            if not f.lower().endswith(".hpp") or f.startswith("imported_"):
                continue
            t = S.strip_comments(rd(os.path.join(base, f)))
            depth = 0
            for m in re.finditer(r'"(?:[^"\n]|"")*"|\bclass\s+(Cfg\w+)\s*\{|\{|\}', t):
                if m.group(0).startswith('"'):
                    continue
                if m.group(1):
                    if depth == 0:
                        found.setdefault(m.group(1).lower(), f)
                    depth += 1
                elif m.group(0) == "{":
                    depth += 1
                else:
                    depth -= 1
        return found

    # ------------------------------------------------------------ the addons' own files
    def repoint(self, addon, dry):
        """jmfsb's own classes that inherit or name an imported class, and paths into the sources."""
        changed = []
        # Only an addon that REQUIRES Aegis, Atlas or OpF is edited - today that is headware, whose
        # FAST-MT paints inherit Aegis's helmet. An addon that merely names a mod's class (the
        # weapons addon's arsenal groupings) works without the mod and is left as it is.
        if not re.search(r'(?is)requiredAddons\[\]\s*=\s*\{[^}]*"A3_(?:Aegis|Atlas|OpF)_', rd(os.path.join(ADDONS, addon, "config.cpp"))):
            return changed
        for path in own_files(addon):
            t = rd(path)
            if not re.search(r"(?i)aegis|atlas|opf", t):
                continue
            out = []
            pos = 0
            for m in re.finditer(r'"(?:[^"\n]|"")*"', t):
                out.append(self.repoint_code(t[pos:m.start()], addon))
                s = m.group(0)[1:-1]
                key = self.by_source.get(s.lower()) if STRIP.match(s) else None
                if key is not None:
                    out.append(self.ref(key[0], s, addon, True))
                elif TPATH.search(s):
                    out.append('"%s"' % self.rewrite_string(s, "picture", Ctx(addon, (), os.path.basename(path))))
                else:
                    out.append(m.group(0))
                pos = m.end()
            out.append(self.repoint_code(t[pos:], addon))
            n = "".join(out)
            # a declaration of a class that is now this mod's own reads as a second definition
            n = re.sub(r"(?m)^[ \t]*class\s+E?GVAR\([^)]*\)\s*;[ \t]*\r?\n", "", n)
            # the dependency the imported classes replace
            n = re.sub(r'(?m)^[ \t]*"A3_(?:Aegis|Atlas|OpF)_\w+"[ \t]*,?[ \t]*(//[^\n]*)?\r?\n', "", n)
            n = re.sub(r",(\s*)\}", r"\1}", n)
            if n != t:
                changed.append(os.path.relpath(path, ADDONS))
                if not dry:
                    io.open(path, "w", encoding="utf-8", newline="").write(n)
        return changed

    def repoint_code(self, code, addon):
        def sub(m):
            key = self.by_source.get(m.group(0).lower())
            return self.ref(key[0], m.group(0), addon, False) if key is not None else m.group(0)
        return re.sub(r"\b(?:Aegis|Atlas|OPF)_\w+", sub, code)

    def wire(self, addon, files, existing, dry):
        base = os.path.join(ADDONS, addon)
        cfg_path = os.path.join(base, "config.cpp")
        cfg = rd(cfg_path)
        nl = "\r\n" if "\r\n" in cfg else "\n"
        tables = {}
        for fn in files:
            m = re.match(r"imported_(Cfg\w+?)(_decl)?\.hpp$", fn)
            if m:
                tables.setdefault(m.group(1).lower(), {})["decl" if m.group(2) else "classes"] = fn
        for table, fns in tables.items():
            self.include_in_block(os.path.join(base, existing[table]), table, fns, addon, dry)
        if "imported_root.hpp" in files and '#include "imported_root.hpp"' not in cfg:
            m = re.search(r"class\s+CfgPatches\s*\{", cfg)
            end = self.block_end(cfg, m.end() - 1)
            semi = cfg.find(";", end) + 1
            cfg = cfg[:semi] + nl + nl + '#include "imported_root.hpp"' + cfg[semi:]
        if "imported_config.hpp" in files and '#include "imported_config.hpp"' not in cfg:
            cfg = cfg.rstrip() + nl + '#include "imported_config.hpp"' + nl
        units = [self.ref(k[0], it["name"], addon, True) for k, it in self.p.items.items()
                 if it["addon"] == addon and it["ns"] == ("cfgvehicles",)]
        weapons = [self.ref(k[0], it["name"], addon, True) for k, it in self.p.items.items()
                   if it["addon"] == addon and it["ns"] == W]
        cfg = self.fill_list(cfg, "units", units, nl)
        cfg = self.fill_list(cfg, "weapons", weapons, nl)
        req = ["A3_Data_F_Decade_Loadorder"] + (["cba_jr"] if self.cba[addon] else []) + \
            ["jmfsb_%s" % a for a in sorted(self.cross[addon])]
        for r in req:
            if '"%s"' % r.lower() in cfg.lower():
                continue
            cfg = re.sub(r'(requiredAddons\[\]\s*=\s*\{\s*)', lambda m: m.group(1) + '"%s",%s            ' % (r, nl), cfg, count=1)
        if not dry:
            io.open(cfg_path, "w", encoding="utf-8", newline="").write(cfg)

    @staticmethod
    def block_end(t, open_brace):
        depth, i, n = 0, open_brace, len(t)
        while i < n:
            c = t[i]
            if c == '"':
                j = t.find('"', i + 1)
                while j >= 0 and j + 1 < n and t[j + 1] == '"':
                    j = t.find('"', j + 2)
                i = n if j < 0 else j + 1
                continue
            if t.startswith("//", i):
                j = t.find("\n", i)
                i = n if j < 0 else j
                continue
            if t.startswith("/*", i):
                j = t.find("*/", i + 2)
                i = n if j < 0 else j + 2
                continue
            if c == "{":
                depth += 1
            elif c == "}":
                depth -= 1
                if depth == 0:
                    return i
            i += 1
        return -1

    def include_in_block(self, path, table, fns, addon, dry):
        t = rd(path)
        nl = "\r\n" if "\r\n" in t else "\n"
        t = re.sub(r'(?m)^[ \t]*#include "imported_[^"]*"[ \t]*\r?\n', "", t)   # what an earlier run put in
        m = re.search(r"(?m)^class\s+%s\s*\{" % re.escape(self.cname((table,))), t) or \
            re.search(r"class\s+%s\s*\{" % re.escape(self.cname((table,))), t, re.I)
        end = self.block_end(t, m.end() - 1)
        mine = {self.ref(k[0], it["name"], addon, False).lower() for k, it in self.p.items.items() if it["addon"] == addon}
        early = bool({x.lower() for x in re.findall(r"class\s+[\w()]+\s*:\s*(GVAR\(\w+\))", t[m.end():end])} & mine)
        # the bare declarations the import's declarations now make, out of the block's top level
        take = self.takeover.get((addon, table), set())
        if take:
            out, depth, pos = [], 0, m.end()
            for line in t[m.end():end].splitlines(True):
                code = S.strip_comments(re.sub(r'"(?:[^"\n]|"")*"', '""', line))
                dm = re.match(r"\s*class\s+(\w+)\s*;\s*$", code)
                if not (depth == 0 and dm and dm.group(1).lower() in take):
                    out.append(line)
                depth += code.count("{") - code.count("}")
            t = t[:m.end()] + "".join(out) + t[end:]
            end = self.block_end(t, m.end() - 1)
        # the declarations go right after the block opens and whatever it includes or comments first
        at = t.find("\n", m.end()) + 1
        for line in t[at:end].splitlines(True):
            s = line.strip()
            if not s or s.startswith(("//", "/*", "*", "#include")):
                at += len(line)
                continue
            break
        ins = ""
        if "decl" in fns:
            ins += '#include "%s"' % fns["decl"] + nl
        if "classes" in fns and early:
            # this addon's own classes inherit imported ones: those come first
            ins += '#include "%s"' % fns["classes"] + nl
        t = t[:at] + ins + t[at:]
        if "classes" in fns and not early:
            end = self.block_end(t, m.end() - 1)
            t = t[:end] + '#include "%s"' % fns["classes"] + nl + t[end:]
        if not dry:
            io.open(path, "w", encoding="utf-8", newline="").write(t)

    @staticmethod
    def fill_list(cfg, array, names, nl):
        beg = "// --- imported %s: generated by tools/aegis_port, do not edit between the markers" % array
        end = "// --- end imported %s" % array
        block = nl.join(["            " + beg] + ["            %s," % n for n in names] + ["            " + end])
        pat = re.compile(r"[ \t]*" + re.escape(beg) + r".*?" + re.escape(end), re.S)
        m0 = re.search(r"class\s+CfgPatches\s*\{", cfg)
        if pat.search(cfg):
            cfg = pat.sub(lambda _m: block if names else "", cfg)
        elif names:
            m = re.search(r"(?m)^([ \t]*)" + array + r"\[\]\s*=\s*\{\s*\};", cfg[m0.start():])
            if m:
                s, e = m0.start() + m.start(), m0.start() + m.end()
                cfg = cfg[:s] + "%s%s[] = {%s%s%s%s};" % (m.group(1), array, nl, block, nl, m.group(1)) + cfg[e:]
            else:
                m = re.search(r"(?m)^[ \t]*" + array + r"\[\]\s*=\s*\{", cfg[m0.start():])
                s = m0.start() + m.end()
                cfg = cfg[:s] + nl + block + cfg[s:]
        # the last entry before the closing brace takes no comma
        return re.sub(r",(\s*//[^\n]*\n\s*)\}", r"\1}", cfg)


def run(w, p, dry=False, configs_only=False):
    e = Emitter(w, p)
    if not SEEDS or FULL:
        e.collapse_vehicles()                               # before requirements: it adds TextureSources entries
    e.own_asset_refs()
    e.trace()
    for it in p.items.values():                         # what each class needs declared, first:
        e.requirements(it)                              # an inherited member can land in another's body
    e.additions()
    for it in p.items.values():
        e.emit_item(it)
    rendered = {a: e.render(a) for a in TARGETS}
    e.trace()                                           # anything a class named late
    # Every file the trace collected gets its place under models/ - not only the ones a config or a
    # model names. The textures beside a model that nothing names were collected and then never
    # written, until this line; the ask was all of them.
    for real, owner in list(e.asset_owner.items()):
        e.target(real, owner)
    sizes, counts = collections.Counter(), collections.Counter()
    for real in set(e.path_real.values()):
        owner = e.asset_owner[real]
        sizes[owner] += os.path.getsize(real)
        counts[owner] += 1
    print("\n%-10s %8s %8s %10s   %s" % ("addon", "classes", "files", "MB", "generated"))
    for a in TARGETS:
        files, _existing = rendered[a]
        n = sum(1 for it in p.items.values() if it["addon"] == a)
        print("%-10s %8d %8d %10.0f   %s" % (a, n, counts[a], sizes[a] / 1e6,
                                             ", ".join("%s (%d KB)" % (f, len(t) // 1024) for f, t in sorted(files.items()))))
    print("crews replaced:", sum(e.crews.values()), "references;", "names given a number:", len(e.renamed))
    print("bare declarations taken over:", {"%s/%s" % k: sorted(v) for k, v in e.takeover.items() if v})
    for k, v in sorted(e.log.items(), key=lambda kv: -len(kv[1])):
        print("  %-78s %5d  e.g. %s" % (k, len(v), "; ".join(v[:2])))
    changed = {a: e.repoint(a, dry=True) for a in TARGETS}
    print("own files that name imported classes or source paths:", {a: c for a, c in changed.items() if c})
    report = {"log": {k: v for k, v in e.log.items()}, "crews": ["%s -> %s" % k for k in e.crews],
              "renamed": e.renamed, "plan_log": {k: v for k, v in p.log.items()}}
    json.dump(report, io.open(os.path.join(HERE, "port_report.json"), "w", encoding="utf-8"), indent=1)
    if dry:
        return e
    write(e, rendered, configs_only)
    return e


def write(e, rendered, configs_only=False):
    # clear what an earlier run wrote
    for a in TARGETS:
        base = os.path.join(ADDONS, a)
        mdir = os.path.join(base, ASSETS)
        if os.path.isdir(mdir) and not configs_only:
            if not os.path.exists(os.path.join(mdir, "GENERATED.txt")):
                raise SystemExit("%s exists and was not written by the port - refusing to delete it" % mdir)
            shutil.rmtree(mdir)
        for f in os.listdir(base):
            if f.startswith("imported_") and f.endswith(".hpp"):
                os.remove(os.path.join(base, f))
    for a in TARGETS:
        files, existing = rendered[a]
        e.repoint(a, dry=False)
        base = os.path.join(ADDONS, a)
        for fn, t in files.items():
            wr(os.path.join(base, fn), t)
        e.wire(a, files, existing, dry=False)
    if configs_only:
        print("configs written; models/ left as the last full run copied it")
        return
    written = 0
    done = set()
    pending = True
    while pending:
        pending = False
        for lo, real in list(e.path_real.items()):
            if lo in done:
                continue
            done.add(lo)
            pending = True
            owner = e.asset_owner[real]
            dst = os.path.join(ADDONS, *e.asset_path[real].split("\\")[3:])
            os.makedirs(os.path.dirname(dst), exist_ok=True)
            ext = os.path.splitext(real)[1].lower()
            if ext == ".p3d":
                with open(real, "rb") as fh:
                    data = e.rewrite_bytes(fh.read(), owner)
                with open(dst, "wb") as fh:
                    fh.write(data)
            elif ext == ".rvmat":
                t = e.rewrite_text_file(rd(real), owner)

                def q(m):
                    v = m.group(2).strip()
                    if v.lower() in ("true", "false"):
                        v = "1" if v.lower() == "true" else "0"
                    elif not re.match(r'^(-?\d|"|\{)', v):
                        v = '"' + v + '"'
                    return m.group(1) + v + ";"
                t = re.sub(r"(?m)^(\s*[A-Za-z_]\w*\s*=\s*)([^;\n]+);", q, t)
                # the same for a bare word in an array (renderFlags[] = {AlphaTest16}, L-C01)
                t = re.sub(r"(?m)^(\s*[A-Za-z_]\w*\[\]\s*=\s*\{)([^}\n]*)(\};)",
                           lambda m: m.group(1) + ",".join(
                               ('"%s"' % x.strip()) if re.match(r"^[A-Za-z_]\w*$", x.strip()) else x
                               for x in m.group(2).split(",")) + m.group(3), t)
                wr(dst, RVMAT_TEX.sub(r"\1.paa\2", t).rstrip("\n") + "\n")
            else:
                shutil.copy2(real, dst)
            written += 1
    # Aegis's and Atlas's Vests, Headgear and Uniforms folders (and OpF's Uniforms) land in one
    # folder each: written one after the other, the last model.cfg won, and every model only the
    # others defined was binarized without its skeleton - a vest drawn at the wearer's feet.
    folders = collections.OrderedDict()
    for real, owner in sorted(e.modelcfg):
        mod, pbo, rest = os.path.relpath(real, SRC).replace("\\", "/").split("/", 2)
        dst = os.path.join(ADDONS, owner, ASSETS, kind_folder(pbo), *rest.split("/"))
        folders.setdefault(os.path.normcase(dst), (dst, []))[1].append((mod.split("_", 1)[-1], e.rewrite_text_file(rd(real), owner)))
    merged = 0
    for dst, sources in folders.values():
        if len(sources) == 1:
            wr(dst, sources[0][1])
            continue
        here = os.path.dirname(dst)
        models = {os.path.splitext(f)[0].lower() for f in os.listdir(here) if f.lower().endswith(".p3d")} if os.path.isdir(here) else set()
        wr(dst, merge_model_cfgs(sources, models, e.log))
        merged += 1
    if merged:
        print("model.cfg files merged from more than one mod: %d" % merged)
    for a in TARGETS:
        mdir = os.path.join(ADDONS, a, ASSETS)
        if os.path.isdir(mdir):
            wr(os.path.join(mdir, "GENERATED.txt"),
               "Everything under this folder is written by tools/aegis_port from the public Aegis, Atlas\n"
               "and OpF sources (APL-SA). Do not hand-edit it: change the generator and re-run.\n")
    print("wrote %d asset files and %d model.cfg files" % (written, len(e.modelcfg)))
