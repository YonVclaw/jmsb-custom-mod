#define COMPONENT acm
#define COMPONENT_BEAUTIFIED ACM
#include "\z\jmfsb\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE

#ifdef DEBUG_ENABLED_ACM
    #define DEBUG_MODE_FULL
#endif
    #ifdef DEBUG_SETTINGS_ACM
    #define DEBUG_SETTINGS DEBUG_SETTINGS_ACM
#endif

#include "\z\jmfsb\addons\main\script_macros.hpp"

// ACM's and ACE's skill dropdowns: who may perform a treatment. ACE's medic
// class is what the PAC skills set - CLS gives 1, Medic gives 2.
#define SKILL_ANYONE 0
#define SKILL_CLS 1
#define SKILL_MEDIC 2
