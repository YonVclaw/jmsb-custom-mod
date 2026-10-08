#include "script_component.hpp"
/*
 * Author: JMSB
 * Is this a shooter worth handing the picture to - something that can put a
 * missile on an aircraft?
 *
 * P2-D2 OF THE PLAN, ANSWERED FROM THE CONFIG. The alternative was a classlist
 * per mission, which is a list that is wrong the moment somebody loads another
 * mod. What makes a launcher a launcher is written in its ammunition: airLock
 * says whether the round can lock an air target at all. A launcher with no
 * radar of its own and a datalink feed is the whole point of the layer - it
 * shoots what somebody else can see.
 *
 * THE VEHICLE, NOT THE CLASS, because `weapons` on the object already walks
 * every turret. Digging turret paths out of the config to reach the same list
 * is more code and more ways to miss a turret.
 *
 * Cached by class - two launchers of one type answer the same.
 *
 * Arguments:
 * 0: The vehicle <OBJECT>
 *
 * Return Value:
 * Can engage aircraft <BOOL>
 *
 * Example:
 * private _yes = [_veh] call jmfsb_iads_fnc_isShooter
 *
 * Public: No
 */

params [["_veh", objNull, [objNull]]];

if (isNull _veh) exitWith {false};

private _cls = typeOf _veh;
if (_cls isEqualTo "") exitWith {false};

private _cached = GVAR(shooterCache) getOrDefault [_cls, -1];
if (_cached isEqualType true) exitWith {_cached};

private _out = false;

{
    private _weapon = _x;
    private _mags = getArray (configFile >> "CfgWeapons" >> _weapon >> "magazines");

    {
        private _ammo = getText (configFile >> "CfgMagazines" >> _x >> "ammo");
        if (_ammo isEqualTo "") then {continue};
        if (getNumber (configFile >> "CfgAmmo" >> _ammo >> "airLock") >= IADS_AIRLOCK_MIN) exitWith {_out = true};
    } forEach _mags;

    if (_out) exitWith {};
} forEach (weapons _veh);

GVAR(shooterCache) set [_cls, _out];
_out
