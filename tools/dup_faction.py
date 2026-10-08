"""Duplicate a faction addon under a new name, side and camo.

Turkey has to exist in both camos on both sides (user, 2026-09-21: "2 typed of tukey factions arid and woodland
tropical, on both east and ind side"), and Iran needed the same treatment earlier. This does the mechanical part:
every file is copied with the class prefix, component, faction class, display name and side rewritten. The camo is
NOT set here - JOBS in tools/camo/faction_camo_make.py decides that, and the map is rebuilt afterwards.

    python tools/dup_faction.py <source addon> <new addon> <old prefix> <new prefix> "<display name>" <side>

e.g. python tools/dup_faction.py faction_turkey faction_turkey_tna jmfsb_Turkey jmfsb_Turkey_tna "2040 Turkey (Tropical)" 0
"""
import io
import os
import shutil
import sys

G = r"D:\Git\jmfs-custom-mod"


def main():
    if len(sys.argv) != 7:
        raise SystemExit(__doc__)
    src_a, dst_a, old_p, new_p, display, side = sys.argv[1:7]
    src, dst = os.path.join(G, "addons", src_a), os.path.join(G, "addons", dst_a)
    if not os.path.isdir(src):
        raise SystemExit("no such addon: " + src)
    if os.path.exists(dst):
        shutil.rmtree(dst)
    os.makedirs(dst)
    n = 0
    for f in sorted(os.listdir(src)):
        p = os.path.join(src, f)
        if os.path.isdir(p) or f == "README.md":
            continue
        raw = io.open(p, encoding="utf-8", newline="").read()
        s = raw
        s = s.replace(old_p + "_", new_p + "_").replace('"%s"' % old_p, '"%s"' % new_p)
        s = s.replace("jmfsb_%s" % src_a, "jmfsb_%s" % dst_a)
        s = s.replace("#define COMPONENT %s" % src_a, "#define COMPONENT %s" % dst_a)
        s = s.replace("z\\jmfsb\\addons\\%s" % src_a, "z\\jmfsb\\addons\\%s" % dst_a)
        # the faction class itself, its name and its side
        s = s.replace("    class %s: NO_CATEGORY {" % old_p, "    class %s: NO_CATEGORY {" % new_p)
        s = s.replace("        class %s {" % old_p, "        class %s {" % new_p)
        if f == "CfgFactionClasses.hpp":
            out = []
            for line in s.replace("\r\n", "\n").split("\n"):
                if line.strip().startswith("displayName ="):
                    line = '        displayName = "%s";' % display
                elif line.strip().startswith("side ="):
                    line = "        side = %s;" % side
                out.append(line)
            s = ("\r\n" if "\r\n" in raw else "\n").join(out)
        if f.endswith(".hpp") and f != "CfgFactionClasses.hpp":
            s = s.replace("        side = %s;" % ("0" if side != "0" else "2"), "        side = %s;" % side)
        io.open(os.path.join(dst, f), "w", encoding="utf-8", newline="").write(s)
        n += 1
    io.open(os.path.join(dst, "README.md"), "w", encoding="utf-8").write(
        "# %s\n\n`jmfsb_%s`\n\n%s again on side %s, made by tools/dup_faction.py.\n" % (display, dst_a, src_a, side))
    print("copied %d files: %s -> %s (%s, side %s)" % (n, src_a, dst_a, display, side))


if __name__ == "__main__":
    main()
