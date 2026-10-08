class XtdGearModels {
    class CfgWeapons {
        class GVAR(MX) {
            label = "MX";
            options[] = {"camo", "type"};
            class camo {
                alwaysSelectable = 1;
                values[] = {"blackcamo", "blackfine", "blackhex", "blacksploch", "browndots", "brownsplash", "brownswirl", "dgreenpat", "greendig", "greenhex", "greenspray", "greenstrip", "greenx", "greyhex", "snadpat", "DPSO", "brush", "trash", "yonv2"};
                class blackcamo { label = "Black Camo"; image = "z\aceax\addons\gearinfo\data\camo\blk.paa"; };
                class blackfine { label = "Black Fine Camo"; image = "z\aceax\addons\gearinfo\data\camo\blk.paa"; };
                class blackhex { label = "Black Hex Camo"; image = "z\aceax\addons\gearinfo\data\camo\blk.paa"; };
                class blacksploch { label = "Black Sploch Camo"; image = "z\aceax\addons\gearinfo\data\camo\blk.paa"; };
                class browndots { label = "Brown Dots Camo"; image = "z\aceax\addons\gearinfo\data\camo\khk.paa"; };
                class brownsplash { label = "Brown Splash Camo"; image = "z\aceax\addons\gearinfo\data\camo\khk.paa"; };
                class brownswirl { label = "Brown Swirl Camo"; image = "z\aceax\addons\gearinfo\data\camo\khk.paa"; };
                class dgreenpat { label = "Dark Green Pattern Camo"; image = "z\aceax\addons\gearinfo\data\camo\sage.paa"; };
                class greendig { label = "Green Digital Camo"; image = "z\aceax\addons\gearinfo\data\camo\sage.paa"; };
                class greenhex { label = "Green Hex Camo"; image = "z\aceax\addons\gearinfo\data\camo\sage.paa"; };
                class greenspray { label = "Green Spray Camo"; image = "z\aceax\addons\gearinfo\data\camo\sage.paa"; };
                class greenstrip { label = "Green Pattern Camo"; image = "z\aceax\addons\gearinfo\data\camo\sage.paa"; };
                class greenx { label = "Green X's Camo"; image = "z\aceax\addons\gearinfo\data\camo\sage.paa"; };
                class greyhex { label = "Grey Hex Camo"; image = "z\aceax\addons\gearinfo\data\camo\gry.paa"; };
                class snadpat { label = "Sand Pattern Camo"; image = "z\aceax\addons\gearinfo\data\camo\khk.paa"; };
                class DPSO { label = "DPSO Camo"; image = "z\aceax\addons\gearinfo\data\camo\sage.paa"; };
                class brush { label = "Brush Camo"; image = "z\aceax\addons\gearinfo\data\camo\sage.paa"; };
                class trash { label = "Trash Camo"; image = "z\aceax\addons\gearinfo\data\camo\blk.paa"; };
                class yonv2 { label = "YonV2 Camo"; image = "z\aceax\addons\gearinfo\data\camo\sage.paa"; };
            };
            class type {
                alwaysSelectable = 1;
                values[] = {"MX", "MX_GL", "MXM", "MXC", "MX_SW"};
                class MX { label = "MX"; };
                class MX_GL { label = "MX 3GL"; };
                class MXM { label = "MXM"; };
                class MXC { label = "MXC"; };
                class MX_SW { label = "MX LMG"; };
            };
        };
    };
};

class XtdGearInfos {
    class CfgWeapons {
        // Black Camo
        class GVAR(MX_blackcamo) {
            model = QGVAR(MX);
            camo = "blackcamo";
            type = "MX";
        };
        class GVAR(MX_GL_blackcamo) {
            model = QGVAR(MX);
            camo = "blackcamo";
            type = "MX_GL";
        };
        class GVAR(MXM_blackcamo) {
            model = QGVAR(MX);
            camo = "blackcamo";
            type = "MXM";
        };
        class GVAR(MXC_blackcamo) {
            model = QGVAR(MX);
            camo = "blackcamo";
            type = "MXC";
        };
        class GVAR(MX_SW_blackcamo) {
            model = QGVAR(MX);
            camo = "blackcamo";
            type = "MX_SW";
        };
        // Black Fine Camo
        class GVAR(MX_blackfine) {
            model = QGVAR(MX);
            camo = "blackfine";
            type = "MX";
        };
        class GVAR(MX_GL_blackfine) {
            model = QGVAR(MX);
            camo = "blackfine";
            type = "MX_GL";
        };
        class GVAR(MXM_blackfine) {
            model = QGVAR(MX);
            camo = "blackfine";
            type = "MXM";
        };
        class GVAR(MXC_blackfine) {
            model = QGVAR(MX);
            camo = "blackfine";
            type = "MXC";
        };
        class GVAR(MX_SW_blackfine) {
            model = QGVAR(MX);
            camo = "blackfine";
            type = "MX_SW";
        };
        // Black Hex Camo
        class GVAR(MX_blackhex) {
            model = QGVAR(MX);
            camo = "blackhex";
            type = "MX";
        };
        class GVAR(MX_GL_blackhex) {
            model = QGVAR(MX);
            camo = "blackhex";
            type = "MX_GL";
        };
        class GVAR(MXM_blackhex) {
            model = QGVAR(MX);
            camo = "blackhex";
            type = "MXM";
        };
        class GVAR(MXC_blackhex) {
            model = QGVAR(MX);
            camo = "blackhex";
            type = "MXC";
        };
        class GVAR(MX_SW_blackhex) {
            model = QGVAR(MX);
            camo = "blackhex";
            type = "MX_SW";
        };
        // Black Sploch Camo
        class GVAR(MX_blacksploch) {
            model = QGVAR(MX);
            camo = "blacksploch";
            type = "MX";
        };
        class GVAR(MX_GL_blacksploch) {
            model = QGVAR(MX);
            camo = "blacksploch";
            type = "MX_GL";
        };
        class GVAR(MXM_blacksploch) {
            model = QGVAR(MX);
            camo = "blacksploch";
            type = "MXM";
        };
        class GVAR(MXC_blacksploch) {
            model = QGVAR(MX);
            camo = "blacksploch";
            type = "MXC";
        };
        class GVAR(MX_SW_blacksploch) {
            model = QGVAR(MX);
            camo = "blacksploch";
            type = "MX_SW";
        };
        // Brown Dots Camo
        class GVAR(MX_browndots) {
            model = QGVAR(MX);
            camo = "browndots";
            type = "MX";
        };
        class GVAR(MX_GL_browndots) {
            model = QGVAR(MX);
            camo = "browndots";
            type = "MX_GL";
        };
        class GVAR(MXM_browndots) {
            model = QGVAR(MX);
            camo = "browndots";
            type = "MXM";
        };
        class GVAR(MXC_browndots) {
            model = QGVAR(MX);
            camo = "browndots";
            type = "MXC";
        };
        class GVAR(MX_SW_browndots) {
            model = QGVAR(MX);
            camo = "browndots";
            type = "MX_SW";
        };
        // Brown Splash Camo
        class GVAR(MX_brownsplash) {
            model = QGVAR(MX);
            camo = "brownsplash";
            type = "MX";
        };
        class GVAR(MX_GL_brownsplash) {
            model = QGVAR(MX);
            camo = "brownsplash";
            type = "MX_GL";
        };
        class GVAR(MXM_brownsplash) {
            model = QGVAR(MX);
            camo = "brownsplash";
            type = "MXM";
        };
        class GVAR(MXC_brownsplash) {
            model = QGVAR(MX);
            camo = "brownsplash";
            type = "MXC";
        };
        class GVAR(MX_SW_brownsplash) {
            model = QGVAR(MX);
            camo = "brownsplash";
            type = "MX_SW";
        };
        // Brown Swirl Camo
        class GVAR(MX_brownswirl) {
            model = QGVAR(MX);
            camo = "brownswirl";
            type = "MX";
        };
        class GVAR(MX_GL_brownswirl) {
            model = QGVAR(MX);
            camo = "brownswirl";
            type = "MX_GL";
        };
        class GVAR(MXM_brownswirl) {
            model = QGVAR(MX);
            camo = "brownswirl";
            type = "MXM";
        };
        class GVAR(MXC_brownswirl) {
            model = QGVAR(MX);
            camo = "brownswirl";
            type = "MXC";
        };
        class GVAR(MX_SW_brownswirl) {
            model = QGVAR(MX);
            camo = "brownswirl";
            type = "MX_SW";
        };
        // Dark Green Pattern Camo
        class GVAR(MX_dgreenpat) {
            model = QGVAR(MX);
            camo = "dgreenpat";
            type = "MX";
        };
        class GVAR(MX_GL_dgreenpat) {
            model = QGVAR(MX);
            camo = "dgreenpat";
            type = "MX_GL";
        };
        class GVAR(MXM_dgreenpat) {
            model = QGVAR(MX);
            camo = "dgreenpat";
            type = "MXM";
        };
        class GVAR(MXC_dgreenpat) {
            model = QGVAR(MX);
            camo = "dgreenpat";
            type = "MXC";
        };
        class GVAR(MX_SW_dgreenpat) {
            model = QGVAR(MX);
            camo = "dgreenpat";
            type = "MX_SW";
        };
        // Green Digital Camo
        class GVAR(MX_greendig) {
            model = QGVAR(MX);
            camo = "greendig";
            type = "MX";
        };
        class GVAR(MX_GL_greendig) {
            model = QGVAR(MX);
            camo = "greendig";
            type = "MX_GL";
        };
        class GVAR(MXM_greendig) {
            model = QGVAR(MX);
            camo = "greendig";
            type = "MXM";
        };
        class GVAR(MXC_greendig) {
            model = QGVAR(MX);
            camo = "greendig";
            type = "MXC";
        };
        class GVAR(MX_SW_greendig) {
            model = QGVAR(MX);
            camo = "greendig";
            type = "MX_SW";
        };
        // Green Hex Camo
        class GVAR(MX_greenhex) {
            model = QGVAR(MX);
            camo = "greenhex";
            type = "MX";
        };
        class GVAR(MX_GL_greenhex) {
            model = QGVAR(MX);
            camo = "greenhex";
            type = "MX_GL";
        };
        class GVAR(MXM_greenhex) {
            model = QGVAR(MX);
            camo = "greenhex";
            type = "MXM";
        };
        class GVAR(MXC_greenhex) {
            model = QGVAR(MX);
            camo = "greenhex";
            type = "MXC";
        };
        class GVAR(MX_SW_greenhex) {
            model = QGVAR(MX);
            camo = "greenhex";
            type = "MX_SW";
        };
        // Green Spray Camo
        class GVAR(MX_greenspray) {
            model = QGVAR(MX);
            camo = "greenspray";
            type = "MX";
        };
        class GVAR(MX_GL_greenspray) {
            model = QGVAR(MX);
            camo = "greenspray";
            type = "MX_GL";
        };
        class GVAR(MXM_greenspray) {
            model = QGVAR(MX);
            camo = "greenspray";
            type = "MXM";
        };
        class GVAR(MXC_greenspray) {
            model = QGVAR(MX);
            camo = "greenspray";
            type = "MXC";
        };
        class GVAR(MX_SW_greenspray) {
            model = QGVAR(MX);
            camo = "greenspray";
            type = "MX_SW";
        };
        // Green Pattern Camo
        class GVAR(MX_greenstrip) {
            model = QGVAR(MX);
            camo = "greenstrip";
            type = "MX";
        };
        class GVAR(MX_GL_greenstrip) {
            model = QGVAR(MX);
            camo = "greenstrip";
            type = "MX_GL";
        };
        class GVAR(MXM_greenstrip) {
            model = QGVAR(MX);
            camo = "greenstrip";
            type = "MXM";
        };
        class GVAR(MXC_greenstrip) {
            model = QGVAR(MX);
            camo = "greenstrip";
            type = "MXC";
        };
        class GVAR(MX_SW_greenstrip) {
            model = QGVAR(MX);
            camo = "greenstrip";
            type = "MX_SW";
        };
        // Green X's Camo
        class GVAR(MX_greenx) {
            model = QGVAR(MX);
            camo = "greenx";
            type = "MX";
        };
        class GVAR(MX_GL_greenx) {
            model = QGVAR(MX);
            camo = "greenx";
            type = "MX_GL";
        };
        class GVAR(MXM_greenx) {
            model = QGVAR(MX);
            camo = "greenx";
            type = "MXM";
        };
        class GVAR(MXC_greenx) {
            model = QGVAR(MX);
            camo = "greenx";
            type = "MXC";
        };
        class GVAR(MX_SW_greenx) {
            model = QGVAR(MX);
            camo = "greenx";
            type = "MX_SW";
        };
        // Grey Hex Camo
        class GVAR(MX_greyhex) {
            model = QGVAR(MX);
            camo = "greyhex";
            type = "MX";
        };
        class GVAR(MX_GL_greyhex) {
            model = QGVAR(MX);
            camo = "greyhex";
            type = "MX_GL";
        };
        class GVAR(MXM_greyhex) {
            model = QGVAR(MX);
            camo = "greyhex";
            type = "MXM";
        };
        class GVAR(MXC_greyhex) {
            model = QGVAR(MX);
            camo = "greyhex";
            type = "MXC";
        };
        class GVAR(MX_SW_greyhex) {
            model = QGVAR(MX);
            camo = "greyhex";
            type = "MX_SW";
        };
        // Sand Pattern Camo
        class GVAR(MX_snadpat) {
            model = QGVAR(MX);
            camo = "snadpat";
            type = "MX";
        };
        class GVAR(MX_GL_snadpat) {
            model = QGVAR(MX);
            camo = "snadpat";
            type = "MX_GL";
        };
        class GVAR(MXM_snadpat) {
            model = QGVAR(MX);
            camo = "snadpat";
            type = "MXM";
        };
        class GVAR(MXC_snadpat) {
            model = QGVAR(MX);
            camo = "snadpat";
            type = "MXC";
        };
        class GVAR(MX_SW_snadpat) {
            model = QGVAR(MX);
            camo = "snadpat";
            type = "MX_SW";
        };
        // DPSO Camo
        class GVAR(MX_DPSO) {
            model = QGVAR(MX);
            camo = "DPSO";
            type = "MX";
        };
        class GVAR(MX_GL_DPSO) {
            model = QGVAR(MX);
            camo = "DPSO";
            type = "MX_GL";
        };
        class GVAR(MXM_DPSO) {
            model = QGVAR(MX);
            camo = "DPSO";
            type = "MXM";
        };
        class GVAR(MXC_DPSO) {
            model = QGVAR(MX);
            camo = "DPSO";
            type = "MXC";
        };
        class GVAR(MX_SW_DPSO) {
            model = QGVAR(MX);
            camo = "DPSO";
            type = "MX_SW";
        };
        // Brush Camo
        class GVAR(MX_brush) {
            model = QGVAR(MX);
            camo = "brush";
            type = "MX";
        };
        class GVAR(MX_GL_brush) {
            model = QGVAR(MX);
            camo = "brush";
            type = "MX_GL";
        };
        class GVAR(MXM_brush) {
            model = QGVAR(MX);
            camo = "brush";
            type = "MXM";
        };
        class GVAR(MXC_brush) {
            model = QGVAR(MX);
            camo = "brush";
            type = "MXC";
        };
        class GVAR(MX_SW_brush) {
            model = QGVAR(MX);
            camo = "brush";
            type = "MX_SW";
        };
        // Trash Camo
        class GVAR(MX_trash) {
            model = QGVAR(MX);
            camo = "trash";
            type = "MX";
        };
        class GVAR(MX_GL_trash) {
            model = QGVAR(MX);
            camo = "trash";
            type = "MX_GL";
        };
        class GVAR(MXM_trash) {
            model = QGVAR(MX);
            camo = "trash";
            type = "MXM";
        };
        class GVAR(MXC_trash) {
            model = QGVAR(MX);
            camo = "trash";
            type = "MXC";
        };
        class GVAR(MX_SW_trash) {
            model = QGVAR(MX);
            camo = "trash";
            type = "MX_SW";
        };
        // YonV2 Camo
        class GVAR(MX_yonv2) {
            model = QGVAR(MX);
            camo = "yonv2";
            type = "MX";
        };
        class GVAR(MX_GL_yonv2) {
            model = QGVAR(MX);
            camo = "yonv2";
            type = "MX_GL";
        };
        class GVAR(MXM_yonv2) {
            model = QGVAR(MX);
            camo = "yonv2";
            type = "MXM";
        };
        class GVAR(MXC_yonv2) {
            model = QGVAR(MX);
            camo = "yonv2";
            type = "MXC";
        };
        class GVAR(MX_SW_yonv2) {
            model = QGVAR(MX);
            camo = "yonv2";
            type = "MX_SW";
        };
    };
};
