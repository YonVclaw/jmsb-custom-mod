class CfgWeapons {
    class UniformItem;
    class Uniform_Base;

    class GVAR(U_CombatUniformNCU_01_mcam_F): Uniform_Base {        author = QAUTHOR;
        scope = 2;
        displayName = "European Combat Uniform (MTP)";
        picture = QPATHTOEF(uniform,models\characters\Uniforms\Data\UI\icon_Atlas_U_CombatUniformNCU_01_mcam_F_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Suitpacks\Data\suitpack_soldier_indep_CO.paa"};
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(CombatUniformNCU_01_mcam_F);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(U_CombatUniformNCU_02_mcam_F): Uniform_Base {        author = QAUTHOR;
        scope = 2;
        displayName = "European Combat Uniform (MTP, Rolled-up)";
        picture = QPATHTOEF(uniform,models\characters\Uniforms\Data\UI\icon_Atlas_U_CombatUniformNCU_02_mcam_F_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Suitpacks\Data\suitpack_soldier_indep_CO.paa"};
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(CombatUniformNCU_02_mcam_F);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(U_CombatUniformNCU_01_mcam_wdl_F): Uniform_Base {        author = QAUTHOR;
        scope = 2;
        displayName = "European Combat Uniform (MTP-W)";
        picture = QPATHTOEF(uniform,models\characters\Uniforms\Data\UI\icon_Atlas_U_CombatUniformNCU_01_mcam_wdl_F_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Suitpacks\Data\suitpack_soldier_indep_CO.paa"};
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(CombatUniformNCU_01_mcam_wdl_F);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(U_CombatUniformNCU_02_mcam_wdl_F): Uniform_Base {        author = QAUTHOR;
        scope = 2;
        displayName = "European Combat Uniform (MTP-W, Rolled-up)";
        picture = QPATHTOEF(uniform,models\characters\Uniforms\Data\UI\icon_Atlas_U_CombatUniformNCU_02_mcam_wdl_F_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Suitpacks\Data\suitpack_soldier_indep_CO.paa"};
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(CombatUniformNCU_02_mcam_wdl_F);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(U_CombatUniformNCU_01_ocp_F): Uniform_Base {        author = QAUTHOR;
        scope = 2;
        displayName = "European Combat Uniform (OCP)";
        picture = QPATHTOEF(uniform,models\characters\Uniforms\Data\UI\icon_Atlas_U_CombatUniformNCU_01_mcam_F_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Suitpacks\Data\suitpack_soldier_indep_CO.paa"};
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(CombatUniformNCU_01_ocp_F);
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class GVAR(U_CombatUniformNCU_02_ocp_F): Uniform_Base {        author = QAUTHOR;
        scope = 2;
        displayName = "European Combat Uniform (OCP, Rolled-up)";
        picture = QPATHTOEF(uniform,models\characters\Uniforms\Data\UI\icon_Atlas_U_CombatUniformNCU_02_mcam_F_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Suitpacks\Data\suitpack_soldier_indep_CO.paa"};
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(CombatUniformNCU_02_ocp_F);
            containerClass = "Supply40";
            mass = 40;
        };
    };
};
