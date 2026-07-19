// Dialog onLoad: label the action buttons from the mission's description.ext,
// hide buttons whose action class is not defined.
params ["_display"];

// While the dialog is open it receives all key events, so it needs the
// keybind handler itself for the combo to close it again.
_display displayAddEventHandler ["KeyDown", {_this call ZMC_fnc_keyDown}];

private _cfg = missionConfigFile >> "MissionControl";
for "_i" from 1 to 8 do {
	private _ctrl = _display displayCtrl (1600 + _i);
	private _actionCfg = _cfg >> format ["Action%1", _i];
	if (isClass _actionCfg) then {
		private _text = getText (_actionCfg >> "text");
		if (_text isEqualTo "") then {_text = format ["Action %1", _i]};
		_ctrl ctrlSetText _text;
	} else {
		_ctrl ctrlShow false;
	};
};
