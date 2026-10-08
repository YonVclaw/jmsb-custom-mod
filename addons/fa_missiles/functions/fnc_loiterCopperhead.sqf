#include "script_component.hpp"
/*
 * Author: YonV
 * XM1200 Copperhead loiter handover. Called for a Copperhead fired without an engine
 * lock: the round climbs to the loiter basket, orbits, and commits an
 * autonomous terminal attack on the first hostile vehicle that enters the
 * basket. Fired WITH a lock (LOBL) the inherited Titan simulation guides it
 * and this script never takes over. The basket is the firer's visible laser
 * spot if one exists, otherwise a point 2500 m along the launch bearing.
 *
 * Runs only where the projectile is local (steering is a local effect).
 *
 * Arguments:
 * 0: Projectile <OBJECT>
 * 1: Firer (vehicle) <OBJECT>
 *
 * Return Value:
 * None
 *
 * Public: No
 */

#define COPPERHEAD_LOITER_ALT    300  // orbit altitude above the basket (m)
#define COPPERHEAD_ORBIT_RADIUS  400  // orbit radius (m)
#define COPPERHEAD_CRUISE_SPEED  110  // transit / orbit speed (m/s)
#define COPPERHEAD_DIVE_SPEED    250  // terminal dive speed (m/s)
#define COPPERHEAD_SCAN_RADIUS  1000  // target acquisition radius around the basket (m)
#define COPPERHEAD_TURN_FACTOR  0.15  // velocity-lerp per 0.1 s tick

params [
    ["_proj", objNull, [objNull]],
    ["_unit", objNull, [objNull]]
];

// Give the engine a beat to assign a LOBL target before deciding.
[{
    params ["_proj", "_unit"];
    if (isNull _proj) exitWith {};
    if (!isNull missileTarget _proj) exitWith {}; // locked shot — engine guides

    private _dir = vectorDir _proj;
    private _center = (getPosASL _proj) vectorAdd [(_dir # 0) * 2500, (_dir # 1) * 2500, 0];
    private _laser = laserTarget _unit;
    if (!isNull _laser) then {
        _center = getPosASL _laser;
    };
    private _centerZ = (getTerrainHeightASL _center) + COPPERHEAD_LOITER_ALT;

    [{
        params ["_args", "_h"];
        _args params ["_proj", "_unit", "_center", "_centerZ", "_target", "_lastScan"];

        if (isNull _proj) exitWith {
            _h call CBA_fnc_removePerFrameHandler;
        };

        private _pos = getPosASL _proj;

        // Terminal: dive at the acquired target; rescan if it died mid-dive.
        if (!isNull _target && {!alive _target}) then {
            _target = objNull;
            _args set [4, _target];
        };

        // Acquisition sweep, 1 Hz: first hostile crewed vehicle in the basket.
        if (isNull _target && {CBA_missionTime - _lastScan > 1}) then {
            _args set [5, CBA_missionTime];
            private _side = side _unit;
            private _candidates = (ASLToAGL _center) nearEntities [["LandVehicle", "Air", "Ship"], COPPERHEAD_SCAN_RADIUS];
            _candidates = _candidates select {
                alive _x
                && _x != _unit
                && {[_side, side _x] call BIS_fnc_sideIsEnemy}
            };
            if (_candidates isNotEqualTo []) then {
                _candidates = _candidates apply {[_x distanceSqr (ASLToAGL _center), _x]};
                _candidates sort true; // nearest to the basket centre
                _target = _candidates # 0 # 1;
                _args set [4, _target];
            };
        };

        private _desired = if (isNull _target) then {
            private _toProj = _pos vectorDiff _center;
            _toProj set [2, 0];
            private _dist2D = vectorMagnitude _toProj;
            if (_dist2D > COPPERHEAD_ORBIT_RADIUS * 1.5) then {
                // transit / climb to the basket edge
                [_center # 0, _center # 1, _centerZ]
            } else {
                // orbit: aim at the tangent point ahead, hold radius + altitude
                private _radial = if (_dist2D < 1) then {[1, 0, 0]} else {vectorNormalized _toProj};
                private _tangent = [-(_radial # 1), _radial # 0, 0];
                (_center vectorAdd (_radial vectorMultiply COPPERHEAD_ORBIT_RADIUS))
                    vectorAdd (_tangent vectorMultiply 250)
                    vectorAdd [0, 0, _centerZ - (_center # 2)]
            }
        } else {
            aimPos _target
        };

        private _speed = [COPPERHEAD_CRUISE_SPEED, COPPERHEAD_DIVE_SPEED] select (!isNull _target);
        private _dirNew = vectorNormalized (
            (vectorNormalized velocity _proj) vectorAdd
            ((vectorNormalized (_desired vectorDiff _pos)) vectorMultiply COPPERHEAD_TURN_FACTOR)
        );
        _proj setVelocity (_dirNew vectorMultiply _speed);
        _proj setVectorDirAndUp [_dirNew, [0, 0, 1]];
    }, 0.1, [_proj, _unit, _center, _centerZ, objNull, 0]] call CBA_fnc_addPerFrameHandler;
}, [_proj, _unit], 0.7] call CBA_fnc_waitAndExecute;
