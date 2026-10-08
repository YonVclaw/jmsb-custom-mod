#!/usr/bin/env python
"""Make jmfsb smaller without dropping anything it uses (user, 2026-10-07: "i'm looking for ways to reduce the size
of the mod" - chose: sounds to OGG, 4096 textures to 2048, one copy of each duplicate).

    sounds    every .wss -> .ogg (Vorbis), and every config reference repointed with an explicit .ogg extension.
              The Aegis import brought 311 WSS files, uncompressed 16-bit PCM: ~150 MB.
    textures  every PAA of 4096 or more on a side halved (Lanczos), in its own compression; a 4096 sheet is four
              times a 2048 one, and nothing in jmfsb is seen close enough to show the difference... much.
    dedupe    byte-identical files: one copy kept and every text reference (config, rvmat, script; full path or
              QPATHTOF / QPATHTOEF macro) repointed to it. A copy named inside a model (.p3d) cannot be repointed
              and stays; the kept copy is always in an addon that never skips itself, so nothing ends up pointing
              into a PBO that may not be loaded.

Every file changed or deleted is copied first to BACKUP/<path under addons>. Re-runnable: run after any import that
brings new assets (tools/aegis_port).

    python tools/slim_assets.py sounds|textures|dedupe [--dry]
"""

import hashlib
import os
import re
import shutil
import struct
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ADDONS = os.path.join(ROOT, "addons")
BACKUP = os.path.join(os.path.dirname(ROOT), "_jmfsb_backup_2026-10-07", "slim_assets")
TEXT = re.compile(r"(?i)\.(hpp|cpp|rvmat|sqf|cfg|inc|bisurf|ext|h)$")
BS = chr(92)
DRY = "--dry" in sys.argv
BIG = 4096


def walk(pred):
    for root, _d, fs in os.walk(ADDONS):
        for f in fs:
            p = os.path.join(root, f)
            if pred(p):
                yield p


def backup(p):
    dst = os.path.join(BACKUP, os.path.relpath(p, ADDONS))
    if not os.path.exists(dst):
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        shutil.copy2(p, dst)


def rd(p):
    return open(p, encoding="utf-8", errors="replace", newline="").read()


def wr(p, t):
    backup(p)
    open(p, "w", encoding="utf-8", newline="").write(t)


def rel_parts(p):
    """(addon, path inside the addon with backslashes) of a file under addons/."""
    rel = os.path.relpath(p, ADDONS).replace("/", BS)
    addon, inner = rel.split(BS, 1)
    if addon == "compatibility" and BS in inner:
        sub, inner = inner.split(BS, 1)
        addon = "compatibility" + BS + sub
    return addon, inner


def addon_of(p):
    return rel_parts(p)[0]


def texts():
    return {p: rd(p) for p in walk(lambda p: TEXT.search(p))}


# ---------------------------------------------------------------------------
# sounds
# ---------------------------------------------------------------------------
def sounds():
    wss = list(walk(lambda p: p.lower().endswith(".wss")))
    tx = texts()
    before = sum(os.path.getsize(p) for p in wss)
    after = 0
    changed = set()
    for p in wss:
        addon, inner = rel_parts(p)
        stem = inner[:-4]
        ogg = p[:-4] + ".ogg"
        if not DRY:
            tmp = os.path.join(tempfile.mkdtemp(prefix="slim_"), "o.ogg")
            r = subprocess.run(["hemtt", "utils", "audio", "convert", p, tmp], capture_output=True, text=True)
            if r.returncode or not os.path.exists(tmp) or os.path.getsize(tmp) < 64:
                print("   !! not converted, left as WSS:", os.path.relpath(p, ADDONS), r.stderr.strip()[:120])
                after += os.path.getsize(p)
                continue
            backup(p)
            shutil.move(tmp, ogg)
            os.remove(p)
            after += os.path.getsize(ogg)
        # repoint: a full path (with or without the leading backslash) anywhere, and the addon's own macros
        full = re.compile(r"(?i)(addons" + re.escape(BS) + re.escape(addon) + re.escape(BS) + re.escape(stem) + r")(\.wss)?(?![\w.])")
        local = re.compile(r"(?i)(PATHTOF\(\s*" + re.escape(stem) + r")(\.wss)?(\s*\))")
        foreign = re.compile(r"(?i)(PATHTOEF\(\s*" + re.escape(addon.split(BS)[-1]) + r"\s*,\s*" + re.escape(stem) + r")(\.wss)?(\s*\))")
        for tp, t in tx.items():
            n = full.sub(lambda m: m.group(1) + ".ogg", t)
            if addon_of(tp) == addon:
                n = local.sub(lambda m: m.group(1) + ".ogg" + m.group(3), n)
            n = foreign.sub(lambda m: m.group(1) + ".ogg" + m.group(3), n)
            if n != t:
                tx[tp] = n
                changed.add(tp)
    if not DRY:
        for tp in changed:
            wr(tp, tx[tp])
    print("sounds: %d WSS, %.0f MB -> %.0f MB OGG; %d config file(s) repointed"
          % (len(wss), before / 2**20, after / 2**20, len(changed)))


# ---------------------------------------------------------------------------
# textures
# ---------------------------------------------------------------------------
TAGS = {0xFF01: "DXT1", 0xFF05: "DXT5"}


def paa_info(p):
    with open(p, "rb") as fh:
        b = fh.read(8192)
    kind = TAGS.get(struct.unpack("<H", b[:2])[0], "other")
    i = 2
    while b[i:i + 4] == b"GGAT":
        i += 12 + struct.unpack("<I", b[i + 8:i + 12])[0]
    i += 2
    w, h = struct.unpack("<HH", b[i:i + 4])
    return kind, w & 0x7FFF, h


def textures():
    from PIL import Image
    done = saved = 0
    for p in walk(lambda p: p.lower().endswith(".paa")):
        kind, w, h = paa_info(p)
        if max(w, h) < BIG:
            continue
        if DRY:
            done += 1
            saved += os.path.getsize(p) * 3 // 4
            continue
        d = tempfile.mkdtemp(prefix="slim_")
        src, half, out = os.path.join(d, "a.png"), os.path.join(d, "b.png"), os.path.join(d, "c.paa")
        subprocess.run(["hemtt", "utils", "paa", "convert", p, src], capture_output=True)
        im = Image.open(src)
        im = im.resize((max(1, w // 2), max(1, h // 2)), Image.LANCZOS)
        if kind == "DXT1" and im.mode == "RGBA":
            im = im.convert("RGB")       # a DXT1 sheet has no alpha to keep: the result is DXT1 again
        im.save(half)
        # hemtt never overwrites, so a fresh name, checked, then moved over the original
        r = subprocess.run(["hemtt", "utils", "paa", "convert", half, out], capture_output=True, text=True)
        if r.returncode or not os.path.exists(out):
            print("   !! not halved:", os.path.relpath(p, ADDONS), r.stderr.strip()[:120])
            continue
        nk, nw, nh = paa_info(out)
        if nk != kind and kind in TAGS.values():
            print("   note: %s %s -> %s" % (os.path.relpath(p, ADDONS), kind, nk))
        old = os.path.getsize(p)
        backup(p)
        shutil.move(out, p)
        saved += old - os.path.getsize(p)
        done += 1
    print("textures: %d halved to 2048, %.0f MB saved" % (done, saved / 2**20))


# ---------------------------------------------------------------------------
# dedupe
# ---------------------------------------------------------------------------
def skippable(addon):
    cfg = os.path.join(ADDONS, *addon.split(BS), "config.cpp")
    return not os.path.exists(cfg) or "skipWhenMissingDependencies" in rd(cfg)


def dedupe():
    groups = {}
    for p in walk(lambda p: re.search(r"(?i)\.(paa|ogg|wss|rvmat|p3d|rtm|jpg)$", p) and os.path.getsize(p) >= 16384):
        with open(p, "rb") as fh:
            groups.setdefault((os.path.getsize(p), hashlib.md5(fh.read()).hexdigest()), []).append(p)
    groups = [v for v in groups.values() if len(v) > 1]
    tx = texts()
    p3d = [open(p, "rb").read().lower() for p in walk(lambda p: p.lower().endswith(".p3d"))]

    def in_model(p):
        addon, inner = rel_parts(p)
        key = ("addons" + BS + addon + BS + inner).lower().encode()
        return any(key in b for b in p3d)

    saved = removed = kept_model = 0
    changed = set()
    for g in groups:
        g = sorted(g, key=lambda p: (in_model(p) is False, skippable(addon_of(p)), addon_of(p).startswith("faction"), len(p)))
        keep = g[0]
        if skippable(addon_of(keep)) and len({addon_of(p) for p in g}) > 1:
            continue                        # every copy is in an addon that can skip itself: leave the group alone
        ka, ki = rel_parts(keep)
        for p in g[1:]:
            if in_model(p):
                kept_model += 1
                continue
            a, inner = rel_parts(p)
            full = re.compile(r"(?i)addons" + re.escape(BS) + re.escape(a) + re.escape(BS) + re.escape(inner) + r"(?![\w.])")
            local = re.compile(r"(?i)\b(Q?)PATHTOF\(\s*" + re.escape(inner) + r"\s*\)")
            foreign = re.compile(r"(?i)\b(Q?)PATHTOEF\(\s*" + re.escape(a.split(BS)[-1]) + r"\s*,\s*" + re.escape(inner) + r"\s*\)")
            hits = 0
            for tp, t in tx.items():
                same = addon_of(tp) == ka
                macro = (lambda m: "%sPATHTOF(%s)" % (m.group(1), ki)) if same else \
                    (lambda m: "%sPATHTOEF(%s,%s)" % (m.group(1), ka.split(BS)[-1], ki))
                n = full.sub(lambda m: "addons" + BS + ka + BS + ki, t)
                if addon_of(tp) == a:
                    n = local.sub(macro, n)
                n = foreign.sub(macro, n)
                if n != t:
                    hits += 1
                    tx[tp] = n
                    changed.add(tp)
            if not hits:
                continue                    # named nowhere we can repoint: not ours to delete here
            saved += os.path.getsize(p)
            removed += 1
            if not DRY:
                backup(p)
                os.remove(p)
    if not DRY:
        for tp in changed:
            wr(tp, tx[tp])
    print("dedupe: %d duplicate group(s); %d copies removed, %.0f MB; %d kept (named inside a model); %d config file(s) repointed"
          % (len(groups), removed, saved / 2**20, kept_model, len(changed)))


# ---------------------------------------------------------------------------
# unreferenced
# ---------------------------------------------------------------------------
# media is the user's own art and stays whole (user, 2026-10-07: "do not touch the media addon")
KEEP_ADDONS = {"media"}
ASSET = re.compile(r"(?i)\.(paa|p3d|rvmat|ogg|wss|wav|rtm)$")


def unreferenced():
    """Assets no config, rvmat, model.cfg, script or model names - the folders the Aegis/Atlas import copied whole
    for variants jmfsb never ported, and the textures of weapons since removed (AK-74, FAMAS, SA80).

    A file is kept when its name (with or without extension) appears in any text file or inside any model, or
    when its FOLDER is named anywhere: a script that builds "...\\letter\\%1.paa" names no file at all.
    """
    # every file-name-like token in every text file and model, once: a set lookup per asset, not a scan
    names = set()
    composed = set()
    tok = re.compile(rb"[a-z0-9_.\-]+")
    # an addon README naming a file counts too: a spare an author documents on purpose (hacking's icons/wireless.paa)
    for p in walk(lambda p: TEXT.search(p) or p.lower().endswith((".p3d", ".rtm", ".bikb", ".fsm", ".xml", ".md"))):
        with open(p, "rb") as fh:
            b = fh.read().lower().replace(b"/", BS.encode())
        for t in tok.findall(b):
            names.add(t)
            if b"." in t:
                names.add(t.rsplit(b".", 1)[0])
        if TEXT.search(p):
            # a folder something composes a file name onto: "...\letter\%1.paa", "...\##className##.paa", "dir\" + x
            for m in re.finditer(rb"addons\\([a-z0-9_\\]+?)\\?(?:%\d|##|[\"']\s*\+|\+\s*[\"'])", b):
                composed.add(m.group(1).rstrip(b"\\").decode())
            for m in re.finditer(rb"pathtoe?f\(\s*(?:(\w+)\s*,\s*)?([a-z0-9_\\]+?)\\?(?:%\d|##)", b):
                composed.add(((m.group(1) or rel_parts(p)[0].lower().encode()).decode() + BS + m.group(2).decode()).rstrip(BS))
    dirs_named = {}
    gone, size = [], 0
    for p in walk(lambda p: ASSET.search(p)):
        addon, inner = rel_parts(p)
        if addon.split(BS)[0] in KEEP_ADDONS:
            continue
        base = os.path.basename(p).lower()
        if base.encode() in names or os.path.splitext(base)[0].encode() in names:
            continue
        folder = (addon + BS + os.path.dirname(inner)).lower().rstrip(BS)
        if folder not in dirs_named:
            dirs_named[folder] = any(folder == c or folder.startswith(c + BS) for c in composed)
        if dirs_named[folder]:
            continue
        gone.append(p)
        size += os.path.getsize(p)
    by = {}
    for p in gone:
        by[addon_of(p)] = by.get(addon_of(p), 0) + os.path.getsize(p)
    for a, s in sorted(by.items(), key=lambda x: -x[1]):
        print("   %7.1f MB  %s" % (s / 2**20, a))
    if not DRY:
        for p in gone:
            backup(p)
            os.remove(p)
        # folders the deletion emptied
        for root, ds, fs in sorted(os.walk(ADDONS), key=lambda x: -len(x[0])):
            if not os.listdir(root):
                os.rmdir(root)
    print("unreferenced: %d file(s), %.0f MB %s; %d folder(s) kept as composed paths"
          % (len(gone), size / 2**20, "would be removed" if DRY else "removed",
             sum(1 for v in dirs_named.values() if v)))


if __name__ == "__main__":
    {"sounds": sounds, "textures": textures, "dedupe": dedupe, "unreferenced": unreferenced}[sys.argv[1]]()
