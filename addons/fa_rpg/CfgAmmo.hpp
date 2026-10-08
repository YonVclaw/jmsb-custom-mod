// RPG-32 / RPG-7 — 2040 round family, the unguided bottom tiers of the 2040
// launcher set (RPG-7 < RPG-32 < Vorona < MAAWS). All rounds stay unguided;
// the AB natures get their drone kill from the antidrone component's scripted
// proximity fuze (registered in XEH_postInit).
// Penetration scale: engine RHA ~ penetrator caliber x 15 mm
// (vanilla RPG-32 PG-32V = 43.3 -> ~650 mm, RPG-7 PG-7 = 20 -> ~300 mm).
class CfgAmmo {
    class ammo_Penetrator_Base;
    class R_PG32V_F;
    class R_TBG32V_F;
    class R_PG7_F;

    // =========================================================
    // Shaped-charge penetrator submunitions
    // =========================================================
    // PG-32V-2 — 700 mm RHA (2040 tandem)
    class FA_ammo_Penetrator_RPG32V2: ammo_Penetrator_Base {
        caliber = 46.7;
        warheadName = "TandemHEAT";
        hit = 500;
    };
    // PG-7VR-2 — 550 mm RHA (2040 tandem, the cheapest tandem in the set)
    class FA_ammo_Penetrator_PG7VR2: ammo_Penetrator_Base {
        caliber = 36.7;
        warheadName = "TandemHEAT";
        hit = 460;
    };

    // =========================================================
    // RPG-32 (105 mm)
    // =========================================================
    // PG-32V-2 — improved tandem HEAT (vanilla PG-32V is already tandem)
    class FA_R_RPG32_PG32V2: R_PG32V_F {
        submunitionAmmo = "FA_ammo_Penetrator_RPG32V2";
        hit = 160;
    };
    // TBG-32V-2 — thermobaric, anti-structure / anti-personnel blast
    class FA_R_RPG32_TBG32V2: R_TBG32V_F {
        hit = 230;
        indirectHit = 60;
        indirectHitRange = 9;
    };
    // AB-32 PROX — prefragmented proximity airburst vs drones. The kill is
    // the antidrone scripted fuze; flies as a normal HE rocket without it.
    class FA_R_RPG32_AB32: R_TBG32V_F {
        hit = 110;
        indirectHit = 40;
        indirectHitRange = 8;
        ace_frag_metal = 1800;
        ace_frag_charge = 300;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_small", "ace_frag_small_HD"};
    };

    // =========================================================
    // RPG-7 (93 mm over-caliber)
    // =========================================================
    // PG-7VR-2 — tandem HEAT (vanilla R_PG7_F is single-charge HE warhead)
    class FA_R_RPG7_PG7VR2: R_PG7_F {
        warheadName = "TandemHEAT";
        submunitionAmmo = "FA_ammo_Penetrator_PG7VR2";
        hit = 100;
    };
    // TBG-7V-2 — thermobaric; drop the penetrator, pure blast
    class FA_R_RPG7_TBG7V2: R_PG7_F {
        submunitionAmmo = "";
        submunitionDirectionType = "";
        submunitionInitSpeed = 0;
        triggerOnImpact = 0;
        warheadName = "HE";
        hit = 170;
        indirectHit = 45;
        indirectHitRange = 8;
    };
    // AB-7 PROX — smallest proximity airburst in the set; scripted fuze
    class FA_R_RPG7_AB7: R_PG7_F {
        submunitionAmmo = "";
        submunitionDirectionType = "";
        submunitionInitSpeed = 0;
        triggerOnImpact = 0;
        warheadName = "HE";
        hit = 85;
        indirectHit = 32;
        indirectHitRange = 6;
        ace_frag_metal = 1400;
        ace_frag_charge = 220;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_small", "ace_frag_small_HD"};
    };
};
