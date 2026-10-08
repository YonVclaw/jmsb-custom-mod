#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(Item_SOF_V_AVSCarrier_Lite_rgr),
            QGVAR(Item_SOF_V_AVSCarrier_Lite_rgr_noflag),
            QGVAR(Item_SOF_V_AVSCarrier_Lite_mcam),
            QGVAR(Item_SOF_V_AVSCarrier_Lite_tna),
            QGVAR(Item_SOF_V_AVSCarrier_Lite_wdl),
            QGVAR(Item_SOF_V_AVSCarrier_Lite_ocp),
            QGVAR(Item_SOF_V_AVSCarrier_Lite_new_rgr),
            QGVAR(Item_SOF_V_AVSCarrier_Lite_new_mcam),
            QGVAR(Item_SOF_V_AVSCarrier_Lite_new_ocp),
            QGVAR(Item_SOF_V_AVSCarrier_Lite_new_tna),
            QGVAR(Item_SOF_V_AVSCarrier_Lite_new_wdl),
            QGVAR(Item_SOF_V_AVSCarrier_Lite_new_blk),
            QGVAR(Item_SOF_V_AVSCarrier_Lite_new_cbr),
            QGVAR(Item_SOF_V_AVSCarrier_Lite_new_snd),
            QGVAR(Item_SOF_V_AVSCarrier_Rifle_new_rgr),
            QGVAR(Item_SOF_V_AVSCarrier_Rifle_new_mcam),
            QGVAR(Item_SOF_V_AVSCarrier_Rifle_new_ocp),
            QGVAR(Item_SOF_V_AVSCarrier_Rifle_new_tna),
            QGVAR(Item_SOF_V_AVSCarrier_Rifle_new_wdl),
            QGVAR(Item_SOF_V_AVSCarrier_Rifle_new_blk),
            QGVAR(Item_SOF_V_AVSCarrier_Rifle_new_cbr),
            QGVAR(Item_SOF_V_AVSCarrier_Rifle_new_snd),
            QGVAR(Item_SOF_V_AVSCarrier_Rifle_new_rgr_noflag),
            QGVAR(Item_SOF_V_AVSCarrier_Rifle_new_mcam_noflag),
            QGVAR(Item_SOF_V_AVSCarrier_Rifle_new_ocp_noflag),
            QGVAR(Item_SOF_V_AVSCarrier_Gunner_new_rgr),
            QGVAR(Item_SOF_V_AVSCarrier_Gunner_new_mcam),
            QGVAR(Item_SOF_V_AVSCarrier_Gunner_new_ocp),
            QGVAR(Item_SOF_V_AVSCarrier_Gunner_new_tna),
            QGVAR(Item_SOF_V_AVSCarrier_Gunner_new_wdl),
            QGVAR(Item_SOF_V_AVSCarrier_Gunner_new_blk),
            QGVAR(Item_SOF_V_AVSCarrier_Gunner_new_cbr),
            QGVAR(Item_SOF_V_AVSCarrier_Gunner_new_snd),
            QGVAR(Item_SOF_V_AVSCarrier_Gunner_new_rgr_noflag),
            QGVAR(Item_SOF_V_AVSCarrier_Gunner_new_mcam_noflag),
            QGVAR(Item_SOF_V_AVSCarrier_Gunner_new_ocp_noflag),
            QGVAR(Item_SOF_V_CHPCCarrier_Lite_khk),
            QGVAR(Item_SOF_V_CHPCCarrier_Lite_blk),
            QGVAR(Item_SOF_V_CHPCCarrier_Lite_oli),
            QGVAR(Item_SOF_V_CHPCCarrier_Lite_hex),
            QGVAR(Item_SOF_V_CHPCCarrier_Lite_ghex),
            QGVAR(Item_SOF_V_CHPCCarrier_SMG_khk),
            QGVAR(Item_SOF_V_CHPCCarrier_SMG_blk),
            QGVAR(Item_SOF_V_CHPCCarrier_SMG_oli),
            QGVAR(Item_SOF_V_CHPCCarrier_SMG_hex),
            QGVAR(Item_SOF_V_CHPCCarrier_SMG_ghex),
            QGVAR(Item_SOF_V_CHPCCarrier_Rig_khk),
            QGVAR(Item_SOF_V_CHPCCarrier_Rig_blk),
            QGVAR(Item_SOF_V_CHPCCarrier_Rig_oli),
            QGVAR(Item_SOF_V_CHPCCarrier_Rig_hex),
            QGVAR(Item_SOF_V_CHPCCarrier_Rig_ghex),
            QGVAR(Item_SOF_V_CHPCCarrier_Gunner_khk),
            QGVAR(Item_SOF_V_CHPCCarrier_Gunner_blk),
            QGVAR(Item_SOF_V_CHPCCarrier_Gunner_oli),
            QGVAR(Item_SOF_V_CHPCCarrier_Gunner_hex),
            QGVAR(Item_SOF_V_CHPCCarrier_Gunner_ghex)
        };
        weapons[] = {
            QGVAR(SOF_V_AVSCarrier_Lite_rgr),
            QGVAR(SOF_V_AVSCarrier_Lite_rgr_noflag),
            QGVAR(SOF_V_AVSCarrier_Lite_mcam),
            QGVAR(SOF_V_AVSCarrier_Lite_tna),
            QGVAR(SOF_V_AVSCarrier_Lite_wdl),
            QGVAR(SOF_V_AVSCarrier_Lite_ocp),
            QGVAR(SOF_V_AVSCarrier_Lite_new_rgr),
            QGVAR(SOF_V_AVSCarrier_Lite_new_mcam),
            QGVAR(SOF_V_AVSCarrier_Lite_new_ocp),
            QGVAR(SOF_V_AVSCarrier_Lite_new_tna),
            QGVAR(SOF_V_AVSCarrier_Lite_new_wdl),
            QGVAR(SOF_V_AVSCarrier_Lite_new_blk),
            QGVAR(SOF_V_AVSCarrier_Lite_new_cbr),
            QGVAR(SOF_V_AVSCarrier_Lite_new_snd),
            QGVAR(SOF_V_AVSCarrier_Rifle_new_rgr),
            QGVAR(SOF_V_AVSCarrier_Rifle_new_mcam),
            QGVAR(SOF_V_AVSCarrier_Rifle_new_ocp),
            QGVAR(SOF_V_AVSCarrier_Rifle_new_tna),
            QGVAR(SOF_V_AVSCarrier_Rifle_new_wdl),
            QGVAR(SOF_V_AVSCarrier_Rifle_new_blk),
            QGVAR(SOF_V_AVSCarrier_Rifle_new_cbr),
            QGVAR(SOF_V_AVSCarrier_Rifle_new_snd),
            QGVAR(SOF_V_AVSCarrier_Rifle_new_rgr_noflag),
            QGVAR(SOF_V_AVSCarrier_Rifle_new_mcam_noflag),
            QGVAR(SOF_V_AVSCarrier_Rifle_new_ocp_noflag),
            QGVAR(SOF_V_AVSCarrier_Gunner_new_rgr),
            QGVAR(SOF_V_AVSCarrier_Gunner_new_mcam),
            QGVAR(SOF_V_AVSCarrier_Gunner_new_ocp),
            QGVAR(SOF_V_AVSCarrier_Gunner_new_tna),
            QGVAR(SOF_V_AVSCarrier_Gunner_new_wdl),
            QGVAR(SOF_V_AVSCarrier_Gunner_new_blk),
            QGVAR(SOF_V_AVSCarrier_Gunner_new_cbr),
            QGVAR(SOF_V_AVSCarrier_Gunner_new_snd),
            QGVAR(SOF_V_AVSCarrier_Gunner_new_rgr_noflag),
            QGVAR(SOF_V_AVSCarrier_Gunner_new_mcam_noflag),
            QGVAR(SOF_V_AVSCarrier_Gunner_new_ocp_noflag),
            QGVAR(SOF_V_CHPCCarrier_Lite_khk),
            QGVAR(SOF_V_CHPCCarrier_Lite_blk),
            QGVAR(SOF_V_CHPCCarrier_Lite_oli),
            QGVAR(SOF_V_CHPCCarrier_Lite_hex),
            QGVAR(SOF_V_CHPCCarrier_Lite_ghex),
            QGVAR(SOF_V_CHPCCarrier_SMG_khk),
            QGVAR(SOF_V_CHPCCarrier_SMG_blk),
            QGVAR(SOF_V_CHPCCarrier_SMG_oli),
            QGVAR(SOF_V_CHPCCarrier_SMG_hex),
            QGVAR(SOF_V_CHPCCarrier_SMG_ghex),
            QGVAR(SOF_V_CHPCCarrier_Rig_khk),
            QGVAR(SOF_V_CHPCCarrier_Rig_blk),
            QGVAR(SOF_V_CHPCCarrier_Rig_oli),
            QGVAR(SOF_V_CHPCCarrier_Rig_hex),
            QGVAR(SOF_V_CHPCCarrier_Rig_ghex),
            QGVAR(SOF_V_CHPCCarrier_Gunner_khk),
            QGVAR(SOF_V_CHPCCarrier_Gunner_blk),
            QGVAR(SOF_V_CHPCCarrier_Gunner_oli),
            QGVAR(SOF_V_CHPCCarrier_Gunner_hex),
            QGVAR(SOF_V_CHPCCarrier_Gunner_ghex)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "jmfsb_main",
            "SOF_Characters",
            "A3_Characters_F"
        };
        skipWhenMissingDependencies = 1;
        authorUrl = "https://github.com/Joint-Multi-Functional-Strike-Battalion/";
        author = QAUTHOR;
        authors[] = {"OokamiJamie"};
        VERSION_CONFIG;
    };
};

class CfgEditorSubcategories {
    class EdSubcat_SOF_Vests {
        displayName = "[JMSB] SOF - Vests";
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
#include "XtdGear.hpp"
