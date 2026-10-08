// An on/off attribute, the way jmfsb_iads writes them.
#define ABOOL(NAME,DEFONOFF,LBL,DESC) \
    class NAME: Combo { \
        property = QUOTE(TRIPLES(jmfsb,COMPONENT,NAME)); \
        displayName = LBL; \
        tooltip = DESC; \
        typeName = "STRING"; \
        defaultValue = DEFONOFF; \
        expression = QUOTE(_this setVariable [ARR_2('NAME',_value isEqualTo 'true')]); \
        class Values { \
            class off { name = "Off"; value = "false"; }; \
            class on  { name = "On";  value = "true"; }; \
        }; \
    }

#define ANUM(NAME,DEF,LBL,DESC) \
    class NAME: Edit { \
        property = QUOTE(TRIPLES(jmfsb,COMPONENT,NAME)); \
        displayName = LBL; \
        tooltip = DESC; \
        typeName = "NUMBER"; \
        defaultValue = DEF; \
        expression = QUOTE(_this setVariable [ARR_2('NAME',_value)]); \
    }

class CfgVehicles {
    class Logic;
    class Module_F: Logic {
        class AttributesBase {
            class Edit;
            class Combo;
        };
        class ModuleDescription;
    };

    // ONE SITE PER MODULE. Sync it to the vehicles that make the Site - radars,
    // launchers, guns, a CIWS - and they defend its area together. Batteries
    // jmfsb_airdefence places for ALiVE's commanders become Sites on their own,
    // with these attributes' defaults; this module is for the ones a mission
    // maker builds.
    //
    // Every number here is how the Site OPERATES. Where it is and what is in it
    // are the module's position and its sync - nothing here names a side.
    class jmfsb_moduleADSite: Module_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "JMSB - Air Defence Site";
        author = QAUTHOR;
        category = "jmfsb_modules";
        function = QUOTE(DFUNC(moduleSite));
        functionPriority = 2;
        isGlobal = 0;
        isTriggerActivated = 0;
        isDisposable = 0;
        is3DEN = 0;
        icon = "\a3\ui_f\data\map\markers\nato\b_antiair.paa";

        class Attributes: AttributesBase {
            class siteName: Edit {
                property = QGVAR(siteName);
                displayName = "Site Name";
                tooltip = "What the notices and the tacpad call this Site. Blank uses the map grid.";
                typeName = "STRING";
                defaultValue = "''";
                expression = QUOTE(_this setVariable [ARR_2('siteName',_value)]);
            };
            ANUM(radius,"800","Protected Radius (m)","The area this Site defends, around the module. Incoming munitions are engaged only while their predicted impact is inside it - a shell landing clear costs nothing.");
            class link: Edit {
                property = QGVAR(link);
                displayName = "Link";
                tooltip = "Sites with the same link share one picture and one coordinator, so two batteries never fire at one target. Blank is a Site on its own.";
                typeName = "STRING";
                defaultValue = "''";
                expression = QUOTE(_this setVariable [ARR_2('link',_value)]);
            };
            ABOOL(automation,"true","Automation","On: the Site engages by itself. Off: it tracks, warns and waits for orders from the tacpad.");
            ABOOL(engageAir,"true","Engage Aircraft","Hostile aircraft, by the sides' relations.");
            ABOOL(engageMunitions,"true","Engage Munitions","Missiles, rockets, bombs, artillery, mortar and MLRS rounds heading into the protected area.");
            class emcon: Combo {
                property = QGVAR(emcon);
                displayName = "Radar Emission";
                tooltip = "AUTOMATIC: the radars run under jmfsb_iads' blink, or freely without it. SILENT UNTIL CUED: dark until a linked Site, a passive sensor or a launch cues them. BURST: one radar searches at a time, handed round the Site. Any radar a hostile anti-radiation missile is homing on goes dark until the missile is gone, whatever the mode.";
                typeName = "STRING";
                defaultValue = "'auto'";
                expression = QUOTE(_this setVariable [ARR_2('emcon',_value)]);
                class Values {
                    class auto   { name = "Automatic";          value = "auto"; };
                    class silent { name = "Silent until cued"; value = "silent"; };
                    class burst  { name = "Burst search";      value = "burst"; };
                };
            };
            ANUM(burstSeconds,"20","Burst Length (s)","In burst search, how long one radar searches before handing over.");
            ANUM(shotsPerThreat,"2","Shots Per Threat","At most this many weapons are committed to one target at once.");
            ANUM(reserveLong,"0.5","Long-Range Reserve","Long-range missiles are held for what only they can reach while more than this fraction of their rounds is left; below it they take munitions too. 0 never holds them back.");
            ANUM(reaction,"2","Crew Reaction (s)","An average crew's time from a threat being handed to it to its weapon firing. A skilled crew is faster, a poor one slower and less reliable - drawn per crew, it stays with them.");
            ANUM(fumble,"0.1","Crew Fumble Chance","For an unskilled crew, the chance an engagement costs a second fumble. A fully skilled crew never fumbles.");
            ABOOL(notices,"true","Notices","A going-live and an incoming notice to the Site's side.");
            class access: Combo {
                property = QGVAR(access);
                displayName = "Tacpad Control";
                tooltip = "Everyone on the Site's side sees its status on the tacpad. Who may change its settings, order intercepts and call strikes: its CREW (a member's crewman), anyone NEAR it (inside the protected area), or the whole SIDE.";
                typeName = "STRING";
                defaultValue = "'near'";
                expression = QUOTE(_this setVariable [ARR_2('access',_value)]);
                class Values {
                    class crew { name = "Crew";      value = "crew"; };
                    class near { name = "Near";      value = "near"; };
                    class side { name = "Whole side"; value = "side"; };
                };
            };
        };

        class ModuleDescription: ModuleDescription {
            description = "An air defence Site: sync the radars, launchers, guns and CIWS that make it. It pools what they see, gives each aircraft or incoming round to the best-fit weapon - guns inside, short-range missiles for the bulk, long-range held in reserve - fires the vehicles' own weapons, and runs on the server. Status and control are on the tacpad.";
            sync[] = {"AnyVehicle"};
        };
    };
};
