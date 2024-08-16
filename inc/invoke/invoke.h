// Functions.h
// This file contains all the function-definitions we'll be using inside
// of the LVP Core; defined for use with our Invoke class.
// **Added all functions from invoke.pwn - CodeMatrix

#pragma once

// STRUCT: PAWN_FUNCTION
// In here we define the function's name and parameters.
typedef struct PAWN_FUNCTION {
	int ParamCnt;			// Number of parameters for the function
	char Function[ 33 ];		// Name of the function, ex. "GetPlayerPos"
	char Params[ 18 ];		// Parameters for the function; i f v s
} PAWN_FUNCTION;

int invoke(AMX* pAMX, const PAWN_FUNCTION* Command, ... );

// Definition of pawn-functions;
// --------------------------------------------
// Parameters:
//   i = integer
//   f = float value
//   s = string
//   v = variable
//   p = string var (GetPlayerName etc.)
static const PAWN_FUNCTION SendClientMessage =					{ 3, "SendClientMessage",					"iis" };
static const PAWN_FUNCTION SendClientMessageToAll =			{ 2, "SendClientMessageToAll",				"is" };
static const PAWN_FUNCTION SendDeathMessage =					{ 3, "SendDeathMessage",					"iii" };
static const PAWN_FUNCTION GameTextForAll =					{ 3, "GameTextForAll",						"sii" };
static const PAWN_FUNCTION GameTextForPlayer =					{ 4, "GameTextForPlayer",					"isii" };
static const PAWN_FUNCTION GetTickCount =						{ 0, "GetTickCount",						"" };
static const PAWN_FUNCTION GetMaxPlayers =						{ 0, "GetMaxPlayers",						"" };
static const PAWN_FUNCTION SetGameModeText =					{ 1, "SetGameModeText",						"s" };
static const PAWN_FUNCTION SetTeamCount =						{ 1, "SetTeamCount",						"i" };
static const PAWN_FUNCTION AddPlayerClass =					{ 11, "AddPlayerClass",						"iffffiiiiii" };
static const PAWN_FUNCTION AddPlayerClassEx =					{ 12, "AddPlayerClassEx",					"iiffffiiiiii" };
static const PAWN_FUNCTION AddStaticVehicle =					{ 7, "AddStaticVehicle",					"iffffii" };
static const PAWN_FUNCTION AddStaticVehicleEx =				{ 8, "AddStaticVehicleEx",					"iffffiii" };
static const PAWN_FUNCTION AddStaticPickup =					{ 5, "AddStaticPickup",						"iifff" };
static const PAWN_FUNCTION ShowNameTags =						{ 1, "ShowNameTags",						"i" };
static const PAWN_FUNCTION ShowPlayerMarkers =					{ 1, "ShowPlayerMarkers",					"i" };
static const PAWN_FUNCTION GameModeExit =						{ 1, "GameModeExit",						"" };
static const PAWN_FUNCTION SetWorldTime =						{ 1, "SetWorldTime",						"i" };
static const PAWN_FUNCTION GetWeaponName =						{ 3, "GetWeaponName",						"ivi" };
static const PAWN_FUNCTION EnableTirePopping =					{ 1, "EnableTirePopping",					"i" };
static const PAWN_FUNCTION AllowInteriorWeapons =				{ 1, "AllowInteriorWeapons",				"i" };
static const PAWN_FUNCTION SetWeather =						{ 1, "SetWeather",							"i" };
static const PAWN_FUNCTION SetGravity =						{ 1, "SetGravity",							"f" };
static const PAWN_FUNCTION AllowAdminTeleport =				{ 1, "AllowAdminTeleport",					"i" };
static const PAWN_FUNCTION SetDeathDropAmount =				{ 1, "SetDeathDropAmount",					"i" };
static const PAWN_FUNCTION CreateExplosion =					{ 5, "CreateExplosion",						"fffif" };
static const PAWN_FUNCTION SetDisabledWeapons =				{ 0, "SetDisabledWeapons",					"" };
static const PAWN_FUNCTION EnableZoneNames =					{ 1, "EnableZoneNames",						"i" };
static const PAWN_FUNCTION IsPlayerAdmin =						{ 1, "IsPlayerAdmin",						"i" };
static const PAWN_FUNCTION Kick =								{ 1, "Kick",								"i" };
static const PAWN_FUNCTION Ban =								{ 2, "BanEx",								"is" };
static const PAWN_FUNCTION BanEx =								{ 1, "Ban",									"i" };
static const PAWN_FUNCTION SendRconCommand =					{ 1, "SendRconCommand",						"s" };

// a_players.inc
static const PAWN_FUNCTION SetSpawnInfo =						{ 13, "SetSpawnInfo",						"iiiffffiiiiii" };
static const PAWN_FUNCTION SpawnPlayer =						{ 1, "SpawnPlayer",							"i" };
static const PAWN_FUNCTION SetPlayerPos =						{ 4, "SetPlayerPos",						"ifff" };
static const PAWN_FUNCTION GetPlayerPos =						{ 4, "GetPlayerPos",						"ivvv" };
static const PAWN_FUNCTION SetPlayerFacingAngle =				{ 2, "SetPlayerFacingAngle",				"if" };
static const PAWN_FUNCTION GetPlayerFacingAngle =				{ 2, "GetPlayerFacingAngle",				"iv" };
static const PAWN_FUNCTION SetPlayerInterior =					{ 2, "SetPlayerInterior",					"ii" };
static const PAWN_FUNCTION GetPlayerInterior =					{ 1, "GetPlayerInterior",					"i" };
static const PAWN_FUNCTION SetPlayerHealth =					{ 2, "SetPlayerHealth",						"if" };
static const PAWN_FUNCTION GetPlayerHealth =					{ 2, "GetPlayerHealth",						"iv" };
static const PAWN_FUNCTION SetPlayerArmour =					{ 2, "SetPlayerArmour",						"if" };
static const PAWN_FUNCTION GetPlayerArmour =					{ 2, "GetPlayerArmour",						"iv" };
static const PAWN_FUNCTION SetPlayerAmmo =						{ 3, "SetPlayerAmmo",						"iii" };
static const PAWN_FUNCTION GetPlayerAmmo =						{ 1, "GetPlayerAmmo",						"i" };
static const PAWN_FUNCTION SetPlayerTeam =						{ 2, "SetPlayerTeam",						"ii" };
static const PAWN_FUNCTION GetPlayerTeam =						{ 1, "GetPlayerTeam",						"i" };
static const PAWN_FUNCTION SetPlayerScore =					{ 2, "SetPlayerScore",						"ii" };
static const PAWN_FUNCTION GetPlayerScore =					{ 1, "GetPlayerScore",						"i" };
static const PAWN_FUNCTION SetPlayerColor =					{ 2, "SetPlayerColor",						"ii" };
static const PAWN_FUNCTION GetPlayerColor =					{ 1, "GetPlayerColor",						"i" };
static const PAWN_FUNCTION SetPlayerSkin =						{ 2, "SetPlayerSkin",						"ii" };
static const PAWN_FUNCTION GivePlayerWeapon =					{ 3, "GivePlayerWeapon",					"iii" };
static const PAWN_FUNCTION ResetPlayerWeapons =				{ 1, "ResetPlayerWeapons",					"i" };
static const PAWN_FUNCTION GetPlayerWeaponData =				{ 6, "GetPlayerWeaponData",					"iiiviv " };
static const PAWN_FUNCTION GivePlayerMoney =					{ 2, "GivePlayerMoney",						"ii" };
static const PAWN_FUNCTION ResetPlayerMoney =					{ 1, "ResetPlayerMoney",					"i" };
static const PAWN_FUNCTION SetPlayerName =						{ 2, "SetPlayerName",						"is" };
static const PAWN_FUNCTION GetPlayerMoney =					{ 1, "GetPlayerMoney",						"i" };
static const PAWN_FUNCTION GetPlayerState =					{ 1, "GetPlayerState",						"i" };
static const PAWN_FUNCTION GetPlayerIp =						{ 3, "GetPlayerIp",							"ipi" };
static const PAWN_FUNCTION GetPlayerPing =						{ 1, "GetPlayerPing",						"i" };
static const PAWN_FUNCTION GetPlayerWeapon =					{ 1, "GetPlayerWeapon",						"i" };
static const PAWN_FUNCTION GetPlayerKeys =						{ 7, "GetPlayerKeys",						"ivvv" };
static const PAWN_FUNCTION GetPlayerName =						{ 3, "GetPlayerName",						"ipi" };
static const PAWN_FUNCTION PutPlayerInVehicle =				{ 3, "PutPlayerInVehicle",					"iii" };
static const PAWN_FUNCTION GetPlayerVehicleID =				{ 1, "GetPlayerVehicleID",					"i" };
static const PAWN_FUNCTION RemovePlayerFromVehicle =			{ 1, "RemovePlayerFromVehicle",				"i" };
static const PAWN_FUNCTION TogglePlayerControllable =			{ 2, "TogglePlayerControllable",			"ii" };
static const PAWN_FUNCTION PlayerPlaySound =					{ 5, "PlayerPlaySound",						"iifff" };
static const PAWN_FUNCTION SetPlayerCheckpoint =				{ 5, "SetPlayerCheckpoint",					"iffff" };
static const PAWN_FUNCTION DisablePlayerCheckpoint =			{ 1, "DisablePlayerCheckpoint",				"i" };
static const PAWN_FUNCTION SetPlayerRaceCheckpoint =			{ 9, "SetPlayerRaceCheckpoint",				"iifffffff" };
static const PAWN_FUNCTION DisablePlayerRaceCheckpoint =		{ 1, "DisablePlayerRaceCheckpoint",			"i" };
static const PAWN_FUNCTION SetPlayerWorldBounds =				{ 5, "SetPlayerWorldBounds",				"iffff" };
static const PAWN_FUNCTION SetPlayerMarkerForPlayer =			{ 3, "SetPlayerMarkerForPlayer",			"iii" };
static const PAWN_FUNCTION ShowPlayerNameTagForPlayer =		{ 3, "ShowPlayerNameTagForPlayer",			"iii" };
static const PAWN_FUNCTION SetPlayerMapIcon =					{ 7, "SetPlayerMapIcon",					"iifffii" };
static const PAWN_FUNCTION RemovePlayerMapIcon =				{ 2, "RemovePlayerMapIcon",					"ii" };
static const PAWN_FUNCTION SetPlayerCameraPos =				{ 4, "SetPlayerCameraPos",					"ifff" };
static const PAWN_FUNCTION SetPlayerCameraLookAt =				{ 4, "SetPlayerCameraLookAt",				"ifff" };
static const PAWN_FUNCTION SetCameraBehindPlayer =				{ 1, "SetCameraBehindPlayer",				"i" };
static const PAWN_FUNCTION AllowPlayerTeleport =				{ 2, "AllowPlayerTeleport",					"ii" };
static const PAWN_FUNCTION IsPlayerConnected =					{ 1, "IsPlayerConnected"					"i" };
static const PAWN_FUNCTION IsPlayerInVehicle =					{ 2, "IsPlayerInVehicle",					"ii" };
static const PAWN_FUNCTION IsPlayerInAnyVehicle =				{ 1, "IsPlayerInAnyVehicle",				"i" };
static const PAWN_FUNCTION IsPlayerInCheckpoint =				{ 1, "IsPlayerInCheckpoint",				"i" };
static const PAWN_FUNCTION IsPlayerInRaceCheckpoint =			{ 1, "IsPlayerInRaceCheckpoint",			"i" };
static const PAWN_FUNCTION SetPlayerTime =						{ 3, "SetPlayerTime",						"iii" };
static const PAWN_FUNCTION TogglePlayerClock =					{ 2, "TogglePlayerClock",					"ii" };
static const PAWN_FUNCTION SetPlayerWeather =					{ 2, "SetPlayerWeather",					"ii" };
static const PAWN_FUNCTION GetPlayerTime =						{ 3, "GetPlayerTime",						"ivv" };
static const PAWN_FUNCTION SetPlayerVirtualWorld =				{ 2, "SetPlayerVirtualWorld",				"ii" };
static const PAWN_FUNCTION GetPlayerVirtualWorld =				{ 1, "GetPlayerVirtualWorld",				"i" };

// a_vehicle.inc
static const PAWN_FUNCTION CreateVehicle =						{ 8, "CreateVehicle",						"iffffiii" };
static const PAWN_FUNCTION DestroyVehicle =					{ 1, "DestroyVehicle",						"i" };
static const PAWN_FUNCTION GetVehiclePos =						{ 4, "GetVehiclePos",						"ivvv" };
static const PAWN_FUNCTION SetVehiclePos =						{ 4, "SetVehiclePos",						"ifff" };
static const PAWN_FUNCTION GetVehicleZAngle =					{ 2, "GetVehicleZAngle",					"iv" };
static const PAWN_FUNCTION SetVehicleZAngle =					{ 2, "SetVehicleZAngle",					"if" };
static const PAWN_FUNCTION SetVehicleParamsForPlayer =			{ 4, "SetVehicleParamsForPlayer",			"iiii" };
static const PAWN_FUNCTION SetVehicleToRespawn =				{ 1, "SetVehicleToRespawn",					"i" };
static const PAWN_FUNCTION LinkVehicleToInterior =				{ 2, "LinkVehicleToInterior",				"ii" };
static const PAWN_FUNCTION AddVehicleComponent =				{ 2, "AddVehicleComponent",					"ii" };
static const PAWN_FUNCTION ChangeVehicleColor =				{ 3, "ChangeVehicleColor",					"iii" };
static const PAWN_FUNCTION ChangeVehiclePaintjob =				{ 2, "ChangeVehiclePaintjob",				"ii" };
static const PAWN_FUNCTION SetVehicleHealth =					{ 2, "SetVehicleHealth",					"if" };
static const PAWN_FUNCTION GetVehicleHealth =					{ 2, "GetVehicleHealth",					"iv" };
static const PAWN_FUNCTION AttachTrailerToVehicle =			{ 2, "AttachTrailerToVehicle",				"ii" };
static const PAWN_FUNCTION DetachTrailerFromVehicle =			{ 1, "DetachTrailerFromVehicle",			"i" };
static const PAWN_FUNCTION IsTrailerAttachedToVehicle =		{ 1, "IsTrailerAttachedToVehicle",			"i" };
static const PAWN_FUNCTION SetVehicleNumberPlate =				{ 2, "SetVehicleNumberPlate",				"is" };
static const PAWN_FUNCTION SetVehicleVirtualWorld =			{ 2, "SetVehicleVirtualWorld",				"ii" };
static const PAWN_FUNCTION GetVehicleVirtualWorld =			{ 1, "GetVehicleVirtualWorld",				"i" };
static const PAWN_FUNCTION ApplyAnimation =					{ 9, "ApplyAnimation",						"issfiiiii" };

// a_objects.inc
static const PAWN_FUNCTION CreateObject =						{ 7, "CreateObject",						"iffffff" };
static const PAWN_FUNCTION SetObjectPos =						{ 4, "SetObjectPos",						"ifff" };
static const PAWN_FUNCTION GetObjectPos =						{ 4, "GetObjectPos",						"ivvv" };
static const PAWN_FUNCTION SetObjectRot =						{ 4, "SetObjectRot",						"ifff" };
static const PAWN_FUNCTION GetObjectRot =						{ 4, "GetObjectRot",						"ivvv" };
static const PAWN_FUNCTION IsValidObject =						{ 1, "IsValidObject",						"i" };
static const PAWN_FUNCTION DestroyObject =						{ 1, "DestroyObject",						"i" };
static const PAWN_FUNCTION MoveObject =						{ 5, "MoveObject",							"iffff" };
static const PAWN_FUNCTION StopObject =						{ 1, "StopObject ",							"i" };
static const PAWN_FUNCTION CreatePlayerObject =				{ 8, "CreatePlayerObject",					"iiffffff" };
static const PAWN_FUNCTION SetPlayerObjectPos =				{ 5, "SetPlayerObjectPos",					"iifff" };
static const PAWN_FUNCTION GetPlayerObjectPos =				{ 5, "GetPlayerObjectPos",					"iivvv" };
static const PAWN_FUNCTION GetPlayerObjectRot =				{ 5, "GetPlayerObjectRot",					"iivvv" };
static const PAWN_FUNCTION SetPlayerObjectRot =				{ 5, "SetPlayerObjectRot",					"iifff" };
static const PAWN_FUNCTION IsValidPlayerObject =				{ 2, "IsValidPlayerObject",					"ii" };
static const PAWN_FUNCTION DestroyPlayerObject =				{ 2, "DestroyPlayerObject",					"ii" };
static const PAWN_FUNCTION MovePlayerObject =					{ 6, "MovePlayerObject",					"iiffff" };
static const PAWN_FUNCTION StopPlayerObject =					{ 2, "StopPlayerObject",					"ii" };

// Menu's
static const PAWN_FUNCTION CreateMenu =						{ 6, "CreateMenu",							"siffff" };
static const PAWN_FUNCTION DestroyMenu =						{ 1, "DestroyMenu",							"i" };
static const PAWN_FUNCTION AddMenuItem =						{ 3, "AddMenuItem",							"iis" };
static const PAWN_FUNCTION SetMenuColumnHeader =				{ 3, "SetMenuColumnHeader",					"iis" };
static const PAWN_FUNCTION ShowMenuForPlayer =					{ 2, "ShowMenuForPlayer",					"ii" };
static const PAWN_FUNCTION HideMenuForPlayer =					{ 2, "HideMenuForPlayer",					"ii" };
static const PAWN_FUNCTION IsValidMenu =						{ 1, "IsValidMenu",							"i" };
static const PAWN_FUNCTION DisableMenu =						{ 1, "DisableMenu",							"i" };
static const PAWN_FUNCTION DisableMenuRow =					{ 2, "DisableMenuRow",						"ii" };

// Textdraw
static const PAWN_FUNCTION TextDrawCreate =					{ 3, "TextDrawCreate",						"ffs" };
static const PAWN_FUNCTION TextDrawDestroy =					{ 1, "TextDrawDestroy",						"i" };
static const PAWN_FUNCTION TextDrawLetterSize =				{ 3, "TextDrawLetterSize",					"iff" };
static const PAWN_FUNCTION TextDrawTextSize =					{ 3, "TextDrawTextSize",					"iff" };
static const PAWN_FUNCTION TextDrawAlignment =					{ 2, "TextDrawAlignment",					"ii" };
static const PAWN_FUNCTION TextDrawColor =						{ 2, "TextDrawColor",						"ii" };
static const PAWN_FUNCTION TextDrawUseBox =					{ 2, "TextDrawUseBox",						"ii" };
static const PAWN_FUNCTION TextDrawBoxColor =					{ 2, "TextDrawBoxColor",					"ii" };
static const PAWN_FUNCTION TextDrawSetShadow =					{ 2, "TextDrawSetShadow",					"ii" };
static const PAWN_FUNCTION TextDrawSetOutline =				{ 2, "TextDrawSetOutline",					"ii" };
static const PAWN_FUNCTION TextDrawBackgroundColor =			{ 2, "TextDrawBackgroundColor",				"ii" };
static const PAWN_FUNCTION TextDrawFont =						{ 2, "TextDrawFont",						"ii" };
static const PAWN_FUNCTION TextDrawSetProportional =			{ 2, "TextDrawSetProportional",				"ii" };
static const PAWN_FUNCTION TextDrawShowForPlayer =				{ 2, "TextDrawShowForPlayer",				"ii" };
static const PAWN_FUNCTION TextDrawHideForPlayer =				{ 2, "TextDrawHideForPlayer",				"ii" };
static const PAWN_FUNCTION TextDrawShowForAll =				{ 1, "TextDrawShowForAll",					"i" };
static const PAWN_FUNCTION TextDrawHideForAll =				{ 1, "TextDrawHideForAll",					"i" };