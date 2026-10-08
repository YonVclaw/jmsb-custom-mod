#include "..\script_component.hpp"
/*
 * Author: JMSB
 * The beat. Every Site refreshes its picture; Sites that share a link are one
 * group with ONE set of commitments, so two batteries never fire at one target
 * (F8); each group's threats are handed out (F3) while its automation is on;
 * radars are run (F5) and notices given (F9).
 *
 * Arguments: None
 *
 * Return Value: None
 *
 * Public: No
 */

if (!isServer) exitWith {};

// dead Sites leave
{
    private _site = GVAR(sites) get _x;
    if (((_site get "members") findIf {!isNull _x && {alive _x}}) < 0) then {
        INFO_1("Site %1 has no living members - removed",_x);
        GVAR(sites) deleteAt _x;
    };
} forEach (keys GVAR(sites));

// the groups: a link name joins Sites, no link is a Site on its own
private _groups = createHashMap;
{
    private _key = [_y get "link", _x] select ((_y get "link") isEqualTo "");
    (_groups getOrDefault [_key, [], true]) pushBack _y;
} forEach GVAR(sites);

{
    private _sites = _y;
    // ONE coordinator: the first Site's commitment maps are every member's
    private _lead = _sites # 0;
    { _x set ["committed", _lead get "committed"]; _x set ["busy", _lead get "busy"] } forEach _sites;

    { [_x] call FUNC(picture) } forEach _sites;
    { [_x, _sites] call FUNC(emcon) } forEach _sites;
    [_sites] call FUNC(assign);
    { [_x] call FUNC(notice) } forEach _sites;
} forEach _groups;
