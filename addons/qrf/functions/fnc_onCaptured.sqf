#include "script_component.hpp"
/*
 * Author: JMSB
 * The reply. Which commander answers is whichever is hostile to the captors -
 * and what it can send depends on what kind of war it fights.
 *
 * Arguments (the capture event):
 * 0: Objective name <STRING>
 * 1: Capturing side <SIDE>
 * 2: Position <ARRAY>
 * 3: Radius <NUMBER>
 *
 * Return Value: None
 *
 * Public: No
 */

params ["_name", "_side", "_pos", "_radius"];

if (!isServer) exitWith {};
if (isNil "jmfsb_adapter_alive_fnc_commanders") exitWith {
    INFO_1("'%1' taken - no adapter, so nobody to answer",_name);
};

private _answering = sideUnknown;
private _ctype = "";
private _faction = "";
{
    _x params ["_cside", "_ct", "_cf"];
    if (_cside getFriend _side < 0.6) exitWith {
        _answering = _cside;
        _ctype = _ct;
        _faction = _cf;
    };
} forEach (call jmfsb_adapter_alive_fnc_commanders);

if (_answering isEqualTo sideUnknown) exitWith {
    INFO_1("'%1' taken - nobody hostile to answer it",_name);
};

INFO_4("QRF: %1 (%2) answers '%3' taken by %4",_answering,_ctype,_name,_side);

[_answering, _ctype, _pos, _radius] call FUNC(waveArty);
[_answering, _pos] call FUNC(waveDrones);
[_answering, _faction, _pos] call FUNC(waveSquads);
