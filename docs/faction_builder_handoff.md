# Faction Builder 2040 — Implementation Handoff

Companion data file: `weapon_pools_2040.md` (all classnames, tables, camo maps). This doc is the logic spec: feed a small input block in → get a complete faction out.

---

## 1. Faction input schema

```
name:     "Placeholder Front"
tag:      "PHF"              // classname prefix for generated classes
side:     EAST               // WEST | EAST | GUER
tier:     1                  // 0-4 — how good their stuff is
strength: 3                  // 1-5 — how many of them there are
shape:    balanced           // balanced | horde | elite | brittle
flavor:   (optional)         // west | east | irregular — overrides side default for gear lineage
camo:     (optional)         // faction camo key, filtered per-family via camo maps
caliber:  (optional)         // faction-wide caliber lock override (t3+ behavior)

// identity — free choice, should visually read as the tier
uniform:  [classnames]       // small array for variety
vest:     [classnames]
headgear: [classnames]
flag:     "path\to\flag.paa" // insignia + markers + CfgFactionClasses icon

// per-pool overrides (optional): rifle: ["classname"] skips the roll entirely
```

## 2. Selection pipeline (strict order — each step only narrows)

1. **SIDE** → default flavor; caliber access gates (see §4); side-locked items (MAAWS = WEST absolute)
2. **TIER** → family min-tiers; caliber min-tiers; discipline level; optics/laser/suppressor/NVG rules; drone load
3. **FLAVOR** (override) → gear lineage swap; side still gates calibers (west-flavored proxy gets MXs, never caseless 6.5)
4. **SHAPE** → specialist family access (elite); uniformity bias (elite prefers single-family, horde/irregular rolls wide); AI skill; brittle degradation flag
5. **ROLL** → family per group → caliber lock per discipline → variant per role → camo filter

Weighted roll: own tier 60% / one below 30% / older 10%.

## 3. Tier reference

| Tier | Label | Feel |
|---|---|---|
| 0 | broke insurgents | AK/SLR surplus, no optics, IED quads |
| 1 | funded insurgents / proxy | last-gen service rifles, patron toys, Gen1 NVG leaders |
| 2 | near-peer | modern rifles, IR lasers, Gen2 NVG all, FPV AT drones |
| 3 | peer | suppressed by default, thermal optics, designators, TI-seeker drones |
| 4 | peer+ | tier 3 gear + depth/mass; procurement freedom, attritable autonomy |

Strength drives: CfgGroups count/size, ALiVE-fork profile counts + force pool, reinforcement rate, vehicle group density. 1=cells, 3=battalion default, 5=endless.

Shape: balanced (default) · horde (low AI skill, echelon attacks — pair high strength) · elite (high skill, specialist access, +1 drone, uniform gear, t4 sensor kit at nominal t3) · brittle (drops one full tier after stockpile/logistics attrited — scripted campaign behavior).

US 2040 canon: tier 3 gear, tier 4 R&D, shape elite, low strength — procurement + recruiting crisis lore.

## 4. Caliber rules

Registry: 6.5 cased = WEST t2+ · 6.5 caseless = WEST t3+ (same rifles, next-gen ammo line) · 6.2 = EAST/GUER t2+ · legacy calibers free · specialist calibers (.300BLK, 12.7x55, .338, .50, .408, 9.3) own supply lines, discipline-exempt.

Discipline by tier: t0-1 none (mixed is authentic) · t2 one caliber per SQUAD (roll once per group) · t3+ one per FACTION (build-time, or `caliber:` input).
Exempt always: dmr, sniper, pistol, specialist calibers.

6.2 conversion ledger (jmfsbfa config work, separate task): FORT, Katiba, CMR-76, CAR-95 (or leave 5.8 — open), Type 115. G36/G433 → open canon call (6.5 vs stay 5.56).

## 5. Role + issuance rules

Roles: rifle, gl, carbine, ar, mg, dmr, sniper, shot, crew, pistol, at, atgm, aa, csw, seo.

- **mg = belt-fed ONLY.** Mag-fed autos live in `ar`. Fallbacks: mg→ar→rifle. East t0-1 has no belt-fed (PKM pending) — ar fallback is official there.
- Other fallbacks: dmr→rifle+optic · shot→rifle · crew(smg)→carbine→rifle · missing family role → next fallback, never break a template.
- MG caliber-matching: at t2+ prefer belt-fed matching the squad's locked caliber; fall through chain if none.
- **Sidearms:** t0 never both — most primary-only, 10-20% pistol-only, nobody unarmed · t1 leaders/crews/specialists only · t2+ everyone.
- **Snipers:** spawn only via sniper-team templates or elite shape. AM rifles are the anti-materiel option inside the slot t2+.
- **Specialist tag:** family never appears in general rolls; elite shape or explicit template request only (ASh-12, SCAR SOF use, Mk23, HK437, AM rifles, SDAR...).
- **Statics (csw):** ACE carry components in weapons-team inventories (2-man loads); emplacement spawns need assembled static vehicle classnames (separate dump, pending).
- **Drones: every squad carries 2-3.** t0-1: recon quad + IED/AP FPV · t2: +AT FPV · t3-4: recon + AT-TI + role pick (Kedr AA / designator / cargo-medical); elite +1. SEO carries primary.

## 6. Attachment rules (slot + caliber matched)

- t0: irons, ~10% scavenged collimator, flashlight only
- t1: collimator standard, magnified leaders/dmr, bipods on ar/mg/dmr/sniper (t1+), visible laser
- t2: magnified standard, **IR laser all primaries**, suppressors elite/specialist only
- t3-4: **suppressors default all primaries** (caliber table in pools doc; 65_TI thermal-insulated cans preferred at t3), thermal optics signature (Nightstalker/NVS leaders, tws rifles, tws_mg MGs, tws_sniper snipers)
- Pistol attachments lag one tier (suppressed pistols t3 elite, MRD t2+)
- Flash hiders = non-suppressed default t1+ where available
- EW cosmetic: muzzle_antenna_* for EW/SIGINT unit flavor

## 7. NVG ladder (kit layer)

t0 none · t1 leaders only (ACE Gen1) · t2 all (ACE Gen2 + vanilla side sets, WP variants) · t3 (ACE Gen4; west adds Compact/LPNVG; east O_NVGoggles) · t4/elite west LPNVG-T fusion + Ti goggles (US sensor edge; east stays t3 kit — their edge is mass).

## 8. Binocular-slot kit

t0 Binocular · t0-1 Yardage450 (broke-faction RF), Camera (GUER media flavor) · t2 Rangefinder (leaders/dmr/sniper) · t2-3 MX-2A thermal (recon/JFO) · t3-4 designators: east Laserdesignator_02 (+ghex); west vanilla Laserdesignator (pending dump).

## 9. Script outputs (what the builder generates)

1. Infantry classes per role with tier-appropriate full loadouts (authoring loop: arsenal export → getUnitLoadout arrays in pool file → spawn-hook `setUnitLoadout`; config bake from same arrays is a later optional step for editor-native units)
2. CfgGroups entries — visible to ALiVE fork profiles, alive_drones, Zeus
3. CfgFactionClasses entry (flag icon, side)
4. Per-faction toggle block: alive_drones behavior tier, ew-zones level, iads-emcon level, jmfsbfa ammo gradient slider, C-UAS effectiveness
5. Arsenal whitelist for the faction
6. Degradation hook for brittle shape (tier-drop on stockpile attrition — campaign layer)

Group templates (NOT YET DESIGNED — next design task, blocks output #2): which roles exist per squad per tier (t0 no MG slot, t1+ weapons teams: HMG/ATGM/mortar, t2+ AA specialist, sniper teams), crew groups, per-tier squad sizes. Same templates all sides for v1; side only changes what fills slots.

## 10. Capability toggles by tier (consumed by companion addons)

| Tier | drones (alive_drones) | EW (ew-zones) | IADS (iads-emcon) | C-UAS |
|---|---|---|---|---|
| 0 | single FPV, daylight, crude | none | none | small arms |
| 1 | loitering munitions, fiber FPV, night | crude area jam, fixed | MANPADS only | point jam |
| 2 | multi-ship recon-strike | mobile jam, TX-detect response | short/med, poor datalink | dedicated teams |
| 3 | autonomous SAD | precision DF → fires | integrated + EMCON | layered soft/hard kill |
| 4 | swarms | t3 denser | t3 denser | t3 denser |

## 11. Open items

**Blocking realism:** east PKM/PKP classnames (only hard hole).
**Stand-ins in place:** east bolt sniper t0-1, modern east dmr t3, modern east pistol t2+, O-Titans as east ATGM/AA, Kord at east t0, east t2 loitering munition (or canonize massed IED quads).
**⚑ arsenal checks:** h6, NCAR15, EF mxar line, FORT 651 role, SMG_04/Gepard/Diplomat tiers, vtf_MK13, hgun_Mk26, ace_milr_base, acc_o_FMS, KVN-vs-Crocus difference, Rev_* drone mod roles, SLR V/D variants.
**Canon calls:** G36/G433 caliber; CAR-95 5.8-vs-6.2; any additional side-locked items (Spike candidate).
**Not started:** group templates (next), vehicle pools, spawned-drone pools per tier, uniform/vest/helmet classname collection, per-family camo mapping table (suffix data exists in pools doc), grenades/medical kit lists, assembled-static vehicle classnames, west laser designator, faction cards for the actual campaign factions (tier/strength/shape assignments).

## 12. Implementation notes

- Engine: script side SQF (Arma 3), config side generated hpp/cpp; CBA settings for the runtime sliders; `magazines[] +=` append convention (established in jmfsbfa) to avoid PBO merge conflicts.
- Spawn hook lives in the ALiVE fork — one hook covers profiles, alive_drones crews, Zeus.
- Pool file is the single source of truth; script reads it (or a JSON/hpp transform of it) — adding a classname + tier tag must never require code changes.
- Per-family camo maps: each family declares its suffix set; faction `camo:` key maps through them; missing camo → family default; no camo key → random mix (irregular look).
- isJFO gating (`player getVariable ["isJFO", false]`) stays the support-access pattern for player-side integration.
