#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(B_Captain_Dwarden_F), QGVAR(B_GEN_Boat_Transport_02_F), QGVAR(B_GEN_Commander_F), QGVAR(B_GEN_Offroad_01_comms_F), QGVAR(B_GEN_Offroad_01_covered_F), QGVAR(B_GEN_Offroad_01_gen_F), QGVAR(B_GEN_Quadbike_01_F), QGVAR(B_GEN_Soldier_F), QGVAR(B_GEN_Soldier_Rifle_F), QGVAR(B_GEN_Soldier_SG_F), QGVAR(B_GEN_Van_02_transport_F), QGVAR(B_GEN_Van_02_vehicle_F)
        };
        weapons[] = {};
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
        requiredAddons[] = {"jmfsb_main", "jmfsb_headware", "jmfsb_weapons"};
        skipWhenMissingDependencies = 1;
        author = QAUTHOR;
        VERSION_CONFIG;
    };
};

#include "CfgFactionClasses.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
#include "CfgGroups.hpp"
