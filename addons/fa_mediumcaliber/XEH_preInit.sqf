#include "script_component.hpp"
ADDON = false;

PREP_RECOMPILE_START;
PREP(initEngine);
PREP(trackShell);
PREP(detonateShell);
PREP_RECOMPILE_END;

#include "initSettings.inc.sqf"

ADDON = true;
