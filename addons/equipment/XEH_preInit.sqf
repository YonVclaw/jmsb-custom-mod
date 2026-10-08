#include "script_component.hpp"

ADDON = false;

// The old EGVAR(main,jmfsb_enabled) master gate stood here. Nothing in the
// repo, the settings or the mission ever WROTE that variable, so the isNil
// arm always fired and everything below this line was dead. Removed.

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

#include "initSettings.inc.sqf"

GVAR(markerIndex) = 0;
GVAR(marker3DQueue) = [];

ADDON = true;


