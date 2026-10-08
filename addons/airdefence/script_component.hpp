#define COMPONENT airdefence
#define COMPONENT_BEAUTIFIED Air Defence
#include "\z\jmfsb\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE

#ifdef DEBUG_ENABLED_AIRDEFENCE
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_AIRDEFENCE
    #define DEBUG_SETTINGS DEBUG_SETTINGS_AIRDEFENCE
#endif

#include "\z\jmfsb\addons\main\script_macros.hpp"

// A TEMPORARY SYSTEM, on purpose. ALiVE places air defence itself and jmfsb's
// standing rule is to feed ALiVE rather than duplicate it - but ALiVE 3's
// version is not stable yet, so this stands in until it is. Nothing else is
// built on top of it and it is expected to be deleted, not grown.

// How the two kinds of commander are answered. A conventional commander -
// invasion or occupation - gets a radar cueing launchers set back from it. An
// asymmetric one gets men with MANPADS, because a guerrilla does not field a
// battery and a battery is not something players can quietly walk past.
#define AD_CONVENTIONAL ["invasion", "occupation"]

// Launchers stand off the radar the way a real battery does: far enough that
// killing the radar is a separate job from killing the launchers, near enough
// that they read as one site.
#define AD_LAUNCH_MIN   150
#define AD_LAUNCH_MAX   450

// A MANPAD team is a couple of men, not a squad - they are meant to be found
// on foot and dealt with, not fought through.
#define AD_TEAM_MIN     2
#define AD_TEAM_MAX     3

// The ring a MANPAD team is placed in around the objective it covers. Off the
// objective itself: a shooter sits where he can see the approach, not in the
// middle of the thing everyone is already looking at.
#define AD_TEAM_MIN_R   200
#define AD_TEAM_MAX_R   700

// Security on a battery: a fireteam, standing off the hardware. Out far enough
// that whatever kills the launchers does not kill the guards with them, close
// enough that they are guarding this site and not the next valley.
#define AD_SEC_MIN      4
#define AD_SEC_MAX      6
#define AD_SEC_MIN_R    60
#define AD_SEC_MAX_R    200
