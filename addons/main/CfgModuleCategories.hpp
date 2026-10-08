class CfgFactionClasses {
    class NO_CATEGORY;
    class PREFIX: NO_CATEGORY {
        displayName = JMFSB_CATEGORY;
    };

    // WHERE EVERY JMFSB MODULE LIVES IN EDEN. Every module in this mod already
    // claimed category "jmfsb_modules" or "jmfsb_ambient_modules" and NEITHER
    // was ever defined - a module category is only a string, so nothing
    // complained and the modules filed themselves under a category with no
    // name. One category, so there is one place to look.
    class DOUBLES(PREFIX,modules): NO_CATEGORY {
        displayName = JMFSB_CATEGORY;
    };
};

class CfgVehicleClasses {
    class PREFIX##_Vehicles {
        displayName = JMFSB_CATEGORY;
    };
};
