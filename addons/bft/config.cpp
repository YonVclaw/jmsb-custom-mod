#include "script_component.hpp"

// Blue Force Tracking, by Jacco Douma. Ported from the TCA_bft addon of Team
// Collaboration Aides (https://github.com/Jaccodouma/TCA-A3) with attribution -
// see README.md for what jmfsb changed and what came over untouched.

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        // ace_interact_menu + ace_common for the map self-interaction that lets a
        // group leader set their own name, icon and colour. jmfsb_common for the
        // admin flag and the #jmfsb command harness the admin surface hangs off.
        requiredAddons[] = {
            "jmfsb_main",
            "jmfsb_common",
            "ace_interact_menu",
            "ace_common",
            "cba_xeh"
        };
        author = QAUTHOR;
        authors[] = {"Jacco Douma", "JMSB"};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
