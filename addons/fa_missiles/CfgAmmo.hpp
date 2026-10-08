// Vehicle missiles — 2040 family, one tier above the infantry launchers
// (RPG-7 < RPG-32 < Vorona < MAAWS < these). Baselines are the vanilla
// vehicle missile natures; guided behaviour comes from the engine simulations
// they inherit (Titan / Scalpel / DAGR / Macer). Fiction for gameplay.
// Penetration scale: engine RHA ~ penetrator caliber x 15 mm
// (same rule as the maaws / vorona components).
// Hit anchors on that scale: 650 mm -> 500, 800 mm -> 550, 850 mm -> 570.
//
// NOTE (sensor components): HEMTT cannot inherit nested classes from an
// external parent, so the inherited Titan/Scalpel seeker component blocks are
// left untouched everywhere below — seeker flavour beyond the engine's
// IR/laser lock params (tri-mode, active radar, GPS/INS) is lore.
class CfgAmmo {
    class ammo_Penetrator_Base;
    class M_Titan_AT;
    class M_Titan_AA;
    class M_Scalpel_AT;
    class M_PG_AT;
    class Missile_AGM_02_F;

    // =========================================================
    // Shaped-charge penetrator submunitions
    // =========================================================
    // BGM-185 Broadsword — 1300 mm RHA (tandem, ERA precursor + main)
    class FA_ammo_Penetrator_BGM185: ammo_Penetrator_Base {
        caliber = 86.7;
        warheadName = "TandemHEAT";
        hit = 700;
    };
    // AGM-190 Wraith — 1200 mm RHA (tandem)
    class FA_ammo_Penetrator_AGM190: ammo_Penetrator_Base {
        caliber = 80;
        warheadName = "TandemHEAT";
        hit = 670;
    };
    // AGR-40 Hydra-P — 600 mm RHA (multipurpose, shaped mode)
    class FA_ammo_Penetrator_AGR40: ammo_Penetrator_Base {
        caliber = 40;
        warheadName = "TandemHEAT";
        hit = 480;
    };
    // XM1200 Copperhead — 800 mm RHA (AT shaped mode)
    class FA_ammo_Penetrator_XM1200: ammo_Penetrator_Base {
        caliber = 53.3;
        warheadName = "TandemHEAT";
        hit = 550;
    };

    // =========================================================
    // BGM-185 Broadsword — ground-vehicle ATGM (IFV / tank destroyer /
    // static). Titan AT simulation: fire-and-forget IR lock with the
    // inherited Direct / TopDown flight profiles; the NLOS shot is the
    // TopDown profile at the 10 km control ceiling.
    // =========================================================
    class FA_M_BGM185_Broadsword: M_Titan_AT {
        warheadName = "TandemHEAT";
        submunitionAmmo = "FA_ammo_Penetrator_BGM185";
        hit = 180;
        maxSpeed = 400;
        typicalSpeed = 380;
        thrustTime = 3;
        timeToLive = 60;
        missileLockMaxDistance = 6000;
        missileLockMinDistance = 100;
        maxControlRange = 10000;
    };

    // =========================================================
    // AGM-190 Wraith — attack-helo / UCAV ATGM. Scalpel simulation
    // (SAL homing + manual steer); IR lock added so it can also be
    // fired LOAL fire-and-forget. Warhead mode select (armor / soft)
    // is lore — terminally it is a tandem HEAT with a frag sleeve.
    // =========================================================
    class FA_M_AGM190_Wraith: M_Scalpel_AT {
        warheadName = "TandemHEAT";
        submunitionAmmo = "FA_ammo_Penetrator_AGM190";
        hit = 170;
        indirectHit = 40;
        indirectHitRange = 8;
        maxSpeed = 450;
        typicalSpeed = 420;
        timeToLive = 60;
        irLock = 1;
        laserLock = 1;
        missileLockMaxDistance = 8000;
        missileLockMinDistance = 100;
        maxControlRange = 12000;
        ace_frag_metal = 4500;
        ace_frag_charge = 1500;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.6;
        ace_frag_classes[] = {"ace_frag_small", "ace_frag_medium", "ace_frag_medium_HD"};
    };

    // =========================================================
    // AGM-205 Warhammer — fixed-wing standoff AGM (anti-structure /
    // anti-ship). Macer simulation; penetrating blast-frag, no HEAT
    // submunition. Two-way datalink / man-in-loop is lore — in engine
    // it is a long-reach IR lock.
    // =========================================================
    class FA_M_AGM205_Warhammer: Missile_AGM_02_F {
        hit = 750;
        indirectHit = 200;
        indirectHitRange = 25;
        maxSpeed = 850;
        typicalSpeed = 800;
        timeToLive = 120;
        missileLockMaxDistance = 12000;
        missileLockMinDistance = 300;
        maxControlRange = 25000;
        ace_frag_metal = 9500;
        ace_frag_charge = 4200;
        ace_frag_gurney_c = 2830;
        ace_frag_gurney_k = 0.8;
        ace_frag_classes[] = {"ace_frag_medium", "ace_frag_medium_HD", "ace_frag_large"};
    };

    // =========================================================
    // MIM-165 Sentry — SPAAG / AA-vehicle SAM. Titan AA simulation;
    // engages fast jets down to drones. Dual active-radar / IR seeker
    // is lore (see sensor note above); proximity fuze is engine-native.
    // =========================================================
    class FA_M_MIM165_Sentry: M_Titan_AA {
        hit = 120;
        indirectHit = 90;
        indirectHitRange = 15;
        proximityExplosionDistance = 20;
        maxSpeed = 1100;
        thrustTime = 3.5;
        timeToLive = 30;
        missileLockMaxDistance = 12000;
        missileLockMinDistance = 150;
        ace_frag_metal = 3000;
        ace_frag_charge = 900;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.6;
        ace_frag_classes[] = {"ace_frag_small", "ace_frag_small_HD", "ace_frag_medium_HD"};
    };

    // =========================================================
    // AGR-40 Hydra-P — laser-guided rocket (APKWS-style pod retrofit).
    // DAGR simulation (SAL homing); salvo-capable from the pod. The
    // counter-UAS mode is the mediumcaliber component's scripted
    // proximity fuze (registered in XEH_postInit); flies as a normal
    // guided rocket if that script is not loaded.
    // =========================================================
    class FA_M_AGR40_HydraP: M_PG_AT {
        warheadName = "TandemHEAT";
        submunitionAmmo = "FA_ammo_Penetrator_AGR40";
        hit = 90;
        indirectHit = 50;
        indirectHitRange = 12;
        maxSpeed = 500;
        typicalSpeed = 450;
        timeToLive = 40;
        missileLockMaxDistance = 8000;
        maxControlRange = 8000;
        ace_frag_metal = 2400;
        ace_frag_charge = 550;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.6;
        ace_frag_classes[] = {"ace_frag_small", "ace_frag_small_HD", "ace_frag_medium_HD"};
    };

    // =========================================================
    // XM1200 Copperhead — loitering munition (vehicle canister / drone
    // rail). Titan AT simulation for the locked (LOBL) shot; fired
    // WITHOUT a lock it hands over to the loiter script — climb,
    // orbit, autonomous terminal attack on the first hostile vehicle
    // that enters the basket (fnc_loiterCopperhead). Endurance is capped by
    // timeToLive (300 s engine budget standing in for the 30 min of
    // lore endurance).
    // =========================================================
    class FA_M_XM1200_Copperhead: M_Titan_AT {
        warheadName = "TandemHEAT";
        submunitionAmmo = "FA_ammo_Penetrator_XM1200";
        hit = 140;
        indirectHit = 70;
        indirectHitRange = 20;
        maxSpeed = 200;
        typicalSpeed = 130;
        thrustTime = 8;
        timeToLive = 300;
        irLock = 1;
        laserLock = 1;
        missileLockMaxDistance = 4000;
        missileLockMinDistance = 50;
        maxControlRange = 40000;
        ace_frag_metal = 3200;
        ace_frag_charge = 1000;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.6;
        ace_frag_classes[] = {"ace_frag_small", "ace_frag_medium", "ace_frag_medium_HD"};
    };

    // =========================================================
    // MIM-166 Roadrunner — dedicated C-UAS hard-kill missile. Titan AA
    // simulation with the seeker basket pulled in close and the lock
    // speed gate raised enough to catch incoming loitering munitions;
    // cheaper per shot than spending a Sentry.
    // =========================================================
    class FA_M_MIM166_Roadrunner: M_Titan_AA {
        hit = 55;
        indirectHit = 40;
        indirectHitRange = 12;
        proximityExplosionDistance = 12;
        maxSpeed = 650;
        thrustTime = 1.5;
        timeToLive = 15;
        missileLockMaxDistance = 4000;
        missileLockMinDistance = 50;
        missileLockMaxSpeed = 250;
        ace_frag_metal = 1800;
        ace_frag_charge = 350;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.5;
        ace_frag_classes[] = {"ace_frag_small", "ace_frag_small_HD"};
    };

    // =========================================================
    // Fixed-wing aircraft missiles — 2040. Fills the base-game gap (jets carry
    // only short-range IR AA + Macer AGM): adds medium/long radar AA, SEAD,
    // standoff cruise, anti-ship. One ammo per role; three side-named pylon
    // magazines ride each (see CfgMagazines.hpp). Ranges are 2040 projections,
    // effectively BVR on Arma maps. Baselines: Missile_AA_04 (IR AA),
    // Missile_AA_03 (radar AA), Missile_AGM_02 (Macer AGM). No nuclear.
    // =========================================================
    class Missile_AA_04_F;
    class Missile_AA_03_F;
    // (Missile_AGM_02_F already forward-declared above for the Warhammer)

    // Short-range IR AA — 35 km, imaging IR. Per-side distinct ammo.
    class FA_M_AIM9X3: Missile_AA_04_F {
        displayName = "AIM-9X Blk III";
        maxSpeed = 1100; timeToLive = 30;
        maxControlRange = 8000; missileLockMaxDistance = 8000;
    };
    class FA_M_R74M: FA_M_AIM9X3 { displayName = "R-74M"; };
    class FA_M_IRIST: FA_M_AIM9X3 { displayName = "IRIS-T"; };

    // Medium-range radar AA — 160 km, active radar. Per-side distinct ammo.
    class FA_M_AIM120E: Missile_AA_03_F {
        displayName = "AIM-120E";
        maxSpeed = 1400; timeToLive = 60;
        maxControlRange = 12000; missileLockMaxDistance = 12000;
    };
    class FA_M_R77M: FA_M_AIM120E { displayName = "R-77M"; };
    class FA_M_MICANG: FA_M_AIM120E { displayName = "MICA-NG"; };

    // Long-range AA — 300 km, networked BVR. Per-side distinct ammo.
    class FA_M_AIM260: Missile_AA_03_F {
        displayName = "AIM-260 JATM";
        maxSpeed = 1700; timeToLive = 90;
        maxControlRange = 16000; missileLockMaxDistance = 16000;
    };
    class FA_M_R37M: FA_M_AIM260 { displayName = "R-37M"; };
    class FA_M_Meteor: FA_M_AIM260 { displayName = "Meteor"; };
    // SEAD anti-radiation (AGM-88G AARGM-ER / Kh-31PD / AARGM-E) — 300 km.
    class FA_M_sead: Missile_AGM_02_F {
        maxSpeed = 1200; timeToLive = 90;
        maxControlRange = 14000; missileLockMaxDistance = 14000;
    };
    // Standoff cruise (AGM-158D JASSM-XR / Kh-101 / SCALP-EG) — 900 km, low-obs.
    class FA_M_cruise: Missile_AGM_02_F {
        maxSpeed = 340; timeToLive = 300;
        maxControlRange = 20000; missileLockMaxDistance = 20000;
        hit = 900; indirectHit = 300; indirectHitRange = 30;
    };
    // Anti-ship (AGM-158C LRASM / Kh-35UE / RBS-15 Mk4) — 500 km, sea-skimming.
    class FA_M_antiship: Missile_AGM_02_F {
        maxSpeed = 340; timeToLive = 240;
        maxControlRange = 16000; missileLockMaxDistance = 16000;
        hit = 700; indirectHit = 250; indirectHitRange = 25;
    };
};
