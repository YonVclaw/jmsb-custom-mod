#include "..\script_component.hpp"
/*
 * Author: JMSB
 * One weapon onto one threat, with the vehicle's OWN weapon (F2) - what flies is
 * the game's round, so ballistics, guidance and damage are the game's.
 * SCHEDULED: it waits on the crew.
 *
 * A MISSILE: after the crew's delay (FUNC(crewDelay)) the gunner watches and
 * targets the threat and the weapon is fired at it. FUNC(fired) catches the
 * round as it leaves, steers it onto a munition and hands it to the fuse.
 *
 * A GUN or a CIWS (F7): it leads the target by its rounds' flight time, plus a
 * correction learned from where its last bursts passed (FUNC(fuze) measures
 * them), and fires a burst only when the predicted miss is under
 * ADS_CIWS_CHANCE metres - the "real chance of hitting" - or three times that
 * for an ordinary gun. It keeps at it while the threat is alive and in reach.
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 * 1: Profile entry (FUNC(profile)) <ARRAY>
 * 2: Target <OBJECT>
 * 3: "air" or "munition" <STRING>
 * 4: Site id <STRING>
 *
 * Return Value: None
 *
 * Public: No
 */

params ["_veh", "_entry", "_target", "_kind", "_siteId"];
_entry params ["_path", "_weapon", "_mag", "_ammo", "_sim", "_max", "_min", "_role", "_guided", "_fuse"];

private _site = GVAR(sites) getOrDefault [_siteId, createHashMap];
private _release = {
    private _busy = _site getOrDefault ["busy", createHashMap];
    _busy deleteAt (hashValue _veh);
};

sleep ([_veh, _path, _site] call FUNC(crewDelay));
if (!alive _veh || {!alive _target}) exitWith _release;

private _man = [_veh turretUnit _path, driver _veh] select (_path isEqualTo [-1]);
if (isNull _man) exitWith _release;
_man doWatch _target;
_man doTarget _target;

if (_role in [ROLE_SHORT, ROLE_LONG]) exitWith {
    // FUNC(fired) reads this as the round leaves
    _veh setVariable [QGVAR(pending), [_target, _fuse, _siteId, _kind]];
    sleep 0.5;
    private _shot = _veh fireAtTarget [_target, _weapon];
    if (!_shot) then { _shot = _man fireAtTarget [_target, _weapon] };
    if (!_shot) then { _man forceWeaponFire [_weapon, (getArray (configFile >> "CfgWeapons" >> _weapon >> "modes")) param [0, "this"]] };
    // the launcher is free again once the round is away (or the try failed)
    sleep 2;
    // still pending: no missile left the tube, so nothing of its holds the
    // commitment - another weapon may take the threat
    if (!isNil {_veh getVariable QGVAR(pending)}) then {
        private _c = _site getOrDefault ["committed", createHashMap];
        private _key = hashValue _target;
        _c set [_key, (_c getOrDefault [_key, []]) - [_veh]];
    };
    _veh setVariable [QGVAR(pending), nil];
    call _release;
};

// ---- a gun or a CIWS ---------------------------------------------------------
private _speed = getNumber (configFile >> "CfgMagazines" >> _mag >> "initSpeed") max 300;
private _mode = (getArray (configFile >> "CfgWeapons" >> _weapon >> "modes")) param [0, "this"];
private _chance = [ADS_CIWS_CHANCE * 3, ADS_CIWS_CHANCE] select (_role isEqualTo ROLE_CIWS);
private _until = time + 12;
_veh setVariable [QGVAR(pending), [_target, ADS_FUSE_DEFAULT / 4, _siteId, _kind]];

while {alive _veh && {alive _target} && {time < _until} && {(_veh distance _target) <= _max} && {(_veh magazineTurretAmmo [_mag, _path]) > 0}} do {
    private _dist = _veh distance _target;
    private _lead = (getPosASL _target) vectorAdd ((velocity _target) vectorMultiply (_dist / _speed));
    // the correction this gun has learned against this target (FUNC(fuze))
    _lead = _lead vectorAdd (_veh getVariable [QGVAR(aimFix), [0, 0, 0]]);
    _man doWatch ASLToAGL _lead;
    sleep 0.15;

    // predicted miss: how far the gun's line passes from the lead point
    private _dir = _veh weaponDirection _weapon;
    private _to = _lead vectorDiff (eyePos _man);
    private _along = _to vectorDotProduct _dir;
    private _miss = if (_along <= 0) then {1e9} else {vectorMagnitude (_to vectorDiff (_dir vectorMultiply _along))};

    if (_miss <= _chance) then {
        private _end = time + 0.6;
        while {time < _end && {alive _target}} do {
            _man forceWeaponFire [_weapon, _mode];
            sleep 0.02;
        };
        sleep 0.2;
    };
};

_veh setVariable [QGVAR(pending), nil];
_veh setVariable [QGVAR(aimFix), [0, 0, 0]];
call _release;
