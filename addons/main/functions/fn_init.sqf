// Registers the keybind on every client. Runs automatically via CfgFunctions postInit,
// no code in the mission is required.
if (!hasInterface) exitWith {};

ZMC_dialogIDD = 86600;	// must match idd of MissionControlGUI in config.cpp

[] spawn {
	waitUntil {!isNull findDisplay 46};

	// Keybind: Ctrl+Shift+Y by default (Z on QWERTZ layouts; DIK codes are
	// physical key positions), overridable in description.ext:
	// class MissionControl { key = 21; shift = 1; ctrl = 1; alt = 0; };
	private _cfg = missionConfigFile >> "MissionControl";
	private _readNum = {
		params ["_entry", "_default"];
		if (isNumber _entry) then {getNumber _entry} else {_default}
	};
	ZMC_key      = [_cfg >> "key",   21] call _readNum;  // DIK_Y = 0x15
	ZMC_keyShift = ([_cfg >> "shift", 1] call _readNum) > 0;
	ZMC_keyCtrl  = ([_cfg >> "ctrl",  1] call _readNum) > 0;
	ZMC_keyAlt   = ([_cfg >> "alt",   0] call _readNum) > 0;

	(findDisplay 46) displayAddEventHandler ["KeyDown", {_this call ZMC_fnc_keyDown}];

	// The Zeus display (312) is recreated every time the interface opens, so
	// the handler has to be re-attached each time. While Zeus is open, key
	// events go to 312 instead of 46; without this the combo would trigger
	// Zeus' own camera actions instead of the console.
	while {true} do {
		waitUntil {sleep 0.5; !isNull findDisplay 312};
		private _zeus = findDisplay 312;
		_zeus displayAddEventHandler ["KeyDown", {_this call ZMC_fnc_keyDown}];
		// Swallow the matching KeyUp too, so Zeus actions bound to the key
		// release do not fire after the console was toggled.
		_zeus displayAddEventHandler ["KeyUp", {
			params ["", "_key"];
			_key == ZMC_key
		}];
		waitUntil {sleep 0.5; isNull findDisplay 312};
	};
};
