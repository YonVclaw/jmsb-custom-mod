#include "script_component.hpp"
/*
 * Author: JMSB
 * The objective-lost-grade reply (new.md section 2): shells from the hostile
 * commander's own guns, a drone sent to look, and the neighbourhood told.
 *
 * ASKED FOR, NOT CONJURED. The shells are an ARTY_REQUEST to a real commander
 * with real batteries - if none is in range, none arrive, and the fallback
 * barrage only fires when there is no commander to ask at all. The drone
 * comes out of that side's ceiling, so a force whose supply was raided
 * answers thinly.
 *
 * Throttled per player: five failed retries are one discovery.
 *
 * Arguments:
 * 0: The player <OBJECT>
 * 1: Source tag <STRING>
 *
 * Return Value: None
 *
 * Public: No
 */

params [["_unit", objNull, [objNull]], ["_source", "?", [""]]];

private _id = netId _unit;
if (CBA_missionTime < ((GVAR(majors) getOrDefault [_id, -1e9]) + REACT_MAJOR_COOLDOWN)) exitWith {};
GVAR(majors) set [_id, CBA_missionTime];
GVAR(flags) deleteAt _id;
// The client-side mirror goes with it - a consumed flag must not keep
// trebling the hacker's fail odds for the rest of its decay window.
_unit setVariable [QGVAR(flaggedUntil), nil, true];

private _pos = getPosATL _unit;
private _pside = side group _unit;

INFO_3("MAJOR on %1 (%2) at %3",name _unit,_source,mapGridPosition _pos);

// --- who is hostile enough to care ---------------------------------------
private _answering = sideUnknown;
if (!isNil "jmfsb_adapter_alive_fnc_commanders") then {
    {
        _x params ["_cside"];
        if (_cside getFriend _pside < 0.6) exitWith { _answering = _cside };
    } forEach (call jmfsb_adapter_alive_fnc_commanders);
};

// --- shells ----------------------------------------------------------------
private _lo = GVAR(roundsMin);
private _hi = GVAR(roundsMax) max _lo;
private _rounds = round (_lo + random (_hi - _lo));

if (_rounds > 0) then {
    private _asked = false;
    if (_answering isNotEqualTo sideUnknown && {!isNil "jmfsb_adapter_alive_fnc_requestFire"}) then {
        _asked = [_answering, _pos, 1] call jmfsb_adapter_alive_fnc_requestFire;
    };
    if (!_asked) then {
        // Nobody to ask. The lesson still lands, from nowhere in particular -
        // which is honest for a mission with no artillery commander at all.
        // GATED like every module spawn: a known answering side only
        // conjures shells onto its own ground - a discovery inside the
        // players' own base is not licence to shell it. No answering side,
        // no TAOR, no gate - the honest-fallback case stands.
        // fireBarrage is [pos, rounds, spread, shell, window] since the
        // refactor - the old ammo-first shape here was the pair of params
        // type errors in every RPT, rescued only by the defaults.
        if ([_answering, _pos, "reaction fallback barrage"] call EFUNC(common,taorGate)) then {
            [_pos, _rounds, REACT_FALLBACK_DISP, REACT_FALLBACK_AMMO, _rounds * REACT_FALLBACK_GAP]
                call EFUNC(common,fireBarrage);
        };
    };
};

// --- a drone comes looking ------------------------------------------------
if (_answering isNotEqualTo sideUnknown && {!isNil "jmfsb_uas_fnc_respondTo"}) then {
    [_answering, _pos] call jmfsb_uas_fnc_respondTo;
};

// --- the neighbourhood learns ---------------------------------------------
private _radius = REACT_REVEAL_MIN + random (REACT_REVEAL_MAX - REACT_REVEAL_MIN);
{
    if ((side group _x) getFriend _pside < 0.6) then {
        _x reveal [_unit, 3.5];
        (group _x) setBehaviourStrong "AWARE";
    };
} forEach (allUnits select {alive _x && {_x distance2D _pos <= _radius}});

// The virtual world hears it too, so a section that walks away from the
// shells does not walk into a commander that never noticed.
if (!isNil "jmfsb_adapter_alive_fnc_nearProfiles") then {
    private _n = count ([_pos, _radius] call jmfsb_adapter_alive_fnc_nearProfiles);
    if (_n > 0) then { INFO_1("%1 nearby profile(s) share the fix",_n) };
};

["COMPROMISED", "They know where you are.", [0.87, 0.36, 0.19, 1], _pside]
    call EFUNC(notify,broadcast);
