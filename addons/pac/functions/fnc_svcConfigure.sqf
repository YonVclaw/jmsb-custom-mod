#include "script_component.hpp"
/* ----------------------------------------------------------------------------
Function: jmfsb_pac_fnc_svcConfigure

Description:
    Hands the pacdb service's address and key to the ghostd_pacdb extension
    - from the two CBA server settings (initSettings.inc.sqf), which a
    rented game server can take where it cannot take a file. With the URL
    setting empty nothing is handed over and the extension uses what it
    finds for itself: GHOSTD_PACDB_URL / GHOSTD_PACDB_KEY in the server's
    environment, then pacdb.json in the server's root.

    Server only, once, at boot step 3 before the first request.

Parameters:
    None

Returns:
    Where the address came from: "setting", "environment" (nothing handed
    over), or "" when the extension did not take it <STRING>

Author:
    YonV
---------------------------------------------------------------------------- */

if (!isServer) exitWith {""};

private _url = missionNamespace getVariable [QGVAR(serviceUrl), ""];
private _key = missionNamespace getVariable [QGVAR(serviceKey), ""];
if !(_url isEqualType "") then {_url = ""};
if !(_key isEqualType "") then {_key = ""};
_url = trim _url;
_key = trim _key;

// PASTED WITH ITS QUOTES. The Atlas string is shown in quotes nearly everywhere
// it is copied from, and an edit box keeps them - the extension then sees
// "mongodb+srv://..., which is not a Mongo address, and tries it as a web one
// (the user's .rpt, 2026-10-08: "An invalid request URI was provided").
{
    private _s = _x;
    if (count _s > 1 && {(_s select [0, 1]) in ["""", "'"]} && {(_s select [count _s - 1, 1]) isEqualTo (_s select [0, 1])}) then {
        _s = trim (_s select [1, count _s - 2]);
    };
    if (_forEachIndex isEqualTo 0) then {_url = _s} else {_key = _s};
} forEach [_url, _key];

if (_url isEqualTo "") exitWith {"environment"};

// THE MASKED STRING IS NOT THE STRING. Every place the address is shown -
// this log, the website, a chat - prints the password as "..." or an ellipsis,
// and that form gets copied into the setting (the user's profile, 2026-10-08:
// "jmsb_pac:...@cluster0" - Atlas answered "Unable to authenticate"). It is
// refused here with a plain reason, and the extension falls through to
// GHOSTD_PACDB_URL or pacdb.json, which hold the real one.
if ((_url find ":...@") >= 0 || {(_url find (toString [8230])) >= 0}) exitWith {
    ERROR("the Database setting holds the MASKED connection string (the password shows as '...'). Paste the real string from the key file, or leave the setting empty and put pacdb.json in the server's root - ignoring the setting");
    "environment"
};

("ghostd_pacdb" callExtension ["configure", [_url, _key]]) params [["_text", "", [""]], "", ["_err", 0, [0]]];
if (_err isNotEqualTo 0 || _text isNotEqualTo "ok") exitWith {
    WARNING_2("pacdb extension did not take the service address from the CBA setting (error %1, said '%2') - is ghostd_pacdb_x64.dll / .so in the mod folder or the server's Arma root?",_err,_text);
    if (_err isNotEqualTo 0) then {GVAR(svcMissing) = true};
    ""
};

private _shown = if ((_url find "@") > 0) then {(_url select [0, (_url find "://") + 3]) + "..." + (_url select [_url find "@"])} else {_url};
INFO_1("database address from the CBA setting: %1",_shown);
"setting"
