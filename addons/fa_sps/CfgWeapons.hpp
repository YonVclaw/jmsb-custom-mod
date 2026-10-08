// =====================================================================
//  SPS AI AXMC — magazine wiring
//
//  The AXMC uses NO magazineWell (magazineWell[] = {} in its base class),
//  so the FA .338 Mk371 magazines defined in CfgMagazines.hpp cannot reach
//  the rifle through a well. They have to be appended directly to the
//  weapon's magazines[] array.
//
//  Only SPS_AI_AXMC338_27_PB_F defines magazines[]; every other .338 variant
//  (colors + PRCFB barrels) inherits it without override, so a single
//  += patch on the base propagates to all ten .338 rifles.
// =====================================================================
class CfgWeapons {
    class SPS_AI_AXMC_base_F;
    class SPS_AI_AXMC338_27_PB_F: SPS_AI_AXMC_base_F {
        magazines[] += {
            // Mk371 LRP 250gr
            "FA_SPS_AI_AXMC_338_Mk371_250gr_T_Red",
            "FA_SPS_AI_AXMC_338_Mk371_250gr_T_Yellow",
            "FA_SPS_AI_AXMC_338_Mk371_250gr_T_Green",
            "FA_SPS_AI_AXMC_338_Mk371_250gr_T_White",
            "FA_SPS_AI_AXMC_338_Mk371_250gr_T_Blue",
            "FA_SPS_AI_AXMC_338_Mk371_250gr_T_Orange",
            "FA_SPS_AI_AXMC_338_Mk371_250gr_T_IR",
            // Mk371 LRP 285gr
            "FA_SPS_AI_AXMC_338_Mk371_285gr_T_Red",
            "FA_SPS_AI_AXMC_338_Mk371_285gr_T_Yellow",
            "FA_SPS_AI_AXMC_338_Mk371_285gr_T_Green",
            "FA_SPS_AI_AXMC_338_Mk371_285gr_T_White",
            "FA_SPS_AI_AXMC_338_Mk371_285gr_T_Blue",
            "FA_SPS_AI_AXMC_338_Mk371_285gr_T_Orange",
            "FA_SPS_AI_AXMC_338_Mk371_285gr_T_IR",
            // Mk371 LRP 300gr
            "FA_SPS_AI_AXMC_338_Mk371_300gr_T_Red",
            "FA_SPS_AI_AXMC_338_Mk371_300gr_T_Yellow",
            "FA_SPS_AI_AXMC_338_Mk371_300gr_T_Green",
            "FA_SPS_AI_AXMC_338_Mk371_300gr_T_White",
            "FA_SPS_AI_AXMC_338_Mk371_300gr_T_Blue",
            "FA_SPS_AI_AXMC_338_Mk371_300gr_T_Orange",
            "FA_SPS_AI_AXMC_338_Mk371_300gr_T_IR"
        };
    };
    // .308 base — every .308 variant inherits this magazines[] without override
    class SPS_AI_AXMC308_26_PB_F: SPS_AI_AXMC_base_F {
        magazines[] += {
            // M80A2 HV
            "FA_SPS_AI_AXMC_762x51_M80A2_HV_T_Red",
            "FA_SPS_AI_AXMC_762x51_M80A2_HV_T_Yellow",
            "FA_SPS_AI_AXMC_762x51_M80A2_HV_T_Green",
            "FA_SPS_AI_AXMC_762x51_M80A2_HV_T_White",
            "FA_SPS_AI_AXMC_762x51_M80A2_HV_T_Blue",
            "FA_SPS_AI_AXMC_762x51_M80A2_HV_T_Orange",
            "FA_SPS_AI_AXMC_762x51_M80A2_HV_T_IR",
            // XM751 CTEP
            "FA_SPS_AI_AXMC_762x51_XM751_CTEP_T_Red",
            "FA_SPS_AI_AXMC_762x51_XM751_CTEP_T_Yellow",
            "FA_SPS_AI_AXMC_762x51_XM751_CTEP_T_Green",
            "FA_SPS_AI_AXMC_762x51_XM751_CTEP_T_White",
            "FA_SPS_AI_AXMC_762x51_XM751_CTEP_T_Blue",
            "FA_SPS_AI_AXMC_762x51_XM751_CTEP_T_Orange",
            "FA_SPS_AI_AXMC_762x51_XM751_CTEP_T_IR"
        };
    };
    // .300 WM base — every .300 variant inherits this magazines[] without override
    class SPS_AI_AXMC300_26_PB_F: SPS_AI_AXMC_base_F {
        magazines[] += {
            // Mk248 Mod 2
            "FA_SPS_AI_AXMC_762x67_Mk248Mod2_T_Red",
            "FA_SPS_AI_AXMC_762x67_Mk248Mod2_T_Yellow",
            "FA_SPS_AI_AXMC_762x67_Mk248Mod2_T_Green",
            "FA_SPS_AI_AXMC_762x67_Mk248Mod2_T_White",
            "FA_SPS_AI_AXMC_762x67_Mk248Mod2_T_Blue",
            "FA_SPS_AI_AXMC_762x67_Mk248Mod2_T_Orange",
            "FA_SPS_AI_AXMC_762x67_Mk248Mod2_T_IR",
            // Mk248 LV
            "FA_SPS_AI_AXMC_762x67_Mk248LV_T_Red",
            "FA_SPS_AI_AXMC_762x67_Mk248LV_T_Yellow",
            "FA_SPS_AI_AXMC_762x67_Mk248LV_T_Green",
            "FA_SPS_AI_AXMC_762x67_Mk248LV_T_White",
            "FA_SPS_AI_AXMC_762x67_Mk248LV_T_Blue",
            "FA_SPS_AI_AXMC_762x67_Mk248LV_T_Orange",
            "FA_SPS_AI_AXMC_762x67_Mk248LV_T_IR"
        };
    };
};
