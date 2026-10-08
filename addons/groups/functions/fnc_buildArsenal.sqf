#include "script_component.hpp"
/*
    File: fnc_buildArsenal.sqf
    Author: YonV
    Description: The player's ACE arsenal, built from scratch: the mission's
        Common_Arsenal, then the database's layers narrowest last - common,
        platoon, squad, then the ROLE SYSTEM (the role's own arsenal fields
        and its role_<class> document) and the SKILLS (one
        qual_<name> document per "arsenal:<name>" effect on the man's PAC
        skills).

        WHICH SYSTEM is the unit's choice, the PAC setting arsenalMode:
        "role" - the role decides, skills add nothing; "skills" - the skills
        decide and the role adds nothing beyond its loadout ("traits" is read
        the same way);
        "both" (the default) - both add. Anything else reads as "both".

        REBUILT, NOT PATCHED. Everything virtual is removed and the lot is
        added again, so a qualification taken away actually takes its gear
        out of the arsenal. Called by FUNC(setupPlayer) when a role is taken,
        and again whenever jmfsb_pac_arsenalChanged fires - a skill granted
        or removed mid-mission, an arsenal list edited, arsenalMode changed -
        so a man given a qualification in the field sees its gear the next
        time he opens the arsenal, with no respawn.

    Parameters:
        0: STRING - the role class
        1: HASHMAP - the role record (optional, read with FUNC(role) if absent)
        2: ARRAY - the role's default loadout for ACE's default-loadout list
           (optional; [] leaves that list alone)
    Returns:
        Nothing
*/
params [
    ["_desiredRole", "", [""]],
    ["_roleConfig", createHashMap, [createHashMap]],
    ["_defaultLoadout", [], [[]]]
];

if (!hasInterface || {isNull player}) exitWith {};
if (count _roleConfig isEqualTo 0) then {_roleConfig = [_desiredRole] call FUNC(role)};

private _mode = toLower ((missionNamespace getVariable [QEGVAR(pac,settings), createHashMap]) getOrDefault ["arsenalMode", "both"]);
if (_mode isEqualTo "traits") then {_mode = "skills"};
if !(_mode in ["role", "skills", "both"]) then {_mode = "both"};

// THE ROLE'S OWN FIELDS are the role system's - left out in "skills" mode.
private _useRole = _mode isNotEqualTo "skills";
private _useQuals = _mode isNotEqualTo "role";
private _weapons = [[], +(_roleConfig getOrDefault ["arsenalWeapons", []])] select _useRole;
private _magazines = [[], +(_roleConfig getOrDefault ["arsenalMagazines", []])] select _useRole;
private _items = [[], +(_roleConfig getOrDefault ["arsenalItems", []])] select _useRole;
private _backpacks = [[], +(_roleConfig getOrDefault ["arsenalBackpacks", []])] select _useRole;

//merge the shared Common_Arsenal (config\arsenal) with the role's own
//extra gear - any array named items* counts as items
private _arsenalSources = [missionConfigFile >> "Common_Arsenal"];
// THE ROLE'S OWN ARSENAL IS NOT A NAMED CLASS ANY MORE (user, 2026-09-09:
// "there is no fucking Arsenal_Wraith - you were supose to make it part of
// the role config, and part of the squad config, and part of the plt
// config"). A role's extra gear is its own arsenalWeapons/Magazines/Items/
// Backpacks above, and the document role_<class> below - derived from the
// role's id the way plt_ and sqd_ are, so there is nothing to point at and
// nothing to spell wrong.
{
    {
        private _name = toLower configName _x;
        switch (true) do {
            case (_name isEqualTo "weapons"): {_weapons append getArray _x};
            case (_name isEqualTo "magazines"): {_magazines append getArray _x};
            case (_name isEqualTo "backpacks"): {_backpacks append getArray _x};
            case (_name select [0,5] isEqualTo "items"): {_items append getArray _x};
        };
    } forEach configProperties [_x, "isArray _x", false];
} forEach _arsenalSources;

// THE DATABASE ADDS TO THE MISSION'S ARSENAL, it does not replace it - so a
// mission that ships config\arsenal keeps working and one that ships none
// gets everything from <unit>.arsenal. The common lists first, then the
// three narrower documents below.
if (!isNil "jmfsb_pac_fnc_cfgLists") then {
    private _fromDb = ["arsenal"] call jmfsb_pac_fnc_cfgLists;
    private _variants = ((missionNamespace getVariable ["jmfsb_pac_structure", createHashMap])
        getOrDefault ["arsenal", createHashMap]) getOrDefault ["variants", createHashMap];
    // FOUR LAYERS, NARROWEST LAST: common, the platoon's, the squad's,
    // then the role's own variant. The platoon and squad documents are
    // found by DERIVING their name from the ids - plt_<platoon> and
    // sqd_<squad>, upper case with anything else an underscore - so
    // adding one is creating a document and nothing else. The web manager
    // computes the same name with the same rule.
    private _fnc_slug = {
        params ["_s"];
        // Built as an array and joined once: concatenating in the loop
        // reallocates the string on every character.
        private _chars = [];
        // A RUN OF SEPARATORS IS ONE UNDERSCORE, and a leading run is
        // nothing at all. This used to write one underscore per character,
        // which agreed with the website only while no name held two
        // separators together: "JMFSB  6" was JMFSB_6 on the website and
        // JMFSB__6 here, so the game looked up a document nobody had
        // written and no error said so (2026-09-09). The website's rule is
        // preg_replace("/[^A-Z0-9]+/", "_") then trim("_") - this is that,
        // character by character.
        private _wasSep = true;
        {
            private _ok = (_x >= 48 && _x <= 57) || (_x >= 65 && _x <= 90);
            if (_ok) then {
                _chars pushBack _x;
                _wasSep = false;
            } else {
                if (!_wasSep) then {
                    _chars pushBack 95;
                    _wasSep = true;
                };
            };
        } forEach (toArray toUpper _s);
        private _out = toString _chars;
        // A trailing run left one underscore on the end - "1-1 SQD " must
        // not become a name that differs from the one the website wrote.
        while {count _out > 0 && {_out select [count _out - 1, 1] isEqualTo "_"}} do {
            _out = _out select [0, count _out - 1];
        };
        _out
    };

    private _pick = [_fromDb];

    // The squad is the player's group name; the platoon is whichever one
    // lists that squad. Both may be absent - a man outside the ORBAT just
    // gets the common arsenal.
    private _squad = toUpper groupId (group player);
    if (_squad isNotEqualTo "") then {
        private _sv = _variants getOrDefault ["sqd_" + ([_squad] call _fnc_slug), createHashMap];

        private _pltId = "";
        {
            _x params ["_pid", "", "", "", ["_squads", []]];
            if (_squads findIf {toUpper _x isEqualTo _squad} > -1) exitWith {_pltId = _pid};
        } forEach ((missionNamespace getVariable ["jmfsb_pac_structure", createHashMap])
            getOrDefault ["orbat", createHashMap] getOrDefault ["platoons", []]);

        if (_pltId isNotEqualTo "") then {
            private _pv = _variants getOrDefault ["plt_" + ([_pltId] call _fnc_slug), createHashMap];
            if (count _pv > 0) then {_pick pushBack _pv};
        };
        if (count _sv > 0) then {_pick pushBack _sv};
    };

    // AND THE ROLE'S OWN, narrowest of all: role_<class>, by the same slug
    // rule as the platoon's and the squad's.
    if (_useRole && _desiredRole isNotEqualTo "" && {_variants isEqualType createHashMap}) then {
        private _rv = _variants getOrDefault ["role_" + ([_desiredRole] call _fnc_slug), createHashMap];
        if (count _rv > 0) then {_pick pushBack _rv};
    };

    // AND THE QUALIFICATIONS, one layer each: qual_<name> for every
    // "arsenal:<name>" effect the man's PAC skills carry (jmfsb_pac_fnc_
    // applySkills keeps the list on him). Same slug rule as above, so
    // arsenal:marksman reads the document <unit>.arsenal.qual_MARKSMAN.
    if (_useQuals && {_variants isEqualType createHashMap}) then {
        {
            private _qv = _variants getOrDefault ["qual_" + ([_x] call _fnc_slug), createHashMap];
            if (count _qv > 0) then {_pick pushBack _qv};
        } forEach (player getVariable [QEGVAR(pac,arsenalQuals), []]);
    };
    {
        private _lists = _x;
        {
            private _name = toLower _x;
            private _vals = _lists get _x;
            if (_vals isEqualType []) then {
                switch (true) do {
                    case (_name isEqualTo "weapons"): {_weapons append _vals};
                    case (_name isEqualTo "magazines"): {_magazines append _vals};
                    case (_name isEqualTo "backpacks"): {_backpacks append _vals};
                    case (_name select [0,5] isEqualTo "items"): {_items append _vals};
                };
            };
        } forEach (keys _lists);
    } forEach _pick;
};

[player,true,false] call ace_arsenal_fnc_removeVirtualItems;
{
    [player,_x,false] call ace_arsenal_fnc_addVirtualItems;
} forEach [_weapons,_magazines,_items,_backpacks];
if (_defaultLoadout isNotEqualTo []) then {
    private _roleName = _roleConfig getOrDefault ["name", _desiredRole];
    [_roleName,_defaultLoadout] call ace_arsenal_fnc_addDefaultLoadout;
};
