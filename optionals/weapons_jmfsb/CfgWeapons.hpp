class CfgWeapons {
    class arifle_MX_Black_F;
    class arifle_MX_GL_Black_F;
    class arifle_MXM_Black_F;
    class arifle_MXC_Black_F;
    class arifle_MX_SW_Black_F;

    // ---- Black Camo ----
    class GVAR(MX_blackcamo): arifle_MX_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX (Black Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-blackcamo.paa),
            QPATHTOF(data\mx\xmx_base_co-blackcamo.paa)
        };
        baseWeapon = QGVAR(MX_blackcamo);
    };
    class GVAR(MX_GL_blackcamo): arifle_MX_GL_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX 3GL (Black Camo)";
        picture = QPATHTOF(UI\mx_gl_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-blackcamo.paa),
            "\A3\Weapons_F_EPB\Rifles\MX_Black\Data\GLX_Black_CO.paa"
        };
        baseWeapon = QGVAR(MX_GL_blackcamo);
    };
    class GVAR(MXM_blackcamo): arifle_MXM_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXM (Black Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_long_co-blackcamo.paa),
            QPATHTOF(data\mx\xmx_long_co-blackcamo.paa)
        };
        baseWeapon = QGVAR(MXM_blackcamo);
    };
    class GVAR(MXC_blackcamo): arifle_MXC_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXC (Black Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_short_co-blackcamo.paa),
            QPATHTOF(data\mx\xmx_short_co-blackcamo.paa)
        };
        baseWeapon = QGVAR(MXC_blackcamo);
    };
    class GVAR(MX_SW_blackcamo): arifle_MX_SW_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX LMG (Black Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_lmg_co-blackcamo.paa),
            QPATHTOF(data\mx\xmx_lmg_co-blackcamo.paa)
        };
        baseWeapon = QGVAR(MX_SW_blackcamo);
    };

    // ---- Black Fine Camo ----
    class GVAR(MX_blackfine): arifle_MX_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX (Black Fine Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-blackfine.paa),
            QPATHTOF(data\mx\xmx_base_co-blackfine.paa)
        };
        baseWeapon = QGVAR(MX_blackfine);
    };
    class GVAR(MX_GL_blackfine): arifle_MX_GL_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX 3GL (Black Fine Camo)";
        picture = QPATHTOF(UI\mx_gl_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-blackfine.paa),
            "\A3\Weapons_F_EPB\Rifles\MX_Black\Data\GLX_Black_CO.paa"
        };
        baseWeapon = QGVAR(MX_GL_blackfine);
    };
    class GVAR(MXM_blackfine): arifle_MXM_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXM (Black Fine Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_long_co-blackfine.paa),
            QPATHTOF(data\mx\xmx_long_co-blackfine.paa)
        };
        baseWeapon = QGVAR(MXM_blackfine);
    };
    class GVAR(MXC_blackfine): arifle_MXC_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXC (Black Fine Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_short_co-blackfine.paa),
            QPATHTOF(data\mx\xmx_short_co-blackfine.paa)
        };
        baseWeapon = QGVAR(MXC_blackfine);
    };
    class GVAR(MX_SW_blackfine): arifle_MX_SW_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX LMG (Black Fine Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_lmg_co-blackfine.paa),
            QPATHTOF(data\mx\xmx_lmg_co-blackfine.paa)
        };
        baseWeapon = QGVAR(MX_SW_blackfine);
    };

    // ---- Black Hex Camo ----
    class GVAR(MX_blackhex): arifle_MX_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX (Black Hex Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-blackhex.paa),
            QPATHTOF(data\mx\xmx_base_co-blackhex.paa)
        };
        baseWeapon = QGVAR(MX_blackhex);
    };
    class GVAR(MX_GL_blackhex): arifle_MX_GL_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX 3GL (Black Hex Camo)";
        picture = QPATHTOF(UI\mx_gl_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-blackhex.paa),
            "\A3\Weapons_F_EPB\Rifles\MX_Black\Data\GLX_Black_CO.paa"
        };
        baseWeapon = QGVAR(MX_GL_blackhex);
    };
    class GVAR(MXM_blackhex): arifle_MXM_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXM (Black Hex Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_long_co-blackhex.paa),
            QPATHTOF(data\mx\xmx_long_co-blackhex.paa)
        };
        baseWeapon = QGVAR(MXM_blackhex);
    };
    class GVAR(MXC_blackhex): arifle_MXC_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXC (Black Hex Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_short_co-blackhex.paa),
            QPATHTOF(data\mx\xmx_short_co-blackhex.paa)
        };
        baseWeapon = QGVAR(MXC_blackhex);
    };
    class GVAR(MX_SW_blackhex): arifle_MX_SW_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX LMG (Black Hex Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_lmg_co-blackhex.paa),
            QPATHTOF(data\mx\xmx_lmg_co-blackhex.paa)
        };
        baseWeapon = QGVAR(MX_SW_blackhex);
    };

    // ---- Black Sploch Camo ----
    class GVAR(MX_blacksploch): arifle_MX_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX (Black Sploch Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-blacksploch.paa),
            QPATHTOF(data\mx\xmx_base_co-blacksploch.paa)
        };
        baseWeapon = QGVAR(MX_blacksploch);
    };
    class GVAR(MX_GL_blacksploch): arifle_MX_GL_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX 3GL (Black Sploch Camo)";
        picture = QPATHTOF(UI\mx_gl_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-blacksploch.paa),
            "\A3\Weapons_F_EPB\Rifles\MX_Black\Data\GLX_Black_CO.paa"
        };
        baseWeapon = QGVAR(MX_GL_blacksploch);
    };
    class GVAR(MXM_blacksploch): arifle_MXM_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXM (Black Sploch Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_long_co-blacksploch.paa),
            QPATHTOF(data\mx\xmx_long_co-blacksploch.paa)
        };
        baseWeapon = QGVAR(MXM_blacksploch);
    };
    class GVAR(MXC_blacksploch): arifle_MXC_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXC (Black Sploch Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_short_co-blacksploch.paa),
            QPATHTOF(data\mx\xmx_short_co-blacksploch.paa)
        };
        baseWeapon = QGVAR(MXC_blacksploch);
    };
    class GVAR(MX_SW_blacksploch): arifle_MX_SW_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX LMG (Black Sploch Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_lmg_co-blacksploch.paa),
            QPATHTOF(data\mx\xmx_lmg_co-blacksploch.paa)
        };
        baseWeapon = QGVAR(MX_SW_blacksploch);
    };

    // ---- Brown Dots Camo ----
    class GVAR(MX_browndots): arifle_MX_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX (Brown Dots Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-browndots.paa),
            QPATHTOF(data\mx\xmx_base_co-browndots.paa)
        };
        baseWeapon = QGVAR(MX_browndots);
    };
    class GVAR(MX_GL_browndots): arifle_MX_GL_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX 3GL (Brown Dots Camo)";
        picture = QPATHTOF(UI\mx_gl_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-browndots.paa),
            "\A3\Weapons_F_EPB\Rifles\MX_Black\Data\GLX_Black_CO.paa"
        };
        baseWeapon = QGVAR(MX_GL_browndots);
    };
    class GVAR(MXM_browndots): arifle_MXM_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXM (Brown Dots Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_long_co-browndots.paa),
            QPATHTOF(data\mx\xmx_long_co-browndots.paa)
        };
        baseWeapon = QGVAR(MXM_browndots);
    };
    class GVAR(MXC_browndots): arifle_MXC_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXC (Brown Dots Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_short_co-browndots.paa),
            QPATHTOF(data\mx\xmx_short_co-browndots.paa)
        };
        baseWeapon = QGVAR(MXC_browndots);
    };
    class GVAR(MX_SW_browndots): arifle_MX_SW_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX LMG (Brown Dots Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_lmg_co-browndots.paa),
            QPATHTOF(data\mx\xmx_lmg_co-browndots.paa)
        };
        baseWeapon = QGVAR(MX_SW_browndots);
    };

    // ---- Brown Splash Camo ----
    class GVAR(MX_brownsplash): arifle_MX_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX (Brown Splash Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-brownsplash.paa),
            QPATHTOF(data\mx\xmx_base_co-brownsplash.paa)
        };
        baseWeapon = QGVAR(MX_brownsplash);
    };
    class GVAR(MX_GL_brownsplash): arifle_MX_GL_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX 3GL (Brown Splash Camo)";
        picture = QPATHTOF(UI\mx_gl_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-brownsplash.paa),
            "\A3\Weapons_F_EPB\Rifles\MX_Black\Data\GLX_Black_CO.paa"
        };
        baseWeapon = QGVAR(MX_GL_brownsplash);
    };
    class GVAR(MXM_brownsplash): arifle_MXM_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXM (Brown Splash Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_long_co-brownsplash.paa),
            QPATHTOF(data\mx\xmx_long_co-brownsplash.paa)
        };
        baseWeapon = QGVAR(MXM_brownsplash);
    };
    class GVAR(MXC_brownsplash): arifle_MXC_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXC (Brown Splash Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_short_co-brownsplash.paa),
            QPATHTOF(data\mx\xmx_short_co-brownsplash.paa)
        };
        baseWeapon = QGVAR(MXC_brownsplash);
    };
    class GVAR(MX_SW_brownsplash): arifle_MX_SW_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX LMG (Brown Splash Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_lmg_co-brownsplash.paa),
            QPATHTOF(data\mx\xmx_lmg_co-brownsplash.paa)
        };
        baseWeapon = QGVAR(MX_SW_brownsplash);
    };

    // ---- Brown Swirl Camo ----
    class GVAR(MX_brownswirl): arifle_MX_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX (Brown Swirl Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-brownswirl.paa),
            QPATHTOF(data\mx\xmx_base_co-brownswirl.paa)
        };
        baseWeapon = QGVAR(MX_brownswirl);
    };
    class GVAR(MX_GL_brownswirl): arifle_MX_GL_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX 3GL (Brown Swirl Camo)";
        picture = QPATHTOF(UI\mx_gl_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-brownswirl.paa),
            "\A3\Weapons_F_EPB\Rifles\MX_Black\Data\GLX_Black_CO.paa"
        };
        baseWeapon = QGVAR(MX_GL_brownswirl);
    };
    class GVAR(MXM_brownswirl): arifle_MXM_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXM (Brown Swirl Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_long_co-brownswirl.paa),
            QPATHTOF(data\mx\xmx_long_co-brownswirl.paa)
        };
        baseWeapon = QGVAR(MXM_brownswirl);
    };
    class GVAR(MXC_brownswirl): arifle_MXC_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXC (Brown Swirl Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_short_co-brownswirl.paa),
            QPATHTOF(data\mx\xmx_short_co-brownswirl.paa)
        };
        baseWeapon = QGVAR(MXC_brownswirl);
    };
    class GVAR(MX_SW_brownswirl): arifle_MX_SW_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX LMG (Brown Swirl Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_lmg_co-brownswirl.paa),
            QPATHTOF(data\mx\xmx_lmg_co-brownswirl.paa)
        };
        baseWeapon = QGVAR(MX_SW_brownswirl);
    };

    // ---- Dark Green Pattern Camo ----
    class GVAR(MX_dgreenpat): arifle_MX_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX (Dark Green Pattern Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-dgreenpat.paa),
            QPATHTOF(data\mx\xmx_base_co-dgreenpat.paa)
        };
        baseWeapon = QGVAR(MX_dgreenpat);
    };
    class GVAR(MX_GL_dgreenpat): arifle_MX_GL_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX 3GL (Dark Green Pattern Camo)";
        picture = QPATHTOF(UI\mx_gl_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-dgreenpat.paa),
            "\A3\Weapons_F_EPB\Rifles\MX_Black\Data\GLX_Black_CO.paa"
        };
        baseWeapon = QGVAR(MX_GL_dgreenpat);
    };
    class GVAR(MXM_dgreenpat): arifle_MXM_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXM (Dark Green Pattern Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_long_co-dgreenpat.paa),
            QPATHTOF(data\mx\xmx_long_co-dgreenpat.paa)
        };
        baseWeapon = QGVAR(MXM_dgreenpat);
    };
    class GVAR(MXC_dgreenpat): arifle_MXC_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXC (Dark Green Pattern Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_short_co-dgreenpat.paa),
            QPATHTOF(data\mx\xmx_short_co-dgreenpat.paa)
        };
        baseWeapon = QGVAR(MXC_dgreenpat);
    };
    class GVAR(MX_SW_dgreenpat): arifle_MX_SW_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX LMG (Dark Green Pattern Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_lmg_co-dgreenpat.paa),
            QPATHTOF(data\mx\xmx_lmg_co-dgreenpat.paa)
        };
        baseWeapon = QGVAR(MX_SW_dgreenpat);
    };

    // ---- Green Digital Camo ----
    class GVAR(MX_greendig): arifle_MX_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX (Green Digital Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-greendig.paa),
            QPATHTOF(data\mx\xmx_base_co-greendig.paa)
        };
        baseWeapon = QGVAR(MX_greendig);
    };
    class GVAR(MX_GL_greendig): arifle_MX_GL_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX 3GL (Green Digital Camo)";
        picture = QPATHTOF(UI\mx_gl_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-greendig.paa),
            "\A3\Weapons_F_EPB\Rifles\MX_Black\Data\GLX_Black_CO.paa"
        };
        baseWeapon = QGVAR(MX_GL_greendig);
    };
    class GVAR(MXM_greendig): arifle_MXM_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXM (Green Digital Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_long_co-greendig.paa),
            QPATHTOF(data\mx\xmx_long_co-greendig.paa)
        };
        baseWeapon = QGVAR(MXM_greendig);
    };
    class GVAR(MXC_greendig): arifle_MXC_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXC (Green Digital Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_short_co-greendig.paa),
            QPATHTOF(data\mx\xmx_short_co-greendig.paa)
        };
        baseWeapon = QGVAR(MXC_greendig);
    };
    class GVAR(MX_SW_greendig): arifle_MX_SW_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX LMG (Green Digital Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_lmg_co-greendig.paa),
            QPATHTOF(data\mx\xmx_lmg_co-greendig.paa)
        };
        baseWeapon = QGVAR(MX_SW_greendig);
    };

    // ---- Green Hex Camo ----
    class GVAR(MX_greenhex): arifle_MX_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX (Green Hex Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-greenhex.paa),
            QPATHTOF(data\mx\xmx_base_co-greenhex.paa)
        };
        baseWeapon = QGVAR(MX_greenhex);
    };
    class GVAR(MX_GL_greenhex): arifle_MX_GL_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX 3GL (Green Hex Camo)";
        picture = QPATHTOF(UI\mx_gl_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-greenhex.paa),
            "\A3\Weapons_F_EPB\Rifles\MX_Black\Data\GLX_Black_CO.paa"
        };
        baseWeapon = QGVAR(MX_GL_greenhex);
    };
    class GVAR(MXM_greenhex): arifle_MXM_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXM (Green Hex Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_long_co-greenhex.paa),
            QPATHTOF(data\mx\xmx_long_co-greenhex.paa)
        };
        baseWeapon = QGVAR(MXM_greenhex);
    };
    class GVAR(MXC_greenhex): arifle_MXC_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXC (Green Hex Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_short_co-greenhex.paa),
            QPATHTOF(data\mx\xmx_short_co-greenhex.paa)
        };
        baseWeapon = QGVAR(MXC_greenhex);
    };
    class GVAR(MX_SW_greenhex): arifle_MX_SW_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX LMG (Green Hex Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_lmg_co-greenhex.paa),
            QPATHTOF(data\mx\xmx_lmg_co-greenhex.paa)
        };
        baseWeapon = QGVAR(MX_SW_greenhex);
    };

    // ---- Green Spray Camo ----
    class GVAR(MX_greenspray): arifle_MX_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX (Green Spray Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-greenspray.paa),
            QPATHTOF(data\mx\xmx_base_co-greenspray.paa)
        };
        baseWeapon = QGVAR(MX_greenspray);
    };
    class GVAR(MX_GL_greenspray): arifle_MX_GL_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX 3GL (Green Spray Camo)";
        picture = QPATHTOF(UI\mx_gl_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-greenspray.paa),
            "\A3\Weapons_F_EPB\Rifles\MX_Black\Data\GLX_Black_CO.paa"
        };
        baseWeapon = QGVAR(MX_GL_greenspray);
    };
    class GVAR(MXM_greenspray): arifle_MXM_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXM (Green Spray Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_long_co-greenspray.paa),
            QPATHTOF(data\mx\xmx_long_co-greenspray.paa)
        };
        baseWeapon = QGVAR(MXM_greenspray);
    };
    class GVAR(MXC_greenspray): arifle_MXC_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXC (Green Spray Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_short_co-greenspray.paa),
            QPATHTOF(data\mx\xmx_short_co-greenspray.paa)
        };
        baseWeapon = QGVAR(MXC_greenspray);
    };
    class GVAR(MX_SW_greenspray): arifle_MX_SW_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX LMG (Green Spray Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_lmg_co-greenspray.paa),
            QPATHTOF(data\mx\xmx_lmg_co-greenspray.paa)
        };
        baseWeapon = QGVAR(MX_SW_greenspray);
    };

    // ---- Green Pattern Camo ----
    class GVAR(MX_greenstrip): arifle_MX_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX (Green Pattern Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-greenstrip.paa),
            QPATHTOF(data\mx\xmx_base_co-greenstrip.paa)
        };
        baseWeapon = QGVAR(MX_greenstrip);
    };
    class GVAR(MX_GL_greenstrip): arifle_MX_GL_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX 3GL (Green Pattern Camo)";
        picture = QPATHTOF(UI\mx_gl_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-greenstrip.paa),
            "\A3\Weapons_F_EPB\Rifles\MX_Black\Data\GLX_Black_CO.paa"
        };
        baseWeapon = QGVAR(MX_GL_greenstrip);
    };
    class GVAR(MXM_greenstrip): arifle_MXM_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXM (Green Pattern Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_long_co-greenstrip.paa),
            QPATHTOF(data\mx\xmx_long_co-greenstrip.paa)
        };
        baseWeapon = QGVAR(MXM_greenstrip);
    };
    class GVAR(MXC_greenstrip): arifle_MXC_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXC (Green Pattern Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_short_co-greenstrip.paa),
            QPATHTOF(data\mx\xmx_short_co-greenstrip.paa)
        };
        baseWeapon = QGVAR(MXC_greenstrip);
    };
    class GVAR(MX_SW_greenstrip): arifle_MX_SW_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX LMG (Green Pattern Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_lmg_co-greenstrip.paa),
            QPATHTOF(data\mx\xmx_lmg_co-greenstrip.paa)
        };
        baseWeapon = QGVAR(MX_SW_greenstrip);
    };

    // ---- Green X's Camo ----
    class GVAR(MX_greenx): arifle_MX_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX (Green X's Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-greenx.paa),
            QPATHTOF(data\mx\xmx_base_co-greenx.paa)
        };
        baseWeapon = QGVAR(MX_greenx);
    };
    class GVAR(MX_GL_greenx): arifle_MX_GL_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX 3GL (Green X's Camo)";
        picture = QPATHTOF(UI\mx_gl_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-greenx.paa),
            "\A3\Weapons_F_EPB\Rifles\MX_Black\Data\GLX_Black_CO.paa"
        };
        baseWeapon = QGVAR(MX_GL_greenx);
    };
    class GVAR(MXM_greenx): arifle_MXM_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXM (Green X's Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_long_co-greenx.paa),
            QPATHTOF(data\mx\xmx_long_co-greenx.paa)
        };
        baseWeapon = QGVAR(MXM_greenx);
    };
    class GVAR(MXC_greenx): arifle_MXC_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXC (Green X's Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_short_co-greenx.paa),
            QPATHTOF(data\mx\xmx_short_co-greenx.paa)
        };
        baseWeapon = QGVAR(MXC_greenx);
    };
    class GVAR(MX_SW_greenx): arifle_MX_SW_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX LMG (Green X's Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_lmg_co-greenx.paa),
            QPATHTOF(data\mx\xmx_lmg_co-greenx.paa)
        };
        baseWeapon = QGVAR(MX_SW_greenx);
    };

    // ---- Grey Hex Camo ----
    class GVAR(MX_greyhex): arifle_MX_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX (Grey Hex Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-greyhex.paa),
            QPATHTOF(data\mx\xmx_base_co-greyhex.paa)
        };
        baseWeapon = QGVAR(MX_greyhex);
    };
    class GVAR(MX_GL_greyhex): arifle_MX_GL_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX 3GL (Grey Hex Camo)";
        picture = QPATHTOF(UI\mx_gl_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-greyhex.paa),
            "\A3\Weapons_F_EPB\Rifles\MX_Black\Data\GLX_Black_CO.paa"
        };
        baseWeapon = QGVAR(MX_GL_greyhex);
    };
    class GVAR(MXM_greyhex): arifle_MXM_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXM (Grey Hex Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_long_co-greyhex.paa),
            QPATHTOF(data\mx\xmx_long_co-greyhex.paa)
        };
        baseWeapon = QGVAR(MXM_greyhex);
    };
    class GVAR(MXC_greyhex): arifle_MXC_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXC (Grey Hex Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_short_co-greyhex.paa),
            QPATHTOF(data\mx\xmx_short_co-greyhex.paa)
        };
        baseWeapon = QGVAR(MXC_greyhex);
    };
    class GVAR(MX_SW_greyhex): arifle_MX_SW_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX LMG (Grey Hex Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_lmg_co-greyhex.paa),
            QPATHTOF(data\mx\xmx_lmg_co-greyhex.paa)
        };
        baseWeapon = QGVAR(MX_SW_greyhex);
    };

    // ---- Sand Pattern Camo ----
    class GVAR(MX_snadpat): arifle_MX_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX (Sand Pattern Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-snadpat.paa),
            QPATHTOF(data\mx\xmx_base_co-snadpat.paa)
        };
        baseWeapon = QGVAR(MX_snadpat);
    };
    class GVAR(MX_GL_snadpat): arifle_MX_GL_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX 3GL (Sand Pattern Camo)";
        picture = QPATHTOF(UI\mx_gl_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-snadpat.paa),
            "\A3\Weapons_F_EPB\Rifles\MX_Black\Data\GLX_Black_CO.paa"
        };
        baseWeapon = QGVAR(MX_GL_snadpat);
    };
    class GVAR(MXM_snadpat): arifle_MXM_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXM (Sand Pattern Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_long_co-snadpat.paa),
            QPATHTOF(data\mx\xmx_long_co-snadpat.paa)
        };
        baseWeapon = QGVAR(MXM_snadpat);
    };
    class GVAR(MXC_snadpat): arifle_MXC_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXC (Sand Pattern Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_short_co-snadpat.paa),
            QPATHTOF(data\mx\xmx_short_co-snadpat.paa)
        };
        baseWeapon = QGVAR(MXC_snadpat);
    };
    class GVAR(MX_SW_snadpat): arifle_MX_SW_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX LMG (Sand Pattern Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_lmg_co-snadpat.paa),
            QPATHTOF(data\mx\xmx_lmg_co-snadpat.paa)
        };
        baseWeapon = QGVAR(MX_SW_snadpat);
    };

    // ---- DPSO Camo ----
    class GVAR(MX_DPSO): arifle_MX_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX (DPSO Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-DPSO.paa),
            QPATHTOF(data\mx\xmx_base_co-DPSO.paa)
        };
        baseWeapon = QGVAR(MX_DPSO);
    };
    class GVAR(MX_GL_DPSO): arifle_MX_GL_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX 3GL (DPSO Camo)";
        picture = QPATHTOF(UI\mx_gl_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co-DPSO.paa),
            "\A3\Weapons_F_EPB\Rifles\MX_Black\Data\GLX_Black_CO.paa"
        };
        baseWeapon = QGVAR(MX_GL_DPSO);
    };
    class GVAR(MXM_DPSO): arifle_MXM_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXM (DPSO Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_long_co-DPSO.paa),
            QPATHTOF(data\mx\xmx_long_co-DPSO.paa)
        };
        baseWeapon = QGVAR(MXM_DPSO);
    };
    class GVAR(MXC_DPSO): arifle_MXC_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXC (DPSO Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_short_co-DPSO.paa),
            QPATHTOF(data\mx\xmx_short_co-DPSO.paa)
        };
        baseWeapon = QGVAR(MXC_DPSO);
    };
    class GVAR(MX_SW_DPSO): arifle_MX_SW_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX LMG (DPSO Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_lmg_co-DPSO.paa),
            QPATHTOF(data\mx\xmx_lmg_co-DPSO.paa)
        };
        baseWeapon = QGVAR(MX_SW_DPSO);
    };

    // ---- Brush Camo ----
    class GVAR(MX_brush): arifle_MX_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX (Brush Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co_brush.paa),
            QPATHTOF(data\mx\xmx_base_co_brush.paa)
        };
        baseWeapon = QGVAR(MX_brush);
    };
    class GVAR(MX_GL_brush): arifle_MX_GL_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX 3GL (Brush Camo)";
        picture = QPATHTOF(UI\mx_gl_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co_brush.paa),
            "\A3\Weapons_F_EPB\Rifles\MX_Black\Data\GLX_Black_CO.paa"
        };
        baseWeapon = QGVAR(MX_GL_brush);
    };
    class GVAR(MXM_brush): arifle_MXM_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXM (Brush Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_long_co_brush.paa),
            QPATHTOF(data\mx\xmx_long_co_brush.paa)
        };
        baseWeapon = QGVAR(MXM_brush);
    };
    class GVAR(MXC_brush): arifle_MXC_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXC (Brush Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_short_co_brush.paa),
            QPATHTOF(data\mx\xmx_short_co_brush.paa)
        };
        baseWeapon = QGVAR(MXC_brush);
    };
    class GVAR(MX_SW_brush): arifle_MX_SW_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX LMG (Brush Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_lmg_co_brush.paa),
            QPATHTOF(data\mx\xmx_lmg_co_brush.paa)
        };
        baseWeapon = QGVAR(MX_SW_brush);
    };

    // ---- Trash Camo ----
    class GVAR(MX_trash): arifle_MX_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX (Trash Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co_trash.paa),
            QPATHTOF(data\mx\xmx_base_co_trash.paa)
        };
        baseWeapon = QGVAR(MX_trash);
    };
    class GVAR(MX_GL_trash): arifle_MX_GL_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX 3GL (Trash Camo)";
        picture = QPATHTOF(UI\mx_gl_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co_trash.paa),
            "\A3\Weapons_F_EPB\Rifles\MX_Black\Data\GLX_Black_CO.paa"
        };
        baseWeapon = QGVAR(MX_GL_trash);
    };
    class GVAR(MXM_trash): arifle_MXM_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXM (Trash Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_long_co_trash.paa),
            QPATHTOF(data\mx\xmx_long_co_trash.paa)
        };
        baseWeapon = QGVAR(MXM_trash);
    };
    class GVAR(MXC_trash): arifle_MXC_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXC (Trash Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_short_co_trash.paa),
            QPATHTOF(data\mx\xmx_short_co_trash.paa)
        };
        baseWeapon = QGVAR(MXC_trash);
    };
    class GVAR(MX_SW_trash): arifle_MX_SW_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX LMG (Trash Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_lmg_co_trash.paa),
            QPATHTOF(data\mx\xmx_lmg_co_trash.paa)
        };
        baseWeapon = QGVAR(MX_SW_trash);
    };

    // ---- YonV2 Camo ----
    class GVAR(MX_yonv2): arifle_MX_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX (YonV2 Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co_yonv2.paa),
            QPATHTOF(data\mx\xmx_base_co_yonv2.paa)
        };
        baseWeapon = QGVAR(MX_yonv2);
    };
    class GVAR(MX_GL_yonv2): arifle_MX_GL_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX 3GL (YonV2 Camo)";
        picture = QPATHTOF(UI\mx_gl_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_base_co_yonv2.paa),
            "\A3\Weapons_F_EPB\Rifles\MX_Black\Data\GLX_Black_CO.paa"
        };
        baseWeapon = QGVAR(MX_GL_yonv2);
    };
    class GVAR(MXM_yonv2): arifle_MXM_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXM (YonV2 Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_long_co_yonv2.paa),
            QPATHTOF(data\mx\xmx_long_co_yonv2.paa)
        };
        baseWeapon = QGVAR(MXM_yonv2);
    };
    class GVAR(MXC_yonv2): arifle_MXC_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MXC (YonV2 Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_short_co_yonv2.paa),
            QPATHTOF(data\mx\xmx_short_co_yonv2.paa)
        };
        baseWeapon = QGVAR(MXC_yonv2);
    };
    class GVAR(MX_SW_yonv2): arifle_MX_SW_Black_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "YonV";
        displayName = "[JMSB] MX LMG (YonV2 Camo)";
        picture = QPATHTOF(UI\mx_blackcamo_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mx\xmx_lmg_co_yonv2.paa),
            QPATHTOF(data\mx\xmx_lmg_co_yonv2.paa)
        };
        baseWeapon = QGVAR(MX_SW_yonv2);
    };

    // ---- Marksman / Rifles / Pistols / Launchers ----

    class srifle_EBR_F;
    class GVAR(EBR_Black_F): srifle_EBR_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "Tyrone";
        displayName = "[JMSB] Mk14 Mod 1 EBR (Anodised Black)";
        picture = QPATHTOF(UI\mk14_ebr_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\m14_ebr01_blackcamo_co.paa),
            QPATHTOF(data\m14_ebr02_blackcamo_co.paa)
        };
        baseWeapon = QGVAR(EBR_Black_F);
    };

    class arifle_Mk20_plain_F;
    class GVAR(Mk20_Black_F): arifle_Mk20_plain_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "Tyrone";
        displayName = "[JMSB] F2000 (Black Camo)";
        picture = QPATHTOF(UI\mk20_blackcamo_ca.paa);
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mk20_blackcamo_co.paa)
        };
        baseWeapon = QGVAR(Mk20_Black_F);
    };

    class hgun_P07_F;
    class GVAR(Walther_P99): hgun_P07_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "JoramD";
        displayName = "[JMSB] Walther P99";
        picture = QPATHTOF(UI\walther_p99_ca.paa);
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {QPATHTOF(data\walther_p99_co.paa)};
        baseWeapon = QGVAR(Walther_P99);
    };
    class GVAR(Walther_P99_Tan): GVAR(Walther_P99) {
        displayName = "[JMSB] Walther P99 (Tan)";
        picture = QPATHTOF(UI\walther_p99_tan_ca.paa);
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {QPATHTOF(data\walther_p99_tan_co.paa)};
        baseWeapon = QGVAR(Walther_P99_Tan);
    };
    class GVAR(hgun_P07_blk_F): hgun_P07_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "nopryl.no";
        baseWeapon = QGVAR(hgun_P07_blk_F);
        displayName = "[JMSB] P07 (Black)";
        hiddenSelectionsTextures[] = {QPATHTOF(data\pistol\p07.paa)};
    };

    class launch_MRAWS_green_F;
    class GVAR(MRAWS_Black_F): launch_MRAWS_green_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "Kresky";
        displayName = "[JMSB] MAAWS Mk4 Mod 1 (Black)";
        picture = QPATHTOF(UI\mraws_black_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mraws_black_co.paa),
            "\A3\Weapons_F_Tank\Launchers\MRAWS\Data\launch_MRAWS_02_F_co"
        };
        baseWeapon = QGVAR(MRAWS_Black_F);
    };
    class launch_MRAWS_green_rail_F;
    class GVAR(MRAWS_Black_Rail_F): launch_MRAWS_green_rail_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "Kresky";
        displayName = "[JMSB] MAAWS Mk4 Mod 0 (Black)";
        picture = QPATHTOF(UI\mraws_black_rail_ca.paa);
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\mraws_black_co.paa),
            "\A3\Weapons_F_Tank\Launchers\MRAWS\Data\launch_MRAWS_rail_02_F_co"
        };
        baseWeapon = QGVAR(MRAWS_Black_Rail_F);
    };

    class LMG_03_F;
    class GVAR(LMG_03_brn_F): LMG_03_F {
        dlc = QUOTE(PREFIX);
        scope = 2;
        author = "nopryl.no";
        baseWeapon = QGVAR(LMG_03_brn_F);
        displayName = "[JMSB] FN Minimi SPW (Brown)";
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\lmg\minimi_01.paa),
            QPATHTOF(data\lmg\minimi_02.paa),
            "\A3\weapons_f\machineguns\m200\data\grip_co.paa"
        };
    };

    // Equipped (hidden) variants
    class GVAR(MX_blackcamo_MRCO): GVAR(MX_blackcamo) {
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptics {
                slot = "CowsSlot";
                item = "optic_MRCO";
            };
        };
    };
    class GVAR(MX_blackcamo_ACO): GVAR(MX_blackcamo) {
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptics {
                slot = "CowsSlot";
                item = "optic_aco";
            };
        };
    };
    class GVAR(MX_GL_blackcamo_ACO): GVAR(MX_GL_blackcamo) {
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptics {
                slot = "CowsSlot";
                item = "optic_aco";
            };
        };
    };

};
