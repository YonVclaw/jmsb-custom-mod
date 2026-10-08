#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(ACE_O_SpottingScope), QGVAR(Aegis_O_BoatCrew_EF), QGVAR(Land_Pod_Heli_Transport_04_ammo_F), QGVAR(Land_Pod_Heli_Transport_04_bench_F), QGVAR(Land_Pod_Heli_Transport_04_box_F), QGVAR(Land_Pod_Heli_Transport_04_covered_F), QGVAR(Land_Pod_Heli_Transport_04_fuel_F), QGVAR(Land_Pod_Heli_Transport_04_medevac_F), QGVAR(Land_Pod_Heli_Transport_04_repair_F), QGVAR(O_AAA_System_01_F), QGVAR(O_APC_Tracked_02_AA_F), QGVAR(O_APC_Tracked_02_cannon_F), QGVAR(O_Boat_Armed_01_hmg_F), QGVAR(O_Boat_Transport_01_F), QGVAR(O_Fighter_Pilot_F), QGVAR(O_GMG_01_A_F), QGVAR(O_GMG_01_F), QGVAR(O_GMG_01_high_F), QGVAR(O_HMG_01_A_F), QGVAR(O_HMG_01_F), QGVAR(O_HMG_01_high_F), QGVAR(O_HMG_02_F), QGVAR(O_HMG_02_high_F), QGVAR(O_HeavyGunner_F), QGVAR(O_Heli_Attack_02_F), QGVAR(O_Heli_Attack_02_dynamicLoadout_F), QGVAR(O_Heli_Light_02_dynamicLoadout_F), QGVAR(O_Heli_Light_02_unarmed_F), QGVAR(O_Heli_Transport_04_F), QGVAR(O_Heli_Transport_04_ammo_F), QGVAR(O_Heli_Transport_04_bench_F), QGVAR(O_Heli_Transport_04_box_F), QGVAR(O_Heli_Transport_04_covered_F), QGVAR(O_Heli_Transport_04_fuel_F), QGVAR(O_Heli_Transport_04_medevac_F), QGVAR(O_Heli_Transport_04_repair_F), QGVAR(O_LSV_02_AT_F), QGVAR(O_LSV_02_armed_F), QGVAR(O_LSV_02_unarmed_F), QGVAR(O_Lifeboat), QGVAR(O_MBT_02_arty_F), QGVAR(O_MBT_02_cannon_F), QGVAR(O_MBT_02_railgun_F), QGVAR(O_MBT_04_cannon_F), QGVAR(O_MBT_04_command_F), QGVAR(O_MRAP_02_F), QGVAR(O_MRAP_02_gmg_F), QGVAR(O_MRAP_02_hmg_F), QGVAR(O_Mortar_01_F), QGVAR(O_Officer_Parade_F), QGVAR(O_Officer_Parade_Veteran_F), QGVAR(O_Pathfinder_F), QGVAR(O_Pilot_F), QGVAR(O_Plane_CAS_02_dynamicLoadout_F), QGVAR(O_Plane_Fighter_02_F), QGVAR(O_Plane_Fighter_02_Stealth_F), QGVAR(O_Quadbike_01_F), QGVAR(O_Quadbike_ALIVE), QGVAR(O_Radar_System_02_F), QGVAR(O_RadioOperator_F), QGVAR(O_SAM_System_01_F), QGVAR(O_SAM_System_02_F), QGVAR(O_SAM_System_04_F), QGVAR(O_SDV_01_F), QGVAR(O_Sharpshooter_F), QGVAR(O_Soldier_AAA_F), QGVAR(O_Soldier_AAR_F), QGVAR(O_Soldier_AAT_F), QGVAR(O_Soldier_AA_F), QGVAR(O_Soldier_AHAT_F), QGVAR(O_Soldier_AR_F), QGVAR(O_Soldier_AT_F), QGVAR(O_Soldier_A_F), QGVAR(O_Soldier_CBRN_F), QGVAR(O_Soldier_CQ_F), QGVAR(O_Soldier_GL_F), QGVAR(O_Soldier_HAT_F), QGVAR(O_Soldier_LAT_F), QGVAR(O_Soldier_SL_F), QGVAR(O_Soldier_TL_F), QGVAR(O_Soldier_lite_F), QGVAR(O_Soldier_unarmed_F), QGVAR(O_Static_Designator_02_F), QGVAR(O_Survivor_F), QGVAR(O_Truck_03_ammo_F), QGVAR(O_Truck_03_covered_F), QGVAR(O_Truck_03_device_F), QGVAR(O_Truck_03_fuel_F), QGVAR(O_Truck_03_medical_F), QGVAR(O_Truck_03_repair_F), QGVAR(O_Truck_03_transport_F), QGVAR(O_UAV_01_F), QGVAR(O_UAV_02_dynamicLoadout_F), QGVAR(O_UAV_06_F), QGVAR(O_UAV_06_medical_F), QGVAR(O_UGV_01_F), QGVAR(O_UGV_01_rcws_F), QGVAR(O_UGV_02_Demining_F), QGVAR(O_UGV_02_Science_F), QGVAR(O_VTOL_02_infantry_dynamicLoadout_F), QGVAR(O_VTOL_02_vehicle_dynamicLoadout_F), QGVAR(O_crew_F), QGVAR(O_diver_F), QGVAR(O_diver_TL_F), QGVAR(O_diver_exp_F), QGVAR(O_engineer_F), QGVAR(O_ghillie_ard_F), QGVAR(O_ghillie_lsh_F), QGVAR(O_ghillie_sard_F), QGVAR(O_ghillie_spotter_ard_F), QGVAR(O_ghillie_spotter_lsh_F), QGVAR(O_ghillie_spotter_sard_F), QGVAR(O_helicrew_F), QGVAR(O_helipilot_F), QGVAR(O_medic_F), QGVAR(O_officer_F), QGVAR(O_recon_AR_F), QGVAR(O_recon_CQ_F), QGVAR(O_recon_F), QGVAR(O_recon_GL_F), QGVAR(O_recon_JTAC_F), QGVAR(O_recon_LAT_F), QGVAR(O_recon_M_F), QGVAR(O_recon_TL_F), QGVAR(O_recon_exp_F), QGVAR(O_recon_medic_F), QGVAR(O_sniper_F), QGVAR(O_soldier_F), QGVAR(O_soldier_M_F), QGVAR(O_soldier_PG_F), QGVAR(O_soldier_UAV_06_F), QGVAR(O_soldier_UAV_06_medical_F), QGVAR(O_soldier_UAV_F), QGVAR(O_soldier_UGV_02_Demining_F), QGVAR(O_soldier_exp_F), QGVAR(O_soldier_mine_F), QGVAR(O_soldier_repair_F), QGVAR(O_spotter_F), QGVAR(O_static_AA_F), QGVAR(O_static_AT_F), QGVAR(O_support_AMG_F), QGVAR(O_support_AMort_F), QGVAR(O_support_GMG_F), QGVAR(O_support_MG_F), QGVAR(O_support_Mort_F), QGVAR(jmfsb_antiship_launcher), QGVAR(jmfsb_antiship_radar), QGVAR(O_UAV_01_backpack_F), QGVAR(O_UAV_06_backpack_F), QGVAR(O_UAV_03_dynamicLoadout_F), QGVAR(O_SwitchBlade_300), QGVAR(O_SwitchBlade_600), QGVAR(O_SwitchBlade_300_LaunchTube), QGVAR(O_SwitchBlade_600_LaunchTube), QGVAR(SwitchBlade_Operator), QGVAR(Drone_Operator)
        };
        weapons[] = {
            QGVAR(arifle_AK12_arco), QGVAR(arifle_AK12_GL_arco_snds), QGVAR(SMG_02_ACO_F_snds), QGVAR(arifle_RPK12_arco_pointer_F_snds)
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
        requiredAddons[] = {"jmfsb_main", "jmfsb_vests", "jmfsb_weapons", "jmfsb_uniform", "jmfsb_vehicle"};
        skipWhenMissingDependencies = 1;
        author = QAUTHOR;
        VERSION_CONFIG;
    };
};

#include "CfgFactionClasses.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
#include "CfgGroups.hpp"
