# Air Defence Sites

`jmfsb_adsite`

Coordinated air defence that shoots down munitions as well as aircraft. Built
from `docs/DESIGN_AIR_DEFENCE.md` (2026-10-07); the placement stays
`jmfsb_airdefence`'s and the radar emission stays `jmfsb_iads`' - this addon is
the brain that engages for both.

**A Site** is a set of vehicles that defend one area together: every battery
`jmfsb_airdefence` places for an ALiVE commander, and any group a mission maker
syncs to a **JMSB - Air Defence Site** module. Its side is its members' side.

- **Munitions as well as aircraft.** Missiles, rockets, bombs, artillery, mortar
  and MLRS rounds are found on the server the way `jmfsb_aps` finds them, and
  engaged only while their predicted impact is inside the protected area - a
  shell landing clear costs nothing. Aircraft are hostile by the sides' own
  relations and have to be seen.
- **Each vehicle as it really is.** Roles, reach and radar range are read from
  its own config and loadout (`fnc_profile`), and it fires its own weapons, so
  ballistics, guidance and damage are the game's.
- **Layered.** CIWS and guns are the inner layer, short-range missiles take the
  bulk of a salvo, long-range missiles are held in reserve for what only they
  can reach. A **proximity fuse** detonates the interceptor - and a munition
  target in the air - inside the interceptor ammo's own blast radius.
- **A CIWS corrects its own aim** from where its last rounds passed, and opens
  fire only when a burst has a real chance.
- **Linked Sites** share one picture and one set of commitments, so two
  batteries never fire at one target.
- **Radar emission** (automatic, silent until cued, burst search) and the
  anti-radiation shutdown run through `jmfsb_iads`' own levers, so the two
  never fight over a radar.
- **Crews** react by skill and a temperament drawn once and kept, and an
  unskilled crew sometimes fumbles.
- **Warnings are jmfsb notices** - going live, and one incoming notice per
  salvo - to the Site's side.
- **The terminal is the tacpad.** The AIR DEFENCE panel on the map screen:
  STATUS, INTERCEPT (pick a track, pick a weapon; automation on or off; STRIKE
  a point on the map) and SETTINGS; the map draws every own-side Site's area and
  tracks. Who may command is the module's Tacpad Control, checked on the server.
- **Zeus:** with Zeus Enhanced, right-click a Site's vehicle for its settings
  and that vehicle's hold-fire override.
- **Server-side:** detection, assignment and engagement all run on the server.

    #jmfsb adsite          Sites, members, tracks, commitments
    #jmfsb adsite.probe    Phase 0 - the engine questions the engagement rests on

**Not yet verified in game.** The probe answers the three engine questions the
design depends on (A0-1..3: the server sees a round in flight, a SAM fires at a
round, the SAM can be steered onto it); run it once before trusting a result.

<!-- generated below this line by tools/gen_addon_readmes.py - do not edit -->

## Requires

- `jmfsb_main`
- `jmfsb_common`
- `jmfsb_iads`
- `jmfsb_notify`
- `jmfsb_tacpad`
- `cba_xeh` _(external)_

## Ships

1 unit class, 22 functions.

## Eden modules

### JMSB - Air Defence Site

`jmfsb_moduleADSite`, category jmfsb_modules

An air defence Site: sync the radars, launchers, guns and CIWS that make it. It pools what they see, gives each aircraft or incoming round to the best-fit weapon - guns inside, short-range missiles for the bulk, long-range held in reserve - fires the vehicles' own weapons, and runs on the server. Status and control are on the tacpad.

<details><summary>14 attributes</summary>

- `access`
- `automation`
- `burstSeconds`
- `emcon`
- `engageAir`
- `engageMunitions`
- `fumble`
- `link`
- `notices`
- `radius`
- `reaction`
- `reserveLong`
- `shotsPerThreat`
- `siteName`

</details>

## Functions

<details><summary>22</summary>

- `jmfsb_adsite_fnc_assign`
- `jmfsb_adsite_fnc_board`
- `jmfsb_adsite_fnc_canControl`
- `jmfsb_adsite_fnc_crewDelay`
- `jmfsb_adsite_fnc_emcon`
- `jmfsb_adsite_fnc_engage`
- `jmfsb_adsite_fnc_fired`
- `jmfsb_adsite_fnc_fuze`
- `jmfsb_adsite_fnc_impact`
- `jmfsb_adsite_fnc_moduleSite`
- `jmfsb_adsite_fnc_notice`
- `jmfsb_adsite_fnc_order`
- `jmfsb_adsite_fnc_panel`
- `jmfsb_adsite_fnc_picture`
- `jmfsb_adsite_fnc_probe`
- `jmfsb_adsite_fnc_profile`
- `jmfsb_adsite_fnc_register`
- `jmfsb_adsite_fnc_report`
- `jmfsb_adsite_fnc_start`
- `jmfsb_adsite_fnc_strike`
- `jmfsb_adsite_fnc_tick`
- `jmfsb_adsite_fnc_zen`

</details>
