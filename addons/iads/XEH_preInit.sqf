#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// EVERYTHING THIS ADDON KEEPS IS DECLARED HERE, AND NOT IN XEH_postInit, and
// that is load-bearing rather than tidy. Module functions run BETWEEN preInit
// and postInit: this module arms the net and scans the map the moment it is
// read, so a registry declared in postInit would be an empty array assigned
// over the top of a net that had already registered every radar on the map.
// jmfsb_airdefence carries the same warning about its own armed flag - it was
// learned once, here it is applied to the whole of the state.
//
// SERVER ONLY. GVAR(radars) is also the broadcast registry an intel product
// would read on a client, and a client that cleared it in preInit would wipe
// the copy the network had just handed it on join.
if (isServer) then {
    GVAR(moduleUp) = false;

    // Live emitters under management, and the radarless shooters handed the
    // picture. Kept apart because they are managed differently: a receiver
    // never blinks.
    GVAR(radars) = [];
    GVAR(receivers) = [];

    // Class -> answer, for the two config sweeps. A lookup that always returns
    // the same answer should cost once per class rather than once per scan.
    GVAR(emitterCache) = createHashMap;
    GVAR(shooterCache) = createHashMap;

    GVAR(markerSeq) = 0;
    // A sweep in progress - see FUNC(scan). Declared here so a rescan that
    // fires before the first sweep ever ran reads false rather than nil.
    GVAR(scanning) = false;
    // P0-2 is logged once per mission, not once per read - see FUNC(tracks).
    GVAR(shapeSaid) = false;

    // The module overwrites every one of these when it is read. They exist so
    // that a function called before any module was placed - the report command,
    // a hand-run scan from a debug console - reads a number rather than nil.
    GVAR(blinkMin) = 20;
    GVAR(blinkMax) = 40;
    GVAR(minEmitters) = 1;
    GVAR(rescan) = 5;
    GVAR(manageAir) = false;
    GVAR(linkAll) = false;
    GVAR(revealEvery) = 10;
    GVAR(ambush) = false;
    GVAR(envelope) = 4000;
    GVAR(debugMarkers) = false;
    GVAR(exempt) = [];
    GVAR(extraReceivers) = [];
};

ADDON = true;
