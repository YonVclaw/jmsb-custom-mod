class CfgWeapons {
#include "acp_full_externs.hpp"
#include "imported_CfgWeapons_decl.hpp"
#include "imported_CfgWeapons.hpp"
    class H_Booniehat_khk_hs;

    // AEGIS'S FAST-MT, LINKED NOT COPIED (user, 2026-08-29: "things copied
    // from Aegis or Atlas need to be removed and the dependencies moved back to
    // linking to Aegis/Atlas"). The three FAST-MT models, their materials and
    // maps, and the tan / ranger-green / black / coyote paints this addon
    // shipped were Aegis's own; they are gone, and Aegis_H_Helmet_FASTMT_* are
    // the classes to reach for. What is left below is OURS - the Multicam,
    // Multicam Alpine, Multicam Woodland and US OCP paints and the cover
    // paints - each inheriting Aegis's base class and putting its own texture
    // on Aegis's model. The headset and the base helmet under a painted cover
    // are Aegis's textures by path.

    /* FAST-MT Helmet - our paints on Aegis's helmet */
    class GVAR(H_Helmet_FASTMT_Multicam_F): GVAR(H_Helmet_FASTMT_base_F) {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] FAST-MT Helmet (Multicam)";
        picture = "\z\jmfsb\addons\headware\models\characters\Headgear\Data\UI\Aegis_H_Helmet_FASTMT_tan_F_ca.paa";
        hiddenSelectionsTextures[] = {QPATHTOF(data\H_HelmetFASTMT_Multicam_CO.paa)};
    };
    class GVAR(H_Helmet_FASTMT_Multicam_Snow_F): GVAR(H_Helmet_FASTMT_base_F) {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] FAST-MT Helmet (Multicam Alpine)";
        picture = "\z\jmfsb\addons\headware\models\characters\Headgear\Data\UI\Aegis_H_Helmet_FASTMT_tan_F_ca.paa";
        hiddenSelectionsTextures[] = {QPATHTOF(data\H_HelmetFASTMT_Multicam_Snow_CO.paa)};
    };
    class GVAR(H_Helmet_FASTMT_A3_Multicam_Woodland_F): GVAR(H_Helmet_FASTMT_base_F) {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] FAST-MT Helmet (Multicam Woodland)";
        picture = "\z\jmfsb\addons\headware\models\characters\Headgear\Data\UI\Aegis_H_Helmet_FASTMT_rgr_F_ca.paa";
        hiddenSelectionsTextures[] = {QPATHTOF(data\H_HelmetFASTMT_A3_Multicam_Woodland_CO.paa)};
    };
    class GVAR(H_Helmet_FASTMT_US_OCP_F): GVAR(H_Helmet_FASTMT_base_F) {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] FAST-MT Helmet (US OCP)";
        picture = "\z\jmfsb\addons\headware\models\characters\Headgear\Data\UI\Aegis_H_Helmet_FASTMT_tan_F_ca.paa";
        hiddenSelectionsTextures[] = {QPATHTOF(data\H_HelmetFASTMT_US_OCP_CO.paa)};
    };

    /* FAST-MT Helmet w/ Headset - our paints, Aegis's headset */
    class GVAR(H_Helmet_FASTMT_Headset_Multicam_F): GVAR(H_Helmet_FASTMT_Headset_base_F) {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        MACRO_ACE_HEARING
        displayName = "[JMSB] FAST-MT Helmet w/ Headset (Multicam)";
        picture = "\z\jmfsb\addons\headware\models\characters\Headgear\Data\UI\Aegis_H_Helmet_FASTMT_Headset_tan_F_ca.paa";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\H_HelmetFASTMT_Multicam_CO.paa),
            "\z\jmfsb\addons\headware\models\characters\Headgear\Data\H_HeadsetWest_tan_CO.paa"
        };
    };
    class GVAR(H_Helmet_FASTMT_Headset_Multicam_Snow_F): GVAR(H_Helmet_FASTMT_Headset_base_F) {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        MACRO_ACE_HEARING
        displayName = "[JMSB] FAST-MT Helmet w/ Headset (Multicam Alpine)";
        picture = "\z\jmfsb\addons\headware\models\characters\Headgear\Data\UI\Aegis_H_Helmet_FASTMT_Headset_tan_F_ca.paa";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\H_HelmetFASTMT_Multicam_Snow_CO.paa),
            "\z\jmfsb\addons\headware\models\characters\Headgear\Data\H_HeadsetWest_tan_CO.paa"
        };
    };
    class GVAR(H_Helmet_FASTMT_Headset_A3_Multicam_Woodland_F): GVAR(H_Helmet_FASTMT_Headset_base_F) {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        MACRO_ACE_HEARING
        displayName = "[JMSB] FAST-MT Helmet w/ Headset (Multicam Woodland)";
        picture = "\z\jmfsb\addons\headware\models\characters\Headgear\Data\UI\Aegis_H_Helmet_FASTMT_Headset_rgr_F_ca.paa";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\H_HelmetFASTMT_A3_Multicam_Woodland_CO.paa),
            "\z\jmfsb\addons\headware\models\characters\Headgear\Data\H_HeadsetWest_oli_CO.paa"
        };
    };
    class GVAR(H_Helmet_FASTMT_Headset_US_OCP_F): GVAR(H_Helmet_FASTMT_Headset_base_F) {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        MACRO_ACE_HEARING
        displayName = "[JMSB] FAST-MT Helmet w/ Headset (US OCP)";
        picture = "\z\jmfsb\addons\headware\models\characters\Headgear\Data\UI\Aegis_H_Helmet_FASTMT_Headset_tan_F_ca.paa";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\H_HelmetFASTMT_US_OCP_CO.paa),
            "\z\jmfsb\addons\headware\models\characters\Headgear\Data\H_HeadsetWest_tan_CO.paa"
        };
    };

    /* FAST-MT Helmet w/ Cover - our cover paints on Aegis's helmet and headset */
    class GVAR(H_Helmet_FASTMT_Cover_mtp_F): GVAR(H_Helmet_FASTMT_Cover_base_F) {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        MACRO_ACE_HEARING
        displayName = "[JMSB] FAST-MT Helmet w/ Cover (MTP)";
        picture = "\z\jmfsb\addons\headware\models\characters\Headgear\Data\UI\Aegis_H_Helmet_FASTMT_Cover_mtp_F_ca.paa";
        hiddenSelectionsTextures[] = {
            "\z\jmfsb\addons\headware\models\characters\Headgear\Data\H_HelmetFASTMT_tan_CO.paa",
            QPATHTOF(data\H_jmfsb_HelmetFASTMT_Cover_mtp_CO.paa),
            "\z\jmfsb\addons\headware\models\characters\Headgear\Data\H_HeadsetWest_tan_CO.paa"
        };
    };
    class GVAR(H_Helmet_FASTMT_Cover_tna_F): GVAR(H_Helmet_FASTMT_Cover_base_F) {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        MACRO_ACE_HEARING
        displayName = "[JMSB] FAST-MT Helmet w/ Cover (Tropic)";
        picture = "\z\jmfsb\addons\headware\models\characters\Headgear\Data\UI\Aegis_H_Helmet_FASTMT_Cover_tna_F_ca.paa";
        hiddenSelectionsTextures[] = {
            "\z\jmfsb\addons\headware\models\characters\Headgear\Data\H_HelmetFASTMT_rgr_CO.paa",
            QPATHTOF(data\H_jmfsb_HelmetFASTMT_Cover_tna_CO.paa),
            "\z\jmfsb\addons\headware\models\characters\Headgear\Data\H_HeadsetWest_oli_CO.paa"
        };
    };
    class GVAR(H_Helmet_FASTMT_Cover_wdl_F): GVAR(H_Helmet_FASTMT_Cover_base_F) {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        MACRO_ACE_HEARING
        displayName = "[JMSB] FAST-MT Helmet w/ Cover (Woodland)";
        picture = "\z\jmfsb\addons\headware\models\characters\Headgear\Data\UI\Aegis_H_Helmet_FASTMT_Cover_wdl_F_ca.paa";
        hiddenSelectionsTextures[] = {
            "\z\jmfsb\addons\headware\models\characters\Headgear\Data\H_HelmetFASTMT_rgr_CO.paa",
            QPATHTOF(data\H_jmfsb_HelmetFASTMT_Cover_wdl_CO.paa),
            "\z\jmfsb\addons\headware\models\characters\Headgear\Data\H_HeadsetWest_oli_CO.paa"
        };
    };
    class GVAR(H_Helmet_FASTMT_Cover_desert_F): GVAR(H_Helmet_FASTMT_Cover_base_F) {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        MACRO_ACE_HEARING
        displayName = "[JMSB] FAST-MT Helmet w/ Cover (Desert)";
        picture = "\z\jmfsb\addons\headware\models\characters\Headgear\Data\UI\Aegis_H_Helmet_FASTMT_Cover_Desert_F_ca.paa";
        hiddenSelectionsTextures[] = {
            "\z\jmfsb\addons\headware\models\characters\Headgear\Data\H_HelmetFASTMT_tan_CO.paa",
            QPATHTOF(data\H_jmfsb_HelmetFASTMT_Cover_desert_CO.paa),
            "\z\jmfsb\addons\headware\models\characters\Headgear\Data\H_HeadsetWest_tan_CO.paa"
        };
    };
    class GVAR(H_Helmet_FASTMT_Cover_Multicam_F): GVAR(H_Helmet_FASTMT_Cover_base_F) {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        MACRO_ACE_HEARING
        displayName = "[JMSB] FAST-MT Helmet w/ Cover (Multicam)";
        picture = "\z\jmfsb\addons\headware\models\characters\Headgear\Data\UI\Aegis_H_Helmet_FASTMT_Cover_tan_F_ca.paa";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\H_HelmetFASTMT_Multicam_CO.paa),
            QPATHTOF(data\H_HelmetFASTMT_Cover_Multicam_CO.paa),
            "\z\jmfsb\addons\headware\models\characters\Headgear\Data\H_HeadsetWest_tan_CO.paa"
        };
    };
    class GVAR(H_Helmet_FASTMT_Cover_Multicam_Snow_F): GVAR(H_Helmet_FASTMT_Cover_base_F) {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        MACRO_ACE_HEARING
        displayName = "[JMSB] FAST-MT Helmet w/ Cover (Multicam Alpine)";
        picture = "\z\jmfsb\addons\headware\models\characters\Headgear\Data\UI\Aegis_H_Helmet_FASTMT_Cover_tan_F_ca.paa";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\H_HelmetFASTMT_Multicam_Snow_CO.paa),
            QPATHTOF(data\H_HelmetFASTMT_Cover_Multicam_Snow_CO.paa),
            "\z\jmfsb\addons\headware\models\characters\Headgear\Data\H_HeadsetWest_tan_CO.paa"
        };
    };
    class GVAR(H_Helmet_FASTMT_Cover_A3_Multicam_Woodland_F): GVAR(H_Helmet_FASTMT_Cover_base_F) {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        MACRO_ACE_HEARING
        displayName = "[JMSB] FAST-MT Helmet w/ Cover (Multicam Woodland)";
        picture = "\z\jmfsb\addons\headware\models\characters\Headgear\Data\UI\Aegis_H_Helmet_FASTMT_Cover_rgr_F_ca.paa";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\H_HelmetFASTMT_A3_Multicam_Woodland_CO.paa),
            QPATHTOF(data\H_HelmetFASTMT_Cover_A3_Multicam_Woodland_CO.paa),
            "\z\jmfsb\addons\headware\models\characters\Headgear\Data\H_HeadsetWest_oli_CO.paa"
        };
    };
    class GVAR(H_Helmet_FASTMT_Cover_US_OCP_F): GVAR(H_Helmet_FASTMT_Cover_base_F) {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        MACRO_ACE_HEARING
        displayName = "[JMSB] FAST-MT Helmet w/ Cover (US OCP)";
        picture = "\z\jmfsb\addons\headware\models\characters\Headgear\Data\UI\Aegis_H_Helmet_FASTMT_Cover_tan_F_ca.paa";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\H_HelmetFASTMT_US_OCP_CO.paa),
            QPATHTOF(data\H_HelmetFASTMT_Cover_US_OCP_CO.paa),
            "\z\jmfsb\addons\headware\models\characters\Headgear\Data\H_HeadsetWest_tan_CO.paa"
        };
    };
    class GVAR(H_Helmet_FASTMT_Cover_jmfsb_US_OCP_F): GVAR(H_Helmet_FASTMT_Cover_base_F) {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        MACRO_ACE_HEARING
        displayName = "[JMSB] FAST-MT Helmet w/ Cover (JMSB US OCP)";
        picture = "\z\jmfsb\addons\headware\models\characters\Headgear\Data\UI\Aegis_H_Helmet_FASTMT_Cover_tan_F_ca.paa";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\H_HelmetFASTMT_US_OCP_CO.paa),
            QPATHTOF(data\H_HelmetFASTMT_Cover_US_OCP_CO.paa),
            "\z\jmfsb\addons\headware\models\characters\Headgear\Data\H_HeadsetWest_tan_CO.paa"
        };
    };

    /* JMSB Boonie Hats */
    class GVAR(H_Booniehat_Multicam_F): H_Booniehat_khk {
        author = QAUTHOR;
        displayName = "[JMSB] (Multicam) Booniehat";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\booniehat_multicam_co.paa)
        };
        hiddenSelectionsMaterials[] = {QPATHTOF(data\booniehat.rvmat)};
        heatReduction = 1;
        picture = QPATHTOF(data\ui\icon_h_booniehat_multicam_ca.paa);
        MACRO_ITEM_COMMON
    };
    class GVAR(H_Booniehat_Multicam_hs_F): H_Booniehat_khk_hs {
        author = QAUTHOR;
        displayName = "[JMSB] (Multicam) Booniehat (Headset)";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\booniehat_multicam_co.paa)
        };
        hiddenSelectionsMaterials[] = {QPATHTOF(data\booniehat.rvmat)};
        heatReduction = 1;
        picture = QPATHTOF(data\ui\icon_h_booniehat_multicam_hs_ca.paa);
        MACRO_ITEM_COMMON
        MACRO_ACE_HEARING
    };
    class GVAR(H_Booniehat_ocp_F): H_Booniehat_khk {
        author = QAUTHOR;
        displayName = "[JMSB] (OCP) Booniehat";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\booniehat_ocp_co.paa)
        };
        hiddenSelectionsMaterials[] = {QPATHTOF(data\booniehat.rvmat)};
        heatReduction = 1;
        picture = QPATHTOF(data\ui\icon_h_booniehat_ocp_ca.paa);
        MACRO_ITEM_COMMON
    };
    class GVAR(H_Booniehat_ocp_hs_F): H_Booniehat_khk_hs {
        author = QAUTHOR;
        displayName = "[JMSB] (OCP) Booniehat (Headset)";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\booniehat_ocp_co.paa)
        };
        hiddenSelectionsMaterials[] = {QPATHTOF(data\booniehat.rvmat)};
        heatReduction = 1;
        picture = QPATHTOF(data\ui\icon_h_booniehat_ocp_hs_ca.paa);
        MACRO_ITEM_COMMON
        MACRO_ACE_HEARING
    };
    class GVAR(H_Booniehat_Multicam_Snow_F): H_Booniehat_khk {
        author = QAUTHOR;
        displayName = "[JMSB] (Multicam Snow) Booniehat";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\booniehat_multicam_snow_co.paa)
        };
        hiddenSelectionsMaterials[] = {QPATHTOF(data\booniehat.rvmat)};
        heatReduction = 1;
        picture = QPATHTOF(data\ui\icon_h_booniehat_multicam_snow_ca.paa);
        MACRO_ITEM_COMMON
    };
    class GVAR(H_Booniehat_Multicam_Snow_hs_F): H_Booniehat_khk_hs {
        author = QAUTHOR;
        displayName = "[JMSB] (Multicam Snow) Booniehat (Headset)";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\booniehat_multicam_snow_co.paa)
        };
        hiddenSelectionsMaterials[] = {QPATHTOF(data\booniehat.rvmat)};
        heatReduction = 1;
        picture = QPATHTOF(data\ui\icon_h_booniehat_multicam_snow_hs_ca.paa);
        MACRO_ITEM_COMMON
        MACRO_ACE_HEARING
    };
    class GVAR(H_Booniehat_Multicam_Woodland_F): H_Booniehat_khk {
        author = QAUTHOR;
        displayName = "[JMSB] (Multicam Woodland) Booniehat";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\booniehat_multicam_woodland_co.paa)
        };
        hiddenSelectionsMaterials[] = {QPATHTOF(data\booniehat.rvmat)};
        heatReduction = 1;
        picture = QPATHTOF(data\ui\icon_h_booniehat_multicam_woodland_ca.paa);
        MACRO_ITEM_COMMON
    };
    class GVAR(H_Booniehat_Multicam_Woodland_hs_F): H_Booniehat_khk_hs {
        author = QAUTHOR;
        displayName = "[JMSB] (Multicam Woodland) Booniehat (Headset)";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\booniehat_multicam_woodland_co.paa)
        };
        hiddenSelectionsMaterials[] = {QPATHTOF(data\booniehat.rvmat)};
        heatReduction = 1;
        picture = QPATHTOF(data\ui\icon_h_booniehat_multicam_woodland_hs_ca.paa);
        MACRO_ITEM_COMMON
        MACRO_ACE_HEARING
    };
    class GVAR(H_Booniehat_Solid_CoyoteBrown_F): H_Booniehat_khk {
        author = QAUTHOR;
        displayName = "[JMSB] (Coyote) Booniehat";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\booniehat_solid_coyotebrown_co.paa)
        };
        hiddenSelectionsMaterials[] = {QPATHTOF(data\booniehat.rvmat)};
        heatReduction = 1;
        picture = QPATHTOF(data\ui\icon_h_booniehat_solid_coyotebrown_ca.paa);
        MACRO_ITEM_COMMON
    };
    class GVAR(H_Booniehat_Solid_CoyoteBrown_hs_F): H_Booniehat_khk_hs {
        author = QAUTHOR;
        displayName = "[JMSB] (Coyote) Booniehat (Headset)";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\booniehat_solid_coyotebrown_co.paa)
        };
        hiddenSelectionsMaterials[] = {QPATHTOF(data\booniehat.rvmat)};
        heatReduction = 1;
        picture = QPATHTOF(data\ui\icon_h_booniehat_solid_coyotebrown_hs_ca.paa);
        MACRO_ITEM_COMMON
        MACRO_ACE_HEARING
    };
    class GVAR(H_Booniehat_Solid_Ranger_Green_F): H_Booniehat_khk {
        author = QAUTHOR;
        displayName = "[JMSB] (Ranger Green) Booniehat";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\booniehat_solid_ranger_green_co.paa)
        };
        hiddenSelectionsMaterials[] = {QPATHTOF(data\booniehat.rvmat)};
        heatReduction = 1;
        picture = QPATHTOF(data\ui\icon_h_booniehat_solid_ranger_green_ca.paa);
        MACRO_ITEM_COMMON
    };
    class GVAR(H_Booniehat_Solid_Ranger_Green_hs_F): H_Booniehat_khk_hs {
        author = QAUTHOR;
        displayName = "[JMSB] (Ranger Green) Booniehat (Headset)";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\booniehat_solid_ranger_green_co.paa)
        };
        hiddenSelectionsMaterials[] = {QPATHTOF(data\booniehat.rvmat)};
        heatReduction = 1;
        picture = QPATHTOF(data\ui\icon_h_booniehat_solid_ranger_green_hs_ca.paa);
        MACRO_ITEM_COMMON
        MACRO_ACE_HEARING
    };
    class GVAR(H_Booniehat_Solid_Olive_F): H_Booniehat_khk {
        author = QAUTHOR;
        displayName = "[JMSB] (Olive) Booniehat";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\booniehat_solid_olive_co.paa)
        };
        hiddenSelectionsMaterials[] = {QPATHTOF(data\booniehat.rvmat)};
        heatReduction = 1;
        picture = QPATHTOF(data\ui\icon_h_booniehat_solid_olive_ca.paa);
        MACRO_ITEM_COMMON
    };
    class GVAR(H_Booniehat_Solid_Olive_hs_F): H_Booniehat_khk_hs {
        author = QAUTHOR;
        displayName = "[JMSB] (Olive) Booniehat (Headset)";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\booniehat_solid_olive_co.paa)
        };
        hiddenSelectionsMaterials[] = {QPATHTOF(data\booniehat.rvmat)};
        heatReduction = 1;
        picture = QPATHTOF(data\ui\icon_h_booniehat_solid_olive_hs_ca.paa);
        MACRO_ITEM_COMMON
        MACRO_ACE_HEARING
    };
    class GVAR(H_Booniehat_Solid_Tan_F): H_Booniehat_khk {
        author = QAUTHOR;
        displayName = "[JMSB] (Tan) Booniehat";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\booniehat_solid_tan_co.paa)
        };
        hiddenSelectionsMaterials[] = {QPATHTOF(data\booniehat.rvmat)};
        heatReduction = 1;
        picture = QPATHTOF(data\ui\icon_h_booniehat_solid_tan_ca.paa);
        MACRO_ITEM_COMMON
    };
    class GVAR(H_Booniehat_Solid_Tan_hs_F): H_Booniehat_khk_hs {
        author = QAUTHOR;
        displayName = "[JMSB] (Tan) Booniehat (Headset)";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\booniehat_solid_tan_co.paa)
        };
        hiddenSelectionsMaterials[] = {QPATHTOF(data\booniehat.rvmat)};
        heatReduction = 1;
        picture = QPATHTOF(data\ui\icon_h_booniehat_solid_tan_hs_ca.paa);
        MACRO_ITEM_COMMON
        MACRO_ACE_HEARING
    };
    class GVAR(H_Booniehat_Solid_White_F): H_Booniehat_khk {
        author = QAUTHOR;
        displayName = "[JMSB] (White) Booniehat";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\booniehat_solid_white_co.paa)
        };
        hiddenSelectionsMaterials[] = {QPATHTOF(data\booniehat.rvmat)};
        heatReduction = 1;
        picture = QPATHTOF(data\ui\icon_h_booniehat_solid_white_ca.paa);
        MACRO_ITEM_COMMON
    };
    class GVAR(H_Booniehat_Solid_White_hs_F): H_Booniehat_khk_hs {
        author = QAUTHOR;
        displayName = "[JMSB] (White) Booniehat (Headset)";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\booniehat_solid_white_co.paa)
        };
        hiddenSelectionsMaterials[] = {QPATHTOF(data\booniehat.rvmat)};
        heatReduction = 1;
        picture = QPATHTOF(data\ui\icon_h_booniehat_solid_white_hs_ca.paa);
        MACRO_ITEM_COMMON
        MACRO_ACE_HEARING
    };
#include "acp_full.hpp"
};
