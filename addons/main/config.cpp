#include "script_version.hpp"

class CfgPatches
{
	class ZMC_main
	{
		name = "Zeus Mission Control";
		author = "Shadow";
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"A3_UI_F"};
	};
};

class CfgFunctions
{
	class ZMC
	{
		class MissionControl
		{
			file = "\z\zmc\addons\main\functions";
			class init { postInit = 1; };
			class keyDown {};
			class openDialog {};
			class dialogLoad {};
			class runAction {};
			class setFriend {};
			class setTime {};
		};
	};
};

class ZMC_RscButton
{
	type = 1;
	idc = -1;
	style = 0+2;
	x = 0;
	y = 0;
	w = "safeZoneW * 0.1125";
	h = "safeZoneH * 0.05";
	text = "";
	borderSize = 0;
	colorBackground[] = {0.102,0.102,0.102,1};
	colorBackgroundActive[] = {0.8,0.8,0.2,1};
	colorBackgroundDisabled[] = {0.2,0.2,0.2,1};
	colorBorder[] = {0.6,0.6,0,1};
	colorDisabled[] = {0.2,0.2,0.2,1};
	colorFocused[] = {0.2,0.2,0.2,1};
	colorShadow[] = {0,0,0,1};
	colorText[] = {0.502,0.502,0.102,1};
	font = "PuristaBold";
	offsetPressedX = 0.01;
	offsetPressedY = 0.01;
	offsetX = 0.01;
	offsetY = 0.01;
	sizeEx = 0.05;
	soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
	soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
	soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
	soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
};

// Small buttons along the screen edges (time / mission end)
class ZMC_RscButtonSmall: ZMC_RscButton
{
	w = "safeZoneW * 0.0625";
	h = "safeZoneH * 0.025";
	sizeEx = 0.04;
};

class MissionControlGUI
{
	idd = 86600;	// must match ZMC_dialogIDD in fn_init.sqf
	onLoad = "_this call ZMC_fnc_dialogLoad";

	class ControlsBackground {};

	class Controls
	{
		class i_friendly: ZMC_RscButton
		{
			x = "safeZoneX + safeZoneW * 0.61875";
			y = "safeZoneY + safeZoneH * 0.3";
			text = "Set Friendly";
			colorBackground[] = {0.102,0.302,0.102,1};
			onMouseButtonDown = "[1] remoteExec [""ZMC_fnc_setFriend"", 0, ""ZMC_setFriend""]";
		};
		class i_hostile: ZMC_RscButton
		{
			x = "safeZoneX + safeZoneW * 0.61875";
			y = "safeZoneY + safeZoneH * 0.375";
			text = "Set Hostile";
			colorBackground[] = {0.6,0,0,1};
			onMouseButtonDown = "[0] remoteExec [""ZMC_fnc_setFriend"", 0, ""ZMC_setFriend""]";
		};
		class time_fast: ZMC_RscButtonSmall
		{
			x = "safeZoneX + safeZoneW * 0.81875";
			y = "safeZoneY + safeZoneH * 0.9";
			text = "Fast Time";
			onMouseButtonDown = "[60] remoteExec [""ZMC_fnc_setTime"", 2]";
		};
		class time_normal: ZMC_RscButtonSmall
		{
			x = "safeZoneX + safeZoneW * 0.74375";
			y = "safeZoneY + safeZoneH * 0.9";
			text = "Normal Time";
			onMouseButtonDown = "[1] remoteExec [""ZMC_fnc_setTime"", 2]";
		};
		class mission_success: ZMC_RscButtonSmall
		{
			x = "safeZoneX + safeZoneW * 0.04375";
			y = "safeZoneY + safeZoneH * 0.875";
			w = "safeZoneW * 0.0875";
			text = "Mission Success";
			colorText[] = {0.2,0.4,0.2,1};
			onMouseButtonDown = "[""end2"", true] remoteExec [""BIS_fnc_endMission""]";
		};
		class mission_fail: ZMC_RscButtonSmall
		{
			x = "safeZoneX + safeZoneW * 0.04375";
			y = "safeZoneY + safeZoneH * 0.925";
			w = "safeZoneW * 0.0875";
			text = "Mission Fail";
			colorText[] = {0.702,0.102,0.102,1};
			onMouseButtonDown = "[""end2"", false] remoteExec [""BIS_fnc_endMission""]";
		};
		class action_1: ZMC_RscButton
		{
			idc = 1601;
			x = "safeZoneX + safeZoneW * 0.26875";
			y = "safeZoneY + safeZoneH * 0.3";
			text = "Action 1";
			onMouseButtonDown = "[1] call ZMC_fnc_runAction";
		};
		class action_2: ZMC_RscButton
		{
			idc = 1602;
			x = "safeZoneX + safeZoneW * 0.26875";
			y = "safeZoneY + safeZoneH * 0.375";
			text = "Action 2";
			onMouseButtonDown = "[2] call ZMC_fnc_runAction";
		};
		class action_3: ZMC_RscButton
		{
			idc = 1603;
			x = "safeZoneX + safeZoneW * 0.26875";
			y = "safeZoneY + safeZoneH * 0.45";
			text = "Action 3";
			onMouseButtonDown = "[3] call ZMC_fnc_runAction";
		};
		class action_4: ZMC_RscButton
		{
			idc = 1604;
			x = "safeZoneX + safeZoneW * 0.26875";
			y = "safeZoneY + safeZoneH * 0.525";
			text = "Action 4";
			onMouseButtonDown = "[4] call ZMC_fnc_runAction";
		};
		class action_5: ZMC_RscButton
		{
			idc = 1605;
			x = "safeZoneX + safeZoneW * 0.41875";
			y = "safeZoneY + safeZoneH * 0.3";
			text = "Action 5";
			onMouseButtonDown = "[5] call ZMC_fnc_runAction";
		};
		class action_6: ZMC_RscButton
		{
			idc = 1606;
			x = "safeZoneX + safeZoneW * 0.41875";
			y = "safeZoneY + safeZoneH * 0.375";
			text = "Action 6";
			onMouseButtonDown = "[6] call ZMC_fnc_runAction";
		};
		class action_7: ZMC_RscButton
		{
			idc = 1607;
			x = "safeZoneX + safeZoneW * 0.41875";
			y = "safeZoneY + safeZoneH * 0.45";
			text = "Action 7";
			onMouseButtonDown = "[7] call ZMC_fnc_runAction";
		};
		class action_8: ZMC_RscButton
		{
			idc = 1608;
			x = "safeZoneX + safeZoneW * 0.41875";
			y = "safeZoneY + safeZoneH * 0.525";
			text = "Action 8";
			onMouseButtonDown = "[8] call ZMC_fnc_runAction";
		};
	};
};
