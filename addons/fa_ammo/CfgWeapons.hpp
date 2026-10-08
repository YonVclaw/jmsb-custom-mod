// THE NAVID TAKES THE FA BELTS. The base game gives the MMG_01 no magazine
// well - just magazines[] = {"150Rnd_93x64_Mag"} - and CBA JAM has no 9.3x64
// well either, so the Type40 belt (CfgMagazines.hpp) would sit in the arsenal
// and never chamber. A well of our own goes on the gun; gen_fa_tiers puts
// the tier belts in that well. `=` not `+=`: there is nothing to add to, and
// nobody else's well to wipe.
class CfgWeapons {
    class Rifle_Long_Base_F;
    class MMG_01_base_F: Rifle_Long_Base_F {
        magazineWell[] = {"FA_Navid_93x64"};
    };
};
