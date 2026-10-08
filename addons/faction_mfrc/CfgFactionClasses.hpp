// FOUR THEATRES, ONE FORCE. The Multi-Functional Reconnaissance Company is
// the players' own faction - four camo variants of one company, not four
// different units. A mission picks the one that matches the map.
//
// BUILT FROM CTRG, NOT OVER IT. BLU_CTRG_F is left exactly as its mod ships
// it (see docs/FACTIONS.md); this is new classes beside it, so both exist and
// nothing anybody else depends on changes.
//
// THE ONLY TIER 4 ON BLUE. Everything else blue tops out at tier 3 - peer+ is
// depth and mass, and only the players get it here.

class CfgFactionClasses {
    class NO_CATEGORY;

    class GVAR(tna): NO_CATEGORY {
        displayName = "2040 MFRC (Tropical)";
        author = QAUTHOR;
        side = 1;
        priority = 1;
        icon = "\A3\Data_F\Flags\flag_NATO_CO.paa";
        flag = "\A3\Data_F\Flags\flag_NATO_CO.paa";
    };

    class GVAR(ocp): NO_CATEGORY {
        displayName = "2040 MFRC (Arid)";
        author = QAUTHOR;
        side = 1;
        priority = 1;
        icon = "\A3\Data_F\Flags\flag_NATO_CO.paa";
        flag = "\A3\Data_F\Flags\flag_NATO_CO.paa";
    };

    class GVAR(wdl): NO_CATEGORY {
        displayName = "2040 MFRC (Woodland)";
        author = QAUTHOR;
        side = 1;
        priority = 1;
        icon = "\A3\Data_F\Flags\flag_NATO_CO.paa";
        flag = "\A3\Data_F\Flags\flag_NATO_CO.paa";
    };

    class GVAR(mtp): NO_CATEGORY {
        displayName = "2040 MFRC (Desert)";
        author = QAUTHOR;
        side = 1;
        priority = 1;
        icon = "\A3\Data_F\Flags\flag_NATO_CO.paa";
        flag = "\A3\Data_F\Flags\flag_NATO_CO.paa";
    };

};
