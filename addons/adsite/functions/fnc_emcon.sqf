#include "..\script_component.hpp"
/*
 * Author: JMSB
 * Radar emission control for one Site (F5), through jmfsb_iads' own levers so
 * the two never fight over a radar:
 *
 *   jmfsb_iads_heldOff    dark, whatever iads' blink would do
 *   jmfsb_iads_pinned     lit, whatever iads' blink would do
 *   neither               iads' blink runs it (or the engine, with no iads module)
 *
 * AUTOMATIC leaves every radar to iads. SILENT UNTIL CUED holds them dark until
 * the Site - or a Site linked to it - is holding a track, then lights them for
 * the cue window. BURST SEARCH lights one at a time for the Site's burst length,
 * handed round the members, and all of them while there is a track to hold.
 *
 * WHATEVER THE MODE: a hostile anti-radiation missile homing on a radar puts
 * that radar dark until the missile is gone, and the Site relies on the others.
 *
 * Arguments:
 * 0: Site <HASHMAP>
 * 1: The Site's link group <ARRAY>
 *
 * Return Value: None
 *
 * Public: No
 */

params [["_site", createHashMap, [createHashMap]], ["_group", [], [[]]]];

private _radars = (_site get "members") select {(([_x] call FUNC(profile)) # 1) > 0};
if (_radars isEqualTo []) exitWith {};

private _now = CBA_missionTime;
private _set = {
    params ["_r", "_held", "_pinned"];
    private _was = [_r getVariable [QEGVAR(iads,heldOff), false], _r getVariable [QEGVAR(iads,pinned), false]];
    if (_was isEqualTo [_held, _pinned]) exitWith {};
    _r setVariable [QEGVAR(iads,heldOff), _held];
    _r setVariable [QEGVAR(iads,pinned), _pinned];
    if (_held) then { [_r, false] call EFUNC(iads,emit) };
    if (_pinned) then { [_r, true] call EFUNC(iads,emit) };
};

// the ARM threat: a hostile missile in the picture whose target is one of our radars
private _armed = [];
{
    _y params ["_obj", "_kind"];
    if (_kind isEqualTo "munition") then {
        private _t = missileTarget _obj;
        if (_t in _radars && {
            ("true" configClasses (configOf _obj >> "Components" >> "SensorsManagerComponent" >> "Components"))
                findIf {getText (_x >> "componentType") isEqualTo "PassiveRadarSensorComponent"} > -1
        }) then { _armed pushBackUnique _t };
    };
} forEach (_site get "tracks");

private _held = _group findIf {count (_x get "tracks") > 0} > -1;
private _mode = _site get "emcon";

{
    private _r = _x;
    if (_r in _armed) then { [_r, true, false] call _set; continue };
    // set by hand from the tacpad (FUNC(order) "radar"): the crew's, until they set it back to auto
    if (_r getVariable [QGVAR(manualRadar), false]) then { continue };
    switch (_mode) do {
        case "silent": {
            if (_held) then { _site set ["cuedUntil", _now + 45] };
            private _lit = _now < (_site get "cuedUntil");
            [_r, !_lit, _lit] call _set;
        };
        case "burst": {
            if (_held) then { [_r, false, true] call _set; continue };
            if (_now - (_site get "burstAt") >= (_site get "burstSeconds")) then {
                _site set ["burstAt", _now];
                _site set ["burstIndex", ((_site get "burstIndex") + 1) mod (count _radars)];
            };
            private _on = _forEachIndex isEqualTo ((_site get "burstIndex") mod (count _radars));
            [_r, !_on, _on] call _set;
        };
        default {
            // automatic: whatever we held or pinned goes back to iads
            [_r, false, false] call _set;
        };
    };
} forEach _radars;
