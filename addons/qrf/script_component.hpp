#define COMPONENT qrf
#define COMPONENT_BEAUTIFIED QRF
#include "\z\jmfsb\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE

#ifdef DEBUG_ENABLED_QRF
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_QRF
    #define DEBUG_SETTINGS DEBUG_SETTINGS_QRF
#endif

#include "\z\jmfsb\addons\main\script_macros.hpp"

// Capture is a held state measured in tens of seconds, so the check is slow
// on purpose.
#define QRF_TICK            5

// Objectives a mission names itself. Also how a test objective exists on a
// map with no ALiVE commander at all.
#define QRF_MARKER_PREFIX   "jmfsb_qrf"
#define QRF_DEFAULT_RADIUS  150

// The ring QRF ground troops come from. Far enough to be a movement rather
// than an ambush out of nowhere.
#define QRF_RING_MIN        3000
#define QRF_RING_MAX        6000

// Rounds scale between these across objective size; dispersion is the
// objective's own footprint, so a roadblock gets a stonk and a base gets
// area fire.
#define QRF_SIZE_FULL       300
#define QRF_MORTAR          "Sh_82mm_AMOS"
