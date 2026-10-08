#include "script_component.hpp"

ADDON = false;

// PREP'd AGAIN AT preInit, AND THIS IS NOT REDUNDANT.
//
// CBA's preStart dispatch runs inside `with uiNamespace do` - the mission
// namespace does not exist that early - and CBA_fnc_compileFunction stores each
// function in uiNamespace, then copies it into missionNamespace. That copy is
// thrown away when a mission loads. An addon that PREPs ONLY at preStart
// therefore has NO functions once a mission is running.
//
// That was the whole reason every function in these eleven addons came back
// "Undefined variable" in game while the config, the packing and the handlers
// were all provably correct. 73 of jmfsb's other 79 addons already do this;
// these were the exception because they were written from scratch in one go.
#include "XEH_PREP.hpp"

// THE ARSENAL FOLLOWS THE QUALIFICATIONS MID-MISSION. TAC//PAC raises this
// when a man's arsenal:<name> skill effects change, when an arsenal list is
// edited and when arsenalMode is changed; the arsenal is rebuilt for the role
// he holds. Before he has taken a role there is nothing to rebuild - taking
// one builds it (FUNC(setupPlayer)).
[QEGVAR(pac,arsenalChanged), {
    if (!hasInterface || {isNull player}) exitWith {};
    private _role = player getVariable ["YMF_role", ""];
    if (_role isEqualTo "") exitWith {};
    [_role] call FUNC(buildArsenal);
}] call CBA_fnc_addEventHandler;

ADDON = true;
