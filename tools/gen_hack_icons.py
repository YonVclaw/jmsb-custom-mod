"""Slice the signals-intelligence icon sheet into individual jmfsb icons.

The source is a 5x2 sheet of black line art on white with a caption under each
cell. Arma tints a picture control by its colorText, which only works if the art
is white on transparent - so every icon comes out as alpha-only white, and the
scanner/tablet decide the colour at runtime.

Run:  python tools/gen_hack_icons.py <sheet.png>
Then: hemtt utils paa convert on each png (the script prints the commands).
"""

import os
import subprocess
import sys

from PIL import Image

# Reading order across the sheet, left to right then down. The names are what
# the icon MEANS to jmfsb, not what the stock caption called it.
NAMES = [
    "signal",       # Signal Waves        - a live emitter
    "antenna",      # Antenna             - your own net
    "intercept",    # Interception Device - the hacking rig itself
    "broken",       # Broken Signal       - link lost
    "listen",       # Listening System    - SIGINT product
    "wireless",     # Wireless Hacking    - hack in progress
    "comms",        # Comms Interception  - remote unit hack
    "uplink",       # Satellite Dish      - tower / uplink
    "jam",          # Signal Jamming      - jamming field
    "mesh",         # Data Flow Tap       - mesh / node links
]

COLS, ROWS = 5, 2
ICON_ZONE = 0.62    # top fraction of a cell that holds art rather than caption
OUT_SIZE = 128      # power of two, as Arma requires
PAD = 0.08          # margin around the art inside the square canvas

OUT = os.path.join(os.path.dirname(os.path.abspath(__file__)),
                   "..", "addons", "hacking", "data", "icons")


def bbox_of_dark(img, thresh=160):
    """Bounding box of the line art. The sheet is black on white, so anything
    below the threshold is ink."""
    px = img.convert("L").load()
    w, h = img.size
    x0, y0, x1, y1 = w, h, -1, -1
    for y in range(h):
        for x in range(w):
            if px[x, y] < thresh:
                if x < x0:
                    x0 = x
                if x > x1:
                    x1 = x
                if y < y0:
                    y0 = y
                if y > y1:
                    y1 = y
    return None if x1 < 0 else (x0, y0, x1 + 1, y1 + 1)


def main():
    if len(sys.argv) < 2:
        sys.exit("usage: gen_hack_icons.py <sheet.png>")
    sheet = Image.open(sys.argv[1]).convert("RGB")
    W, H = sheet.size
    cw, ch = W // COLS, H // ROWS

    os.makedirs(OUT, exist_ok=True)
    made = []

    for i, name in enumerate(NAMES):
        col, row = i % COLS, i // COLS
        cell = sheet.crop((col * cw, row * ch, (col + 1) * cw, row * ch + int(ch * ICON_ZONE)))
        box = bbox_of_dark(cell)
        if box is None:
            print("  !! no art found in cell %d (%s)" % (i, name))
            continue
        art = cell.crop(box)

        # Ink -> opaque white, paper -> transparent. Anti-aliased edges carry
        # through as partial alpha, which is what keeps the lines smooth when
        # the icon is drawn at 20 px on a phone screen.
        grey = art.convert("L")
        alpha = grey.point(lambda v: 255 - v)
        rgba = Image.new("RGBA", art.size, (255, 255, 255, 0))
        rgba.putalpha(alpha)

        # Fit into a square canvas so every icon occupies the same box on screen
        # regardless of whether the original was wide or tall.
        inner = int(OUT_SIZE * (1 - PAD * 2))
        aw, ah = rgba.size
        scale = min(inner / aw, inner / ah)
        rgba = rgba.resize((max(1, int(aw * scale)), max(1, int(ah * scale))), Image.LANCZOS)
        canvas = Image.new("RGBA", (OUT_SIZE, OUT_SIZE), (255, 255, 255, 0))
        canvas.paste(rgba, ((OUT_SIZE - rgba.size[0]) // 2, (OUT_SIZE - rgba.size[1]) // 2))

        png = os.path.normpath(os.path.join(OUT, name + ".png"))
        canvas.save(png)
        made.append((name, png))
        print("  %-10s %s  (from %dx%d)" % (name, os.path.basename(png), aw, ah))

    print("\nconverting to paa...")
    for name, png in made:
        paa = png[:-4] + ".paa"
        subprocess.run(["hemtt", "utils", "paa", "convert", png, paa],
                       check=True, capture_output=True)
        os.remove(png)
        print("  %s" % os.path.basename(paa))


if __name__ == "__main__":
    main()
