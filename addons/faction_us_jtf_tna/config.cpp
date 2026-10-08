#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(B_Heli_Attack_03_F), QGVAR(B_M_Heli_Attack_03_F), QGVAR(VVE_VTOL_03_unarmed_QAV), QGVAR(ACE_B_T_SpottingScope), QGVAR(Aegis_B_T_CommandoMortar_RF), QGVAR(Aegis_B_T_UAV_02_lxWS), QGVAR(Atlas_B_T_JSOC_F), QGVAR(Atlas_B_T_JSOC_JTAC_F), QGVAR(Atlas_B_T_JSOC_LAT_F), QGVAR(Atlas_B_T_JSOC_UAV_F), QGVAR(Atlas_B_T_JSOC_UAV_lxWS), QGVAR(B_AAA_System_01_F), QGVAR(B_Heli_Light_01_F), QGVAR(B_Heli_Light_01_dynamicLoadout_F), QGVAR(B_Heli_Light_01_stripped_F), QGVAR(B_Heli_Transport_01_F), QGVAR(B_Heli_Transport_01_pylons_F), QGVAR(B_Heli_Transport_01_unarmed_F), QGVAR(B_Heli_Transport_03_F), QGVAR(B_Heli_Transport_03_unarmed_F), QGVAR(B_Plane_CAS_01_Cluster_F), QGVAR(B_Plane_CAS_01_dynamicLoadout_F), QGVAR(B_Plane_Fighter_01_Cluster_F), QGVAR(B_Plane_Fighter_01_F), QGVAR(B_Plane_Fighter_01_Stealth_F), QGVAR(B_Radar_System_01_F), QGVAR(B_SAM_System_03_F), QGVAR(B_T_APC_Wheeled_01_apc_QAV), QGVAR(B_T_APC_Wheeled_01_cannon_F), QGVAR(B_T_APC_Wheeled_01_medical_F), QGVAR(B_T_APC_Wheeled_01_mgs_QAV), QGVAR(B_T_APC_Wheeled_01_mgs_up_QAV), QGVAR(B_T_APC_Wheeled_01_shorad_QAV), QGVAR(B_T_Boat_Armed_01_minigun_F), QGVAR(B_T_Boat_Transport_01_F), QGVAR(B_T_Crew_F), QGVAR(B_T_Diver_Exp_F), QGVAR(B_T_Diver_F), QGVAR(B_T_Diver_TL_F), QGVAR(B_T_Engineer_F), QGVAR(B_T_Fighter_Pilot_F), QGVAR(B_T_GMG_01_A_F), QGVAR(B_T_GMG_01_F), QGVAR(B_T_GMG_01_high_F), QGVAR(B_T_HMG_01_A_F), QGVAR(B_T_HMG_01_F), QGVAR(B_T_HMG_01_high_F), QGVAR(B_T_HMG_02_F), QGVAR(B_T_HMG_02_high_F), QGVAR(B_T_HeavyGunner_F), QGVAR(B_T_Helicrew_F), QGVAR(B_T_Helipilot_F), QGVAR(B_T_LSV_01_AT_F), QGVAR(B_T_LSV_01_armed_F), QGVAR(B_T_LSV_01_light_F), QGVAR(B_T_LSV_01_unarmed_F), QGVAR(B_T_Lifeboat), QGVAR(B_T_MBT_01_arty_F), QGVAR(B_T_MBT_01_mlrs_F), QGVAR(B_T_MRAP_01_F), QGVAR(B_T_MRAP_01_gmg_F), QGVAR(B_T_MRAP_01_hmg_F), QGVAR(B_T_Medic_F), QGVAR(B_T_Mortar_01_F), QGVAR(B_T_Officer_F), QGVAR(B_T_Pilot_F), QGVAR(B_T_Quadbike_01_F), QGVAR(B_T_RadioOperator_F), QGVAR(B_T_Recon_AR_F), QGVAR(B_T_Recon_CQ_F), QGVAR(B_T_Recon_Exp_F), QGVAR(B_T_Recon_F), QGVAR(B_T_Recon_GL_F), QGVAR(B_T_Recon_JTAC_F), QGVAR(B_T_Recon_LAT_F), QGVAR(B_T_Recon_MG_F), QGVAR(B_T_Recon_M_F), QGVAR(B_T_Recon_Medic_F), QGVAR(B_T_Recon_Sharpshooter_F), QGVAR(B_T_Recon_TL_F), QGVAR(B_T_SDV_01_F), QGVAR(B_T_Sharpshooter_F), QGVAR(B_T_Sniper_F), QGVAR(B_T_Soldier_AAA_F), QGVAR(B_T_Soldier_AAR_F), QGVAR(B_T_Soldier_AAT_F), QGVAR(B_T_Soldier_AA_F), QGVAR(B_T_Soldier_AR_F), QGVAR(B_T_Soldier_AT_F), QGVAR(B_T_Soldier_A_F), QGVAR(B_T_Soldier_CBRN_F), QGVAR(B_T_Soldier_CQ_F), QGVAR(B_T_Soldier_Exp_F), QGVAR(B_T_Soldier_F), QGVAR(B_T_Soldier_GL_F), QGVAR(B_T_Soldier_LAT2_F), QGVAR(B_T_Soldier_LAT_F), QGVAR(B_T_Soldier_Lite_F), QGVAR(B_T_Soldier_MG_F), QGVAR(B_T_Soldier_PG_F), QGVAR(B_T_Soldier_Repair_F), QGVAR(B_T_Soldier_SL_F), QGVAR(B_T_Soldier_TL_F), QGVAR(B_T_Soldier_UAV_F), QGVAR(B_T_Soldier_unarmed_F), QGVAR(B_T_Spotter_F), QGVAR(B_T_Static_AA_F), QGVAR(B_T_Static_AT_F), QGVAR(B_T_Static_Designator_01_F), QGVAR(B_T_Support_AMG_F), QGVAR(B_T_Support_AMort_F), QGVAR(B_T_Support_GMG_F), QGVAR(B_T_Support_MG_F), QGVAR(B_T_Support_Mort_F), QGVAR(B_T_Survivor_F), QGVAR(B_T_Truck_01_Repair_F), QGVAR(B_T_Truck_01_ammo_F), QGVAR(B_T_Truck_01_box_F), QGVAR(B_T_Truck_01_cargo_F), QGVAR(B_T_Truck_01_covered_F), QGVAR(B_T_Truck_01_flatbed_F), QGVAR(B_T_Truck_01_fuel_F), QGVAR(B_T_Truck_01_medical_F), QGVAR(B_T_Truck_01_mover_F), QGVAR(B_T_Truck_01_transport_F), QGVAR(B_T_UAV_01_F), QGVAR(B_T_UAV_05_F), QGVAR(B_T_UGV_02_Demining_F), QGVAR(B_T_VTOL_03_unarmed_QAV), QGVAR(B_T_ghillie_spotter_tna_F), QGVAR(B_T_ghillie_tna_F), QGVAR(B_T_qav_abramsx), QGVAR(B_T_soldier_M_F), QGVAR(B_T_soldier_UAV_02_LxWS_F), QGVAR(B_T_soldier_UGV_02_Demining_F), QGVAR(B_T_soldier_mine_F), QGVAR(B_qav_abramsx_templar), QGVAR(B_qav_abramsx_tusk), QGVAR(GX_B_HONEYBADGER_UGV_AT_GREEN), QGVAR(GX_B_HUNTER_SP_LAUNCHER), QGVAR(GX_B_HUNTER_SP_UAV), QGVAR(GX_B_MAGURA_V5_USV), QGVAR(GX_B_MQ8B_UAV_ARMED), QGVAR(GX_B_MQ8B_UAV_RECON), QGVAR(GX_B_MQ8B_UAV_RECON_SEATED), QGVAR(GX_B_RWS_DEFNDER_MEDIUM), QGVAR(GX_B_THEMIS_UGV_CARGO), QGVAR(GX_B_THEMIS_UGV_DEFNDER_MEDIUM), QGVAR(GX_B_THEMIS_UGV_HUNTER_LAUNCHER), QGVAR(qav_b_ripsaw_Mk44), QGVAR(qav_ripsaw_c), QGVAR(C_IDAP_UAV_06_antimine_backpack_F), QGVAR(C_IDAP_UAV_06_antimine_F), QGVAR(B_Heli_Transport_01_medevac_F), QGVAR(Drone_Operator)
        };
        weapons[] = {QGVAR(LMG_Mk200_khk_Hamr_Pointer_Bipod_F_snds),QGVAR(MMG_02_khaki_RCO_LP_F_snds),QGVAR(SMG_01_khk_Holo_F_snds),QGVAR(arifle_MXC_khk_ACO_Pointer_F_snds),QGVAR(arifle_MXC_khk_F_snds),QGVAR(arifle_MXC_khk_Holo_F_snds),QGVAR(arifle_MXC_khk_Holo_Flash_F_snds),QGVAR(arifle_MXC_khk_Holo_Pointer_F_snds),QGVAR(arifle_MXM_khk_MOS_Pointer_Bipod_F_snds),QGVAR(arifle_MX_GL_khk_ACO_Pointer_F_snds),QGVAR(arifle_MX_GL_khk_Hamr_Pointer_F_snds),QGVAR(arifle_MX_SW_khk_Hamr_Pointer_F_snds),QGVAR(arifle_MX_khk_ACO_Pointer_F_snds),QGVAR(arifle_MX_khk_Hamr_Pointer_F_snds),QGVAR(arifle_MX_khk_Holo_Pointer_F_snds),QGVAR(srifle_DMR_03_khaki_AMS_LP_BI_F_snds),QGVAR(srifle_LRR_tna_LRPS_F_snds)};
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
        requiredAddons[] = {"jmfsb_main", "jmfsb_vehicle", "jmfsb_uniform", "jmfsb_weapons"};
        skipWhenMissingDependencies = 1;
        author = QAUTHOR;
        VERSION_CONFIG;
    };
};

#include "CfgFactionClasses.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
#include "CfgGroups.hpp"
