#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(mtp_ReconScout),
            QGVAR(ocp_ReconScout),
            QGVAR(tna_ReconScout),
            QGVAR(wdl_ReconScout)
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        // jmfsb_uniform_sof CARRIES THE FATIGUES the scout wears, and it is
        // ours - so it is a real requirement rather than a soft one. The CTRG
        // base class this inherits from is the base game's and is
        // forward-declared instead; see CfgVehicles.hpp.
        requiredAddons[] = {"jmfsb_main", "jmfsb_uniform_sof", "jmfsb_headware"};
        skipWhenMissingDependencies = 1;
        author = QAUTHOR;
        VERSION_CONFIG;
    };
};

#include "CfgFactionClasses.hpp"
#include "CfgVehicles.hpp"
#include "CfgGroups.hpp"
