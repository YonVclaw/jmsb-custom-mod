#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// THE LEDGER OF PLACED MODULES. One entry per module logic, in placement
// order, and the index into this IS the asset id the support page sends back -
// so a request can be routed to the right airframe without the app ever
// holding an object reference across the network.
//
// It is never compacted. A module that is deleted mid-mission leaves a null in
// place rather than shuffling every id after it onto a different aircraft.
GVAR(entities) = [];

ADDON = true;
