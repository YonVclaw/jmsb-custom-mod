// =====================================================================
//  Aegis SCAR — magazine wiring
//
//  The Aegis SCAR family uses NO magazineWell (its base class only sets
//  magazines[] = {20Rnd_762x51_Mag}), so FA 7.62x51 mags cannot reach it
//  through a well like the SR25/SLR do. They have to be appended directly
//  to the weapon's magazines[] array.
//
//  Only arifle_SCAR_base_F defines magazines[]; every other variant
//  (GL / short / grip + black / khaki colors) inherits it without override,
//  so a single += patch on the base propagates to all SCARs.
// =====================================================================
class CfgWeapons {
    class Rifle_Base_F;
    class arifle_SCAR_base_F: Rifle_Base_F {
        magazines[] += {
            // 7.62 M80A2 HV (hybrid case)
            "FA_b_20Rnd_762_M80A2_HV",
            "FA_20Rnd_762_M80A2_HV",
            "FA_b_20Rnd_762_M80A2_HV_T_Red",
            "FA_20Rnd_762_M80A2_HV_T_Red",
            "FA_b_20Rnd_762_M80A2_HV_T_Yellow",
            "FA_20Rnd_762_M80A2_HV_T_Yellow",
            "FA_b_20Rnd_762_M80A2_HV_T_Green",
            "FA_20Rnd_762_M80A2_HV_T_Green",
            "FA_b_20Rnd_762_M80A2_HV_T_White",
            "FA_20Rnd_762_M80A2_HV_T_White",
            "FA_b_20Rnd_762_M80A2_HV_T_Blue",
            "FA_20Rnd_762_M80A2_HV_T_Blue",
            "FA_b_20Rnd_762_M80A2_HV_T_Orange",
            "FA_20Rnd_762_M80A2_HV_T_Orange",
            "FA_b_20Rnd_762_M80A2_HV_T_IR",
            "FA_20Rnd_762_M80A2_HV_T_IR",
            // 7.62 XM751 CTEP (cased-telescoped)
            "FA_b_20Rnd_762_XM751_CTEP",
            "FA_20Rnd_762_XM751_CTEP",
            "FA_b_20Rnd_762_XM751_CTEP_T_Red",
            "FA_20Rnd_762_XM751_CTEP_T_Red",
            "FA_b_20Rnd_762_XM751_CTEP_T_Yellow",
            "FA_20Rnd_762_XM751_CTEP_T_Yellow",
            "FA_b_20Rnd_762_XM751_CTEP_T_Green",
            "FA_20Rnd_762_XM751_CTEP_T_Green",
            "FA_b_20Rnd_762_XM751_CTEP_T_White",
            "FA_20Rnd_762_XM751_CTEP_T_White",
            "FA_b_20Rnd_762_XM751_CTEP_T_Blue",
            "FA_20Rnd_762_XM751_CTEP_T_Blue",
            "FA_b_20Rnd_762_XM751_CTEP_T_Orange",
            "FA_20Rnd_762_XM751_CTEP_T_Orange",
            "FA_b_20Rnd_762_XM751_CTEP_T_IR",
            "FA_20Rnd_762_XM751_CTEP_T_IR"
        };
    };
};
