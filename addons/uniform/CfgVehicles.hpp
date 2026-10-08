class CfgVehicles {
#include "acp_full_holder_externs.hpp"
#include "imported_CfgVehicles_decl.hpp"
    class Item_Base_F;

    /* Character classes - full sleeve (B_CTRG_Soldier_F body) */
    class GVAR(B_JSOC_StealthUniform_soldier_F): B_CTRG_Soldier_F {        scope = 1;
        scopeCurator = 0;
        uniformClass = QGVAR(U_B_JSOC_StealthUniform_F);
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_co.paa)};
    };
    class GVAR(B_D_JSOC_StealthUniform_soldier_F): B_CTRG_Soldier_F {        scope = 1;
        scopeCurator = 0;
        uniformClass = QGVAR(U_B_D_JSOC_StealthUniform_F);
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_des_co.paa)};
    };
    class GVAR(B_T_JSOC_StealthUniform_soldier_F): B_CTRG_Soldier_F {        scope = 1;
        scopeCurator = 0;
        uniformClass = QGVAR(U_B_T_JSOC_StealthUniform_F);
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_tna_co.paa)};
    };
    class GVAR(B_W_JSOC_StealthUniform_soldier_F): B_CTRG_Soldier_F {        scope = 1;
        scopeCurator = 0;
        uniformClass = QGVAR(U_B_W_JSOC_StealthUniform_F);
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_wdl_co.paa)};
    };
    class GVAR(B_OCP_JSOC_StealthUniform_soldier_F): B_CTRG_Soldier_F {        scope = 1;
        scopeCurator = 0;
        uniformClass = QGVAR(U_B_OCP_JSOC_StealthUniform_F);
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_ocp_co.paa)};
    };
    class GVAR(B_Snow_JSOC_StealthUniform_soldier_F): B_CTRG_Soldier_F {        scope = 1;
        scopeCurator = 0;
        uniformClass = QGVAR(U_B_Snow_JSOC_StealthUniform_F);
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_snow_co.paa)};
    };

    /* Character classes - rolled-up sleeve (B_CTRG_Soldier_3_F body) */
    class GVAR(B_JSOC_StealthUniform_RolledUp_soldier_F): B_CTRG_Soldier_3_F {        scope = 1;
        scopeCurator = 0;
        uniformClass = QGVAR(U_B_JSOC_StealthUniform_RolledUp_F);
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_co.paa)};
    };
    class GVAR(B_D_JSOC_StealthUniform_RolledUp_soldier_F): B_CTRG_Soldier_3_F {        scope = 1;
        scopeCurator = 0;
        uniformClass = QGVAR(U_B_D_JSOC_StealthUniform_RolledUp_F);
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_des_co.paa)};
    };
    class GVAR(B_T_JSOC_StealthUniform_RolledUp_soldier_F): B_CTRG_Soldier_3_F {        scope = 1;
        scopeCurator = 0;
        uniformClass = QGVAR(U_B_T_JSOC_StealthUniform_RolledUp_F);
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_tna_co.paa)};
    };
    class GVAR(B_W_JSOC_StealthUniform_RolledUp_soldier_F): B_CTRG_Soldier_3_F {        scope = 1;
        scopeCurator = 0;
        uniformClass = QGVAR(U_B_W_JSOC_StealthUniform_RolledUp_F);
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_wdl_co.paa)};
    };
    class GVAR(B_OCP_JSOC_StealthUniform_RolledUp_soldier_F): B_CTRG_Soldier_3_F {        scope = 1;
        scopeCurator = 0;
        uniformClass = QGVAR(U_B_OCP_JSOC_StealthUniform_RolledUp_F);
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_ocp_co.paa)};
    };
    class GVAR(B_Snow_JSOC_StealthUniform_RolledUp_soldier_F): B_CTRG_Soldier_3_F {        scope = 1;
        scopeCurator = 0;
        uniformClass = QGVAR(U_B_Snow_JSOC_StealthUniform_RolledUp_F);
        hiddenSelectionsTextures[] = {QPATHTOF(data\jmfsb_u_b_jsoc_soldier_f_snow_co.paa)};
    };

    /* Editor/Zeus placeable item entities */
    class GVAR(Item_U_B_JSOC_StealthUniform_F): Item_Base_F {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform";
        editorCategory = "EdCat_Equipment";
        editorSubcategory = "EdSubcat_Uniforms";
        vehicleClass = "ItemsUniform";
        model = "\A3\Weapons_F\dummyweapon.p3d";
        class TransportItems {
            class GVAR(U_B_JSOC_StealthUniform_F) {
                name = QGVAR(U_B_JSOC_StealthUniform_F);
                count = 1;
            };
        };
    };
    class GVAR(Item_U_B_JSOC_StealthUniform_RolledUp_F): Item_Base_F {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform (Rolled Up)";
        editorCategory = "EdCat_Equipment";
        editorSubcategory = "EdSubcat_Uniforms";
        vehicleClass = "ItemsUniform";
        model = "\A3\Weapons_F\dummyweapon.p3d";
        class TransportItems {
            class GVAR(U_B_JSOC_StealthUniform_RolledUp_F) {
                name = QGVAR(U_B_JSOC_StealthUniform_RolledUp_F);
                count = 1;
            };
        };
    };

    class GVAR(Item_U_B_D_JSOC_StealthUniform_F): Item_Base_F {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform (Desert)";
        editorCategory = "EdCat_Equipment";
        editorSubcategory = "EdSubcat_Uniforms";
        vehicleClass = "ItemsUniform";
        model = "\A3\Weapons_F\dummyweapon.p3d";
        class TransportItems {
            class GVAR(U_B_D_JSOC_StealthUniform_F) {
                name = QGVAR(U_B_D_JSOC_StealthUniform_F);
                count = 1;
            };
        };
    };
    class GVAR(Item_U_B_D_JSOC_StealthUniform_RolledUp_F): Item_Base_F {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform (Desert, Rolled Up)";
        editorCategory = "EdCat_Equipment";
        editorSubcategory = "EdSubcat_Uniforms";
        vehicleClass = "ItemsUniform";
        model = "\A3\Weapons_F\dummyweapon.p3d";
        class TransportItems {
            class GVAR(U_B_D_JSOC_StealthUniform_RolledUp_F) {
                name = QGVAR(U_B_D_JSOC_StealthUniform_RolledUp_F);
                count = 1;
            };
        };
    };

    class GVAR(Item_U_B_T_JSOC_StealthUniform_F): Item_Base_F {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform (Tropic)";
        editorCategory = "EdCat_Equipment";
        editorSubcategory = "EdSubcat_Uniforms";
        vehicleClass = "ItemsUniform";
        model = "\A3\Weapons_F\dummyweapon.p3d";
        class TransportItems {
            class GVAR(U_B_T_JSOC_StealthUniform_F) {
                name = QGVAR(U_B_T_JSOC_StealthUniform_F);
                count = 1;
            };
        };
    };
    class GVAR(Item_U_B_T_JSOC_StealthUniform_RolledUp_F): Item_Base_F {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform (Tropic, Rolled Up)";
        editorCategory = "EdCat_Equipment";
        editorSubcategory = "EdSubcat_Uniforms";
        vehicleClass = "ItemsUniform";
        model = "\A3\Weapons_F\dummyweapon.p3d";
        class TransportItems {
            class GVAR(U_B_T_JSOC_StealthUniform_RolledUp_F) {
                name = QGVAR(U_B_T_JSOC_StealthUniform_RolledUp_F);
                count = 1;
            };
        };
    };

    class GVAR(Item_U_B_W_JSOC_StealthUniform_F): Item_Base_F {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform (Woodland)";
        editorCategory = "EdCat_Equipment";
        editorSubcategory = "EdSubcat_Uniforms";
        vehicleClass = "ItemsUniform";
        model = "\A3\Weapons_F\dummyweapon.p3d";
        class TransportItems {
            class GVAR(U_B_W_JSOC_StealthUniform_F) {
                name = QGVAR(U_B_W_JSOC_StealthUniform_F);
                count = 1;
            };
        };
    };
    class GVAR(Item_U_B_W_JSOC_StealthUniform_RolledUp_F): Item_Base_F {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform (Woodland, Rolled Up)";
        editorCategory = "EdCat_Equipment";
        editorSubcategory = "EdSubcat_Uniforms";
        vehicleClass = "ItemsUniform";
        model = "\A3\Weapons_F\dummyweapon.p3d";
        class TransportItems {
            class GVAR(U_B_W_JSOC_StealthUniform_RolledUp_F) {
                name = QGVAR(U_B_W_JSOC_StealthUniform_RolledUp_F);
                count = 1;
            };
        };
    };

    class GVAR(Item_U_B_OCP_JSOC_StealthUniform_F): Item_Base_F {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform (OCP)";
        editorCategory = "EdCat_Equipment";
        editorSubcategory = "EdSubcat_Uniforms";
        vehicleClass = "ItemsUniform";
        model = "\A3\Weapons_F\dummyweapon.p3d";
        class TransportItems {
            class GVAR(U_B_OCP_JSOC_StealthUniform_F) {
                name = QGVAR(U_B_OCP_JSOC_StealthUniform_F);
                count = 1;
            };
        };
    };
    class GVAR(Item_U_B_OCP_JSOC_StealthUniform_RolledUp_F): Item_Base_F {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform (OCP, Rolled Up)";
        editorCategory = "EdCat_Equipment";
        editorSubcategory = "EdSubcat_Uniforms";
        vehicleClass = "ItemsUniform";
        model = "\A3\Weapons_F\dummyweapon.p3d";
        class TransportItems {
            class GVAR(U_B_OCP_JSOC_StealthUniform_RolledUp_F) {
                name = QGVAR(U_B_OCP_JSOC_StealthUniform_RolledUp_F);
                count = 1;
            };
        };
    };

    class GVAR(Item_U_B_Snow_JSOC_StealthUniform_F): Item_Base_F {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform (Snow)";
        editorCategory = "EdCat_Equipment";
        editorSubcategory = "EdSubcat_Uniforms";
        vehicleClass = "ItemsUniform";
        model = "\A3\Weapons_F\dummyweapon.p3d";
        class TransportItems {
            class GVAR(U_B_Snow_JSOC_StealthUniform_F) {
                name = QGVAR(U_B_Snow_JSOC_StealthUniform_F);
                count = 1;
            };
        };
    };
    class GVAR(Item_U_B_Snow_JSOC_StealthUniform_RolledUp_F): Item_Base_F {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] JSOC Stealth Uniform (Snow, Rolled Up)";
        editorCategory = "EdCat_Equipment";
        editorSubcategory = "EdSubcat_Uniforms";
        vehicleClass = "ItemsUniform";
        model = "\A3\Weapons_F\dummyweapon.p3d";
        class TransportItems {
            class GVAR(U_B_Snow_JSOC_StealthUniform_RolledUp_F) {
                name = QGVAR(U_B_Snow_JSOC_StealthUniform_RolledUp_F);
                count = 1;
            };
        };
    };

#include "acp_ocp_vehicles.hpp"
#include "acp_snow_vehicles.hpp"
#include "imported_CfgVehicles.hpp"
};
