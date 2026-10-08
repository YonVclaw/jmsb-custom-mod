#include "..\script_component.hpp"
/*
 * Author: JMSB
 * What a vehicle can do in a Site, read from its own config and loadout - never
 * from a list (F2). Cached per class.
 *
 * Every turret weapon with a magazine is one entry:
 *   [turret path, weapon, magazine, ammo, simulation, max range, min range, role, guided, fuse]
 * and the role falls out of the numbers:
 *   a missile that can lock air      LONG at ADS_LONG_RANGE or more, SHORT under it
 *   a gun or cannon that can lock air CIWS if it fires faster than ADS_CIWS_RELOAD, GUN otherwise
 *   anything that cannot lock air    SURFACE - what a strike from the tacpad can use
 * An active radar makes the vehicle a SENSOR as well, at its own air range.
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 *
 * Return Value:
 * [weapon entries, radar range m, roles] <ARRAY>
 *
 * Example:
 * [_launcher] call jmfsb_adsite_fnc_profile
 *
 * Public: No
 */

params [["_veh", objNull, [objNull]]];

if (isNull _veh) exitWith {[[], 0, []]};
private _cls = typeOf _veh;
private _cached = GVAR(profiles) get _cls;
if (!isNil "_cached") exitWith {_cached};

private _entries = [];
private _paths = (allTurrets [_veh, false]) + [[-1]];
{
    private _path = _x;
    private _mags = _veh magazinesTurret _path;
    {
        private _weapon = _x;
        private _wcfg = configFile >> "CfgWeapons" >> _weapon;
        private _compatible = (compatibleMagazines _weapon) apply {toLower _x};
        private _mag = _mags param [_mags findIf {(toLower _x) in _compatible}, ""];
        if (_mag isEqualTo "") then { continue };

        private _ammo = getText (configFile >> "CfgMagazines" >> _mag >> "ammo");
        private _acfg = configFile >> "CfgAmmo" >> _ammo;
        private _sim = toLower getText (_acfg >> "simulation");

        // The weapon's own reach: the longest and shortest of its fire modes,
        // and a missile's own lock distance where it says one.
        private _max = 0;
        private _min = 1e9;
        private _reload = 1e9;
        {
            private _m = [_wcfg >> _x, _wcfg] select (_x isEqualTo "this");
            _max = _max max getNumber (_m >> "maxRange");
            _min = _min min getNumber (_m >> "minRange");
            _reload = _reload min ([getNumber (_m >> "reloadTime"), 1e9] select (getNumber (_m >> "reloadTime") <= 0));
        } forEach getArray (_wcfg >> "modes");
        _max = _max max getNumber (_acfg >> "missileLockMaxDistance");
        if (_min > 1e8) then { _min = 0 };

        private _air = getNumber (_acfg >> "airLock") >= 1;
        private _missile = _sim in ["shotmissile", "shotrocket"];
        private _guided = _missile && {getNumber (_acfg >> "maneuvrability") > 0 || {getNumber (_acfg >> "manualControl") > 0}};
        private _role = switch (true) do {
            case (_air && _missile): { [ROLE_SHORT, ROLE_LONG] select (_max >= ADS_LONG_RANGE) };
            case (_air): { [ROLE_GUN, ROLE_CIWS] select (_reload <= ADS_CIWS_RELOAD) };
            case (_sim in ["shotshell", "shotmissile", "shotrocket", "shotsubmunitions"]): { ROLE_SURFACE };
            default { "" };
        };
        if (_role isEqualTo "") then { continue };

        private _fuse = getNumber (_acfg >> "indirectHitRange");
        if (_fuse <= 0) then { _fuse = ADS_FUSE_DEFAULT };
        _entries pushBack [_path, _weapon, _mag, _ammo, _sim, _max, _min, _role, _guided, _fuse];
    } forEach (_veh weaponsTurret _path);
} forEach _paths;

// An active radar, at its range against air.
private _radar = 0;
{
    if (getText (_x >> "componentType") isEqualTo "ActiveRadarSensorComponent") then {
        _radar = _radar max getNumber (_x >> "AirTarget" >> "maxRange");
    };
} forEach ("true" configClasses (configOf _veh >> "Components" >> "SensorsManagerComponent" >> "Components"));

private _roles = [];
{ _roles pushBackUnique (_x # 7) } forEach _entries;
if (_radar > 0) then { _roles pushBackUnique ROLE_SENSOR };

private _profile = [_entries, _radar, _roles];
GVAR(profiles) set [_cls, _profile];
_profile
