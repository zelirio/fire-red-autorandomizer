PalletTown_PlayersHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_PlayersHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_PlayersHouse_2F_OnWarp
	.byte 0

PalletTown_PlayersHouse_2F_OnTransition::
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 0, PalletTown_PlayersHouse_2F_EventScript_SetRespawn
	end

PalletTown_PlayersHouse_2F_EventScript_SetRespawn::
	setrespawn SPAWN_PALLET_TOWN
	return

PalletTown_PlayersHouse_2F_OnWarp::
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 0, PalletTown_PlayersHouse_2F_FirstWarpIn
	.2byte 0

PalletTown_PlayersHouse_2F_FirstWarpIn::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	setvar VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 1
	setvar VAR_MAP_SCENE_SETTINGS, 1
	end

PalletTown_PlayersHouse_2F_EventScript_NES::
	msgbox PalletTown_PlayersHouse_2F_Text_PlayedWithNES, MSGBOX_SIGN
	end

PalletTown_PlayersHouse_2F_EventScript_Sign::
	msgbox PalletTown_PlayersHouse_2F_Text_PressLRForHelp, MSGBOX_SIGN
	end

PalletTown_PlayersHouse_2F_EventScript_PC::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	setvar VAR_0x8004, HELPCONTEXT_BEDROOM_PC
	special Script_SetHelpContext
	setvar VAR_0x8004, 1
	special AnimatePcTurnOn
	playse SE_PC_ON
	msgbox Text_PlayerBootedUpPC
	special BedroomPC
	waitstate
	special SetHelpContextForMap
	releaseall
	end

EventScript_PalletTown_PlayersHouse_2F_ShutDownPC::
	setvar VAR_0x8004, 1
	playse SE_PC_OFF
	special AnimatePcTurnOff
	special SetHelpContextForMap
	releaseall
	end

PalletTown_PlayersHouse_2F_EventScript_Settings_Selection::
	lock
	setvar VAR_DONT_RANDOMIZE, 0
	msgbox PalletTown_PlayersHouse_2F_Text_Random_Encounters, MSGBOX_YESNO
	copyvar VAR_RANDOM_WILD_ENCOUNTER, VAR_RESULT
	msgbox PalletTown_PlayersHouse_2F_Text_Random_Trainers, MSGBOX_YESNO
	copyvar VAR_RANDOM_TRAINER, VAR_RESULT
	msgbox PalletTown_PlayersHouse_2F_Text_Random_Starter, MSGBOX_YESNO
	copyvar VAR_RANDOM_STARTER, VAR_RESULT
	msgbox PalletTown_PlayersHouse_2F_Text_Random_Gift_Pokemon, MSGBOX_YESNO
	copyvar VAR_RANDOM_GIFT_POKEMON, VAR_RESULT
	msgbox PalletTown_PlayersHouse_2F_Text_Random_Evolution, MSGBOX_YESNO
	copyvar VAR_RANDOM_EVOLUTION, VAR_RESULT
	msgbox PalletTown_PlayersHouse_2F_Text_Random_Move, MSGBOX_YESNO
	copyvar VAR_RANDOM_MOVE, VAR_RESULT
	msgbox PalletTown_PlayersHouse_2F_Text_Random_Item, MSGBOX_YESNO
	copyvar VAR_RANDOM_ITEM, VAR_RESULT
	msgbox PalletTown_PlayersHouse_2F_Text_Random_Ability, MSGBOX_YESNO
	copyvar VAR_RANDOM_ABILITY, VAR_RESULT
	setvar VAR_MAP_SCENE_SETTINGS, 2
	release
	end