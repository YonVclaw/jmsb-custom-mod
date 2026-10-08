#include "script_component.hpp"
ADDON = false;
PREP_RECOMPILE_START;
PREP(init);
PREP(handle);
PREP(chute);
PREP(relay);
PREP(emp);
PREP(msmoke);
PREP(decoy);
PREP(ugs);
PREP(jammer);
PREP(enemiesNear);
PREP(notify);
PREP(jamUAV);
PREP_RECOMPILE_END;
ADDON = true;
