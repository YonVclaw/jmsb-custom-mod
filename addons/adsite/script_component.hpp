#define COMPONENT adsite
#define COMPONENT_BEAUTIFIED Air Defence Sites
#include "\z\jmfsb\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE

#ifdef DEBUG_ENABLED_ADSITE
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_ADSITE
    #define DEBUG_SETTINGS DEBUG_SETTINGS_ADSITE
#endif

#include "\z\jmfsb\addons\main\script_macros.hpp"

// THE BEAT. How often a Site looks at its sky and hands out threats. A mortar
// round is in the air for twenty seconds and a rocket for fewer; a quarter of a
// second is four looks a second, which leaves the crews' own reaction time -
// not this number - as what decides whether a round is caught.
#define ADS_BEAT 0.25

// How often the server publishes the board the tacpad panel draws. A panel that
// redraws every two seconds needs nothing fresher.
#define ADS_BOARD_EVERY 2

// Munitions are looked for this far beyond a Site's longest reach: a round has
// to be seen before it is inside the envelope, or the first look is too late.
#define ADS_TRACK_MARGIN 1500

// Impact predicted inside the protected area plus this margin counts as a
// threat. A shell's predicted point is ballistic and wind-free; the margin is
// what wind and drag can move it, so a round that lands just inside is not
// waved through on a rounding.
#define ADS_IMPACT_MARGIN 60

// The proximity fuse, when the interceptor's own ammo names no blast radius.
#define ADS_FUSE_DEFAULT 12

// An interceptor that has not met its target in this long is let go.
#define ADS_FUSE_TIMEOUT 40

// A gun counts as a CIWS - the inner layer that bursts at what it can hit - when
// its fastest mode fires faster than this (seconds between rounds). A Praetorian
// is about 0.0133; an AA autocannon about 0.06.
#define ADS_CIWS_RELOAD 0.03

// The longest-range missiles are the reserve: at this range or more a launcher
// is LONG, and held back from munitions while it is above the Site's reserve.
#define ADS_LONG_RANGE 6000

// The CIWS opens fire only when its corrected aim predicts a miss under this
// many metres at the target - the "real chance of hitting" the feature asks for.
#define ADS_CIWS_CHANCE 8

// An incoming notice is coalesced: one per Site at most this often, however many
// rounds are in the salvo.
#define ADS_NOTICE_GAP 10

// The munitions a Site looks for. The cores, so every family's children count:
// missiles, rockets (MLRS among them), shells (artillery and mortar), bombs and
// submunitions.
#define ADS_MUNITIONS ["MissileCore", "RocketCore", "ShellCore", "BombCore", "SubmunitionCore"]

// Roles a member can play, from its own config (FUNC(profile)).
#define ROLE_LONG "long"
#define ROLE_SHORT "short"
#define ROLE_GUN "gun"
#define ROLE_CIWS "ciws"
#define ROLE_SENSOR "sensor"
#define ROLE_SURFACE "surface"

// Panel placement on the map screen, safe-zone fractions.
#define DEFAULT_ADSITE [0.165, 0.47, 0.26, 0.34]
