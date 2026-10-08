// ONE FACTION, ONE CAMO. The 1st JMSB is the players' own faction: a company
// in OCP whatever the map (user, 2026-10-08: "only one camo ocp"). It used to
// declare four theatre variants of itself; a mission that needs the scout now
// places this one.
//
// BUILT FROM CTRG, NOT OVER IT. BLU_CTRG_F is left exactly as its mod ships
// it (see docs/FACTIONS.md); this is new classes beside it, so both exist and
// nothing anybody else depends on changes.
//
// THE ONLY TIER 4 ON BLUE. Everything else blue tops out at tier 3 - peer+ is
// depth and mass, and only the players get it here.

class CfgFactionClasses {
    class NO_CATEGORY;

    class GVAR(ocp): NO_CATEGORY {
        displayName = "2040 1st JMSB";
        author = QAUTHOR;
        side = 1;
        priority = 1;
        icon = "\A3\Data_F\Flags\flag_NATO_CO.paa";
        flag = "\A3\Data_F\Flags\flag_NATO_CO.paa";
    };
};
