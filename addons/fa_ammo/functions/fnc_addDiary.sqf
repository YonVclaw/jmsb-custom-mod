#include "..\script_component.hpp"
/*
 * Author: 1st Joint Multi-Functional Strike Battalion
 * Adds the "Future Ammunition" briefing subject to a unit's map Notes tab,
 * with one record per caliber / family. Runs client-side for the local
 * player (see XEH_postInit), and re-runs on respawn since diary records
 * live on the unit object.
 *
 * Arguments:
 * 0: Unit to add the diary to <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player] call jmfsbfa_ammo_fnc_addDiary
 *
 * Public: No
 */

params [["_unit", player, [objNull]]];

if (isNull _unit) exitWith {};
// guard against double-add on the same unit
if (_unit getVariable [QGVAR(diaryAdded), false]) exitWith {};
_unit setVariable [QGVAR(diaryAdded), true];

private _subject = "FA_Ammo";
_unit createDiarySubject [_subject, "Future Ammunition"];

// colour helpers
#define H(t)   "<font color='#DE5C30' size='18'>" + t + "</font><br/>"
#define R(n)   "<font color='#E9A63C'>" + n + "</font>  "
#define S(t)   "  <font color='#7F93AC'>(" + t + ")</font>"
#define NL     "<br/>"
// employment / how-to-use line
#define U(t)   "<font color='#8FBF6F'>Use</font>  " + t + NL

private _entries = [

  ["Overview",
    H("1st Joint Multi-Functional Strike Battalion - Future Ammunition") +
    "A lore-driven projection of small-arms, autocannon, tank, mortar, artillery, naval and aircraft ammunition for ACE3." + NL +
    "Everything dated past 2026 is fiction tuned for gameplay; the historical baselines (M193 -> M855A1+, M80 -> M80A1, 6.8 Fury) are real." + NL + NL +
    "<font color='#E9A63C'>Naming</font>  NATO = Mk / XM / M ; Russian = GRAU 7N (ball/AP) and 7U (subsonic) ; CSAT = Type ## ; AAF = AF-## . Several mortar / artillery natures are re-labelled per side (same round, distinct name). All arsenal mags are tagged [JMSB]." + NL +
    "<font color='#E9A63C'>Design</font>  Cased rounds plateau in the low-to-mid 80,000 psi range - the gains come from hybrid cases and tungsten cores, not raw pressure. Subsonic loads stay under Mach 1 and improve through mass alone." + NL +
    "<font color='#E9A63C'>Requires</font>  CBA_A3 + ACE3 with Advanced Ballistics ENABLED, or the per-barrel velocity / drag / penetration tables do not apply." + NL + NL +
    "<font color='#E9A63C'>Airburst control</font>  The programmable-airburst rounds (40mm Mk364, MAAWS HE 448, Vorona Oskol) share one slant-range setting. Dial it with the CBA keybind <font color='#E9A63C'>Mk364: Cycle Airburst Range</font> (UNBOUND by default - assign a key under Options > Controls > Configure Addons > 1st Joint Multi-Functional Strike Battalion) or the ACE self-interaction menu. Steps 0 / 100 / 150 / 200 / 250 / 300 / 400 m; 0 = off (proximity + HE on impact)."],

  ["Tracer Colors",
    H("Tracer color conventions") +
    "<font color='#D0453A'>Red</font>  Typically used by NATO / Western forces for standard ammunition." + NL +
    "<font color='#5CB85C'>Green</font>  Commonly used by OPFOR / Eastern bloc forces (CSAT, Syndikat)." + NL +
    "<font color='#E9A63C'>Yellow / Orange</font>  Frequently used for heavy machine guns, larger caliber autocannons (20mm / 30mm) and specific ammunition variants." + NL +
    "<font color='#7F93AC'>IR</font>  NVG-only tracer - invisible to the naked eye, glows green under night vision."],

  ["5.56x45",
    H("NATO carbine") +
    R("Mk327 HV") + "Hybrid-case hypervelocity ball, 62gr" + S("2033 - ~83 kpsi") + NL +
    R("XM891 CTEP") + "Cased-telescoped 2-stage tungsten EPR" + S("2039 - ~85 kpsi") + NL +
    R("Mk332 AP") + "Tungsten armor-piercing" + S("2040") + NL +
    R("Mk361 PAB") + "Proximity airburst, C-UAS (antidrone)" + NL +
    R("Mk368K/L AD") + "Anti-drone buckshot - 8 pellets/100 m (K), 5 pellets/200 m (L) (antidrone)" + NL +
    R("AF-556 / AF-556C / AF-556P") + "AAF faction trio - HV / CT / AP at ~95% of NATO performance" + S("2040") + NL +
    "<font color='#7F93AC'>Mk327 / XM891 / Mk332 ride every 5.56 mag (STANAG, JCA, SPS, RHS, boxes/belts) in all tracer colors.</font>"],

  ["5.8x42",
    H("CSAT / PLA carbine") +
    R("Ball HV") + "High-velocity ball reference load" + NL +
    R("DBP-39 CT") + "Cased-telescoped tungsten" + S("2040") + NL +
    R("DBP-40 AP") + "Tungsten armor-piercing" + S("2040")],

  ["7.62x39",
    H("AK / RPK") +
    R("7N43 Kremen") + "Hybrid-case hollow-point (camo + drum variants)" + S("2034 - HP") + NL +
    R("7N47 Kremen-2 CT") + "Cased-telescoped" + S("2040 - CT") + NL +
    R("7U4 Tishina-2") + "Subsonic AP, suppressed"],

  ["7.62x51 (.308)",
    H("Battle rifle / GPMG") +
    R("M80A2 HV") + "Hybrid-case 135gr tungsten EPR" + S("2032 - ~78 kpsi") + NL +
    R("XM751 CTEP") + "Cased-telescoped tungsten, long-range / anti-armor" + S("2039 - ~82 kpsi") + NL +
    R("Mk362 PAB") + "Proximity airburst, C-UAS (antidrone)" + NL +
    R("Mk369K/L AD") + "Anti-drone buckshot - 12 pellets/150 m (K), 10 pellets/250 m (L) (antidrone)" + NL +
    R("AF-762 / AF-762C / AF-762P") + "AAF faction trio - HV / CT / AP at ~95% of NATO performance" + S("2040") + NL +
    "<font color='#7F93AC'>M80A2 / XM751 ride every .308 mag (core, ACE, JCA, SPS AXMC, RHS M240) in all tracer colors.</font>"],

  [".300 BLK",
    H("Suppressed carbine - full family") +
    R("Mk335 / 336 / 337") + "110 / 125 / 150 gr supersonic" + NL +
    R("Mk342 / 343") + "190 / 220 gr subsonic" + NL +
    R("Mk341 SUB-AP") + "Subsonic tungsten AP" + S("2038") + NL +
    R("XM345 SUB-AP2") + "Subsonic tungsten AP, 2nd-gen" + S("2039")],

  ["6.5x39",
    H("Intermediate / caseless - MX family") +
    R("Mk330 EPR") + "Tungsten-cored standard load, requires a caseless-capable rifle by design" + S("2035 - ~75 kpsi") + NL +
    R("Mk331 AP") + "Tungsten armor-piercing" + S("2040") + NL +
    R("Mk328 HV / Mk329 LR") + "Match / long-range DMR loads" + NL +
    R("XM892 / XM893 CTEP") + "Cased-telescoped enhanced-penetration" + NL +
    R("Mk367 PAB") + "Proximity airburst, C-UAS (antidrone)" + NL +
    R("Type 41 / 42 / 43") + "CSAT faction trio for the Katiba - EPR / CT / AP at ~90% of NATO" + S("2040") + NL +
    "<font color='#7F93AC'>All feed the standard 6.5 caseless mags / wells (Sand/Black/Khaki/MSBS) in all tracer colors - same caliber, different loads.</font>"],

  [".338",
    H("Long-range precision + medium MG") +
    R("Mk371 LRP (Lapua)") + "250 / 285 / 300 gr precision (AWM / AXMC / core)" + NL +
    R("Mk372 MMG (Norma)") + "130 / 200 rnd belt-fed sustained fire" + NL +
    R("Mk373 PAB") + "Proximity airburst, C-UAS (antidrone)"],

  ["9.3x64",
    H("CSAT marksman") +
    R("Type 40") + "Hybrid case, tungsten core" + S("2038")],

  [".408 / .45 ACP",
    H("Extreme range + suppressed pistol") +
    R("Mk240 LRP (.408)") + "340 gr all-round match" + NL +
    R("Mk421 SUB-AP (.45)") + "Subsonic tungsten AP" + S("2038")],

  ["12.7 (.50)",
    H("Anti-materiel rifle / HMG") +
    R("Mk250 LRP") + "Match precision" + NL +
    R("Mk211 Mod 2") + "HEIAP anti-materiel"],

  ["12 Gauge",
    H("Buckshot / birdshot loads") +
    R("No.0 / 1 / 2 / 3 / 4 Buck") + "9 -> 27 pellet spreads, 8.4 -> 6.1 mm" + NL +
    R("No.4 Bird") + "Fine-pellet birdshot"],

  ["9x39 (VSS / Val)",
    H("East suppressed spec-ops - extracal") +
    U("Subsonic by design - runs on the CBA 9x39 well, so it feeds any VSS/Val. Zero close; drops fast past 300 m.") +
    R("7U15") + "Subsonic tungsten AP - defeats body armor quietly" + NL +
    R("7U16") + "Subsonic hollow-point - anti-personnel"],

  ["5.7x28 (PDW)",
    H("West PDW - P90 / Five-seveN - extracal") +
    R("Mk430 AP") + "Tungsten penetrator - soft-armor defeat" + NL +
    R("Mk431 SUB") + "Subsonic suppressed load"],

  ["14.5x114 (AM rifle)",
    H("Above .50 - heavy MG / anti-materiel - extracal") +
    U("Mag-fed AM rifles get these via the CBA well. 7N62 is a drone-killer - point at the UAV and the fuze bursts near it.") +
    R("7N60 AP-T") + "Tungsten AP-tracer - shreds light vehicles" + NL +
    R("7N61 HEIAP") + "HE incendiary AP - multipurpose" + NL +
    R("7N62 HEAB") + "Proximity airburst, C-UAS (PAB script)"],

  ["12.7x55 (ASh-12)",
    H("Russian heavy CQB rifle - Reaction Forces - rf") +
    U("Feeds the ASh-12 via the CBA 12.7x55 well. Subsonic loads for suppressed work.") +
    R("7N52 Molot") + "Heavy AP" + NL +
    R("7U13 Molot-S") + "Subsonic AP, suppressed" + NL +
    R("7U14 Uragan") + "Subsonic expanding"],

  ["Rearma - US",
    H("M7 / RM277 / M250 / NX / KAC AMG / M27A5 / M28A5 / MP7A2 / M17 / M72A7 - rearma_us") +
    U("Loads only with rearma's US weapons, on rearma's own mags (black and tan). The M320 and every rearma underbarrel launcher take the FA 40mm rounds; the M28A5 takes FA 7.62 20Rnd mags. PAB / PROX rounds are drone-killers - point at the UAV and the fuze bursts near it. The M72A7 comes as separate FA launchers, one per round.") +
    R("Mk400 HV / Mk401 AP / Mk402 PAB (6.8x51)") + "General purpose / tungsten AP / proximity airburst" + NL +
    R("Mk408 UW (6.8x51)") + "RM277 UW underwater dart" + NL +
    R("Mk405 HV / Mk406 AP / Mk407 PAB (6x38)") + "NX family and KAC AMG" + NL +
    R("Mk327 / XM891 / Mk332 / Mk361 / Mk368K-L (5.56)") + "M27A5 on rearma STANAG and PMAG bodies" + NL +
    R("Mk432 AP / Mk433 SUB (4.6x30)") + "MP7A2 - tungsten penetrator / subsonic" + NL +
    R("Mk422 AP / Mk423 SUB (9x19)") + "M17 / M18 - tungsten +P / 147 gr subsonic" + NL +
    R("M72A10 TNDM / M72A11 TBX / M72A12 PROX") + "66mm tandem HEAT ~350 mm / thermobaric / C-UAS airburst"],

  ["Rearma - Russia",
    H("AK35 / RPK35 / ADS35 / RPL 35 / PKP / SVCh / MP-443 / KS-23 / RPG-26 / RShG-2 - rearma_rus") +
    U("Loads only with rearma's Russian weapons, on rearma's own mags and belts (plain and camo). The 7N56 shot loads in the AK35 pellet mags. 7N55, Barrikada-AB and AB-26 are drone-killers - point at the UAV and the fuze bursts near it. The RPG-26 and RShG-2 come as separate FA launchers, one per round.") +
    R("7N44 HP / 7N48 CT / 7U5 SubAP / 7N55 HEAB (5.45)") + "AK35 30 / 45Rnd, RPK35 drum, RPL 35 belt (no subsonic belt)" + NL +
    R("7N56K / 7N56L AD (5.45)") + "Anti-drone shot, 7 pellets 90 m / 5 pellets 180 m" + NL +
    R("PSP-2 UW (5.45)") + "ADS35 underwater dart" + NL +
    R("Ball HV / 7N49 AP / 7U18 SUB (7.62x54R)") + "PKP belt (ball / AP), SVCh 10Rnd" + NL +
    R("Mk371 250 / 285 / 300gr, Mk373 PAB (.338 LM)") + "SVCh / SV-98M 10Rnd" + NL +
    R("7N53 AP / 7U17 SUB (9x19)") + "MP-443 tungsten core / MP-446 S subsonic" + NL +
    R("Shrapnel-AD50 / AD100 (23mm)") + "KS-23 anti-drone shot, 50 m / 100 m" + NL +
    R("Barrikada-AB (23mm)") + "KS-23 proximity airburst slug" + NL +
    R("RPG-26M2 TNDM / RPG-26 AB PROX / RShG-2M2 TBX") + "72.5mm tandem ~600 mm / C-UAS airburst / thermobaric"],

  ["Rearma - China",
    H("QBZ-191 / QJS-201 / QBW-201 / QBU-201 / QBU-202 / QBS-09 / QCQ-171 / QLU-11 / QN-205 / PF-89 - rearma_cn") +
    U("Loads only with rearma's Chinese weapons, on rearma's own mags (plain, transparent, AP-marked). The QLU-11 fires the whole FA 40mm lineup in 35mm at reduced power: DFK-135, DFP-135 and QN-205B airburst on the Mk364 dial, and the DFZ carriers deploy by chute at apex. The PF-89A and WPF-89 come as separate FA launchers, one per round.") +
    R("5.8 Ball HV / DBP-39 CT / DBP-40 AP / DBJ-39 PAB") + "QBZ / QBU-191 30Rnd, QJS-201 belt" + NL +
    R("DBS-39K / DBS-39L AD (5.8)") + "Anti-drone shot in the QBZ pellet mags, 8 pellets 110 m / 6 pellets 210 m" + NL +
    R("DBP-41 / DBP-42 SubAP / DBJ-41 PAB (8.6x39)") + "QBW-201 supersonic / subsonic tungsten / airburst" + NL +
    R("DBP-43 AP / DBP-44 SUB (9x21)") + "QCQ-171 and QSZ-92 - tungsten core / subsonic" + NL +
    R("Mk371 250 / 285 / 300gr, Mk373 PAB (.338 LM)") + "QBU-202 5Rnd" + NL +
    R("DBJ-127 PAB, Mk250, Mk211 Mod 2 (12.7x108)") + "QBU-201" + NL +
    R("Mk350-353 / Mk360 AD / Mk363 PAB-S, buck / bird (12 ga)") + "QBS-09" + NL +
    R("DFK-135 PAB / DFP-135 HE-P / DFJ-135 DP / DFB-135 TBK (35mm)") + "QLU-11 airburst / HE-P / dual-purpose / buckshot" + NL +
    R("DFZ-130 NRP / 133 EMP / 134 MSmoke / 135 Decoy / 136 UGS / 138 Jammer") + "QLU-11 ISR / EW carriers, ~0.75x the 40mm effect" + NL +
    R("QN-205T TNDM / QN-205B TBX / QN-205D C-UAS") + "Mini-missiles - tandem ~450 mm / thermobaric airburst / drone seeker" + NL +
    R("PF-89C TNDM / PF-89K PROX / WPF-89C TBX") + "80mm tandem ~675 mm / C-UAS airburst / thermobaric"],

  ["40mm ISR / EW",
    H("Mk380 block - smart UGL support payloads") +
    "Inert carriers: pop a HuntIR-style chute at apex, deploy on landing." + NL +
    U("Fire from any UGL like a normal grenade - set range with the ACE UGL zeroing (or vanilla PageUp / PageDown). The carrier deploys on its own: chute at apex, payload activates where it lands. Lob it past the tree line, not at a point target.") +
    R("Mk380 NR-P") + "Network relay; extends squad data-link" + NL +
    R("Mk383 EMP-M") + "Soft-kill EW burst - downs drones, whites-out optics, jams comms" + NL +
    R("Mk384 M-SMK") + "Multispectral (visual + thermal) smoke" + NL +
    R("Mk385 DCOY") + "IR / RF decoy that baits loitering munitions" + NL +
    R("Mk386 UGS") + "Unattended ground sensor; persistent contact picket" + NL +
    R("Mk388 JAM") + "Area comms / GNSS jammer bubble"],

  ["Counter-UAS PAB",
    H("Hard-kill drone rounds - proximity airburst") +
    "Targets UAVs only (unitIsUAV); MP-safe damage. Falls back to ball if the fuze script is not loaded." + NL +
    U("Point and shoot at the drone - the fuze bursts on its own as the round passes close. No lock, no dialing. Lead a moving drone the same as any target; near-misses still kill. The 40mm Mk364 is the exception - it uses the dialled airburst range (see Overview).") +
    R("Mk361 PAB") + "5.56 proximity airburst" + NL +
    R("Mk362 PAB") + "7.62 proximity airburst" + NL +
    R("Mk363 PAB") + ".300 BLK supersonic proximity airburst" + NL +
    R("Mk367 PAB") + "6.5 caseless (MX / Mk200 / MSBS)" + NL +
    R("Mk366 PAB") + "12.7x99 heavy, vehicle HMG" + NL +
    R("Mk373 PAB") + ".338 LM precision long-range" + NL +
    R("Mk364 PAB") + "40mm programmable airburst - ACE menu / CBA keybind sets range; HE on impact" + NL +
    R("Mk389") + "40mm tungsten buckshot" + NL +
    R("Mk368K/L AD") + "5.56 buckshot - 8 pellets/100 m (K), 5 pellets/200 m (L), config only" + NL +
    R("Mk369K/L AD") + "7.62 buckshot - 12 pellets/150 m (K), 10 pellets/250 m (L), config only" + NL +
    R("Mk360 AD") + "12 ga dense spread (config only, no script)"],

  ["MAAWS (Carl Gustaf M4)",
    H("84mm recoilless - 2040 round family - maaws") +
    "Fires from the vanilla MAAWS Mk4; the launcher gains lock-on only when a seeker round is loaded." + NL +
    U("Aim through the launcher's FCS optic - lase the target to auto-zero the reticle, then fire. The unguided rounds (HEAT 665, HE 448) fly the vanilla trajectory the reticle is built for, so they hit on the aimpoint. GM 841 homes on a laser spot - keep a designator on target. HEAT 758 (top-attack) and the seeker rounds (ADM 487 IR, AAM 517 IR) need a lock tone before you fire. HE 448 airburst uses the shared Mk364 range keybind (see Overview).") +
    R("HEAT 758 TT") + "Tandem fire-and-forget top-attack; dives onto turret roofs" + S("2040 - 850mm RHA, 1.2 km") + NL +
    R("HEAT 665 CS") + "Heavy tandem HEAT, confined-space - fire from enclosures" + S("2040 - 650mm RHA") + NL +
    R("HE 448 AB") + "Prefragmented HE, programmable airburst - trenches, rooftops, cover (Mk364 airburst keybind dials the range)" + S("2040 - 1.5 km") + NL +
    R("GM 841") + "Semi-active laser homing vs movers / bunkers - lase and fire" + S("2040 - 2 km") + NL +
    R("ADM 484 PROX") + "C-UAS proximity frag, single drone" + S("600 m") + NL +
    R("ADM 486 CAN") + "Tungsten flechette canister - wall of darts for a close swarm" + S("150 m") + NL +
    R("ADM 487 SEEK") + "IR fire-and-forget vs a locked drone" + S("1 km") + NL +
    R("AAM 517 SR") + "Last-ditch VSHORAD - helos, low/slow air, large UAS; half the Titan envelope by design" + S("1.75 km")],

  ["Mk 153 SMAW (JCA)",
    H("83mm shoulder assault weapon - 2040 - jca_mk153") +
    "Fires from the JCA Mk153 (a separate addon, loads only with the JCA launcher). MAAWS-tier but anti-structure flavored; damage sits a notch below the Titan launchers by design. The PWS model carries a fire-control range sight." + NL +
    U("Aim through the PWS fire-control sight where fitted; the plain model is iron-sight direct fire. Mk22 GS is guided - keep the crosshair on the target and steer it in (manual / SACLOS), best off the PWS sight. Mk3 HEDP airburst uses the shared Mk364 range keybind (see Overview); Mk18 ADM just point at the drone (proximity fuze).") +
    R("Mk6 Mod 2 HEAA-T") + "Tandem anti-armor, defeats ERA" + S("2040 - ~720mm RHA, 500 m") + NL +
    R("Mk3 Mod 2 HEDP-P") + "Dual-purpose HE + shaped, programmable airburst (Mk364 keybind)" + S("2040 - ~270mm RHA, 500 m") + NL +
    R("Mk80 Mod 1 NE") + "Thermobaric - bunker / room clearer, overpressure kill" + S("2040 - 400 m") + NL +
    R("Mk7 CS") + "Tandem HEAT, confined-space - fire from enclosures" + S("2040 - ~600mm RHA, 300 m") + NL +
    R("Mk85 FTG") + "Follow-through grenade - breach the wall, grenade detonates inside the room" + S("250 m") + NL +
    R("Mk22 GS") + "Guided precision, tandem dual-purpose - steer to the PWS crosshair" + S("2040 - ~675mm RHA, 800 m") + NL +
    R("Mk18 ADM") + "C-UAS prefragmented proximity - drones and loitering munitions" + S("500 m")],

  ["Vorona / RPG-32 / RPG-7",
    H("2040 launcher tiers under the MAAWS - vorona / rpg") +
    "Tier: RPG-7 < RPG-32 < Vorona < MAAWS. The Vorona keeps its SACLOS manual guidance; both RPGs stay unguided." + NL +
    U("Vorona (Grom / Oskol): SACLOS - hold the crosshair on the target through the whole flight and the missile steers to it; Osa needs an IR lock tone first. Both RPGs are unguided iron-sight rockets - use the sight range steps and lead movers. Oskol airburst uses the shared Mk364 range keybind (see Overview).") +
    R("9M135M Grom") + "Vorona tandem SACLOS anti-tank" + S("2040 - 800mm RHA, 1.8 km") + NL +
    R("9M135F-2 Oskol") + "Vorona thermobaric + prefrag, programmable airburst (Mk364 airburst keybind)" + S("2040 - 1.6 km") + NL +
    R("9M135PVO Osa") + "Vorona IR lock-on vs helos, low/slow air and drones - lock tone, fire" + S("2040 - 1.2 km") + NL +
    R("PG-32V-2") + "RPG-32 tandem HEAT" + S("2040 - 700mm RHA, 500 m") + NL +
    R("TBG-32V-2") + "RPG-32 thermobaric" + S("400 m") + NL +
    R("AB-32 PROX") + "RPG-32 C-UAS proximity airburst" + S("300 m") + NL +
    R("PG-7VR-2") + "RPG-7 tandem HEAT - the cheapest tandem in the set" + S("2040 - 550mm RHA, 330 m") + NL +
    R("TBG-7V-2") + "RPG-7 thermobaric room-clearer" + S("200 m") + NL +
    R("AB-7 PROX") + "RPG-7 poor-man's counter-drone airburst" + S("200 m")],

  ["Vehicle & aircraft missiles",
    H("Turret / pylon guided munitions - 2040 - missiles") +
    "Crewed-platform and pylon ordnance, not arsenal items - they ride vanilla missile bodies, so they show up in vehicle turrets and the dynamic-loadout (pylon) editor." + NL +
    R("BGM-185 Broadsword") + "Ground-vehicle tandem F&F top-attack ATGM, NLOS-capable" + S("2040 - 1300mm RHA, 10 km") + NL +
    R("AGM-190 Wraith") + "Helo / UCAV tri-mode tandem HEAT + frag, LOAL" + S("2040 - 1200mm RHA, 12 km") + NL +
    R("AGM-205 Warhammer") + "Fixed-wing standoff blast-frag, anti-structure / anti-ship" + S("2040 - 25 km") + NL +
    R("AGR-40 Hydra-P") + "Laser-guided multipurpose rocket pod, C-UAS proximity mode" + S("2040 - 600mm RHA, 8 km") + NL +
    R("XM1200 Copperhead") + "Loitering munition - orbit and autonomous terminal, or lock before launch" + S("2040 - 800mm RHA, 40 km") + NL +
    R("MIM-165 Sentry") + "Dual-seeker SAM, proximity prefrag - jets down to drones" + S("2040 - 12 km") + NL +
    R("MIM-166 Roadrunner") + "C-UAS hard-kill missile, proximity prefrag - drones + loitering munitions" + S("2040 - 4 km") + NL +
    "<font color='#E9A63C'>Man-portable</font>  Broadsword / Copperhead also load on the shoulder Titan AT launcher, and Sentry / Roadrunner on the shoulder Titan AA launcher (single-round infantry tubes) - same rounds, same range." + NL +
    U("From a vehicle turret or pylon (or the shoulder Titan for the four man-portable rounds above). Lock, then fire: Broadsword, Wraith, Sentry, Roadrunner, Warhammer. Laser-guided (keep a designator on the target): Hydra-P. Copperhead: launch WITHOUT a lock to loiter and hunt autonomously, or lock a target first for a direct run.")],

  ["Autocannon (medium)",
    H("30 / 35 / 50 mm - mediumcaliber") +
    R("30mm APFSDS-T") + "Tungsten long-rod (Red OPFOR gradient variant)" + S("2033") + NL +
    R("30mm API-T") + "Armor-piercing incendiary" + NL +
    R("30mm HEI-T") + "High-explosive incendiary" + NL +
    R("30mm ABM") + "Programmable airburst - defilade defeat" + S("2036") + NL +
    R("30mm PROX") + "Counter-UAS proximity airburst" + S("2036") + NL +
    R("35mm AHEAD") + "Timed tungsten sub-projectile airburst" + NL +
    R("50mm HEAB / APFSDS") + "XM913-class flagship - dormant, no 50mm platform in this modset" + S("2039") + NL +
    U("Vehicle natures - selected from the turret ammo menu. The PROX / ABM airburst rounds carry an automatic proximity fuze that bursts near air and soft targets on their own; no range to dial. AP / APFSDS are point rounds - just fire.")],

  ["Tank main gun",
    H("120 / 125 mm - maincaliber") +
    R("120mm APFSDS-T") + "Tungsten long-rod penetrator (Red OPFOR variant)" + S("2033") + NL +
    R("120mm AMP") + "Programmable multi-purpose - point / delay / airburst" + NL +
    R("120mm HEAT-MP") + "Multi-purpose shaped charge" + NL +
    R("120mm HE-AB") + "Programmable airburst" + S("2036") + NL +
    R("125mm 3BM70 Vacuum-2") + "APFSDS-T tungsten long-rod" + S("2033") + NL +
    R("125mm 3BK-31 Breza") + "Tandem HEAT multi-purpose" + NL +
    R("125mm 3OF-82") + "HE, programmable airburst" + S("2036") + NL +
    R("125mm 9M119M2 Refleks-M") + "Gun-launched SACLOS ATGM, 5 km" + NL +
    U("Pick the nature from the turret ammo menu. The HE-AB / AMP airburst natures self-fuze - they burst near air and soft targets on their own; APFSDS is a direct-fire point round and HEAT-MP works point or against structures with no setup.")],

  ["Mortars (82 / 120 mm)",
    H("Guided & smart mortar bombs - vehicles / rf") +
    "Per-side naming: NATO Mk/XM/M, CSAT Type, AAF AF-. 82mm rides the vanilla mortar; the 120mm twin is a Reaction Forces vehicle (jmfsb_fa_rf)." + NL +
    U("Fire from the mortar's turret ammo menu. Guided natures need their cue - APMI a grid, LGM a laser spot, STRIX armor beneath the apex. HE-ER / smoke / illum are ballistic - use the computer.") +
    R("XM395-2 APMI / XM1113-P") + "82 / 120mm GPS precision to a grid" + NL +
    R("M-LGM / M-LGM120") + "Laser-homing on a designated spot" + NL +
    R("M-STRIX AT / M-STRIX 120") + "Top-attack anti-armor sensor bomb" + NL +
    R("M821E1 / M934E1 HE-ER") + "Extended-range prefragmented HE" + NL +
    R("M-SMK / M-TB") + "Multispectral smoke / thermobaric" + NL +
    R("M853 IR") + "82mm IR illumination (NVG)"],

  ["Field & rocket artillery",
    H("155mm SPG + 230mm MLRS - vehicles") +
    "Per-side naming (NATO Mk/XM/M, CSAT Type, AAF AF-). Fired from self-propelled guns and the MLRS." + NL +
    U("Artillery computer / fire mission. GPS (Excalibur) and laser (Krasnopol / CLGP) natures are first-round precision; SADARM / AW submunitions self-target armor under the apex; mines build a scatterable field.") +
    R("M795E1 HE-ER") + "155mm extended-range prefrag HE" + NL +
    R("M982E1 Excalibur") + "155mm GPS precision" + NL +
    R("M-CLGP / Krasnopol") + "155mm laser-guided" + NL +
    R("M898 SADARM-2") + "155mm sensor-fuzed top-attack AT" + NL +
    R("M692 ADAM / M718 RAAMS") + "155mm scatterable AP / AT mines" + NL +
    R("M31E2 GMLRS-U") + "230mm guided unitary" + NL +
    R("M403 GMLRS-ER") + "230mm extended-range HE" + NL +
    R("M-AW") + "230mm sensor-fuzed AT submunitions"],

  ["Naval gunfire (120 mm)",
    H("Destroyer main gun - vehicles") +
    U("From the ship's gun. Vulcano GLR reaches ~40 km on GPS/IIR; LG homes on a laser; the rest are ballistic naval support.") +
    R("Vulcano-120 GLR") + "Guided extended-range, ~40 km" + NL +
    R("Mk-HE 120N") + "Ballistic naval HE" + NL +
    R("Mk-LG 120N") + "Laser-guided vs movers / shore" + NL +
    R("Mk-SFM 120N") + "Sensor-fuzed submunition" + NL +
    R("Mk-SMK 120N") + "Multispectral smoke"],

  ["Vehicle HMG belts (12.7x108)",
    H("East heavy MG - NSVT-class - vehicles") +
    "12.7x108 belts to match the West .50 belts; 7N42 turns the HMG into a drone-killer." + NL +
    R("7N40 AP-T") + "Tungsten AP-tracer" + NL +
    R("7N41 HEIAP") + "HE incendiary AP" + NL +
    R("7N42 HEAB") + "Proximity airburst, C-UAS (PAB script)"],

  ["Aircraft AA & strike missiles",
    H("Fixed-wing pylon ordnance - missiles") +
    "Dynamic-loadout (pylon) items - three per-side AA seeker tiers plus strike missiles. Naming: NATO / Russia / Europe." + NL +
    U("Load from the pylon editor. Radar AA locks beyond visual range; IR AA is short-range high-off-boresight. SEAD homes on emitters, anti-ship on ships, cruise on a grid.") +
    R("AIM-9X Blk III / R-74M / IRIS-T") + "Short-range IR AA (35 km)" + NL +
    R("AIM-120E / R-77M / MICA-NG") + "Medium-range radar AA (160 km)" + NL +
    R("AIM-260 JATM / R-37M / Meteor") + "Long-range radar AA" + NL +
    R("AGM-88G AARGM-ER / Kh-31PD") + "SEAD anti-radiation" + NL +
    R("AGM-158D JASSM-XR / Kh-101 / SCALP-EG") + "Standoff cruise" + NL +
    R("AGM-158C LRASM / Kh-35UE / RBS-15 Mk4") + "Anti-ship"],

  ["RC40 (Reaction Forces)",
    H("40mm revolver-grenade payloads - rf") +
    U("Fire like a UGL grenade from the RC40. AD is a drone-killer (proximity); MS screens visual + thermal.") +
    R("RC40 HE-P") + "HE point-detonation" + NL +
    R("RC40 DP") + "Dual-purpose HE + shaped charge" + NL +
    R("RC40 MS") + "Multispectral smoke" + NL +
    R("RC40 AD") + "Anti-drone proximity airburst (PAB script)"]
];

// add reversed so "Overview" lands on top
{
    _unit createDiaryRecord [_subject, [_x select 0, _x select 1]];
} forEach (+_entries call { reverse _this; _this });
