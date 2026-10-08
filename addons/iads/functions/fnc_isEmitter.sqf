#include "script_component.hpp"
/*
 * Author: JMSB
 * Does this class emit - that is, does it carry an ACTIVE radar?
 *
 * READ OFF THE CONFIG, NOT OFF A CLASS LIST. A list would need maintaining
 * every time a mission changes mods, and the answer is already written down in
 * the vehicle: the sensors overhaul puts an ActiveRadarSensorComponent inside
 * SensorsManagerComponent, and anything with one is a thing that can be seen
 * emitting.
 *
 * THE LEGACY FIELD IS THE SECOND HALF. radarType predates the sensor
 * components and plenty of hardware - including the vanilla search radars
 * jmfsb_airdefence picks its own batteries by - still declares only that. A
 * sweep that read only the modern structure would quietly skip the exact
 * radars this mod places itself.
 *
 * Cached by class: this is asked once per vehicle per scan and the answer
 * cannot change.
 *
 * Arguments:
 * 0: Class name <STRING>
 *
 * Return Value:
 * Emits <BOOL>
 *
 * Example:
 * private _yes = ["O_Radar_System_02_F"] call jmfsb_iads_fnc_isEmitter
 *
 * Public: No
 */

params [["_cls", "", [""]]];

if (_cls isEqualTo "") exitWith {false};

private _cached = GVAR(emitterCache) getOrDefault [_cls, -1];
if (_cached isEqualType true) exitWith {_cached};

private _cfg = configFile >> "CfgVehicles" >> _cls;
private _out = false;

private _sensors = _cfg >> "Components" >> "SensorsManagerComponent" >> "Components";
if (isClass _sensors) then {
    {
        private _name = configName _x;
        // Prefix, not equality: a vehicle with two sets declares
        // ActiveRadarSensorComponent and ActiveRadarSensorComponent1.
        if ((IADS_EMITTER_COMPONENTS findIf {(_name find _x) isEqualTo 0}) > -1) exitWith {_out = true};
    } forEach ("true" configClasses _sensors);
};

if (!_out && {getNumber (_cfg >> "radarType") > 0}) then {_out = true};

GVAR(emitterCache) set [_cls, _out];
_out
