# Faction camo

Paints the factions' vehicles. Two scripts do the work and one applies the result:

```
python tools/camo/model_masks.py            # where each vehicle's wheels lie on its textures
python tools/camo/faction_camo_make.py      # make the textures, rewrite work/faction_camo.json
python tools/apply_faction_camo.py          # write the paths into CfgVehicles.hpp, prune what is unused
```

`faction_camo_make.py` takes `--plan` (decide nothing, print what each vehicle would be painted from),
`--preview` (a before/after sheet, nothing written), `--why <class>` (why a vehicle picked what it did),
`--remake` (rebuild every texture) and `--remake-tags a,b` (rebuild only those camos).

## Where things live

Scripts are here. Everything they cache or render is **outside the repo**, at `D:\work\camo_cache`
(override with `JMFSB_CAMO_CACHE`) — the class table, the camo pool, the wheel masks and scratch PNGs,
several hundred MB of it, none of which belongs in git.

`work/faction_camo.json` is the map the two halves talk through: per vehicle, the camo picked, where it
came from, the textures to set, what was copied and what was made.

## Things that will bite

**`hemtt utils paa convert` refuses to overwrite an existing output file — and exits 0.** It prints the
refusal to stderr only. A script that captures stderr and then tests `os.path.exists(dst)` reads the stale
file as a success, so every rebuild after the first silently does nothing. `make()` deletes the output
first for that reason. If a texture fix "doesn't show up", check the file's mtime before re-reading code.

**Never source a paint from our own output.** The class table is read from configs this pipeline has
already painted, so a vehicle's own `hiddenSelectionsTextures` *is* our camo. "Its own paint" therefore
takes the value the vehicle **inherits from its parent**, and `jmfsb_camo_*` entries are skipped when the
appearance menu is rebuilt. Without both, a re-run recolours a recolour, lists every menu entry twice
(HEMTT L-C02/L-C03), and silently drops any vehicle whose referenced file a prune has since removed.

**`textureList[] = {}` empties the texture dropdown.** It stops `BIS_fnc_initVehicle` repainting a spawned
vehicle from its parent's list, but a vehicle with an empty list and no `TextureSources` has no texture
selection at all. Every painted vehicle names its own camo instead.

**The game pairs `hiddenSelectionsTextures[i]` with `hiddenSelections[i]` by index.** A texture set of a
different length is mis-paired whatever it is called, which is why the picker prefers a set whose length
matches the vehicle's selection count.

**Creator DLC ships encrypted `.ebo`.** Neither its configs nor its textures can be read from disk, so
those vehicles are skipped. `tools/dump_hidden_selections.sqf`, run in the debug console with the mod
loaded, dumps the selections and textures the pipeline cannot see; `work/ef_selections.txt` is one such
dump.

## Size

Nothing ships above 2048, and a camo no faction wears — one that exists only to sit in an appearance
menu — ships at half size. `DEFAULT_TAGS` is the set that decides this.
