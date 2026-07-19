// Sets independent's attitude towards BLUFOR. setFriend only has local effect,
// so this is remoteExec'd to all machines (JIP-persistent).
params ["_value"];
resistance setFriend [west, _value];
