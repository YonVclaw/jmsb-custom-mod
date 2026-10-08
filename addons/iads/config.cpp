#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {"jmfsb_moduleIADS"};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        // NO ADAPTER DEPENDENCY, AND THAT IS DELIBERATE. This addon manages
        // whatever radars are standing on the map, whoever put them there -
        // ALiVE placement, jmfsb_airdefence, or a mission maker's own Eden
        // hardware. It never asks who created anything, so it never has to
        // know ALiVE exists (docs/new.md rule 4) and it needs no event to
        // wait for: the rescan finds what arrived since last time.
        requiredAddons[] = {
            "jmfsb_main",
            "jmfsb_common",
            "cba_xeh"
        };
        skipWhenMissingDependencies = 1;
        author = QAUTHOR;
        authors[] = {"JMSB"};
        authorUrl = URL;
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
