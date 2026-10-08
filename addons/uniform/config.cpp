#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(B_D_Helicrew_F), QGVAR(O_C_D_Crew_F), QGVAR(O_C_D_Engineer_F), QGVAR(O_C_D_Fighter_Pilot_F), QGVAR(O_C_D_HeavyGunner_F), QGVAR(O_C_D_Helicrew_F), QGVAR(O_C_D_Helipilot_F), QGVAR(O_C_D_Medic_F), QGVAR(O_C_D_Officer_F), QGVAR(O_C_D_Pathfinder_F), QGVAR(O_C_D_Pilot_F), QGVAR(O_C_D_RadioOperator_F), QGVAR(O_C_D_Recon_AR_F), QGVAR(O_C_D_Recon_CQ_F), QGVAR(O_C_D_Recon_Exp_F), QGVAR(O_C_D_Recon_F), QGVAR(O_C_D_Recon_GL_F), QGVAR(O_C_D_Recon_JTAC_F), QGVAR(O_C_D_Recon_LAT_F), QGVAR(O_C_D_Recon_M_F), QGVAR(O_C_D_Recon_Medic_F), QGVAR(O_C_D_Recon_TL_F), QGVAR(O_C_D_Sharpshooter_F), QGVAR(O_C_D_Sniper_F), QGVAR(O_C_D_Soldier_AAA_F), QGVAR(O_C_D_Soldier_AAR_F), QGVAR(O_C_D_Soldier_AAT_F), QGVAR(O_C_D_Soldier_AA_F), QGVAR(O_C_D_Soldier_AHAT_F), QGVAR(O_C_D_Soldier_AR_F), QGVAR(O_C_D_Soldier_AT_F), QGVAR(O_C_D_Soldier_A_F), QGVAR(O_C_D_Soldier_CBRN_F), QGVAR(O_C_D_Soldier_CQ_F), QGVAR(O_C_D_Soldier_Exp_F), QGVAR(O_C_D_Soldier_F), QGVAR(O_C_D_Soldier_GL_F), QGVAR(O_C_D_Soldier_HAT_F), QGVAR(O_C_D_Soldier_LAT_F), QGVAR(O_C_D_Soldier_Lite_F), QGVAR(O_C_D_Soldier_M_F), QGVAR(O_C_D_Soldier_PG_F), QGVAR(O_C_D_Soldier_Repair_F), QGVAR(O_C_D_Soldier_SL_F), QGVAR(O_C_D_Soldier_TL_F), QGVAR(O_C_D_Soldier_UAV_06_F), QGVAR(O_C_D_Soldier_UAV_06_medical_F), QGVAR(O_C_D_Soldier_UAV_F), QGVAR(O_C_D_Soldier_UGV_02_Demining_F), QGVAR(O_C_D_Soldier_unarmed_F), QGVAR(O_C_D_Spotter_F), QGVAR(O_C_D_Support_AMG_F), QGVAR(O_C_D_Support_AMort_F), QGVAR(O_C_D_Support_GMG_F), QGVAR(O_C_D_Support_MG_F), QGVAR(O_C_D_Support_Mort_F), QGVAR(B_D_JSOC_JTAC_F), QGVAR(B_D_JSOC_LAT_F), QGVAR(B_D_JSOC_StealthUniform_F), QGVAR(B_D_JSOC_StealthUniform_RolledUp_F), QGVAR(B_D_JSOC_UAV_F), QGVAR(B_D_JSOC_UAV_lxWS), QGVAR(B_H_Crew_F), QGVAR(B_H_Engineer_F), QGVAR(B_H_HeavyGunner_F), QGVAR(B_H_Helicrew_F), QGVAR(B_H_Helipilot_F), QGVAR(B_H_Medic_F), QGVAR(B_H_Officer_F), QGVAR(B_H_RadioOperator_F), QGVAR(B_H_Soldier_AR_F), QGVAR(B_H_Soldier_A_F), QGVAR(B_H_Soldier_Exp_F), QGVAR(B_H_Soldier_F), QGVAR(B_H_Soldier_GL_F), QGVAR(B_H_Soldier_LAT_F), QGVAR(B_H_Soldier_SL_F), QGVAR(B_H_Soldier_TL_F), QGVAR(B_H_Soldier_commando_AR_F), QGVAR(B_H_Soldier_commando_F), QGVAR(B_H_Soldier_commando_LAT_F), QGVAR(B_H_Soldier_commando_M_F), QGVAR(B_H_Soldier_commando_TL_F), QGVAR(B_H_Soldier_commando_exp_F), QGVAR(B_H_Soldier_commando_gl_F), QGVAR(B_H_Soldier_commando_jtac_F), QGVAR(B_H_Soldier_commando_medic_F), QGVAR(B_H_Soldier_unarmed_F), QGVAR(B_H_soldier_M_F), QGVAR(B_JSOC_JTAC_F), QGVAR(B_JSOC_LAT_F), QGVAR(B_JSOC_StealthUniform_F), QGVAR(B_JSOC_StealthUniform_RolledUp_F), QGVAR(B_JSOC_UAV_F), QGVAR(B_JSOC_UAV_lxWS), QGVAR(B_T_JSOC_JTAC_F), QGVAR(B_T_JSOC_LAT_F), QGVAR(B_T_JSOC_StealthUniform_F), QGVAR(B_T_JSOC_StealthUniform_RolledUp_F), QGVAR(B_A_Fighter_Pilot_F), QGVAR(B_D_Pilot_lxWS), QGVAR(B_RadioOperator_F), QGVAR(B_Soldier_CBRN_F), QGVAR(B_Soldier_CQ_F), QGVAR(B_Soldier_MG_F), QGVAR(B_ghillie_spotter_ard_F), QGVAR(B_ghillie_spotter_lsh_F), QGVAR(B_ghillie_spotter_sard_F), QGVAR(B_recon_AR_F), QGVAR(B_recon_CQ_F), QGVAR(B_recon_GL_F), QGVAR(B_recon_MG_F), QGVAR(O_R_diver_F), QGVAR(O_R_diver_TL_F), QGVAR(O_R_diver_TL_ard_F), QGVAR(O_R_diver_ard_F), QGVAR(O_R_diver_exp_F), QGVAR(O_R_diver_exp_ard_F), QGVAR(O_RadioOperator_F), QGVAR(O_Soldier_CBRN_F), QGVAR(O_Soldier_CQ_F), QGVAR(O_T_Fighter_Pilot_F), QGVAR(O_T_HeavyGunner_F), QGVAR(O_T_Pathfinder_F), QGVAR(O_T_RadioOperator_F), QGVAR(O_T_Recon_AR_F), QGVAR(O_T_Recon_CQ_F), QGVAR(O_T_Recon_GL_F), QGVAR(O_T_Sharpshooter_F), QGVAR(O_T_Soldier_CBRN_F), QGVAR(O_T_Soldier_CQ_F), QGVAR(O_T_Soldier_Lite_F), QGVAR(O_T_Soldier_UAV_02_lxWS_F), QGVAR(O_T_Survivor_F), QGVAR(O_T_ghillie_spotter_tna_F), QGVAR(O_T_soldier_UGV_02_Demining_F), QGVAR(O_ghillie_spotter_ard_F), QGVAR(O_ghillie_spotter_lsh_F), QGVAR(O_ghillie_spotter_sard_F), QGVAR(O_recon_AR_F), QGVAR(O_recon_CQ_F), QGVAR(O_recon_GL_F), QGVAR(O_soldier_UGV_02_Demining_F), QGVAR(B_carryall_oicamo_Eng_F), QGVAR(B_FieldPack_oicamo_Medic_F), QGVAR(B_RadioBag_01_oicamo_F), QGVAR(B_carryall_oicamo_Exp_F), QGVAR(B_FieldPack_oicamo_LAT_F), QGVAR(B_Carryall_oicamo_OCDAAA_F), QGVAR(B_Carryall_oicamo_OCDAAR_F), QGVAR(B_Carryall_oicamo_OCDAAT_F), QGVAR(B_FieldPack_oicamo_AA_F), QGVAR(B_Carryall_oicamo_OCDAHAT_F), QGVAR(B_FieldPack_oicamo_AT_F), QGVAR(B_Carryall_oicamo_OCDAmmo_F), QGVAR(B_FieldPack_oicamo_HAT_F), QGVAR(B_FieldPack_oicamo_RepSpec_F), QGVAR(B_D_Soldier_JSOC_base), QGVAR(B_Soldier_JSOC_base), QGVAR(B_H_Soldier_Base_F), QGVAR(B_H_Man_Base_F), QGVAR(B_Carryall_jungle_BHEng_F), QGVAR(B_TacticalPack_oli_BHHG_F), QGVAR(B_TacticalPack_oli_BHMedic_F), QGVAR(B_RadioBag_01_jungle_F), QGVAR(B_Carryall_jungle_BHAmmo_F), QGVAR(B_Carryall_jungle_BHExp_F), QGVAR(B_TacticalPack_oli_BHLAT_F), QGVAR(B_H_Soldier_Commando_Base), QGVAR(B_TacticalPack_rgr_BALAT_F), QGVAR(B_RadioBag_01_commando_F), QGVAR(B_TacticalPack_rgr_BAReconMedic_F), QGVAR(B_AssaultPack_JSOC_LAT_F), QGVAR(B_T_Soldier_JSOC_base), QGVAR(B_T_AssaultPack_JSOC_LAT_F), QGVAR(B_A_Pilot_F), QGVAR(B_RadioBag_01_coyote_F), QGVAR(O_R_Soldier_diver_base), QGVAR(O_Fatigues_01_oicamo_F), QGVAR(B_carryall_oicamo), QGVAR(B_FieldPack_oicamo), QGVAR(O_OfficerFatigues_01_oicamo_F), QGVAR(O_C_D_Sniper_oicamo_F), QGVAR(B_AssaultPackSpec_Base), QGVAR(UniformBDU_02_HI_F), QGVAR(UniformBDU_01_HI_F), QGVAR(B_Carryall_jungle), QGVAR(B_H_OfficerFatigues_01_jungle_F), QGVAR(B_H_CombatFatigues_01_Commando_F), QGVAR(B_AssaultPackSpec_mcamo), QGVAR(B_AssaultPack_Enh_tna_F), QGVAR(UniformBDU_02_oli_F), QGVAR(UniformBDU_01_oli_F), QGVAR(O_R_Wetsuit_01_F), QGVAR(B_JSOC_StealthUniform_soldier_F), QGVAR(B_D_JSOC_StealthUniform_soldier_F), QGVAR(B_T_JSOC_StealthUniform_soldier_F), QGVAR(B_W_JSOC_StealthUniform_soldier_F), QGVAR(B_OCP_JSOC_StealthUniform_soldier_F), QGVAR(B_Snow_JSOC_StealthUniform_soldier_F), QGVAR(B_JSOC_StealthUniform_RolledUp_soldier_F), QGVAR(B_D_JSOC_StealthUniform_RolledUp_soldier_F), QGVAR(B_T_JSOC_StealthUniform_RolledUp_soldier_F), QGVAR(B_W_JSOC_StealthUniform_RolledUp_soldier_F), QGVAR(B_OCP_JSOC_StealthUniform_RolledUp_soldier_F), QGVAR(B_Snow_JSOC_StealthUniform_RolledUp_soldier_F), QGVAR(Item_U_B_JSOC_StealthUniform_F), QGVAR(Item_U_B_JSOC_StealthUniform_RolledUp_F), QGVAR(Item_U_B_D_JSOC_StealthUniform_F), QGVAR(Item_U_B_D_JSOC_StealthUniform_RolledUp_F), QGVAR(Item_U_B_T_JSOC_StealthUniform_F), QGVAR(Item_U_B_T_JSOC_StealthUniform_RolledUp_F), QGVAR(Item_U_B_W_JSOC_StealthUniform_F), QGVAR(Item_U_B_W_JSOC_StealthUniform_RolledUp_F), QGVAR(Item_U_B_OCP_JSOC_StealthUniform_F), QGVAR(Item_U_B_OCP_JSOC_StealthUniform_RolledUp_F), QGVAR(Item_U_B_Snow_JSOC_StealthUniform_F), QGVAR(Item_U_B_Snow_JSOC_StealthUniform_RolledUp_F), QGVAR(B_CombatUniform_ocp_soldier_F), QGVAR(B_CombatUniform_snow_soldier_F)
        };
        weapons[] = {
            // --- imported weapons: generated by tools/aegis_port, do not edit between the markers
            QGVAR(U_O_CombatUniform_oicamo),
            QGVAR(U_O_OfficerUniform_oicamo),
            QGVAR(U_O_C_D_Sniper_oicamo_F),
            QGVAR(U_UniformBDU_02_HI_F),
            QGVAR(U_UniformBDU_01_HI_F),
            QGVAR(U_B_H_Officer_F),
            QGVAR(U_B_H_Soldier_commando_F),
            QGVAR(U_O_T_Pilot_F),
            QGVAR(O_NVGoggles_blk_F),
            QGVAR(U_O_R_Wetsuit),
            QGVAR(U_UniformBDU_02_oli_F),
            QGVAR(U_UniformBDU_01_oli_F),
            // --- end imported weapons
            QGVAR(U_B_JSOC_StealthUniform_F),
            QGVAR(U_B_JSOC_StealthUniform_RolledUp_F),
            QGVAR(U_B_D_JSOC_StealthUniform_F),
            QGVAR(U_B_D_JSOC_StealthUniform_RolledUp_F),
            QGVAR(U_B_T_JSOC_StealthUniform_F),
            QGVAR(U_B_T_JSOC_StealthUniform_RolledUp_F),
            QGVAR(U_B_W_JSOC_StealthUniform_F),
            QGVAR(U_B_W_JSOC_StealthUniform_RolledUp_F),
            QGVAR(U_B_OCP_JSOC_StealthUniform_F),
            QGVAR(U_B_OCP_JSOC_StealthUniform_RolledUp_F),
            QGVAR(U_B_Snow_JSOC_StealthUniform_F),
            QGVAR(U_B_Snow_JSOC_StealthUniform_RolledUp_F),
            QGVAR(U_B_CombatUniform_ocp_F),
            QGVAR(U_B_CombatUniform_snow_F)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"jmfsb_weapons",
            "A3_Data_F_Decade_Loadorder",
            "jmfsb_main"};
        author = QAUTHOR;
        authors[] = {""};
        VERSION_CONFIG;
    };
};

class CfgEditorSubcategories {
    class EdSubcat_Uniforms {
        displayName = "Uniforms";
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
#include "XtdGear.hpp"
// #include "Xtdsmilgp.hpp"
#include "imported_config.hpp"
