class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_SCRIPT(XEH_preInit));
    };
};

// Extended_Init rather than a bare `class EventHandlers { init = ... }` on the
// vehicle: that form severs CBA's own extended handlers and the class stops
// supporting them entirely.
class Extended_Init_EventHandlers {
    class GVAR(vlsAA) {
        class ADDON {
            init = QUOTE(call FUNC(initSamShip));
        };
    };
};
