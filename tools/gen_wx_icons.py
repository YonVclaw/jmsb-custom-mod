"""Cuts the cTab S7 weather glyphs out of a flat-colour icon sheet.

Each condition ships as two files - <cond>_cloud and <cond>_detail - because
Arma tints a whole picture at once and only the cloud is meant to follow the
player's accent colour. The split is by colour: the blue weather body goes to
the cloud layer, and the coloured accents (a gold sun, a red bolt, a green
moon) go to the detail layer, which is drawn white and so keeps them as-is.

Three conditions Arma reports have no cell on the sheet - overcast, snow and
wind - so they are composed from the plain cloud plus flakes or gusts drawn
here.

    python tools/gen_wx_icons.py "C:/Users/jwise/Downloads/AdobeStock_...jpeg"

Writes PNGs into addons/ctab_devices/data; run `hemtt utils paa convert` after.
"""

import os
import sys

from PIL import Image, ImageDraw

DATA = os.path.join(os.path.dirname(os.path.abspath(__file__)),
                    "..", "addons", "ctab_devices", "data")

SIZE = 256          # the glyph is never drawn larger than a tile face
ROWS, COLS = 4, 5

# The sheet's own palette, sampled: everything at or near the blue is the
# weather body, everything else is an accent.
BLUES = [(29, 78, 216), (37, 99, 235), (30, 64, 175), (23, 37, 84)]

# condition -> (row, col) on the sheet, 1-indexed, and what to keep.
# "both" keeps the cell whole; "cloud" drops the accents (that is how the
# plain overcast cloud is got out of the thunderstorm cell); "detail" drops
# the body (which is how the bare crescent is got out of the night-rain cell).
CELLS = {
    "sunny": ((1, 1), "both"),      # the full gold sun
    "part":  ((1, 2), "both"),      # sun behind a cloud, the only one with no rain
    "rain":  ((1, 5), "both"),      # cloud, sun, rain streaks
    "storm": ((3, 3), "both"),      # cloud with the red bolt
    "fog":   ((3, 3), "cloud"),     # cloud, over bars taken from r3c5
    "cloud": ((3, 3), "cloud"),     # the same cloud with the bolt dropped
    "night": ((1, 3), "none"),      # nothing kept; the crescent is drawn
    "snow":  ((3, 3), "cloud"),     # cloud, plus flakes drawn below
    "wind":  ((3, 3), "cloud"),     # cloud, plus gusts drawn below
}


def is_blue(px):
    r, g, b = px[:3]
    if r > 200 and g > 200 and b > 200:
        return False
    return b > r + 30 and b > 60


def is_edge(px):
    """A JPEG anti-aliasing pixel: dull, neither the white ground nor an ink.

    Without this the detail layer keeps a dotted grey outline of whatever the
    cloud layer took, which is what made the night glyph look like a smudged
    cloud with a moon stuck to it."""
    r, g, b = px[:3]
    return max(r, g, b) - min(r, g, b) < 40


def cells(sheet):
    """The icon grid, found by where the ink is rather than by hard numbers."""
    w, h = sheet.size
    # the sheet's left third is a title panel; the grid is everything right of it
    grid = sheet.crop((int(w * 0.30), 0, w, h))
    gw, gh = grid.size
    out = {}
    for r in range(ROWS):
        for c in range(COLS):
            box = (int(gw * c / COLS), int(gh * r / ROWS),
                   int(gw * (c + 1) / COLS), int(gh * (r + 1) / ROWS))
            cell = grid.crop(box)
            # trim to the ink, so every glyph ends up the same weight
            bg = Image.new("RGB", cell.size, (255, 255, 255))
            diff = Image.new("L", cell.size)
            diff.putdata([0 if abs(a[0] - b[0]) + abs(a[1] - b[1]) + abs(a[2] - b[2]) < 60
                          else 255 for a, b in zip(cell.convert("RGB").getdata(), bg.getdata())])
            bbox = diff.getbbox()
            if bbox:
                cell = cell.crop(bbox)
            out[(r + 1, c + 1)] = cell.convert("RGB")
    return out


def split(cell, keep):
    """One cell into its two layers, square and centred."""
    src = cell.copy()
    src.thumbnail((SIZE - 16, SIZE - 16), Image.LANCZOS)
    ox = (SIZE - src.size[0]) // 2
    oy = (SIZE - src.size[1]) // 2

    body = Image.new("RGBA", (SIZE, SIZE), (0, 0, 0, 0))
    detail = Image.new("RGBA", (SIZE, SIZE), (0, 0, 0, 0))
    bp, dp = body.load(), detail.load()

    for y in range(src.size[1]):
        for x in range(src.size[0]):
            px = src.getpixel((x, y))
            if min(px[:3]) > 200:
                continue                      # the sheet's white ground, and
                                              # the pale bleed around each ink
            if is_edge(px):
                continue                      # a compression fringe, not ink
            if is_blue(px):
                if keep in ("both", "cloud"):
                    # flat white: the engine tints this layer to the accent
                    bp[x + ox, y + oy] = (255, 255, 255, 255)
            else:
                if keep in ("both", "detail"):
                    dp[x + ox, y + oy] = (px[0], px[1], px[2], 255)
    return body, detail


def bars(body, cell):
    """The fog bars off the night-fog cell, under the plain cloud."""
    w, h = cell.size
    strip = cell.crop((0, int(h * 0.72), w, h))
    strip.thumbnail((int(SIZE * 0.78), SIZE), Image.LANCZOS)
    sw, sh = strip.size
    ox = (SIZE - sw) // 2
    oy = int(SIZE * 0.74)
    bp = body.load()
    for y in range(sh):
        for x in range(sw):
            px = strip.getpixel((x, y))
            if min(px[:3]) > 200 or is_edge(px):
                continue
            if y + oy < SIZE:
                bp[x + ox, y + oy] = (255, 255, 255, 255)


def crescent(detail):
    """A clean crescent for a clear night - the sheet has no moon on its own,
    only ones with a cloud taking a bite out of them."""
    gold = (245, 183, 49, 255)
    r = SIZE * 0.30
    cx, cy = SIZE * 0.50, SIZE * 0.50
    disc = Image.new("RGBA", (SIZE, SIZE), (0, 0, 0, 0))
    d = ImageDraw.Draw(disc)
    d.ellipse([cx - r, cy - r, cx + r, cy + r], fill=gold)
    bite = Image.new("RGBA", (SIZE, SIZE), (0, 0, 0, 0))
    b = ImageDraw.Draw(bite)
    b.ellipse([cx - r * 1.45, cy - r * 1.18, cx + r * 0.72, cy + r * 1.18],
              fill=(0, 0, 0, 255))
    px, bx = disc.load(), bite.load()
    for y in range(SIZE):
        for x in range(SIZE):
            if bx[x, y][3]:
                px[x, y] = (0, 0, 0, 0)
    detail.alpha_composite(disc)


def flakes(body):
    """Three flakes under the cloud - the sheet has no snow cell."""
    d = ImageDraw.Draw(body)
    for cx, cy, rr in ((SIZE * 0.32, SIZE * 0.78, SIZE * 0.075),
                       (SIZE * 0.52, SIZE * 0.90, SIZE * 0.062),
                       (SIZE * 0.72, SIZE * 0.77, SIZE * 0.075)):
        for dx, dy in ((rr, 0), (0, rr), (rr * 0.7, rr * 0.7), (rr * 0.7, -rr * 0.7)):
            d.line([cx - dx, cy - dy, cx + dx, cy + dy], fill=(255, 255, 255, 255),
                   width=max(2, int(SIZE * 0.016)))


def gusts(body):
    """Three gust lines under the cloud - the sheet has no wind cell either."""
    d = ImageDraw.Draw(body)
    w = max(3, int(SIZE * 0.028))
    for i, (x0, x1, y) in enumerate(((0.20, 0.78, 0.78),
                                     (0.30, 0.88, 0.86),
                                     (0.24, 0.66, 0.94))):
        d.line([SIZE * x0, SIZE * y, SIZE * x1, SIZE * y],
               fill=(255, 255, 255, 255), width=w)


def main(path):
    sheet = Image.open(path).convert("RGB")
    grid = cells(sheet)
    for cond, ((r, c), keep) in CELLS.items():
        body, detail = split(grid[(r, c)], keep)
        if cond == "fog":
            bars(body, grid[(3, 5)])
        if cond == "night":
            crescent(detail)
        if cond == "snow":
            flakes(body)
        if cond == "wind":
            gusts(body)
        body.save(os.path.join(DATA, "icon_wx_%s_cloud.png" % cond))
        detail.save(os.path.join(DATA, "icon_wx_%s_detail.png" % cond))
        print("%-6s r%dc%d %-6s  body %s  detail %s" % (
            cond, r, c, keep,
            "yes" if body.getbbox() else "empty",
            "yes" if detail.getbbox() else "empty"))


if __name__ == "__main__":
    main(sys.argv[1] if len(sys.argv) > 1
         else r"C:\Users\jwise\Downloads\AdobeStock_2116238459.jpeg")
