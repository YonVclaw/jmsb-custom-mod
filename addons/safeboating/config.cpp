#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        author = QAUTHOR;
        name = QUOTE(ADDON);
        requiredAddons[] = {
            "jmfsb_main"
        };
        units[] = {};
        weapons[] = {};
        requiredVersion = 1.52;
        VERSION_CONFIG;
        authors[] = {"Fusselwurm"};
    };
};

#include "CfgEventHandlers.hpp"

class CfgVehicles {
    // Boat_F is the game's parent (boat_transport_01). Naming the RHIB's base
    // instead rebinds every rubber boat to it - RPT "Updating base class
    // 'Boat_F'->'Boat_Transport_02_base_F'".
    class Boat_F;
    class Rubber_duck_base_F: Boat_F {
        rudderForceCoef = 0.3;
    };
};
