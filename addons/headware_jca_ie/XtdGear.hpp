class XtdGearModels {
    class CfgWeapons {
        class GVAR(HelmetHBK) {
            label = "AMH (HBK)";
            options[] = {"acc", "camo"};
            class acc {
                alwaysSelectable = 1;
                values[] = {"Std", "Chops", "EarPro", "Headset"};
                class Std {
                    label = "Std";
                };
                class Chops {
                    label = "Chops";
                };
                class EarPro {
                    label = "EarPro";
                };
                class Headset {
                    label = "Headset";
                };
            };
            class camo {
                alwaysSelectable = 1;
                values[] = {"Black", "Olive", "Sand"};
                class Black {
                    label = "Black";
                    image = "z\aceax\addons\gearinfo\data\camo\blk.paa";
                };
                class Olive {
                    label = "Olive";
                    image = "z\aceax\addons\gearinfo\data\camo\sage.paa";
                };
                class Sand {
                    label = "Sand";
                    image = "z\aceax\addons\gearinfo\data\camo\khk.paa";
                };
            };
        };
    };
};

class XtdGearInfos {
    class CfgWeapons {
        class GVAR(JCA_H_HelmetHBK_black_F) {
            model = QGVAR(HelmetHBK);
            acc = "Std";
            camo = "Black";
        };
        class GVAR(JCA_H_HelmetHBK_chops_black_F) {
            model = QGVAR(HelmetHBK);
            acc = "Chops";
            camo = "Black";
        };
        class GVAR(JCA_H_HelmetHBK_chops_olive_F) {
            model = QGVAR(HelmetHBK);
            acc = "Chops";
            camo = "Olive";
        };
        class GVAR(JCA_H_HelmetHBK_chops_sand_F) {
            model = QGVAR(HelmetHBK);
            acc = "Chops";
            camo = "Sand";
        };
        class GVAR(JCA_H_HelmetHBK_ear_black_F) {
            model = QGVAR(HelmetHBK);
            acc = "EarPro";
            camo = "Black";
        };
        class GVAR(JCA_H_HelmetHBK_ear_olive_F) {
            model = QGVAR(HelmetHBK);
            acc = "EarPro";
            camo = "Olive";
        };
        class GVAR(JCA_H_HelmetHBK_ear_sand_F) {
            model = QGVAR(HelmetHBK);
            acc = "EarPro";
            camo = "Sand";
        };
        class GVAR(JCA_H_HelmetHBK_headset_black_F) {
            model = QGVAR(HelmetHBK);
            acc = "Headset";
            camo = "Black";
        };
        class GVAR(JCA_H_HelmetHBK_headset_olive_F) {
            model = QGVAR(HelmetHBK);
            acc = "Headset";
            camo = "Olive";
        };
        class GVAR(JCA_H_HelmetHBK_headset_sand_F) {
            model = QGVAR(HelmetHBK);
            acc = "Headset";
            camo = "Sand";
        };
        class GVAR(JCA_H_HelmetHBK_olive_F) {
            model = QGVAR(HelmetHBK);
            acc = "Std";
            camo = "Olive";
        };
        class GVAR(JCA_H_HelmetHBK_sand_F) {
            model = QGVAR(HelmetHBK);
            acc = "Std";
            camo = "Sand";
        };
    };
};
