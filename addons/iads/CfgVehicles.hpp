// Modern 3DEN attribute system, as used across the jmfsb modules.

#define AEDIT(NAME,TYPE,DEF,LBL,DESC) \
    class NAME: Edit { \
        property = QUOTE(TRIPLES(jmfsb,COMPONENT,NAME)); \
        displayName = LBL; \
        tooltip = DESC; \
        typeName = TYPE; \
        defaultValue = DEF; \
        expression = QUOTE(_this setVariable [ARR_2('NAME',_value)]); \
    }

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

class CfgVehicles {
    class Logic;
    class Module_F: Logic {
        class AttributesBase {
            class Edit;
            class Combo;
        };
        class ModuleDescription;
    };

    // PLACING THIS MODULE IS THE ENABLE. Without it every radar on the map
    // radiates continuously, which is the game's own behaviour and a perfectly
    // reasonable mission.
    //
    // NO SIDE ATTRIBUTE, BY RULE (D59). Sides are typed once in this mod, and a
    // third module asking "which side?" is a regression rather than a feature.
    // This manages every side the players are NOT on - the same derivation
    // jmfsb_uas uses to keep enemy drones off friendly commanders, see
    // FUNC(sides). A player-side SAM belongs to the players and nothing here
    // reaches into it.
    //
    // ONE MODULE RUNS THE SYSTEM. A second placement is refused with a warning
    // rather than arming a second scheduler over the same radars, which would
    // be two schedulers fighting over one switch.
    class jmfsb_moduleIADS: Module_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "JMSB - IADS / EMCON";
        author = QAUTHOR;
        category = "jmfsb_modules";
        function = QUOTE(DFUNC(moduleController));
        functionPriority = 1;
        isGlobal = 0;
        isTriggerActivated = 0;
        isDisposable = 0;
        is3DEN = 0;
        icon = "\a3\ui_f\data\map\markers\nato\o_antiair.paa";

        class Attributes: AttributesBase {
            // THE BLINK IS A RANGE, NOT AN INTERVAL, and every set re-rolls its
            // own timer inside it. A single number is a metronome, and a
            // metronome is learnable: count to twenty, cross while it is down.
            AEDIT(blinkMin,"NUMBER","20","Blink Min (sec)","Shortest a radar holds one state - lit or dark - before it re-rolls. Each set rolls its own, so the net never goes quiet all at once.");
            AEDIT(blinkMax,"NUMBER","40","Blink Max (sec)","Longest a radar holds one state before it re-rolls. Set this equal to the minimum to get a metronome, which is a thing a player can time.");
            // THE FLOOR IS WHAT MAKES IT A NETWORK rather than a field of
            // independently twitching sets: somebody is always looking.
            AEDIT(minEmitters,"NUMBER","1","Minimum Emitters","How many radars per side stay lit whatever the blink says - the set that has been dark longest is the one brought back up. 0 lets a whole side go dark at once: pure random blinking.");
            AEDIT(rescan,"NUMBER","5","Rescan (min)","How often the net looks for radars that were not there last time - ALiVE spawns, jmfsb_airdefence batteries, anything a mission built mid-game. 0 scans once at start and never again.");
            ABOOL(manageAir,"'false'","Manage Aircraft","Off: only ground vehicles and statics blink. An AI pilot manages his own emissions and a scheduler fighting him is two systems on one switch. On: aircraft radars blink too.");
            AEDIT(exempt,"STRING","''","Always-On Classes","Comma-separated classnames pinned lit - an early-warning set that is MEANT to be found, or the one radar a mission is built around. They still feed the datalink; they simply never go dark.");

            // --- the picture ---------------------------------------------
            ABOOL(linkAll,"'false'","Link Whole Side","Off: the radars and the air-defence shooters found beside them share the picture. On: every vehicle on the side reports and receives - the full 2040 datalink, and it will touch vehicles other systems may be managing.");
            AEDIT(extraReceivers,"STRING","''","Extra Receiver Classes","Comma-separated classnames handed the picture on top of what the config sweep finds, for a launcher whose config does not admit what it is.");
            AEDIT(revealEvery,"NUMBER","10","Reveal Interval (sec)","How often the net files what it holds on its side's threat board, so the rest of the mod can act on what the radars see. 0 keeps the picture inside the air-defence net.");

            // --- pop-up ambush, gated -------------------------------------
            ABOOL(ambush,"'false'","Ambush Mode","UNVERIFIED - leave off until `#jmfsb iads.probe` says a radarless launcher will FIRE on a datalink track and not merely display it (P0-3). On: a dark site lights only when a shared track enters its envelope, shoots, and goes dark again.");
            AEDIT(envelope,"NUMBER","4000","Ambush Envelope (m)","How close a shared track has to be before a dark site lights up. A difficulty knob rather than a missile range: large lights early and can be baited, small lights too late to shoot.");

            ABOOL(debugMarkers,"'false'","Debug Markers","A marker per managed radar - lit or dark, with its class. For tuning a mission, not for playing one: it shows the players exactly what they are meant to be hunting.");
        };

        class ModuleDescription: ModuleDescription {
            description[] = {
                "Emission control for the air defence net. Every radar the enemy has blinks on and off on its own jittered timer, a minimum number stay lit so the side is never blind, and everything on the net shares one picture.",
                "",
                "WHY IT MATTERS: a radar that never stops radiating is a beacon that can be waited out. One that blinks cannot - a strike has to accept that something will see it, and the pilot's problem becomes timing rather than patience.",
                "",
                "It manages every side the players are not on. Nothing is placed and nothing is spawned: it manages the radars already standing, whoever put them there.",
                "",
                "Blink Min / Max - the range each set re-rolls its own timer in",
                "Minimum Emitters - how many stay lit per side, whatever the blink says",
                "Rescan - how often it looks for radars that were not there before",
                "Link Whole Side - share the picture beyond the air-defence net",
                "Reveal Interval - how often the picture reaches the mod's threat board",
                "Ambush Mode - UNVERIFIED, see the tooltip and run `#jmfsb iads.probe` first"
            };
        };
    };
};
