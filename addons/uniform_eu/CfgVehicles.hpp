class CfgVehicles {
    class I_soldier_F;

    // JMSB-local NCU uniform bases (models vendored from Aegis/Atlas, no longer inherited).
    // hiddenSelectionsMaterials overrides the rvmats baked into the p3d (which point at
    // \A3_Atlas\ and \A3_Aegis\ paths) with the local copies in data\, so the Aegis mods
    // are not required at runtime. The camo/camo2 diffuse is set per-variant below.
    class GVAR(CombatUniformNCU_01_base): I_soldier_F {
        scope = 1;
        scopeCurator = 0;
        model = QPATHTOF(U_CombatUniformNCU_01);
        hiddenSelections[] = {"camo", "camo2", "insignia"};
        hiddenSelectionsMaterials[] = {
            QPATHTOF(data\clothing_ncu.rvmat),
            QPATHTOF(data\combatgloves.rvmat)
        };
        armorStructural = 4;
        class Wounds {
            tex[] = {};
            mat[] = {
                QPATHTOF(data\clothing_ncu.rvmat),
                QPATHTOF(data\clothing_ncu_injury.rvmat),
                QPATHTOF(data\clothing_ncu_injury.rvmat)
            };
        };
    };
    class GVAR(CombatUniformNCU_02_base): GVAR(CombatUniformNCU_01_base) {
        model = QPATHTOF(U_CombatUniformNCU_02);
    };

    class GVAR(CombatUniformNCU_01_mcam_F): GVAR(CombatUniformNCU_01_base) {
        uniformClass = QGVAR(U_CombatUniformNCU_01_mcam_F);
        hiddenSelectionsTextures[] = {
            QPATHTOEF(uniform,models\characters\Uniforms\Data\clothing_ncu_mcam_CO.paa),
            QPATHTOF(data\combatgloves_khk_co.paa)
        };
    };
    class GVAR(CombatUniformNCU_02_mcam_F): GVAR(CombatUniformNCU_02_base) {
        uniformClass = QGVAR(U_CombatUniformNCU_02_mcam_F);
        hiddenSelectionsTextures[] = {
            QPATHTOEF(uniform,models\characters\Uniforms\Data\clothing_ncu_mcam_CO.paa),
            QPATHTOF(data\combatgloves_khk_co.paa)
        };
    };
    class GVAR(CombatUniformNCU_01_mcam_wdl_F): GVAR(CombatUniformNCU_01_base) {
        uniformClass = QGVAR(U_CombatUniformNCU_01_mcam_wdl_F);
        hiddenSelectionsTextures[] = {
            QPATHTOEF(uniform,models\characters\Uniforms\Data\clothing_ncu_mcam_wdl_CO.paa),
            QPATHTOF(data\combatgloves_grn_co.paa)
        };
    };
    class GVAR(CombatUniformNCU_02_mcam_wdl_F): GVAR(CombatUniformNCU_02_base) {
        uniformClass = QGVAR(U_CombatUniformNCU_02_mcam_wdl_F);
        hiddenSelectionsTextures[] = {
            QPATHTOEF(uniform,models\characters\Uniforms\Data\clothing_ncu_mcam_wdl_CO.paa),
            QPATHTOF(data\combatgloves_grn_co.paa)
        };
    };
    class GVAR(CombatUniformNCU_01_ocp_F): GVAR(CombatUniformNCU_01_base) {
        uniformClass = QGVAR(U_CombatUniformNCU_01_ocp_F);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\clothing_ncu_ocp_co.paa),
            QPATHTOF(data\combatgloves_khk_co.paa)
        };
    };
    class GVAR(CombatUniformNCU_02_ocp_F): GVAR(CombatUniformNCU_02_base) {
        uniformClass = QGVAR(U_CombatUniformNCU_02_ocp_F);
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\clothing_ncu_ocp_co.paa),
            QPATHTOF(data\combatgloves_khk_co.paa)
        };
    };
};
