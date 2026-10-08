#define COMPONENT leaders
#define COMPONENT_BEAUTIFIED Leaders
#include "\z\jmfsb\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE

#ifdef DEBUG_ENABLED_LEADERS
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_LEADERS
    #define DEBUG_SETTINGS DEBUG_SETTINGS_LEADERS
#endif

#include "\z\jmfsb\addons\main\script_macros.hpp"

// FINITE by design (new.md rule 5). Three, and nothing ever replaces one.
#define LEADERS_COUNT       3

// The ladder a safe-house fix walks down, and how far off-centre it is thrown.
#define LEADERS_RADII       [3000, 2000, 1000]
#define LEADERS_OFFSET      0.6

// Markers, not modules: WHERE comes from the map (new.md rule 2).
#define LEADERS_PRISON      "jmfsb_prison"

// How close a handcuffed leader must be delivered, and how often that is
// checked.
#define LEADERS_PRISON_R    50
#define LEADERS_PRISON_TICK 10

// A house counts as entered at this range, and a sprung trap is this heavy.
// How far from the safe house his car is parked, and how close the drive has
// to get before he counts as arrived. The completion radius is generous: a car
// stopping exactly on a building is not something Arma's driver does well.
#define LEADERS_CAR_RANGE   80
// how far from a house FUNC(parkSpot) will accept a kerb as "outside it"
#define LEADERS_PARK_ROAD   70
#define LEADERS_ARRIVE_R    60
// Seconds between reaching the town and being in position, so he is seen
// getting out rather than teleporting the moment the car stops.
#define LEADERS_DISMOUNT    12

// Civilian cars, best first. He hides among the population and moves the way
// the population moves - an armed technical outside a house says "search this
// one". First class that exists in the mission's mod set wins.
#define LEADERS_CAR_CLASSES ["C_Offroad_01_F", "C_SUV_01_F", "C_Hatchback_01_F", "C_Van_01_transport_F", "C_Offroad_02_unarmed_F"]

#define LEADERS_HOUSE_R     15
#define LEADERS_TRAP_AMMO   "Sh_82mm_AMOS"
#define LEADERS_TRAP_DISP   50
