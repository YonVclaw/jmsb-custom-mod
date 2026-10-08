"""Split a work/dump_orbat.sqf RPT run into work/orbat/<FACTION>.cpp.

THE FILE work/orbat_dump.sqf HAS BEEN TELLING YOU TO RUN SINCE THE DAY IT WAS
WRITTEN. It ends with "run: python work/extract_orbat.py"; that file never
existed, so every ORBAT export went to the RPT and stopped there.

One .cpp per faction, in the same shape as work/blue.sqf - the ALiVE ORBAT
Creator export. The SQF writes each faction between markers:

    // >>>> ORBAT BEGIN <faction> <<<<
    ...
    // >>>> ORBAT END <faction> <<<<

    python tools/extract_orbat.py
    python tools/extract_orbat.py --rpt X.rpt --out work/orbat
"""
import os, io, re, sys, glob, argparse

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, "work", "orbat")

BEGIN = re.compile(r"//\s*>>>>\s*ORBAT BEGIN (\S+)\s*<<<<")
END = re.compile(r"//\s*>>>>\s*ORBAT END (\S+)\s*<<<<")

# Arma stamps every RPT line with a wall clock; it has to come off the config
# or the .cpp will not compile.
STAMP = re.compile(r"^\s*\d{1,2}:\d{2}:\d{2}(?:\.\d+)?\s")


def newest_rpt():
    base = os.environ.get("LOCALAPPDATA")
    if not base:
        return None
    hits = glob.glob(os.path.join(base, "Arma 3", "Arma3_x64_*.rpt"))
    if not hits:
        hits = glob.glob(os.path.join(base, "Arma 3", "*.rpt"))
    return max(hits, key=os.path.getmtime) if hits else None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--rpt")
    ap.add_argument("--out", default=OUT)
    args = ap.parse_args()

    rpt = args.rpt or newest_rpt()
    if not rpt or not os.path.exists(rpt):
        print("no RPT found. Run work/dump_orbat.sqf in the debug console")
        print("first, or pass --rpt <path>.")
        return 2

    text = io.open(rpt, encoding="utf-8", errors="replace").read()
    lines = text.splitlines()

    # THE LAST RUN OF EACH FACTION, NOT THE FIRST. An RPT accumulates across
    # sessions and a faction is often re-exported after a fix; taking the first
    # copy hands back the version you just replaced.
    blocks = {}
    cur, buf = None, []
    for raw in lines:
        line = STAMP.sub("", raw)

        m = END.search(line)
        if m and cur and m.group(1).lower() == cur.lower():
            blocks[cur.lower()] = (cur, buf)
            cur, buf = None, []
            continue

        m = BEGIN.search(line)
        if m:
            cur, buf = m.group(1), []
            continue

        if cur is not None:
            buf.append(line)

    if cur is not None:
        # NOT SILENT. A block with no END is a run that was cut off - the file
        # would be missing its closing brace and would not compile.
        print("!! %s has no END marker - dump was cut short, skipping it" % cur)

    if not blocks:
        print("%s holds no ORBAT export - looked for the BEGIN marker." % rpt)
        print("Paste work/dump_orbat.sqf into the debug console and Exec.")
        return 2

    if not os.path.isdir(args.out):
        os.makedirs(args.out)

    print("read   %s" % rpt)
    total_u = 0
    bad = []
    for key in sorted(blocks):
        name, body = blocks[key]
        text = "\n".join(body).rstrip() + "\n"

        # A COMPILE SANITY CHECK, not a parse. An unbalanced brace means the
        # RPT dropped a line, and finding that here beats finding it in HEMTT.
        if text.count("{") != text.count("}"):
            bad.append(name)

        nunit = len(re.findall(r"^    class \S+ : \S+_OCimport_02 \{", text, re.M))
        total_u += nunit

        path = os.path.join(args.out, name + ".cpp")
        io.open(path, "w", encoding="utf-8", newline="\r\n").write(text)
        print("  %-28s %5d unit(s)  %7d bytes" % (name + ".cpp", nunit, len(text)))

    print("wrote  %d faction file(s), %d unit(s) into %s"
          % (len(blocks), total_u, args.out))

    nl = len(re.findall(r"^\s*// !! .* would not spawn", "\n".join(
        "\n".join(b[1]) for b in blocks.values()), re.M))
    if nl:
        print("       %d man/men would not spawn - no loadout read, marked in the file" % nl)
    if bad:
        print("       !! UNBALANCED BRACES, will not compile: %s" % ", ".join(bad))
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
