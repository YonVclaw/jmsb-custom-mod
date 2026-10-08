#include "script_component.hpp"

// The old EGVAR(main,jmfsb_enabled) master gate stood here. Nothing in the
// repo, the settings or the mission ever WROTE that variable, so the isNil
// arm always fired and everything below this line was dead. Removed.

if (hasInterface) then {
    #include "initKeybinds.inc.sqf"

    [QGVAR(marker3D), {_this call FUNC(show3DMarker)}] call CBA_fnc_addEventHandler;
};

