// Toggles the mission console: closes it if it is open, otherwise opens it.
// Opening is restricted to Zeus/curators; closing always works.
private _dlg = findDisplay ZMC_dialogIDD;
if (!isNull _dlg) exitWith {_dlg closeDisplay 2; true};

if (isNull (getAssignedCuratorLogic player)) exitWith {false};
createDialog "MissionControlGUI"
