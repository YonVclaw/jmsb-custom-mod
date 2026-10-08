# AntiShip

`jmfsb_antiship`

A coastal anti-ship battery whose launchers sit inland behind terrain
and cannot see the sea.

Something else has to see for them, which is what makes the surface search radar
worth attacking: kill it, or wait out its tracks, and the battery is blind. The
missile flies faster than any interceptor so it has to be met head-on rather
than chased, and it carries a decoy the defending side's AA and CIWS can engage.

**JMSB - Anti-Ship Batteries sites them for you.** Place the module and every
ALiVE commander the players are not on gets its batteries inside its own TAOR: a
surface search radar on the shoreline, where it can see the sea, and launchers
inland behind it, where they cannot. Nobody building the mission knows where they
ended up. The module asks only how many - batteries per side, launchers per
battery, radars per battery. With no ALiVE commanders its own area is the ground,
for the side the players oppose. (DIVINER dropped this module because it has no
TAORs; jmfsb runs ALiVE, so it is back under its old class name.)

**Or place them by hand.** A launcher or a radar placed in Eden or Zeus brings
itself on line the same way - the launcher registers as a battery and starts its
own clock, the radar starts sweeping.

**One launcher is one tube on its own clock**, sited or hand-placed, so three on
a headland are three cycles rather than one battery firing three times as fast.
**How they behave is CBA settings**, under *1st Joint Multi-Functional Strike Battalion > Anti-Ship*:
interval, search range, target classes, missile speed, cruise altitude, terminal
range, whether the missile is interceptable, and debug. The module's other
fourteen attributes described where to SITE a battery and died with it.

**LOCATE ANTI-SHIP and LOCATE RADAR read this addon.** `jmfsb_antiship_batteries`
and `jmfsb_antiship_radars` are what the intrusion suite's products and its
Intel Hunt pool hunt through - without this addon loaded neither product is ever
offered.

<!-- generated below this line by tools/gen_addon_readmes.py - do not edit -->

## Requires

- `jmfsb_main`
- `jmfsb_common`
- `cba_xeh` _(external)_

Carries `skipWhenMissingDependencies` - the PBO is skipped rather than breaking the load order when something above is absent.

## Ships

6 unit classes, 8 functions.

## Eden modules

### JMSB - Anti-Ship Batteries

`jmfsb_moduleAntiShip`, category jmfsb_modules

Sites coastal anti-ship batteries for every ALiVE commander the players are not on, inside its own TAOR: a surface search radar on the shoreline and launchers inland behind it. Nobody placing the mission knows where. Without ALiVE, the module's own area is the ground and the battery belongs to the side opposing the players. How they fire is under CBA settings, Anti-Ship.

<details><summary>3 attributes</summary>

- `batteriesPerSide`
- `launchersPerBattery`
- `radarsPerBattery`

</details>

## CBA settings

| Setting | Type | Name |
|---|---|---|
| `jmfsb_antiship_interval` | SLIDER | Seconds between launches |
| `jmfsb_antiship_searchRange` | SLIDER | Search range (m) |
| `jmfsb_antiship_targetClasses` | EDITBOX | Target classes |
| `jmfsb_antiship_missileSpeed` | SLIDER | Missile speed (m/s) |
| `jmfsb_antiship_cruiseAlt` | SLIDER | Cruise altitude (m) |
| `jmfsb_antiship_terminalRange` | SLIDER | Terminal range (m) |
| `jmfsb_antiship_interceptable` | CHECKBOX | Interceptable |
| `jmfsb_antiship_debug` | CHECKBOX | Debug |

## Functions

<details><summary>8</summary>

- `jmfsb_antiship_fnc_fly`
- `jmfsb_antiship_fnc_launch`
- `jmfsb_antiship_fnc_launcherInit`
- `jmfsb_antiship_fnc_moduleAntiShip`
- `jmfsb_antiship_fnc_pickTarget`
- `jmfsb_antiship_fnc_radarInit`
- `jmfsb_antiship_fnc_radarSweep`
- `jmfsb_antiship_fnc_tick`

</details>
