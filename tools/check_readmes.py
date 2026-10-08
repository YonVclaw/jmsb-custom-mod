"""Fail if any addon README is missing or stale.

    python tools/check_readmes.py

A generated README that has drifted from its addon is worse than no README - it
is a confident wrong answer. This regenerates into memory and compares, so the
check fails the moment somebody adds a setting without re-running the generator.

Hand-written prose above the marker is never compared; only the generated half.
"""
import io
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import gen_docs as G
import gen_addon_readmes as R


def main():
    missing, stale = [], []

    for base, optional in ((G.ADDONS, False), (G.OPTIONALS, True)):
        if not os.path.isdir(base):
            continue
        for name in sorted(os.listdir(base)):
            d = os.path.join(base, name)
            if not os.path.isdir(d) or not os.path.exists(os.path.join(d, "config.cpp")):
                continue

            p = os.path.join(d, "README.md")
            if not os.path.exists(p):
                missing.append(name)
                continue

            have = io.open(p, encoding="utf-8").read()
            want = R.render(base, name, G.scan_addon(base, name), optional)
            if have.split(R.MARKER)[-1].strip() != want.split(R.MARKER)[-1].strip():
                stale.append(name)

    print("Validating addon READMEs")
    print("------")
    if missing:
        print("MISSING (%d): %s" % (len(missing), ", ".join(missing)))
    if stale:
        print("STALE (%d): %s" % (len(stale), ", ".join(stale)))
        print("\nRun: python tools/gen_addon_readmes.py")
    if missing or stale:
        print("README validation FAILED")
        return 1

    print("READMEs up to date")
    return 0


if __name__ == "__main__":
    sys.exit(main())
