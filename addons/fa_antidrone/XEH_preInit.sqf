#include "script_component.hpp"
ADDON = false;

PREP_RECOMPILE_START;
PREP(initAntiDrone);
PREP(trackAD);
PREP(detonateAD);
PREP(setBurst);
PREP(cycleBurst);
PREP(hasMk364);
PREP_RECOMPILE_END;

#include "initSettings.inc.sqf"

ADDON = true;
