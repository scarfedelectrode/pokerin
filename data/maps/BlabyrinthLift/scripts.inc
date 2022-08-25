.set LOCALID_ATTENDANT, 1

BlabyrinthLift_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleLabyrinth_EnterWarp_LiftScript
	.byte 0
	
BattleLabyrinth_EnterWarp_LiftScript:
	map_script_2 VAR_TEMP_0, 0, BattleLabyrinth_EnterWarp_LiftScript2
	.2byte 0

BattleLabyrinth_EnterWarp_LiftScript2:
	setvar VAR_TEMP_0, 1
	msgbox Labyrinth_warp_room_text, MSGBOX_DEFAULT
	applymovement LOCALID_ATTENDANT, Blab_move_to_warp
	applymovement OBJ_EVENT_ID_PLAYER, Blab_move_to_warp
	waitmovement 0
	warp MAP_BLABYRINTH_STAGING , 3, 3
	end
	
Labyrinth_warp_room_text:
	.string "This teleporter will take us to the\n"
	.string "staging area.$"
	
Blab_move_to_warp:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end