#!/usr/bin/env python
"""One name pattern for every Future Ammunition magazine jmfsb defines.

FA's displayNames leave out the calibre and the magazine: a PMAG, a USGI, an HK
and a D60 of Mk332 all read "[JMSB] 30Rnd Mk332 AP", and a tier magazine
(_t2/_t3/_t4, tools/gen_fa_tiers.py) inherits its base's name outright. In the
arsenal that is a column of identical rows - ACE Arsenal Extended - Attachments
writes the magazine's own displayName on the weapon-magazine tabs, so the name
has to be right in the config itself (user, 2026-10-06: "names read
differently", "lots of same name"; chose "rewrite all").

Every FA magazine gets

    [JMSB] <rounds> <calibre> <load> (<magazine>) - <variant>

where the head is the row name tools/gen_aceax_ammo.py gives the magazine's
family (unique across the mod) and the variant is what the family varies on:
"Red Tracer", "Tan", "T2". The plain member of a family has no variant tail.

Edits each addon's own files in place, so every class stays where its
requiredAddons and skipWhenMissingDependencies put it. Re-run after any
generator that rewrites magazines - gen_fa_tiers.py calls it at its end.

    python tools/fa_names.py            # rewrite
    python tools/fa_names.py --dry      # count what would change
"""

import io
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import gen_aceax_ammo as GA  # noqa: E402

ADDONS = GA.ADDONS
CLASS = re.compile(r"(?m)^    class (FA_\w+)\s*(?::\s*(\w+))?\s*\{")
DISPLAY = re.compile(r'(?m)^(\s*)displayName\s*=\s*[^;\n]*;')


def variant(vals, family_key):
    """The tail: tracer, colour, finish and tier, in that order, the plain value of each left out."""
    out = []
    k, lab = vals.get("tracer", GA.DEFAULT["tracer"])
    if k == "tracer":
        out.append("Tracer")
    elif k != "ball":
        out.append("%s Tracer" % lab)
    for axis in ("colour", "finish"):
        k, lab = vals.get(axis, GA.DEFAULT[axis])
        if k != GA.DEFAULT[axis][0]:
            out.append(lab)
    k, lab = vals.get("tier", GA.DEFAULT["tier"])
    if k != "base":
        out.append(k.upper())
    return ", ".join(out)


def names():
    """{magazine class: new displayName} for every FA magazine in a jmfsb family."""
    groups = GA.build(GA.read_mags())
    out = {}
    for key, (label, members, _live) in groups.items():
        if not label.startswith("[JMSB]"):
            continue
        for m, vals in members.items():
            tail = variant(vals, key)
            out[m] = label + (" - " + tail if tail else "")
    return out


def body_end(t, i):
    """Index just past the `}` that closes the brace opened at t[i-1]."""
    d = 1
    while d:
        d += {"{": 1, "}": -1}.get(t[i], 0)
        i += 1
    return i


def rewrite(t, want):
    """The CfgMagazines text with each FA class's displayName set; (text, classes changed)."""
    i0 = t.find("class CfgMagazines")
    if i0 < 0:
        return t, 0
    out, pos, n = [], 0, 0
    for m in CLASS.finditer(t, i0):
        if m.start() < pos:
            continue
        cls = m.group(1)
        if cls not in want:
            continue
        open_ = m.end()
        close = body_end(t, open_)
        body = t[open_:close - 1]
        line = 'displayName = "%s";' % want[cls]
        if "\n" not in body:
            # A ONE-LINE CLASS KEEPS EVERYTHING ELSE ON ITS LINE. `class A: B { ammo = ...; displayName = ...;
            # tracersEvery = 4; };` - the first version replaced the whole body here and took the ammo and
            # the tracer rate with it (caught in the diff, 2026-10-06). Only the displayName is touched.
            hit = re.search(r"displayName\s*=\s*[^;]*;", body)
            if hit:
                if hit.group(0) == line:
                    continue
                new = body[:hit.start()] + line + body[hit.end():]
            elif body.strip():
                new = " " + line + " " + body.lstrip()
            else:
                # `class A: B {};` - an empty body takes the name alone
                new = " %s " % line
        else:
            # only the class's own displayName, not one in a nested class
            depth, k, hit = 0, 0, None
            for dm in re.finditer(r"[{}]|displayName\s*=\s*[^;\n]*;", body):
                s = dm.group(0)
                if s == "{":
                    depth += 1
                elif s == "}":
                    depth -= 1
                elif depth == 0:
                    hit = dm
                    break
            if hit:
                if hit.group(0) == line:
                    continue
                new = body[:hit.start()] + line + body[hit.end():]
            else:
                nl = body.index("\n")
                new = body[:nl + 1] + "        " + line + "\n" + body[nl + 1:]
        out.append(t[pos:open_])
        out.append(new)
        pos = close - 1
        n += 1
    out.append(t[pos:])
    return "".join(out), n


def main():
    dry = "--dry" in sys.argv
    want = names()
    total = files = 0
    for root, _dirs, fs in os.walk(ADDONS):
        if os.path.relpath(root, ADDONS).split(os.sep)[0] in GA.SKIP_ADDONS:
            continue
        for f in fs:
            if not f.lower().endswith(".hpp"):
                continue
            p = os.path.join(root, f)
            t = io.open(p, encoding="utf-8", newline="").read()
            if "class CfgMagazines" not in t:
                continue
            crlf = "\r\n" in t
            new, n = rewrite(t.replace("\r\n", "\n"), want)
            if n:
                files += 1
                total += n
                if not dry:
                    io.open(p, "w", encoding="utf-8", newline="").write(new.replace("\n", "\r\n") if crlf else new)
    print("fa_names: %d magazine name(s) %s in %d file(s); %d FA magazines named in all"
          % (total, "would change" if dry else "set", files, len(want)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
