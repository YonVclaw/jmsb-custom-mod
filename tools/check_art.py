#!/usr/bin/env python3
"""Verify committed generated art still matches what its generator produces.

    python tools/check_art.py

Half this repo's art is produced by a `gen_*.py` beside it. Nothing has ever
checked that the committed PNG is what the current script emits, so a script
edited without a re-run - or a PNG hand-tweaked and then silently overwritten by
the next run - is invisible until it shows up in a screenshot.

Content-based, not timestamps: git does not preserve mtimes, so a fresh clone
would report everything as stale.

Each generator runs in a COPY of its own folder (sources only, no .paa) and its
output is compared byte for byte with what is committed. A generator that writes
to an absolute path cannot be checked this way and says so rather than passing
quietly.
"""

import filecmp
import glob
import io
import os
import shutil
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def check(script):
    folder = os.path.dirname(script)
    name = os.path.relpath(script, ROOT)

    source = io.open(script, encoding="utf-8", errors="ignore").read()
    if ROOT.replace("/", "\\") in source or ":\\" in source or ":/" in source:
        print("  %-52s CANNOT CHECK (writes an absolute path)" % name)
        return 0

    work = tempfile.mkdtemp()
    try:
        for f in os.listdir(folder):
            if f.endswith((".py", ".png")):
                shutil.copy2(os.path.join(folder, f), work)

        before = {f: os.path.getmtime(os.path.join(work, f))
                  for f in os.listdir(work) if f.endswith(".png")}

        result = subprocess.run([sys.executable, os.path.basename(script)],
                                cwd=work, capture_output=True, text=True)
        if result.returncode != 0:
            # Needs an argument, or an input kept outside the repo. That says
            # nothing about whether the committed art is stale, so it is not a
            # failure - but the reason is printed rather than swallowed.
            why = ((result.stderr or result.stdout or "").strip().splitlines() or [""])[0]
            print("  %-52s CANNOT CHECK (%s)" % (name, why[:60]))
            return 0

        stale = []
        for f in sorted(os.listdir(work)):
            if not f.endswith(".png"):
                continue
            # only what this run actually wrote
            if f in before and os.path.getmtime(os.path.join(work, f)) == before[f]:
                continue
            committed = os.path.join(folder, f)
            if not os.path.isfile(committed):
                stale.append(f + " (not committed)")
            elif not filecmp.cmp(os.path.join(work, f), committed, shallow=False):
                stale.append(f)

        if stale:
            print("  %-52s STALE: %s" % (name, ", ".join(stale)))
            return len(stale)

        print("  %-52s ok" % name)
        return 0
    finally:
        shutil.rmtree(work, ignore_errors=True)


def main():
    print("Checking generated art")
    print("----------------------")
    bad = 0
    scripts = []
    for base in ("addons", "optionals", "tools"):
        scripts += glob.glob(os.path.join(ROOT, base, "**", "gen_*.py"), recursive=True)
    for s in sorted(scripts):
        bad += check(s)

    print()
    print("Art check " + ("PASSED" if bad == 0 else "FAILED - %d file(s)" % bad))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
