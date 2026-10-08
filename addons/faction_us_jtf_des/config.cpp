#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(B_Heli_Attack_03_F), QGVAR(B_M_Heli_Attack_03_F), QGVAR(VVE_VTOL_03_unarmed_QAV), QGVAR(APC_Wheeled_01_apc_qav), QGVAR(APC_Wheeled_01_mgs_QAV), QGVAR(APC_Wheeled_01_mgs_up_QAV), QGVAR(APC_Wheeled_01_shorad_QAV), QGVAR(Aegis_B_D_CommandoMortar_RF), QGVAR(Aegis_B_D_GMG_01_A_F), QGVAR(Aegis_B_D_GMG_01_F), QGVAR(Aegis_B_D_GMG_01_high_F), QGVAR(Aegis_B_D_HMG_01_A_F), QGVAR(Aegis_B_D_HMG_01_F), QGVAR(Aegis_B_D_HMG_01_high_F), QGVAR(Aegis_B_D_HeavyGunner_F), QGVAR(Aegis_B_D_Helicrew_F), QGVAR(Aegis_B_D_LSV_01_AT_F), QGVAR(Aegis_B_D_LSV_01_armed_F), QGVAR(Aegis_B_D_LSV_01_light_F), QGVAR(Aegis_B_D_LSV_01_unarmed_F), QGVAR(Aegis_B_D_RadioOperator_F), QGVAR(Aegis_B_D_Recon_CQ_F), QGVAR(Aegis_B_D_Recon_GL_F), QGVAR(Aegis_B_D_Recon_MG_F), QGVAR(Aegis_B_D_Recon_Sharpshooter), QGVAR(Aegis_B_D_Sharpshooter_F), QGVAR(Aegis_B_D_Soldier_CQ_F), QGVAR(Aegis_B_D_Soldier_MG_F), QGVAR(Aegis_B_D_Static_Designator_01_F), QGVAR(Aegis_B_D_UAV_01_F), QGVAR(Aegis_B_D_UAV_02_lxWS), QGVAR(Aegis_B_D_UAV_05_F), QGVAR(Aegis_B_D_UGV_02_Demining_F), QGVAR(Aegis_B_D_soldier_UGV_02_Demining_F), QGVAR(Aegis_B_MJTF_D_APC_Wheeled_01_medical_F), QGVAR(Atlas_B_D_JSOC_F), QGVAR(Atlas_B_D_JSOC_JTAC_F), QGVAR(Atlas_B_D_JSOC_LAT_F), QGVAR(Atlas_B_D_JSOC_UAV_F), QGVAR(Atlas_B_D_JSOC_UAV_lxWS), QGVAR(B_AAA_System_01_F), QGVAR(B_D_APC_Wheeled_01_atgm_lxWS_v2), QGVAR(B_D_APC_Wheeled_01_cannon_lxWS_v2), QGVAR(B_D_Fighter_Pilot_F), QGVAR(B_D_MBT_01_arty_lxWS), QGVAR(B_D_MBT_01_mlrs_lxWS), QGVAR(B_D_Pilot_lxWS), QGVAR(B_D_VTOL_03_unarmed_QAV), QGVAR(B_D_recon_AR_lxWS), QGVAR(B_Heli_Light_01_F), QGVAR(B_Heli_Light_01_dynamicLoadout_F), QGVAR(B_Heli_Light_01_stripped_F), QGVAR(B_Heli_Transport_01_F), QGVAR(B_Heli_Transport_01_pylons_F), QGVAR(B_Heli_Transport_01_unarmed_F), QGVAR(B_Heli_Transport_03_F), QGVAR(B_Heli_Transport_03_unarmed_F), QGVAR(B_Plane_CAS_01_Cluster_F), QGVAR(B_Plane_CAS_01_dynamicLoadout_F), QGVAR(B_Plane_Fighter_01_Cluster_F), QGVAR(B_Plane_Fighter_01_F), QGVAR(B_Plane_Fighter_01_Stealth_F), QGVAR(B_Radar_System_01_F), QGVAR(B_SAM_System_03_F), QGVAR(B_SDV_01_F), QGVAR(B_T_APC_Wheeled_01_cannon_F), QGVAR(B_T_Boat_Armed_01_minigun_F), QGVAR(B_T_Boat_Transport_01_F), QGVAR(B_T_Diver_Exp_F), QGVAR(B_T_Diver_F), QGVAR(B_T_Diver_TL_F), QGVAR(B_T_Sniper_F), QGVAR(B_T_Spotter_F), QGVAR(B_T_Support_AMG_F), QGVAR(B_T_Support_GMG_F), QGVAR(B_T_Support_MG_F), QGVAR(B_T_Support_Mort_F), QGVAR(B_qav_abramsx), QGVAR(B_qav_abramsx_templar), QGVAR(B_qav_abramsx_tusk), QGVAR(GX_B_HONEYBADGER_UGV_AT_BLACK), QGVAR(GX_B_HONEYBADGER_UGV_AT_DESERT), QGVAR(GX_B_HONEYBADGER_UGV_AT_GREEN), QGVAR(GX_B_HONEYBADGER_UGV_AT_HEX), QGVAR(GX_B_HUNTER_SP_LAUNCHER), QGVAR(GX_B_HUNTER_SP_UAV), QGVAR(GX_B_MAGURA_V5_USV), QGVAR(GX_B_MQ8B_UAV_ARMED), QGVAR(GX_B_MQ8B_UAV_RECON), QGVAR(GX_B_MQ8B_UAV_RECON_SEATED), QGVAR(GX_B_RWS_DEFNDER_MEDIUM), QGVAR(GX_B_THEMIS_UGV_CARGO), QGVAR(GX_B_THEMIS_UGV_DEFNDER_MEDIUM), QGVAR(GX_B_THEMIS_UGV_HUNTER_LAUNCHER), QGVAR(qav_b_ripsaw_Mk44), QGVAR(qav_ripsaw_c), QGVAR(C_IDAP_UAV_06_antimine_backpack_F), QGVAR(C_IDAP_UAV_06_antimine_F), QGVAR(B_Heli_Transport_01_medevac_F)
        };
        weapons[] = {QGVAR(LMG_Mk200_plain_RCO_LP_F_snds),QGVAR(MMG_02_sand_RCO_LP_F_snds),QGVAR(SMG_01_Holo_F_snds),QGVAR(SMG_01_black_Holo_F_snds),QGVAR(arifle_MXC_ACO_pointer_F_snds),QGVAR(arifle_MXC_F_snds),QGVAR(arifle_MXC_Holo_F_snds),QGVAR(arifle_MXC_Holo_pointer_F_snds),QGVAR(arifle_MXC_khk_ACO_Pointer_F_snds),QGVAR(arifle_MXM_MOS_LP_BI_F_snds),QGVAR(arifle_MX_ACO_pointer_F_snds),QGVAR(arifle_MX_GL_ACO_pointer_F_snds),QGVAR(arifle_MX_GL_Hamr_pointer_F_snds),QGVAR(arifle_MX_Hamr_pointer_F_snds),QGVAR(arifle_MX_Holo_pointer_F_snds),QGVAR(arifle_MX_SW_Hamr_pointer_F_snds),QGVAR(srifle_DMR_03_tan_AMS_LP_F_snds),QGVAR(srifle_LRR_tna_LRPS_F_snds)};
        requiredVersion = REQUIRED_VERSION;
        // jmfsb_fa_tiers IS NOT REQUIRED, DELIBERATELY. The tier
        // magazines are named as STRINGS in magazines[]; nothing here
        // inherits from them, so there is no load order to enforce.
        // Requiring it was fatal: fa_tiers requires fa_rhs, fa_sps,
        // fa_e22raf and fa_jca, which require RHS, SPS, E22 and JCA -
        // and with skipWhenMissingDependencies any one of those absent
        // dropped this whole faction out of 3DEN and Zeus in silence.
        //
        // NOTHING FROM THE SOURCE FACTION'S MOD IS REQUIRED EITHER.
        // Every parent class is forward-declared in CfgVehicles.hpp, so a
        // load order without that mod gets inert classes instead of a
        // broken config. skipWhenMissingDependencies does the rest.
        requiredAddons[] = {"jmfsb_main", "jmfsb_headware", "jmfsb_uniform", "jmfsb_vests", "jmfsb_weapons", "jmfsb_vehicle"};
        skipWhenMissingDependencies = 1;
        author = QAUTHOR;
        VERSION_CONFIG;
    };
};

#include "CfgFactionClasses.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
#include "CfgGroups.hpp"
