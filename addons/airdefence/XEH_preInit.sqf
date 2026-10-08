#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// ARMED FLAG, DECLARED AT PREINIT. Module functions run BETWEEN preInit and
// postInit, so declaring this in postInit means the module reads it before it
// exists - and postInit then sets it back to false after the module armed.
GVAR(moduleUp) = false;

ADDON = true;
