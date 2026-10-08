#!/usr/bin/env python3
r"""One PRC-148 face per platoon: its own sixteen channels in full, and what the
other three groups hold.

    python tools/gen_prc148_faces.py <path to mission config_radio.hpp>
    python tools/gen_prc148_faces.py <path> --paa

THE PLAN IS READ, NOT RETYPED. Channels, labels and groups come out of the
mission's config_radio.hpp every run, so a card cannot drift from the radio it is
painted on. Change the config, re-run this, ship both.

Output: paa/radios/prc148_<group>.png, and with --paa the same into
addons/acre_faces/data.
"""

import io
import os
import re
import subprocess
import sys

from PIL import Image, ImageDraw, ImageFilter, ImageFont

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
IMG = os.path.join(ROOT, "paa", "radios")
LOGO = os.path.join(ROOT, "newlogo.png")
OUT_DATA = os.path.join(ROOT, "addons", "acre_faces", "data")
F_HAND = r"C:\Windows\Fonts\Inkfree.ttf"


def read_plan(cfg):
    t = io.open(cfg, "rb").read().decode("utf-8")
    chans = {int(c): (int(f), n) for c, f, n in
             re.findall(r'\[(\d+),(\d+),"([^"]+)"\]',
                        re.search(r'jmfsb_radio_srChannels\s*=\s*\[(.*?)\n\];', t, re.S).group(1))}
    groups = [(lab, [int(x) for x in nums.replace(" ", "").split(",") if x])
              for lab, nums in re.findall(r'\["([^"]+)",\s*\[([0-9,\s]*)\]\]',
                                          re.search(r'jmfsb_radio_srGroups\s*=\s*\[(.*?)\n\];', t, re.S).group(1))]
    return chans, groups


def font(size):
    return ImageFont.truetype(F_HAND, size)


def scratched(layer, seed, density, keep):
    import random
    rnd = random.Random(seed)
    mask = Image.new("L", layer.size, 255)
    d = ImageDraw.Draw(mask)
    w, h = layer.size
    for _ in range(density):
        x, y = rnd.randrange(w), rnd.randrange(h)
        d.line((x, y, x + rnd.randint(-26, 26), y + rnd.randint(-6, 6)),
               fill=rnd.randint(0, 90), width=rnd.choice((1, 1, 2)))
    mask = mask.filter(ImageFilter.GaussianBlur(0.8))
    a = Image.composite(layer.getchannel("A"), Image.new("L", layer.size, 0),
                        mask.point(lambda v: 255 if v > 40 else 0))
    layer.putalpha(Image.eval(a, lambda v: int(v * keep)))
    return layer


def unit_mark(px, seed):
    import random
    logo = Image.open(LOGO).convert("RGBA")
    logo = logo.crop(logo.getchannel("A").getbbox())
    alpha = Image.composite(
        logo.convert("L").point(lambda v: 255 - v),
        Image.new("L", logo.size, 0),
        logo.getchannel("A").point(lambda v: 255 if v > 40 else 0),
    ).point(lambda v: 0 if v < 70 else min(255, int((v - 70) * 1.9)))
    mark = Image.new("RGBA", logo.size, (226, 226, 220, 255))
    mark.putalpha(alpha)
    mark = scratched(mark.resize((px, px), Image.LANCZOS), seed, int(px * 3.2), 0.55)
    return mark.rotate(random.Random(seed).uniform(-7, 7), resample=Image.BICUBIC)


def face(chans, groups, idx):
    import random
    base = Image.open(os.path.join(IMG, "prc148_ui_backplate_src.png")).convert("RGBA")
    W, H = base.size
    X0, Y0, X1, Y1 = 726, 1252, 1252, 1888
    ink = (232, 231, 224)

    label, mine = groups[idx]
    others = [(l, c) for i, (l, c) in enumerate(groups) if i != idx]

    f_head, f_row, f_note = font(34), font(30), font(26)

    def draw(d, rnd):
        d.text((X0 + 14, Y0), label, font=f_head, fill=ink + (255,))
        d.line((X0 + 12, Y0 + 48, X1 - 30, Y0 + 48), fill=ink + (200,), width=3)

        top = Y0 + 60
        step = 27.5
        for i, ch in enumerate(mine):
            y = top + i * step + rnd.uniform(-1.6, 1.6)
            freq, name = chans.get(ch, (0, "-"))
            d.text((X0 + 66, y), str(ch), font=f_row, fill=ink + (255,), anchor="ra")
            d.text((X0 + 82, y), name, font=f_row, fill=ink + (255,))
            d.text((X1 - 26, y), "%d" % freq, font=f_row, fill=ink + (170,), anchor="ra")

        # what the other three groups are - the GR knob's other stops
        y = top + len(mine) * step + 14
        d.line((X0 + 12, y, X1 - 30, y), fill=ink + (110,), width=2)
        y += 8
        for l, c in others:
            d.text((X0 + 14, y), "%s   ch%d-%d" % (l, c[0], c[-1]), font=f_note, fill=ink + (200,))
            y += 30

    layer = Image.new("RGBA", (W, H), (0, 0, 0, 0))
    draw(ImageDraw.Draw(layer), random.Random(idx))
    layer = layer.rotate(random.Random(idx).uniform(-0.9, 0.9), resample=Image.BICUBIC)
    layer = scratched(layer.filter(ImageFilter.GaussianBlur(0.6)), 1148 + idx, 2600, 0.93)

    out = base.copy()
    out.alpha_composite(unit_mark(104, 48 + idx), (1146, 1792))
    out.alpha_composite(layer)
    return out


def main():
    cfg = sys.argv[1]
    chans, groups = read_plan(cfg)
    made = []
    for i, (label, _) in enumerate(groups):
        slug = re.sub(r"[^a-z0-9]+", "", label.lower())
        p = os.path.join(IMG, "prc148_%s.png" % slug)
        face(chans, groups, i).save(p)
        made.append((slug, p))
        print("wrote %s  (%s)" % (os.path.relpath(p, ROOT), label))

    if "--paa" in sys.argv:
        os.makedirs(OUT_DATA, exist_ok=True)
        for slug, p in made:
            paa = os.path.join(OUT_DATA, "prc148_%s.paa" % slug)
            if os.path.exists(paa):
                os.remove(paa)
            subprocess.run(["hemtt", "utils", "paa", "convert", p, paa],
                           stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
            print("  -> %s" % os.path.relpath(paa, ROOT))


if __name__ == "__main__":
    main()
