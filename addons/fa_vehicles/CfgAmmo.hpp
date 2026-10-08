// Heavy-fires 2040 ammo for the vanilla artillery platforms (155mm AMOS SPGs,
// 230mm GAT MLRS). Only natures that need a distinct 2040 round are defined here;
// the inherit-only natures (GPS/Excalibur, laser, smoke, AP/AT mines, cluster/
// SFM) keep the vanilla ammo via their magazine body and aren't redefined.
class CfgAmmo {
    class Sh_155mm_AMOS;
    class R_230mm_HE;
    class M_Mo_230mm_guided;
    class M_Mo_230mm_AT;

    // 155mm HE-ER — extended-range prefragmented HE.
    class FA_155_heer: Sh_155mm_AMOS {
        indirectHit = 200;
        indirectHitRange = 40;
        ace_frag_metal = 6800;
        ace_frag_charge = 1800;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_large", "ace_frag_medium", "ace_frag_medium_HD"};
    };

    // 155mm thermobaric — enhanced-blast overpressure.
    class FA_155_tb: Sh_155mm_AMOS {
        indirectHit = 230;
        indirectHitRange = 50;
        ace_frag_metal = 1500;
        ace_frag_charge = 7000;
        ace_frag_gurney_c = 2400;
        ace_frag_gurney_k = 0.3;
        ace_frag_classes[] = {"ace_frag_tiny", "ace_frag_tiny_HD"};
    };

    // 230mm GMLRS unitary — precision unitary warhead (keeps the guided sim).
    class FA_230_gmlrsu: M_Mo_230mm_guided {
        indirectHit = 260;
        indirectHitRange = 45;
    };

    // 230mm GMLRS-ER — extended-range HE rocket.
    class FA_230_gmlrser: R_230mm_HE {
        indirectHit = 220;
        indirectHitRange = 45;
    };

    // 230mm AW — sensor-fuzed AT submunition rocket (keeps the AT submunition sim).
    class FA_230_aw: M_Mo_230mm_AT {
    };

    // =========================================================
    // 82mm Mk6 Mortar (vanilla, mortar_82mm) — 2040 natures. Baselines are the
    // vanilla 82mm AMOS ammo; guided/laser keep the vanilla precision sim.
    // =========================================================
    class ammo_Penetrator_Base;
    class Sh_82mm_AMOS;
    class Sh_82mm_AMOS_guided;
    class Sh_82mm_AMOS_LG;
    class Smoke_82mm_AMOS_White;
    class Flare_82mm_AMOS_White;

    // Per-side ammo: the West class carries the params; East (_O) / Ind (_I)
    // inherit it and just re-label (distinct class + displayName per side).
    // APMI — GPS precision HE
    class FA_82_apmi: Sh_82mm_AMOS_guided { displayName = "XM395-2 APMI"; hit = 190; indirectHit = 90; indirectHitRange = 18; };
    class FA_82_apmi_O: FA_82_apmi { displayName = "Type 82-GN"; };
    class FA_82_apmi_I: FA_82_apmi { displayName = "AF-82P"; };
    // LGM — laser homing HE
    class FA_82_lgm: Sh_82mm_AMOS_LG { displayName = "M-LGM"; hit = 190; indirectHit = 90; indirectHitRange = 18; };
    class FA_82_lgm_O: FA_82_lgm { displayName = "Type 82G Gran"; };
    class FA_82_lgm_I: FA_82_lgm { displayName = "AF-82L"; };
    // HE-ER — extended-range prefragmented HE
    class FA_82_heer: Sh_82mm_AMOS {
        displayName = "M821E1 HE-ER";
        hit = 210; indirectHit = 100; indirectHitRange = 20;
        ace_frag_metal = 3400; ace_frag_charge = 900; ace_frag_gurney_c = 2700; ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_medium", "ace_frag_medium_HD", "ace_frag_small_HD"};
    };
    class FA_82_heer_O: FA_82_heer { displayName = "Type 82-1 HE"; };
    class FA_82_heer_I: FA_82_heer { displayName = "AF-82E"; };
    // STRIX — terminal top-attack AT (guided + HEAT penetrator). 500mm RHA.
    class FA_ammo_Penetrator_82_strix: ammo_Penetrator_Base { caliber = 33.3; warheadName = "HEAT"; hit = 350; };
    class FA_82_strix: Sh_82mm_AMOS_guided {
        displayName = "M-STRIX AT";
        warheadName = "HEAT"; submunitionAmmo = "FA_ammo_Penetrator_82_strix";
        hit = 90; indirectHit = 30; indirectHitRange = 5;
    };
    class FA_82_strix_O: FA_82_strix { displayName = "Type 82K Kitolov"; };
    class FA_82_strix_I: FA_82_strix { displayName = "AF-82K"; };
    // MS smoke — multispectral (inherits the vanilla smoke effect)
    class FA_82_smk: Smoke_82mm_AMOS_White { displayName = "M-SMK MS"; };
    class FA_82_smk_O: FA_82_smk { displayName = "Type 82D"; };
    class FA_82_smk_I: FA_82_smk { displayName = "AF-82S"; };
    // IR illum — NVG-only flare (West only; inherits the vanilla flare)
    class FA_82_ir: Flare_82mm_AMOS_White { displayName = "M853 IR"; };
    // TB — thermobaric
    class FA_82_tb: Sh_82mm_AMOS {
        displayName = "M-TB";
        hit = 180; indirectHit = 130; indirectHitRange = 30;
        ace_frag_metal = 900; ace_frag_charge = 4000; ace_frag_gurney_c = 2400; ace_frag_gurney_k = 0.3;
        ace_frag_classes[] = {"ace_frag_tiny", "ace_frag_tiny_HD"};
    };
    class FA_82_tb_O: FA_82_tb { displayName = "Type 82TB"; };
    class FA_82_tb_I: FA_82_tb { displayName = "AF-82T"; };

    // =========================================================
    // Mk45 Hammer naval gun (vanilla weapon_ShipCannon_120mm, B_Ship_Gun_01_F).
    // West-only. The HE / laser / SFM / smoke naval rounds reskin the vanilla
    // ship ammo via their magazine body; only the Vulcano GLR needs distinct
    // 2040 ammo (guided extended-range precision).
    // =========================================================
    class ammo_ShipCannon_120mm_HE_guided;
    class FA_120N_glr: ammo_ShipCannon_120mm_HE_guided {
        indirectHit = 150;
        indirectHitRange = 25;
    };

    // =========================================================
    // CSAT 12.7x108 heavy MG (HMG_NSVT / Kord) — 2040. The East counterpart to
    // the FA 12.7x99 .50 belts (different cartridge). GRAU-designated.
    // =========================================================
    class B_127x108_Ball;
    class B_127x108_APDS;
    // 7N40 AP-T — tungsten armor-piercing tracer
    class FA_127x108_7N40: B_127x108_APDS {
        ACE_caliber = 12.98; ACE_bulletMass = 48.0;
    };
    // 7N41 HEIAP — high-explosive incendiary armor-piercing
    class FA_127x108_7N41: B_127x108_Ball {
        ACE_caliber = 12.98; ACE_bulletMass = 44.0;
        ace_frag_metal = 30; ace_frag_charge = 5; ace_frag_gurney_c = 2700; ace_frag_gurney_k = 0.7;
        ace_frag_classes[] = {"ace_frag_tiny_HD"};
    };
    // 7N42 HEAB — proximity airburst (anti-drone). Hooks the PAB script
    // (registered in XEH_postInit); flies as ball if the script is not loaded.
    class FA_127x108_7N42: B_127x108_Ball {
        ACE_caliber = 12.98; ACE_bulletMass = 43.0;
        ace_frag_metal = 40; ace_frag_charge = 6; ace_frag_gurney_c = 2700; ace_frag_gurney_k = 0.6;
        ace_frag_classes[] = {"ace_frag_tiny", "ace_frag_tiny_HD"};
    };
};
