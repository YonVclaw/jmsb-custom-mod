from pathlib import Path

from PIL import Image, ImageDraw


SIZE = 256
SCALE = 4
CANVAS = SIZE * SCALE


def s(value: float) -> int:
    return int(round(value * SCALE))


def ellipse_bbox(cx: float, cy: float, rx: float, ry: float) -> tuple[int, int, int, int]:
    return (s(cx - rx), s(cy - ry), s(cx + rx), s(cy + ry))


def polygon(points: list[tuple[float, float]]) -> list[tuple[int, int]]:
    return [(s(x), s(y)) for x, y in points]


def render_icon(highlight: bool) -> Image.Image:
    image = Image.new("RGBA", (CANVAS, CANVAS), (0, 0, 0, 0))
    draw = ImageDraw.Draw(image)

    ring = (196, 72, 43, 255)
    disk = (44, 45, 49, 255)
    disk_shadow = (25, 26, 29, 255)
    skull = (236, 239, 234, 255)
    skull_shadow = (196, 202, 198, 255)
    outline = (14, 16, 18, 255)
    helmet = (119, 104, 74, 255)
    helmet_shadow = (83, 70, 49, 255)
    strap = (74, 58, 40, 255)
    frame = (104, 108, 84, 255)
    lens = (79, 95, 92, 255)
    lens_shine = (154, 168, 164, 180)
    accent = (246, 247, 244, 255)

    if highlight:
        draw.ellipse(ellipse_bbox(128, 128, 108, 108), outline=(255, 255, 255, 240), width=s(10))

    draw.ellipse(ellipse_bbox(128, 132, 86, 86), fill=disk_shadow)
    draw.ellipse(ellipse_bbox(128, 128, 92, 92), fill=disk)
    draw.ellipse(ellipse_bbox(128, 128, 102, 102), outline=ring, width=s(12))

    if highlight:
        draw.ellipse(ellipse_bbox(128, 128, 110, 110), outline=accent, width=s(8))

    draw.rounded_rectangle(
        (s(82), s(42), s(174), s(109)),
        radius=s(26),
        fill=helmet,
        outline=outline,
        width=s(3),
    )
    draw.polygon(
        polygon([(84, 78), (66, 136), (82, 139), (104, 92), (152, 92), (174, 139), (190, 136), (172, 78)]),
        fill=helmet_shadow,
        outline=outline,
    )
    draw.polygon(
        polygon([(85, 53), (117, 38), (162, 40), (174, 58), (166, 81), (90, 81), (82, 61)]),
        fill=(132, 116, 84, 255),
    )
    draw.line((s(92), s(110), s(80), s(172)), fill=strap, width=s(5))
    draw.line((s(164), s(110), s(176), s(172)), fill=strap, width=s(5))

    draw.rounded_rectangle(
        (s(86), s(58), s(170), s(93)),
        radius=s(17),
        fill=frame,
        outline=outline,
        width=s(3),
    )
    draw.rounded_rectangle(
        (s(90), s(62), s(126), s(89)),
        radius=s(11),
        fill=lens,
    )
    draw.rounded_rectangle(
        (s(130), s(62), s(166), s(89)),
        radius=s(11),
        fill=lens,
    )
    draw.rectangle((s(124), s(67), s(132), s(83)), fill=frame)
    draw.arc((s(92), s(61), s(166), s(88)), 195, 345, fill=lens_shine, width=s(3))

    draw.ellipse(ellipse_bbox(128, 121, 40, 44), fill=skull, outline=outline, width=s(3))
    draw.polygon(
        polygon([(99, 138), (157, 138), (151, 178), (128, 196), (105, 178)]),
        fill=skull,
        outline=outline,
    )
    draw.ellipse(ellipse_bbox(108, 119, 12, 14), fill=outline)
    draw.ellipse(ellipse_bbox(148, 119, 12, 14), fill=outline)
    draw.polygon(polygon([(128, 126), (118, 145), (128, 151), (138, 145)]), fill=outline)
    draw.line((s(108), s(155), s(148), s(155)), fill=outline, width=s(3))
    for x in (116, 124, 132, 140):
        draw.line((s(x), s(154), s(x), s(171)), fill=outline, width=s(2))

    draw.polygon(
        polygon([(110, 179), (146, 179), (157, 216), (128, 233), (99, 216)]),
        fill=skull_shadow,
        outline=outline,
    )
    draw.polygon(
        polygon([(118, 186), (138, 186), (144, 205), (128, 216), (112, 205)]),
        fill=(223, 227, 220, 255),
    )

    if highlight:
        draw.arc((s(92), s(54), s(166), s(90)), 205, 320, fill=(236, 239, 234, 210), width=s(4))

    return image.resize((SIZE, SIZE), Image.Resampling.LANCZOS)


def main() -> None:
    root = Path(__file__).resolve().parents[1]
    render_icon(False).save(root / ".codex_tmp_gobp2_256_new.png")
    render_icon(True).save(root / ".codex_tmp_gobp2_256_g_new.png")


if __name__ == "__main__":
    main()
