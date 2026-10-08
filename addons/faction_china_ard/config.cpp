#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(ACE_O_T_SpottingScope), QGVAR(Aegis_O_C_D_Crew_F), QGVAR(Aegis_O_C_D_Engineer_F), QGVAR(Aegis_O_C_D_Fighter_Pilot_F), QGVAR(Aegis_O_C_D_HeavyGunner_F), QGVAR(Aegis_O_C_D_Helicrew_F), QGVAR(Aegis_O_C_D_Helipilot_F), QGVAR(Aegis_O_C_D_Medic_F), QGVAR(Aegis_O_C_D_Officer_F), QGVAR(Aegis_O_C_D_Pathfinder_F), QGVAR(Aegis_O_C_D_Pilot_F), QGVAR(Aegis_O_C_D_RadioOperator_F), QGVAR(Aegis_O_C_D_Recon_AR_F), QGVAR(Aegis_O_C_D_Recon_CQ_F), QGVAR(Aegis_O_C_D_Recon_Exp_F), QGVAR(Aegis_O_C_D_Recon_F), QGVAR(Aegis_O_C_D_Recon_GL_F), QGVAR(Aegis_O_C_D_Recon_JTAC_F), QGVAR(Aegis_O_C_D_Recon_LAT_F), QGVAR(Aegis_O_C_D_Recon_M_F), QGVAR(Aegis_O_C_D_Recon_Medic_F), QGVAR(Aegis_O_C_D_Recon_TL_F), QGVAR(Aegis_O_C_D_Sharpshooter_F), QGVAR(Aegis_O_C_D_Sniper_F), QGVAR(Aegis_O_C_D_Soldier_AAA_F), QGVAR(Aegis_O_C_D_Soldier_AAR_F), QGVAR(Aegis_O_C_D_Soldier_AAT_F), QGVAR(Aegis_O_C_D_Soldier_AA_F), QGVAR(Aegis_O_C_D_Soldier_AHAT_F), QGVAR(Aegis_O_C_D_Soldier_AR_F), QGVAR(Aegis_O_C_D_Soldier_AT_F), QGVAR(Aegis_O_C_D_Soldier_A_F), QGVAR(Aegis_O_C_D_Soldier_CBRN_F), QGVAR(Aegis_O_C_D_Soldier_CQ_F), QGVAR(Aegis_O_C_D_Soldier_Exp_F), QGVAR(Aegis_O_C_D_Soldier_F), QGVAR(Aegis_O_C_D_Soldier_GL_F), QGVAR(Aegis_O_C_D_Soldier_HAT_F), QGVAR(Aegis_O_C_D_Soldier_LAT_F), QGVAR(Aegis_O_C_D_Soldier_Lite_F), QGVAR(Aegis_O_C_D_Soldier_M_F), QGVAR(Aegis_O_C_D_Soldier_PG_F), QGVAR(Aegis_O_C_D_Soldier_Repair_F), QGVAR(Aegis_O_C_D_Soldier_SL_F), QGVAR(Aegis_O_C_D_Soldier_TL_F), QGVAR(Aegis_O_C_D_Soldier_UAV_06_F), QGVAR(Aegis_O_C_D_Soldier_UAV_06_medical_F), QGVAR(Aegis_O_C_D_Soldier_UAV_F), QGVAR(Aegis_O_C_D_Soldier_UGV_02_Demining_F), QGVAR(Aegis_O_C_D_Soldier_unarmed_F), QGVAR(Aegis_O_C_D_Spotter_F), QGVAR(Aegis_O_C_D_Support_AMG_F), QGVAR(Aegis_O_C_D_Support_AMort_F), QGVAR(Aegis_O_C_D_Support_GMG_F), QGVAR(Aegis_O_C_D_Support_MG_F), QGVAR(Aegis_O_C_D_Support_Mort_F), QGVAR(Aegis_O_T_BoatCrew_EF), QGVAR(Land_Pod_Heli_Transport_04_ammo_F), QGVAR(Land_Pod_Heli_Transport_04_bench_F), QGVAR(Land_Pod_Heli_Transport_04_box_F), QGVAR(Land_Pod_Heli_Transport_04_covered_F), QGVAR(Land_Pod_Heli_Transport_04_fuel_F), QGVAR(Land_Pod_Heli_Transport_04_medevac_F), QGVAR(Land_Pod_Heli_Transport_04_repair_F), QGVAR(O_APC_Tracked_02_AA_F), QGVAR(O_APC_Tracked_02_cannon_F), QGVAR(O_Boat_Armed_01_hmg_F), QGVAR(O_Boat_Transport_01_F), QGVAR(O_GMG_01_A_F), QGVAR(O_GMG_01_F), QGVAR(O_GMG_01_high_F), QGVAR(O_HMG_01_A_F), QGVAR(O_HMG_01_F), QGVAR(O_HMG_01_high_F), QGVAR(O_Heli_Attack_02_F), QGVAR(O_Heli_Attack_02_dynamicLoadout_F), QGVAR(O_Heli_Light_02_dynamicLoadout_F), QGVAR(O_Heli_Light_02_unarmed_F), QGVAR(O_Heli_Transport_04_F), QGVAR(O_Heli_Transport_04_ammo_F), QGVAR(O_Heli_Transport_04_bench_F), QGVAR(O_Heli_Transport_04_box_F), QGVAR(O_Heli_Transport_04_covered_F), QGVAR(O_Heli_Transport_04_fuel_F), QGVAR(O_Heli_Transport_04_medevac_F), QGVAR(O_Heli_Transport_04_repair_F), QGVAR(O_LSV_02_AT_F), QGVAR(O_LSV_02_armed_F), QGVAR(O_LSV_02_unarmed_F), QGVAR(O_Lifeboat), QGVAR(O_MBT_02_arty_F), QGVAR(O_MBT_02_cannon_F), QGVAR(O_MBT_02_railgun_F), QGVAR(O_MBT_04_cannon_F), QGVAR(O_MBT_04_command_F), QGVAR(O_MRAP_02_F), QGVAR(O_MRAP_02_gmg_F), QGVAR(O_MRAP_02_hmg_F), QGVAR(O_Mortar_01_F), QGVAR(O_Plane_CAS_02_dynamicLoadout_F), QGVAR(O_Plane_Fighter_02_F), QGVAR(O_Plane_Fighter_02_Stealth_F), QGVAR(O_Quadbike_01_F), QGVAR(O_Quadbike_ALIVE), QGVAR(O_Radar_System_02_F), QGVAR(O_SAM_System_04_F), QGVAR(O_SDV_01_F), QGVAR(O_Static_Designator_02_F), QGVAR(O_T_Diver_Exp_F), QGVAR(O_T_Diver_F), QGVAR(O_T_Diver_TL_F), QGVAR(O_T_Soldier_UAV_02_lxWS_F), QGVAR(O_T_Survivor_F), QGVAR(O_T_UAV_04_CAS_F), QGVAR(O_T_VTOL_02_infantry_ghex_F), QGVAR(O_T_ghillie_spotter_tna_F), QGVAR(O_T_ghillie_tna_F), QGVAR(O_T_soldier_mine_F), QGVAR(O_Truck_03_ammo_F), QGVAR(O_Truck_03_covered_F), QGVAR(O_Truck_03_device_F), QGVAR(O_Truck_03_fuel_F), QGVAR(O_Truck_03_medical_F), QGVAR(O_Truck_03_repair_F), QGVAR(O_Truck_03_transport_F), QGVAR(O_UAV_01_F), QGVAR(O_UAV_06_F), QGVAR(O_UAV_06_medical_F), QGVAR(O_UGV_01_F), QGVAR(O_UGV_01_rcws_F), QGVAR(O_UGV_02_Demining_F), QGVAR(O_VTOL_02_infantry_dynamicLoadout_F), QGVAR(O_VTOL_02_vehicle_dynamicLoadout_F), QGVAR(O_static_AA_F), QGVAR(O_static_AT_F), QGVAR(jmfsb_antiship_launcher), QGVAR(jmfsb_antiship_radar), QGVAR(qav_o_t_625e), QGVAR(qav_o_t_ztl11), QGVAR(O_UAV_01_backpack_F), QGVAR(O_UAV_06_backpack_F), QGVAR(O_UAV_03_dynamicLoadout_F), QGVAR(O_SwitchBlade_300), QGVAR(O_SwitchBlade_600), QGVAR(O_SwitchBlade_300_LaunchTube), QGVAR(O_SwitchBlade_600_LaunchTube), QGVAR(SwitchBlade_Operator), QGVAR(Drone_Operator)
        };
        weapons[] = {
            QGVAR(Aegis_arifle_CTARS_tan_ARCO_Pointer_F_snds), QGVAR(Aegis_arifle_CTAR_GL_tan_ARCO_Pointer_F_snds), QGVAR(Aegis_arifle_CTAR_tan_ARCO_Pointer_F_snds), QGVAR(LMG_03_Arco_Pointer_F_snds), QGVAR(SMG_02_ACO_F_snds), QGVAR(hgun_Rook40_F_snds), QGVAR(srifle_DMR_05_KHS_LP_F_snds), QGVAR(srifle_DMR_07_blk_DMS_F_snds)
        };
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
        requiredAddons[] = {"jmfsb_main", "jmfsb_uniform", "jmfsb_vests", "jmfsb_weapons", "jmfsb_vehicle"};
        skipWhenMissingDependencies = 1;
        author = QAUTHOR;
        VERSION_CONFIG;
    };
};

#include "CfgFactionClasses.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
#include "CfgGroups.hpp"
