// WHY IS THIS AA NOT IN ALiVE'S PICKER - run in the debug console, any time.
//
// ALiVE_fnc_listFactionAAUnits puts a vehicle in the AA picker only if it
// passes FOUR gates in order. Three of them are readable off the config on
// this machine; the fourth (a turret that elevates past 65 degrees carrying
// ammunition flagged airLock) is only knowable in game, which is what this
// is for. Every vehicle of ours that 3DEN files under the AA subcategory is
// tested and the FIRST gate it fails is named.
//
// Paste, Exec, read the RPT (and the clipboard - the result is copied).

private _markers = ["_aa_", "_aa.", "aa_pod", "aapod", "anti_air", "anti-air", "antiair",
    "_sam_", "stinger", "igla", "avenger", "tunguska", "shilka", "zsu", "zu23", "zu_23",
    "zu-23", "praetorian", "patriot", "centurion", "pantsir", "tigris", "bardelas", "buk",
    "manpad", " tor ", "_tor_", "rapier", "starstreak", "strela", "roland", "2s6"];

private _gate = {
    params ["_c"];
    private _cfg = configFile >> "CfgVehicles" >> _c;
    private _dn = getText (_cfg >> "displayName");
    // 1 - the exclusions
    if (_c isKindOf "StaticMGWeapon" || {_c isKindOf "StaticATWeapon"}
        || {_c isKindOf "StaticGrenadeLauncher"} || {_c isKindOf "StaticMortar"}
        || {(toLower _c) find "radar" >= 0} || {(toLower _c) find "designator" >= 0}
        || {(toLower _dn) find "designator" >= 0}) exitWith {"1 EXCLUDED (static/radar/designator)"};
    if !(_c isKindOf "LandVehicle") exitWith {"2 NOT A LANDVEHICLE"};
    if (getNumber (_cfg >> "artilleryScanner") != 0) exitWith {"2 artilleryScanner"};
    // 3 - the name gate (ours to fix: see gen_us_factions display())
    private _hit = "";
    { if (((toLower _c) find _x >= 0) || {(toLower _dn) find _x >= 0}) exitWith {_hit = _x} } forEach _markers;
    if (_hit isEqualTo "") then {
        { if (_c isKindOf _x) exitWith {_hit = "base " + _x} } forEach
            ["APC_Tracked_01_AA_base_F", "APC_Tracked_02_AA_base_F", "SAM_System_01_base_F",
             "SAM_System_02_base_F", "SAM_System_04_base_F", "AAA_System_01_base_F"];
    };
    if (_hit isEqualTo "") exitWith {"3 NO NAME MARKER"};
    // 4 - the behavioural gate: a high turret with airLock ammunition
    private _elev = false;
    private _air = false;
    {
        if ((getNumber (_x >> "maxElev")) > 65) then {
            _elev = true;
            {
                private _w = _x;
                {
                    if (getNumber (configFile >> "CfgAmmo" >> getText (configFile >> "CfgMagazines" >> _x >> "ammo") >> "airLock") > 0) exitWith {_air = true};
                } forEach getArray (configFile >> "CfgWeapons" >> _w >> "magazines");
            } forEach getArray (_x >> "weapons");
        };
    } forEach ("true" configClasses (_cfg >> "Turrets"));
    if (!_elev) exitWith {"4 NO TURRET ABOVE 65 DEG"};
    if (!_air) exitWith {"4 NO airLock AMMO ON THAT TURRET"};
    format ["LISTED (via %1)", _hit]
};

private _rows = [];
private _fac = createHashMap;
{
    private _c = configName _x;
    private _f = getText (_x >> "faction");
    if (getNumber (_x >> "scope") == 2 && {(_f select [0, 5]) isEqualTo "jmfsb_"}
        && {getText (_x >> "editorSubcategory") isEqualTo "EdSubcat_AAs"}) then {
        private _verdict = [_c] call _gate;
        _rows pushBack format ["%1 | %2 | %3 | %4", _f, getText (_x >> "displayName"), _c, _verdict];
        if !(_verdict select [0, 6] isEqualTo "LISTED") then {
            _fac set [_f, (_fac getOrDefault [_f, 0]) + 1];
        };
    };
} forEach ("true" configClasses (configFile >> "CfgVehicles"));
_rows sort true;

private _out = ["=== 2040 AA vs ALiVE's picker ==="] + _rows;
if (!isNil "ALiVE_fnc_listFactionAAUnits") then {
    _out pushBack "";
    _out pushBack "=== what ALiVE itself returns per faction (side-wide, so bigger) ===";
    {
        private _f = configName _x;
        if ((_f select [0, 5]) isEqualTo "jmfsb_") then {
            private _aa = [_f] call ALiVE_fnc_listFactionAAUnits;
            private _mine = _aa select {((_x select 0) select [0, 5]) isEqualTo "jmfsb_"};
            _out pushBack format ["%1: %2 listed, %3 of them ours", _f, count _aa, count _mine];
        };
    } forEach ("true" configClasses (configFile >> "CfgFactionClasses"));
} else {
    _out pushBack "ALiVE not loaded - name-gate results above are still valid";
};
{ diag_log text _x } forEach _out;
copyToClipboard (_out joinString endl);
systemChat format ["AA diag: %1 vehicle(s) checked, %2 faction(s) with a failure - RPT + clipboard", count _rows, count _fac];
