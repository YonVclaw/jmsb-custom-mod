#include "script_component.hpp"

// PROBE - macro-free on purpose. Every jmfsb_* addon that came out of the
// mission logged nothing at all, and the question "did preStart even run"
// cannot be answered by a line that itself depends on the functions preStart
// is supposed to compile.
diag_log text "[JMFSB-PROBE] jmfsb_diag XEH_preStart ran";
#include "XEH_PREP.hpp"

diag_log text format ["[JMFSB-PROBE] after PREP, jmfsb_diag_fnc_info is %1", isNil "jmfsb_diag_fnc_info"];
