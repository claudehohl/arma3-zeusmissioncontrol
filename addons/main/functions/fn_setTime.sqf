// Sets the time multiplier. setTimeMultiplier must run on the server (global effect),
// so this is remoteExec'd to the server.
params ["_multiplier"];
setTimeMultiplier _multiplier;
