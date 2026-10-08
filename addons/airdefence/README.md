# Air Defence

`jmfsb_airdefence`

Places air defence for every ALiVE commander on the map. TEMPORARY - it stands in until ALiVE 3's own air defence is stable.<br>Conventional commanders (invasion, occupation) get radar-cued missile batteries. Asymmetric commanders get MANPAD teams instead - a guerrilla does not field a battery.<br>Where they go is read from ALiVE: each commander's own TAOR and objectives, never anything set here. Everything placed is profiled, so it costs nothing while nobody is near it.<br>Batteries Per Side - conventional commanders only, asymmetric get none Launchers Per Battery - set back from the radar that cues them Battery Spacing (m) - least distance between two batteries Radar Class / Launcher Class / MANPAD Weapon - leave blank to pick from each commander's own faction Clear Ground (m) - open ground a battery needs; a radar in a wood sees nothing MANPAD Teams Per Side - asymmetric commanders only

<!-- generated below this line by tools/gen_addon_readmes.py - do not edit -->

## Requires

- `jmfsb_main`
- `jmfsb_common`
- `cba_xeh` _(external)_

Carries `skipWhenMissingDependencies` - the PBO is skipped rather than breaking the load order when something above is absent.

## Ships

1 unit class, 11 functions.

## Eden modules

### JMSB - Air Defence (temporary)

`jmfsb_moduleAirDefence`, category jmfsb_modules

Places air defence for every ALiVE commander on the map. TEMPORARY - it stands in until ALiVE 3's own air defence is stable.<br>Conventional commanders (invasion, occupation) get radar-cued missile batteries. Asymmetric commanders get MANPAD teams instead - a guerrilla does not field a battery.<br>Where they go is read from ALiVE: each commander's own TAOR and objectives, never anything set here. Everything placed is profiled, so it costs nothing while nobody is near it.<br>Batteries Per Side - conventional commanders only, asymmetric get none Launchers Per Battery - set back from the radar that cues them Battery Spacing (m) - least distance between two batteries Radar / Launcher / MANPAD classes are set PER SIDE - the three commanders are three different armies. Leave any of them blank to pick from that commander's own faction. Clear Ground (m) - open ground a battery needs; a radar in a wood sees nothing MANPAD Teams Per Side - asymmetric commanders only

<details><summary>22 attributes</summary>

- `launcherEast`
- `launcherGuer`
- `launcherWest`
- `launchers`
- `manpadEast`
- `manpadGuer`
- `manpadManEast`
- `manpadManGuer`
- `manpadManWest`
- `manpadWest`
- `openGround`
- `radarEast`
- `radarGuer`
- `radarWest`
- `rearmEvery`
- `security`
- `sitesPerSide`
- `spacing`
- `taorEast`
- `taorGuer`
- `taorWest`
- `teamsPerSide`

</details>

## Functions

<details><summary>11</summary>

- `jmfsb_airdefence_fnc_aaKind`
- `jmfsb_airdefence_fnc_buildBattery`
- `jmfsb_airdefence_fnc_buildSecurity`
- `jmfsb_airdefence_fnc_buildTeam`
- `jmfsb_airdefence_fnc_factionMen`
- `jmfsb_airdefence_fnc_moduleController`
- `jmfsb_airdefence_fnc_plan`
- `jmfsb_airdefence_fnc_planBatteries`
- `jmfsb_airdefence_fnc_planManpads`
- `jmfsb_airdefence_fnc_sideKit`
- `jmfsb_airdefence_fnc_start`

</details>
