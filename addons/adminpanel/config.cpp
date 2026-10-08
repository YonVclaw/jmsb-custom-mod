#include "script_component.hpp"

// ---------------------------------------------------------------------------
// THIS ADDON IS GPL-3, AND THE REST OF JMFSB IS NOT.
//
// The panel is JohnnyShootos' work, edited by TheTimidShade, taken from the
// mission framework it shipped in - which carries the GNU General Public
// License v3. That licence travels with the code: it cannot be relicensed as
// APL-SA, so it is not mixed into any other jmfsb addon. It is its own PBO,
// with its own LICENSE beside it, distributed alongside jmfsb rather than
// dissolved into it.
//
// See LICENSE and README.md in this folder before moving any of it anywhere.
// ---------------------------------------------------------------------------

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "jmfsb_main",
            "jmfsb_common",
            "jmfsb_notify",
            "jmfsb_tacpad",
            "cba_xeh"
        };
        author = "JohnnyShootos";
        authors[] = {"JohnnyShootos", "TheTimidShade", "JMSB"};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgFunctions.hpp"
#include "ui\controls.inc.hpp"
#include "ui\dialog.inc.hpp"
