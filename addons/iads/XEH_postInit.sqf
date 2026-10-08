#include "script_component.hpp"

if (!isServer) exitWith {};

// THE MODULE IS THE ENABLE. This file registers the two admin commands and
// nothing else - the state they read is declared in XEH_preInit, because module
// functions have already run by the time this does.

["iads", "state of the air defence net - emitters, who is radiating, tracks", {
    [] call FUNC(report)
}] call EFUNC(common,addDebugCommand);

// PHASE 0 OF THE PLAN, AS A COMMAND. Four of the design decisions rest on
// engine behaviour that cannot be read out of a config, and guessing at them is
// how a system ends up confidently backwards. This drives the experiment; the
// answers it cannot see - what the sensor display does - are printed as what to
// watch while it runs.
["iads.probe", "run the engine probes this design is gated on (P0-1..P0-4)", {
    params ["_args", "_caller"];
    [_args, _caller] call FUNC(probe)
}] call EFUNC(common,addDebugCommand);
