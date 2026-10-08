#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "ace_ballistics",
            "cba_main"
        };
        author = "1st Joint Multi-Functional Strike Battalion";
        VERSION_CONFIG;
    };
};
