#include "script_component.hpp"
/*
 * Author: YonV
 * Shows an in-world (3D) marker name at a Vector target position for
 * GVAR(marker3DDuration) seconds. Runs on every client via the
 * QGVAR(marker3D) CBA event raised by FUNC(placeTargetMarker).
 *
 * Arguments:
 * 0: Target position ASL <ARRAY>
 * 1: Marker text <STRING>
 * 2: Marker color config name <STRING> (default: "Default")
 *
 * Return Value:
 * None
 *
 * Example:
 * [[1000, 2000, 30], "YonV (750m)", "ColorRed"] call jmfsb_equipment_fnc_show3DMarker
 */

params ["_posASL", "_text", ["_colorName", "Default"]];

if (!hasInterface) exitWith {};
if (GVAR(marker3DDuration) <= 0) exitWith {};

private _color = getArray (configFile >> "CfgMarkerColors" >> _colorName >> "color");
_color = _color apply {
    if (_x isEqualType "") then {parseNumber _x} else {_x}
};
if (count _color != 4) then {
    _color = [1, 1, 1, 1];
};

private _posAGL = (ASLToAGL _posASL) vectorAdd [0, 0, 1.5];
GVAR(marker3DQueue) pushBack [_posAGL, _text, _color, CBA_missionTime + GVAR(marker3DDuration)];

// One shared Draw3D handler, added lazily on the first 3D marker
if (isNil QGVAR(marker3DDrawEH)) then {
    GVAR(marker3DDrawEH) = addMissionEventHandler ["Draw3D", {
        if (GVAR(marker3DQueue) isEqualTo []) exitWith {};

        private _now = CBA_missionTime;
        GVAR(marker3DQueue) = GVAR(marker3DQueue) select {_now < (_x select 3)};

        {
            _x params ["_posAGL", "_text", "_color"];
            drawIcon3D [
                "\A3\ui_f\data\map\markers\military\dot_CA.paa",
                _color,
                _posAGL,
                0.7,
                0.7,
                0,
                _text,
                2,
                0.035,
                "PuristaMedium"
            ];
        } forEach GVAR(marker3DQueue);
    }];
};
