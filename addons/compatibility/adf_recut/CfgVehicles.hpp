// ADF RE-CUT'S CALLSIGN ATTRIBUTE, ITS CONDITION REPAIRED (RPT 2026-10-06). The Abrams and ASLAV "Vehicle
// Callsigns" Eden attributes set condition = "_this isKindOf '...'" - SQF, where Eden expects its own condition
// keywords. Eden evaluates it with no _this and the RPT fills with "Undefined variable in expression: _this", once
// per class that inherits it. objectVehicle is Eden's keyword for "any vehicle"; the attribute only exists on
// these classes and their children, so it shows exactly where it did. The classes are restated as ADF Re-Cut
// writes them: the same parents, Attributes and PlatoonMarkings with no parent of their own.
class CfgVehicles {
    class I_MBT_03_cannon_F;
    class APC_Wheeled_03_base_F;

    class adfrc_abrams: I_MBT_03_cannon_F {
        class Attributes {
            class PlatoonMarkings {
                condition = "objectVehicle";
            };
        };
    };
    class adfrc_aslav_base: APC_Wheeled_03_base_F {
        class Attributes {
            class PlatoonMarkings {
                condition = "objectVehicle";
            };
        };
    };
    class adfrc_aslav_pc_base: adfrc_aslav_base {
        class Attributes {
            class PlatoonMarkings {
                condition = "objectVehicle";
            };
        };
    };
};
