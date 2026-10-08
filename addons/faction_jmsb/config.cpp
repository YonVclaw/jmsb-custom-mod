#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {QGVAR(ocp_ReconScout)};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        // jmfsb_uniform_sof CARRIES THE FATIGUES, jmfsb_headware the boonie,
        // jmfsb_vests_mig the Ferro Bison carrier and sps_hk_vp9_pistols the VP9
        // the scout spawns with - all real requirements rather than soft ones,
        // and the two outside ones are what makes this faction drop with MIG or
        // SPS rather than spawn a man with no vest and no pistol. The CTRG base
        // class this inherits from is the base game's and is forward-declared
        // instead; see CfgVehicles.hpp.
        requiredAddons[] = {"jmfsb_main", "jmfsb_uniform_sof", "jmfsb_headware", "jmfsb_vests_mig", "sps_hk_vp9_pistols"};
        skipWhenMissingDependencies = 1;
        author = QAUTHOR;
        VERSION_CONFIG;
    };
};

#include "CfgFactionClasses.hpp"
#include "CfgVehicles.hpp"
#include "CfgGroups.hpp"
