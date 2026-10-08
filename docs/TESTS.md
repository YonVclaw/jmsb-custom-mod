# Test plan — docs/new.md §9, steps 1-6

**Only slice zero has ever run.** Everything else below is unexecuted code.
Work down in order: each test assumes the ones above it passed, because a
failure high up makes everything under it meaningless.

Every check has a **fail meaning** — what it tells me if it does not do that.
Paste the RPT lines for anything that fails; the log line is worth more than
a description.

---

## Mission setup

| Place | Why |
|---|---|
| ALiVE Required + Virtual AI System | everything |
| **Military AI Commander** — conventional (occupation *or* invasion) | steps 1-5 |
| **Military AI Commander** — asymmetric | leaders, safe houses, QRF's mortar branch |
| **Military Placement** synced to each commander, with a TAOR marker | every TAOR read |
| ALiVE **artillery** module for a conventional side, with a battery in range | fire requests |
| A `jmfsb_prison` marker where you will hold prisoners | leader capture |
| An arsenal, or Zeus | to take an **Intel Drop Case** and a hacking tablet |

Terrain: one ALiVE has indexed. On an unindexed map the cluster globals do
not exist and coastal / caches / safe houses will say so and place nothing —
that is correct behaviour, not a bug, but it makes those tests untestable.

---

## 0. Boot

1. Load the mission. Read the RPT top to bottom once.

| Check | Pass | Fail means |
|---|---|---|
| No `Script ... not found` warnings for any jmfsb addon | ☐ | a CfgEventHandlers references a file that does not exist |
| No `Undefined variable` / `Error Params` from a `z\jmfsb\` file | ☐ | a real bug — paste it |
| `[JMFSB] (adapter_alive) INFO: ALiVE up after Ns - N commander(s)` | ☐ | the adapter never became ready; nothing below will work |

---

## 1. Slice zero — re-run it

The adapter changed since it last passed, so it is worth 60 seconds.

    #jmfsbreads
    #jmfsbsquad
    #jmfsbfire
    #jmfsbcapture

| Check | Pass | Fail means |
|---|---|---|
| Every commander prints `logic=resolved` | ☐ | the position-match broke; every TAOR read returns empty |
| `taor=[...]` non-empty for each side | ☐ | placements are not synced, or the key read is wrong |
| `AA pool n=` matches roughly the AA ALiVE placed | ☐ | the aaProfileBehaviour join is wrong |
| The squad profiles and walks to you | ☐ | spawn→profile→move is broken; QRF and patrols both depend on it |
| `#jmfsbcapture`: hold 10 s → `jmfsb_objective_captured raised` | ☐ | capture detection is broken; QRF cannot fire |

---

## 2. Coastal

    #jmfsbcoastal

| Check | Pass | Fail means |
|---|---|---|
| It lists one site per side, up to the slider | ☐ | no coastline passed the water test, or no marine clusters — the RPT says which |
| Each site reports `launchers=N radars=1` once you are near it | ☐ | the position-keyed refresh is not finding its own hardware |
| Sites are on real shore, not inland ponds | ☐ | the water-ring test is too loose |
| Radar and launchers are **separated**, not in a heap | ☐ | the inland placement pass failed |
| Fly/sail a large boat past → the battery engages | ☐ | the battery behaviour is not being driven |
| Walk away 3 km, come back → it still works | ☐ | **the important one.** Profiling deleted the hardware and the refresh did not re-point at the new objects |

---

## 3. Jamming

    #jmfsbjam

| Check | Pass | Fail means |
|---|---|---|
| Zones listed, roughly the objective share you set | ☐ | props missing from your mod set (RPT says so), or no objectives |
| Standing near a prop degrades your radio | ☐ | the applier is not running client-side |
| **Destroy** a prop → its zone leaves the list | ☐ | the prune is not catching destruction |
| **Hack** a prop → its zone leaves the list | ☐ | the hacked-flag branch of the prune is wrong |
| Once a zone is gone it stays gone | ☐ | something re-registers it |

---

## 4. Caches and patrols

    #jmfsbuas

| Check | Pass | Fail means |
|---|---|---|
| `ceilings west=N east=N` matches the slider | ☐ | settings not read |
| Patrol counts non-zero after adapter-ready | ☐ | patrols would not profile — check RPT for the delete-rather-than-leave-live warning |
| A patrol drone is **not** flying when you are far away | ☐ | it did not profile, and you have live aircraft on an empty map |
| Approach an objective → a drone materialises | ☐ | ALiVE is not spawning the profile |
| Find and destroy a cache → RPT logs `ceiling N for Ns`, and `#jmfsbuas` shows the outage | ☐ | the Killed handler or the outage map is wrong |
| While the outage runs, fewer drones come back | ☐ | `ceilingFor` is not being consulted where drones are made |

---

## 5. The hack console

Take a hacking tablet. Hack a comms tower.

| Check | Pass | Fail means |
|---|---|---|
| Buttons appear only for pools that have something | ☐ | the published counts are stale or wrong |
| **LOCATE AA** plots icons on ALiVE's AA, exactly | ☐ | pool or renderer problem |
| **LOCATE ARTILLERY** draws an offset circle | ☐ | as above |
| Hack again → the artillery circle **tightens** | ☐ | the ladder tier is not incrementing |
| Hack a third time at the same tier → **same circle, same place** | ☐ | the cached throw is being re-rolled — players can fish for a better centre |
| **LOCATE JAMMER** plots the props | ☐ | zone registry read |
| **TRACE NETWORK** appears only with an asymmetric commander | ☐ | the live-leader count gate |

---

## 6. The intel tally

Take an **Intel Drop Case** from the arsenal.

| Check | Pass | Fail means |
|---|---|---|
| Self-interact → **Deploy Intel Drop**; the case sits flat on the ground | ☐ | the surface trace failed |
| Kill an **insurgent** (asymmetric side) → body has **Search For Intel** | ☐ | the phone rule, or the side→controltype cache |
| Kill a **conventional** soldier carrying a radio → also searchable | ☐ | the radio test |
| Kill one with no radio → usually **not** searchable | ☐ | the documents roll is not gating |
| Search → you receive **Captured Intel**; counter does **not** move | ☐ | banking on pickup, which defeats the whole mechanic |
| Interact on the deployed case → **Deposit Intel**; RPT logs `N of M` | ☐ | the deposit path |
| Hit the threshold → a yellow hint circle appears on an installation or safe house | ☐ | empty hint pool — RPT says which |
| Deposit 20 at once with a threshold of 10 → **two** hints | ☐ | the batch loop pays out once |
| **Pack Up Intel Drop** → item returns to your inventory | ☐ | correspondingItem / pack path |

---

## 7. The reaction ladder

    #jmfsbreact

Set **Detect Chance** to 100 % temporarily so you are not testing dice.

| Check | Pass | Fail means |
|---|---|---|
| Fail a hack once → **nothing visible happens** | ☐ | SMALL is supposed to be silent; if you were told, the flag is leaking |
| `#jmfsbreact` now says **FLAGGED** | ☐ | the flag was not set |
| Fail again while flagged → shells, a drone, and enemies turn toward you | ☐ | MAJOR did not fire |
| The shells came from ALiVE's battery when one is in range | ☐ | the request path — check for `ARTY_REQUEST` in the RPT |
| With **no** artillery module, the fallback barrage lands instead | ☐ | fallback branch |
| Wait 5 minutes without incident → `#jmfsbreact` says **clean** | ☐ | the flag never decays |
| Transmit on a **long-range** radio in the open → eventually flagged | ☐ | radio watch not armed |
| Transmit on a **squad** radio → never flagged | ☐ | short-range is reaching the filter |
| Transmit with an **ACRE SATCOM antenna connected** → never flagged | ☐ | the SATCOM exemption |
| Let a drone see you → same ladder | ☐ | the drone-spot event has no listener |

---

## 8. QRF

    #jmfsbqrf

| Check | Pass | Fail means |
|---|---|---|
| The watch list holds ALiVE objectives and any `jmfsb_qrf*` marker | ☐ | gather |
| Clear an objective and stand on it → after the hold time it reports taken | ☐ | capture detection |
| **No countdown or warning appears** | ☐ | something is announcing it; QRF replaced Objective Watch on purpose |
| Artillery arrives, scaled to the objective's size | ☐ | wave 1 |
| An **asymmetric** objective gets mortars *or nothing*, never a full barrage | ☐ | the controltype branch |
| A drone comes | ☐ | wave 2 / ceiling |
| Squads appear **3-6 km out** and walk in — not on top of you | ☐ | origin ring or profiling |
| Retake the same objective inside the cooldown → no second QRF | ☐ | the cooldown |

---

## 9. The leader chain

    #jmfsbleaders

| Check | Pass | Fail means |
|---|---|---|
| Three leaders, each in a safe house, on the asymmetric side | ☐ | no asymmetric commander, or fewer than three houses — RPT says |
| They are the asymmetric faction's own men | ☐ | faction derivation |
| **TRACE NETWORK** circles a *house*, never a man | ☐ | product |
| Trace again → tighter circle | ☐ | ladder |
| Wait for a rotation → a leader moves; a trace now points at the **new** house | ☐ | the next-house pointer is set before the move |
| Enter a watched house → mortars | ☐ | trap arming |
| Kill a leader → RPT logs the pool cut, `#jmfsbleaders` shows `dead` | ☐ | Killed handler |
| **ACE-restrain one and carry him to `jmfsb_prison`** → logged `captured`, and another leader's position is revealed exactly | ☐ | the whole capture play |
| Kill all three → "That was the last of them", and **none respawn** | ☐ | finite is broken |
| Restart the mission with ALiVE persistence on → the dead stay dead | ☐ | save/getData |

---

## 10. Tacpad app layer — nothing sticks open

The suite's full-screen apps live over the map and redraw themselves by
reopening, which is where the stuck-window bugs live. These four races are the
ones the shell now closes by itself — each one was a real "the window will not
close" report. "Immediately" means within the same second, so the reopen the
first press queued is still in flight when the close lands.

| Check | Pass | Fail means |
|---|---|---|
| Open SQUAD, press a man, then CLOSE immediately — the window stays closed | ☐ | a queued reopen outlived the close; the stale-reopen guard missed a call site |
| Open TIMER, press +1 MIN, then CLOSE immediately — the timer does not come back | ☐ | same guard, the timer's reopen path |
| Open HACK, then open SETTINGS, wait several seconds — the hack screen does not tear itself down under settings | ☐ | appCurrent ownership broke |
| Hold the cursor on an open app while it is due to redraw — a slow press still lands | ☐ | the redraw hold (appIdle) regressed |
| The floating **FORCE CLOSE** strip sits over the open app and nothing covers it | ☐ | appBar is drawn under the app group |
| Press the floating FORCE CLOSE strip — the app closes and the strip disappears | ☐ | the bar's own close path |
| Open SUPPORT with tasking held by another tag — a blank screen is not the result; the strip is there and closes out | ☐ | the gate refused before its dialog opened |
| Close the map with an app open, reopen it — no app, no strip, panels back | ☐ | appCurrent / appBar survived the map close |

---

## 11. IADS / EMCON — the net blinks, and Phase 0

**Run the probe before anything else in this section.** The addon was written
against a design whose four engine questions were never verified, and the probe
is those questions asked of a running game. Everything below is meaningless if
`setVehicleRadar` turns out to be missing or inverted.

Setup: a **JMSB - IADS / EMCON** module, and two or three enemy search radars
standing somewhere you can watch them (ALiVE placement, a `jmfsb_airdefence`
battery, or hand-placed in Eden). Turn **Debug Markers** on for this test only.

    #jmfsb iads.probe
    #jmfsb iads

| Check | Pass | Fail means |
|---|---|---|
| `setVehicleRadar: present`, `listRemoteTargets: present` | ☐ | P0-1 fails: the addon cannot switch anything and refuses to arm - the RPT says so |
| The probe names a radar and drives it, and forced ON and forced OFF look **different** on the dish or the RWR | ☐ | P0-1 is inverted: swap `IADS_RADAR_ON` and `IADS_RADAR_OFF` in `script_component.hpp` and nothing else |
| RPT: `listRemoteTargets element is a ...` once a hostile aircraft is up | ☐ | P0-2 unanswered - the datalink is empty, so nothing is being shared to read |
| While a set is forced OFF, does it still detect an aircraft close by? | ☐ | this IS P0-4, and either answer is a pass - write down which one you saw |
| `#jmfsb iads` lists radars per side with some lit and some dark | ☐ | the scan found nothing: sides are wrong, or nothing hostile carries a radar |
| Watch the markers for two minutes - sets flip at different moments, not together | ☐ | the jitter is not being re-rolled; every set is on one metronome |
| With Minimum Emitters 1, at least one marker is green at all times | ☐ | the duty-cycle floor is not holding - the whole side can go dark |
| Set Minimum Emitters to 0 and watch: the side does go fully dark sometimes | ☐ | the floor is being applied when it was switched off |
| An always-on class named in **Always-On Classes** never goes dark | ☐ | the pinned list is not matching - check the classname, case does not matter |
| Kill a radar: its marker disappears and `#jmfsb iads` counts one fewer | ☐ | the prune is not running, and dead hardware still counts towards the floor |
| With **Threat Board Debug** on (CBA, Common), fly a hostile aircraft past a lit radar: the RPT files a `contact ... (radar)` for the radar's side | ☐ | the reveal bridge is not filing, and the rest of the mod cannot see the air picture |

**P0-3 is not on this list because no script can answer it.** Park a radarless
launcher and a search radar on one side, fly a target in, and watch whether the
launcher *fires* on the shared track or only draws it. Only turn **Ambush Mode**
on after you have seen it fire.

---

## 12. Air Defence Sites — munitions and aircraft, layered

Setup: a **JMSB - Air Defence Site** module synced to a search radar, two
launchers and a gun or CIWS, all OPFOR; a player on OPFOR inside the protected
area, and something BLUFOR that can shoot into it (a mortar, a rocket
artillery piece, a jet).

    #jmfsb adsite.probe
    #jmfsb adsite

| Check | ☐ | If it fails |
|---|---|---|
| The probe says **A0-3 yes** (the server sees the round in flight) | ☐ | Sites cannot track munitions at all - the whole munition half rests on this |
| The probe says **A0-2 fired** and **A0-1 yes**, and the round is intercepted | ☐ | A0-2 no: `fnc_engage` falls back to forceWeaponFire - watch that it fires. A0-1 no: the fuse alone has to catch it; expect fewer kills |
| `#jmfsb adsite` lists the Site, its members with roles (LONG/SHORT/GUN/CIWS/SENSOR) and the radar | ☐ | `fnc_profile` read the vehicles wrong - their roles decide everything after |
| A mortar round fired AT the Site's area is engaged; one fired well clear of it is not | ☐ | `fnc_impact`'s prediction or the protected radius is wrong |
| A salvo is spread across the launchers, guns first on what is close, long-range held back | ☐ | `fnc_assign`'s layers |
| An OPFOR player gets **AIR DEFENCE ... radiating** once, and **INCOMING ...** once per salvo, not once per round | ☐ | `fnc_notice` |
| The tacpad shows the AIR DEFENCE panel for OPFOR only; STATUS, INTERCEPT and SETTINGS draw; the map shows the area and the tracks | ☐ | the board is not publishing, or the panel's condition is wrong |
| AUTOMATION OFF stops the Site; picking a track and pressing FIRE on a member engages it | ☐ | `fnc_order` "engage" |
| A BLUFOR player near the Site sees no panel; an OPFOR player outside the area with access "near" sees it read-only | ☐ | `fnc_canControl` |
| Two Sites with the same Link never put two weapons on one round beyond Shots Per Threat | ☐ | the shared coordinator in `fnc_tick` |
| Silent until cued: the radar stays dark until a track exists, then lights | ☐ | `fnc_emcon` and the iads `heldOff` lever |
| With Zeus Enhanced: right-click a member, the dialog opens and a change shows on the panel | ☐ | `fnc_zen` |

---

## What "pass" means

Not "the feature is good" — only **"the code ran and did roughly what it
claims"**. Tuning comes after something has run.

The chat reports are the cheap check; the RPT is the real one. Every system
logs what it decided and why it declined, so *not configured* and *not
working* look different.
