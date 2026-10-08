class XtdGearModels {
    class CfgWeapons {
        // --- EF vests ---
        class GVAR(AAV) {
            label = "AAV";
            options[] = {"camo", "type", "style"};
            class camo {
                alwaysSelectable = 1;
                values[] = {"Black", "Coy", "Olive", "Desert", "Tropic", "Woodland", "MTP"};
                class Black {
                    label = "Black";
                    image = "z\aceax\addons\gearinfo\data\camo\blk.paa";
                };
                class Coy {
                    label = "Coyote";
                    image = "z\aceax\addons\gearinfo\data\camo\khk.paa";
                };
                class Olive {
                    label = "Olive";
                    image = "z\aceax\addons\gearinfo\data\camo\sage.paa";
                };
                class Desert {
                    label = "Desert";
                    image = "z\aceax\addons\gearinfo\data\camo\mcd.paa";
                };
                class Tropic {
                    label = "Tropic";
                    image = "z\aceax\addons\gearinfo\data\camo\mct.paa";
                };
                class Woodland {
                    label = "Woodland";
                    image = "z\aceax\addons\gearinfo\data\camo\mcw.paa";
                };
                class MTP {
                    label = "OCP";
                    image = "z\aceax\addons\gearinfo\data\camo\mtp.paa";
                };
            };
            class type {
                alwaysSelectable = 1;
                values[] = {"Base", "Diver", "DiverNoReb", "Rifleman", "Sailor", "Scout", "Support", "TL"};
                class Base {
                    label = "Base";
                };
                class Diver {
                    label = "Diver";
                };
                class DiverNoReb {
                    label = "Diver NR";
                };
                class Rifleman {
                    label = "Rifle";
                };
                class Sailor {
                    label = "Sailor";
                };
                class Scout {
                    label = "Scout";
                };
                class Support {
                    label = "Supp";
                };
                class TL {
                    label = "TL";
                };
            };
            class style {
                alwaysSelectable = 1;
                values[] = {"Std", "Alt"};
                class Std {
                    label = "Std";
                };
                class Alt {
                    label = "Alt";
                };
            };
        };
        class GVAR(CCR) {
            label = "CCR";
            options[] = {"camo", "type", "style"};
            class camo {
                alwaysSelectable = 1;
                values[] = {"Black", "Coy", "Olive", "Desert", "Tropic", "Woodland", "MTP"};
                class Black {
                    label = "Black";
                    image = "z\aceax\addons\gearinfo\data\camo\blk.paa";
                };
                class Coy {
                    label = "Coyote";
                    image = "z\aceax\addons\gearinfo\data\camo\khk.paa";
                };
                class Olive {
                    label = "Olive";
                    image = "z\aceax\addons\gearinfo\data\camo\sage.paa";
                };
                class Desert {
                    label = "Desert";
                    image = "z\aceax\addons\gearinfo\data\camo\mcd.paa";
                };
                class Tropic {
                    label = "Tropic";
                    image = "z\aceax\addons\gearinfo\data\camo\mct.paa";
                };
                class Woodland {
                    label = "Woodland";
                    image = "z\aceax\addons\gearinfo\data\camo\mcw.paa";
                };
                class MTP {
                    label = "OCP";
                    image = "z\aceax\addons\gearinfo\data\camo\mtp.paa";
                };
            };
            class type {
                alwaysSelectable = 1;
                values[] = {"Rifleman", "Scout", "Support", "TL"};
                class Rifleman {
                    label = "Rifle";
                };
                class Scout {
                    label = "Scout";
                };
                class Support {
                    label = "Supp";
                };
                class TL {
                    label = "TL";
                };
            };
            class style {
                alwaysSelectable = 1;
                values[] = {"Std", "Alt"};
                class Std {
                    label = "Std";
                };
                class Alt {
                    label = "Alt";
                };
            };
        };
        // --- Plate carriers ---
        class GVAR(PlateCarrier1) {
            label = "PlateCarrier1";
            options[] = {"camo"};
            class camo {
                alwaysSelectable = 1;
                values[] = {"Black", "Coyote", "Khaki", "Olive", "Ranger", "RangerNF", "Desert", "Tropic", "Woodland", "MTP", "OCP", "Multicam", "MC_Wdl", "MC_Snow"};
                class OCP {
                    label = "OCP";
                    image = "z\aceax\addons\gearinfo\data\camo\ocp.paa";
                };
                class Multicam {
                    label = "Multicam";
                    image = "z\aceax\addons\gearinfo\data\camo\mc.paa";
                };
                class MC_Wdl {
                    label = "MC-Wdl";
                    image = "z\aceax\addons\gearinfo\data\camo\mcw.paa";
                };
                class MC_Snow {
                    label = "MC-Snow";
                    image = "z\aceax\addons\gearinfo\data\camo\wht.paa";
                };
                class Black {
                    label = "Black";
                    image = "z\aceax\addons\gearinfo\data\camo\blk.paa";
                };
                class Coyote {
                    label = "Coyote";
                    image = "z\aceax\addons\gearinfo\data\camo\khk.paa";
                };
                class Khaki {
                    label = "Khaki";
                    image = "z\aceax\addons\gearinfo\data\camo\khk.paa";
                };
                class Olive {
                    label = "Olive";
                    image = "z\aceax\addons\gearinfo\data\camo\sage.paa";
                };
                class Ranger {
                    label = "Ranger";
                    image = "z\aceax\addons\gearinfo\data\camo\rgr.paa";
                };
                class RangerNF {
                    label = "Ranger NF";
                    image = "z\aceax\addons\gearinfo\data\camo\rgr.paa";
                };
                class Desert {
                    label = "Desert";
                    image = "z\aceax\addons\gearinfo\data\camo\mcd.paa";
                };
                class Tropic {
                    label = "Tropic";
                    image = "z\aceax\addons\gearinfo\data\camo\mct.paa";
                };
                class Woodland {
                    label = "Woodland";
                    image = "z\aceax\addons\gearinfo\data\camo\mcw.paa";
                };
                class MTP {
                    label = "MTP";
                    image = "z\aceax\addons\gearinfo\data\camo\mtp.paa";
                };
            };
        };
        class GVAR(PlateCarrier2) {
            label = "PlateCarrier2";
            options[] = {"camo", "style"};
            class camo {
                alwaysSelectable = 1;
                values[] = {"Black", "Coyote", "Khaki", "Olive", "Ranger", "RangerNF", "Desert", "Tropic", "Woodland", "MTP", "OCP", "Multicam", "MC_Wdl", "MC_Snow"};
                class OCP {
                    label = "OCP";
                    image = "z\aceax\addons\gearinfo\data\camo\ocp.paa";
                };
                class Multicam {
                    label = "Multicam";
                    image = "z\aceax\addons\gearinfo\data\camo\mc.paa";
                };
                class MC_Wdl {
                    label = "MC-Wdl";
                    image = "z\aceax\addons\gearinfo\data\camo\mcw.paa";
                };
                class MC_Snow {
                    label = "MC-Snow";
                    image = "z\aceax\addons\gearinfo\data\camo\wht.paa";
                };
                class Black {
                    label = "Black";
                    image = "z\aceax\addons\gearinfo\data\camo\blk.paa";
                };
                class Coyote {
                    label = "Coyote";
                    image = "z\aceax\addons\gearinfo\data\camo\khk.paa";
                };
                class Khaki {
                    label = "Khaki";
                    image = "z\aceax\addons\gearinfo\data\camo\khk.paa";
                };
                class Olive {
                    label = "Olive";
                    image = "z\aceax\addons\gearinfo\data\camo\sage.paa";
                };
                class Ranger {
                    label = "Ranger";
                    image = "z\aceax\addons\gearinfo\data\camo\rgr.paa";
                };
                class RangerNF {
                    label = "Ranger NF";
                    image = "z\aceax\addons\gearinfo\data\camo\rgr.paa";
                };
                class Desert {
                    label = "Desert";
                    image = "z\aceax\addons\gearinfo\data\camo\mcd.paa";
                };
                class Tropic {
                    label = "Tropic";
                    image = "z\aceax\addons\gearinfo\data\camo\mct.paa";
                };
                class Woodland {
                    label = "Woodland";
                    image = "z\aceax\addons\gearinfo\data\camo\mcw.paa";
                };
                class MTP {
                    label = "MTP";
                    image = "z\aceax\addons\gearinfo\data\camo\mtp.paa";
                };
            };
            class style {
                alwaysSelectable = 1;
                values[] = {"Std", "Alt"};
                class Std {
                    label = "Std";
                };
                class Alt {
                    label = "Alt";
                };
            };
        };
        class GVAR(PlateCarrierGL) {
            label = "PlateCarrierGL";
            options[] = {"camo"};
            class camo {
                alwaysSelectable = 1;
                values[] = {"Black", "Coyote", "Ranger", "Desert", "Tropic", "Woodland", "MTP", "OCP", "Multicam", "MC_Wdl", "MC_Snow"};
                class OCP {
                    label = "OCP";
                    image = "z\aceax\addons\gearinfo\data\camo\ocp.paa";
                };
                class Multicam {
                    label = "Multicam";
                    image = "z\aceax\addons\gearinfo\data\camo\mc.paa";
                };
                class MC_Wdl {
                    label = "MC-Wdl";
                    image = "z\aceax\addons\gearinfo\data\camo\mcw.paa";
                };
                class MC_Snow {
                    label = "MC-Snow";
                    image = "z\aceax\addons\gearinfo\data\camo\wht.paa";
                };
                class Black {
                    label = "Black";
                    image = "z\aceax\addons\gearinfo\data\camo\blk.paa";
                };
                class Coyote {
                    label = "Coyote";
                    image = "z\aceax\addons\gearinfo\data\camo\khk.paa";
                };
                class Ranger {
                    label = "Ranger";
                    image = "z\aceax\addons\gearinfo\data\camo\rgr.paa";
                };
                class Desert {
                    label = "Desert";
                    image = "z\aceax\addons\gearinfo\data\camo\mcd.paa";
                };
                class Tropic {
                    label = "Tropic";
                    image = "z\aceax\addons\gearinfo\data\camo\mct.paa";
                };
                class Woodland {
                    label = "Woodland";
                    image = "z\aceax\addons\gearinfo\data\camo\mcw.paa";
                };
                class MTP {
                    label = "MTP";
                    image = "z\aceax\addons\gearinfo\data\camo\mtp.paa";
                };
            };
        };
        class GVAR(PlateCarrierSpec) {
            label = "PlateCarrierSpec";
            options[] = {"camo"};
            class camo {
                alwaysSelectable = 1;
                values[] = {"Black", "Coyote", "Ranger", "Desert", "Tropic", "Woodland", "MTP", "OCP", "Multicam", "MC_Wdl", "MC_Snow"};
                class OCP {
                    label = "OCP";
                    image = "z\aceax\addons\gearinfo\data\camo\ocp.paa";
                };
                class Multicam {
                    label = "Multicam";
                    image = "z\aceax\addons\gearinfo\data\camo\mc.paa";
                };
                class MC_Wdl {
                    label = "MC-Wdl";
                    image = "z\aceax\addons\gearinfo\data\camo\mcw.paa";
                };
                class MC_Snow {
                    label = "MC-Snow";
                    image = "z\aceax\addons\gearinfo\data\camo\wht.paa";
                };
                class Black {
                    label = "Black";
                    image = "z\aceax\addons\gearinfo\data\camo\blk.paa";
                };
                class Coyote {
                    label = "Coyote";
                    image = "z\aceax\addons\gearinfo\data\camo\khk.paa";
                };
                class Ranger {
                    label = "Ranger";
                    image = "z\aceax\addons\gearinfo\data\camo\rgr.paa";
                };
                class Desert {
                    label = "Desert";
                    image = "z\aceax\addons\gearinfo\data\camo\mcd.paa";
                };
                class Tropic {
                    label = "Tropic";
                    image = "z\aceax\addons\gearinfo\data\camo\mct.paa";
                };
                class Woodland {
                    label = "Woodland";
                    image = "z\aceax\addons\gearinfo\data\camo\mcw.paa";
                };
                class MTP {
                    label = "MTP";
                    image = "z\aceax\addons\gearinfo\data\camo\mtp.paa";
                };
            };
        };
        class GVAR(PlateCarrier_RF) {
            label = "PlateCarrier_RF";
            options[] = {"camo"};
            class camo {
                alwaysSelectable = 1;
                values[] = {"Black", "Coyote", "Khaki", "Olive", "Ranger", "Desert", "Tropic", "Woodland", "MTP"};
                class Black {
                    label = "Black";
                    image = "z\aceax\addons\gearinfo\data\camo\blk.paa";
                };
                class Coyote {
                    label = "Coyote";
                    image = "z\aceax\addons\gearinfo\data\camo\khk.paa";
                };
                class Khaki {
                    label = "Khaki";
                    image = "z\aceax\addons\gearinfo\data\camo\khk.paa";
                };
                class Olive {
                    label = "Olive";
                    image = "z\aceax\addons\gearinfo\data\camo\sage.paa";
                };
                class Ranger {
                    label = "Ranger";
                    image = "z\aceax\addons\gearinfo\data\camo\rgr.paa";
                };
                class Desert {
                    label = "Desert";
                    image = "z\aceax\addons\gearinfo\data\camo\mcd.paa";
                };
                class Tropic {
                    label = "Tropic";
                    image = "z\aceax\addons\gearinfo\data\camo\mct.paa";
                };
                class Woodland {
                    label = "Woodland";
                    image = "z\aceax\addons\gearinfo\data\camo\mcw.paa";
                };
                class MTP {
                    label = "MTP";
                    image = "z\aceax\addons\gearinfo\data\camo\mtp.paa";
                };
            };
        };
        class GVAR(PlateCarrier_CTRG) {
            label = "PlateCarrier CTRG";
            options[] = {"camo", "type"};
            class camo {
                alwaysSelectable = 1;
                values[] = {"OCP", "MTP", "Multicam", "MC_Wdl", "MC_Snow", "Tropic"};
                class OCP {
                    label = "OCP";
                    image = "z\aceax\addons\gearinfo\data\camo\ocp.paa";
                };
                class MTP {
                    label = "MTP";
                    image = "z\aceax\addons\gearinfo\data\camo\mtp.paa";
                };
                class Multicam {
                    label = "Multicam";
                    image = "z\aceax\addons\gearinfo\data\camo\mc.paa";
                };
                class MC_Wdl {
                    label = "MC-Wdl";
                    image = "z\aceax\addons\gearinfo\data\camo\mcw.paa";
                };
                class MC_Snow {
                    label = "MC-Snow";
                    image = "z\aceax\addons\gearinfo\data\camo\wht.paa";
                };
                class Tropic {
                    label = "Tropic";
                    image = "z\aceax\addons\gearinfo\data\camo\mct.paa";
                };
            };
            class type {
                alwaysSelectable = 1;
                values[] = {"Light", "Heavy"};
                class Light {
                    label = "Light";
                };
                class Heavy {
                    label = "Heavy";
                };
            };
        };
    };
};

class XtdGearInfos {
    class CfgWeapons {
        #include "XtdGearInfos_EF.hpp"
        #include "XtdGearInfos_PlateCarriers.hpp"
    };
};
