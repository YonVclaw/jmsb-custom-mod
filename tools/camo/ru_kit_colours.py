#!/usr/bin/env python3
"""Russia's soldier kit in e22's colours, and an arctic set (user, 2026-10-06: "remake russia without the e22 but make
camos to match the e22 color scheme"; asked: the soldiers from Aegis's Russian uniforms and loadouts, the arctic in
e22's alpine greys).

uniform_ru holds Aegis's Russian kit (tools/aegis_port/port_to_addon.py). Its taiga and arid sheets keep their digital
pattern and take e22's colours: each sheet's fabric is histogram-matched, channel by channel, to e22 RAF's lesnoy /
arid / alpine combat uniform. e22's textures are not copied or needed here - only their colour distributions, measured
once (2026-10-06) and written below as 33 quantiles per channel of the fabric pixels.

    python tools/aegis_port/port_to_addon.py <sandbox> uniform_ru     # restores Aegis's own sheets
    python tools/camo/ru_kit_colours.py                                # then this

It also writes uniform_ru/arctic_CfgWeapons.hpp and arctic_CfgVehicles.hpp: an arctic twin of every taiga uniform (with
the wearer class whose textures it shows), chest rig and Luchnik helmet cover, on arctic sheets made from the taiga ones.
"""
import os
import re
import shutil
import subprocess
import tempfile

import numpy as np
from PIL import Image

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
ADDON = os.path.join(ROOT, "addons", "uniform_ru")
MODELS = os.path.join(ADDON, "models")
# e22 RAF combat uniform fabric, 33 quantiles of R, G and B (measured off u_combatuniform_01_01_<scheme>_co)
E22 = {
    "woodland": [[16, 21, 21, 24, 24, 27, 27, 29, 30, 33, 33, 33, 33, 35, 37, 38, 40, 41, 41, 43, 43, 46, 49, 49, 49, 51, 54, 57, 60, 65, 68, 74, 123],
                 [16, 22, 24, 26, 28, 28, 30, 32, 32, 33, 34, 36, 36, 38, 38, 40, 41, 42, 44, 44, 46, 48, 49, 50, 52, 53, 56, 56, 60, 64, 67, 73, 121],
                 [13, 18, 20, 21, 24, 24, 24, 24, 27, 27, 29, 30, 33, 33, 33, 33, 33, 35, 35, 38, 40, 41, 41, 41, 43, 46, 46, 49, 49, 53, 57, 63, 115]],
    "arid": [[16, 24, 27, 30, 33, 38, 41, 41, 43, 46, 49, 49, 52, 54, 57, 57, 60, 63, 66, 68, 71, 74, 74, 79, 82, 84, 90, 90, 96, 99, 106, 115, 148],
             [16, 22, 25, 28, 32, 34, 37, 38, 40, 42, 44, 46, 48, 50, 52, 53, 56, 57, 60, 62, 65, 67, 69, 71, 73, 77, 78, 81, 85, 89, 93, 101, 138],
             [8, 16, 18, 21, 24, 24, 27, 29, 32, 33, 33, 35, 36, 38, 41, 41, 41, 43, 43, 46, 49, 49, 51, 54, 57, 57, 60, 63, 66, 68, 74, 82, 107]],
    "arctic": [[16, 24, 30, 33, 35, 41, 41, 46, 49, 51, 54, 57, 60, 66, 68, 73, 74, 79, 82, 90, 90, 98, 99, 107, 109, 115, 120, 123, 132, 140, 148, 159, 198],
               [16, 26, 30, 33, 36, 40, 43, 45, 48, 52, 54, 56, 60, 65, 68, 71, 75, 78, 83, 88, 93, 97, 101, 106, 110, 116, 120, 125, 130, 138, 150, 158, 195],
               [10, 24, 24, 32, 33, 35, 41, 41, 46, 49, 49, 52, 57, 57, 63, 66, 68, 74, 76, 82, 88, 90, 98, 99, 107, 109, 115, 121, 123, 132, 142, 153, 189]],
}
Q = np.linspace(0, 1, 33)
TAIGA = re.compile(r"(?i)(ru)?taiga")
ARID = re.compile(r"(?i)(ru)?arid")
FABRIC_MIN = 18                 # below this the sheet is UV background or deep shadow - left as it is
ARCTIC_LIFT = 1.3
SHEETS = re.compile(r"(?i)(clothing|vchestrig|vests_|radiobag|ghillie|helmeteast_cover|officer)")


def paa_to_png(src, png):
    if os.path.exists(png):
        os.remove(png)
    subprocess.run(["hemtt", "utils", "paa", "convert", src, png], capture_output=True)
    return Image.open(png)


def png_to_paa(img, dst):
    with tempfile.TemporaryDirectory() as d:
        png = os.path.join(d, "x.png")
        img.save(png)
        if os.path.exists(dst):            # hemtt refuses to overwrite, and exits 0 - see tools/camo/README.md
            os.remove(dst)
        subprocess.run(["hemtt", "utils", "paa", "convert", png, dst], capture_output=True)
    if not os.path.exists(dst):
        raise RuntimeError("paa convert failed: " + dst)


def padding(rgb):
    """The flat colour Aegis fills a sheet's unused UV space with: the commonest colour of the border, and what is near it."""
    edge = np.concatenate([rgb[:4].reshape(-1, 3), rgb[-4:].reshape(-1, 3), rgb[:, :4].reshape(-1, 3), rgb[:, -4:].reshape(-1, 3)])
    q = (edge // 8).astype(np.int32)
    keys, counts = np.unique(q[:, 0] * 4096 + q[:, 1] * 64 + q[:, 2], return_counts=True)
    k = keys[counts.argmax()]
    pad = np.array([k // 4096, (k // 64) % 64, k % 64], dtype=np.float32) * 8 + 4
    return np.abs(rgb - pad).max(-1) < 14


def ranks_of(v):
    return np.searchsorted(np.sort(v), v, side="right") / v.size


def match(img, scheme):
    """The fabric of a sheet in a scheme's colours, its own brightness order kept. Woodland and arid take e22's colour
    distribution channel by channel; arctic takes e22's alpine brightness on a neutral grey, so the olive panels go grey
    with the pattern and the sheet reads white and grey, not tinted. The UV padding is left as it is."""
    rgba = img.convert("RGBA")
    a = np.asarray(rgba, dtype=np.float32)
    rgb, alpha = a[..., :3], a[..., 3:]
    fabric = (rgb.mean(-1) > FABRIC_MIN) & ~padding(rgb)
    if not fabric.any():
        return rgba
    out = rgb.copy()
    if scheme == "arctic":
        target = np.mean(E22["arctic"], axis=0)
        tint = np.array([E22["arctic"][c][16] for c in range(3)], dtype=np.float32)
        tint /= tint.mean()
        lum = rgb[fabric].mean(-1)
        # e22's alpine reads whiter on the model than its quantiles say - the boots, straps and patches of an
        # Aegis sheet take the dark end here, so the fabric is lifted to sit where e22's does (judged side by side)
        grey = np.interp(ranks_of(lum), Q, target) * ARCTIC_LIFT
        out[fabric] = grey[:, None] * tint[None, :]
    else:
        for c in range(3):
            out[..., c][fabric] = np.interp(ranks_of(rgb[..., c][fabric]), Q, E22[scheme][c])
    return Image.fromarray(np.concatenate([np.clip(out, 0, 255), alpha], -1).astype(np.uint8), "RGBA")


def sheets():
    for dp, _dn, fs in os.walk(MODELS):
        for f in fs:
            if f.lower().endswith("_co.paa") and SHEETS.search(f):
                yield os.path.join(dp, f)


def main():
    tmp = tempfile.mkdtemp()
    made = {}
    # the Luchnik covers sit in headware, shared: the kit gets copies of its own first
    cw = os.path.join(ADDON, "CfgWeapons.hpp")
    t = open(cw, encoding="utf-8").read()
    for m in set(re.findall(r'"(\\z\\jmfsb\\addons\\headware\\models\\([^"]*H_HelmetEAST_Cover_ru(?:taiga|arid)_CO\.paa))"', t)):
        src = os.path.join(ROOT, "addons", "headware", "models", *m[1].split("\\"))
        dst = os.path.join(MODELS, "headware", *m[1].split("\\"))
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        shutil.copy2(src, dst)
        t = t.replace(m[0], "\\z\\jmfsb\\addons\\uniform_ru\\models\\headware\\" + m[1])
    open(cw, "w", encoding="utf-8", newline="\n").write(t)
    for p in sorted(sheets()):
        name = os.path.basename(p)
        scheme = "woodland" if TAIGA.search(name) else "arid" if ARID.search(name) else None
        if scheme is None or "arctic" in name.lower():
            continue
        img = paa_to_png(p, os.path.join(tmp, "src.png"))
        png_to_paa(match(img, scheme), p)
        if scheme == "woodland":
            arc = os.path.join(os.path.dirname(p), TAIGA.sub(lambda mo: "ruarctic" if mo.group(1) else "arctic", name))
            png_to_paa(match(img, "arctic"), arc)
            made[p] = arc
        print("%-8s %s" % (scheme, os.path.relpath(p, MODELS)))
    write_arctic(made)
    shutil.rmtree(tmp, ignore_errors=True)


def rel(path):
    return "\\z\\jmfsb\\addons\\uniform_ru\\models\\" + os.path.relpath(path, MODELS).replace("/", "\\")


def write_arctic(made):
    """The arctic items and their wearers, on the arctic sheets."""
    swap = {rel(k).lower(): rel(v) for k, v in made.items()}

    def arctic_paths(arr):
        out = []
        for x in re.findall(r'"([^"]*)"', arr):
            out.append('"%s"' % swap.get(x.lower(), x))
        return out
    cw = open(os.path.join(ADDON, "CfgWeapons.hpp"), encoding="utf-8").read()
    cv = open(os.path.join(ADDON, "CfgVehicles.hpp"), encoding="utf-8").read()

    def body(text, name):
        m = re.search(r"(?m)^    class GVAR\(%s\)\s*:\s*([\w(),]+)\s*\{" % re.escape(name), text)
        if not m:
            return None, None
        i, d = m.end(), 1
        while d:
            d += {"{": 1, "}": -1}.get(text[i], 0)
            i += 1
        return m.group(1), text[m.end():i - 1]

    def textures(text, name):
        """hiddenSelectionsTextures of a class, inherited through the addon's own parents."""
        while name:
            par, b = body(text, name)
            if b is None:
                return None
            m = re.search(r"\bhiddenSelectionsTextures\[\]\s*=\s*\{([^}]*)\}", b)
            if m:
                return m.group(1)
            pm = re.match(r"GVAR\((\w+)\)", par or "")
            name = pm.group(1) if pm else None
        return None
    W, V = [], []
    for name in sorted(set(re.findall(r"(?m)^    class GVAR\((\w*taiga\w*)\)\s*:", cw, re.I))):
        par, b = body(cw, name)
        arc = TAIGA.sub(lambda mo: "ruarctic" if mo.group(1) else "arctic", name)
        um = re.search(r"\buniformClass\s*=\s*QGVAR\((\w+)\)", b or "")
        if um:                                           # a uniform: its wearer's textures decide what it looks like
            wearer = um.group(1)
            tex = textures(cv, wearer)
            if not tex:
                continue
            V += ["    class GVAR(%s_arctic): GVAR(%s) {" % (wearer, wearer), "        scope = 1;", "        scopeCurator = 0;",
                  "        uniformClass = QGVAR(%s);" % arc,
                  "        hiddenSelectionsTextures[] = {%s};" % ", ".join(arctic_paths(tex)), "    };"]
            W += ["    class GVAR(%s): GVAR(%s) {" % (arc, name), '        displayName = "%s";' % display(b, name),
                  "        class ItemInfo: ItemInfo {", "            uniformClass = QGVAR(%s_arctic);" % wearer, "        };", "    };"]
            continue
        tex = textures(cw, name)
        if tex and any(swap.get(x.lower()) for x in re.findall(r'"([^"]*)"', tex)):   # a rig or a cover
            W += ["    class GVAR(%s): GVAR(%s) {" % (arc, name), '        displayName = "%s";' % display(b, name),
                  "        hiddenSelectionsTextures[] = {%s};" % ", ".join(arctic_paths(tex)), "    };"]
    hdr = ["// Generated by tools/camo/ru_kit_colours.py - re-run it rather than hand-edit.",
           "// The arctic twins of the taiga kit, on sheets made from the taiga ones in e22's alpine greys."]
    open(os.path.join(ADDON, "arctic_CfgWeapons.hpp"), "w", encoding="utf-8", newline="\n").write("\n".join(hdr + W + [""]))
    open(os.path.join(ADDON, "arctic_CfgVehicles.hpp"), "w", encoding="utf-8", newline="\n").write("\n".join(hdr + V + [""]))
    # the arctic items in the addon's CfgPatches weapons[] (port_to_addon.py writes the list without them)
    names = [re.match(r"    class GVAR\((\w+)\)", x).group(1) for x in W if x.startswith("    class")]
    cp = os.path.join(ADDON, "config.cpp")
    cfg = open(cp, encoding="utf-8").read()
    m = re.search(r"(weapons\[\] = \{)([^}]*)(\};)", cfg)
    have = set(re.findall(r"QGVAR\((\w+)\)", m.group(2)))
    add = ["QGVAR(%s)" % n for n in names if n not in have]
    if add:
        inner = m.group(2).strip()
        cfg = cfg[:m.start()] + m.group(1) + ", ".join(([inner] if inner else []) + add) + m.group(3) + cfg[m.end():]
        open(cp, "w", encoding="utf-8", newline="\n").write(cfg)
    print("arctic: %d items, %d wearers" % (sum(1 for x in W if x.startswith("    class")), sum(1 for x in V if x.startswith("    class"))))


def display(b, name):
    m = re.search(r'\bdisplayName\s*=\s*"([^"]*)"', b or "")
    d = m.group(1) if m else name
    d = re.sub(r"(?i)\(\s*taiga\s*\)|\btaiga\b", "Arctic", d)
    return d if "rctic" in d else d + " (Arctic)"


if __name__ == "__main__":
    main()
