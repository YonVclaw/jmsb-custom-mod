// Heavy-fires 2040 magazines. 155mm AMOS SPGs (Sholef/Sochor/Scorcher, weapon
// mortar_155mm_AMOS) and 230mm GAT MLRS (Seara/Zamak, weapon rockets_230mm_GAT).
// Tri-side (_B West / _O East / _I Ind); East uses the vanilla _O magazine body,
// West/Ind use the base body. IR illum is West-only (on a vanilla flare body -
// no 155mm illum body exists). Fed to the two vanilla weapons in CfgWeapons.hpp.
class CfgMagazines {
    // vanilla 155mm bodies (base + _O East)
    class 32Rnd_155mm_Mo_shells;
    class 32Rnd_155mm_Mo_shells_O;
    class 6Rnd_155mm_Mo_smoke;
    class 6Rnd_155mm_Mo_smoke_O;
    class 4Rnd_155mm_Mo_guided;
    class 4Rnd_155mm_Mo_guided_O;
    class 4Rnd_155mm_Mo_LG;
    class 4Rnd_155mm_Mo_LG_O;
    class 6Rnd_155mm_Mo_mine;
    class 6Rnd_155mm_Mo_mine_O;
    class 6Rnd_155mm_Mo_AT_mine;
    class 6Rnd_155mm_Mo_AT_mine_O;
    class 2Rnd_155mm_Mo_Cluster;
    class 2Rnd_155mm_Mo_Cluster_O;
    class 8Rnd_82mm_Mo_Flare_white;   // vanilla flare body for IR illum (155 + 82)
    // vanilla 230mm rocket bodies
    class 12Rnd_230mm_rockets;
    class 12Rnd_230mm_rockets_cluster;
    // vanilla 82mm Mk6 mortar bodies
    class 8Rnd_82mm_Mo_shells;
    class 8Rnd_82mm_Mo_guided;
    class 8Rnd_82mm_Mo_LG;
    class 8Rnd_82mm_Mo_Smoke_white;

    // ---- 155mm HE-ER (extended-range HE) ----
    class FA_32Rnd_155mm_heer_B: 32Rnd_155mm_Mo_shells   { author = QAUTHOR; ammo = "FA_155_heer"; displayName = "[JMSB] 32Rnd 155mm M795E1 HE-ER"; descriptionShort = "155mm extended-range HE (2040)<br/>Prefragmented, ~40 m lethal"; };
    class FA_32Rnd_155mm_heer_O: 32Rnd_155mm_Mo_shells_O { author = QAUTHOR; ammo = "FA_155_heer"; displayName = "[JMSB] 32Rnd 155mm Type 155-1 HE"; descriptionShort = "155mm extended-range HE (2040)<br/>Prefragmented, ~40 m lethal"; };
    class FA_32Rnd_155mm_heer_I: 32Rnd_155mm_Mo_shells   { author = QAUTHOR; ammo = "FA_155_heer"; displayName = "[JMSB] 32Rnd 155mm AF-155E"; descriptionShort = "155mm extended-range HE (2040)<br/>Prefragmented, ~40 m lethal"; };

    // ---- 155mm GPS precision (Excalibur) ----
    class FA_4Rnd_155mm_apmi_B: 4Rnd_155mm_Mo_guided   { author = QAUTHOR; displayName = "[JMSB] 4Rnd 155mm M982E1 Excalibur"; descriptionShort = "155mm GPS precision (2040)<br/>GPS/GLONASS to a fixed grid"; };
    class FA_4Rnd_155mm_apmi_O: 4Rnd_155mm_Mo_guided_O { author = QAUTHOR; displayName = "[JMSB] 4Rnd 155mm Type 155-GN"; descriptionShort = "155mm GPS precision (2040)<br/>GPS/GLONASS to a fixed grid"; };
    class FA_4Rnd_155mm_apmi_I: 4Rnd_155mm_Mo_guided   { author = QAUTHOR; displayName = "[JMSB] 4Rnd 155mm AF-155P"; descriptionShort = "155mm GPS precision (2040)<br/>GPS/GLONASS to a fixed grid"; };

    // ---- 155mm laser-guided ----
    class FA_4Rnd_155mm_lgm_B: 4Rnd_155mm_Mo_LG   { author = QAUTHOR; displayName = "[JMSB] 4Rnd 155mm M-CLGP"; descriptionShort = "155mm laser-guided (2040)<br/>Homes on a designated laser spot"; };
    class FA_4Rnd_155mm_lgm_O: 4Rnd_155mm_Mo_LG_O { author = QAUTHOR; displayName = "[JMSB] 4Rnd 155mm Type 155K Krasnopol"; descriptionShort = "155mm laser-guided (2040)<br/>Homes on a designated laser spot"; };
    class FA_4Rnd_155mm_lgm_I: 4Rnd_155mm_Mo_LG   { author = QAUTHOR; displayName = "[JMSB] 4Rnd 155mm AF-155L"; descriptionShort = "155mm laser-guided (2040)<br/>Homes on a designated laser spot"; };

    // ---- 155mm multispectral smoke ----
    class FA_6Rnd_155mm_smk_B: 6Rnd_155mm_Mo_smoke   { author = QAUTHOR; displayName = "[JMSB] 6Rnd 155mm M-SMK 155"; descriptionShort = "155mm multispectral smoke (2040)<br/>Visual + thermal screen"; };
    class FA_6Rnd_155mm_smk_O: 6Rnd_155mm_Mo_smoke_O { author = QAUTHOR; displayName = "[JMSB] 6Rnd 155mm Type 155D"; descriptionShort = "155mm multispectral smoke (2040)<br/>Visual + thermal screen"; };
    class FA_6Rnd_155mm_smk_I: 6Rnd_155mm_Mo_smoke   { author = QAUTHOR; displayName = "[JMSB] 6Rnd 155mm AF-155S"; descriptionShort = "155mm multispectral smoke (2040)<br/>Visual + thermal screen"; };

    // ---- 155mm scatterable AP mines ----
    class FA_6Rnd_155mm_apmine_B: 6Rnd_155mm_Mo_mine   { author = QAUTHOR; displayName = "[JMSB] 6Rnd 155mm M692 ADAM-2"; descriptionShort = "155mm scatterable AP mines (2040)<br/>Self-destruct minefield"; };
    class FA_6Rnd_155mm_apmine_O: 6Rnd_155mm_Mo_mine_O { author = QAUTHOR; displayName = "[JMSB] 6Rnd 155mm Type 155-PP"; descriptionShort = "155mm scatterable AP mines (2040)<br/>Self-destruct minefield"; };
    class FA_6Rnd_155mm_apmine_I: 6Rnd_155mm_Mo_mine   { author = QAUTHOR; displayName = "[JMSB] 6Rnd 155mm AF-155MP"; descriptionShort = "155mm scatterable AP mines (2040)<br/>Self-destruct minefield"; };

    // ---- 155mm scatterable AT mines ----
    class FA_6Rnd_155mm_atmine_B: 6Rnd_155mm_Mo_AT_mine   { author = QAUTHOR; displayName = "[JMSB] 6Rnd 155mm M718 RAAMS-2"; descriptionShort = "155mm scatterable AT mines (2040)<br/>Self-destruct minefield"; };
    class FA_6Rnd_155mm_atmine_O: 6Rnd_155mm_Mo_AT_mine_O { author = QAUTHOR; displayName = "[JMSB] 6Rnd 155mm Type 155-PT"; descriptionShort = "155mm scatterable AT mines (2040)<br/>Self-destruct minefield"; };
    class FA_6Rnd_155mm_atmine_I: 6Rnd_155mm_Mo_AT_mine   { author = QAUTHOR; displayName = "[JMSB] 6Rnd 155mm AF-155MT"; descriptionShort = "155mm scatterable AT mines (2040)<br/>Self-destruct minefield"; };

    // ---- 155mm sensor-fuzed submunition (SADARM) ----
    class FA_2Rnd_155mm_sfm_B: 2Rnd_155mm_Mo_Cluster   { author = QAUTHOR; displayName = "[JMSB] 2Rnd 155mm M898 SADARM-2"; descriptionShort = "155mm sensor-fuzed submunition (2040)<br/>Top-attack self-destructing submunitions"; };
    class FA_2Rnd_155mm_sfm_O: 2Rnd_155mm_Mo_Cluster_O { author = QAUTHOR; displayName = "[JMSB] 2Rnd 155mm Type 155-SF"; descriptionShort = "155mm sensor-fuzed submunition (2040)<br/>Top-attack self-destructing submunitions"; };
    class FA_2Rnd_155mm_sfm_I: 2Rnd_155mm_Mo_Cluster   { author = QAUTHOR; displayName = "[JMSB] 2Rnd 155mm AF-155SF"; descriptionShort = "155mm sensor-fuzed submunition (2040)<br/>Top-attack self-destructing submunitions"; };

    // ---- 155mm thermobaric ----
    class FA_32Rnd_155mm_tb_B: 32Rnd_155mm_Mo_shells   { author = QAUTHOR; ammo = "FA_155_tb"; displayName = "[JMSB] 32Rnd 155mm M-TB 155"; descriptionShort = "155mm thermobaric (2040)<br/>Enhanced-blast overpressure, ~50 m lethal"; };
    class FA_32Rnd_155mm_tb_O: 32Rnd_155mm_Mo_shells_O { author = QAUTHOR; ammo = "FA_155_tb"; displayName = "[JMSB] 32Rnd 155mm Type 155TB"; descriptionShort = "155mm thermobaric (2040)<br/>Enhanced-blast overpressure, ~50 m lethal"; };
    class FA_32Rnd_155mm_tb_I: 32Rnd_155mm_Mo_shells   { author = QAUTHOR; ammo = "FA_155_tb"; displayName = "[JMSB] 32Rnd 155mm AF-155T"; descriptionShort = "155mm thermobaric (2040)<br/>Enhanced-blast overpressure, ~50 m lethal"; };

    // ---- 155mm IR illum (West only, vanilla flare body) ----
    class FA_8Rnd_155mm_ir_B: 8Rnd_82mm_Mo_Flare_white { author = QAUTHOR; displayName = "[JMSB] 155mm M-IR 155"; descriptionShort = "155mm IR illumination (2040)<br/>NVG-only flare (West only)"; };

    // ---- 230mm GMLRS unitary ----
    class FA_12Rnd_230mm_gmlrsu_B: 12Rnd_230mm_rockets { author = QAUTHOR; ammo = "FA_230_gmlrsu"; displayName = "[JMSB] 12Rnd 230mm M31E2 GMLRS-U"; descriptionShort = "230mm precision unitary (2040)<br/>Guided unitary warhead"; };
    class FA_12Rnd_230mm_gmlrsu_O: 12Rnd_230mm_rockets { author = QAUTHOR; ammo = "FA_230_gmlrsu"; displayName = "[JMSB] 12Rnd 230mm Type 230-1"; descriptionShort = "230mm precision unitary (2040)<br/>Guided unitary warhead"; };
    class FA_12Rnd_230mm_gmlrsu_I: 12Rnd_230mm_rockets { author = QAUTHOR; ammo = "FA_230_gmlrsu"; displayName = "[JMSB] 12Rnd 230mm AF-230U"; descriptionShort = "230mm precision unitary (2040)<br/>Guided unitary warhead"; };

    // ---- 230mm GMLRS-ER ----
    class FA_12Rnd_230mm_gmlrser_B: 12Rnd_230mm_rockets { author = QAUTHOR; ammo = "FA_230_gmlrser"; displayName = "[JMSB] 12Rnd 230mm M403 GMLRS-ER"; descriptionShort = "230mm extended-range HE (2040)"; };
    class FA_12Rnd_230mm_gmlrser_O: 12Rnd_230mm_rockets { author = QAUTHOR; ammo = "FA_230_gmlrser"; displayName = "[JMSB] 12Rnd 230mm Type 230-ER"; descriptionShort = "230mm extended-range HE (2040)"; };
    class FA_12Rnd_230mm_gmlrser_I: 12Rnd_230mm_rockets { author = QAUTHOR; ammo = "FA_230_gmlrser"; displayName = "[JMSB] 12Rnd 230mm AF-230E"; descriptionShort = "230mm extended-range HE (2040)"; };

    // ---- 230mm sensor-fuzed AT (AW) ----
    class FA_12Rnd_230mm_aw_B: 12Rnd_230mm_rockets_cluster { author = QAUTHOR; ammo = "FA_230_aw"; displayName = "[JMSB] 12Rnd 230mm M-AW"; descriptionShort = "230mm sensor-fuzed AT (2040)<br/>Top-attack self-destructing submunitions"; };
    class FA_12Rnd_230mm_aw_O: 12Rnd_230mm_rockets_cluster { author = QAUTHOR; ammo = "FA_230_aw"; displayName = "[JMSB] 12Rnd 230mm Type 230-SF"; descriptionShort = "230mm sensor-fuzed AT (2040)<br/>Top-attack self-destructing submunitions"; };
    class FA_12Rnd_230mm_aw_I: 12Rnd_230mm_rockets_cluster { author = QAUTHOR; ammo = "FA_230_aw"; displayName = "[JMSB] 12Rnd 230mm AF-230SF"; descriptionShort = "230mm sensor-fuzed AT (2040)<br/>Top-attack self-destructing submunitions"; };

    // ---- 82mm Mk6 Mortar (vanilla mortar_82mm; B/O/I_Mortar_01_F) ----
    class FA_8Rnd_82mm_apmi_B: 8Rnd_82mm_Mo_guided { author = QAUTHOR; ammo = "FA_82_apmi"; displayName = "[JMSB] 8Rnd 82mm XM395-2 APMI"; descriptionShort = "82mm GPS precision HE (2040)<br/>First-round precision, CEP ~1m"; };
    class FA_8Rnd_82mm_apmi_O: 8Rnd_82mm_Mo_guided { author = QAUTHOR; ammo = "FA_82_apmi_O"; displayName = "[JMSB] 8Rnd 82mm Type 82-GN"; descriptionShort = "82mm GPS precision HE (2040)<br/>First-round precision, CEP ~1m"; };
    class FA_8Rnd_82mm_apmi_I: 8Rnd_82mm_Mo_guided { author = QAUTHOR; ammo = "FA_82_apmi_I"; displayName = "[JMSB] 8Rnd 82mm AF-82P"; descriptionShort = "82mm GPS precision HE (2040)<br/>First-round precision, CEP ~1m"; };
    class FA_8Rnd_82mm_lgm_B: 8Rnd_82mm_Mo_LG { author = QAUTHOR; ammo = "FA_82_lgm"; displayName = "[JMSB] 8Rnd 82mm M-LGM"; descriptionShort = "82mm laser-guided HE (2040)<br/>Homes on a designated laser spot"; };
    class FA_8Rnd_82mm_lgm_O: 8Rnd_82mm_Mo_LG { author = QAUTHOR; ammo = "FA_82_lgm_O"; displayName = "[JMSB] 8Rnd 82mm Type 82G Gran"; descriptionShort = "82mm laser-guided HE (2040)<br/>Homes on a designated laser spot"; };
    class FA_8Rnd_82mm_lgm_I: 8Rnd_82mm_Mo_LG { author = QAUTHOR; ammo = "FA_82_lgm_I"; displayName = "[JMSB] 8Rnd 82mm AF-82L"; descriptionShort = "82mm laser-guided HE (2040)<br/>Homes on a designated laser spot"; };
    class FA_8Rnd_82mm_heer_B: 8Rnd_82mm_Mo_shells { author = QAUTHOR; ammo = "FA_82_heer"; displayName = "[JMSB] 8Rnd 82mm M821E1 HE-ER"; descriptionShort = "82mm extended-range HE (2040)<br/>Prefragmented, more range and frag than stock"; };
    class FA_8Rnd_82mm_heer_O: 8Rnd_82mm_Mo_shells { author = QAUTHOR; ammo = "FA_82_heer_O"; displayName = "[JMSB] 8Rnd 82mm Type 82-1 HE"; descriptionShort = "82mm extended-range HE (2040)<br/>Prefragmented, more range and frag than stock"; };
    class FA_8Rnd_82mm_heer_I: 8Rnd_82mm_Mo_shells { author = QAUTHOR; ammo = "FA_82_heer_I"; displayName = "[JMSB] 8Rnd 82mm AF-82E"; descriptionShort = "82mm extended-range HE (2040)<br/>Prefragmented, more range and frag than stock"; };
    class FA_8Rnd_82mm_strix_B: 8Rnd_82mm_Mo_guided { author = QAUTHOR; ammo = "FA_82_strix"; displayName = "[JMSB] 8Rnd 82mm M-STRIX AT"; descriptionShort = "82mm top-attack AT (2040)<br/>Fire-and-forget terminal seeker, 500mm RHA"; };
    class FA_8Rnd_82mm_strix_O: 8Rnd_82mm_Mo_guided { author = QAUTHOR; ammo = "FA_82_strix_O"; displayName = "[JMSB] 8Rnd 82mm Type 82K Kitolov"; descriptionShort = "82mm top-attack AT (2040)<br/>Fire-and-forget terminal seeker, 500mm RHA"; };
    class FA_8Rnd_82mm_strix_I: 8Rnd_82mm_Mo_guided { author = QAUTHOR; ammo = "FA_82_strix_I"; displayName = "[JMSB] 8Rnd 82mm AF-82K"; descriptionShort = "82mm top-attack AT (2040)<br/>Fire-and-forget terminal seeker, 500mm RHA"; };
    class FA_8Rnd_82mm_smk_B: 8Rnd_82mm_Mo_Smoke_white { author = QAUTHOR; ammo = "FA_82_smk"; displayName = "[JMSB] 8Rnd 82mm M-SMK MS"; descriptionShort = "82mm multispectral smoke (2040)<br/>Visual + thermal screen"; };
    class FA_8Rnd_82mm_smk_O: 8Rnd_82mm_Mo_Smoke_white { author = QAUTHOR; ammo = "FA_82_smk_O"; displayName = "[JMSB] 8Rnd 82mm Type 82D"; descriptionShort = "82mm multispectral smoke (2040)<br/>Visual + thermal screen"; };
    class FA_8Rnd_82mm_smk_I: 8Rnd_82mm_Mo_Smoke_white { author = QAUTHOR; ammo = "FA_82_smk_I"; displayName = "[JMSB] 8Rnd 82mm AF-82S"; descriptionShort = "82mm multispectral smoke (2040)<br/>Visual + thermal screen"; };
    class FA_8Rnd_82mm_tb_B: 8Rnd_82mm_Mo_shells { author = QAUTHOR; ammo = "FA_82_tb"; displayName = "[JMSB] 8Rnd 82mm M-TB"; descriptionShort = "82mm thermobaric (2040)<br/>Enhanced-blast overpressure"; };
    class FA_8Rnd_82mm_tb_O: 8Rnd_82mm_Mo_shells { author = QAUTHOR; ammo = "FA_82_tb_O"; displayName = "[JMSB] 8Rnd 82mm Type 82TB"; descriptionShort = "82mm thermobaric (2040)<br/>Enhanced-blast overpressure"; };
    class FA_8Rnd_82mm_tb_I: 8Rnd_82mm_Mo_shells { author = QAUTHOR; ammo = "FA_82_tb_I"; displayName = "[JMSB] 8Rnd 82mm AF-82T"; descriptionShort = "82mm thermobaric (2040)<br/>Enhanced-blast overpressure"; };
    class FA_8Rnd_82mm_ir_B: 8Rnd_82mm_Mo_Flare_white { author = QAUTHOR; ammo = "FA_82_ir"; displayName = "[JMSB] 8Rnd 82mm M853 IR"; descriptionShort = "82mm IR illumination (2040)<br/>NVG-only flare (West only)"; };

    // ---- Mk45 Hammer naval gun (vanilla weapon_ShipCannon_120mm, West only) ----
    class magazine_ShipCannon_120mm_HE_shells_x32;
    class magazine_ShipCannon_120mm_smoke_shells_x6;
    class magazine_ShipCannon_120mm_HE_guided_shells_x2;
    class magazine_ShipCannon_120mm_HE_LG_shells_x2;
    class magazine_ShipCannon_120mm_HE_cluster_shells_x2;
    class FA_2Rnd_120N_glr: magazine_ShipCannon_120mm_HE_guided_shells_x2 { author = QAUTHOR; ammo = "FA_120N_glr"; displayName = "[JMSB] Vulcano-120 GLR"; descriptionShort = "120mm naval guided ER (2040)<br/>GPS/IIR precision naval fire support, ~40 km"; };
    class FA_32Rnd_120N_he: magazine_ShipCannon_120mm_HE_shells_x32 { author = QAUTHOR; displayName = "[JMSB] Mk-HE 120N"; descriptionShort = "120mm naval HE (2040)<br/>Ballistic naval high-explosive"; };
    class FA_2Rnd_120N_lg: magazine_ShipCannon_120mm_HE_LG_shells_x2 { author = QAUTHOR; displayName = "[JMSB] Mk-LG 120N"; descriptionShort = "120mm naval laser-guided (2040)<br/>SALH for movers / shore targets"; };
    class FA_2Rnd_120N_sfm: magazine_ShipCannon_120mm_HE_cluster_shells_x2 { author = QAUTHOR; displayName = "[JMSB] Mk-SFM 120N"; descriptionShort = "120mm naval sensor-fuzed submunition (2040)<br/>Replaces the naval cluster round"; };
    class FA_6Rnd_120N_smk: magazine_ShipCannon_120mm_smoke_shells_x6 { author = QAUTHOR; displayName = "[JMSB] Mk-SMK 120N"; descriptionShort = "120mm naval multispectral smoke (2040)<br/>Visual + thermal screen"; };

    // ---- CSAT 12.7x108 heavy MG belts (HMG_NSVT) ----
    class 450Rnd_127x108_Ball;
    class FA_450Rnd_127x108_7N40: 450Rnd_127x108_Ball { author = QAUTHOR; ammo = "FA_127x108_7N40"; displayName = "[JMSB] 450Rnd 12.7x108 7N40 AP-T"; descriptionShort = "12.7x108 tungsten AP-tracer (2040)"; };
    class FA_450Rnd_127x108_7N41: 450Rnd_127x108_Ball { author = QAUTHOR; ammo = "FA_127x108_7N41"; displayName = "[JMSB] 450Rnd 12.7x108 7N41 HEIAP"; descriptionShort = "12.7x108 HE incendiary AP (2040)"; };
    class FA_450Rnd_127x108_7N42: 450Rnd_127x108_Ball { author = QAUTHOR; ammo = "FA_127x108_7N42"; displayName = "[JMSB] 450Rnd 12.7x108 7N42 HEAB"; descriptionShort = "12.7x108 proximity airburst (2040)<br/>C-UAS - bursts near drones (PAB script)"; };
};
