.set LOCALID_ATTENDANT_SINGLES, 1

BattleLabyrinth_MapScripts::
	.byte 0

BattleLabyrinth_Tourny_Clerk_Script::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_TOURNY_CLERK
	call BattlyLabyrinth_Clerk_welcome
	goto BattleLabyrinth_Tourny_Clerk_Selection
	end


BattleLabyrinth_Tourny_Clerk_Selection::
	setvar VAR_UNUSED_0x40DC, 0
	setvar VAR_0x8004, SCROLL_MULTI_BATTLE_LABYRINTH_TOURNAMENT
	msgbox chooseacompetitionblab MSGBOX_DEFAULT
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, BattleLabryrinth_EventScript_Amateur
	case 1, BattleLabryrinth_EventScript_Rinvitational
	case 2, BattleLabryrinth_EventScript_Rumble
	case 3, BattleLabryrinth_EventScript_AceI
	case 4, BattleLabryrinth_EventScript_AceII
	case 5, BattleLabryrinth_EventScript_Elite
	case 6, BattleLabryrinth_EventScript_Master
	case 7, BattleLabryrinth_EventScript_Grandmaster
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end
	
chooseacompetitionblab::
	.string "Would you like to enter a competition?$"
	
BattleLabryrinth_EventScript_Amateur::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleLabyrinth_Tourny_Clerk_Selection
	setvar VAR_UNUSED_0x40E5, LABYRINTH_AMATEUR
	call BattleLabyrinth_EventScript_WalkToDoor
	special HealPlayerParty
	call clear_flags_blabam
	warp MAP_BLABYRINTH_LIFT , 3, 5
	end
	
BattleLabryrinth_EventScript_Rinvitational::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleLabyrinth_Tourny_Clerk_Selection
	goto_if_unset FLAG_UNUSED_0x2B1, sorryyoudontqualify_text
	setvar VAR_UNUSED_0x40E5, LABYRINTH_INVITATIONAL
	call BattleLabyrinth_EventScript_WalkToDoor
	special HealPlayerParty
	warp MAP_BLABYRINTH_LIFT , 3, 5
	end
	
BattleLabryrinth_EventScript_Rumble::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleLabyrinth_Tourny_Clerk_Selection
	goto_if_unset FLAG_UNUSED_0x2B2, sorryyoudontqualify_text
	setvar VAR_UNUSED_0x40E5, LABYRINTH_RUMBLE
	call BattleLabyrinth_EventScript_WalkToDoor
	special HealPlayerParty
	warp MAP_BLABYRINTH_LIFT , 3, 5
	end
	
BattleLabryrinth_EventScript_AceI::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleLabyrinth_Tourny_Clerk_Selection
	goto_if_unset FLAG_UNUSED_0x2B3, sorryyoudontqualify_text
	setvar VAR_UNUSED_0x40E5, LABYRINTH_ACE
	call BattleLabyrinth_EventScript_WalkToDoor
	special HealPlayerParty
	warp MAP_BLABYRINTH_LIFT , 3, 5
	end
	
BattleLabryrinth_EventScript_AceII::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleLabyrinth_Tourny_Clerk_Selection
	goto_if_unset FLAG_UNUSED_0x2B4, sorryyoudontqualify_text
	setvar VAR_UNUSED_0x40E5, LABYRINTH_ACEII
	call BattleLabyrinth_EventScript_WalkToDoor
	special HealPlayerParty
	warp MAP_BLABYRINTH_LIFT , 3, 5
	end
	
BattleLabryrinth_EventScript_Elite::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleLabyrinth_Tourny_Clerk_Selection
	goto_if_unset FLAG_UNUSED_0x2B5, sorryyoudontqualify_text
	setvar VAR_UNUSED_0x40E5, LABYRINTH_ELITE
	call BattleLabyrinth_EventScript_WalkToDoor
	special HealPlayerParty
	warp MAP_BLABYRINTH_LIFT , 3, 5
	end
	
BattleLabryrinth_EventScript_Master::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleLabyrinth_Tourny_Clerk_Selection
	goto_if_unset FLAG_UNUSED_0x2B6, sorryyoudontqualify_text
	setvar VAR_UNUSED_0x40E5, LABYRINTH_MASTER
	call BattleLabyrinth_EventScript_WalkToDoor
	special HealPlayerParty
	warp MAP_BLABYRINTH_LIFT , 3, 5
	end
	
BattleLabryrinth_EventScript_Grandmaster::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleLabyrinth_Tourny_Clerk_Selection
	goto_if_unset FLAG_UNUSED_0x2B7, sorryyoudontqualify_text
	setvar VAR_UNUSED_0x40E5, LABYRINTH_GRANDMASTER
	call BattleLabyrinth_EventScript_WalkToDoor
	special HealPlayerParty
	warp MAP_BLABYRINTH_LIFT , 3, 5
	end

BattlyLabyrinth_Clerk_welcome::
	msgbox BattlyLabyrinth_Clerk_welcome_text, MSGBOX_DEFAULT
	return
	
sorryyoudontqualify_text::
	msgbox sorrynoqualify_textbox, MSGBOX_DEFAULT
	goto BattleLabyrinth_Tourny_Clerk_Selection
	return
	
BattlyLabyrinth_Clerk_welcome_text:
	.string "Welcome to the BATTLE LABYRINTH!\p"
	.string "This is where trainers from across RIN\n"
	.string "come to test themselves in battle.$"

	
sorrynoqualify_textbox:
	.string "I'm sorry, you do not meet the\n"
	.string "qualification criteria.$"
	
BattleLabyrinth_EventScript_WalkToDoor::
	call BattleLabyrinth_EventScript_SinglesAttendantWalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleLabyrinth_Movement_WalkToDoor
	waitmovement 0
	call BattleLabyrinth_EventScript_OpenSinglesDoor
	waitdooranim
	call BattleLabyrinth_EventScript_SinglesAttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleLabyrinth_Movement_PlayerEnterDoor
	waitmovement 0
	call BattleLabyrinth_EventScript_CloseSinglesDoor
	waitdooranim
	return
	
BattleLabyrinth_EventScript_SinglesAttendantWalkToDoor::
	applymovement LOCALID_ATTENDANT_SINGLES, BattleLabyrinth_Movement_WalkToDoor
	return	
	
BattleLabyrinth_EventScript_SinglesAttendantEnterDoor::
	applymovement LOCALID_ATTENDANT_SINGLES, BattleLabyrinth_Movement_AttendantEnterDoor
	return	
	
BattleLabyrinth_EventScript_OpenSinglesDoor::
	opendoor 12, 3
	return
	
BattleLabyrinth_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	step_end
	
BattleLabyrinth_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleLabyrinth_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end
	
BattleLabyrinth_EventScript_CloseSinglesDoor::
	closedoor 12, 3
	return
	
	
