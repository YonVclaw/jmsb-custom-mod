#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "jmfsb_fa_main",
            "jmfsb_notify",
            "cba_main",
            "ace_ballistics"
        };
        author = QAUTHOR;
        VERSION_CONFIG;
        ammo[] = {
            // 5.56 Mk361 PAB
            "FA_b_556_Mk361_PAB",
            // 7.62 Mk362 PAB
            "FA_b_762_Mk362_PAB",
            // .300 BLK Mk363 PAB
            "FA_b_300_Mk363_PAB",
            // 40mm Mk364 PAB
            "FA_b_40mm_Mk364_PAB",
            // .50 Mk366 PAB
            "FA_b_127_Mk366_PAB",
            // 6.5 caseless Mk367 PAB
            "FA_b_65_Mk367_PAB",
            // .338 Mk373 PAB
            "FA_b_338_Mk373_PAB",
            // PAB tracer ammo
            "FA_b_556_Mk361_PAB_T_Red",
            "FA_b_556_Mk361_PAB_T_Yellow",
            "FA_b_556_Mk361_PAB_T_Green",
            "FA_b_556_Mk361_PAB_T_White",
            "FA_b_556_Mk361_PAB_T_Blue",
            "FA_b_556_Mk361_PAB_T_Orange",
            "FA_b_762_Mk362_PAB_T_Red",
            "FA_b_762_Mk362_PAB_T_Yellow",
            "FA_b_762_Mk362_PAB_T_Green",
            "FA_b_762_Mk362_PAB_T_White",
            "FA_b_762_Mk362_PAB_T_Blue",
            "FA_b_762_Mk362_PAB_T_Orange",
            "FA_b_300_Mk363_PAB_T_Red",
            "FA_b_300_Mk363_PAB_T_Yellow",
            "FA_b_300_Mk363_PAB_T_Green",
            "FA_b_300_Mk363_PAB_T_White",
            "FA_b_300_Mk363_PAB_T_Blue",
            "FA_b_300_Mk363_PAB_T_Orange",
            "FA_b_127_Mk366_PAB_T_Red",
            "FA_b_127_Mk366_PAB_T_Yellow",
            "FA_b_127_Mk366_PAB_T_Green",
            "FA_b_127_Mk366_PAB_T_White",
            "FA_b_127_Mk366_PAB_T_Blue",
            "FA_b_127_Mk366_PAB_T_Orange",
            "FA_b_65_Mk367_PAB_T_Red",
            "FA_b_65_Mk367_PAB_T_Yellow",
            "FA_b_65_Mk367_PAB_T_Green",
            "FA_b_65_Mk367_PAB_T_White",
            "FA_b_65_Mk367_PAB_T_Blue",
            "FA_b_65_Mk367_PAB_T_Orange",
            "FA_b_338_Mk373_PAB_T_Red",
            "FA_b_338_Mk373_PAB_T_Yellow",
            "FA_b_338_Mk373_PAB_T_Green",
            "FA_b_338_Mk373_PAB_T_White",
            "FA_b_338_Mk373_PAB_T_Blue",
            "FA_b_338_Mk373_PAB_T_Orange",
            // Mk368/Mk369 AD buckshot (K short / L long)
            "FA_b_556_Mk368K_AD_Sub",
            "FA_b_556_Mk368K_AD",
            "FA_b_556_Mk368L_AD_Sub",
            "FA_b_556_Mk368L_AD",
            "FA_b_762_Mk369K_AD_Sub",
            "FA_b_762_Mk369K_AD",
            "FA_b_762_Mk369L_AD_Sub",
            "FA_b_762_Mk369L_AD"
        };
        magazines[] = {
            // 5.56 Mk361 PAB
            "FA_b_30Rnd_556_Mk361_PAB",
            // 7.62 Mk362 PAB
            "FA_b_20Rnd_762_Mk362_PAB",
            // .300 BLK Mk363 PAB
            "FA_b_30Rnd_300_Mk363_PAB",
            // 40mm Mk364 PAB
            "FA_b_1Rnd_40mm_Mk364_PAB",
            "FA_b_3Rnd_40mm_Mk364_PAB",
            // .50 Mk366 PAB
            "FA_b_100Rnd_127_Mk366_PAB",
            // 6.5 caseless Mk367 PAB 30Rnd (Sand / Green / Black)
            "FA_b_30Rnd_65_Mk367_PAB",
            "FA_b_30Rnd_65_Mk367_PAB_Green",
            "FA_b_30Rnd_65_Mk367_PAB_Black",
            // 6.5 caseless Mk367 PAB 100Rnd (Sand / Khaki / Black) — Mk200 LMG
            "FA_b_100Rnd_65_Mk367_PAB",
            "FA_b_100Rnd_65_Mk367_PAB_Khaki",
            "FA_b_100Rnd_65_Mk367_PAB_Black",
            // 6.5 Mk367 PAB — 200Rnd cased box (Mk200 LMG)
            "FA_b_200Rnd_65_Mk367_PAB",
            // .338 Mk373 PAB
            "FA_b_10Rnd_338_Mk373_PAB",
            // 6.5 caseless Mk367 PAB 30Rnd MSBS
            "FA_b_30Rnd_65_Mk367_PAB_MSBS",
            // PAB tracer mags
            "FA_b_30Rnd_556_Mk361_PAB_T_Red",
            "FA_b_30Rnd_556_Mk361_PAB_T_Yellow",
            "FA_b_30Rnd_556_Mk361_PAB_T_Green",
            "FA_b_30Rnd_556_Mk361_PAB_T_White",
            "FA_b_30Rnd_556_Mk361_PAB_T_Blue",
            "FA_b_30Rnd_556_Mk361_PAB_T_Orange",
            "FA_b_20Rnd_762_Mk362_PAB_T_Red",
            "FA_b_20Rnd_762_Mk362_PAB_T_Yellow",
            "FA_b_20Rnd_762_Mk362_PAB_T_Green",
            "FA_b_20Rnd_762_Mk362_PAB_T_White",
            "FA_b_20Rnd_762_Mk362_PAB_T_Blue",
            "FA_b_20Rnd_762_Mk362_PAB_T_Orange",
            "FA_b_30Rnd_300_Mk363_PAB_T_Red",
            "FA_b_30Rnd_300_Mk363_PAB_T_Yellow",
            "FA_b_30Rnd_300_Mk363_PAB_T_Green",
            "FA_b_30Rnd_300_Mk363_PAB_T_White",
            "FA_b_30Rnd_300_Mk363_PAB_T_Blue",
            "FA_b_30Rnd_300_Mk363_PAB_T_Orange",
            "FA_b_100Rnd_127_Mk366_PAB_T_Red",
            "FA_b_100Rnd_127_Mk366_PAB_T_Yellow",
            "FA_b_100Rnd_127_Mk366_PAB_T_Green",
            "FA_b_100Rnd_127_Mk366_PAB_T_White",
            "FA_b_100Rnd_127_Mk366_PAB_T_Blue",
            "FA_b_100Rnd_127_Mk366_PAB_T_Orange",
            "FA_b_30Rnd_65_Mk367_PAB_T_Red",
            "FA_b_30Rnd_65_Mk367_PAB_T_Yellow",
            "FA_b_30Rnd_65_Mk367_PAB_T_Green",
            "FA_b_30Rnd_65_Mk367_PAB_T_White",
            "FA_b_30Rnd_65_Mk367_PAB_T_Blue",
            "FA_b_30Rnd_65_Mk367_PAB_T_Orange",
            "FA_b_30Rnd_65_Mk367_PAB_Green_T_Red",
            "FA_b_30Rnd_65_Mk367_PAB_Green_T_Yellow",
            "FA_b_30Rnd_65_Mk367_PAB_Green_T_Green",
            "FA_b_30Rnd_65_Mk367_PAB_Green_T_White",
            "FA_b_30Rnd_65_Mk367_PAB_Green_T_Blue",
            "FA_b_30Rnd_65_Mk367_PAB_Green_T_Orange",
            "FA_b_30Rnd_65_Mk367_PAB_Black_T_Red",
            "FA_b_30Rnd_65_Mk367_PAB_Black_T_Yellow",
            "FA_b_30Rnd_65_Mk367_PAB_Black_T_Green",
            "FA_b_30Rnd_65_Mk367_PAB_Black_T_White",
            "FA_b_30Rnd_65_Mk367_PAB_Black_T_Blue",
            "FA_b_30Rnd_65_Mk367_PAB_Black_T_Orange",
            "FA_b_100Rnd_65_Mk367_PAB_T_Red",
            "FA_b_100Rnd_65_Mk367_PAB_T_Yellow",
            "FA_b_100Rnd_65_Mk367_PAB_T_Green",
            "FA_b_100Rnd_65_Mk367_PAB_T_White",
            "FA_b_100Rnd_65_Mk367_PAB_T_Blue",
            "FA_b_100Rnd_65_Mk367_PAB_T_Orange",
            "FA_b_100Rnd_65_Mk367_PAB_Khaki_T_Red",
            "FA_b_100Rnd_65_Mk367_PAB_Khaki_T_Yellow",
            "FA_b_100Rnd_65_Mk367_PAB_Khaki_T_Green",
            "FA_b_100Rnd_65_Mk367_PAB_Khaki_T_White",
            "FA_b_100Rnd_65_Mk367_PAB_Khaki_T_Blue",
            "FA_b_100Rnd_65_Mk367_PAB_Khaki_T_Orange",
            "FA_b_100Rnd_65_Mk367_PAB_Black_T_Red",
            "FA_b_100Rnd_65_Mk367_PAB_Black_T_Yellow",
            "FA_b_100Rnd_65_Mk367_PAB_Black_T_Green",
            "FA_b_100Rnd_65_Mk367_PAB_Black_T_White",
            "FA_b_100Rnd_65_Mk367_PAB_Black_T_Blue",
            "FA_b_100Rnd_65_Mk367_PAB_Black_T_Orange",
            "FA_b_200Rnd_65_Mk367_PAB_T_Red",
            "FA_b_200Rnd_65_Mk367_PAB_T_Yellow",
            "FA_b_200Rnd_65_Mk367_PAB_T_Green",
            "FA_b_200Rnd_65_Mk367_PAB_T_White",
            "FA_b_200Rnd_65_Mk367_PAB_T_Blue",
            "FA_b_200Rnd_65_Mk367_PAB_T_Orange",
            "FA_b_10Rnd_338_Mk373_PAB_T_Red",
            "FA_b_10Rnd_338_Mk373_PAB_T_Yellow",
            "FA_b_10Rnd_338_Mk373_PAB_T_Green",
            "FA_b_10Rnd_338_Mk373_PAB_T_White",
            "FA_b_10Rnd_338_Mk373_PAB_T_Blue",
            "FA_b_10Rnd_338_Mk373_PAB_T_Orange",
            "FA_b_30Rnd_65_Mk367_PAB_MSBS_T_Red",
            "FA_b_30Rnd_65_Mk367_PAB_MSBS_T_Yellow",
            "FA_b_30Rnd_65_Mk367_PAB_MSBS_T_Green",
            "FA_b_30Rnd_65_Mk367_PAB_MSBS_T_White",
            "FA_b_30Rnd_65_Mk367_PAB_MSBS_T_Blue",
            "FA_b_30Rnd_65_Mk367_PAB_MSBS_T_Orange",
            // Mk368/Mk369 AD buckshot (K short / L long)
            "FA_b_30Rnd_556_Mk368K_AD",
            "FA_b_30Rnd_556_Mk368L_AD",
            "FA_b_20Rnd_762_Mk369K_AD",
            "FA_b_20Rnd_762_Mk369L_AD"
        };
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazinewells.hpp"
#include "CfgVehicles.hpp"
