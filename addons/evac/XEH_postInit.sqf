#include "script_component.hpp"

// ACM BRINGS ITS OWN EVACUATION - ACM_evacuation, litters and all - so with it
// loaded this system stands down entirely (user, 2026-10-08: "with acm loaded
// we need to disable our medivac system"): no server handler, no casualty
// clone, and FUNC(canConvert) keeps the action off the menu. The setting
// stays visible; it has nothing to switch on.
if (missionNamespace getVariable [QEGVAR(patches,usesACM), false]) exitWith {
    INFO("ACM loaded - medic evac stands down");
};


// --- server: build the injured AI casualty clone + heal the player onto the medic
// Runs on the server, which can read the casualty's ACE medical vars (they are all
// broadcast) and owns the AI it creates.
if (isServer) then {
    [QGVAR(evac), {
        params ["_medic", "_casualty"];
        if (isNull _casualty) exitWith {};

        // -- snapshot the casualty's injuries so the clone matches exactly --
        private _hitPoints = ["HitHead", "HitChest", "HitLeftArm", "HitRightArm", "HitLeftLeg", "HitRightLeg"];
        private _hits = _hitPoints apply { [_x, _casualty getHitPointDamage _x] };

        // The full ACE injury surface (same set fullHealLocal resets). openWounds /
        // bandaged / stitched are hashMaps - deep-copied below so the clone never
        // shares a reference with the casualty.
        private _medVars = [
            "ace_medical_pain",
            "ace_medical_painSuppress",
            "ace_medical_inPain",
            "ace_medical_bloodVolume",
            "ace_medical_bloodPressure",
            "ace_medical_heartRate",
            "ace_medical_peripheralResistance",
            "ace_medical_spo2",
            "ace_medical_oxygenDemand",
            "ace_medical_woundBleeding",
            "ace_medical_openWounds",
            "ace_medical_bandagedWounds",
            "ace_medical_stitchedWounds",
            "ace_medical_tourniquets",
            "ace_medical_fractures",
            "ace_medical_bodyPartDamage",
            "ace_medical_isLimping",
            "ace_medical_inCardiacArrest",
            "ace_medical_ivBags"
        ];
        private _med = [];
        {
            private _val = _casualty getVariable _x;
            if (!isNil "_val") then {
                if (_val isEqualTypeAny [[], createHashMap]) then {
                    _val = +_val;
                };
                _med pushBack [_x, _val];
            };
        } forEach _medVars;

        // -- spawn the AI casualty clone at the downed spot, same loadout --
        private _type = typeOf _casualty;
        private _side = side (group _casualty);
        private _pos = getPosATL _casualty;
        private _dir = getDir _casualty;
        private _loadout = getUnitLoadout _casualty;

        private _ai = (createGroup [_side, true]) createUnit [_type, _pos, [], 0, "CAN_COLLIDE"];
        _ai setDir _dir;
        _ai setUnitLoadout _loadout;
        _ai setName (name _casualty);
        _ai setVariable [QGVAR(isCasualtyAI), true, true];
        // Per-unit override so ACE never auto-kills this AI just for being down.
        _ai setVariable ["ace_medical_statemachine_AIUnconsciousness", true, true];

        // -- apply the matching injuries + knock out, once ACE medical has settled --
        [{
            params ["_ai", "_med", "_hits"];
            if (isNull _ai) exitWith {};

            {
                _x params ["_hp", "_dmg"];
                _ai setHitPointDamage [_hp, _dmg];
            } forEach _hits;
            {
                _x params ["_var", "_val"];
                _ai setVariable [_var, _val, true];
            } forEach _med;

            [_ai, true] call ace_medical_fnc_setUnconscious;
            _ai disableAI "ALL";
            _ai setUnitPos "DOWN";
            _ai setBehaviour "CARELESS";
        }, [_ai, _med, _hits], 1] call CBA_fnc_waitAndExecute;

        // -- fully heal the actual player and place them on the medic --
        [_medic, _casualty] call ace_medical_treatment_fnc_fullHeal;
        _casualty setVariable [QGVAR(claimed), nil, true];

        private _rel = _medic getRelPos [1.5, 90];
        _casualty setPosATL [_rel select 0, _rel select 1, (getPosATL _medic) select 2];
    }] call CBA_fnc_addEventHandler;
};

// --- everywhere: a marked casualty AI can never stay awake --------------------
// ace_unconscious fires on every consciousness change with [_unit, _active] where
// _active is true when the unit goes DOWN and false when it wakes. If one of our
// casualties woke (treated to stable vitals, epinephrine, spontaneous), put it
// straight back under. Death is never blocked, so it is still fully mortal.
["ace_unconscious", {
    params ["_unit", "_active"];
    if (_active) exitWith {};
    if !(local _unit) exitWith {};
    if !(_unit getVariable [QGVAR(isCasualtyAI), false]) exitWith {};
    if !(alive _unit) exitWith {};

    [{
        params ["_unit"];
        if (alive _unit && {_unit getVariable [QGVAR(isCasualtyAI), false]}) then {
            [_unit, true] call ace_medical_fnc_setUnconscious;
        };
    }, [_unit], 0.1] call CBA_fnc_waitAndExecute;
}] call CBA_fnc_addEventHandler;
