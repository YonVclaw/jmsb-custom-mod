#include "script_component.hpp"
/* ----------------------------------------------------------------------------
Function: jmfsb_tacpad_apps_fnc_simplexProvider

Description:
    Registers Simplex Support Services as a TAC//SUPPORT provider.

    ONE BOARD, NOT TWO. DIVINER rebuilt TAC//SUPPORT as a board over Simplex
    because ALiVE's combat support had gone and Simplex was what was left. Both
    exist here, and two SUPPORT apps would be a worse answer than either. So
    Simplex arrives the way jmfsb's own CAS module arrives: as three pieces of
    code under a prefix in EGVAR(adapter_alive,providers), merged into
    EFUNC(adapter_alive,supportAssets) alongside ALiVE's ATO and NEO assets.

    THE SEAM RUNS BOTH WAYS. This file names sss_* symbols and no ALiVE symbol;
    the adapter names ALiVE symbols and no sss_* one. Neither learns the other's
    vocabulary, which is the whole point of the registry - see
    EFUNC(adapter_alive,supportAssets) for the reasoning.

    TASKING HANDS OFF TO SIMPLEX'S OWN GUI. Simplex's request flow is a screen
    of its own with its own rules about what may be asked for; reimplementing it
    against the adapter's task vocabulary would be a second implementation of
    somebody else's mod. Pressing a Simplex row on the board opens that screen.

Parameters:
    None.

Returns:
    Nothing.

Author:
    YonV
---------------------------------------------------------------------------- */
if (!hasInterface) exitWith {};
if (isNil "sss_common_fnc_getEntities") exitWith {
    INFO("Simplex is not loaded - no support provider registered");
};

// Read-modify-write, exactly as EFUNC(cas,XEH_postInit) does it: the registry is
// shared and a provider that replaced the hashmap would drop the others.
private _providers = missionNamespace getVariable [QEGVAR(adapter_alive,providers), createHashMap];

_providers set ["sss", [
    // --- list ---------------------------------------------------------------
    // Rows are [id, type, callsign, platform, status, ordnance, gunCount].
    // The id carries the provider's prefix, which is how a press routes back
    // here: "sss:<service>:<index>".
    {
        private _rows = [];
        private _unit = call CBA_fnc_currentUnit;
        {
            private _service = _x;
            {
                _rows pushBack [
                    format ["sss:%1:%2", _service, _forEachIndex],
                    "cas",
                    _x getVariable ["sss_callsign", "UNNAMED"],
                    toUpper _service,
                    ["idle", "busy"] select ((_x getVariable ["sss_cooldownTimer", 0]) > 0),
                    "",
                    0
                ];
            } forEach ([_unit, _service] call sss_common_fnc_getEntities);
        } forEach (keys (missionNamespace getVariable ["sss_common_services", createHashMap]));
        _rows
    },

    // --- task ---------------------------------------------------------------
    // [assetId, task, point, params] -> [ok, text]. The board's own verbs do not
    // map onto Simplex's, so this opens Simplex's request screen for the entity
    // that was pressed and lets it ask its own questions.
    {
        params [["_assetId", "", [""]]];
        private _parts = _assetId splitString ":";
        private _service = _parts param [1, ""];
        private _idx = parseNumber (_parts param [2, "-1"]);
        private _unit = call CBA_fnc_currentUnit;
        private _entities = [_unit, _service] call sss_common_fnc_getEntities;
        private _entity = _entities param [_idx, objNull];
        if (isNull _entity) exitWith {[false, "that Simplex asset is no longer available"]};

        [ARR_3(_service,_entity,false)] call sss_common_fnc_openGUI;
        [true, "Simplex request screen opened"]
    },

    // --- sitrep -------------------------------------------------------------
    // Simplex publishes a cooldown and nothing else worth reading back, so the
    // honest answer is the cooldown.
    {
        params [["_assetId", "", [""]]];
        private _parts = _assetId splitString ":";
        private _service = _parts param [1, ""];
        private _idx = parseNumber (_parts param [2, "-1"]);
        private _unit = call CBA_fnc_currentUnit;
        private _entity = ([_unit, _service] call sss_common_fnc_getEntities) param [_idx, objNull];
        if (isNull _entity) exitWith {[false, "no such asset"]};

        private _cd = _entity getVariable ["sss_cooldownTimer", 0];
        if (_cd > 0) exitWith {[true, format ["%1 rearming - %2s", toUpper _service, round _cd]]};
        [true, format ["%1 on call", toUpper _service]]
    }
]];

missionNamespace setVariable [QEGVAR(adapter_alive,providers), _providers];
INFO("Simplex registered as a TAC//SUPPORT provider");
