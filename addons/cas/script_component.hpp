#define COMPONENT cas
#define COMPONENT_BEAUTIFIED CAS
#include "\z\jmfsb\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE

#ifdef DEBUG_ENABLED_CAS
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_CAS
    #define DEBUG_SETTINGS DEBUG_SETTINGS_CAS
#endif

#include "\z\jmfsb\addons\main\script_macros.hpp"

// How long the run is allowed to take before the airframe is written off and
// swept, whatever it is doing. A drone that loses its waypoints to terrain or
// a stall would otherwise circle for the rest of the mission holding its
// asset busy - and the ledger would never free up.
#define CAS_RUN_TIMEOUT     600

// How close to the target counts as arrived, for the pass that releases
// ordnance. The aircraft is doing 200+ m/s; a tighter ring is one the tick
// can step straight over.
#define CAS_RELEASE_RING    600

// The terminal-guidance poll. The aircraft re-looks for a laser or smoke on
// the way in rather than once, so a JTAC who lights the target LATE - which
// is the normal case, you do not burn a designator for a minute - is still
// picked up before release.
#define CAS_ACQUIRE_STEP    1

// A dummy laser target is what actually guides the ordnance; see
// FUNC(fireAt). This is how far above the aim point it sits so a bomb
// fuses on the target rather than short of it.
#define CAS_DUMMY_UP        0.1

// HOW THE HEAVIEST THING ABOARD IS DECIDED, and the only place that order is
// written. FUNC(stores) ranks the airframe's stores with it so the page reads
// down the list in the order a run would have chosen for itself, and
// FUNC(fireAt) picks AUTO with it. Bombs first because that is what a strike
// is for; the gun last so an airframe carrying only cannon still makes a run
// rather than flying over silently. Submunitions sit with the bombs - a
// cluster store is a bomb to everyone except the config.
#define CAS_RANK            ["shotbomb", "shotsubmunitions", "shotmissile", "shotrocket", "shotshell", "shotbullet"]

// LOITER IS A TASK, NOT A RUN, so it gets its own patience: an ISR asset is
// meant to sit over the objective for as long as the section is working, and
// the strike timeout would pull it off station in ten minutes. It still ends
// on RTB, on death, or here.
#define CAS_LOITER_TIMEOUT  3600

// The orbit the aircraft holds over the task point once it is on station.
#define CAS_LOITER_RADIUS   900

// How close to the task point counts as ON STATION - the ring that hands the
// gunner's seat to the drone controller. Wide, because an orbit this size
// never puts the aircraft on the point itself.
#define CAS_STATION_RING    1600
