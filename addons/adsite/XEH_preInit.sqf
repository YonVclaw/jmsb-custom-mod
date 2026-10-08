#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// DECLARED HERE, NOT IN postInit: the Site module's function runs before
// postInit does, and it registers into these.
//
// id -> Site hashmap (FUNC(register) documents the keys). Server only.
GVAR(sites) = createHashMap;
// class -> profile, filled the first time a class joins a Site (FUNC(profile))
GVAR(profiles) = createHashMap;
// interceptors in flight: [projectile, target, fuse distance, launched at, site id]
GVAR(inFlight) = [];
// the per-frame and beat handlers, started once by FUNC(start)
GVAR(running) = false;
GVAR(nextSite) = 0;

// What every client's tacpad panel draws - the server writes it, public, every
// ADS_BOARD_EVERY seconds (FUNC(board)).
if (isNil QGVAR(board)) then { GVAR(board) = [] };

ADDON = true;
