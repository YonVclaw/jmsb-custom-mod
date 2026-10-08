"""Write a README.md into every addon and optional.

    python tools/gen_addon_readmes.py

WHY THESE ARE GENERATED. A hand-written README per addon is a hundred and eleven
files that go stale the first time somebody renames a setting, and a stale README
is worse than none - it is a confident wrong answer. Everything factual here is
scanned out of the addon itself, so re-running this after a change keeps it true.

WHERE THE PROSE GOES. Mechanical facts cannot say why an addon exists, so each
README has a hand-written section at the top, above a marker line. Anything above
the marker is yours and is never touched; everything below it is regenerated. A
new README is seeded with the best prose already in the source - an Eden module
description, or the header of the addon's main function - and flagged when there
is none to find.

Reuses tools/gen_docs.py's scanners rather than re-implementing them.
"""
import io
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import gen_docs as G

ROOT = G.ROOT
MARKER = "<!-- generated below this line by tools/gen_addon_readmes.py - do not edit -->"


def first_docblock(d):
    """The best sentence the addon's own source already has about itself.

    Prefers a controller or the addon's namesake function: those carry the
    'why this exists' paragraphs, where a leaf helper describes a detail.
    """
    fdir = os.path.join(d, "functions")
    if not os.path.isdir(fdir):
        return ""

    names = sorted(f for f in os.listdir(fdir) if f.startswith("fnc_"))
    base = os.path.basename(d)
    preferred = [f for f in names if "module" in f.lower()] + \
                [f for f in names if base.split("_")[0] in f.lower()]
    for f in preferred + names:
        txt = G.read(os.path.join(fdir, f))
        # ACE-style ` * Author: X\n * <prose>` or the /* Description: */ form
        m = re.search(r"\*\s*Author:[^\n]*\n\s*\*\s+(.+?)(?:\n\s*\*\s*\n|\n\s*\*\s*Arguments)", txt, re.S)
        if not m:
            m = re.search(r"Description:\s*\n\s*(.+?)(?:\n\s*\n|\nParameters:)", txt, re.S)
        if not m:
            continue
        s = re.sub(r"\n\s*\*?\s*", " ", m.group(1))
        s = re.sub(r"\s+", " ", s).strip()
        if len(s) > 40:
            return s
    return ""


def header_prose(d):
    """The comment block an addon's own script_component.hpp opens with.

    The newer addons carry a real 'why this exists' paragraph there, and it is a
    far better description of the ADDON than any single function's docblock -
    which describes a function.
    """
    txt = G.read(os.path.join(d, "script_component.hpp"))

    # Everything after the macros include, up to the first #define, is the
    # addon's own preamble where it has one.
    i = txt.find("script_macros.hpp")
    if i < 0:
        return ""
    tail = txt[i:]
    j = tail.find("#define")
    block = tail[:j] if j > 0 else tail

    lines = []
    for line in block.splitlines()[1:]:
        s = line.strip()
        if not s:
            if lines:
                break          # first blank line after prose ends the preamble
            continue
        if not s.startswith("//"):
            continue
        s = re.sub(r"^//\s?", "", s)
        # A section divider is not prose. An addon whose preamble opens with one
        # has no preamble - it has a commented-out table of contents.
        if re.match(r"^-{3,}", s) or re.match(r"^---\s*\w[\w \-/]*\s*-{3,}$", s):
            if lines:
                break
            return ""
        lines.append(s)

    body = re.sub(r"\s+", " ", " ".join(lines)).strip()
    return body if len(body) > 60 else ""


def intro_for(d, a):
    """Seed prose for a README that does not have any yet."""
    # An Eden module description is prose somebody already wrote about the whole
    # thing, so it wins.
    for m in a["modules"]:
        if m["desc"]:
            return m["desc"]

    s = header_prose(d)
    if s:
        return s

    # A pack of classes with no code describes itself accurately by what it
    # contains - borrowing a helper function's docblock would be worse, not
    # better, because there is no helper that is about the pack.
    # Fewer than three functions alongside a pile of classes is a pack with a
    # helper in it, not a system - and no helper's docblock is about the pack.
    if a["fns"] < 3 and (a["units"] or a["weapons"]):
        bits = []
        if a["units"]:
            bits.append("%d unit class%s" % (a["units"], "es" if a["units"] != 1 else ""))
        if a["weapons"]:
            bits.append("%d weapon and item class%s" % (a["weapons"], "es" if a["weapons"] != 1 else ""))
        return "A content pack: %s. No scripted behaviour." % " and ".join(bits)

    s = first_docblock(d)
    if s:
        return s
    return "_No description yet - add one above the generated marker._"


def render(base, name, a, optional):
    d = os.path.join(base, name)
    prefix = "jmfsb_" + name

    L = []
    L.append("# %s" % a["nice"])
    L.append("")
    L.append("`%s`%s" % (prefix, " - optional addon" if optional else ""))
    L.append("")

    # ---- hand-written section, preserved across runs ----------------------
    existing = G.read(os.path.join(d, "README.md"))
    if MARKER in existing:
        head = existing.split(MARKER)[0].rstrip()
        # drop the title lines we re-emit above
        lines = head.splitlines()
        while lines and (lines[0].startswith("# ") or lines[0].startswith("`") or not lines[0].strip()):
            lines.pop(0)
        body = "\n".join(lines).strip()
        L.append(body if body else intro_for(d, a))
    else:
        L.append(intro_for(d, a))

    L.append("")
    L.append(MARKER)
    L.append("")

    # ---- what it needs ----------------------------------------------------
    if a["deps"]:
        L.append("## Requires")
        L.append("")
        for x in a["deps"]:
            note = ""
            if not x.startswith("jmfsb_"):
                note = " _(external)_"
            L.append("- `%s`%s" % (x, note))
        if a["skip"]:
            L.append("")
            L.append("Carries `skipWhenMissingDependencies` - the PBO is skipped rather than "
                     "breaking the load order when something above is absent.")
        L.append("")

    # ---- what it ships ----------------------------------------------------
    ships = []
    if a["units"]:
        ships.append("%d unit class%s" % (a["units"], "es" if a["units"] != 1 else ""))
    if a["weapons"]:
        ships.append("%d weapon/item class%s" % (a["weapons"], "es" if a["weapons"] != 1 else ""))
    if a["fns"]:
        ships.append("%d function%s" % (a["fns"], "s" if a["fns"] != 1 else ""))
    if ships:
        L.append("## Ships")
        L.append("")
        L.append(", ".join(ships) + ".")
        L.append("")

    # ---- Eden modules -----------------------------------------------------
    if a["modules"]:
        L.append("## Eden modules")
        L.append("")
        for m in a["modules"]:
            L.append("### %s" % (m["display"] or m["class"]))
            L.append("")
            L.append("`%s`%s" % (m["class"], ", category %s" % m["category"] if m["category"] else ""))
            if m["desc"]:
                L.append("")
                L.append(m["desc"])
            if m["attrs"]:
                L.append("")
                L.append("<details><summary>%d attributes</summary>" % len(m["attrs"]))
                L.append("")
                for x in m["attrs"]:
                    L.append("- `%s`" % x)
                L.append("")
                L.append("</details>")
            L.append("")

    # ---- settings ---------------------------------------------------------
    if a["settings"]:
        L.append("## CBA settings")
        L.append("")
        L.append("| Setting | Type | Name |")
        L.append("|---|---|---|")
        for s in a["settings"]:
            L.append("| `%s%s` | %s | %s |" % (prefix + "_", s["var"], s["type"], s["label"]))
        L.append("")

    # ---- functions --------------------------------------------------------
    fdir = os.path.join(d, "functions")
    if os.path.isdir(fdir):
        fns = sorted(f[4:-4] for f in os.listdir(fdir) if f.startswith("fnc_") and f.endswith(".sqf"))
        if fns:
            L.append("## Functions")
            L.append("")
            L.append("<details><summary>%d</summary>" % len(fns))
            L.append("")
            for f in fns:
                L.append("- `%s_fnc_%s`" % (prefix, f))
            L.append("")
            L.append("</details>")
            L.append("")

    return "\n".join(L).rstrip() + "\n"


def main():
    written = 0
    seeded = 0
    for base, optional in ((G.ADDONS, False), (G.OPTIONALS, True)):
        if not os.path.isdir(base):
            continue
        for name in sorted(os.listdir(base)):
            d = os.path.join(base, name)
            if not os.path.isdir(d) or not os.path.exists(os.path.join(d, "config.cpp")):
                continue
            a = G.scan_addon(base, name)
            had = MARKER in G.read(os.path.join(d, "README.md"))
            txt = render(base, name, a, optional)
            io.open(os.path.join(d, "README.md"), "w", encoding="utf-8", newline="\n").write(txt)
            written += 1
            if not had:
                seeded += 1

    print("%d README(s) written, %d newly seeded" % (written, seeded))

    todo = []
    for base in (G.ADDONS, G.OPTIONALS):
        if not os.path.isdir(base):
            continue
        for name in sorted(os.listdir(base)):
            p = os.path.join(base, name, "README.md")
            if os.path.exists(p) and "_No description yet" in G.read(p):
                todo.append(name)
    if todo:
        print("\n%d still need a hand-written intro:" % len(todo))
        print("  " + ", ".join(todo))


if __name__ == "__main__":
    main()
