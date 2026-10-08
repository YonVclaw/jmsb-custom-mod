#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(B_Heli_Attack_03_F), QGVAR(B_M_Heli_Attack_03_F), QGVAR(VVE_VTOL_03_unarmed_QAV), QGVAR(Aegis_B_D_LSV_01_AT_F), QGVAR(Aegis_B_D_LSV_01_armed_F), QGVAR(Aegis_B_D_LSV_01_light_F), QGVAR(Aegis_B_D_LSV_01_unarmed_F), QGVAR(Aegis_B_MJTF_D_APC_Wheeled_01_atgm_v2), QGVAR(Aegis_B_MJTF_D_APC_Wheeled_01_cannon_v2_F), QGVAR(Aegis_B_MJTF_D_APC_Wheeled_01_command_lxWS), QGVAR(Aegis_B_MJTF_D_APC_Wheeled_01_medical_F), QGVAR(Aegis_B_MJTF_D_APC_Wheeled_01_mortar_lxWS), QGVAR(B_Pilot_F), QGVAR(B_Plane_CAS_01_Cluster_F), QGVAR(B_Plane_CAS_01_dynamicLoadout_F), QGVAR(B_Plane_Fighter_01_Cluster_F), QGVAR(B_Plane_Fighter_01_F), QGVAR(B_Plane_Fighter_01_Stealth_F), QGVAR(B_qav_abramsx), QGVAR(C_IDAP_UAV_06_antimine_backpack_F), QGVAR(C_IDAP_UAV_06_antimine_F), QGVAR(B_Heli_Transport_01_medevac_F)
        };
        weapons[] = {
            QGVAR(SMG_01_black_Holo_F_snds)
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
        requiredAddons[] = {"jmfsb_main", "jmfsb_vehicle"};
        skipWhenMissingDependencies = 1;
        author = QAUTHOR;
        VERSION_CONFIG;
    };
};

#include "CfgFactionClasses.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
#include "CfgGroups.hpp"
