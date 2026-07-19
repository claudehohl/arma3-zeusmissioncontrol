// Runs the mission-defined code of action button N on the Zeus machine.
// Mission makers use remoteExec inside their code if the effect must be global.
params ["_index"];

private _code = getText (missionConfigFile >> "MissionControl" >> format ["Action%1", _index] >> "code");
if (_code isEqualTo "") exitWith {};
call compile _code;
