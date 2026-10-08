// Mk 153 SMAW (JCA) — 2040 round family. 83mm USMC shoulder assault weapon,
// MAAWS-tier but anti-structure flavored. Baselines are the vanilla MAAWS Mk4
// natures (R_MRAAWS_*); the guided Mk22 GS borrows the Titan missile sim
// (M_Titan_AT) for manual (SACLOS) steering off the PWS fire-control sight.
//
// Damage is deliberately kept BELOW the infantry Titan tier: the vanilla Titan
// AT is carrier hit 95 with an ammo_Penetrator_Titan_AT of caliber 60 (~900mm
// RHA) / hit 585. Every SMAW round here stays under that — carrier hit <= 90 and
// penetrators below caliber 60 / hit 585 — so the SMAW never out-damages a Titan.
// Penetration scale (engine): RHA ~ penetrator caliber x 15 mm.
class CfgAmmo {
    class ammo_Penetrator_Base;
    class R_MRAAWS_HE_F;
    class R_MRAAWS_HEAT55_F;
    class M_Titan_AT;

    // =========================================================
    // Shaped-charge penetrator submunitions (all below Titan's caliber 60 / 585)
    // =========================================================
    // HEAA (Mk6 Mod 2, tandem) — ~720mm RHA
    class FA_ammo_Penetrator_smaw_HEAA: ammo_Penetrator_Base {
        caliber = 48.0;
        warheadName = "TandemHEAT";
        hit = 500;
    };
    // CS (Mk7, tandem low-signature) — ~600mm RHA
    class FA_ammo_Penetrator_smaw_CS: ammo_Penetrator_Base {
        caliber = 40.0;
        warheadName = "TandemHEAT";
        hit = 420;
    };
    // GS (Mk22, tandem dual-purpose, guided) — ~675mm RHA
    class FA_ammo_Penetrator_smaw_GS: ammo_Penetrator_Base {
        caliber = 45.0;
        warheadName = "TandemHEAT";
        hit = 480;
    };
    // HEDP (Mk3 Mod 2, shaped element) — ~270mm RHA
    class FA_ammo_Penetrator_smaw_HEDP: ammo_Penetrator_Base {
        caliber = 18.0;
        warheadName = "HEAT";
        hit = 200;
    };

    // =========================================================
    // Mk6 Mod 2 HEAA-T — tandem anti-armor, unguided direct. ~720mm RHA.
    // =========================================================
    class FA_R_smaw_Mk6Mod2_HEAA: R_MRAAWS_HEAT55_F {
        warheadName = "TandemHEAT";
        submunitionAmmo = "FA_ammo_Penetrator_smaw_HEAA";
        hit = 80;
        maxSpeed = 260;
    };

    // =========================================================
    // Mk3 Mod 2 HEDP-P — dual-purpose HE + shaped, programmable airburst.
    // Burst range shares the Mk364 airburst keybind / ACE self-menu.
    // =========================================================
    class FA_R_smaw_Mk3Mod2_HEDP: R_MRAAWS_HE_F {
        warheadName = "HEAT";
        submunitionAmmo = "FA_ammo_Penetrator_smaw_HEDP";
        hit = 80;
        indirectHit = 40;
        indirectHitRange = 8;
        maxSpeed = 250;
        ace_frag_metal = 1600;
        ace_frag_charge = 500;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.6;
        ace_frag_classes[] = {"ace_frag_small", "ace_frag_small_HD", "ace_frag_medium_HD"};
    };

    // =========================================================
    // Mk80 Mod 1 NE — enhanced novel-explosive (thermobaric). Big overpressure
    // radius, bunker / room clearer. No armor penetration (no penetrator).
    // =========================================================
    class FA_R_smaw_Mk80Mod1_NE: R_MRAAWS_HE_F {
        hit = 90;
        indirectHit = 85;
        indirectHitRange = 24;
        maxSpeed = 240;
        ace_frag_metal = 800;
        ace_frag_charge = 3000;
        ace_frag_gurney_c = 2400;
        ace_frag_gurney_k = 0.3;
        ace_frag_classes[] = {"ace_frag_tiny", "ace_frag_tiny_HD"};
    };

    // =========================================================
    // Mk7 CS — tandem HEAT, confined-space (reduced backblast, fire from inside).
    // ~600mm RHA.
    // =========================================================
    class FA_R_smaw_Mk7_CS: R_MRAAWS_HEAT55_F {
        warheadName = "TandemHEAT";
        submunitionAmmo = "FA_ammo_Penetrator_smaw_CS";
        hit = 75;
        maxSpeed = 220;
    };

    // =========================================================
    // Mk85 FTG — follow-through grenade. Breaching charge punches the wall, then
    // a submunition grenade detonates just beyond it. Config approximation of the
    // scripted 2-stage: the carrier triggers on impact and releases an HE grenade
    // forward through the breach.
    // =========================================================
    class FA_smaw_FTG_grenade: R_MRAAWS_HE_F {
        hit = 70;
        indirectHit = 55;
        indirectHitRange = 6;
        timeToLive = 0.6;
        maxSpeed = 120;
        soundHit1[] = {"", 1, 1, 200};
    };
    class FA_R_smaw_Mk85_FTG: R_MRAAWS_HEAT55_F {
        warheadName = "HEAT";
        submunitionAmmo = "FA_smaw_FTG_grenade";
        submunitionInitSpeed = 120;
        triggerOnImpact = 1;
        deleteParentWhenTriggered = 1;
        hit = 70;
        indirectHit = 18;
        indirectHitRange = 3;
        maxSpeed = 230;
    };

    // =========================================================
    // Mk22 GS — guided precision (SMAW II FCS lineage). Titan-AT sim for manual
    // (SACLOS) steering to the PWS crosshair. Kept clearly below the Titan AT it
    // borrows from (carrier 85 < 95, penetrator caliber 45 / hit 480 < 60 / 585).
    // =========================================================
    class FA_M_smaw_Mk22_GS: M_Titan_AT {
        warheadName = "TandemHEAT";
        submunitionAmmo = "FA_ammo_Penetrator_smaw_GS";
        hit = 85;
        indirectHit = 18;
        indirectHitRange = 3;
        maxSpeed = 260;
        typicalSpeed = 250;
        maxControlRange = 800;
        missileLockMaxDistance = 800;
        missileLockMinDistance = 30;
    };

    // =========================================================
    // Mk18 ADM — counter-UAS prefragmented proximity (unguided). Hooks the same
    // antidrone proximity fuze as the PAB family; plain HE rocket if not loaded.
    // =========================================================
    class FA_R_smaw_Mk18_ADM: R_MRAAWS_HE_F {
        hit = 85;
        indirectHit = 38;
        indirectHitRange = 10;
        maxSpeed = 260;
        ace_frag_metal = 2000;
        ace_frag_charge = 400;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_small", "ace_frag_small_HD"};
    };
};
