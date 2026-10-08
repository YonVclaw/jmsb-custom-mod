#!/usr/bin/env python3
r"""JMSB's ACRE radio faces: the channel card written on the body, and a
scratched unit mark beside it.

    python tools/gen_radio_faces.py            # PNG masters into paa/radios
    python tools/gen_radio_faces.py --paa      # ...and convert into the addon

WHY A GENERATOR AND NOT A PAINTED PNG. The card is the net plan, and the net
plan moves. Painting it in an image editor means every channel change is a
round trip through somebody's Photoshop; here it is the two tables below, and
the picture follows. THE TABLES ARE THE ONLY THING ANYONE SHOULD NEED TO EDIT -
that is the point of the file. Change a line, re-run, done.

They must agree with config\config_radio.hpp in the mission. Nothing enforces
that, because the radio a man is holding cannot read the mission's config - the
card is a picture. If you change one, change the other in the same commit.

The bases are ACRE's own UI plates, extracted from D:\Git\acre2 and committed
beside this script as *_src.png so the generator is reproducible without the
ACRE source tree.
"""

import io
import os
import random
import subprocess
import sys

from PIL import Image, ImageDraw, ImageFilter, ImageFont

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
IMG = os.path.join(ROOT, "paa", "radios")
LOGO = os.path.join(ROOT, "newlogo.png")
OUT_DATA = os.path.join(ROOT, "addons", "acre_faces", "data")

# Handwriting. Ink Free ships with Windows 10/11; Segoe Print is the fallback.
F_HAND = r"C:\Windows\Fonts\Inkfree.ttf"
F_HAND2 = r"C:\Windows\Fonts\segoepr.ttf"


# ---------------------------------------------------------------- the plan --
# THE 148 IS THE TEAM RADIO. One channel per element, fourteen of them, and the
# channel IS the element's row in the mission's group_setup - so this list is in
# group_setup's order and has to stay that way.
PRC148 = {
    "group": "TEAM NETS  ·  0.5 W",
    # WHICH BANK GOES TO WHICH TEAM - four channels to a group, one group to a
    # platoon, which is what the GR knob turns between. Same order as
    # jmfsb_radio_srGroups and jmfsb_radio_srChannels in the mission.
    "banks": [
        ("G01 INF", [("1", "JMFSB 1-1"), ("2", "REAPER 1-2"),
                     ("3", "SPECTER 1-3"), ("4", "SCYTHE 1-4")]),
        ("G02 MECH", [("5", "NOMAD 2-1"), ("6", "NOMAD 2-2"),
                      ("7", "NOMAD 2-3"), ("8", "NOMAD 2-4")]),
        ("G03 AIR", [("9", "TALON 3-1"), ("10", "TALON 3-2"),
                     ("11", "TALON 3-3"), ("12", "TALON 3-4")]),
        ("G04 SPT", [("13", "WRAITH 4-1"), ("14", "CHARON 4-2")]),
    ],
}

# THE 152 IS THE NET RADIO - the sixteen named nets, and the only way off your
# own team. Frequencies are the MR plan's, written out because a man reading a
# card wants to know what he is turning to, not just what it is called.
PRC152 = {
    "group": "MR PLAN  \u00b7  250 mW",
    "note": "",
    "rows": [
        ("1", "COMMAND", "100"),
        ("2", "INFANTRY", "110"),
        ("3", "MECH", "120"),
        ("4", "AIR", "130"),
        ("5", "SUPPORT", "140"),
        ("6", "GROUND 1", "151"),
        ("7", "GROUND 2", "152"),
        ("8", "GROUND 3", "153"),
        ("9", "GROUND 4", "154"),
        ("10", "AIR 1", "161"),
        ("11", "AIR 2", "162"),
        ("12", "AIR 3", "163"),
        ("13", "AIR 4", "164"),
        ("14", "CAS", "170"),
        ("15", "MEDICAL", "180"),
        ("16", "A2G", "200"),
    ],
}


def font(path, size):
    try:
        return ImageFont.truetype(path, size)
    except OSError:
        return ImageFont.truetype(F_HAND2, size)


def hand_layer(size, draw_fn, jitter=1.6, seed=0):
    """Text drawn on its own layer, then nudged and blurred a hair so it reads
    as a pen on a moulded surface rather than a decal."""
    rnd = random.Random(seed)
    layer = Image.new("RGBA", size, (0, 0, 0, 0))
    draw_fn(ImageDraw.Draw(layer), rnd)
    layer = layer.rotate(rnd.uniform(-jitter, jitter), resample=Image.BICUBIC)
    return layer.filter(ImageFilter.GaussianBlur(0.6))


def scratched(layer, seed, density=900, keep=0.82):
    """Rub a layer down: random strokes taken out of its alpha, so paint sits in
    the moulding and comes off the high spots."""
    rnd = random.Random(seed)
    a = layer.getchannel("A")
    mask = Image.new("L", layer.size, 255)
    d = ImageDraw.Draw(mask)
    w, h = layer.size
    for _ in range(density):
        x, y = rnd.randrange(w), rnd.randrange(h)
        dx, dy = rnd.randint(-26, 26), rnd.randint(-6, 6)
        d.line((x, y, x + dx, y + dy), fill=rnd.randint(0, 90), width=rnd.choice((1, 1, 2)))
    mask = mask.filter(ImageFilter.GaussianBlur(0.8))
    a = Image.eval(Image.composite(a, Image.new("L", layer.size, 0), mask.point(lambda v: 255 if v > 40 else 0)),
                   lambda v: int(v * keep))
    layer.putalpha(a)
    return layer


def unit_mark(size_px, seed, ink=(226, 226, 220)):
    """The logo as a one-colour stencil, worn. The full-colour mark is a sticker;
    at 200 px on a radio body a sticker is mud, so it is reduced to its own
    silhouette in a single ink and then scratched."""
    logo = Image.open(LOGO).convert("RGBA")
    logo = logo.crop(logo.getchannel("A").getbbox())

    # silhouette from luminance: the dark linework becomes the mark, the light
    # fills drop out, which is what a stencil of this logo would actually cut
    lum = logo.convert("L")
    alpha = Image.composite(
        lum.point(lambda v: 255 - v),
        Image.new("L", logo.size, 0),
        logo.getchannel("A").point(lambda v: 255 if v > 40 else 0),
    ).point(lambda v: 0 if v < 70 else min(255, int((v - 70) * 1.9)))

    mark = Image.new("RGBA", logo.size, ink + (255,))
    mark.putalpha(alpha)
    mark = mark.resize((size_px, size_px), Image.LANCZOS)
    mark = scratched(mark, seed, density=int(size_px * 3.2), keep=0.55)
    return mark.rotate(random.Random(seed).uniform(-7, 7), resample=Image.BICUBIC)


def card_148():
    base = Image.open(os.path.join(IMG, "prc148_ui_backplate_src.png")).convert("RGBA")
    W, H = base.size

    # the battery pack - the one broad flat face on this radio, and where the
    # green arrow in the brief points
    # clear of the moulded slot at the top of the pack and of the FHALES
    # lettering stamped across the bottom
    X0, Y0, X1, Y1 = 726, 1252, 1252, 1888
    ink = (232, 231, 224)

    f_head = font(F_HAND, 33)
    f_bank = font(F_HAND, 31)
    f_row = font(F_HAND, 33)

    def draw(d, rnd):
        d.text((X0 + 14, Y0), PRC148["group"], font=f_head, fill=ink + (255,))
        d.line((X0 + 12, Y0 + 46, X1 - 30, Y0 + 46), fill=ink + (200,), width=3)

        # a line per team, plus a line for each bank heading
        rows = sum(1 + len(r) for _, r in PRC148["banks"])
        top = Y0 + 58
        step = (Y1 - top) / float(rows)
        i = 0
        for bank, teams in PRC148["banks"]:
            y = top + i * step + rnd.uniform(-1.5, 1.5)
            d.text((X0 + 14, y), bank, font=f_bank, fill=ink + (220,))
            d.line((X0 + 30 + int(f_bank.getlength(bank)), y + 21, X1 - 30, y + 21),
                   fill=ink + (95,), width=2)
            i += 1
            for ch, name in teams:
                y = top + i * step + rnd.uniform(-2.0, 2.0)
                d.text((X0 + 100, y), ch, font=f_row, fill=ink + (255,), anchor="ra")
                d.text((X0 + 120, y + rnd.uniform(-1.5, 1.5)), name, font=f_row, fill=ink + (255,))
                i += 1


    text = scratched(hand_layer((W, H), draw, jitter=0.9, seed=148), seed=1148,
                     density=2600, keep=0.93)

    # bottom right, under the last bank - the only corner the list leaves clear
    # now that the bank headings have pushed the team names further in
    mark = unit_mark(104, seed=48)
    out = base.copy()
    out.alpha_composite(mark, (1146, 1792))
    out.alpha_composite(text)
    return out


def card_152():
    base = Image.open(os.path.join(IMG, "prc152c_ui_src.png")).convert("RGBA")
    W, H = base.size

    # the 152's battery is shorter than the 148's, so this one gets a taped card
    # rather than pen straight on the body - which is also what the reference
    # photo of the real thing has
    # the card is taped high on the pack; the strip it leaves below is where the
    # unit mark goes, which is the only bare body this face has
    X0, Y0, X1, Y1 = 800, 1362, 1250, 1806
    ink = (34, 33, 30)

    f_head = font(F_HAND, 26)
    f_row = font(F_HAND, 25)

    card = Image.new("RGBA", (W, H), (0, 0, 0, 0))
    cd = ImageDraw.Draw(card)
    cd.rounded_rectangle((X0, Y0, X1, Y1), radius=8, fill=(206, 203, 186, 244))
    cd.rounded_rectangle((X0, Y0, X1, Y1), radius=8, outline=(120, 118, 104, 210), width=2)
    # tape at the corners
    for tx, ty in ((X0 - 16, Y0 - 12), (X1 - 66, Y0 - 12), (X0 - 16, Y1 - 22), (X1 - 66, Y1 - 22)):
        cd.rectangle((tx, ty, tx + 82, ty + 34), fill=(224, 220, 198, 120))
    card = card.rotate(-0.8, resample=Image.BICUBIC)

    def draw(d, rnd):
        d.text((X0 + 16, Y0 + 6), PRC152["group"], font=f_head, fill=ink + (255,))
        d.line((X0 + 14, Y0 + 42, X1 - 16, Y0 + 42), fill=ink + (170,), width=2)

        top = Y0 + 52
        step = (Y1 - 30 - top) / float(len(PRC152["rows"]))
        for i, (ch, name, freq) in enumerate(PRC152["rows"]):
            y = top + i * step + rnd.uniform(-1.6, 1.6)
            d.text((X0 + 18, y), "ch" + ch, font=f_row, fill=ink + (255,))
            d.text((X0 + 96, y + rnd.uniform(-1.2, 1.2)), name, font=f_row, fill=ink + (255,))
            d.text((X1 - 20, y), ": " + freq, font=f_row, fill=ink + (255,), anchor="ra")

    text = hand_layer((W, H), draw, jitter=0.5, seed=152)

    mark = unit_mark(112, seed=52, ink=(214, 214, 206))
    out = base.copy()
    out.alpha_composite(mark, ((X0 + X1) // 2 - 56, Y1 + 14))
    out.alpha_composite(card)
    out.alpha_composite(text)
    return out


def main():
    os.makedirs(IMG, exist_ok=True)
    made = []
    for name, fn in (("prc148_ui_backplate", card_148), ("prc152c_ui", card_152)):
        p = os.path.join(IMG, name + ".png")
        fn().save(p)
        made.append((name, p))
        print("wrote %s" % os.path.relpath(p, ROOT))

    if "--paa" in sys.argv:
        os.makedirs(OUT_DATA, exist_ok=True)
        for name, p in made:
            paa = os.path.join(OUT_DATA, name + ".paa")
            if os.path.exists(paa):
                os.remove(paa)
            subprocess.run(["hemtt", "utils", "paa", "convert", p, paa],
                           stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
            print("  -> %s" % os.path.relpath(paa, ROOT))


if __name__ == "__main__":
    main()
