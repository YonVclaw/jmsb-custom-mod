#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.inc.sqf"

// ARMED FLAG, DECLARED AT PREINIT. Module functions run BETWEEN preInit and
// postInit, so declaring this in postInit was wrong twice over: the module
// read it before it existed, and postInit then set it back to false AFTER the
// module had armed the system.
GVAR(moduleUp) = false;

ADDON = true;
