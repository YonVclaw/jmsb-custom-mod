"""Import the Aegis, Atlas and OpF vehicles, weapons, vests, uniforms and headgear into jmfsb.

    python tools/aegis_port/vanilla_config.py     # once per game update: the base game's classes
    python tools/aegis_port/port.py --census      # what the sources hold, by kind and model
    python tools/aegis_port/port.py --plan        # what would come in, and why the rest does not
    python tools/aegis_port/port.py --dry         # everything but the writing
    python tools/aegis_port/port.py               # write it

THE ASK (user, 2026-09-12): "i want imported all vechicles with p3d files, all weapons with p3d
files all vests with p3d files, all uniforms with p3d files no dependincies on atlas/aegis, no for
or 5 add ons, vhechicles to vhcicles, weapons to wepaons, and bring in all textures for any assit
imported", then "bring in all uniform textures and vest and helment textures and any hemets that
have p3ds". Settled by question the same day: every class whose model ships - in the public
sources or in the base game - comes in; only the classes whose .p3d was removed from the public
repository stay out. The mods' factions are kept under jmfsb_ names, and vehicle crews become the
base game's.

WHERE THINGS GO. Five existing addons, no new ones:
    vehicles                         -> vehicle
    weapons and weapon accessories   -> weapons
    vests                            -> vests
    uniforms (and the soldier each uniform needs)  -> uniform
    headgear                         -> headware
Everything a class needs comes with it into the same addon - its parents, magazines, ammo, sound
sets, recoils, gestures, crew poses, factions - and every model, texture, material, sound and
animation it names is copied under that addon's models/ folder, with every path rewritten to
point there. Nothing requires Aegis, Atlas or OpF, and no class is named after them.

Sources: the public A3_Aegis_Public_Releases repository (APL-SA, like jmfsb); authors are kept on
every class. See README.md beside this file for the decisions and the run order.
"""
import collections
import os
import pickle
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
sys.setrecursionlimit(20000)
import vanilla_config  # noqa: F401,E402 - the cache's node class is defined there
import source_config as S  # noqa: E402

JMFSB = os.path.normpath(os.path.join(HERE, "..", ".."))
ADDONS = os.path.join(JMFSB, "addons")
SRC = S.SRC
MOD_PREFIXES = ("a3_aegis\\", "a3_atlas\\", "a3_opf\\")

KIND_ADDON = {"vehicle": "vehicle", "weapon": "weapons", "accessory": "weapons",
              "vest": "vests", "uniform": "uniform", "headgear": "headware"}
ITEM_KIND = {701: "vest", 605: "headgear", 801: "uniform", 101: "accessory", 201: "accessory",
             301: "accessory", 302: "accessory"}


def num(v):
    """A config value as a number, when it is one."""
    if isinstance(v, (int, float)):
        return v
    if isinstance(v, tuple) and v[0] in ("n", "b", "s"):
        try:
            return int(v[1]) if re.match(r"^-?\d+$", v[1].strip()) else float(v[1])
        except ValueError:
            # a scope written as a word the sources' lowercase macros never matched - emit.SCOPE_WORDS
            return {"private": 0, "protected": 1, "public": 2}.get(v[1].strip().lower())
    return None


def text(v):
    if isinstance(v, tuple):
        return v[1]
    return v if isinstance(v, str) else ""


class World:
    """The sources laid over the base game, with the lookups the port keeps asking."""

    # Where a parent written inside a moves table is found. `class GestureReloadBase: Default`
    # names CfgGesturesMale >> Default, one level out from States; the engine walks outward, and
    # so does this. A crew pose's Default is further out still, in CfgMovesBasic.
    SCOPES = {
        ("cfggesturesmale", "states"): [("cfggesturesmale", "states"), ("cfggesturesmale",)],
        ("cfgmovesmalesdr", "states"): [("cfgmovesmalesdr", "states"), ("cfgmovesmalesdr",), ("cfgmovesbasic",)],
        ("cfgmovesbasic", "actions"): [("cfgmovesbasic", "actions"), ("cfgmovesbasic",)],
    }

    def __init__(self):
        with open(os.path.join(HERE, "vanilla_config.cache"), "rb") as fh:
            cache = pickle.load(fh)
        self.V = cache["tree"]
        self.files = cache["files"]
        self.cba = cache["cba"]
        self.patches = cache["patches"]
        self.src = S.load(cache["includes"], cache["patches"].keys())
        self.R = self.src["tree"]
        self.index = self.src["index"]

    # -- raw nodes
    def snode(self, ns, name):
        n = self.R
        for p in ns:
            n = n.kids.get(p)
            if n is None:
                return None
        c = n.kids.get(name.lower())
        return c if c is not None and not c.decl else None

    def vnode(self, ns, name):
        n = self.V
        for p in ns:
            n = n.c.get(p)
            if n is None:
                return None
        return n.c.get(name.lower())

    def is_new(self, ns, name):
        return self.snode(ns, name) is not None and self.vnode(ns, name) is None

    def is_cba(self, ns, name):
        return ((ns[0] if ns else name.lower()), name.lower() if ns else name.lower()) in self.cba or \
            ((ns[0] if ns else ""), name.lower()) in self.cba

    def known(self, ns, name):
        return self.vnode(ns, name) is not None or self.snode(ns, name) is not None

    def parent(self, ns, name):
        if self.is_new(ns, name):
            return self.snode(ns, name).parent
        v = self.vnode(ns, name)
        return v.p if v is not None else ""

    def parent_ns(self, ns, pname):
        for s in self.SCOPES.get(ns, [ns]):
            if self.known(s, pname):
                return s
        return None

    def ancestry_ns(self, ns, name):
        """[(ns, name), (ns, parent), ...] and whether it ends somewhere real."""
        if not self.known(ns, name):
            return [], False
        out, seen = [], set()
        cur_ns, cur = ns, name
        while cur:
            k = (cur_ns, cur.lower())
            if k in seen:
                return out, False
            seen.add(k)
            out.append((cur_ns, cur))
            par = self.parent(cur_ns, cur)
            if not par:
                return out, True
            pns = self.parent_ns(cur_ns, par)
            if pns is None:
                return out, False
            cur_ns, cur = pns, par
        return out, True

    def ancestry(self, ns, name):
        pairs, ok = self.ancestry_ns(ns, name)
        return [n for _, n in pairs], ok

    def value(self, ns, name, key):
        key = key.lower()
        for cns, cls in self.ancestry_ns(ns, name)[0]:
            if self.is_new(cns, cls):
                p = self.snode(cns, cls).props.get(key)
                if p is not None:
                    return p[2]
            else:
                v = self.vnode(cns, cls)
                if v is not None and key in v.v:
                    return v.v[key]
        return None

    def item_type(self, name):
        """The ItemInfo type of a CfgWeapons item, followed through both kinds of inheritance."""
        ns = ("cfgweapons",)
        for cls in self.ancestry(ns, name)[0]:
            if self.is_new(ns, cls):
                ii = self.snode(ns, cls).kids.get("iteminfo")
                if ii is not None and not ii.decl:
                    if "type" in ii.props:
                        return num(ii.props["type"][2])
                    if ii.parent and ii.parent.lower() != "iteminfo":
                        return num(self.value(ns, ii.parent, "type"))
            else:
                ii = self.vnode(ns, cls).c.get("iteminfo")
                if ii is not None:
                    if "type" in ii.v:
                        return ii.v["type"]
                    if ii.p and ii.p.lower() != "iteminfo":
                        return num(self.value(ns, ii.p, "type"))
        return None

    def uniform_class(self, name):
        ns = ("cfgweapons",)
        for cls in self.ancestry(ns, name)[0]:
            if self.is_new(ns, cls):
                ii = self.snode(ns, cls).kids.get("iteminfo")
                if ii is not None and "uniformclass" in ii.props:
                    return text(ii.props["uniformclass"][2])
            else:
                ii = self.vnode(ns, cls).c.get("iteminfo")
                if ii is not None and "uniformclass" in ii.v:
                    return ii.v["uniformclass"]
        return None

    # -- what a class is
    def kind(self, ns, name):
        anc, ok = self.ancestry(ns, name)
        low = {a.lower() for a in anc}
        if ns == ("cfgvehicles",):
            if "camanbase" in low:
                return "man"
            if low & {"landvehicle", "air", "ship"}:
                return "vehicle"
            if low & {"weaponholder", "weapon_base_f", "item_base_f", "vest_base_f", "headgear_base_f"}:
                return "holder"
            return "other"
        if ns == ("cfgweapons",):
            if low & {"riflecore", "pistolcore", "launchercore"}:
                return "weapon"
            return ITEM_KIND.get(self.item_type(name), "other")
        return "other"

    # -- files
    def resolve_src(self, path, exts=()):
        lo = path.strip().replace("/", "\\").lstrip("\\").lower()
        if lo.endswith(".tga"):
            lo = lo[:-4] + ".paa"
        for cand in [lo] + [lo + e for e in exts]:
            if cand in self.index:
                return self.index[cand]
        return None

    def asset_state(self, path, exts=()):
        """none, mod (in the sources), mod-missing (removed from them), game, or unavailable."""
        lo = path.strip().replace("/", "\\").lstrip("\\").lower()
        if not lo or lo in ("bmp", "empty"):
            return "none"
        if lo.startswith(MOD_PREFIXES):
            return "mod" if self.resolve_src(lo, exts) else "mod-missing"
        if lo.startswith("#"):
            return "none"                                   # a procedural texture
        for cand in [lo] + [lo + e for e in exts]:
            if cand in self.files:
                return "game"
        return "unavailable"


def census(w):
    src = w.src
    print("sources: %d addons loaded, %d left out as creator-DLC compat, %d parse problems"
          % (len(src["addons"]), len(src["cdlc"]), sum(len(v) for v in src["errors"].values())))
    table = collections.Counter()
    examples = collections.defaultdict(list)
    for root in ("cfgvehicles", "cfgweapons"):
        ns = (root,)
        for k, node in w.R.kids[root].kids.items():
            if node.decl or not w.is_new(ns, node.name):
                continue
            if all("deprecated" in f.lower() for f in node.files):
                table[(root, "deprecated alias", "-")] += 1
                continue
            kd = w.kind(ns, node.name)
            anc, ok = w.ancestry(ns, node.name)
            if not ok:
                state = "parent not available"
            elif kd == "uniform":
                uc = w.uniform_class(node.name)
                if not uc:
                    state = "no uniformClass"
                elif not w.known(("cfgvehicles",), uc):
                    state = "uniformClass not available"
                else:
                    state = w.asset_state(text(w.value(("cfgvehicles",), uc, "model")), (".p3d",))
            else:
                state = w.asset_state(text(w.value(ns, node.name, "model")), (".p3d",))
            table[(root, kd, state)] += 1
            if num(w.value(ns, node.name, "scope")) == 2:
                table[(root, kd + " (public)", state)] += 1
            if len(examples[(root, kd, state)]) < 3:
                examples[(root, kd, state)].append(node.name)
    print("\n%-12s %-22s %-28s %6s" % ("table", "kind", "model", "count"))
    for (root, kd, state), n in sorted(table.items()):
        print("%-12s %-22s %-28s %6d   %s" % (root, kd, state, n, ", ".join(examples.get((root, kd.replace(" (public)", ""), state), []))))


# ---------------------------------------------------------------- the plan: what comes in, and where
# The tables a class can be named in, as the path to the class list. () is the config root, where
# the weapon fire modes, the attachment slots and the particle effects live.
NAMESPACES = [("cfgvehicles",), ("cfgweapons",), ("cfgmagazines",), ("cfgammo",), ("cfgglasses",),
              ("cfgmagazinewells",), ("cfgrecoils",), ("cfgsoundsets",), ("cfgsoundshaders",),
              ("cfgcloudlets",), ("cfglights",), ("cfgnonaivehicles",), ("cfgfactionclasses",),
              ("cfgeditorsubcategories",), ("cfgweaponcursors",),
              ("cfgmovesmalesdr", "states"), ("cfggesturesmale", "states"), ("cfgmovesbasic", "actions"), ()]
GEAR = {"weapon", "accessory", "vest", "headgear", "uniform"}
# Which table a key means when a name exists in more than one.
KEY_NS = {
    "weapons": ("cfgweapons",), "weapon": ("cfgweapons",), "linkeditems": ("cfgweapons",),
    "respawnlinkeditems": ("cfgweapons",), "item": ("cfgweapons",), "baseweapon": ("cfgweapons",),
    "respawnweapons": ("cfgweapons",), "magazines": ("cfgmagazines",), "magazine": ("cfgmagazines",),
    "respawnmagazines": ("cfgmagazines",), "pylonmagazine": ("cfgmagazines",), "ammo": ("cfgammo",),
    "submunitionammo": ("cfgammo",), "crew": ("cfgvehicles",), "typicalcargo": ("cfgvehicles",),
    "uniformclass": ("cfgvehicles",), "backpack": ("cfgvehicles",), "faction": ("cfgfactionclasses",),
    "factions": ("cfgfactionclasses",), "soundsetshot": ("cfgsoundsets",), "soundsets": ("cfgsoundsets",),
    "soundshaders": ("cfgsoundshaders",), "recoil": ("cfgrecoils",), "magazinewell": ("cfgmagazinewells",),
    "editorsubcategory": ("cfgeditorsubcategories",), "cursor": ("cfgweaponcursors",),
    "cursoraim": ("cfgweaponcursors",), "actions": ("cfgmovesbasic", "actions"),
    "reloadaction": ("cfggesturesmale", "states"),
}
# Keys whose values are selections, memory points or inner class names - never a class in a table.
NOT_REFS = {"hiddenselections", "texturelist", "animationlist", "modes", "muzzles", "sounds",
            "selectionfireanim", "memorypointgun", "gunbeg", "gunend", "memorypointcamera",
            "cameradir", "simulation", "hitpoint", "selection", "source", "proxytype",
            "hidevalue", "unhidevalue"}
CREW_KEYS = {"crew", "typicalcargo", "gunnertype", "drivertype", "commandertype"}
OWN_ADDON_NS = {("cfgfactionclasses",): "vehicle", ("cfgeditorsubcategories",): "vehicle"}
ORDER = ["weapons", "vests", "headware", "uniform", "vehicle"]
# A class comes in under its name without the mod's prefix, so two source classes can meet on one
# name - see Plan.dedupe.
STRIP = re.compile("(?i)^(?:aegis|atlas|opf)_")
MOD_ORDER = {"aegis": 0, "atlas": 1, "opf": 2}
# --seeds FILE (user, 2026-10-04: the Aegis family leaves the load order, "fix what you can"): import only
# the classes jmfsb's faction addons name, one per line, and what they need - soldiers, gear on
# base-game models and the FAMAS included, since the factions are built on them. Empty: the full import.
SEEDS = []
if "--seeds" in sys.argv:
    with open(sys.argv[sys.argv.index("--seeds") + 1], encoding="utf-8") as _fh:
        SEEDS = [l.strip() for l in _fh if l.strip() and not l.startswith("#")]
# --full vehicle,weapon,accessory (user, 2026-10-05: "also add back all the vehicles and weapons from
# opensource aegis/atlas"): beside the seeds, every class of those kinds the full import would bring -
# public, filed under jmfsb_blue/red/green and folded one per type, as the 2026-09-13/14 decisions say.
FULL_KINDS = set()
if "--full" in sys.argv:
    FULL_KINDS = set(sys.argv[sys.argv.index("--full") + 1].split(","))


class Plan:
    def __init__(self, w):
        self.w = w
        self.items = collections.OrderedDict()   # (ns, lower name) -> dict(ns, name, addon, why)
        self.blocked = {}                        # (ns, lower name) -> reason
        self.twin = {}                           # (ns, lower name) of a dropped duplicate -> the one kept, or ("own", addon, name)
        self.log_reparent = []                   # classes moved onto the copy kept
        self.dupes = {}                          # (ns, lower name) -> (reason, name, the name kept)
        # The names jmfsb's own files already give their classes, per addon: `class GVAR(x)`.
        self.own_defs = collections.defaultdict(dict)
        for addon in set(KIND_ADDON.values()):
            for r, dirs, files in os.walk(os.path.join(ADDONS, addon)):
                dirs[:] = [d for d in dirs if d != "models"]
                for f in files:
                    if f.endswith((".hpp", ".cpp")) and not f.startswith("imported_"):
                        with open(os.path.join(r, f), encoding="utf-8", errors="replace") as fh:
                            for m in re.finditer(r"class\s+GVAR\((\w+)\)\s*[:{]", fh.read()):
                                self.own_defs[addon].setdefault(m.group(1).lower(), m.group(1))
        self.log = collections.defaultdict(list)
        self.assets = {}                         # real path -> owner addon
        self.missing_assets = collections.Counter()
        self.crew = collections.Counter()
        self.index = collections.defaultdict(list)   # lower name -> [ns] where the sources define it new
        for ns in NAMESPACES:
            table = w.R.get(*ns) if ns else w.R
            if table is None:
                continue
            for k, node in table.kids.items():
                if node.decl or (not ns and k.startswith("cfg")):
                    continue
                if w.is_new(ns, node.name):
                    self.index[k].append(ns)

    # -- judging a class
    def model_ok(self, ns, name):
        w = self.w
        if ns == ("cfgweapons",) and w.kind(ns, name) == "uniform":
            uc = w.uniform_class(name)
            if not uc or not w.known(("cfgvehicles",), uc):
                return "its uniformClass is not available"
            # The soldier IS the uniform: an item whose soldier stays out cannot be worn, and ACE says so
            # ("has invalid uniformClass"). Ten did - their soldiers stand on Western Sahara's encrypted
            # O_A_Soldier_lxWS / I_SFIA_*_lxWS and take their model from it. A soldier dropped as a
            # duplicate is fine: the copy kept stands in for it.
            soldier = self.portable(("cfgvehicles",), uc)
            if soldier and not soldier.startswith("duplicate:"):
                return "its soldier class cannot come in (%s)" % soldier
            state = w.asset_state(text(w.value(("cfgvehicles",), uc, "model")), (".p3d",))
        else:
            state = w.asset_state(text(w.value(ns, name, "model")), (".p3d",))
        if state == "mod-missing":
            return "model removed from the public sources"
        if state == "unavailable":
            return "model belongs to a DLC the port cannot carry"
        return None

    def portable(self, ns, name):
        """None when the class can come in, else why not."""
        w = self.w
        key = (ns, name.lower())
        if key in self.blocked:
            return self.blocked[key]
        anc, ok = w.ancestry(ns, name)
        why = None
        if self.famas(ns, name) and not SEEDS:
            # User, 2026-09-13: "you can remove the FAMAS". Its M203 versions dress the launcher in
            # Aegis's M4A1 M203 textures, which Aegis took out of the public repository in January
            # 2025 (74aca1a9), so those models named files nothing ships.
            why = "the FAMAS, left out by request"
        elif not SEEDS and ("lxws" in name.lower() or (ns == ("cfgvehicles",) and "lxws" in text(w.value(ns, name, "faction")).lower())):
            # --seeds: a class filed under one of Western Sahara's factions, or named for it, can
            # still stand on the base game alone - the faction is replaced by side anyway, and a
            # parent or model of that DLC's is caught below
            # Aegis's Western Sahara variants: their parents are the base game's, but their extra
            # turrets, sounds and textures are that creator DLC's - and a vehicle in one of its
            # factions (NATO desert, SFIA, ION, Tura) is filed under a faction jmfsb cannot load
            why = "a Western Sahara variant (built on that creator DLC)"
        elif not ok:
            why = "a parent is not in the base game, CBA or the loaded sources"
        elif ns == ("cfgvehicles",) and num(w.value(ns, name, "scope")) == 2 and self.ws_armed(ns, name):
            why = "a Western Sahara variant (built on that creator DLC)"
        elif ns in (("cfgvehicles",), ("cfgweapons",), ("cfgmagazines",)):
            why = self.model_ok(ns, name)
            if why is None and ns == ("cfgvehicles",) and w.kind(ns, name) == "vehicle":
                if w.asset_state(text(w.value(ns, name, "model")), (".p3d",)) == "none" and num(w.value(ns, name, "scope")) in (1, 2):
                    why = "a public vehicle with no model"
        if why:
            self.blocked[key] = why
        return why

    FAMAS_DIR = re.compile(r"(?i)[\\/]rifles[\\/]famas[\\/]")

    def famas(self, ns, name):
        """Atlas's FAMAS family: the rifles, presets, magazines, magazine well, reload gesture and
        magazine proxy are all named for it; anything else on one of its models is caught by the
        model. Not by source file - that folder's cfgWeapons.hpp gives Rifle_Base_F a body too."""
        if "famas" in name.lower():
            return True
        return any(self.FAMAS_DIR.search(text(self.w.value(ns, name, k))) for k in ("model", "modelspecial"))

    def seed_roots(self):
        """The --seeds classes, wherever they live, each into the addon its kind goes to; a soldier into
        uniform, beside the soldiers its uniforms need."""
        w = self.w
        out = []
        for name in SEEDS:
            cands = self.index.get(name.lower())
            if not cands:
                self.log["seed left out: not in the public sources"].append(name)
                continue
            ns = cands[0]
            why = self.portable(ns, name)
            if why:
                self.log["seed left out: " + why.split(" (")[0]].append(name)
                continue
            kd = w.kind(ns, name)
            addon = KIND_ADDON.get(kd) or ("uniform" if kd == "man" else "vehicle" if ns == ("cfgvehicles",) else "weapons")
            out.append((ns, w.snode(ns, name).name, addon, kd if kd in KIND_ADDON or kd == "man" else "dep"))
        out.sort(key=lambda r: ORDER.index(r[2]))
        return out

    def roots(self):
        if not SEEDS:
            return self.full_roots(None)
        out = self.seed_roots()
        self.full_root_names = set()
        if FULL_KINDS:
            have = {r[1].lower() for r in out}
            for r in self.full_roots(FULL_KINDS):
                self.full_root_names.add(r[1].lower())
                if r[1].lower() not in have:
                    out.append(r)
            out.sort(key=lambda r: ORDER.index(r[2]))
        return out

    def full_roots(self, only):
        w = self.w
        out = []
        for root, kinds in (("cfgweapons", None), ("cfgvehicles", {"vehicle"})):
            ns = (root,)
            for k, node in w.R.kids[root].kids.items():
                if node.decl or not w.is_new(ns, node.name):
                    continue
                kd = w.kind(ns, node.name)
                if root == "cfgweapons":
                    if kd not in GEAR:
                        continue
                    if kd == "weapon" and num(w.value(ns, node.name, "type")) not in (1, 2, 4):
                        continue                                    # a vehicle's gun, not a man's
                elif kd not in kinds:
                    continue
                if all("deprecated" in f.lower() for f in node.files):
                    self.log["left out: deprecated alias of a renamed class"].append(node.name)
                    continue
                why = self.portable(ns, node.name)
                if why:
                    if not why.startswith("duplicate:"):     # build() lists those with what was kept
                        self.log["left out: " + why].append(node.name)
                    continue
                if kd in ("vehicle", "weapon", "accessory") and \
                        w.asset_state(text(w.value(ns, node.name, "model")), (".p3d",)) != "mod":
                    # User, 2026-09-13: "you were not supose to import any vechicle that had a base
                    # game p3d", then "no vechicles no weapons, vests uniforms and headgear are ok".
                    # A vehicle or weapon comes in only on a model the import brings in; a new paint
                    # on a base-game model stays out. Vests, uniforms and headgear keep those.
                    self.log["left out: a %s on a base-game model" % ("vehicle" if kd == "vehicle" else "weapon")].append(node.name)
                    continue
                if only is not None and kd not in only:
                    continue
                out.append((ns, node.name, KIND_ADDON[kd], kd))
        out.sort(key=lambda r: ORDER.index(r[2]))
        return out

    # -- references
    def values(self, node, path=()):
        """(key, scalar, path) for every value under node, arrays flattened."""
        def flat(v):
            if isinstance(v, list):
                for x in v:
                    yield from flat(x)
            elif isinstance(v, tuple):
                yield v
        for k, (key, op, val, pbo) in node.props.items():
            for sv in flat(val):
                yield k, sv, path
        for kid in node.kids.values():
            if not kid.decl:
                yield from self.values(kid, path + (kid.name.lower(),))

    def lookup(self, key, token):
        """The table a token names, when it names a new class in the sources."""
        t = token.strip().lower()
        cands = self.index.get(t)
        if not cands or key in NOT_REFS:
            return None
        if len(cands) == 1:
            return cands[0]
        hint = KEY_NS.get(key)
        return hint if hint in cands else cands[0]

    def decide(self, ctx, key, tns, tname):
        """pull, crew, gear or drop - what a reference from a ctx class does to its target."""
        w = self.w
        if SEEDS and ctx == "man" and tns != ("cfgfactionclasses",):
            # a faction's soldier stands on this one: its kit comes too, or the man is left bare
            if tns == ("cfgvehicles",) and w.kind(tns, tname) == "man" and key in CREW_KEYS:
                return "crew"
            if tns == ("cfgweapons",) and w.kind(tns, tname) in GEAR:
                return "gear"
            return "pull"
        if tns == ("cfgvehicles",):
            tk = w.kind(tns, tname)
            if tk == "man":
                if key in CREW_KEYS:
                    return "crew"
                return "pull" if key == "uniformclass" else "drop"
            if tk == "holder" or key == "backpack":
                return "drop"                    # a backpack in a vehicle's cargo: backpacks were not asked for
            return "pull" if ctx in ("vehicle", "dep") else "drop"
        if tns == ("cfgweapons",):
            tk = w.kind(tns, tname)
            if tk == "accessory" and ctx in ("weapon", "dep") and key == "item":
                return "pull"                    # the optic an imported rifle comes fitted with, whatever its model
            if tk == "weapon" and num(w.value(tns, tname, "type")) not in (1, 2, 4):
                # a vehicle's launcher (type 65536): the Vikhr, Vorona and AGM-154 launchers are
                # children of LauncherCore like a soldier's, but only a pylon or a turret carries
                # one - left to roots(), which skips vehicle guns, a pylon rack named nothing
                return "pull" if ctx in ("vehicle", "dep") else "drop"
            if tk in GEAR:
                return "gear"                    # ported as a root when it can be; never pulled
            if w.item_type(tname) is not None:
                return "drop"                    # NVGs, radios, binoculars: not asked for
            return "pull" if ctx in ("vehicle", "dep", "weapon") else "drop"
        if tns == ("cfgglasses",):
            return "drop"
        if tns == ("cfgfactionclasses",):
            # user, 2026-09-13: the mods' factions are not imported - every imported vehicle and
            # soldier goes under jmfsb_blue, jmfsb_red or jmfsb_green by side (emit.JMFSB_FACTIONS)
            return "drop"
        if tns == ("cfgmagazines",):
            return "drop" if ctx == "man" else "pull"
        return "pull"

    def add(self, ns, name, addon, why):
        key = (ns, name.lower())
        if key in self.items:
            return self.items[key]
        addon = OWN_ADDON_NS.get(ns, addon)
        it = {"ns": ns, "name": name, "addon": addon, "why": why}
        self.items[key] = it
        self.queue.append(it)
        return it

    def build(self):
        w = self.w
        for _round in range(30):
            self.log = collections.defaultdict(list)
            self.items = collections.OrderedDict()
            self.queue = collections.deque()
            self.crew = collections.Counter()
            self.assets = {}
            self.missing_assets = collections.Counter()
            for ns, name, addon, kd in self.roots():
                self.add(ns, name, addon, "root:" + kd)
            while self.queue:
                self.expand(self.queue.popleft())
            # A class whose parent could not come in cannot come in either - and neither can
            # what only it pulled. Block, and go round again until nothing changes.
            changed = False
            for key, it in list(self.items.items()):
                ns, name = it["ns"], it["name"]
                if self.portable(ns, name):
                    continue
                for ans, anc in w.ancestry_ns(ns, name)[0][1:]:
                    if w.is_new(ans, anc) and self.portable(ans, anc):
                        self.blocked[key] = "parent %s cannot come in (%s)" % (anc, self.blocked[(ans, anc.lower())])
                        changed = True
                        break
            if not changed:
                changed = self.dedupe()
            if not changed:
                break
        for key, it in self.items.items():
            if key in self.blocked:
                self.log["left out: " + self.blocked[key].split(" (")[0]].append(it["name"])
        for key, (why, name, kept) in self.dupes.items():
            self.log["left out: " + why].append("%s (the same as %s)" % (name, kept))
        if self.log_reparent:
            self.log["moved onto the copy kept (same model)"] = sorted(set(self.log_reparent))
        self.items = collections.OrderedDict((k, v) for k, v in self.items.items() if k not in self.blocked)

    def model_of(self, ns, name):
        w = self.w
        if ns == ("cfgweapons",) and w.kind(ns, name) == "uniform":
            uc = w.uniform_class(name)
            return text(w.value(("cfgvehicles",), uc, "model")).lower() if uc else ""
        return text(w.value(ns, name, "model")).lower()

    def ws_armed(self, ns, name):
        """A vehicle whose turret still fires Western Sahara's weapons: the nearest weapons[] one of
        its turrets inherits names that DLC's classes. The 2S90M cannon variants take their 30 mm
        autocannon and Vorona launcher from the base turret, and without the DLC they would be left
        with a coaxial machine gun; the v2 and export variants replace that turret and stay."""
        w = self.w
        nearest = {}

        def walk(turrets, path):
            for k, kid in turrets.kids.items():
                if kid.decl:
                    continue
                p = path + (k,)
                if "weapons" in kid.props and p not in nearest:
                    v = kid.props["weapons"][2]
                    nearest[p] = any(isinstance(x, tuple) and "lxws" in x[1].lower()
                                     for x in (v if isinstance(v, list) else [v]))
                inner = kid.kids.get("turrets")
                if inner is not None and not inner.decl:
                    walk(inner, p)
        for cns, cls in w.ancestry_ns(ns, name)[0]:
            if not w.is_new(cns, cls):
                break
            tur = w.snode(cns, cls).kids.get("turrets")
            if tur is not None and not tur.decl:
                walk(tur, ())
        return any(nearest.values())

    def mod_of(self, ns, name):
        node = self.w.snode(ns, name)
        return node.pbos[0].split("/")[0].lower().replace("a3_", "") if node is not None and node.pbos else ""

    def dedupe(self):
        """Classes that would come in under one jmfsb name. When the mods renamed a class they kept
        the old name as an alias for old missions, and Atlas remakes some of Aegis's items; with
        the prefix off, both land on one name. An alias goes, a hidden copy beside a public one
        goes, and where two mods make the same thing Aegis's stays (user, 2026-09-13: "Keep
        Aegis's version"). A copy that other imported classes are built on stays, or they would
        go with it. References to a dropped copy are turned to the one kept (self.twin)."""
        w = self.w
        groups = collections.defaultdict(list)
        for it in self.items.values():
            if it["ns"] != ("cfgnonaivehicles",):
                groups[(it["addon"], it["ns"], (STRIP.sub("", it["name"]) or it["name"]).lower())].append(it)
        children = collections.Counter()
        for it in self.items.values():
            node = w.snode(it["ns"], it["name"])
            if node is not None and node.parent:
                children[(it["ns"], node.parent.lower())] += 1
        changed = False
        for (addon, ns, short), members in groups.items():
            own = self.own_defs[addon].get(short)
            if own is not None:
                # jmfsb already makes this item under this name - the unit's own version wins, and
                # anything that names the imported one is pointed at jmfsb's
                for m in members:
                    key = (ns, m["name"].lower())
                    if children[key]:
                        continue
                    self.blocked[key] = "duplicate: jmfsb has its own class of this name"
                    self.twin[key] = ("own", addon, own)
                    self.dupes[key] = (self.blocked[key], m["name"], "jmfsb_%s_%s" % (addon, own))
                    changed = True
                continue
            if len(members) < 2:
                continue
            lows = {m["name"].lower() for m in members}

            def rank(m):
                node = w.snode(ns, m["name"])
                alias = node.parent.lower() in lows and node.parent.lower() != m["name"].lower()
                hidden = num(w.value(ns, m["name"], "scope")) != 2
                return (alias, hidden, MOD_ORDER.get(self.mod_of(ns, m["name"]), 3), 0 if STRIP.match(m["name"]) else 1)
            ordered = sorted(members, key=rank)
            keep = ordered[0]
            for m in ordered[1:]:
                key = (ns, m["name"].lower())
                if children[key]:
                    # Other classes are built on this copy. When the copy kept is the same model,
                    # they move onto it - Atlas's own paint variants of an AAF MRAP sit on Aegis's
                    # MRAP just as well - and keep their own textures. Otherwise they need this one.
                    if self.model_of(ns, m["name"]) != self.model_of(ns, keep["name"]):
                        continue
                    for it in self.items.values():
                        node = w.snode(it["ns"], it["name"])
                        if it["ns"] == ns and node is not None and node.parent.lower() == m["name"].lower():
                            node.parent = keep["name"]
                            self.log_reparent.append("%s: %s -> %s" % (it["name"], m["name"], keep["name"]))
                node = w.snode(ns, m["name"])
                if node.parent.lower() in lows:
                    why = "duplicate: an old name the mods kept for old missions"
                elif num(w.value(ns, m["name"], "scope")) != 2 and num(w.value(ns, keep["name"], "scope")) == 2:
                    why = "duplicate: a hidden copy of a public class"
                elif self.mod_of(ns, keep["name"]) != self.mod_of(ns, m["name"]):
                    why = "duplicate: made by two mods, %s's copy kept" % self.mod_of(ns, keep["name"]).capitalize()
                else:
                    why = "duplicate: a second copy"
                self.blocked[key] = why
                self.twin[key] = (ns, keep["name"].lower())
                self.dupes[key] = (why, m["name"], keep["name"])
                changed = True
        return changed

    def ctx_of(self, it):
        if it["why"].startswith("root:"):
            return it["why"][5:]
        if it["ns"] == ("cfgvehicles",) and self.w.kind(it["ns"], it["name"]) == "man":
            return "man"
        return "dep"

    def expand(self, it):
        w = self.w
        ns, name, addon = it["ns"], it["name"], it["addon"]
        node = w.snode(ns, name)
        ctx = self.ctx_of(it)
        for ans, anc in w.ancestry_ns(ns, name)[0][1:]:
            if w.is_new(ans, anc):
                self.add(ans, anc, addon, "parent of " + name)
        # nested classes whose parent is a class at the table or config root: `ItemInfo: VestItem`,
        # `MuzzleSlot: asdg_MuzzleSlot_556`, `Single: Mode_SemiAuto`
        def nested(n, scope_names):
            for kid in n.kids.values():
                if kid.parent and kid.parent.lower() != kid.name.lower() and kid.parent.lower() not in scope_names:
                    for tns in w.SCOPES.get(ns, [ns]) + [()]:
                        if w.is_new(tns, kid.parent):
                            if not self.portable(tns, kid.parent):
                                self.add(tns, kid.parent, addon, "nested parent in " + name)
                            break
                if not kid.decl:
                    nested(kid, scope_names | set(kid.kids))
        nested(node, set(node.kids))
        for key, (kind, tok), path in self.values(node):
            if kind not in ("s", "b"):
                continue
            self.scan_assets(tok, addon, key)
            tns = self.lookup(key, tok)
            if tns is None or (tns == ns and tok.strip().lower() == name.lower()):
                continue
            target = tok.strip()
            if (tns, target.lower()) in self.twin:
                # a duplicate that was dropped: the reference goes to the copy that stayed
                tw = self.twin[(tns, target.lower())]
                if tw[0] == "own":
                    continue                             # jmfsb's own class: nothing to pull
                tns, lo = tw
                target = w.snode(tns, lo).name
            act = self.decide(ctx, key, tns, target)
            if act == "pull" and not self.portable(tns, target):
                to = addon
                if SEEDS and (ctx == "man" or addon == "uniform") and tns in (("cfgmagazines",), ("cfgammo",)):
                    # a soldier's magazines go beside the weapons, or uniform and weapons each
                    # build on the other's magazines and require each other
                    to = "weapons"
                self.add(tns, target, to, "%s of %s" % (key, name))
            elif act == "gear" and SEEDS and ctx == "man" and not self.portable(tns, target):
                tk = w.kind(tns, target)
                self.add(tns, target, KIND_ADDON[tk], "root:" + tk)
            elif act == "crew":
                self.crew[tok.strip()] += 1
        # a move or gesture comes with the action arrays that play it
        if ns in (("cfggesturesmale", "states"), ("cfgmovesmalesdr", "states")):
            acts = w.R.get("CfgMovesBasic", "Actions")
            for anode in (acts.kids.values() if acts is not None else ()):
                p = anode.props.get(name.lower())
                if p is None:
                    continue
                for v in (p[2] if isinstance(p[2], list) else [p[2]]):
                    if isinstance(v, tuple):
                        t = v[1].strip()
                        tns = self.lookup("", t)
                        if tns in (("cfggesturesmale", "states"), ("cfgmovesmalesdr", "states")) and not self.portable(tns, t):
                            self.add(tns, t, addon, "action array for " + name)

    # -- assets
    PATH = re.compile(r"(?i)\\?a3_(?:aegis|atlas|opf)\\[^\"';,\]\[{}\r\n]+")

    def scan_assets(self, tok, addon, key):
        for m in self.PATH.finditer(tok):
            p = m.group(0).strip()
            exts = (".p3d",) if key in ("model", "modeloptics", "uimodel") else (".wss", ".ogg", ".wav", ".paa", ".p3d", ".rtm", ".jpg")
            real = self.w.resolve_src(p, exts)
            if real is None:
                self.missing_assets[p.lower()] += 1
                continue
            self.assets.setdefault(real, addon)


def plan_summary(p):
    by = collections.Counter((it["addon"], "/".join(it["ns"]) if it["ns"] else "(root)", "root" if it["why"].startswith("root:") else "dependency") for it in p.items.values())
    print("\n%-10s %-30s %-12s %6s" % ("addon", "table", "", "classes"))
    for (a, t, why), n in sorted(by.items()):
        print("%-10s %-30s %-12s %6d" % (a, t, why, n))
    print("\nroots by kind:", dict(collections.Counter(it["why"] for it in p.items.values() if it["why"].startswith("root:"))))
    print("crews replaced (distinct):", len(p.crew))
    print("assets named directly: %d files; references that point at nothing in the sources: %d" % (len(p.assets), len(p.missing_assets)))
    for k, v in sorted(p.log.items(), key=lambda kv: -len(kv[1])):
        print("  %-70s %5d  e.g. %s" % (k, len(v), ", ".join(v[:3])))


def main():
    w = World()
    if "--census" in sys.argv:
        census(w)
        return
    p = Plan(w)
    p.build()
    if "--plan" in sys.argv:
        plan_summary(p)
        return
    import emit
    emit.SEEDS = SEEDS
    emit.FULL = getattr(p, "full_root_names", set())
    # --configs-only rewrites the configs and leaves models/ as the last run copied it: for
    # iterating on the generated text without copying the assets again
    emit.run(w, p, dry="--dry" in sys.argv, configs_only="--configs-only" in sys.argv)


if __name__ == "__main__":
    main()
