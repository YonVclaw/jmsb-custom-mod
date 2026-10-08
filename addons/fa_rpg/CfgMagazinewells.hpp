// The vanilla launchers already feed from these wells (launch_RPG32_F and
// launch_RPG7_F both set magazineWell[]), so registering here is enough —
// no launcher patch needed.
class CfgMagazineWells {
    class RPG32 {
        ADDON[] = {
            "FA_RPG32_PG32V2",
            "FA_RPG32_TBG32V2",
            "FA_RPG32_AB32"
        };
    };
    class RPG7 {
        ADDON[] = {
            "FA_RPG7_PG7VR2",
            "FA_RPG7_TBG7V2",
            "FA_RPG7_AB7"
        };
    };
};
