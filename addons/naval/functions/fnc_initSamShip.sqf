#include "script_component.hpp"
/* ----------------------------------------------------------------------------
Function: jmfsb_naval_fnc_initSamShip

Description:
    Puts a SAM ship on its side's sensor network.

    A 16 km missile is worth nothing to a launcher that can only see 4 km. The
    reach is real, but reaching it means being TOLD where the target is - by the
    destroyer's own radar, by an AWACS, by a recon drone - rather than finding it
    alone. Without the datalink the ship engages what wanders into its own
    sensors and the extra range is decoration.

    It reports as well as receives: a ship is a large radar in its own right, and
    what it sees is worth passing to everything else on its side.

Parameters (Extended_Init EH): 0: the ship

Author:
    JMSB
---------------------------------------------------------------------------- */
params ["_veh"];

if (!local _veh) exitWith {};

[_veh] call EFUNC(common,setDatalink);
