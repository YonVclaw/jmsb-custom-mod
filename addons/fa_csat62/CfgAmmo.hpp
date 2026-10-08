class CfgAmmo {
    class B_65x39_Caseless;   // structural base - 6.2x40 is fictional, rides the 6.5 caseless projectile

    // =========================================================
    // DBP-25 : caseless standard
    // =========================================================
    class FA_o_ammo_62_DBP25: B_65x39_Caseless {
        hit = 11; caliber = 2.7; typicalSpeed = 930; airFriction = -0.00110; deflecting = 14;
        ACE_caliber = 6.30; ACE_bulletLength = 26.0; ACE_bulletMass = 5.2;   // ~80 gr
        ACE_muzzleVelocityVariationSD = 0.16;
        ACE_ballisticCoefficients[] = {0.195}; ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO"; ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {880, 930, 965};
        ACE_barrelLengths[]    = {267, 393, 508};
    };
    class FA_o_ammo_62_DBP25_T_Red:    FA_o_ammo_62_DBP25 { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_o_ammo_62_DBP25_T_Yellow: FA_o_ammo_62_DBP25 { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_o_ammo_62_DBP25_T_Green:  FA_o_ammo_62_DBP25 { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_o_ammo_62_DBP25_T_White:  FA_o_ammo_62_DBP25 { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_o_ammo_62_DBP25_T_Blue:   FA_o_ammo_62_DBP25 { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_o_ammo_62_DBP25_T_Orange: FA_o_ammo_62_DBP25 { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_o_ammo_62_DBP25_T_IR:     FA_o_ammo_62_DBP25 { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // DBP-26 AP : caseless tungsten AP
    // =========================================================
    class FA_o_ammo_62_DBP26_AP: B_65x39_Caseless {
        hit = 11; caliber = 3.3; typicalSpeed = 900; airFriction = -0.00105; deflecting = 12;
        ACE_caliber = 6.30; ACE_bulletLength = 27.0; ACE_bulletMass = 5.5;   // tungsten core
        ACE_muzzleVelocityVariationSD = 0.15;
        ACE_ballisticCoefficients[] = {0.205}; ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO"; ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {850, 900, 935};
        ACE_barrelLengths[]    = {267, 393, 508};
    };
    class FA_o_ammo_62_DBP26_AP_T_Red:    FA_o_ammo_62_DBP26_AP { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_o_ammo_62_DBP26_AP_T_Yellow: FA_o_ammo_62_DBP26_AP { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_o_ammo_62_DBP26_AP_T_Green:  FA_o_ammo_62_DBP26_AP { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_o_ammo_62_DBP26_AP_T_White:  FA_o_ammo_62_DBP26_AP { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_o_ammo_62_DBP26_AP_T_Blue:   FA_o_ammo_62_DBP26_AP { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_o_ammo_62_DBP26_AP_T_Orange: FA_o_ammo_62_DBP26_AP { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_o_ammo_62_DBP26_AP_T_IR:     FA_o_ammo_62_DBP26_AP { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // DBP-88B : caseless heavy (DMR / GPMG)
    // =========================================================
    class FA_o_ammo_62_DBP88B: B_65x39_Caseless {
        hit = 12; caliber = 3.1; typicalSpeed = 860; airFriction = -0.00092; deflecting = 11;
        ACE_caliber = 6.30; ACE_bulletLength = 30.0; ACE_bulletMass = 6.3;   // heavy load
        ACE_muzzleVelocityVariationSD = 0.14;
        ACE_ballisticCoefficients[] = {0.240}; ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO"; ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {820, 860, 900};
        ACE_barrelLengths[]    = {480, 600, 660};
    };
    class FA_o_ammo_62_DBP88B_T_Red:    FA_o_ammo_62_DBP88B { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_o_ammo_62_DBP88B_T_Yellow: FA_o_ammo_62_DBP88B { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_o_ammo_62_DBP88B_T_Green:  FA_o_ammo_62_DBP88B { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_o_ammo_62_DBP88B_T_White:  FA_o_ammo_62_DBP88B { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_o_ammo_62_DBP88B_T_Blue:   FA_o_ammo_62_DBP88B { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_o_ammo_62_DBP88B_T_Orange: FA_o_ammo_62_DBP88B { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_o_ammo_62_DBP88B_T_IR:     FA_o_ammo_62_DBP88B { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    // =========================================================
    // DBJ-25 PAB : caseless proximity airburst (counter-UAS)
    //   burst is driven by the antidrone proximity-fuze registry
    //   (see XEH_postInit.sqf); flies as a plain round if absent.
    // =========================================================
    class FA_o_ammo_62_DBJ25_PAB: B_65x39_Caseless {
        hit = 6; caliber = 2.1; typicalSpeed = 910; airFriction = -0.00112; deflecting = 14;
        ACE_caliber = 6.30; ACE_bulletLength = 26.5; ACE_bulletMass = 5.1;
        ACE_muzzleVelocityVariationSD = 0.18;
        ACE_ballisticCoefficients[] = {0.190}; ACE_velocityBoundaries[] = {};
        ACE_standardAtmosphere = "ICAO"; ACE_dragModel = 7;
        ACE_muzzleVelocities[] = {860, 910, 945};
        ACE_barrelLengths[]    = {267, 393, 508};
    };
    class FA_o_ammo_62_DBJ25_PAB_T_Red:    FA_o_ammo_62_DBJ25_PAB { tracer = 1; tracerColor[] = {1.0, 0.0, 0.0, 1.0}; };
    class FA_o_ammo_62_DBJ25_PAB_T_Yellow: FA_o_ammo_62_DBJ25_PAB { tracer = 1; tracerColor[] = {1.0, 1.0, 0.0, 1.0}; };
    class FA_o_ammo_62_DBJ25_PAB_T_Green:  FA_o_ammo_62_DBJ25_PAB { tracer = 1; tracerColor[] = {0.0, 1.0, 0.0, 1.0}; };
    class FA_o_ammo_62_DBJ25_PAB_T_White:  FA_o_ammo_62_DBJ25_PAB { tracer = 1; tracerColor[] = {1.0, 1.0, 1.0, 1.0}; };
    class FA_o_ammo_62_DBJ25_PAB_T_Blue:   FA_o_ammo_62_DBJ25_PAB { tracer = 1; tracerColor[] = {0.0, 0.3, 1.0, 1.0}; };
    class FA_o_ammo_62_DBJ25_PAB_T_Orange: FA_o_ammo_62_DBJ25_PAB { tracer = 1; tracerColor[] = {1.0, 0.4, 0.0, 1.0}; };
    class FA_o_ammo_62_DBJ25_PAB_T_IR:     FA_o_ammo_62_DBJ25_PAB { tracer = 1; nvgOnly = 1; tracerColor[] = {0.2, 1.0, 0.2, 1.0}; };

    #include "CfgAmmo_compat.hpp"
};
