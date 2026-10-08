#include "script_component.hpp"

#ifndef JMFSB_LEAN_RHS_CUP_HLC

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"jmfsb_common"};
        author = QAUTHOR;
        authors[] = {"PabstMirror"};
        authorUrl = "https://github.com/Joint-Multi-Functional-Strike-Battalion";
        VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"

#endif
