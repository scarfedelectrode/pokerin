.set LOCALID_LAWRENCE, 8
.set LOCALID_NATALIE, 9
.set LOCALID_COLIN, 10
.set LOCALID_HANNA, 11
.set LOCALID_HOWARD, 12

BLabyrinthArena_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Blabarena_Enter_Script
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, blabhideopponent
	.byte 0

Blabarena_Enter_Script::
	map_script_2 VAR_TEMP_1, 0, Blabarena_Enter_Script2
	map_script_2 VAR_TEMP_1, 1, Blabarena_Enter_Script3
	.2byte 0
	
blabhideopponent::
	map_script_2 VAR_TEMP_1, 0, blabhideopponent2
	.2byte 0
	
blabhideopponent2:
	applymovement LOCALID_LAWRENCE, setinvisiblearena1
	applymovement LOCALID_NATALIE, setinvisiblearena1
	applymovement LOCALID_COLIN, setinvisiblearena1
	applymovement LOCALID_HANNA, setinvisiblearena1
	applymovement LOCALID_HOWARD, setinvisiblearena1
	end
	
Blabarena_Enter_Script3:
	setvar VAR_TEMP_1, 0
	goto_if_eq VAR_UNUSED_0x40DC, 0, blab1victory0
	goto_if_eq VAR_UNUSED_0x40DC, 1, blab1victory1
	goto_if_eq VAR_UNUSED_0x40DC, 2, blab1victory2
	goto_if_eq VAR_UNUSED_0x40DC, 3, blab1victory3
	goto_if_eq VAR_UNUSED_0x40DC, 4, blab1victory4
	end
	
	
setinvisiblearena1:
	set_invisible
	step_end


Blabarena_Enter_Script2:
	setvar VAR_TEMP_1, 1
	lockall
	delay 16
	msgbox blabpleasewelcomeplayer, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, steptobattlezone1
	waitmovement 0
	goto_if_eq VAR_UNUSED_0x40DC, 0, blab1lawrence
	goto_if_eq VAR_UNUSED_0x40DC, 1, blab1natalie
	goto_if_eq VAR_UNUSED_0x40DC, 2, blab1colin
	goto_if_eq VAR_UNUSED_0x40DC, 3, blab1hanna
	goto_if_eq VAR_UNUSED_0x40DC, 4, blab1howard
	end
	
blab1lawrence:
	msgbox blabpleasewelcomelawrence, MSGBOX_DEFAULT	
	applymovement LOCALID_LAWRENCE, steptobattlezone2
	waitmovement 0
	trainerbattle_single TRAINER_SAWYER_1, Route131_Text_RichardIntro, Route131_Text_RichardDefeat
	msgbox Route131_Text_RichardPostBattle, MSGBOX_AUTOCLOSE
	end
	
blab1natalie:
	msgbox blabpleasewelcomenatalie, MSGBOX_DEFAULT	
	applymovement LOCALID_NATALIE, steptobattlezone2
	waitmovement 0
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, Route131_Text_RichardIntro, Route131_Text_RichardDefeat
	msgbox Route131_Text_RichardPostBattle, MSGBOX_AUTOCLOSE
	end
	
blab1colin:
	msgbox blabpleasewelcomecolin, MSGBOX_DEFAULT	
	applymovement LOCALID_COLIN, steptobattlezone2
	waitmovement 0
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, Route131_Text_RichardIntro, Route131_Text_RichardDefeat
	msgbox Route131_Text_RichardPostBattle, MSGBOX_AUTOCLOSE
	end
	
blab1hanna:
	msgbox blabpleasewelcomehanna, MSGBOX_DEFAULT	
	applymovement LOCALID_HANNA, steptobattlezone2
	waitmovement 0
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_2, Route131_Text_RichardIntro, Route131_Text_RichardDefeat
	msgbox Route131_Text_RichardPostBattle, MSGBOX_AUTOCLOSE
	end
	
blab1howard:
	msgbox blabpleasewelcomehoward, MSGBOX_DEFAULT	
	applymovement LOCALID_HOWARD, steptobattlezone2
	waitmovement 0
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_3, Route131_Text_RichardIntro, Route131_Text_RichardDefeat
	msgbox Route131_Text_RichardPostBattle, MSGBOX_AUTOCLOSE
	end
	
blab1victory0:
	setvar VAR_UNUSED_0x40DC, 1
	msgbox blab1victory0text, MSGBOX_DEFAULT
	special HealPlayerParty
	warp MAP_BLABYRINTH_STAGING , 3, 3
	end

blab1victory1:
	setvar VAR_UNUSED_0x40DC, 2
	msgbox blab1victory1text, MSGBOX_DEFAULT
	special HealPlayerParty
	warp MAP_BLABYRINTH_STAGING , 3, 3
	end

blab1victory2:
	setvar VAR_UNUSED_0x40DC, 3
	msgbox blab1victory2text, MSGBOX_DEFAULT
	special HealPlayerParty
	warp MAP_BLABYRINTH_STAGING , 3, 3
	end
	
blab1victory3:
	setvar VAR_UNUSED_0x40DC, 4
	msgbox blab1victory3text, MSGBOX_DEFAULT
	special HealPlayerParty
	warp MAP_BLABYRINTH_STAGING , 3, 3
	end
	
blab1victory4:
	setvar VAR_UNUSED_0x40DC, 0
	msgbox blab1victory4text, MSGBOX_DEFAULT
	setflag FLAG_UNUSED_0x2B1
	warp MAP_BATTLE_LABYRINTH , 3, 3
	end
	
clear_flags_blabam::
	cleartrainerflag TRAINER_GRUNT_AQUA_HIDEOUT_1
	cleartrainerflag TRAINER_GRUNT_AQUA_HIDEOUT_2
	cleartrainerflag TRAINER_GRUNT_AQUA_HIDEOUT_3
	cleartrainerflag TRAINER_GRUNT_AQUA_HIDEOUT_4
	cleartrainerflag TRAINER_SAWYER_1
	return
	
blab1victory0text:
	.string "The victor, through to the second round,\n"
	.string "{PLAYER}!$"	

blab1victory1text:
	.string "The victor, through to the quarter final,\n"
	.string "{PLAYER}!$"
	
blab1victory2text:
	.string "The victor, through to the semi final,\n"
	.string "{PLAYER}!$"
	
blab1victory3text:
	.string "The victor, through to the final,\n"
	.string "{PLAYER}!$"
	
blab1victory4text:
	.string "Our tournament champion,\n"
	.string "{PLAYER}!$"
	
blabpleasewelcomeplayer:
	.string "Ladies and Gentlemen, please welcome\n"
	.string "{PLAYER}!$"	
	
blabpleasewelcomelawrence:
	.string "And now our second competitor.\p"
	.string "They say he has scaled every peak\n"
	.string "In all of RIN.\p"
	.string "A familiar face on the amateur circuit,\n"
	.string "well balanced between attack and defense.\p"
	.string "Ladies and Gentlemen, please welcome\n"
	.string "HIKER LAWRENCE!$"
	
blabpleasewelcomecolin:
	.string "And the next trainer.\p"
	.string "The eccentric expert on bug POKéMON.\p"
	.string "He's more interested in hunting CATERPIEs\n"
	.string "than winning tournaments.\p"
	.string "Nonetheless, a seasoned competitor\n"
	.string "who's a challenge on his day.\p"
	.string "Ladies and Gentlemen, please welcome\n"
	.string "BUG MANIAC COLIN!$"
	
blabpleasewelcomenatalie:
	.string "And now the opponent.\p"
	.string "Top of her class at Rin Elementary.\p"
	.string "She was given her first POKéMON\n"
	.string "at just 8 years old.\p"
	.string "Please welcome, the youthful prodigy,\n"
	.string "NATALIE!$"
	
blabpleasewelcomehanna:
	.string "And the opponent.\p"
	.string "A first time competitor at the OPEN.\p"
	.string "She has so far impressed with her\n"
	.string "varied team and strategy.\p"
	.string "Ladies and Gentlemen, please welcome\n"
	.string "HANNA!$"
	
blabpleasewelcomeeloise:
	.string "And now the opponent.\p"
	.string "She's blown away the opposition so far.\p"
	.string "A woman with a disposition as sunny\p"
	.string "as her strategy.\n"
	.string "Ladies and Gentlemen, please welcome\n"
	.string "ELOISE!$"
	
blabpleasewelcomehoward:
	.string "And now, our second finalist.\p"
	.string "His powerful POKéMON have ruthlessly\n"
	.string "Cut a path to this final.\p"
	.string "A kid with a lot of money but no\n"
	.string "shred of mercy.\p"
	.string "Can he be stopped tonight?\p"
	.string "Ladies and gentlemen, please welcome\n"
	.string "HOWARD!$"

howardtext:
	.string "You think you can win?\p"
	.string "I bet you caught all those yourself.\p"
	.string "Mine are all thoroughbred winners,\n"
	.string "the best money can buy.\p"
	.string "Let's see what happens to your mongrels,\n"
	.string "shall we?$"
	
hannatext:
	.string "A newbie too?\p"
	.string "Scary up here, isn't it?\p"
	.string "I hope I can win, but good luck!$"
	
steptobattlezone1::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end
	
steptobattlezone2::
	set_visible
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end
