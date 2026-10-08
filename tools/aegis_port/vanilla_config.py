"""The base game's config, read straight out of the installed PBOs.

    python tools/aegis_port/vanilla_config.py

Writes tools/aegis_port/vanilla_config.cache (a pickle, ignored by git as *.cache):

  tree      every root class the port can need - CfgVehicles, CfgWeapons, CfgAmmo, the moves and
            gestures, the sound sets, the weapon modes and slots at the root - as a merged tree of
            {name, parent, a few values, children}. Merged the way the engine merges: a class that
            several PBOs write is one class holding what all of them wrote.
  includes  the text of every .h/.hpp/.hh/.inc the game ships, by game path, so a source config
            that includes one of the game's headers can be preprocessed without a P: drive.
  files     every model, texture, material, sound and animation the game ships, by game path, so
            the port can tell a base-game reference that resolves from one that needs a DLC.
  cba       the (root, class) pairs only CBA defines. jmfsb requires CBA, so they count as
            available; the port adds cba_jr to requiredAddons when it inherits one.
  patches   every CfgPatches name, with the PBO that defines it.

WHY NOT THE OLD vanilla_classes.json. That was a flat list of names, and a name is not enough: the
port has to know a class's parent to write its declaration, its side to pick a crew, and whether a
nested `class Turrets: Turrets` has anything to inherit.

Only .pbo is read. Creator DLC ships encrypted .ebo, which nothing outside the game can open; the
port recognises those classes by what they fail to resolve against and does not port anything
built on them.
"""
import io, os, re, sys, struct, pickle, time

A3 = r"E:/SteamLibrary/steamapps/common/Arma 3"
CBA = r"E:/SteamLibrary/steamapps/workshop/content/107410/450814997/addons"
# The folders the base game and Bohemia's own DLC install into. Not !Workshop, not @mods.
# Not Contact either: that folder loads only when the Contact DLC is switched on in the launcher
# (Livonia and its kit are Enoch, which always loads). Counting it as the base game let Aegis's
# 25x40mm ammo pass for the game's own, so the XM25's magazines named ammo nothing loaded.
FOLDERS = ["Dta", "Addons", "Curator", "Kart", "Heli", "Mark", "Expansion", "Jets", "Argo",
           "Orange", "Tacops", "Tank", "Enoch", "AoW"]
OUT = os.path.join(os.path.dirname(os.path.abspath(__file__)), "vanilla_config.cache")
ASSET_EXT = (".p3d", ".paa", ".rvmat", ".wss", ".ogg", ".wav", ".rtm", ".jpg", ".sqf", ".fsm", ".bisurf")

# Roots that cost memory and that no weapon, vehicle or piece of gear can name.
SKIP_ROOTS = {r.lower() for r in (
    "CfgWorlds", "CfgWorldList", "CfgGroups", "CfgMissions", "CfgHints", "CfgORBAT", "CfgSentences",
    "CfgUIGrids", "CfgInGameUI", "CfgDiary", "CfgLocationTypes", "CfgTaskTypes", "CfgVoice",
    "CfgIdentities", "CfgFaces", "CfgHeads", "CfgMusic", "CfgRadio", "CfgSurfaces",
    "CfgSurfaceCharacters", "CfgEnvSounds", "CfgCommunicationMenu", "CfgNotifications",
    "CfgMPGameTypes", "CfgDebriefing", "CfgRespawnTemplates", "CfgDifficultyPresets",
    "CfgScriptPaths", "CfgFunctions", "CfgCredits", "CfgDLCs", "CfgMods", "CfgLanguages",
    "CfgVoiceMask", "CfgChainOfCommand", "CfgCoreData", "CfgTimeTrials", "CfgHelp",
    "CfgAddons", "CfgEditorPreviews", "CfgMarkerColors", "CfgCommands", "CfgDisabledCommands",
    "CfgRemoteExec", "CfgLeaderboards", "CfgAchievements", "CfgStats", "CfgMainMenuSpotlight",
    "CfgFirstAid", "CfgSimpleTasks", "CfgTutorials", "CfgFieldManuals",
    "CfgCampaigns", "CfgVideoOptions", "CfgDefaultKeysPresets", "CfgUserActions",
    "CfgKeyMapping", "CfgActions", "CfgWrapperUI", "CfgEditorCamera", "Cfg3DEN",
)}
KEEP_MOVES = {"cfgmovesbasic", "cfgmovesmalesdr", "cfggesturesmale"}

# Values worth keeping. The port reads scope, side, faction and friends off base-game parents;
# everything else only needs the class structure.
KEEP_VALUES = {k.lower() for k in (
    "scope", "scopeCurator", "scopeArsenal", "side", "faction", "crew", "simulation", "model",
    "displayName", "vehicleClass", "editorCategory", "editorSubcategory", "uniformClass", "type",
    "author", "picture", "icon", "file", "actions", "gunnerType", "isMan", "isUAV",
)}


def lzss(src, outlen):
    """The PBO flavour of LZSS: 8 flag bits per group, a set bit is a literal byte."""
    out = bytearray(); i = 0; n = len(src)
    while len(out) < outlen and i < n:
        flags = src[i]; i += 1
        for bit in range(8):
            if len(out) >= outlen or i >= n: break
            if flags & (1 << bit):
                out.append(src[i]); i += 1
            else:
                b1, b2 = src[i], src[i + 1]; i += 2
                rpos = len(out) - (b1 | ((b2 & 0xF0) << 4))
                for k in range((b2 & 0x0F) + 3):
                    out.append(out[rpos + k] if rpos + k >= 0 else 0x20)
    return bytes(out)


def pbo_index(path):
    """(properties, [[name, packing, original_size, offset, size]]) - reads only the header."""
    with open(path, "rb") as fh:
        buf = b""; pos = 0; props = {}; entries = []
        def need(k):
            nonlocal buf
            while len(buf) < pos + k:
                chunk = fh.read(1 << 20)
                if not chunk: raise EOFError(path)
                buf += chunk
        def cstr():
            nonlocal pos
            while True:
                e = buf.find(b"\0", pos)
                if e >= 0: break
                need(len(buf) - pos + 1)
            s = buf[pos:e].decode("latin1"); pos = e + 1; return s
        while True:
            name = cstr(); need(20)
            packing, orig, _res, _ts, size = struct.unpack_from("<5I", buf, pos); pos += 20
            if name == "" and packing == 0x56657273:          # 'sreV': the properties block
                while True:
                    k = cstr()
                    if k == "": break
                    props[k.lower()] = cstr()
                continue
            if name == "": break
            entries.append([name, packing, orig, 0, size])
        off = pos
        for e in entries:
            e[3] = off; off += e[4]
    return props, entries


def pbo_read(path, entry):
    name, packing, orig, off, size = entry
    with open(path, "rb") as fh:
        fh.seek(off); data = fh.read(size)
    if packing == 0x43707273 or (orig and orig != size):
        data = lzss(data, orig)
    return data


# ---------------------------------------------------------------- the merged tree
class N:
    # b: the class was given a body somewhere. A class only ever declared (`class Turrets;` inside
    # a vehicle) is a member inherited from above; restating it with a body and no parent would cut
    # it off from that parent, so the port has to be able to tell the two apart.
    __slots__ = ("n", "p", "v", "c", "b")
    def __init__(self, name):
        self.n = name; self.p = ""; self.v = {}; self.c = {}; self.b = False


def child(node, name):
    k = name.lower()
    c = node.c.get(k)
    if c is None:
        c = node.c[k] = N(name)
    return c


class Rap:
    """A rapified config.bin, walked straight into the merged tree."""
    def __init__(self, b):
        self.b = b

    def cstr(self, p):
        e = self.b.index(b"\0", p)
        return self.b[p:e].decode("utf-8", "replace"), e + 1

    def cint(self, p):
        v = 0; s = 0
        while True:
            c = self.b[p]; p += 1
            v |= (c & 0x7F) << s
            if not c & 0x80: return v, p
            s += 7

    def arr(self, p):
        n, p = self.cint(p); out = []
        for _ in range(n):
            t = self.b[p]; p += 1
            if t in (0, 4): v, p = self.cstr(p)
            elif t == 1: v = struct.unpack_from("<f", self.b, p)[0]; p += 4
            elif t == 2: v = struct.unpack_from("<i", self.b, p)[0]; p += 4
            elif t == 3: v, p = self.arr(p)
            elif t == 6: v = struct.unpack_from("<q", self.b, p)[0]; p += 8
            else: raise ValueError("array element type %d" % t)
            out.append(v)
        return out, p

    def body(self, off, node, depth, path):
        parent, p = self.cstr(off)
        if parent: node.p = parent
        n, p = self.cint(p)
        for _ in range(n):
            t = self.b[p]; p += 1
            if t == 0:
                name, p = self.cstr(p)
                o = struct.unpack_from("<I", self.b, p)[0]; p += 4
                if depth == 0:
                    lo = name.lower()
                    if lo in SKIP_ROOTS or lo.startswith(("rsc", "display", "ctrl")): continue
                    if lo.startswith(("cfgmoves", "cfggestures")) and lo not in KEEP_MOVES: continue
                c = child(node, name)
                c.b = True
                # the spelling a class is defined with, not the first declaration seen: the game
                # writes `class default;` in one place and `class Default {` in another, and HEMTT
                # holds every parent to the case of its definition
                c.n = name
                self.body(o, c, depth + 1, path)
            elif t == 1:
                st = self.b[p]; p += 1
                name, p = self.cstr(p)
                if st in (0, 3, 4): v, p = self.cstr(p)
                elif st == 1: v = struct.unpack_from("<f", self.b, p)[0]; p += 4
                elif st == 2: v = struct.unpack_from("<i", self.b, p)[0]; p += 4
                elif st == 6: v = struct.unpack_from("<q", self.b, p)[0]; p += 8
                else: raise ValueError("value subtype %d in %s" % (st, path))
                if depth <= 3 and name.lower() in KEEP_VALUES: node.v[name.lower()] = v
            elif t == 2:
                name, p = self.cstr(p)
                v, p = self.arr(p)
                # magazineWell and every *Magazines / *mags array: a weapon's own and inherited ammo,
                # and what each CfgMagazineWells well holds (BI_mags[], CBA_Magazines[] ...) - what a
                # replacement weapon fires, so a soldier's magazines can follow it
                lo = name.lower()
                if depth <= 3 and (lo in ("hiddenselections", "hiddenselectionstextures", "typicalcargo", "weapons", "magazinewell")
                                   or lo.endswith(("magazines", "mags"))):
                    node.v[lo] = v
            elif t == 3:
                name, p = self.cstr(p)
                if depth > 0: child(node, name)                # an extern: the name exists here
            elif t == 4:
                name, p = self.cstr(p)
            elif t == 5:
                p += 4
                name, p = self.cstr(p)
                v, p = self.arr(p)
            else:
                raise ValueError("entry type %d in %s" % (t, path))

    def load(self, root, path):
        if self.b[:4] != b"\0raP": raise ValueError("not rapified: %s" % path)
        self.body(16, root, 0, path)


def main():
    t0 = time.time()
    pbos = []
    for f in FOLDERS:
        for r, _d, fs in os.walk(os.path.join(A3, f)):
            pbos += [os.path.join(r, x) for x in fs if x.lower().endswith(".pbo")]
    pbos.sort()
    # CBA last: jmfsb requires it, so its classes (the asdg_ rail slots the sources' weapons
    # inherit) are as available as the game's own. Recorded separately so the port can require it.
    cba = sorted(os.path.join(CBA, x) for x in os.listdir(CBA) if x.lower().endswith(".pbo")) if os.path.isdir(CBA) else []
    root = N("")
    includes, patches, files, bad = {}, {}, set(), []
    before_cba = None
    for i, path in enumerate(pbos + cba):
        if cba and path == cba[0]:
            before_cba = {rk: set(rn.c) for rk, rn in root.c.items()}
        try:
            props, entries = pbo_index(path)
        except Exception as e:
            bad.append("%s: %s" % (path, e)); continue
        prefix = props.get("prefix", "").strip("\\").lower()
        label = "CBA" if path in cba else os.path.relpath(path, A3)
        for e in entries:
            lo = e[0].lower().replace("/", "\\")
            full = (prefix + "\\" + lo) if prefix else lo
            unpacked = e[2] if e[2] else e[4]
            if lo.endswith("config.bin"):
                try:
                    data = pbo_read(path, e)
                    before = set(root.c["cfgpatches"].c) if "cfgpatches" in root.c else set()
                    Rap(data).load(root, "%s:%s" % (os.path.basename(path), e[0]))
                    for pn in set(root.c["cfgpatches"].c) - before if "cfgpatches" in root.c else ():
                        patches[pn] = label
                except Exception as ex:
                    bad.append("%s:%s: %s" % (os.path.basename(path), e[0], ex))
            elif lo.endswith((".h", ".hpp", ".hh", ".inc")) and unpacked < 2_000_000:
                try:
                    includes[full] = pbo_read(path, e).decode("utf-8", "replace")
                except Exception as ex:
                    bad.append("%s:%s: %s" % (os.path.basename(path), e[0], ex))
            elif lo.endswith(ASSET_EXT):
                files.add(full)
        if i % 100 == 0:
            print("[%5.1fs] %d/%d %s" % (time.time() - t0, i, len(pbos) + len(cba), os.path.basename(path)), flush=True)
    cba_classes = set()
    if before_cba is not None:
        for rk, rn in root.c.items():
            for k in set(rn.c) - before_cba.get(rk, set()):
                cba_classes.add((rk, k))
    counts = {k: len(v.c) for k, v in sorted(root.c.items()) if len(v.c) > 500}
    print("roots: %d  big ones: %s" % (len(root.c), counts))
    print("includes: %d  files: %d  patches: %d  cba classes: %d  problems: %d"
          % (len(includes), len(files), len(patches), len(cba_classes), len(bad)))
    for b in bad[:10]: print("  !", b)
    with open(OUT, "wb") as fh:
        pickle.dump({"tree": root, "includes": includes, "patches": patches, "files": files, "cba": cba_classes},
                    fh, protocol=pickle.HIGHEST_PROTOCOL)
    print("[%5.1fs] wrote %s (%.0f MB)" % (time.time() - t0, OUT, os.path.getsize(OUT) / 1e6))


if __name__ == "__main__":
    # Run through the module, not __main__: the pickle names the node class by module, and
    # port.py has to be able to import it back.
    sys.setrecursionlimit(20000)
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    import vanilla_config
    vanilla_config.main()
