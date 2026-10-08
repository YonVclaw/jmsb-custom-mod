"""Write work/aegis_seed_map.json: every class `port.py --seeds` imports, by its source name, with the
jmfsb addon and name it came in under (dropped duplicates point at the copy kept, or at jmfsb's own
class). repoint_factions.py reads it.

    python tools/aegis_port/seed_map.py

When an earlier map exists and a re-import moved a class to another addon (a magazine from uniform to
weapons), EGVAR(old,name) is turned into EGVAR(new,name) in jmfsb's own addons first.
"""
import json
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
JMFSB = os.path.normpath(os.path.join(HERE, "..", ".."))
MAP = os.path.join(JMFSB, "work", "aegis_seed_map.json")
TARGETS = {"weapons", "vests", "headware", "uniform", "vehicle"}

# the same import port.py was run with: the seeds, plus the full vehicles and weapons (2026-10-05)
FULL_ARG = "vehicle,weapon,accessory"
sys.argv = [sys.argv[0], "--seeds", os.path.join(HERE, "seeds.txt"), "--full", FULL_ARG]
sys.path.insert(0, HERE)
import port  # noqa: E402
import emit  # noqa: E402


def build():
    emit.SEEDS = port.SEEDS
    w = port.World()
    p = port.Plan(w)
    p.build()
    emit.FULL = getattr(p, "full_root_names", set())
    e = emit.Emitter(w, p)
    m = {}
    for (ns, lo), (addon, n) in e.names.items():
        if addon is not None:
            m[p.items[(ns, lo)]["name"]] = {"ns": ns[0] if ns else "", "addon": addon, "name": n}
    for (ns, lo), tw in p.twin.items():
        src = w.snode(ns, lo).name
        if tw[0] == "own":
            m[src] = {"ns": ns[0], "addon": tw[1], "name": tw[2]}
        else:
            a, n = e.names[tw]
            m[src] = {"ns": ns[0], "addon": a, "name": n}
    return m


def remap(old, new):
    moves = {(o["addon"], o["name"]): (new[k]["addon"], new[k]["name"]) for k, o in old.items()
             if k in new and (o["addon"], o["name"]) != (new[k]["addon"], new[k]["name"])}
    if not moves:
        return
    adds = os.path.join(JMFSB, "addons")
    for a in sorted(os.listdir(adds)):
        if a in TARGETS:
            continue
        for dp, dn, fs in os.walk(os.path.join(adds, a)):
            dn[:] = [d for d in dn if d not in ("models", "data")]
            for f in fs:
                if not f.endswith((".hpp", ".cpp")):
                    continue
                path = os.path.join(dp, f)
                t0 = t = open(path, encoding="utf-8", newline="").read()
                for (oa, on), (na, nn) in moves.items():
                    t = re.sub(r"\b(Q?EGVAR)\(%s,%s\)" % (oa, re.escape(on)),
                               lambda mo, na=na, nn=nn: "%s(%s,%s)" % (mo.group(1), na, nn), t)
                if t != t0:
                    open(path, "w", encoding="utf-8", newline="").write(t)
                    print("moved references in", os.path.relpath(path, JMFSB))


def main():
    new = build()
    if os.path.exists(MAP):
        remap(json.load(open(MAP, encoding="utf-8")), new)
    json.dump(new, open(MAP, "w", encoding="utf-8"), indent=0, sort_keys=True)
    print("%d classes mapped -> %s" % (len(new), os.path.relpath(MAP, JMFSB)))


if __name__ == "__main__":
    main()
