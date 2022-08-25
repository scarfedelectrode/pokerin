.set LOCALID_ATTENDANT, 1

BLabyrinthStaging_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BlabStaging_Enter_Script
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomePreBattleRoom_OnWarp
	.byte 0
	
BlabStaging_Enter_Script:
	map_script_2 VAR_TEMP_0, 0, BlabStaging_Enter_Script2
	.2byte 0

BlabStaging_Enter_Script2:
	setvar VAR_TEMP_0, 1
	msgbox blab_stagingroom_introtext, MSGBOX_DEFAULT
	closemessage
	end
	
blab_stagingroom_introtext:
	.string "Here you can make changes to your\n"
	.string "party before the next round.\p"
	.string "Please let me know when you wish to\n"
	.string "proceed.$"
	
blab_stagingroom_readytostartscript::
	msgbox blab_stagingroom_startyesnotext, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, close_script_thing
	goto_if_eq VAR_UNUSED_0x40E5, LABYRINTH_AMATEUR, blab_staging_amateurwarp
	goto_if_eq VAR_UNUSED_0x40E5, LABYRINTH_INVITATIONAL, blab_staging_invitationalwarp
	goto_if_eq VAR_UNUSED_0x40E5, LABYRINTH_RUMBLE, blab_staging_rumblewarp
	goto_if_eq VAR_UNUSED_0x40E5, LABYRINTH_ACE, blab_staging_acewarp
	goto_if_eq VAR_UNUSED_0x40E5, LABYRINTH_ACEII, blab_staging_aceiiwarp
	goto_if_eq VAR_UNUSED_0x40E5, LABYRINTH_ELITE, blab_staging_elitewarp
	goto_if_eq VAR_UNUSED_0x40E5, LABYRINTH_MASTER, blab_staging_masterwarp
	goto_if_eq VAR_UNUSED_0x40E5, LABYRINTH_GRANDMASTER, blab_staging_grandmasterwarp
	end
	
	
	
blab_stagingroom_startyesnotext:
	.string "Are you ready to begin?$"
	
close_script_thing:
	closemessage
	end
	
blab_staging_amateurwarp:
	call Blab_staging_attendant_move
	waitmovement 0
	call blab_open_staging_door
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, blab_staging_player_leave
	waitmovement 0
	call blab_staging_close_door
	waitdooranim
	warp MAP_BLABYRINTH_ARENA , 4, 14
	end

blab_staging_invitationalwarp:
	call Blab_staging_attendant_move
	waitmovement 0
	call blab_open_staging_door
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, blab_staging_player_leave
	waitmovement 0
	call blab_staging_close_door
	waitdooranim
	warp MAP_BLABYRINTH_ARENA , 3, 5
	end

blab_staging_rumblewarp:
	call Blab_staging_attendant_move
	waitmovement 0
	call blab_open_staging_door
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, blab_staging_player_leave
	waitmovement 0
	call blab_staging_close_door
	waitdooranim
	warp MAP_BLABYRINTH_ARENA , 3, 5
	end

blab_staging_acewarp:
	call Blab_staging_attendant_move
	waitmovement 0
	call blab_open_staging_door
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, blab_staging_player_leave
	waitmovement 0
	call blab_staging_close_door
	waitdooranim
	warp MAP_BLABYRINTH_ARENA , 3, 5
	end

blab_staging_aceiiwarp:
	call Blab_staging_attendant_move
	waitmovement 0
	call blab_open_staging_door
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, blab_staging_player_leave
	waitmovement 0
	call blab_staging_close_door
	waitdooranim
	warp MAP_BLABYRINTH_ARENA , 3, 5
	end

blab_staging_elitewarp:
	call Blab_staging_attendant_move
	waitmovement 0
	call blab_open_staging_door
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, blab_staging_player_leave
	waitmovement 0
	call blab_staging_close_door
	waitdooranim
	warp MAP_BLABYRINTH_ARENA , 3, 5
	end

blab_staging_masterwarp:
	call Blab_staging_attendant_move
	waitmovement 0
	call blab_open_staging_door
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, blab_staging_player_leave
	waitmovement 0
	call blab_staging_close_door
	waitdooranim
	warp MAP_BLABYRINTH_ARENA , 3, 5
	end

blab_staging_grandmasterwarp:
	call Blab_staging_attendant_move
	waitmovement 0
	call blab_open_staging_door
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, blab_staging_player_leave
	waitmovement 0
	call blab_staging_close_door
	waitdooranim
	warp MAP_BLABYRINTH_ARENA , 3, 5
	end
	
Blab_staging_attendant_move::
	applymovement LOCALID_ATTENDANT, Blab_staging_attendant_move2
	return

blab_staging_player_leave::
	walk_up
	walk_up
	step_end

blab_open_staging_door:
	opendoor 3, 1
	return
	
blab_staging_close_door:
	closedoor 3, 1
	return
	
Blab_staging_attendant_move2:
	walk_left
	face_down
	step_end
	