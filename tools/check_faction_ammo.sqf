// 2040 FACTION AMMO CHECK - run in the debug console with the load order the
// factions are meant for. For every man of every faction whose name starts
// "2040", asks the game which magazines his weapons take (wells included, via
// compatibleMagazines) and logs to the RPT:
//
//   FAMMO;MISFIT;faction;class;magazine;weapons    a magazine none of his weapons takes
//   FAMMO;NOTFA;faction;class;magazine;weapon;fa   a non-FA magazine where FA rounds fit (fa: the FA options)
//   FAMMO;DONE;men;misfits;notfa
//
// Pull it out of the RPT with: grep "FAMMO;" <rpt>

[] spawn {
    private _factions = ("(getText (_x >> 'displayName')) find '2040' == 0" configClasses (configFile >> "CfgFactionClasses")) apply {toLower configName _x};
    // plain ammo by design (user, 2026-10-01): "these do not need fa ammo"
    _factions = _factions - ["jmfsb_faction_gen", "jmfsb_faction_himf"];
    private _men = 0;
    private _misfit = 0;
    private _notfa = 0;
    private _compat = createHashMap;

    {
        private _cfg = _x;
        private _fac = toLower getText (_cfg >> "faction");
        if (getNumber (_cfg >> "scope") > 0 && {_fac in _factions} && {configName _cfg isKindOf "CAManBase"}) then {
            _men = _men + 1;
            private _cls = configName _cfg;
            private _weapons = (getArray (_cfg >> "weapons")) - ["Throw", "Put"];
            // Throw and Put take grenades, smoke, chemlights and explosives - checked with the rest
            private _all = [];
            {
                private _w = _x;
                private _c = _compat getOrDefault [toLower _w, []];
                if (_c isEqualTo []) then {
                    _c = (compatibleMagazines _w) apply {toLower _x};
                    _compat set [toLower _w, _c];
                };
                _all append _c;
            } forEach (_weapons + ["Throw", "Put"]);
            {
                private _m = _x;
                private _lm = toLower _m;
                if !(_lm in _all) then {
                    diag_log text format ["FAMMO;MISFIT;%1;%2;%3;%4", _fac, _cls, _m, _weapons];
                    _misfit = _misfit + 1;
                } else {
                    if ((_lm find "fa_") != 0) then {
                        {
                            private _w = _x;
                            private _c = _compat getOrDefault [toLower _w, []];
                            if (_lm in _c) then {
                                private _fa = _c select {(_x find "fa_") == 0};
                                if (_fa isNotEqualTo []) then {
                                    diag_log text format ["FAMMO;NOTFA;%1;%2;%3;%4;%5", _fac, _cls, _m, _w, _fa];
                                    _notfa = _notfa + 1;
                                };
                            };
                        } forEach _weapons;
                    };
                };
            } forEach ((getArray (_cfg >> "magazines")) arrayIntersect (getArray (_cfg >> "magazines")));
        };
    } forEach ("true" configClasses (configFile >> "CfgVehicles"));

    diag_log text format ["FAMMO;DONE;%1;%2;%3", _men, _misfit, _notfa];
    systemChat format ["2040 AMMO CHECK DONE: %1 men, %2 magazines fit no weapon, %3 could be FA - grep the RPT for FAMMO", _men, _misfit, _notfa];
};
