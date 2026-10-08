class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_SCRIPT(XEH_preInit));
    };
};

// The radar brings itself on the air when it is created - placed in Eden,
// spawned by Zeus or dropped by a script, all the same. Extended_Init rather
// than a class EventHandlers on the vehicle: the latter severs CBA's own XEH
// on anything that inherits it.
class Extended_Init_EventHandlers {
    class GVAR(radar) {
        class ADDON {
            init = QUOTE(call FUNC(radarInit));
        };
    };
    // The launcher does the same, and for the same reason - it builds its own
    // config from the settings and starts its own clock.
    //
    // A FRAME LATER, because it reads its SIDE off its crew. Init fires inside
    // createVehicle, before anything that spawned it by script has crewed it -
    // so jmfsb_moduleAntiShip's west or independent batteries read as civilian,
    // fell back to the OPFOR class side and registered as east. One frame on, a
    // spawned launcher is crewed; one placed in Eden or Zeus already was.
    class GVAR(launcher) {
        class ADDON {
            init = QUOTE([ARR_2(FUNC(launcherInit),_this)] call CBA_fnc_execNextFrame);
        };
    };
};
