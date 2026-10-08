#include "..\script_component.hpp"
/*
 * Author: JMSB
 * How long this crew takes from being handed a threat to its weapon firing
 * (F6) - no fixed timer.
 *
 * The Site's reaction is an average crew's. A skilled gunner is faster and a
 * poor one slower; each crewman carries a temperament drawn once and kept for
 * the mission, so the same crew is reliably quick or reliably slow rather than
 * random each time; and an unskilled crew sometimes fumbles, losing a second.
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 * 1: Turret path of the weapon <ARRAY>
 * 2: Site <HASHMAP>
 *
 * Return Value:
 * Seconds <NUMBER>
 *
 * Example:
 * [_veh, [0], _site] call jmfsb_adsite_fnc_crewDelay
 *
 * Public: No
 */

params [["_veh", objNull, [objNull]], ["_path", [0], [[]]], ["_site", createHashMap, [createHashMap]]];

private _man = [_veh turretUnit _path, driver _veh] select (_path isEqualTo [-1]);
if (isNull _man) exitWith { _site getOrDefault ["reaction", 2] };

private _skill = ((_man skill "spotTime") + (_man skill "aimingSpeed") + (_man skill "commanding")) / 3;
private _temper = _man getVariable [QGVAR(temper), -1];
if (_temper < 0) then {
    _temper = 0.8 + random 0.45;
    _man setVariable [QGVAR(temper), _temper];
};

private _delay = (_site getOrDefault ["reaction", 2]) * (1.5 - _skill) * _temper;
if (random 1 < (_site getOrDefault ["fumble", 0.1]) * (1 - _skill)) then {
    _delay = _delay + 1 + random 1;
};
_delay max 0.2
