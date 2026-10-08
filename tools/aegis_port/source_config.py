"""The Aegis, Atlas and OpF sources, preprocessed and parsed the way the game loads them.

    import source_config
    src = source_config.load(vanilla_includes)

Every config.cpp under the sources is one addon (one PBO). Each is preprocessed - #include,
#define with and without arguments, # and ##, #ifdef - parsed into its own class tree, and the
trees are merged in load order into the one config the game builds when the mods are loaded.

WHY A REAL PREPROCESSOR. The sources build their item holders out of token-pasting macros
(`class Weapon_##a##: Weapon_Base_F`, `magazine = ##mag##;`) and write scope, side and slot
numbers as names (`scope = public;`). The earlier port matched the raw text with regular
expressions; every class written through a macro was invisible to it, and every value written as
a name had to be guessed at. Expanding first means the tree holds what the game holds.

WHAT IS NOT LOADED. An addon whose requiredAddons names a patch that neither the base game nor the
sources define needs a creator DLC (Reaction Forces, Western Sahara, ...). It is left out entirely,
so nothing it adds to a class leaks into the port.

Values keep their kind, so they can be written back faithfully:
  ("s", text)   a quoted string, text as written between the quotes ("" still doubled)
  ("n", text)   a number, as written
  ("b", text)   a bare word or expression - $STR_ keys, names, `1 + 16`
  [ ... ]       an array of the above, nested
"""
import collections
import io
import os
import re

SRC = r"D:/Git/A3_Aegis_Public_Releases"
MODS = ("A3_Aegis", "A3_Atlas", "A3_OpF")


# ---------------------------------------------------------------- the tree
class C:
    __slots__ = ("name", "parent", "props", "kids", "decl", "pbos", "files")

    def __init__(self, name):
        self.name = name
        self.parent = ""        # as last written with a body; "" is no parent
        self.props = {}         # lower key -> (key, op, value, pbo); op is "=", "[]=" or "[]+="
        self.kids = {}          # lower name -> C, in the order first seen
        self.decl = True        # only ever declared (class X;), never given a body
        self.pbos = []          # the addons that gave it a body, in load order
        self.files = []         # the source files those bodies came from

    def kid(self, name):
        k = name.lower()
        c = self.kids.get(k)
        if c is None:
            c = self.kids[k] = C(name)
        return c

    def get(self, *path):
        n = self
        for p in path:
            n = n.kids.get(p.lower())
            if n is None:
                return None
        return n


def merge(dst, src):
    """Lay src over dst the way a later addon lays over an earlier one."""
    for k, v in src.props.items():
        old = dst.props.get(k)
        if v[1] == "[]+=" and old is not None and old[1] in ("[]=", "[]+=") \
                and isinstance(old[2], list) and isinstance(v[2], list):
            # Two addons adding to one array keep both additions, the way the game builds it: Aegis
            # and Atlas each `magazines[] +=` their own 25mm pylon pod onto gatling_25mm, and letting
            # the later one replace the earlier lost Aegis's pod from the weapon ("wrong 'pylonWeapon'").
            dst.props[k] = (v[0], old[1], old[2] + [x for x in v[2] if x not in old[2]], v[3])
        else:
            dst.props[k] = v
    for k, s in src.kids.items():
        d = dst.kids.get(k)
        if d is None:
            dst.kids[k] = s
            continue
        if not s.decl:
            if d.decl:
                d.name = s.name
            d.decl = False
            d.parent = s.parent
            d.pbos += [p for p in s.pbos if p not in d.pbos]
            d.files += [f for f in s.files if f not in d.files]
        merge(d, s)


# ---------------------------------------------------------------- preprocessor
WORD = re.compile(r"\w+")                   # \w, not [A-Za-z0-9_]: Atlas names people Akchoté
IDENT = re.compile(r"[A-Za-z_][A-Za-z0-9_]*$")
PPTOK = re.compile(r'"(?:[^"\n]|"")*"|##|#|[A-Za-z0-9_]+|\s+|.', re.S)


def strip_comments(t):
    """Comments out, strings left alone - a // inside a URL is not a comment."""
    out = []; i = 0; n = len(t)
    while i < n:
        c = t[i]
        if c == '"':
            j = i + 1
            while j < n:
                if t[j] == '"':
                    if j + 1 < n and t[j + 1] == '"':
                        j += 2; continue
                    break
                if t[j] == "\n":
                    break
                j += 1
            out.append(t[i:j + 1]); i = j + 1
        elif t.startswith("//", i):
            j = t.find("\n", i)
            i = n if j < 0 else j
        elif t.startswith("/*", i):
            j = t.find("*/", i + 2)
            nl = t.count("\n", i, n if j < 0 else j)
            out.append("\n" * nl)
            i = n if j < 0 else j + 2
        else:
            out.append(c); i += 1
    return "".join(out)


class Preprocessor:
    def __init__(self, file_index, vanilla_includes):
        self.index = file_index                  # lower game path (no leading \) -> real path
        self.vinc = vanilla_includes or {}
        self.defs = {}                           # name -> (params or None, body)
        self.missing = collections.Counter()
        self.seen = []

    # -- includes
    def resolve(self, inc, cur):
        inc = inc.strip().replace("/", "\\")
        if inc.startswith("\\"):
            key = inc.lstrip("\\").lower()
            if key in self.index:
                return ("file", self.index[key])
            if key in self.vinc:
                return ("text", key)
            return None
        p = os.path.normpath(os.path.join(os.path.dirname(cur), inc.replace("\\", os.sep)))
        if os.path.exists(p):
            return ("file", p)
        # a path relative to the mod root, written without its leading backslash
        key = inc.lower()
        if key in self.index:
            return ("file", self.index[key])
        if key in self.vinc:
            return ("text", key)
        return None

    def run(self, path):
        self.defs = {}
        out = []
        self._file(path, out, 0)
        return "".join(out)

    def _file(self, path, out, depth, text=None):
        if depth > 32:
            return
        if text is None:
            self.seen.append(path)
            text = io.open(path, encoding="utf-8-sig", errors="replace").read()
        text = text.replace("\r\n", "\n").replace("\r", "\n")
        text = re.sub(r"\\[ \t]*\n", " ", text)           # line continuations
        text = strip_comments(text)
        stack = []                                          # [active, taken]
        buf = []

        def active():
            return all(a for a, _ in stack)

        def flush():
            if buf:
                out.append(self.expand("".join(buf)))
                buf.clear()

        for line in text.split("\n"):
            s = line.lstrip()
            if not s.startswith("#"):
                if active():
                    buf.append(line + "\n")
                continue
            flush()
            m = re.match(r"#\s*(\w+)\s*(.*)$", s)
            if not m:
                continue
            d, rest = m.group(1), m.group(2)
            if d in ("ifdef", "ifndef"):
                name = rest.split()[0] if rest.split() else ""
                on = (name in self.defs) == (d == "ifdef")
                stack.append([on, on]); continue
            if d == "if":
                on = self.cond(rest)
                stack.append([on, on]); continue
            if d == "elif":
                if stack:
                    on = (not stack[-1][1]) and self.cond(rest)
                    stack[-1] = [on, stack[-1][1] or on]
                continue
            if d == "else":
                if stack:
                    stack[-1] = [not stack[-1][1], True]
                continue
            if d == "endif":
                if stack:
                    stack.pop()
                continue
            if not active():
                continue
            if d == "include":
                im = re.match(r'["<]([^">]+)[">]', rest)
                if not im:
                    continue
                r = self.resolve(im.group(1), path)
                if r is None:
                    self.missing[im.group(1)] += 1
                elif r[0] == "file":
                    self._file(r[1], out, depth + 1)
                else:
                    self._file(r[1], out, depth + 1, text=self.vinc[r[1]])
            elif d == "define":
                dm = re.match(r"([A-Za-z_][A-Za-z0-9_]*)(\(([^)]*)\))?\s?(.*)$", rest)
                if dm:
                    params = None if dm.group(2) is None else [p.strip() for p in dm.group(3).split(",") if p.strip()]
                    self.defs[dm.group(1)] = (params, dm.group(4).strip())
            elif d == "undef":
                self.defs.pop(rest.strip(), None)
        flush()

    def cond(self, expr):
        e = self.expand(expr).strip()
        e = re.sub(r"\bdefined\s*\(?\s*([A-Za-z_]\w*)\s*\)?", lambda m: "1" if m.group(1) in self.defs else "0", e)
        e = re.sub(r"[A-Za-z_]\w*", "0", e).replace("&&", " and ").replace("||", " or ").replace("!", " not ")
        try:
            return bool(eval(e, {"__builtins__": {}}, {}))
        except Exception:
            return False

    # -- expansion
    def expand(self, text, disabled=frozenset()):
        if not self.defs:
            return text
        toks = PPTOK.findall(text)
        out = []; i = 0; n = len(toks)
        while i < n:
            t = toks[i]
            if t in self.defs and t not in disabled and IDENT.match(t):
                params, body = self.defs[t]
                if params is None:
                    out.append(self.expand(body, disabled | {t})); i += 1; continue
                j = i + 1
                while j < n and toks[j].isspace():
                    j += 1
                if j >= n or toks[j] != "(":
                    out.append(t); i += 1; continue
                args, cur, depth, k = [], [], 0, j + 1
                while k < n:
                    x = toks[k]
                    if x == "(":
                        depth += 1
                    elif x == ")":
                        if depth == 0:
                            break
                        depth -= 1
                    elif x == "," and depth == 0:
                        args.append("".join(cur)); cur = []; k += 1; continue
                    cur.append(x); k += 1
                args.append("".join(cur))
                if len(params) == 0 and len(args) == 1 and not args[0].strip():
                    args = []
                out.append(self.expand(self.subst(t, params, body, [a.strip() for a in args], disabled), disabled | {t}))
                i = k + 1
                continue
            out.append(t); i += 1
        return "".join(out)

    def subst(self, name, params, body, args, disabled):
        while len(args) < len(params):
            args.append("")
        pos = {p: k for k, p in enumerate(params)}
        toks = PPTOK.findall(body)
        res = []                                   # (text, is_paste)
        i = 0; n = len(toks)
        # ARMA'S ## IS NOT C'S. In C it glues the tokens either side and eats the space between;
        # in Arma it is a marker that simply disappears. The sources rely on that: HEADGEAR_HOLDER
        # writes `class ##a##`, which Arma reads as `class H_HelmetB` and C would weld into
        # `classH_HelmetB`.
        while i < n:
            t = toks[i]
            if t == "#" and i + 1 < n and toks[i + 1] in pos:
                res.append(('"%s"' % args[pos[toks[i + 1]]], False)); i += 2; continue
            if t in pos:
                raw = (i > 0 and toks[i - 1] == "##") or (i + 1 < n and toks[i + 1] == "##")
                a = args[pos[t]]
                res.append((a if raw else self.expand(a, disabled), False)); i += 1; continue
            if t == "##":
                i += 1; continue
            res.append((t, False)); i += 1
        return "".join(t for t, _ in res)


# ---------------------------------------------------------------- parser
NUM = re.compile(r"^[-+]?(?:\d+\.?\d*|\.\d+)(?:[eE][-+]?\d+)?$|^0x[0-9A-Fa-f]+$")
MATH = re.compile(r"^[\d\s.+\-*/()eE]+$")


def bare(text):
    t = text.strip()
    if NUM.match(t):
        return ("n", t)
    ev = re.match(r"^__EVAL\s*\((.*)\)$", t, re.S)
    if ev:
        t = ev.group(1).strip()
    if MATH.match(t) and re.search(r"\d", t) and re.search(r"[+\-*/]", t.lstrip("+-")):
        try:
            v = eval(t, {"__builtins__": {}}, {})
            if isinstance(v, (int, float)):
                return ("n", repr(v) if isinstance(v, float) else str(v))
        except Exception:
            pass
    return ("b", t)


class ParseError(Exception):
    pass


class Parser:
    def __init__(self, text, pbo, file):
        self.t = text; self.i = 0; self.n = len(text); self.pbo = pbo; self.file = file
        self.errors = []

    def ws(self):
        t, i, n = self.t, self.i, self.n
        while i < n and t[i] in " \t\r\n\f\v":
            i += 1
        self.i = i

    def word(self):
        self.ws()
        m = WORD.match(self.t, self.i)
        if not m:
            return None
        self.i = m.end()
        return m.group(0)

    def expect(self, ch):
        self.ws()
        if self.t.startswith(ch, self.i):
            self.i += len(ch); return True
        return False

    def string(self):
        t, i, n = self.t, self.i + 1, self.n
        j = i
        while j < n:
            if t[j] == '"':
                if j + 1 < n and t[j + 1] == '"':
                    j += 2; continue
                break
            j += 1
        self.i = j + 1
        return t[i:j]

    def raw_until(self, stops):
        t, i, n = self.t, self.i, self.n
        depth = 0; start = i
        while i < n:
            c = t[i]
            if c == '"':
                self.i = i; self.string(); i = self.i; continue
            if c == "(":
                depth += 1
            elif c == ")":
                depth -= 1
            elif depth <= 0 and c in stops:
                break
            i += 1
        self.i = i
        return t[start:i]

    def scalar(self):
        self.ws()
        if self.i < self.n and self.t[self.i] == '"':
            s = self.string()
            rest = self.raw_until(";")
            if rest.strip():
                return ("b", '"%s"%s' % (s, rest))
            return ("s", s)
        return bare(self.raw_until(";"))

    def array(self):
        self.ws()
        if not self.expect("{"):
            # an array written as a single value
            return [self.scalar()]
        out = []
        while True:
            self.ws()
            if self.i >= self.n:
                raise ParseError("unterminated array")
            c = self.t[self.i]
            if c == "}":
                self.i += 1; return out
            if c == ",":
                self.i += 1; continue
            if c == "{":
                out.append(self.array()); continue
            if c == '"':
                s = self.string()
                self.ws()
                if self.i < self.n and self.t[self.i] not in ",}":
                    out.append(("b", '"%s"%s' % (s, self.raw_until(",}"))))
                else:
                    out.append(("s", s))
                continue
            v = self.raw_until(",}")
            if v.strip():
                out.append(bare(v))

    def body(self, node, top):
        while True:
            self.ws()
            if self.i >= self.n:
                if not top:
                    raise ParseError("unexpected end of file")
                return
            c = self.t[self.i]
            if c == "}":
                if top:
                    self.errors.append("stray } at %d" % self.i); self.i += 1; continue
                self.i += 1; self.expect(";"); return
            if c == ";":
                self.i += 1; continue
            start = self.i
            w = self.word()
            if w is None:
                self.errors.append("unexpected %r near %r" % (c, self.t[max(0, self.i - 40):self.i + 40]))
                self.raw_until(";}"); self.expect(";"); continue
            if w == "class":
                name = self.word(); parent = ""
                if self.expect(":"):
                    parent = self.word() or ""
                if self.expect("{"):
                    k = node.kid(name)
                    k.decl = False; k.parent = parent
                    if self.pbo not in k.pbos: k.pbos.append(self.pbo)
                    if self.file not in k.files: k.files.append(self.file)
                    self.body(k, False)
                else:
                    self.expect(";")
                    k = node.kid(name)
                    if parent and k.decl:
                        k.parent = parent
                continue
            if w == "delete":
                self.word(); self.expect(";"); continue
            if w in ("enum", "__EXEC"):
                self.raw_until("{;")
                if self.expect("{"):
                    depth = 1
                    while self.i < self.n and depth:
                        depth += {"{": 1, "}": -1}.get(self.t[self.i], 0); self.i += 1
                self.expect(";"); continue
            self.ws()
            if self.t.startswith("[", self.i):
                self.expect("["); self.expect("]")
                op = "[]+=" if self.expect("+=") else ("[]=" if self.expect("=") else None)
                if op is None:
                    self.errors.append("array without = : %s" % w); self.raw_until(";"); self.expect(";"); continue
                node.props[w.lower()] = (w, op, self.array(), self.pbo)
                self.expect(";"); continue
            if self.expect("="):
                node.props[w.lower()] = (w, "=", self.scalar(), self.pbo)
                self.expect(";"); continue
            self.errors.append("cannot read %r near %r" % (w, self.t[start:start + 80]))
            self.raw_until(";}"); self.expect(";")


# ---------------------------------------------------------------- loading
def file_index():
    idx = {}
    for mod in MODS:
        base = os.path.join(SRC, mod)
        for r, dirs, files in os.walk(base):
            dirs[:] = [d for d in dirs if d != ".git"]
            for f in files:
                real = os.path.join(r, f)
                idx[os.path.relpath(real, SRC).replace("/", "\\").lower()] = real
    return idx


def load(vanilla_includes=None, vanilla_patches=()):
    idx = file_index()
    pp = Preprocessor(idx, vanilla_includes)
    addons = []                                    # dicts: pbo, path, tree, patches, requires, errors
    for key, real in sorted(idx.items()):
        if not key.endswith("\\config.cpp"):
            continue
        pbo = os.path.dirname(os.path.relpath(real, SRC)).replace("\\", "/")
        text = pp.run(real)
        p = Parser(text, pbo, os.path.relpath(real, SRC).replace("\\", "/"))
        tree = C("")
        try:
            p.body(tree, True)
        except ParseError as e:
            p.errors.append(str(e))
        patches = [k for k in tree.get("CfgPatches").kids] if tree.get("CfgPatches") else []
        req = []
        for pk in patches:
            v = tree.get("CfgPatches", pk).props.get("requiredaddons")
            if v and isinstance(v[2], list):
                req += [x[1].lower() for x in v[2] if isinstance(x, tuple)]
        addons.append({"pbo": pbo, "path": real, "tree": tree, "patches": patches, "requires": req, "errors": p.errors})

    # Which addons need a creator DLC: they themselves require a patch that neither the base game
    # nor the sources define. Not transitive - the mods' load-order addon lists the DLC patches
    # too, so that it loads after them when they are there, and following that chain would mark
    # every addon in the mod.
    known = {p.lower() for p in vanilla_patches}
    ours = {pk: a for a in addons for pk in a["patches"]}
    # CBA is not a creator DLC: jmfsb requires it, so CBA's joint-rail patches are always there.
    # Treating them as missing dropped Aegis's whole weapons and characters addons.
    known |= {r for a in addons for r in a["requires"] if r.startswith("cba_")}
    # A requirement nobody defines only matters when the addon also sets
    # skipWhenMissingDependencies - the Reaction Forces, Expeditionary Forces and FIR compat
    # addons all do. The main addons (weapons_f_aegis, characters_f_aegis) list Western Sahara's
    # patches too, but only so they load after it; they work without it, and whatever in them
    # really is built on Western Sahara is caught class by class, when its parent is not found.
    unknown = collections.Counter()
    cdlc = set()
    for a in addons:
        miss = [r for r in a["requires"] if r not in known and r not in ours]
        a["unknown"] = miss
        unknown.update(miss)
        cp = a["tree"].get("CfgPatches")
        skips = cp and any(
            (pn.props.get("skipwhenmissingdependencies") or (0, 0, ("n", "0")))[2][1] not in ("0", "false")
            for pn in cp.kids.values())
        if miss and skips:
            cdlc.add(a["pbo"])

    # Load order: an addon after everything of ours it requires.
    order, placed = [], set()
    pending = [a for a in addons if a["pbo"] not in cdlc]
    while pending:
        progress = False
        for a in list(pending):
            deps = {ours[r]["pbo"] for r in a["requires"] if r in ours} - {a["pbo"]}
            if deps <= placed:
                order.append(a); placed.add(a["pbo"]); pending.remove(a); progress = True
        if not progress:                           # a cycle: take the rest as they come
            order += pending; break

    root = C("")
    for a in order:
        merge(root, a["tree"])
    return {
        "tree": root,
        "addons": order,
        "cdlc": sorted(cdlc),
        "unknown_requires": unknown,
        "all_addons": addons,
        "missing_includes": pp.missing,
        "errors": {a["pbo"]: a["errors"] for a in addons if a["errors"]},
        "index": idx,
    }
