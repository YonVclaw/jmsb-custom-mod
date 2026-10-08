[
    "1st Joint Multi-Functional Strike Battalion",
    QGVAR(placeTargetMarker),
    ["Vector: Place Target Marker", "Places a map marker on the point aimed at through a [JMSB] Vector Designator."],
    {
        call FUNC(placeTargetMarker) // return
    },
    {},
    [50, [true, true, false]]   // Ctrl+Shift+M
] call CBA_fnc_addKeybind;

// THE PERSONAL WAYPOINT, next door to the target marker on the keyboard because
// they are the same gesture with different audiences - one goes to the section,
// one stays with you.
[
    "1st Joint Multi-Functional Strike Battalion",
    QGVAR(placeWaypoint),
    ["Vector: Place Personal Waypoint", "Drops a waypoint only you can see on the point aimed at through a [JMSB] Vector Designator. One at a time; aim at it again to clear it."],
    {
        call FUNC(placeWaypoint) // return
    },
    {},
    [49, [true, true, false]]   // Ctrl+Shift+N
] call CBA_fnc_addKeybind;
