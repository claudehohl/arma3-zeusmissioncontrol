// Shared KeyDown handler, attached to the mission display (46), the Zeus
// display (312) and the console dialog itself. Toggles the console on the
// configured combo and returns true so the display's own key handling
// (e.g. Zeus camera actions) never sees the keypress.
params ["_display", "_key", "_shift", "_ctrl", "_alt"];

if (
	_key == ZMC_key
	&& {_shift isEqualTo ZMC_keyShift}
	&& {_ctrl isEqualTo ZMC_keyCtrl}
	&& {_alt isEqualTo ZMC_keyAlt}
) exitWith {
	call ZMC_fnc_openDialog;
	true
};
false
