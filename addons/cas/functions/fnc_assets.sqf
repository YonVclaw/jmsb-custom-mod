#include "script_component.hpp"
/*
 * Author: JMSB
 * Every CAS module this side owns, as support-page rows.
 *
 * REGISTERED AS A PROVIDER, NOT BOLTED INTO THE ADAPTER. The support page used
 * to have exactly one source of assets - ALiVE - and the page called it by
 * name. Naming this addon in there instead would have put a jmfsb system
 * inside the adapter seam that check_invariants.py exists to keep clean. So
 * the seam grew a neutral registry and this publishes into it: the adapter
 * never learns this addon's name, and this addon never learns ALiVE's.
 *
 * SIDE IS THE VIEWER'S. A support page is drawn for the man looking at it, and
 * he may not task another side's aircraft.
 *
 * Arguments: None
 *
 * Return Value:
 * Rows <ARRAY>
 *
 * Public: No
 */

private _side = side group player;

(GVAR(entities) select {
    !isNull _x && {(_x getVariable [QGVAR(side), sideUnknown]) isEqualTo _side}
}) apply {
    [_x] call FUNC(entityRow)
} select {
    _x isNotEqualTo []
}
