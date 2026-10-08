// Vorona (9M135) — 2040 round family, one tier under the MAAWS 2040 set.
// The two ground natures keep the Vorona's native SACLOS manual guidance
// (steer to the crosshair); the Osa borrows the Titan AA simulation for
// IR lock-on against air and drones.
// Penetration scale: engine RHA ~ penetrator caliber x 15 mm
// (vanilla Vorona HEAT penetrator = 650 mm baseline).
class CfgAmmo {
    class ammo_Penetrator_Base;
    class M_Vorona_HEAT;
    class M_Vorona_HE;
    class M_Titan_AA;

    // 9M135M Grom — 800 mm RHA (2040 tandem, ERA precursor + main)
    class FA_ammo_Penetrator_Vorona_9M135M: ammo_Penetrator_Base {
        caliber = 53.3;
        warheadName = "TandemHEAT";
        hit = 550;
    };

    // =========================================================
    // 9M135M Grom — primary anti-tank. Native Vorona SACLOS with
    // a heavier tandem warhead; range pulled in to 1800 m (the
    // MAAWS GM 841 keeps the 2000 m precision slot).
    // =========================================================
    class FA_M_Vorona_9M135M: M_Vorona_HEAT {
        warheadName = "TandemHEAT";
        submunitionAmmo = "FA_ammo_Penetrator_Vorona_9M135M";
        hit = 160;
        maxControlRange = 1800;
    };

    // =========================================================
    // 9M135F-2 Oskol — thermobaric + prefrag, programmable
    // airburst. Burst range is dialled with the antidrone
    // component's cycleBurst keybind (shared with the Mk364 and
    // MAAWS HE 448 AB). ACE frag: prefragmented sleeve.
    // =========================================================
    class FA_M_Vorona_9M135F2: M_Vorona_HE {
        hit = 270;
        indirectHit = 65;
        indirectHitRange = 12;
        maxControlRange = 1600;
        ace_frag_metal = 2600;
        ace_frag_charge = 600;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.6;
        ace_frag_classes[] = {"ace_frag_small", "ace_frag_small_HD", "ace_frag_medium_HD"};
    };

    // =========================================================
    // 9M135PVO Osa — IR lock-on vs helos, low/slow aircraft and
    // drones. Titan AA simulation, envelope deliberately under
    // the MAAWS AAM 517 SR (1200 m vs 1750 m).
    // =========================================================
    class FA_M_Vorona_9M135PVO: M_Titan_AA {
        hit = 75;
        indirectHit = 55;
        indirectHitRange = 8;
        proximityExplosionDistance = 10;
        maxSpeed = 700;
        thrustTime = 1.8;
        timeToLive = 10;
        missileLockMaxDistance = 1200;
        missileLockMinDistance = 75;
    };
};
