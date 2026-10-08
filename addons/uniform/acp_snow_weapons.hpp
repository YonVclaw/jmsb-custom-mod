// ACP Multicam Snow uniforms -- included from CfgWeapons.hpp

    class GVAR(U_B_CombatUniform_snow_F): U_B_CombatUniform_mcam {
        author = QAUTHOR;
        MACRO_ITEM_COMMON
        displayName = "[JMSB] Combat Fatigues (Multicam Snow)";
        picture = QPATHTOF(data\ui\icon_U_B_CombatUniform_Multicam_Snow_ca.paa);
        hiddenSelectionsTextures[] = {QPATHTOF(data\clothing1_Multicam_Snow.paa)};
        class ItemInfo: ItemInfo {
            uniformClass = QGVAR(B_CombatUniform_snow_soldier_F);
        };
    };
