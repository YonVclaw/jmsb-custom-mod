#include "script_component.hpp"

class CfgPatches {
    class cba_settings_userconfig {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"cba_settings", "ace_hearing"};
        author = QAUTHOR;
        authors[] = {"commy2"};
        authorUrl = "https://github.com/Joint-Multi-Functional-Strike-Battalion";
        VERSION_CONFIG;
    };
};
