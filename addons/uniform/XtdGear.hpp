class XtdGearModels {
    class CfgWeapons {
        class jmfsb_uniform_JSOC {
            label = "JSOC";
            options[] = {"camo", "type"};
            class camo {
                alwaysSelectable = 1;
                values[] = {"Plain", "DES", "TNA", "WDL", "OCP", "SNW"};
                class Plain {
                    label = "Plain";
                    image = "z\aceax\addons\gearinfo\data\camo\mc.paa";
                };
                class DES {
                    label = "DES";
                    image = "z\aceax\addons\gearinfo\data\camo\mcd.paa";
                };
                class TNA {
                    label = "TNA";
                    image = "z\aceax\addons\gearinfo\data\camo\tropic.paa";
                };
                class WDL {
                    label = "WDL";
                    image = "z\aceax\addons\gearinfo\data\camo\mcw.paa";
                };
                class OCP {
                    label = "OCP";
                    image = "z\aceax\addons\gearinfo\data\camo\ocp.paa";
                };
                class SNW {
                    label = "SNW";
                    image = "z\aceax\addons\gearinfo\data\camo\wht.paa";
                };
            };
            class type {
                alwaysSelectable = 1;
                values[] = {"Full", "RolledUp"};
                class Full {
                    label = "Full";
                };
                class RolledUp {
                    label = "Rolled";
                };
            };
        };
        class jmfsb_uniform_CombatUniform {
            label = "Combat Fatigues";
            options[] = {"camo"};
            class camo {
                alwaysSelectable = 1;
                values[] = {"OCP", "SNW"};
                class OCP {
                    label = "OCP";
                    image = "z\aceax\addons\gearinfo\data\camo\ocp.paa";
                };
                class SNW {
                    label = "SNW";
                    image = "z\aceax\addons\gearinfo\data\camo\wht.paa";
                };
            };
        };
    };
};

class XtdGearInfos {
    class CfgWeapons {
        class jmfsb_uniform_U_B_JSOC_StealthUniform_F {
            model = "jmfsb_uniform_JSOC";
            camo = "Plain";
            type = "Full";
        };
        class jmfsb_uniform_U_B_JSOC_StealthUniform_RolledUp_F {
            model = "jmfsb_uniform_JSOC";
            camo = "Plain";
            type = "RolledUp";
        };
        class jmfsb_uniform_U_B_D_JSOC_StealthUniform_F {
            model = "jmfsb_uniform_JSOC";
            camo = "DES";
            type = "Full";
        };
        class jmfsb_uniform_U_B_D_JSOC_StealthUniform_RolledUp_F {
            model = "jmfsb_uniform_JSOC";
            camo = "DES";
            type = "RolledUp";
        };
        class jmfsb_uniform_U_B_T_JSOC_StealthUniform_F {
            model = "jmfsb_uniform_JSOC";
            camo = "TNA";
            type = "Full";
        };
        class jmfsb_uniform_U_B_T_JSOC_StealthUniform_RolledUp_F {
            model = "jmfsb_uniform_JSOC";
            camo = "TNA";
            type = "RolledUp";
        };
        class jmfsb_uniform_U_B_W_JSOC_StealthUniform_F {
            model = "jmfsb_uniform_JSOC";
            camo = "WDL";
            type = "Full";
        };
        class jmfsb_uniform_U_B_W_JSOC_StealthUniform_RolledUp_F {
            model = "jmfsb_uniform_JSOC";
            camo = "WDL";
            type = "RolledUp";
        };
        class jmfsb_uniform_U_B_OCP_JSOC_StealthUniform_F {
            model = "jmfsb_uniform_JSOC";
            camo = "OCP";
            type = "Full";
        };
        class jmfsb_uniform_U_B_OCP_JSOC_StealthUniform_RolledUp_F {
            model = "jmfsb_uniform_JSOC";
            camo = "OCP";
            type = "RolledUp";
        };
        class jmfsb_uniform_U_B_Snow_JSOC_StealthUniform_F {
            model = "jmfsb_uniform_JSOC";
            camo = "SNW";
            type = "Full";
        };
        class jmfsb_uniform_U_B_Snow_JSOC_StealthUniform_RolledUp_F {
            model = "jmfsb_uniform_JSOC";
            camo = "SNW";
            type = "RolledUp";
        };
        class jmfsb_uniform_U_B_CombatUniform_ocp_F {
            model = "jmfsb_uniform_CombatUniform";
            camo = "OCP";
        };
        class jmfsb_uniform_U_B_CombatUniform_snow_F {
            model = "jmfsb_uniform_CombatUniform";
            camo = "SNW";
        };
    };
};
