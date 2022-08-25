.set LOCALID_t1, 1
.set LOCALID_t2, 2

fmainspookhous_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, spookhouse_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, spookhousehide
	.byte 0
	
spookhouse_OnTransition:
	map_script_2 VAR_UNUSED_0x40F7, 0, spookhousething
	.2byte 0


spookhousehide::
	map_script_2 VAR_TEMP_1, 0, spookhousehidetwins
	.2byte 0

spookhousething::
	setvar VAR_UNUSED_0x40F7, 1
	goto twinsappearspookhousemain
	end
	
nothingspookhouse:
	end
	
twinsappearspookhousemain:
	lock
	goto twinsappearspookhouse
	setvar VAR_UNUSED_0x40F7, 1
	release
	end
	
twinsappearspookhouse:
	fadescreen FADE_TO_BLACK
	waitmovement 0
	applymovement LOCALID_t1, spookhousesetvisible
	applymovement LOCALID_t2, spookhousesetvisible
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	waitmovement 0
	return


spookhousehidetwins:
	applymovement LOCALID_t1, setinvisiblearena1
	applymovement LOCALID_t2, setinvisiblearena1
	return
	
spookhousesetvisible:
	walk_up
	set_visible
	step_end
	
spookhousetwintalk::
	lock
	faceplayer
	msgbox spookhousetwintext, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	waitmovement 0
	removeobject LOCALID_t1
	removeobject LOCALID_t2
	setflag FLAG_UNUSED_0x26C
	setvar VAR_UNUSED_0x40F7, 2
	fadescreen FADE_FROM_BLACK
	waitmovement 0
	release
	end
	
spookhousetwintext:
	.string "Don't...\p"
	.string "...Go north.$"
	