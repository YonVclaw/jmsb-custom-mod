# IADS

`jmfsb_iads`

Emission control for the enemy air defence net, and one shared air picture
underneath it.

A radar that radiates without stopping is a beacon: fly the route once, note
where the warning came from, and the site becomes terrain you route around.
**Blinking takes that away.** Every set holds its state for its own draw out of
the blink range and then flips, so there is no interval to count - and the
duty-cycle floor keeps a minimum number lit per side, with the set that has
been dark longest brought back first, so a side is never blind by accident.

Nothing is placed and nothing is spawned. It manages the radars already
standing, whoever put them there - ALiVE placement, `jmfsb_airdefence`, or a
mission maker's own Eden hardware - so there is no ALiVE coupling and no spawn
event to hook. A rescan finds what arrived since last time, **walked a slice
per frame, never the whole vehicle list in one**, and every sweep logs what it
cost; the blink and reveal beats warn in the RPT if a pass ever runs long, so
"is the net what is hitching the server" is a question the log answers with a
number.

    #jmfsb iads          radars, who is lit, what the datalink holds
    #jmfsb iads.probe    the engine probes this design is gated on

## The picture, and who else gets it

Everything on the net reports and receives on the vanilla datalink, so a
radarless launcher can shoot what the search radar two ridges away is holding.
Every reveal interval the tracks are also filed on the side's **threat board**
(`jmfsb_common_fnc_contactReport`, source `radar`) - the same place the coastal
radars and the EW net file theirs - so any consumer in the mod can act on what
the radars see without a private wire back to them. Friendly own-position
tracks are dropped on the way; a commander must not react to its own aircraft.

## What is verified, and what is not

Built from a design whose Phase 0 - four engine questions - was entirely
unverified. Code on an unverified guess does not fail loudly; it runs, logs
success, and does the opposite of what it claims. So:

| Question | How this addon handles it |
| --- | --- |
| **P0-1** `setVehicleRadar` values | Named once in `script_component.hpp`; `FUNC(emit)` is the only caller; the module refuses to arm if the engine lacks the command. |
| **P0-2** `listRemoteTargets` element shape | `FUNC(tracks)` accepts either shape and logs the raw first element once per mission. |
| **P0-3** will a radarless launcher FIRE on a shared track? | Ambush Mode is written, **off by default**, and its own tooltip says it is unverified. `confirmSensorTarget` is deliberately not called on spec. |
| **P0-4** do passive sensors survive a forced-off radar? | Nothing is faked either way: only the radar is forced, IR and visual are never touched. |

`#jmfsb iads.probe` is Phase 0 as a command - it asks which commands exist,
prints the datalink shape, and drives the nearest radar through on, off and
back to default while telling you what to watch. **If the probe disagrees with
the code, the code is what changes.**

## Sides

Every side the players are **not** on, derived the way `jmfsb_uas` derives it -
hostility asked of the engine, never a side attribute (D59). A player-side SAM
belongs to the players, and switching it off is not what an enemy air defence
system is for.

<!-- generated below this line by tools/gen_addon_readmes.py - do not edit -->

## Requires

- `jmfsb_main`
- `jmfsb_common`
- `cba_xeh` _(external)_

Carries `skipWhenMissingDependencies` - the PBO is skipped rather than breaking the load order when something above is absent.

## Ships

1 unit class, 17 functions.

## Eden modules

### JMSB - IADS / EMCON

`jmfsb_moduleIADS`, category jmfsb_modules

Emission control for the air defence net. Every radar the enemy has blinks on and off on its own jittered timer, a minimum number stay lit so the side is never blind, and everything on the net shares one picture.<br>WHY IT MATTERS: a radar that never stops radiating is a beacon that can be waited out. One that blinks cannot - a strike has to accept that something will see it, and the pilot's problem becomes timing rather than patience.<br>It manages every side the players are not on. Nothing is placed and nothing is spawned: it manages the radars already standing, whoever put them there.<br>Blink Min / Max - the range each set re-rolls its own timer in Minimum Emitters - how many stay lit per side, whatever the blink says Rescan - how often it looks for radars that were not there before Link Whole Side - share the picture beyond the air-defence net Reveal Interval - how often the picture reaches the mod's threat board Ambush Mode - UNVERIFIED, see the tooltip and run `#jmfsb iads.probe` first

<details><summary>12 attributes</summary>

- `ambush`
- `blinkMax`
- `blinkMin`
- `debugMarkers`
- `envelope`
- `exempt`
- `extraReceivers`
- `linkAll`
- `manageAir`
- `minEmitters`
- `rescan`
- `revealEvery`

</details>

## Functions

<details><summary>17</summary>

- `jmfsb_iads_fnc_ambush`
- `jmfsb_iads_fnc_emit`
- `jmfsb_iads_fnc_engine`
- `jmfsb_iads_fnc_isEmitter`
- `jmfsb_iads_fnc_isShooter`
- `jmfsb_iads_fnc_marker`
- `jmfsb_iads_fnc_moduleController`
- `jmfsb_iads_fnc_probe`
- `jmfsb_iads_fnc_register`
- `jmfsb_iads_fnc_report`
- `jmfsb_iads_fnc_reveal`
- `jmfsb_iads_fnc_scan`
- `jmfsb_iads_fnc_scanStep`
- `jmfsb_iads_fnc_sides`
- `jmfsb_iads_fnc_start`
- `jmfsb_iads_fnc_tick`
- `jmfsb_iads_fnc_tracks`

</details>
