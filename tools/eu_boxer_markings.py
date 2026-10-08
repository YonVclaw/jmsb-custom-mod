#!/usr/bin/env python3
"""The GTK Boxer's German markings, covered for the EU factions (user, 2026-10-06: "use these apcs cover the
german logos please").

    python tools/eu_boxer_markings.py

The Boxer (Hawks GTK Boxer, unpacked at D:\\work\\boxer) carries two German marks:

  * the Bundeswehr cross - its own hiddenSelection, "cross" (boxer_cross.paa). It becomes the EU shield
    (tools/camo/eu_shield.png, the one the old EU logo work used) on the same transparent square.
  * the "D" flag strip on its two number plates, painted into the hull sheet (camo1: boxer_body_co and its
    sand / snow copies). Each strip becomes an EU plate band - EU blue with the ring of gold stars - in the
    same rectangle, so the rest of the sheet (camo, wheels, glass) is the mod's own, untouched.

Copies of the mod's sheets, modified (the copy - modify - make rule). Written to addons/faction_eudf/data/boxer;
the Arid and Arctic factions reference them there. tools/gen_mod_factions.py points the Boxers at these files.
"""
import math
import os
import subprocess
import sys

from PIL import Image, ImageDraw

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = r"D:\work\boxer\hawks_gtk_boxer\data\tex"
OUT = os.path.join(ROOT, "addons", "faction_eudf", "data", "boxer")
SHIELD = os.path.join(ROOT, "tools", "camo", "eu_shield.png")
WORK = os.path.join(ROOT, ".hemttout", "eu_boxer")

# the plate flag strips on the 4096 hull sheet - identical on the green, sand and snow sheets
FLAGS = [(3620, 2736, 3642, 2767), (3760, 2907, 3781, 2942)]
EU_BLUE = (0, 51, 153, 255)
EU_GOLD = (255, 204, 0, 255)
SHEETS = {"boxer_body_co": "boxer_body_eu_co", "boxer_body_sand_co": "boxer_body_sand_eu_co",
          "boxer_body_snow_co": "boxer_body_snow_eu_co"}


def paa_to_png(name):
    png = os.path.join(WORK, name + ".png")
    if os.path.exists(png):
        os.remove(png)
    subprocess.run(["hemtt", "utils", "paa", "convert", os.path.join(SRC, name + ".paa"), png], check=True,
                   capture_output=True)
    return Image.open(png).convert("RGBA")


def png_to_paa(im, name):
    png = os.path.join(WORK, name + ".png")
    im.save(png)
    paa = os.path.join(OUT, name + ".paa")
    if os.path.exists(paa):
        os.remove(paa)                      # hemtt refuses to overwrite and still exits 0
    subprocess.run(["hemtt", "utils", "paa", "convert", png, paa], check=True, capture_output=True)
    if not os.path.exists(paa):
        sys.exit("not written: " + paa)
    print("wrote", os.path.relpath(paa, ROOT))


def eu_band(im, box):
    x0, y0, x1, y1 = box
    d = ImageDraw.Draw(im)
    d.rectangle(box, fill=EU_BLUE)
    cx, cy = (x0 + x1) / 2.0, y0 + (x1 - x0) / 2.0 + 1
    r = (x1 - x0) * 0.32
    for k in range(12):
        a = 2 * math.pi * k / 12
        sx, sy = cx + r * math.cos(a), cy + r * math.sin(a)
        d.ellipse((sx - 0.9, sy - 0.9, sx + 0.9, sy + 0.9), fill=EU_GOLD)


def main():
    os.makedirs(OUT, exist_ok=True)
    os.makedirs(WORK, exist_ok=True)
    cross = paa_to_png("boxer_cross")
    shield = Image.open(SHIELD).convert("RGBA")
    side = int(cross.size[0] * 0.92)
    shield = shield.resize((side, side), Image.LANCZOS)
    out = Image.new("RGBA", cross.size, (0, 0, 0, 0))
    out.alpha_composite(shield, ((cross.size[0] - side) // 2, (cross.size[1] - side) // 2))
    png_to_paa(out, "boxer_cross_eu_ca")
    for src, dst in SHEETS.items():
        im = paa_to_png(src)
        for box in FLAGS:
            eu_band(im, box)
        png_to_paa(im, dst)


if __name__ == "__main__":
    main()
