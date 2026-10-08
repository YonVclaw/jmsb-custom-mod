"""Vehicle base classes of jmfsb's imported vehicle addon and the PLA pack in D:\\work\\pla2,
with the paint schemes their configs define and the camo variants their texture files carry.

    python vehicle_bases.py          -> vehicle_bases.json + a summary
    python vehicle_bases.py --diag   -> parser check: classes found by a plain brace count vs parsed
"""
import os, re, sys, json, pickle, collections
sys.path.insert(0, r"D:\Git\jmfs-custom-mod\tools\aegis_port")
import vanilla_config  # noqa: F401  (the pickle needs class N)

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
SP = os.environ.get("JMFSB_CAMO_CACHE", r"D:\work\camo_cache")
os.makedirs(SP, exist_ok=True)
PLA = r"D:\work\pla2"
JMFSB = r"D:\Git\jmfs-custom-mod"
VV = pickle.load(open(os.path.join(JMFSB, r"tools\aegis_port\vanilla_config.cache"), "rb"))["tree"].c["cfgvehicles"]


# ------------------------------------------------------------------ config text parser
def read_text(p):
    b = open(p, "rb").read()
    for enc in ("utf-8-sig", "gbk", "latin-1"):
        try:
            return b.decode(enc)
        except UnicodeDecodeError:
            pass


def strip(text):
    out, i, n = [], 0, len(text)
    while i < n:
        c = text[i]
        if c == '"':
            j = i + 1
            while j < n:
                if text[j] == '"':
                    if j + 1 < n and text[j + 1] == '"':
                        j += 2
                        continue
                    break
                j += 1
            out.append(text[i:j + 1])
            i = j + 1
        elif text.startswith("//", i):
            j = text.find("\n", i)
            i = n if j < 0 else j
        elif text.startswith("/*", i):
            j = text.find("*/", i + 2)
            i = n if j < 0 else j + 2
        elif c == "#" and text[text.rfind("\n", 0, i) + 1:i].strip() == "":
            j = text.find("\n", i)
            while 0 < j and text[j - 1] == "\\":
                j = text.find("\n", j + 1)
            i = n if j < 0 else j
        else:
            out.append(c)
            i += 1
    return "".join(out)


TOK = re.compile(r'"(?:[^"]|"")*"|\+=|[{}();:,=\[\]]|[^\s{}();:,=\[\]"]+')


class Node:
    def __init__(self, name, parent=None, body=False):
        self.name, self.parent, self.body, self.props, self.kids = name, parent, body, {}, {}


def parse(text):
    toks = TOK.findall(strip(text))
    n = len(toks)
    pos = 0
    root = Node("", body=True)

    def v(t):
        return t[1:-1].replace('""', '"') if t.startswith('"') else t

    def arr():
        nonlocal pos
        pos += 1
        items, cur = [], []
        while pos < n:
            t = toks[pos]
            if t == "{":
                items.append(arr())
                continue
            if t == "}":
                if cur:
                    items.append(" ".join(cur))
                pos += 1
                return items
            if t == ",":
                if cur:
                    items.append(" ".join(cur))
                cur = []
                pos += 1
                continue
            cur.append(v(t))
            pos += 1
        return items

    def body(node):
        nonlocal pos
        while pos < n:
            t = toks[pos]
            if t == "}":
                pos += 1
                if pos < n and toks[pos] == ";":
                    pos += 1
                if node is root:
                    continue
                return
            if t == ";":
                pos += 1
                continue
            if t == "class" and pos + 1 < n:
                name = toks[pos + 1]
                pos += 2
                parent = None
                if pos < n and toks[pos] == ";":
                    pos += 1
                    node.kids.setdefault(name.lower(), Node(name))
                    continue
                if pos < n and toks[pos] == ":":
                    parent = toks[pos + 1] if pos + 1 < n else None
                    pos += 2
                if pos < n and toks[pos] == "{":
                    pos += 1
                    k = node.kids.get(name.lower())
                    if k is None or not k.body:
                        k = Node(name, parent, True)
                        node.kids[name.lower()] = k
                    elif parent:
                        k.parent = parent
                    body(k)
                continue
            if t == "delete":
                pos += 3
                continue
            name = t
            pos += 1
            if pos < n and toks[pos] == "[":
                pos += 3  # [ ] and = or +=
                if pos < n and toks[pos] == "{":
                    val = arr()
                else:
                    cur = []
                    while pos < n and toks[pos] not in (";", "}"):
                        cur.append(v(toks[pos]))
                        pos += 1
                    val = [" ".join(cur)]
                if pos < n and toks[pos] == ";":
                    pos += 1
                node.props[name.lower()] = val
                continue
            if pos < n and toks[pos] == "=":
                pos += 1
                cur = []
                while pos < n and toks[pos] not in (";", "}"):
                    cur.append(v(toks[pos]))
                    pos += 1
                if pos < n and toks[pos] == ";":
                    pos += 1
                node.props[name.lower()] = " ".join(cur)
                continue
    body(root)
    return root


def scan_top_classes(text, root_name="cfgvehicles"):
    """Class bodies directly inside a root class, by brace counting alone (the parser's check)."""
    toks = TOK.findall(strip(text))
    stack, out, i, n = [], [], 0, len(toks)
    while i < n:
        t = toks[i]
        if t == "class" and i + 1 < n:
            name, j = toks[i + 1], i + 2
            if j < n and toks[j] == ":":
                j += 2
            if j < n and toks[j] == "{":
                if len(stack) == 1 and stack[0].lower() == root_name:
                    out.append(name)
                stack.append(name)
                i = j + 1
                continue
            i = j
            continue
        if t == "{":
            stack.append("{")
        elif t == "}" and stack:
            stack.pop()
        i += 1
    return out


# ------------------------------------------------------------------ sources
strings = {}
_st = os.path.join(PLA, "language_lk", "stringtable.xml")
if os.path.exists(_st):
    # not well-formed XML (the file opens with bytes ElementTree rejects), so read it by pattern
    for m in re.finditer(r'(?s)<Key\s+ID="([^"]+)"\s*>(.*?)</Key>', read_text(_st)):
        for lang in ("English", "Original"):
            e = re.search(r"(?s)<%s>(.*?)</%s>" % (lang, lang), m.group(2))
            if e and e.group(1).strip():
                strings[m.group(1).lower()] = e.group(1).strip()
                break


def resolve_str(s):
    if isinstance(s, str) and s.startswith("$"):
        return strings.get(s[1:].lower(), s)
    return s


class Rec:
    def __init__(self, node, folder):
        self.node, self.folder = node, folder
        self.name, self.parent = node.name, node.parent


JMFSB_CFG = os.path.join(JMFSB, "addons", "vehicle", "imported_config.hpp")
FACTIONS = ("jmfsb_blue", "jmfsb_red", "jmfsb_green")
KEPT_LOG = "one vehicle per type: kept <- hidden (+ paints added)"


def jmfsb_text():
    """The vehicle addon's generated config as the game reads it: jmfsb's macros spelled out."""
    t = read_text(JMFSB_CFG)
    t = re.sub(r"\bQEGVAR\((\w+),\s*(\w+)\)", r'"jmfsb_\1_\2"', t)
    t = re.sub(r"\bEGVAR\((\w+),\s*(\w+)\)", r"jmfsb_\1_\2", t)
    t = re.sub(r"\bQGVAR\((\w+)\)", r'"jmfsb_vehicle_\1"', t)
    t = re.sub(r"\bGVAR\((\w+)\)", r"jmfsb_vehicle_\1", t)
    return t


def load_jmfsb():
    root = parse(jmfsb_text())
    cv = root.kids.get("cfgvehicles")
    return {k: Rec(nd, "vehicle") for k, nd in cv.kids.items() if nd.body}, {}


def folded_by_keeper():
    """lower jmfsb name of each vehicle kept for its type -> the jmfsb names folded into it (port log)."""
    out = {}
    strip = lambda n: "jmfsb_vehicle_" + re.sub(r"(?i)^(aegis|atlas|opf)_", "", n)
    try:
        rep = json.load(open(os.path.join(JMFSB, "tools", "aegis_port", "port_report.json"), encoding="utf-8"))
    except (OSError, ValueError):
        return out
    for row in rep.get("log", {}).get(KEPT_LOG, []):
        _fac, rest = row.split(" ", 1)
        keep, _, tail = rest.partition(" <- ")
        names = [h for h in re.sub(r"\s*\(\+.*\)$", "", tail).split(", ") if h and h != "-"]
        out[strip(keep).lower()] = [strip(h) for h in names]
    return out


def faction_vehicles(table, kept_from):
    """Every vehicle a jmfsb faction can place, with the paints Eden's appearance menu offers it."""
    out = []
    for k, r in table.items():
        fam, uav, _anc = family(table, r.name)
        if fam is None or scope(table, r.name) != 2 or value(table, r.name, "faction") not in FACTIONS:
            continue
        paints = []
        for kk, e in nested(table, r.name, "texturesources").items():
            textures, tokens, rep, missing, external = texture_set("jmfsb", e.props.get("textures") or [])
            paints.append({"kind": "scheme", "name": resolve_str(e.props.get("displayname", e.name)) or e.name,
                           "cls": e.name, "tokens": sorted(tokens, key=str.lower), "rep": rep,
                           "factions": [f for f in (e.props.get("factions") or []) if isinstance(f, str)],
                           "textures": len(textures), "missing": missing, "external": external,
                           "added": kk.startswith("jmfsb_")})
        out.append({"cls": r.name, "displayName": resolve_str(value(table, r.name, "displayname") or ""),
                    "faction": value(table, r.name, "faction"), "family": fam, "uav": uav,
                    "folded": sorted(kept_from.get(k, []), key=str.lower), "paints": paints})
    return sorted(out, key=lambda v: (FACTIONS.index(v["faction"]), v["family"], v["displayName"].lower()))


def pla_configs():
    by_patch = collections.defaultdict(list)
    for d in sorted(os.listdir(PLA)):
        p = os.path.join(PLA, d, "config.cpp")
        if not os.path.isfile(p) or os.path.getsize(p) == 0:
            continue
        text = read_text(p)
        root = parse(text)
        cp = root.kids.get("cfgpatches")
        pname = next(iter(cp.kids.values())).name if cp and cp.kids else d
        by_patch[pname.lower()].append((d, root, text))
    return by_patch


def load_pla():
    table, also = {}, collections.defaultdict(list)
    for pname, entries in pla_configs().items():
        # the Driverski copies (_patch / _class_patch) share the CfgPatches name: they win
        entries.sort(key=lambda e: e[0].lower().endswith("patch"))
        for d, root, _text in entries:
            cv = root.kids.get("cfgvehicles")
            if cv is None:
                continue
            for k, nd in cv.kids.items():
                if not nd.body:
                    continue
                if k in table and table[k].folder != d:
                    also[k].append(table[k].folder)
                table[k] = Rec(nd, d)
    return table, also


# ------------------------------------------------------------------ class queries
SCOPE_WORDS = {"private": 0, "protected": 1, "public": 2}


def ancestry(table, name):
    out, seen, cur = [], set(), name
    while cur and cur.lower() not in seen:
        seen.add(cur.lower())
        r = table.get(cur.lower())
        if r is not None:
            out.append(("src", r))
            cur = r.parent
            continue
        vn = VV.c.get(cur.lower())
        if vn is not None:
            out.append(("vanilla", vn))
            cur = vn.p
            continue
        out.append(("unknown", cur))
        break
    return out


def anc_name(kind, x):
    return x.name if kind == "src" else x.n if kind == "vanilla" else x


def value(table, name, key):
    for kind, x in ancestry(table, name):
        if kind == "src" and key in x.node.props:
            return x.node.props[key]
        if kind == "vanilla" and isinstance(x.v, dict) and key in x.v:
            return x.v[key]
    return None


def scope(table, name):
    s = value(table, name, "scope")
    if s is None:
        return 0
    s = str(s).strip().lower()
    if s in SCOPE_WORDS:
        return SCOPE_WORDS[s]
    return int(float(s)) if re.fullmatch(r"-?\d+(\.\d+)?", s) else 0


FAMILY = [("camanbase", None), ("man", None), ("bag_base", None), ("reammobox", None), ("thing", None),
          ("building", None), ("parachutebase", None), ("staticweapon", "Static weapon"), ("ship", "Boat"),
          ("helicopter", "Helicopter"), ("plane", "Plane"), ("tank", "Tracked"), ("car", "Wheeled")]


def family(table, name):
    anc = ancestry(table, name)
    names = [anc_name(k, x).lower() for k, x in anc]
    for key, fam in FAMILY:
        if key in names:
            return fam, any("uav" in a for a in names), anc
    return None, False, anc


def nested(table, name, cname):
    """A nested class merged down the in-source ancestry (child entries win)."""
    merged = collections.OrderedDict()
    chain = [x for kind, x in ancestry(table, name) if kind == "src"]
    for r in reversed(chain):
        k = r.node.kids.get(cname)
        if k is not None:
            for kk, e in k.kids.items():
                if e.body:
                    merged[kk] = e
    return merged


# ------------------------------------------------------------------ texture variants
# Words that name a PART of a texture set (or a map type), never a paint. Single letters stay out: the
# PLA pack's camo suffixes are _d, _k, _o, _w2, _b.
NONCAMO = set("""glass optic optics int inter interior mfd fix lod mlod damage destruct wreck cockpit wheel
wheels gear gears fuel fueltank fueltanks eng engine panel panle dash light lights decal decals ca nohq smdi as
ti mc dt number numbers glow emit screen hud blur rotor rotors blade blades prop mat detail details shadow trans
env land bottom bottoms cop tracks track chain body hull turret adds ext cargo cover girder era eras rws antenna
gun guns barrel seat seats canopy pylon pylons missile missiles weapon weapons wing wings tail pod pods launcher
mount frame part parts misc""".split())
_dirs = {}


def noncamo(tok):
    return tok.isdigit() or re.sub(r"\d+$", "", tok.lower()) in NONCAMO


def dir_variants(d):
    """{file lower: (camo token or None, full path, size)} for the _co textures in one folder.

    A suffix is a camo when it sits beside its own default texture (h_d beside h) or when the same suffix
    ends two or more part names (body_BAF, adds_BAF). Failing both, a set of two or more sibling endings
    that are not themselves part names (j20a_ext_black / _grey / _camo1) counts too."""
    if d in _dirs:
        return _dirs[d]
    files = [f for f in os.listdir(d) if f.lower().endswith("_co.paa")] if os.path.isdir(d) else []
    stems = {f: f[:-7].split("_") for f in files}
    low = {f: tuple(x.lower() for x in t) for f, t in stems.items()}
    lowset = set(low.values())
    sufpre = collections.defaultdict(set)
    for t in lowset:
        for k in range(1, len(t)):
            sufpre[t[k:]].add(t[:k])
    parts_of_other = {t for t in lowset if any(len(o) > len(t) and o[:len(t)] == t for o in lowset)}
    groups = collections.defaultdict(set)
    for t in lowset:
        if len(t) > 1:
            groups[t[:-1]].add(t)
    res = {}
    for f, t in stems.items():
        tl, tok = low[f], None
        for k in range(1, len(tl)):
            suf = tl[k:]
            if noncamo(suf[0]) or all(noncamo(x) for x in suf):
                continue
            if tl[:k] in lowset or len(sufpre[suf]) >= 2:
                tok = "_".join(t[k:])
                break
        if tok is None and len(tl) > 1 and not noncamo(tl[-1]):
            sib = [s for s in groups[tl[:-1]] if s not in parts_of_other and not noncamo(s[-1])]
            if len(sib) >= 2:
                tok = t[-1]
        full = os.path.join(d, f)
        res[f.lower()] = (tok, full, os.path.getsize(full))
    _dirs[d] = res
    return res


_pla_dirs = {d.lower(): d for d in os.listdir(PLA)}


def disk_path(src, p):
    if not isinstance(p, str) or not p.strip():
        return None
    q = p.strip().lstrip("\\").replace("/", "\\")
    if src == "jmfsb":
        m = re.match(r"(?i)z\\jmfsb\\addons\\(.*)", q)
        return os.path.join(JMFSB, "addons", m.group(1)) if m else None
    first, _, rest = q.partition("\\")
    d = _pla_dirs.get(first.lower())
    return os.path.join(PLA, d, rest) if d else None


def tex_info(src, p):
    """(state, token, disk path): state is 'disk', 'missing' (ours, not on disk) or 'external'."""
    dp = disk_path(src, p)
    if dp is None:
        return "external", None, None
    if not dp.lower().endswith(".paa"):
        dp += ".paa"
    got = dir_variants(os.path.dirname(dp)).get(os.path.basename(dp).lower())
    if got is None:
        return "missing", None, dp
    return "disk", got[0], got[1]


def tex_key(t):
    return t.strip().lstrip("\\").lower().removesuffix(".paa")


def texture_set(src, textures):
    """Colour textures only (the _co / _ca maps a paint swaps), with their tokens and the largest file."""
    textures = [t for t in textures if isinstance(t, str) and t.strip() and not t.strip().startswith("#")]
    tokens, best, missing, external, first_game = set(), None, 0, 0, None
    for t in textures:
        state, tok, dp = tex_info(src, t)
        if state == "external":
            external += 1
            if first_game is None and t.strip().lstrip("\\").lower().startswith("a3\\"):
                first_game = t.strip().lstrip("\\")
            continue
        if state == "missing":
            missing += 1
            continue
        if tok:
            tokens.add(tok)
        size = os.path.getsize(dp)
        if best is None or size > best[1]:
            best = (dp, size)
    # a paint that only uses the game's own textures gets its swatch from the game's PBO ("game:" path)
    rep = best[0] if best else (("game:" + first_game) if first_game else None)
    return textures, tokens, rep, missing, external


# ------------------------------------------------------------------ rows
def build(src, table, also, skip=frozenset()):
    children = collections.defaultdict(list)
    for r in table.values():
        if r.parent:
            children[r.parent.lower()].append(r)
    fams = {k: family(table, r.name) for k, r in table.items()}
    bases, unknown = {}, []
    for k, r in table.items():
        if src != "game" and k in VV.c:
            continue  # a base-game class the config restates
        fam, uav, anc = fams[k]
        looks_base = bool(children[k]) or "base" in k
        if fam is None:
            if anc and anc[-1][0] == "unknown" and looks_base:
                unknown.append("%s  <- %s" % (r.name, " > ".join(anc_name(a, x) for a, x in anc[1:])))
            continue
        if scope(table, r.name) < 2 and looks_base and k not in skip:     # a hidden folded variant is no base
            bases[k] = r

    nearest = {}
    for c in table.values():
        cc = [x for kind, x in ancestry(table, c.name) if kind == "src"][1:]
        near = next((x for x in cc if x.name.lower() in bases), None)
        nearest[c.name.lower()] = near.name.lower() if near else None

    rows = []
    for k, r in bases.items():
        fam, uav, anc = fams[k]
        chain = [x for kind, x in anc if kind == "src"]
        depth = sum(1 for x in chain[1:] if x.name.lower() in bases)
        publics = [c for c in table.values() if c.name.lower() not in bases and nearest[c.name.lower()] == k
                   and scope(table, c.name) >= 2]

        paints, seen_sets, dirs = [], [], set()

        def note_dirs(textures):
            for t in textures:
                state, _tok, dp = tex_info(src, t)
                if state == "disk":
                    dirs.add(os.path.dirname(dp))

        schemes = collections.OrderedDict()
        for owner in [r] + publics:
            for kk, e in nested(table, owner.name, "texturesources").items():
                schemes.setdefault(kk, (owner, e))
        for kk, (owner, e) in schemes.items():
            textures, tokens, rep, missing, external = texture_set(src, e.props.get("textures") or [])
            note_dirs(textures)
            seen_sets.append({tex_key(t) for t in textures})
            paints.append({"kind": "scheme", "name": resolve_str(e.props.get("displayname", e.name)) or e.name,
                           "cls": e.name, "tokens": sorted(tokens, key=str.lower), "rep": rep,
                           "factions": [f for f in (e.props.get("factions") or []) if isinstance(f, str)],
                           "textures": len(textures), "missing": missing, "external": external})
        for owner in [r] + publics:
            hst = value(table, owner.name, "hiddenselectionstextures")
            if not isinstance(hst, list):
                continue
            textures, tokens, rep, missing, external = texture_set(src, hst)
            key = {tex_key(t) for t in textures}
            note_dirs(textures)
            if not key or any(key <= s for s in seen_sets):
                continue
            seen_sets.append(key)
            paints.append({"kind": "class", "name": resolve_str(value(table, owner.name, "displayname") or "")
                           or owner.name, "cls": owner.name, "tokens": sorted(tokens, key=str.lower), "rep": rep,
                           "factions": [], "textures": len(textures), "missing": missing, "external": external})

        model = value(table, r.name, "model") or ""
        if model:
            mdl = disk_path(src, model if model.lower().endswith(".p3d") else model + ".p3d")
            if mdl and os.path.isdir(os.path.dirname(mdl)):
                for dp_, _dn, fn in os.walk(os.path.dirname(mdl)):
                    if any(f.lower().endswith("_co.paa") for f in fn):
                        dirs.add(dp_)
        named = {t.lower() for p in paints for t in p["tokens"]}
        disk = collections.OrderedDict()
        for d in sorted(dirs):
            for _f, (tok, full, size) in dir_variants(d).items():
                if tok and tok.lower() not in named:
                    e = disk.setdefault(tok.lower(), {"token": tok, "files": {}})
                    e["files"][full] = size
        for key, e in disk.items():
            rep = max(e["files"].items(), key=lambda kv: kv[1])[0]
            paints.append({"kind": "disk", "name": e["token"], "cls": "", "tokens": [e["token"]], "rep": rep,
                           "factions": [], "textures": len(e["files"]), "missing": 0, "external": 0})

        rows.append({
            "source": src, "addon": r.folder, "also": sorted(set(also.get(k, []))), "cls": r.name,
            "parent": r.parent or "", "parentBase": bases[nearest[k]].name if nearest.get(k) else None,
            "depth": depth, "family": fam, "uav": uav, "scope": scope(table, r.name), "model": model,
            "displayName": resolve_str(value(table, r.name, "displayname") or ""),
            "publics": [{"cls": c.name, "displayName": resolve_str(value(table, c.name, "displayname") or ""),
                         "addon": c.folder} for c in sorted(publics, key=lambda c: c.name.lower())],
            "paints": paints,
        })
    return rows, unknown


def diag():
    t = jmfsb_text()
    scanned = {x.lower() for x in scan_top_classes(t)}
    parsed = set(parse(t).kids.get("cfgvehicles").kids)
    print("jmfsb: brace count %d, parsed %d, missed %d" % (len(scanned), len(parsed), len(scanned - parsed)))
    print("  first missed:", sorted(scanned - parsed)[:12])
    for pname, entries in pla_configs().items():
        for d, root, text in entries:
            scanned = {x.lower() for x in scan_top_classes(text)}
            cv = root.kids.get("cfgvehicles")
            parsed = {k for k, nd in (cv.kids.items() if cv else []) if nd.body}
            if scanned != parsed:
                print("pla %-22s brace %3d parsed %3d missed %s extra %s" % (
                    d, len(scanned), len(parsed), sorted(scanned - parsed)[:6], sorted(parsed - scanned)[:4]))
    print("pla: every other config parses to the brace count")


if __name__ == "__main__":
    if "--diag" in sys.argv:
        diag()
        sys.exit(0)
    g_table, g_also = load_jmfsb()
    kept_from = folded_by_keeper()
    g_rows, unk_g = build("jmfsb", g_table, g_also, skip={h.lower() for hs in kept_from.values() for h in hs})
    fv = faction_vehicles(g_table, kept_from)
    json.dump(fv, open(os.path.join(SP, "faction_vehicles.json"), "w", encoding="utf-8"), ensure_ascii=False, indent=1)
    print("jmfsb faction vehicles:", dict(collections.Counter(v["faction"] for v in fv)),
          "| paints:", sum(len(v["paints"]) for v in fv), "| added:", sum(p["added"] for v in fv for p in v["paints"]))
    # user, 2026-09-14: "remove the extra mods only include base game, jmfsb and A3_Aegis_Public_Releases"
    p_table, p_rows, unk_p = {}, [], []
    out = g_rows
    json.dump(out, open(os.path.join(SP, "vehicle_bases.json"), "w", encoding="utf-8"), ensure_ascii=False, indent=1)
    print("jmfsb classes parsed:", len(g_table), "| pla classes parsed:", len(p_table), "| strings:", len(strings))
    for src in ("jmfsb", "pla"):
        rs = [r for r in out if r["source"] == src]
        kinds = collections.Counter(p["kind"] for r in rs for p in r["paints"])
        print("\n%s: %d base classes; by family %s; paints %s; public variants %d" % (
            src, len(rs), dict(collections.Counter(r["family"] for r in rs)), dict(kinds),
            sum(len(r["publics"]) for r in rs)))
        for r in sorted(rs, key=lambda r: (r["family"], r["cls"].lower()))[:40]:
            print("  %-13s %-46s d%d pub%-3d %s" % (r["family"], r["cls"], r["depth"], len(r["publics"]),
                  [("%s%s" % ({"scheme": "", "class": "c:", "disk": "f:"}[p["kind"]], p["name"])) for p in r["paints"]][:10]))
    print("\nunknown-ancestry candidates:", len(unk_g), len(unk_p))
    for u in (unk_g + unk_p)[:20]:
        print("  " + u)
