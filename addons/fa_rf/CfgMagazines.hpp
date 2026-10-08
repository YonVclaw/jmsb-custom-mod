// Reaction Forces 120mm Twin Mortar — 2040 side-named magazines. Each inherits
// the confirmed RF magazine body (so it chambers and, for the guided / laser /
// mine / AT-mine / cluster natures, inherits RF's own working mechanics). One
// body per nature; three side variants (_B West / _O East / _I Ind) with the
// West/East/Ind naming convention. Fed to Twin_Mortar_120mm_RF in CfgWeapons.hpp.
//
// Natures still pending (need the RF ammo classnames to author distinct 2040
// ammo, since they share a body with another nature or have no RF body):
//   STRIX terminal-AT, thermobaric, and 120mm IR illum (no illum body in the
//   Twin loadout). The 60mm Commando family is likewise pending its classnames.
class CfgMagazines {
    class 6Rnd_120mm_HE_shells_RF;
    class 2Rnd_120mm_Mo_guided_RF;
    class 2Rnd_120mm_Mo_LG_RF;
    class 4Rnd_120mm_Mo_smoke_RF;
    class 2Rnd_120mm_Mo_mine_RF;
    class 4Rnd_120mm_Mo_AT_mine_RF;
    class 2Rnd_120mm_Mo_Cluster_RF;
    class 8Rnd_82mm_Mo_Flare_white;  // vanilla flare body for the IR illum (no RF illum body)

    // HE-ER — extended-range HE
    class FA_6Rnd_120mm_heer_B: 6Rnd_120mm_HE_shells_RF { author = QAUTHOR; ammo = "FA_120_heer"; displayName = "[JMSB] 6Rnd 120mm heer [BLUFOR]"; descriptionShort = "HE-ER — general-purpose HE<br/>120mm extended-range HE (2040)<br/>Prefragmented, ~30 m lethal, ~9 km"; };
    class FA_6Rnd_120mm_heer_O: 6Rnd_120mm_HE_shells_RF { author = QAUTHOR; ammo = "FA_120_heer_O"; displayName = "[JMSB] 6Rnd 120mm heer [OPFOR]"; descriptionShort = "HE-ER — general-purpose HE<br/>120mm extended-range HE (2040)<br/>Prefragmented, ~30 m lethal, ~9 km"; };
    class FA_6Rnd_120mm_heer_I: 6Rnd_120mm_HE_shells_RF { author = QAUTHOR; ammo = "FA_120_heer_I"; displayName = "[JMSB] 6Rnd 120mm heer [INDEP]"; descriptionShort = "HE-ER — general-purpose HE<br/>120mm extended-range HE (2040)<br/>Prefragmented, ~30 m lethal, ~9 km"; };

    // GPS precision
    class FA_2Rnd_120mm_apmi_B: 2Rnd_120mm_Mo_guided_RF { author = QAUTHOR; ammo = "FA_120_gps"; displayName = "[JMSB] 2Rnd 120mm apmi [BLUFOR]"; descriptionShort = "GPS precision<br/>120mm GPS precision HE (2040)<br/>GPS/GLONASS to a fixed grid, first-round precision"; };
    class FA_2Rnd_120mm_apmi_O: 2Rnd_120mm_Mo_guided_RF { author = QAUTHOR; ammo = "FA_120_gps_O"; displayName = "[JMSB] 2Rnd 120mm apmi [OPFOR]"; descriptionShort = "GPS precision<br/>120mm GPS precision HE (2040)<br/>GPS/GLONASS to a fixed grid, first-round precision"; };
    class FA_2Rnd_120mm_apmi_I: 2Rnd_120mm_Mo_guided_RF { author = QAUTHOR; ammo = "FA_120_gps_I"; displayName = "[JMSB] 2Rnd 120mm apmi [INDEP]"; descriptionShort = "GPS precision<br/>120mm GPS precision HE (2040)<br/>GPS/GLONASS to a fixed grid, first-round precision"; };

    // LGM — laser-guided HE
    class FA_2Rnd_120mm_lgm_B: 2Rnd_120mm_Mo_LG_RF { author = QAUTHOR; ammo = "FA_120_lgm"; displayName = "[JMSB] 2Rnd 120mm lgm [BLUFOR]"; descriptionShort = "Laser-guided<br/>120mm laser-guided HE (2040)<br/>Homes on a designated laser spot - movers or points"; };
    class FA_2Rnd_120mm_lgm_O: 2Rnd_120mm_Mo_LG_RF { author = QAUTHOR; ammo = "FA_120_lgm_O"; displayName = "[JMSB] 2Rnd 120mm lgm [OPFOR]"; descriptionShort = "Laser-guided<br/>120mm laser-guided HE (2040)<br/>Homes on a designated laser spot - movers or points"; };
    class FA_2Rnd_120mm_lgm_I: 2Rnd_120mm_Mo_LG_RF { author = QAUTHOR; ammo = "FA_120_lgm_I"; displayName = "[JMSB] 2Rnd 120mm lgm [INDEP]"; descriptionShort = "Laser-guided<br/>120mm laser-guided HE (2040)<br/>Homes on a designated laser spot - movers or points"; };

    // MS — multispectral smoke
    class FA_4Rnd_120mm_smk_B: 4Rnd_120mm_Mo_smoke_RF { author = QAUTHOR; ammo = "FA_120_smk"; displayName = "[JMSB] 4Rnd 120mm smk [BLUFOR]"; descriptionShort = "Multispectral smoke<br/>120mm multispectral smoke (2040)<br/>Visual + thermal screen, larger and longer"; };
    class FA_4Rnd_120mm_smk_O: 4Rnd_120mm_Mo_smoke_RF { author = QAUTHOR; ammo = "FA_120_smk_O"; displayName = "[JMSB] 4Rnd 120mm smk [OPFOR]"; descriptionShort = "Multispectral smoke<br/>120mm multispectral smoke (2040)<br/>Visual + thermal screen, larger and longer"; };
    class FA_4Rnd_120mm_smk_I: 4Rnd_120mm_Mo_smoke_RF { author = QAUTHOR; ammo = "FA_120_smk_I"; displayName = "[JMSB] 4Rnd 120mm smk [INDEP]"; descriptionShort = "Multispectral smoke<br/>120mm multispectral smoke (2040)<br/>Visual + thermal screen, larger and longer"; };

    // Scatterable AP mines
    class FA_2Rnd_120mm_apmine_B: 2Rnd_120mm_Mo_mine_RF { author = QAUTHOR; ammo = "FA_120_apmine"; displayName = "[JMSB] 2Rnd 120mm apmine [BLUFOR]"; descriptionShort = "Scatterable AP mines<br/>120mm scatterable AP mines (2040)<br/>Self-destruct minefield over the impact area"; };
    class FA_2Rnd_120mm_apmine_O: 2Rnd_120mm_Mo_mine_RF { author = QAUTHOR; ammo = "FA_120_apmine_O"; displayName = "[JMSB] 2Rnd 120mm apmine [OPFOR]"; descriptionShort = "Scatterable AP mines<br/>120mm scatterable AP mines (2040)<br/>Self-destruct minefield over the impact area"; };
    class FA_2Rnd_120mm_apmine_I: 2Rnd_120mm_Mo_mine_RF { author = QAUTHOR; ammo = "FA_120_apmine_I"; displayName = "[JMSB] 2Rnd 120mm apmine [INDEP]"; descriptionShort = "Scatterable AP mines<br/>120mm scatterable AP mines (2040)<br/>Self-destruct minefield over the impact area"; };

    // Scatterable AT mines
    class FA_4Rnd_120mm_atmine_B: 4Rnd_120mm_Mo_AT_mine_RF { author = QAUTHOR; ammo = "FA_120_atmine"; displayName = "[JMSB] 4Rnd 120mm atmine [BLUFOR]"; descriptionShort = "Scatterable AT mines<br/>120mm scatterable AT mines (2040)<br/>Self-destruct minefield over the impact area"; };
    class FA_4Rnd_120mm_atmine_O: 4Rnd_120mm_Mo_AT_mine_RF { author = QAUTHOR; ammo = "FA_120_atmine_O"; displayName = "[JMSB] 4Rnd 120mm atmine [OPFOR]"; descriptionShort = "Scatterable AT mines<br/>120mm scatterable AT mines (2040)<br/>Self-destruct minefield over the impact area"; };
    class FA_4Rnd_120mm_atmine_I: 4Rnd_120mm_Mo_AT_mine_RF { author = QAUTHOR; ammo = "FA_120_atmine_I"; displayName = "[JMSB] 4Rnd 120mm atmine [INDEP]"; descriptionShort = "Scatterable AT mines<br/>120mm scatterable AT mines (2040)<br/>Self-destruct minefield over the impact area"; };

    // Sensor-fuzed submunition (CCM-compliant successor to the cluster round)
    class FA_2Rnd_120mm_sfm_B: 2Rnd_120mm_Mo_Cluster_RF { author = QAUTHOR; ammo = "FA_120_sfm"; displayName = "[JMSB] 2Rnd 120mm sfm [BLUFOR]"; descriptionShort = "Sensor-fuzed submunition<br/>120mm sensor-fuzed submunition (2040)<br/>Top-attack self-destructing submunitions over armor"; };
    class FA_2Rnd_120mm_sfm_O: 2Rnd_120mm_Mo_Cluster_RF { author = QAUTHOR; ammo = "FA_120_sfm_O"; displayName = "[JMSB] 2Rnd 120mm sfm [OPFOR]"; descriptionShort = "Sensor-fuzed submunition<br/>120mm sensor-fuzed submunition (2040)<br/>Top-attack self-destructing submunitions over armor"; };
    class FA_2Rnd_120mm_sfm_I: 2Rnd_120mm_Mo_Cluster_RF { author = QAUTHOR; ammo = "FA_120_sfm_I"; displayName = "[JMSB] 2Rnd 120mm sfm [INDEP]"; descriptionShort = "Sensor-fuzed submunition<br/>120mm sensor-fuzed submunition (2040)<br/>Top-attack self-destructing submunitions over armor"; };

    // STRIX — terminal top-attack AT (on the guided body, with a HEAT penetrator)
    class FA_2Rnd_120mm_strix_B: 2Rnd_120mm_Mo_guided_RF { author = QAUTHOR; ammo = "FA_120_strix"; displayName = "[JMSB] 2Rnd 120mm strix [BLUFOR]"; descriptionShort = "STRIX top-attack AT<br/>120mm top-attack AT (2040)<br/>Fire-and-forget IR seeker, dives on top armor - 650mm RHA"; };
    class FA_2Rnd_120mm_strix_O: 2Rnd_120mm_Mo_guided_RF { author = QAUTHOR; ammo = "FA_120_strix_O"; displayName = "[JMSB] 2Rnd 120mm strix [OPFOR]"; descriptionShort = "STRIX top-attack AT<br/>120mm top-attack AT (2040)<br/>Fire-and-forget IR seeker, dives on top armor - 650mm RHA"; };
    class FA_2Rnd_120mm_strix_I: 2Rnd_120mm_Mo_guided_RF { author = QAUTHOR; ammo = "FA_120_strix_I"; displayName = "[JMSB] 2Rnd 120mm strix [INDEP]"; descriptionShort = "STRIX top-attack AT<br/>120mm top-attack AT (2040)<br/>Fire-and-forget IR seeker, dives on top armor - 650mm RHA"; };

    // TB — thermobaric (on the HE body)
    class FA_6Rnd_120mm_tb_B: 6Rnd_120mm_HE_shells_RF { author = QAUTHOR; ammo = "FA_120_tb"; displayName = "[JMSB] 6Rnd 120mm tb [BLUFOR]"; descriptionShort = "Thermobaric<br/>120mm thermobaric (2040)<br/>Enhanced-blast overpressure vs structures, trenches, rooms - ~40 m lethal"; };
    class FA_6Rnd_120mm_tb_O: 6Rnd_120mm_HE_shells_RF { author = QAUTHOR; ammo = "FA_120_tb_O"; displayName = "[JMSB] 6Rnd 120mm tb [OPFOR]"; descriptionShort = "Thermobaric<br/>120mm thermobaric (2040)<br/>Enhanced-blast overpressure vs structures, trenches, rooms - ~40 m lethal"; };
    class FA_6Rnd_120mm_tb_I: 6Rnd_120mm_HE_shells_RF { author = QAUTHOR; ammo = "FA_120_tb_I"; displayName = "[JMSB] 6Rnd 120mm tb [INDEP]"; descriptionShort = "Thermobaric<br/>120mm thermobaric (2040)<br/>Enhanced-blast overpressure vs structures, trenches, rooms - ~40 m lethal"; };

    // IR illum — West only. On the vanilla flare body (no RF illum body exists);
    // the IR/NVG-only behaviour uses the vanilla flare and may need FX tuning.
    class FA_8Rnd_120mm_ir_B: 8Rnd_82mm_Mo_Flare_white { author = QAUTHOR; displayName = "[JMSB] 8Rnd 120mm ir"; descriptionShort = "IR illumination (West-only)<br/>120mm IR illumination (2040)<br/>NVG-only flare - lights the field, dark to the naked eye (West only)"; };

    // ---- CSAT 12.7x55 (ASh-12) magazines ----
    // On the RF standard mag bodies (20Rnd / 10Rnd). Wood/desert cosmetic bodies
    // are skins of the same round, so not duplicated. These need to be added to
    // the ASh-12's magazineWell (name TBD) to appear on the rifle.
    class 20Rnd_127x55_Mag_RF;
    class 10Rnd_127x55_Mag_RF;
    class FA_rf_20Rnd_127x55_7N52: 20Rnd_127x55_Mag_RF { author = QAUTHOR; ammo = "FA_rf_ammo_127x55_7N52"; displayName = "[JMSB] 20Rnd 12.7x55mm 7N52"; descriptionShort = "12.7x55 tungsten AP, transonic (2040)"; };
    class FA_rf_20Rnd_127x55_7U13: 20Rnd_127x55_Mag_RF { author = QAUTHOR; ammo = "FA_rf_ammo_127x55_7U13"; displayName = "[JMSB] 20Rnd 12.7x55mm 7U13"; descriptionShort = "12.7x55 subsonic tungsten AP (2040)"; };
    class FA_rf_20Rnd_127x55_7U14: 20Rnd_127x55_Mag_RF { author = QAUTHOR; ammo = "FA_rf_ammo_127x55_7U14"; displayName = "[JMSB] 20Rnd 12.7x55mm 7U14"; descriptionShort = "12.7x55 subsonic heavy HP (2040)"; };
    class FA_rf_10Rnd_127x55_7N52: 10Rnd_127x55_Mag_RF { author = QAUTHOR; ammo = "FA_rf_ammo_127x55_7N52"; displayName = "[JMSB] 10Rnd 12.7x55mm 7N52"; descriptionShort = "12.7x55 tungsten AP, transonic (2040)"; };
    class FA_rf_10Rnd_127x55_7U13: 10Rnd_127x55_Mag_RF { author = QAUTHOR; ammo = "FA_rf_ammo_127x55_7U13"; displayName = "[JMSB] 10Rnd 12.7x55mm 7U13"; descriptionShort = "12.7x55 subsonic tungsten AP (2040)"; };
    class FA_rf_10Rnd_127x55_7U14: 10Rnd_127x55_Mag_RF { author = QAUTHOR; ammo = "FA_rf_ammo_127x55_7U14"; displayName = "[JMSB] 10Rnd 12.7x55mm 7U14"; descriptionShort = "12.7x55 subsonic heavy HP (2040)"; };

    // ---- CSAT RC40 revolver-GL shells (ASh-12 GL) ----
    // On the RF RC40 shell bodies; registered into the CBA 40mm GL wells (see
    // CfgMagazinewells.hpp), the same wells RF's own RC40 rounds use.
    class 1Rnd_RC40_HE_shell_RF;
    class 1Rnd_RC40_SmokeWhite_shell_RF;
    class FA_1Rnd_RC40_HEP: 1Rnd_RC40_HE_shell_RF { author = QAUTHOR; ammo = "FA_ammo_RC40_HEP"; displayName = "[JMSB] 1Rnd 40mm HEP"; descriptionShort = "RC40 programmable airburst HE (2040)<br/>Impact / delay / airburst (Mk364 dial)"; };
    class FA_1Rnd_RC40_MS: 1Rnd_RC40_SmokeWhite_shell_RF { author = QAUTHOR; ammo = "FA_ammo_RC40_MS"; displayName = "[JMSB] 1Rnd 40mm MS"; descriptionShort = "RC40 multispectral smoke (2040)<br/>Visual + thermal screen"; };
    class FA_1Rnd_RC40_AD: 1Rnd_RC40_HE_shell_RF { author = QAUTHOR; ammo = "FA_ammo_RC40_AD"; displayName = "[JMSB] 1Rnd 40mm AD"; descriptionShort = "RC40 anti-drone proximity (2040)<br/>C-UAS - bursts near drones (PAB script)"; };
    class FA_1Rnd_RC40_DP: 1Rnd_RC40_HE_shell_RF { author = QAUTHOR; ammo = "FA_ammo_RC40_DP"; displayName = "[JMSB] 1Rnd 40mm DP"; descriptionShort = "RC40 dual-purpose HEDP (2040)<br/>~50mm RHA + fragmentation"; };

    // ============================================================
    // 5.56x45 on RF STANAG-AP mag bodies (black / khaki / tan). Each cosmetic
    // body carries the full FA 5.56 lineup (Mk327 HV / Mk332 AP / XM891 CTEP,
    // each base + 7 tracer colours), fed to the STANAG_556x45 well.
    // ============================================================
    class 30Rnd_556x45_AP_Stanag_RF;
    class 30Rnd_556x45_AP_Stanag_khk_RF;
    class 30Rnd_556x45_AP_Stanag_Tan_RF;

    // ---- 5.56x45 on RF body 30Rnd_556x45_AP_Stanag_RF (black) ----
    class FA_30Rnd_556x45_AP_Stanag_RF: 30Rnd_556x45_AP_Stanag_RF { author = QAUTHOR; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG)"; descriptionShort = "Mk327 HV"; ammo = "FA_b_556_Mk327_HV"; initSpeed = 1000; };
    class FA_30Rnd_556x45_AP_Stanag_RF_T_Red: FA_30Rnd_556x45_AP_Stanag_RF { ammo = "FA_b_556_Mk327_HV_T_Red"; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG) - Red Tracer"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_RF_T_Yellow: FA_30Rnd_556x45_AP_Stanag_RF { ammo = "FA_b_556_Mk327_HV_T_Yellow"; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG) - Yellow Tracer"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_RF_T_Green: FA_30Rnd_556x45_AP_Stanag_RF { ammo = "FA_b_556_Mk327_HV_T_Green"; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG) - Green Tracer"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_RF_T_White: FA_30Rnd_556x45_AP_Stanag_RF { ammo = "FA_b_556_Mk327_HV_T_White"; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG) - White Tracer"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_RF_T_Blue: FA_30Rnd_556x45_AP_Stanag_RF { ammo = "FA_b_556_Mk327_HV_T_Blue"; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG) - Blue Tracer"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_RF_T_Orange: FA_30Rnd_556x45_AP_Stanag_RF { ammo = "FA_b_556_Mk327_HV_T_Orange"; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG) - Orange Tracer"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_RF_T_IR: FA_30Rnd_556x45_AP_Stanag_RF { ammo = "FA_b_556_Mk327_HV_T_IR"; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG) - IR Tracer"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_RF_Mk332_AP: 30Rnd_556x45_AP_Stanag_RF { author = QAUTHOR; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG)"; descriptionShort = "Mk332 AP"; ammo = "FA_b_556_Mk332_AP"; initSpeed = 940; };
    class FA_30Rnd_556x45_AP_Stanag_RF_Mk332_AP_T_Red: FA_30Rnd_556x45_AP_Stanag_RF_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Red"; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG) - Red Tracer"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_RF_Mk332_AP_T_Yellow: FA_30Rnd_556x45_AP_Stanag_RF_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Yellow"; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG) - Yellow Tracer"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_RF_Mk332_AP_T_Green: FA_30Rnd_556x45_AP_Stanag_RF_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Green"; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG) - Green Tracer"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_RF_Mk332_AP_T_White: FA_30Rnd_556x45_AP_Stanag_RF_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_White"; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG) - White Tracer"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_RF_Mk332_AP_T_Blue: FA_30Rnd_556x45_AP_Stanag_RF_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Blue"; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG) - Blue Tracer"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_RF_Mk332_AP_T_Orange: FA_30Rnd_556x45_AP_Stanag_RF_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Orange"; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG) - Orange Tracer"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_RF_Mk332_AP_T_IR: FA_30Rnd_556x45_AP_Stanag_RF_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_IR"; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG) - IR Tracer"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_RF_XM891_CTEP: 30Rnd_556x45_AP_Stanag_RF { author = QAUTHOR; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG)"; descriptionShort = "XM891 CTEP"; ammo = "FA_b_556_XM891_CTEP"; initSpeed = 1015; };
    class FA_30Rnd_556x45_AP_Stanag_RF_XM891_CTEP_T_Red: FA_30Rnd_556x45_AP_Stanag_RF_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Red"; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG) - Red Tracer"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_RF_XM891_CTEP_T_Yellow: FA_30Rnd_556x45_AP_Stanag_RF_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Yellow"; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG) - Yellow Tracer"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_RF_XM891_CTEP_T_Green: FA_30Rnd_556x45_AP_Stanag_RF_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Green"; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG) - Green Tracer"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_RF_XM891_CTEP_T_White: FA_30Rnd_556x45_AP_Stanag_RF_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_White"; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG) - White Tracer"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_RF_XM891_CTEP_T_Blue: FA_30Rnd_556x45_AP_Stanag_RF_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Blue"; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG) - Blue Tracer"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_RF_XM891_CTEP_T_Orange: FA_30Rnd_556x45_AP_Stanag_RF_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Orange"; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG) - Orange Tracer"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_RF_XM891_CTEP_T_IR: FA_30Rnd_556x45_AP_Stanag_RF_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_IR"; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG) - IR Tracer"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };

    // ---- 5.56x45 on RF body 30Rnd_556x45_AP_Stanag_khk_RF (Khaki) ----
    class FA_30Rnd_556x45_AP_Stanag_khk_RF: 30Rnd_556x45_AP_Stanag_khk_RF { author = QAUTHOR; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG) - Khaki"; descriptionShort = "Mk327 HV"; ammo = "FA_b_556_Mk327_HV"; initSpeed = 1000; };
    class FA_30Rnd_556x45_AP_Stanag_khk_RF_T_Red: FA_30Rnd_556x45_AP_Stanag_khk_RF { ammo = "FA_b_556_Mk327_HV_T_Red"; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG) - Red Tracer, Khaki"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_khk_RF_T_Yellow: FA_30Rnd_556x45_AP_Stanag_khk_RF { ammo = "FA_b_556_Mk327_HV_T_Yellow"; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG) - Yellow Tracer, Khaki"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_khk_RF_T_Green: FA_30Rnd_556x45_AP_Stanag_khk_RF { ammo = "FA_b_556_Mk327_HV_T_Green"; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG) - Green Tracer, Khaki"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_khk_RF_T_White: FA_30Rnd_556x45_AP_Stanag_khk_RF { ammo = "FA_b_556_Mk327_HV_T_White"; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG) - White Tracer, Khaki"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_khk_RF_T_Blue: FA_30Rnd_556x45_AP_Stanag_khk_RF { ammo = "FA_b_556_Mk327_HV_T_Blue"; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG) - Blue Tracer, Khaki"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_khk_RF_T_Orange: FA_30Rnd_556x45_AP_Stanag_khk_RF { ammo = "FA_b_556_Mk327_HV_T_Orange"; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG) - Orange Tracer, Khaki"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_khk_RF_T_IR: FA_30Rnd_556x45_AP_Stanag_khk_RF { ammo = "FA_b_556_Mk327_HV_T_IR"; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG) - IR Tracer, Khaki"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_khk_RF_Mk332_AP: 30Rnd_556x45_AP_Stanag_khk_RF { author = QAUTHOR; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG) - Khaki"; descriptionShort = "Mk332 AP"; ammo = "FA_b_556_Mk332_AP"; initSpeed = 940; };
    class FA_30Rnd_556x45_AP_Stanag_khk_RF_Mk332_AP_T_Red: FA_30Rnd_556x45_AP_Stanag_khk_RF_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Red"; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG) - Red Tracer, Khaki"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_khk_RF_Mk332_AP_T_Yellow: FA_30Rnd_556x45_AP_Stanag_khk_RF_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Yellow"; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG) - Yellow Tracer, Khaki"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_khk_RF_Mk332_AP_T_Green: FA_30Rnd_556x45_AP_Stanag_khk_RF_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Green"; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG) - Green Tracer, Khaki"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_khk_RF_Mk332_AP_T_White: FA_30Rnd_556x45_AP_Stanag_khk_RF_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_White"; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG) - White Tracer, Khaki"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_khk_RF_Mk332_AP_T_Blue: FA_30Rnd_556x45_AP_Stanag_khk_RF_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Blue"; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG) - Blue Tracer, Khaki"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_khk_RF_Mk332_AP_T_Orange: FA_30Rnd_556x45_AP_Stanag_khk_RF_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Orange"; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG) - Orange Tracer, Khaki"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_khk_RF_Mk332_AP_T_IR: FA_30Rnd_556x45_AP_Stanag_khk_RF_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_IR"; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG) - IR Tracer, Khaki"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_khk_RF_XM891_CTEP: 30Rnd_556x45_AP_Stanag_khk_RF { author = QAUTHOR; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG) - Khaki"; descriptionShort = "XM891 CTEP"; ammo = "FA_b_556_XM891_CTEP"; initSpeed = 1015; };
    class FA_30Rnd_556x45_AP_Stanag_khk_RF_XM891_CTEP_T_Red: FA_30Rnd_556x45_AP_Stanag_khk_RF_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Red"; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG) - Red Tracer, Khaki"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_khk_RF_XM891_CTEP_T_Yellow: FA_30Rnd_556x45_AP_Stanag_khk_RF_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Yellow"; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG) - Yellow Tracer, Khaki"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_khk_RF_XM891_CTEP_T_Green: FA_30Rnd_556x45_AP_Stanag_khk_RF_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Green"; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG) - Green Tracer, Khaki"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_khk_RF_XM891_CTEP_T_White: FA_30Rnd_556x45_AP_Stanag_khk_RF_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_White"; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG) - White Tracer, Khaki"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_khk_RF_XM891_CTEP_T_Blue: FA_30Rnd_556x45_AP_Stanag_khk_RF_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Blue"; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG) - Blue Tracer, Khaki"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_khk_RF_XM891_CTEP_T_Orange: FA_30Rnd_556x45_AP_Stanag_khk_RF_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Orange"; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG) - Orange Tracer, Khaki"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_khk_RF_XM891_CTEP_T_IR: FA_30Rnd_556x45_AP_Stanag_khk_RF_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_IR"; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG) - IR Tracer, Khaki"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };

    // ---- 5.56x45 on RF body 30Rnd_556x45_AP_Stanag_Tan_RF (Tan) ----
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF: 30Rnd_556x45_AP_Stanag_Tan_RF { author = QAUTHOR; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG) - Tan"; descriptionShort = "Mk327 HV"; ammo = "FA_b_556_Mk327_HV"; initSpeed = 1000; };
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF_T_Red: FA_30Rnd_556x45_AP_Stanag_Tan_RF { ammo = "FA_b_556_Mk327_HV_T_Red"; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG) - Red Tracer, Tan"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF_T_Yellow: FA_30Rnd_556x45_AP_Stanag_Tan_RF { ammo = "FA_b_556_Mk327_HV_T_Yellow"; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG) - Yellow Tracer, Tan"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF_T_Green: FA_30Rnd_556x45_AP_Stanag_Tan_RF { ammo = "FA_b_556_Mk327_HV_T_Green"; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG) - Green Tracer, Tan"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF_T_White: FA_30Rnd_556x45_AP_Stanag_Tan_RF { ammo = "FA_b_556_Mk327_HV_T_White"; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG) - White Tracer, Tan"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF_T_Blue: FA_30Rnd_556x45_AP_Stanag_Tan_RF { ammo = "FA_b_556_Mk327_HV_T_Blue"; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG) - Blue Tracer, Tan"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF_T_Orange: FA_30Rnd_556x45_AP_Stanag_Tan_RF { ammo = "FA_b_556_Mk327_HV_T_Orange"; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG) - Orange Tracer, Tan"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF_T_IR: FA_30Rnd_556x45_AP_Stanag_Tan_RF { ammo = "FA_b_556_Mk327_HV_T_IR"; displayName = "[JMSB] 30Rnd 5.56mm AP (STANAG) - IR Tracer, Tan"; descriptionShort = "Mk327 HV"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF_Mk332_AP: 30Rnd_556x45_AP_Stanag_Tan_RF { author = QAUTHOR; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG) - Tan"; descriptionShort = "Mk332 AP"; ammo = "FA_b_556_Mk332_AP"; initSpeed = 940; };
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF_Mk332_AP_T_Red: FA_30Rnd_556x45_AP_Stanag_Tan_RF_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Red"; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG) - Red Tracer, Tan"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF_Mk332_AP_T_Yellow: FA_30Rnd_556x45_AP_Stanag_Tan_RF_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Yellow"; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG) - Yellow Tracer, Tan"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF_Mk332_AP_T_Green: FA_30Rnd_556x45_AP_Stanag_Tan_RF_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Green"; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG) - Green Tracer, Tan"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF_Mk332_AP_T_White: FA_30Rnd_556x45_AP_Stanag_Tan_RF_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_White"; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG) - White Tracer, Tan"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF_Mk332_AP_T_Blue: FA_30Rnd_556x45_AP_Stanag_Tan_RF_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Blue"; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG) - Blue Tracer, Tan"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF_Mk332_AP_T_Orange: FA_30Rnd_556x45_AP_Stanag_Tan_RF_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_Orange"; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG) - Orange Tracer, Tan"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF_Mk332_AP_T_IR: FA_30Rnd_556x45_AP_Stanag_Tan_RF_Mk332_AP { ammo = "FA_b_556_Mk332_AP_T_IR"; displayName = "[JMSB] 30Rnd 5.56mm AP Mk332 (STANAG) - IR Tracer, Tan"; descriptionShort = "Mk332 AP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF_XM891_CTEP: 30Rnd_556x45_AP_Stanag_Tan_RF { author = QAUTHOR; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG) - Tan"; descriptionShort = "XM891 CTEP"; ammo = "FA_b_556_XM891_CTEP"; initSpeed = 1015; };
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF_XM891_CTEP_T_Red: FA_30Rnd_556x45_AP_Stanag_Tan_RF_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Red"; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG) - Red Tracer, Tan"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF_XM891_CTEP_T_Yellow: FA_30Rnd_556x45_AP_Stanag_Tan_RF_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Yellow"; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG) - Yellow Tracer, Tan"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF_XM891_CTEP_T_Green: FA_30Rnd_556x45_AP_Stanag_Tan_RF_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Green"; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG) - Green Tracer, Tan"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF_XM891_CTEP_T_White: FA_30Rnd_556x45_AP_Stanag_Tan_RF_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_White"; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG) - White Tracer, Tan"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF_XM891_CTEP_T_Blue: FA_30Rnd_556x45_AP_Stanag_Tan_RF_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Blue"; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG) - Blue Tracer, Tan"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF_XM891_CTEP_T_Orange: FA_30Rnd_556x45_AP_Stanag_Tan_RF_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_Orange"; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG) - Orange Tracer, Tan"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };
    class FA_30Rnd_556x45_AP_Stanag_Tan_RF_XM891_CTEP_T_IR: FA_30Rnd_556x45_AP_Stanag_Tan_RF_XM891_CTEP { ammo = "FA_b_556_XM891_CTEP_T_IR"; displayName = "[JMSB] 30Rnd 5.56mm AP XM891 CTEP (STANAG) - IR Tracer, Tan"; descriptionShort = "XM891 CTEP"; tracersEvery = 4; };

    // ---- Glock 19X 9x19 (user, 2026-09-27) - loaded through jmfsb_fa_Glock19_RF, CfgWeapons.hpp ----
    class 17Rnd_9x19_Mag_RF;
    class 33Rnd_9x19_Mag_Tan_RF;
    class FA_rf_17Rnd_9x19_Mk422_AP: 17Rnd_9x19_Mag_RF { author = QAUTHOR; ammo = "FA_rf_9x19_Mk422_AP"; displayName = "[JMSB] 17Rnd 9mm Mk422 AP [RF]"; displayNameShort = "Mk422 AP"; descriptionShort = "9x19 Mk422 AP"; initSpeed = 400; };
    class FA_rf_33Rnd_9x19_Mk422_AP: 33Rnd_9x19_Mag_Tan_RF { author = QAUTHOR; ammo = "FA_rf_9x19_Mk422_AP"; displayName = "[JMSB] 33Rnd 9mm Mk422 AP"; displayNameShort = "Mk422 AP"; descriptionShort = "9x19 Mk422 AP"; initSpeed = 400; };

    #include "CfgMagazines_compat.hpp"
};
