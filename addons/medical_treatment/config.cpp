#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "JMFSB_apapItem"
        };
        weapons[] = {
            "JMFSB_apap"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "ace_medical_treatment",
            "jmfsb_main"
        };
        author = "ArmaForces";
        VERSION_CONFIG;
    };
};


#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
#include "ACE_Medical_Treatment_Actions.hpp"
#include "ACE_Medical_Treatment.hpp"
