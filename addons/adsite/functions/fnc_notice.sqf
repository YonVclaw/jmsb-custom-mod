#include "..\script_component.hpp"
/*
 * Author: JMSB
 * The Site's alarms, as jmfsb notices (F9 - user, 2026-10-07: "warning should be
 * a notice"). No sounds of the Site's own: the notice stack is how every jmfsb
 * system warns, and its history is the log.
 *
 * GOING LIVE - the first time the Site's radars radiate, and again after a
 * silence of two minutes or more.
 * INCOMING - when munitions are coming down inside the protected area: one
 * notice per salvo (at most every ADS_NOTICE_GAP seconds), with the count and
 * the soonest impact.
 *
 * Both go to the Site's side only.
 *
 * Arguments:
 * 0: Site <HASHMAP>
 *
 * Return Value: None
 *
 * Public: No
 */

params [["_site", createHashMap, [createHashMap]]];

if !(_site get "notices") exitWith {};
private _now = CBA_missionTime;
private _side = _site get "side";
private _name = _site get "name";
private _pos = ASLToAGL (_site get "centre");

// going live
private _lit = (_site get "members") findIf {isVehicleRadarOn _x} > -1;
if (_lit) then {
    if (!(_site get "live") && {_now - (_site getOrDefault ["darkSince", -1e9]) >= 120}) then {
        _site set ["live", true];
        ["AIR DEFENCE", format ["%1 radiating", _name], [0.85, 0.65, 0.15, 1], _side, _pos] call EFUNC(notify,broadcast);
    };
} else {
    if (_site get "live") then {
        _site set ["live", false];
        _site set ["darkSince", _now];
    };
};

// incoming
private _rounds = values (_site get "tracks") select {(_x # 1) isEqualTo "munition"};
if (_rounds isNotEqualTo [] && {_now - (_site get "lastIncoming") >= ADS_NOTICE_GAP}) then {
    _site set ["lastIncoming", _now];
    private _soonest = selectMin (_rounds apply {_x # 4});
    private _what = if (count _rounds == 1) then { getText (configFile >> "CfgAmmo" >> (_rounds # 0 # 2) >> "displayName") } else { format ["%1 rounds", count _rounds] };
    if (_what isEqualTo "") then { _what = "1 round" };
    ["INCOMING", format ["%1 on %2, %3 s", _what, _name, ceil _soonest], [0.871, 0.2, 0.15, 1], _side, _pos] call EFUNC(notify,broadcast);
};
