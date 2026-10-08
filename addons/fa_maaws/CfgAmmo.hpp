// MAAWS / MRAWS (Carl Gustaf M4) — 2040 round family.
// Baselines are the vanilla Tanks-DLC MAAWS Mk4 natures (R_MRAAWS_*); the
// guided/seeking rounds borrow the Titan missile simulation (M_Titan_*) so
// lock-on, top-attack profiles and proximity fuzing come from the engine.
// Penetration scale: engine RHA ~ penetrator caliber x 15 mm
// (vanilla HEAT 75 = 33.3 -> ~500 mm, HEAT 55 = 26.7 -> ~400 mm).
class CfgAmmo {
    class BulletBase;
    class ammo_Penetrator_Base;
    class R_MRAAWS_HE_F;
    class R_MRAAWS_HEAT55_F;
    class M_Titan_AT;
    class M_Titan_AA;

    // =========================================================
    // Shaped-charge penetrator submunitions
    // =========================================================
    // HEAT 758 TT — 850 mm RHA (2040 tandem, ERA precursor + main)
    class FA_ammo_Penetrator_MRAWS_758: ammo_Penetrator_Base {
        caliber = 56.7;
        warheadName = "TandemHEAT";
        hit = 570;
    };
    // HEAT 665 CS — 650 mm RHA (2040 tandem, confined-space)
    class FA_ammo_Penetrator_MRAWS_665: ammo_Penetrator_Base {
        caliber = 43.3;
        warheadName = "TandemHEAT";
        hit = 500;
    };
    // GM 841 — 700 mm RHA (tandem dual-purpose AT + structure)
    class FA_ammo_Penetrator_MRAWS_841: ammo_Penetrator_Base {
        caliber = 46.7;
        warheadName = "TandemHEAT";
        hit = 530;
    };

    // =========================================================
    // HEAT 758 TT — primary anti-tank, fire-and-forget top-attack
    // Titan simulation: LOAL lock (ground IR), Direct / TopDown
    // flight profiles inherited from M_Titan_AT.
    // =========================================================
    class FA_R_MRAWS_HEAT758_TT: M_Titan_AT {
        model = "\A3\Weapons_F_Tank\Launchers\MRAWS\rocket_MRAWS_HEAT_F.p3d";
        warheadName = "TandemHEAT";
        submunitionAmmo = "FA_ammo_Penetrator_MRAWS_758";
        hit = 110;
        maxSpeed = 290;
        typicalSpeed = 270;
        missileLockMaxDistance = 1200;
        missileLockMinDistance = 50;
        maxControlRange = 1200;
    };

    // =========================================================
    // HEAT 665 CS — heavy tandem HEAT, confined-space (unguided).
    // Counter-mass / low signature is lore; ballistically a slower,
    // harder-hitting HEAT 55.
    // =========================================================
    class FA_R_MRAWS_HEAT665_CS: R_MRAAWS_HEAT55_F {
        warheadName = "TandemHEAT";
        submunitionAmmo = "FA_ammo_Penetrator_MRAWS_665";
        hit = 110;
        // Match vanilla MRAWS muzzle velocity (350) so the FCS optic reticle
        // zeroes correctly; a slower round drops well short of the aimpoint.
        maxSpeed = 350;
    };

    // =========================================================
    // HE 448 AB — prefragmented HE, programmable airburst.
    // Burst range is dialled with the antidrone component's
    // cycleBurst keybind (shared with the 40mm Mk364); trigger
    // radius 0 in the registry disables its drone-proximity check.
    // ACE frag: prefragmented sleeve, ~3.1 kg warhead.
    // =========================================================
    class FA_R_MRAWS_HE448_AB: R_MRAAWS_HE_F {
        hit = 220;
        indirectHit = 55;
        indirectHitRange = 9;
        // Match vanilla MRAWS muzzle velocity (350) so the FCS optic reticle
        // zeroes correctly; a slower round drops well short of the aimpoint.
        maxSpeed = 350;
        ace_frag_metal = 2400;
        ace_frag_charge = 550;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.6;
        ace_frag_classes[] = {"ace_frag_small", "ace_frag_small_HD", "ace_frag_medium_HD"};
    };

    // =========================================================
    // GM 841 — semi-active laser homing, precision vs movers /
    // bunkers. Lases via any laser designator; manual steer to the
    // crosshair (inherited manualControl) covers the direct profile.
    // =========================================================
    class FA_M_MRAWS_GM841: M_Titan_AT {
        model = "\A3\Weapons_F_Tank\Launchers\MRAWS\rocket_MRAWS_HEAT_F.p3d";
        warheadName = "TandemHEAT";
        submunitionAmmo = "FA_ammo_Penetrator_MRAWS_841";
        hit = 130;
        indirectHit = 25;
        indirectHitRange = 4;
        maxSpeed = 270;
        typicalSpeed = 250;
        airLock = 0;
        irLock = 0;
        laserLock = 1;
        weaponLockSystem = 4;
        missileLockMaxDistance = 2000;
        missileLockMinDistance = 50;
        maxControlRange = 2000;
    };

    // =========================================================
    // ADM 484 PROX — counter-UAS proximity frag (unguided).
    // The kill is the antidrone component's scripted proximity fuze
    // (registered in XEH_postInit); flies as a normal HE rocket if
    // the script is not loaded. ACE frag: prefragmented, ~3.0 kg.
    // =========================================================
    class FA_R_MRAWS_ADM484: R_MRAAWS_HE_F {
        hit = 130;
        indirectHit = 45;
        indirectHitRange = 12;
        maxSpeed = 260;
        ace_frag_metal = 2500;
        ace_frag_charge = 400;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_small", "ace_frag_small_HD"};
    };

    // =========================================================
    // ADM 486 CAN — anti-swarm tungsten flechette canister.
    // Muzzle-triggered submunition burst (config only, no script):
    // the carrier flies ~15 m then dumps a poisson-disc cone of
    // flechettes, same idea as the 12 ga Mk360 AD dense spread.
    // =========================================================
    class FA_R_MRAWS_ADM486_flechette: BulletBase {
        hit = 15;
        caliber = 2;
        typicalSpeed = 380;
        airFriction = -0.0012;
        airLock = 1;
        timeToLive = 3;
        deflecting = 0;
        cost = 5;
        model = "\A3\Weapons_f\Data\bullettracer\tracer_white";
        tracerScale = 0.8;
        tracerStartTime = 0;
        tracerEndTime = 1;
    };
    class FA_R_MRAWS_ADM486: R_MRAAWS_HE_F {
        simulation = "shotSubmunitions";
        submunitionAmmo = "FA_R_MRAWS_ADM486_flechette";
        submunitionConeType[] = {"poissondisc", 40};
        submunitionConeAngle = 6;
        triggerTime = 0.05;
        deleteParentWhenTriggered = 1;
        hit = 10;
        indirectHit = 0;
        indirectHitRange = 0;
        maxSpeed = 290;
    };

    // =========================================================
    // ADM 487 SEEK — IR fire-and-forget vs a locked drone.
    // Titan AA simulation with the seeker envelope pulled in close
    // (lock 30–1000 m) and slowed to drone-hunting speeds.
    // =========================================================
    class FA_M_MRAWS_ADM487: M_Titan_AA {
        hit = 70;
        indirectHit = 50;
        indirectHitRange = 8;
        proximityExplosionDistance = 8;
        maxSpeed = 600;
        thrustTime = 1.5;
        thrust = 300;
        timeToLive = 12;
        missileLockMaxDistance = 1000;
        missileLockMinDistance = 30;
        missileLockMaxSpeed = 200;
        // seeker envelope approximated by the lock params above; the inherited
        // Titan AA IR sensor component is left untouched (HEMTT cannot inherit
        // nested classes from an external parent)
    };

    // =========================================================
    // AAM 517 SR — very-short-range AA (helos, low/slow aircraft,
    // large UAS). Deliberately half the Titan AA envelope (1750 m
    // vs 3500 m) — a last-ditch shoulder option, not a replacement.
    // =========================================================
    class FA_M_MRAWS_AAM517: M_Titan_AA {
        hit = 85;
        indirectHit = 60;
        indirectHitRange = 8;
        proximityExplosionDistance = 10;
        maxSpeed = 800;
        thrustTime = 2;
        timeToLive = 10;
        missileLockMaxDistance = 1750;
        missileLockMinDistance = 100;
    };
};
