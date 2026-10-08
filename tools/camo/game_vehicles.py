"""Base-game vehicle base classes and the paints their configs name, read from the game's own PBOs.

The folders are the port's own (vanilla_config.FOLDERS): the base game and Bohemia's DLC that ship as
.pbo. Creator DLC ships encrypted .ebo and is not read. Writes game_bases.json in vehicle_bases.py's
row shape, so the page builds both the same way."""
import collections, json, os, struct, sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
SP = os.environ.get("JMFSB_CAMO_CACHE", r"D:\work\camo_cache")
os.makedirs(SP, exist_ok=True)
sys.path.insert(0, r"D:\Git\jmfs-custom-mod\tools\aegis_port")
import vanilla_config as VC  # noqa: E402
import vehicle_bases as VB   # noqa: E402


class Walk(VC.Rap):
    """CfgVehicles, whole: every value and nested class, merged the way a later config lays over an earlier."""

    def __init__(self, b, label, table, where):
        super().__init__(b)
        self.label, self.table, self.where = label, table, where

    def walk(self, off, node, depth):
        parent, p = self.cstr(off)
        if node is not None:
            node.parent = parent or None
        n, p = self.cint(p)
        for _ in range(n):
            t = self.b[p]
            p += 1
            if t == 0:
                name, p = self.cstr(p)
                o = struct.unpack_from("<I", self.b, p)[0]
                p += 4
                if depth == 0:
                    if name.lower() == "cfgvehicles":
                        self.walk(o, None, 1)
                    continue
                kids = self.table if depth == 1 else node.kids
                k = kids.get(name.lower())
                if k is None or not k.body:
                    fresh = VB.Node(name, None, True)
                    if k is not None:
                        fresh.kids = k.kids
                    kids[name.lower()] = fresh
                    k = fresh
                k.name = name
                if depth == 1:
                    self.where[name.lower()] = self.label
                self.walk(o, k, depth + 1)
            elif t == 1:
                st = self.b[p]
                p += 1
                name, p = self.cstr(p)
                if st in (0, 3, 4):
                    v, p = self.cstr(p)
                elif st == 1:
                    v = struct.unpack_from("<f", self.b, p)[0]
                    p += 4
                elif st == 2:
                    v = struct.unpack_from("<i", self.b, p)[0]
                    p += 4
                elif st == 6:
                    v = struct.unpack_from("<q", self.b, p)[0]
                    p += 8
                else:
                    raise ValueError("value subtype %d" % st)
                if node is not None:
                    node.props[name.lower()] = v if isinstance(v, str) else str(v)
            elif t == 2:
                name, p = self.cstr(p)
                v, p = self.arr(p)
                if node is not None:
                    node.props[name.lower()] = v
            elif t == 3:
                name, p = self.cstr(p)
                if node is not None and depth > 1:
                    node.kids.setdefault(name.lower(), VB.Node(name))
            elif t == 4:
                name, p = self.cstr(p)
            elif t == 5:
                p += 4
                name, p = self.cstr(p)
                v, p = self.arr(p)
                if node is not None:
                    old = node.props.get(name.lower())
                    node.props[name.lower()] = (old if isinstance(old, list) else []) + v
            else:
                raise ValueError("entry type %d" % t)


def main():
    strings = json.load(open(r"D:\Git\jmfs-custom-mod\tools\aegis_port\vanilla_strings.json", encoding="utf-8"))
    VB.strings.update({k.lower(): v for k, v in strings.items()})
    pbos = []
    for f in VC.FOLDERS:
        for r, _d, fs in os.walk(os.path.join(VC.A3, f)):
            pbos += [os.path.join(r, x) for x in fs if x.lower().endswith(".pbo")]
    pbos.sort()
    table, where, configs, bad = {}, {}, 0, []
    for path in pbos:
        try:
            _props, entries = VC.pbo_index(path)
        except Exception as ex:
            bad.append("%s: %s" % (os.path.basename(path), ex))
            continue
        for e in entries:
            if not e[0].lower().replace("/", "\\").endswith("config.bin"):
                continue
            try:
                data = VC.pbo_read(path, e)
                if data[:4] != b"\0raP":
                    continue
                Walk(data, os.path.basename(path), table, where).walk(16, None, 0)
                configs += 1
            except Exception as ex:
                bad.append("%s:%s: %s" % (os.path.basename(path), e[0], ex))
    recs = {k: VB.Rec(n, where.get(k, "")) for k, n in table.items() if n.body}
    rows, unknown = VB.build("game", recs, {})
    json.dump(rows, open(os.path.join(SP, "game_bases.json"), "w", encoding="utf-8"), ensure_ascii=False, indent=1)
    reps = {p["rep"] for r in rows for p in r["paints"] if p.get("rep")}
    print("PBOs %d, configs %d, CfgVehicles classes %d, problems %d" % (len(pbos), configs, len(recs), len(bad)))
    for b in bad[:5]:
        print("  !", b)
    print("base classes: %d; by family %s; public variants %d; paints %s; distinct swatch textures %d" % (
        len(rows), dict(collections.Counter(r["family"] for r in rows)), sum(len(r["publics"]) for r in rows),
        dict(collections.Counter(p["kind"] for r in rows for p in r["paints"])), len(reps)))
    for r in sorted(rows, key=lambda r: -len(r["paints"]))[:12]:
        print("  %-13s %-40s pub %-3d %s" % (r["family"], r["cls"], len(r["publics"]), [p["name"] for p in r["paints"]][:6]))


if __name__ == "__main__":
    sys.setrecursionlimit(20000)
    main()
