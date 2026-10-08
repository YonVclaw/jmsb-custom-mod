#include "script_component.hpp"
/*
 * Author: JMSB
 * Arms this client's transmission watch.
 *
 * TFAR reports a key-up as an event and tells us whether the set was long or
 * short range, so short-range traffic never even reaches the filter - the
 * squad net is always safe. ACRE has no such event, so it is polled for the
 * rising edge of isBroadcasting.
 *
 * Arguments: None
 *
 * Return Value: None
 *
 * Public: No
 */

if (!hasInterface) exitWith {};
if (!isNil QGVAR(radioReady)) exitWith {};
GVAR(radioReady) = true;

if (isClass (configFile >> "CfgPatches" >> "task_force_radio")
    && {!isNil "TFAR_fnc_addEventHandler"}) then {
    [QGVAR(track), "OnTangent", {
        // TFAR: [unit, radioClass, radioType, additionalChannel, buttonDown]
        // radioType 1 is long range; 0 is the squad set and never reported.
        params [["_unit", objNull], "_radio", ["_type", -1], "", ["_down", false]];
        if (_down && _type == 1) then {
            [_radio] call FUNC(onTransmit);
        };
    }, player] call TFAR_fnc_addEventHandler;
};

if (isClass (configFile >> "CfgPatches" >> "acre_main")
    && {!isNil "acre_api_fnc_isBroadcasting"}) then {
    GVAR(wasTx) = false;
    [{
        private _tx = [] call acre_api_fnc_isBroadcasting;
        if (_tx && {!GVAR(wasTx)}) then {
            private _radio = "";
            if (!isNil "acre_api_fnc_getCurrentRadio") then {
                _radio = [] call acre_api_fnc_getCurrentRadio;
            };
            [_radio] call FUNC(onTransmit);
        };
        GVAR(wasTx) = _tx;
    }, 1, []] call CBA_fnc_addPerFrameHandler;
};
