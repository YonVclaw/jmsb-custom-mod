class CfgWeapons {
    // ACE OVERHEATING - THE MX FAMILY RUNS COOLER (user, 2026-08-29: "reduce the
    // cook off chance with the MX's, mass gain is acceptable").
    //
    // HOW COOK-OFF WORKS, read out of ace_overheating 3.21.2 (derapified from
    // the shipped PBO, 2026-08-29 - fnc_updateTemperature, fnc_calculateCooling,
    // fnc_updateAmmoTemperature, fnc_getWeaponData), so the numbers below are
    // checkable:
    //
    //   heating   temperature += energy / (barrelMass * 466)      per 3 rounds
    //   cooling   rate = (convection + radiation) * surface / (barrelMass * 466)
    //             where surface = barrelMass * 0.029427, so barrelMass CANCELS
    //   cook-off  the chambered round tracks the barrel and fires itself past
    //             180 C x ace_overheating_cookoffCoef (1 on this server)
    //
    // So barrel mass scales heat IN and leaves heat OUT alone: double it and
    // every round adds half the temperature, the sustained rate of fire that
    // holds the barrel under the ignition line doubles, and a magazine dumped
    // on full auto raises the barrel half as far. Lower temperature is also
    // less added dispersion and fewer jams - ACE reads them all off the one
    // number. This is the lever, not a random stat.
    //
    // WHERE ACE GETS barrelMass. fnc_getWeaponData reads
    // ace_overheating_barrelMass off the weapon FIRST, and only when that is
    // absent falls back to 0.55 x (WeaponSlotsInfo mass / 22) - inventory mass
    // over 40. The values below are 2 x that fallback as the base game ships
    // it (MXC 80, MX 100, MXM / SW / GL 120, Mk200 220, read from weapons_f).
    //
    // NO INVENTORY MASS IS CHANGED HERE, and the "mass gain" of the first
    // version never happened: it wrote WeaponSlotsInfo mass = 155 for the MX,
    // and ace_realisticweights - loaded on this server, and applied AFTER this
    // addon (the RPT's "Updating base class" order) - writes its own 79 over
    // it. With realistic weights the game's fallback would have been 79/40 =
    // 1.98, so the 5.0 below is 2.5 x what the rifle actually had, and the
    // carried weight is whatever the load order says, as it always was. A
    // server without realistic weights gets 2 x vanilla. Either way the
    // barrel mass is explicit and the load order cannot touch it.
#include "imported_CfgWeapons_decl.hpp"
    class arifle_MX_Base_F: Rifle_Base_F {};

    class arifle_MXC_F: arifle_MX_Base_F {
        ace_overheating_barrelMass = 4.0;            // vanilla fallback 80/40 = 2.0, x2
    };
    class arifle_MX_F: arifle_MX_Base_F {
        ace_overheating_barrelMass = 5.0;            // vanilla fallback 100/40 = 2.5, x2
    };
    class arifle_MXM_F: arifle_MX_Base_F {
        ace_overheating_barrelMass = 6.0;            // vanilla fallback 120/40 = 3.0, x2
    };
    class arifle_MX_SW_F: arifle_MX_Base_F {
        // The LMG, and the one that actually runs hot: belt-fed, 750 rpm, and
        // the only MX ACE lets swap a barrel. Its own 0.75 dispersion
        // coefficient and its clear-jam gesture are inherited from ACE's
        // config and are not restated here.
        ace_overheating_barrelMass = 6.0;            // vanilla fallback 120/40 = 3.0, x2
    };
    class arifle_MX_GL_F: arifle_MX_Base_F {         // vanilla parent is MX_Base_F, not MX_F
        ace_overheating_barrelMass = 6.0;            // vanilla fallback 120/40 = 3.0, x2
    };

    // Mk200 LMG. The previous author's x1.15 over an "assumed" 5.5 - the
    // assumption was right (vanilla mass 220, weapons_f\Machineguns\M200) -
    // brought to the same x2 rule as the MX family, because a belt-fed 6.5
    // that cooks off before the rifle beside it is the wrong way round.
    class LMG_Mk200_F: Rifle_Long_Base_F {
        ace_overheating_barrelMass = 11.0;           // vanilla fallback 220/40 = 5.5, x2
    };
#include "imported_CfgWeapons.hpp"
};
