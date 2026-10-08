#define COMPONENT iads
#define COMPONENT_BEAUTIFIED IADS
#include "\z\jmfsb\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE

#ifdef DEBUG_ENABLED_IADS
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_IADS
    #define DEBUG_SETTINGS DEBUG_SETTINGS_IADS
#endif

#include "\z\jmfsb\addons\main\script_macros.hpp"

// THE ENGINE'S RADAR STATES, NAMED IN ONE PLACE. setVehicleRadar takes 0 for
// default (the AI decides), 1 for forced off and 2 for forced on.
//
// This is P0-1 of the plan and it is the one number here that a wrong guess
// would silently INVERT - a mod that blinked every radar ON when it meant off
// would look like it was working while doing the opposite. So: nothing else in
// this addon knows these numbers, FUNC(emit) is their only caller, and
// `#jmfsb iads.probe` drives all three on a real vehicle in front of you. If
// the probe disagrees with these three lines, these three lines are the fix.
#define IADS_RADAR_AUTO 0
#define IADS_RADAR_OFF  1
#define IADS_RADAR_ON   2

// The beat. NOT a knob: the blink intervals are what a mission tunes and this
// is only how often the scheduler gets to look at them. Five seconds is under
// the shortest blink anybody would sensibly set, and it costs one pass over a
// list that is a few dozen long at most.
#define IADS_TICK 5

// How long a radar lit by the ambush trigger stays up. Long enough to acquire,
// launch and guide; short enough that a site which lit for a track passing its
// edge is dark again before anything can be vectored onto it. Not a knob,
// because the knob that matters is the envelope it triggers on.
#define IADS_AMBUSH_WINDOW 45

// THE SWEEP IS SLICED, because it is the one job here whose size this addon
// does not control: `vehicles` on an ALiVE map is at its largest exactly when
// profiles have spawned in around the players, and walking all of it in one
// frame is a hitch on a metronome - every rescan, on the second. Twenty-five a
// frame keeps a slice well under a frame's budget with every cache cold, and a
// four-hundred-vehicle map still finishes a sweep in under a second of wall
// time.
#define IADS_SCAN_SLICE 25

// When a beat owns up to being slow, in milliseconds. A frame at 60 fps is
// about 16 ms; a beat that eats 10 of them is most of a frame and worth a line
// in the RPT, and one that eats 100 is the freeze somebody is hunting. Under
// the threshold nothing is logged - the sweep's own completion line already
// carries its cost.
#define IADS_SLOW_MS 10

// Sensor components that mean "this thing emits". The active radar is what
// EMCON is about: passive radar, IR and visual give nothing away and are never
// touched here - see the dark-but-watching note in FUNC(emit).
#define IADS_EMITTER_COMPONENTS ["ActiveRadarSensorComponent"]

// A magazine whose ammo can lock onto aircraft makes the vehicle carrying it a
// SHOOTER worth handing the picture to. airLock: 0 none, 1 can lock air, 2 air
// only.
#define IADS_AIRLOCK_MIN 1
