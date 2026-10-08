#include "script_component.hpp"
ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

GVAR(curators) = [];

["ModuleCurator_F", "InitPost", {
    params ["_curator"];
    _curator addEventHandler ["CuratorObjectPlaced", {
        params ["", "_object"];
        // AN AUTONOMOUS VEHICLE KEEPS ITS AI. ALiVE profiles what Zeus places
        // (the mission's zeusSpawn option), deletes the original, and hands
        // back a bare hull - its profiler blacklists UAV-AI crew, so the seat
        // comes back empty. The adapter's profileIgnore is the opt-out.
        // isUav covers every autonomous turret and drone - it is what makes
        // them UAV-terminal connectable - never a crewed truck.
        //
        // GUARDED, unlike jmfsb's copy. curator does not list the adapter in
        // requiredAddons, so with ALiVE absent its PBO is skipped and these
        // would be calls on a nil variable.
        if (getNumber (configOf _object >> "isUav") > 0
            && {!isNil QEFUNC(adapter_alive,profileIgnore)}) then {
            [_object] call EFUNC(adapter_alive,profileIgnore);
            // The crew's GROUP, not the men one by one: the adapter's group
            // path marks the group, its members and their vehicle in one go,
            // which is what protects a modded drone whose crew class is not
            // on ALiVE's own UAV-crew blacklist.
            [group ((crew _object) param [0, objNull])] call EFUNC(adapter_alive,profileIgnore);
        };
        [QGVAR(objectAdd), _object] call CBA_fnc_serverEvent;
    }];
    _curator addEventHandler ["CuratorGroupPlaced", {
        params ["", "_group"];
        [QGVAR(groupAdd), _group] call CBA_fnc_serverEvent;
    }];
}] call CBA_fnc_addClassEventHandler;

if (isServer) then {
    ["ModuleCurator_F", "InitPost", {
        params ["_curator"];
        {
            [QGVAR(objectAdd), _x] call CBA_fnc_localEvent;
        } forEach (allUnits + vehicles);
    }] call CBA_fnc_addClassEventHandler;

    [QGVAR(objectAdd), {
        params ["_object"];
        {
            _x addCuratorEditableObjects [[_object], true];
        } forEach allCurators;
    }] call CBA_fnc_addEventHandler;

    [QGVAR(groupAdd), {
        params ["_group"];
        {
            [QGVAR(objectAdd), _x] call CBA_fnc_localEvent;
        } forEach units _group;
    }] call CBA_fnc_addEventHandler;

    // Create curator on demand
    [QGVAR(zeusAssign), {
        params ["_unit"];
        if !(isPlayer _unit) exitWith {};

        INFO_1("Assigning Zeus to '%1'",_unit);

        private _curatorModule = [_unit] call FUNC(getFreeCuratorModule);
        unassignCurator getAssignedCuratorLogic _unit;

        // Curator unassign can take a moment, add delay. A plain delayed
        // call - the old waitUntilAndExecute form used {} as the condition,
        // which returns Nothing and threw a type error every frame for the
        // whole five seconds; the assignment only ever happened because the
        // timeout branch fired.
        [{
            params ["_unit", "_curatorModule"];

            _unit assignCurator _curatorModule;

            [QGVAR(zeusAssigned), _curatorModule, _unit] call CBA_fnc_targetEvent;
        }, [_unit, _curatorModule], 5] call CBA_fnc_waitAndExecute;

    }] call CBA_fnc_addEventHandler;

    // Unassign curator on demand
    [QGVAR(zeusUnassign), {
        params ["_unit"];
        if !(isPlayer _unit) exitWith {};

        INFO_1("Unassigning Zeus from '%1'",_unit);

        private _curatorModule = getAssignedCuratorLogic _unit;
        if (_curatorModule isEqualTo objNull) exitWith {};
        unassignCurator _curatorModule;
    }] call CBA_fnc_addEventHandler;

    // Activate Zeus addons
    [QGVAR(zeusActivateAddons), {
        params ["_curatorModule", "_addons"];

        INFO_1("Activating curator addons - '%1'",_curatorModule);

        _curatorModule addCuratorAddons _addons;
    }] call CBA_fnc_addEventHandler;
};

if (hasInterface) then {
    [QGVAR(zeusAssigned), {
        params ["_curatorModule"];

        INFO_1("Assigned Curator '%1'",_curatorModule);

        private _allAddons = ("true" configClasses (configFile >> "CfgPatches")) apply {configName _x};
        [QGVAR(zeusActivateAddons), [_curatorModule, _allAddons]] call CBA_fnc_serverEvent;

        if !(_curatorModule getVariable [QGVAR(drawCuratorLocations), false]) then {
            _curatorModule setVariable [QGVAR(drawCuratorLocations), true];
            [_curatorModule] call BIS_fnc_drawCuratorLocations;
        };
    }] call CBA_fnc_addEventHandler;
};

ADDON = true;
