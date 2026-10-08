# futureAmmo - findings for the mod

A review of futureAmmo carried out while porting it into the jmfsb mod.
Tier work is deliberately excluded - this is only what applies to FA as it
ships on its own.

Base game values throughout come from an index of the unpacked A3 tree,
resolved through inheritance so a tracer round reports the numbers it
actually has. The full table is `docs/AMMO_VANILLA.md` in jmfsb; the
round-by-round comparison is `docs/AMMO_COMPARE.md`.

## 1. Integrity: nothing broken

Checked across all 30 addons and every `.hpp`, not just the standard
filenames - futureAmmo spreads definitions over `CfgAmmo_compat.hpp`,
`CfgMag65_matrix.hpp` and `CfgMagazines_compat.hpp` as well:

| Check | Result |
|---|---|
| Classes defined | 6212 |
| `magazineWell` entries naming a magazine that does not exist | **0** |
| Magazines whose `ammo =` class does not exist | **0** |
| Ammo whose `submunitionAmmo` does not exist | **0** |
| Classes defined in more than one addon | **0** |

Worth saying plainly: the reference graph is clean. The compat aliases in
`CfgAmmo_compat.hpp` / `CfgMagazines_compat.hpp` do their job - every old
pre-side-prefix name a magazine well still uses resolves to a real class.

**A warning for anyone auditing this mod.** Reading only `CfgAmmo.hpp` and
`CfgMagazines.hpp` produces a large and completely false list of broken
references - it misses the compat aliases and the 6.5 matrix. That mistake
was made here first and is easy to repeat.

## 2. Rounds below the base game on penetration (20)

`caliber` is where FA leads the base game almost everywhere - 393 rounds
above, and the ones below are listed here in case any are unintended.
Tracer variants are collapsed into their parent.

| Round | Base game class | FA caliber | vanilla | Defined in |
|---|---|---:|---:|---|
| `FA_Sh_105mm_APFSDS` | `Sh_120mm_APFSDS` | 22 | 35.2688 | `maincaliber/CfgAmmo.hpp` |
| `FA_Sh_105mm_HEATMP` | `Sh_120mm_HEAT_MP` | 14 | 34 | `maincaliber/CfgAmmo.hpp` |
| `FA_Sh_105mm_HEOB` | `Sh_120mm_HE` | 6 | 10 | `maincaliber/CfgAmmo.hpp` |
| `FA_Sh_120mm_APFSDS` | `Sh_120mm_APFSDS` | 19.5 | 35.2688 | `maincaliber/CfgAmmo.hpp` |
| `FA_Sh_120mm_APFSDS_Red` | `Sh_120mm_APFSDS` | 18.4 | 35.2688 | `maincaliber/CfgAmmo.hpp` |
| `FA_Sh_125mm_APFSDS` | `Sh_125mm_APFSDS` | 20.15 | 34.8387 | `maincaliber/CfgAmmo.hpp` |
| `FA_ammo_Penetrator_82_strix` | `ammo_Penetrator_Base` | 33.3 | 40 | `vehicles/CfgAmmo.hpp` |
| `FA_ammo_Penetrator_PG7VR2` | `ammo_Penetrator_Base` | 36.7 | 40 | `rpg/CfgAmmo.hpp` |
| `FA_ammo_Penetrator_smaw_HEDP` | `ammo_Penetrator_Base` | 18 | 40 | `jca_mk153/CfgAmmo.hpp` |
| `FA_b_12G_Mk352_APS` | `B_12Gauge_Slug` | 2.2 | 3 | `ammo/CfgAmmo.hpp` |
| `FA_b_12G_Mk353_BRC` | `B_12Gauge_Slug` | 0.15 | 3 | `ammo/CfgAmmo.hpp` |
| `FA_b_12G_Mk360_AD_Sub` | `B_12Gauge_Pellets_Submunition` | 0.9 | 1 | `ammo/CfgAmmo.hpp` |
| `FA_b_12G_Mk363_PABS` | `B_12Gauge_Slug` | 0.8 | 3 | `ammo/CfgAmmo.hpp` |
| `FA_b_300_Mk335` | `B_762x51_Ball` | 1.4 | 1.6 | `ammo/CfgAmmo.hpp` |
| `FA_b_300_Mk336` | `B_762x51_Ball` | 1.5 | 1.6 | `ammo/CfgAmmo.hpp` |
| `FA_b_556_Mk368K_AD_Sub` | `B_12Gauge_Pellets_Submunition` | 0.5 | 1 | `antidrone/CfgAmmo.hpp` |
| `FA_b_556_Mk368L_AD_Sub` | `B_12Gauge_Pellets_Submunition` | 0.6 | 1 | `antidrone/CfgAmmo.hpp` |
| `FA_b_762_Mk369K_AD_Sub` | `B_12Gauge_Pellets_Submunition` | 0.5 | 1 | `antidrone/CfgAmmo.hpp` |
| `FA_b_762_Mk369L_AD_Sub` | `B_12Gauge_Pellets_Submunition` | 0.55 | 1 | `antidrone/CfgAmmo.hpp` |
| `FA_rf_ammo_127x55_7U14` | `B_127x99_Ball` | 1.6 | 2.6 | `rf/CfgAmmo.hpp` |

## 3. Rounds below the base game on damage (56)

These are rounds whose NATURE is unchanged - a ball round is still a ball
round - but which hit for less than the base game round they inherit from.
Rounds that changed nature (smoke, EMP, decoy, jammer, UGS, proximity) are
in the next section instead, because comparing their `hit` to an HE shell's
is meaningless.

This may all be deliberate: FA clearly trades damage for penetration and
velocity. It is listed so the trade is a decision on the record rather than
an accident.

| Round | Base game class | FA hit | vanilla | Defined in |
|---|---|---:|---:|---|
| `FA_120_strix` | `ammo_ShipCannon_120mm_HE_guided` | 90 | 300 | `rf/CfgAmmo.hpp` |
| `FA_120_strix_I` | `ammo_ShipCannon_120mm_HE_guided` | 90 | 300 | `rf/CfgAmmo.hpp` |
| `FA_120_strix_O` | `ammo_ShipCannon_120mm_HE_guided` | 90 | 300 | `rf/CfgAmmo.hpp` |
| `FA_40mm_Mk380_NRP` | `G_40mm_HE` | 0 | 80 | `grenade_40mm/CfgAmmo.hpp` |
| `FA_82_strix` | `Sh_82mm_AMOS_guided` | 90 | 165 | `vehicles/CfgAmmo.hpp` |
| `FA_82_strix_I` | `Sh_82mm_AMOS_guided` | 90 | 165 | `vehicles/CfgAmmo.hpp` |
| `FA_82_strix_O` | `Sh_82mm_AMOS_guided` | 90 | 165 | `vehicles/CfgAmmo.hpp` |
| `FA_B_35mm_AHEAD` | `B_35mm_AA` | 45 | 60 | `mediumcaliber/CfgAmmo.hpp` |
| `FA_M_AGM205_Warhammer` | `Missile_AGM_02_F` | 750 | 1100 | `missiles/CfgAmmo.hpp` |
| `FA_M_AGR40_HydraP` | `M_PG_AT` | 90 | 95 | `missiles/CfgAmmo.hpp` |
| `FA_M_MIM166_Roadrunner` | `M_Titan_AA` | 55 | 80 | `missiles/CfgAmmo.hpp` |
| `FA_M_Vorona_9M135PVO` | `M_Titan_AA` | 75 | 80 | `vorona/CfgAmmo.hpp` |
| `FA_M_antiship` | `Missile_AGM_02_F` | 700 | 1100 | `missiles/CfgAmmo.hpp` |
| `FA_M_cruise` | `Missile_AGM_02_F` | 900 | 1100 | `missiles/CfgAmmo.hpp` |
| `FA_M_smaw_Mk22_GS` | `M_Titan_AT` | 85 | 95 | `jca_mk153/CfgAmmo.hpp` |
| `FA_R_RPG32_AB32` | `R_TBG32V_F` | 110 | 200 | `rpg/CfgAmmo.hpp` |
| `FA_R_RPG7_AB7` | `R_PG7_F` | 85 | 95 | `rpg/CfgAmmo.hpp` |
| `FA_R_smaw_Mk3Mod2_HEDP` | `R_MRAAWS_HE_F` | 80 | 200 | `jca_mk153/CfgAmmo.hpp` |
| `FA_R_smaw_Mk6Mod2_HEAA` | `R_MRAAWS_HEAT55_F` | 80 | 95 | `jca_mk153/CfgAmmo.hpp` |
| `FA_R_smaw_Mk7_CS` | `R_MRAAWS_HEAT55_F` | 75 | 95 | `jca_mk153/CfgAmmo.hpp` |
| `FA_R_smaw_Mk80Mod1_NE` | `R_MRAAWS_HE_F` | 90 | 200 | `jca_mk153/CfgAmmo.hpp` |
| `FA_R_smaw_Mk85_FTG` | `R_MRAAWS_HEAT55_F` | 70 | 95 | `jca_mk153/CfgAmmo.hpp` |
| `FA_ammo_Penetrator_smaw_HEDP` | `ammo_Penetrator_Base` | 200 | 300 | `jca_mk153/CfgAmmo.hpp` |
| `FA_ammo_RC40_DP` | `G_40mm_HE` | 60 | 80 | `rf/CfgAmmo.hpp` |
| `FA_b_12G_Mk350_TBS_Sub` | `B_12Gauge_Pellets_Submunition` | 8 | 20 | `ammo/CfgAmmo.hpp` |
| `FA_b_12G_Mk351_FLE_Sub` | `B_12Gauge_Pellets_Submunition` | 5 | 20 | `ammo/CfgAmmo.hpp` |
| `FA_b_12G_Mk352_APS` | `B_12Gauge_Slug` | 30 | 42 | `ammo/CfgAmmo.hpp` |
| `FA_b_12G_Mk353_BRC` | `B_12Gauge_Slug` | 35 | 42 | `ammo/CfgAmmo.hpp` |
| `FA_b_12G_Mk360_AD_Sub` | `B_12Gauge_Pellets_Submunition` | 6 | 20 | `ammo/CfgAmmo.hpp` |
| `FA_b_12G_Mk363_PABS` | `B_12Gauge_Slug` | 4 | 42 | `ammo/CfgAmmo.hpp` |
| `FA_b_300_Mk335` | `B_762x51_Ball` | 9 | 11.6 | `ammo/CfgAmmo.hpp` |
| `FA_b_300_Mk336` | `B_762x51_Ball` | 10 | 11.6 | `ammo/CfgAmmo.hpp` |
| `FA_b_300_Mk337` | `B_762x51_Ball` | 11 | 11.6 | `ammo/CfgAmmo.hpp` |
| `FA_b_300_Mk341_SubAP` | `B_762x51_Ball` | 10 | 11.6 | `ammo/CfgAmmo.hpp` |
| `FA_b_300_Mk342_Sub` | `B_762x51_Ball` | 8 | 11.6 | `ammo/CfgAmmo.hpp` |
| `FA_b_300_Mk343_Sub` | `B_762x51_Ball` | 9 | 11.6 | `ammo/CfgAmmo.hpp` |
| `FA_b_300_XM345_SubAP2` | `B_762x51_Ball` | 11 | 11.6 | `ammo/CfgAmmo.hpp` |
| `FA_b_40mm_Mk389_TBK_Sub` | `B_12Gauge_Pellets_Submunition` | 11 | 20 | `ammo/CfgAmmo.hpp` |
| `FA_b_556_Mk327_HV` | `B_556x45_Ball` | 8 | 9 | `ammo/CfgAmmo.hpp` |
| `FA_b_556_Mk332_AP` | `B_556x45_Ball` | 8 | 9 | `ammo/CfgAmmo.hpp` |
| `FA_b_556_Mk368K_AD_Sub` | `B_12Gauge_Pellets_Submunition` | 4.5 | 20 | `antidrone/CfgAmmo.hpp` |
| `FA_b_556_Mk368L_AD_Sub` | `B_12Gauge_Pellets_Submunition` | 6 | 20 | `antidrone/CfgAmmo.hpp` |
| `FA_b_556_XM891_CTEP` | `B_556x45_Ball` | 8 | 9 | `ammo/CfgAmmo.hpp` |
| `FA_b_762_Mk369K_AD_Sub` | `B_12Gauge_Pellets_Submunition` | 4.5 | 20 | `antidrone/CfgAmmo.hpp` |
| `FA_b_762_Mk369L_AD_Sub` | `B_12Gauge_Pellets_Submunition` | 5.5 | 20 | `antidrone/CfgAmmo.hpp` |
| `FA_i_556_AF556C_CT` | `B_556x45_Ball` | 8 | 9 | `ammo/CfgAmmo.hpp` |
| `FA_i_556_AF556P_AP` | `B_556x45_Ball` | 8 | 9 | `ammo/CfgAmmo.hpp` |
| `FA_i_556_AF556_HV` | `B_556x45_Ball` | 8 | 9 | `ammo/CfgAmmo.hpp` |
| `FA_o_545x39_7N44_HP` | `B_762x39_Ball_F` | 10 | 11 | `ammo/CfgAmmo.hpp` |
| `FA_o_545x39_7N48_CT` | `B_762x39_Ball_F` | 10 | 11 | `ammo/CfgAmmo.hpp` |
| `FA_o_545x39_7U5_SubAP` | `B_762x39_Ball_F` | 8 | 11 | `ammo/CfgAmmo.hpp` |
| `FA_o_ammo_62_DBJ25_PAB` | `B_65x39_Caseless` | 6 | 10 | `csat62/CfgAmmo.hpp` |
| `FA_o_ammo_62_DBP25` | `B_65x39_Caseless` | 8 | 10 | `csat62/CfgAmmo.hpp` |
| `FA_o_ammo_62_DBP26_AP` | `B_65x39_Caseless` | 8 | 10 | `csat62/CfgAmmo.hpp` |
| `FA_o_ammo_62_DBP88B` | `B_65x39_Caseless` | 9 | 10 | `csat62/CfgAmmo.hpp` |
| `FA_smaw_FTG_grenade` | `R_MRAAWS_HE_F` | 70 | 200 | `jca_mk153/CfgAmmo.hpp` |

## 4. Different nature, not weaker (10)

Listed only so they are not mistaken for the section above. A smoke round
with `hit = 0` inheriting a 40 mm HE grenade is not a regression.

| Round | Base game class | FA hit | vanilla |
|---|---|---:|---:|
| `FA_40mm_Carrier_Base` | `G_40mm_HE` | 0 | 80 |
| `FA_40mm_Mk383_EMP` | `G_40mm_HE` | 0 | 80 |
| `FA_40mm_Mk384_MSmoke` | `G_40mm_HE` | 0 | 80 |
| `FA_40mm_Mk385_Decoy` | `G_40mm_HE` | 0 | 80 |
| `FA_40mm_Mk386_UGS` | `G_40mm_HE` | 0 | 80 |
| `FA_40mm_Mk388_Jammer` | `G_40mm_HE` | 0 | 80 |
| `FA_M_MRAWS_ADM487` | `M_Titan_AA` | 70 | 80 |
| `FA_R_MRAWS_ADM484` | `R_MRAAWS_HE_F` | 130 | 200 |
| `FA_R_MRAWS_ADM486` | `R_MRAAWS_HE_F` | 10 | 200 |
| `FA_R_smaw_Mk18_ADM` | `R_MRAAWS_HE_F` | 85 | 200 |

## 5. One question

`FA_40mm_Carrier_Base` inherits `G_40mm_HE` and sets `hit = 0`. If it is a
structural base that nothing spawns directly, that is fine and this is
noise. If anything inherits it and is meant to do damage, it will not.

