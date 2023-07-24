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
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
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
	closemessage
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
	msgbox lawrencetext, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SAWYER_1, blablawrencedefeattext
	end
	
blab1natalie:
	msgbox blabpleasewelcomenatalie, MSGBOX_DEFAULT	
	applymovement LOCALID_NATALIE, steptobattlezone2
	waitmovement 0
	msgbox natalietext, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_AQUA_HIDEOUT_1, blabnataliedefeattext
	end
	
blab1colin:
	msgbox blabpleasewelcomecolin, MSGBOX_DEFAULT	
	applymovement LOCALID_COLIN, steptobattlezone2
	waitmovement 0
	msgbox colintext, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_AQUA_HIDEOUT_4, blabcolindefeattext
	end
	
blab1hanna:
	msgbox blabpleasewelcomehanna, MSGBOX_DEFAULT	
	applymovement LOCALID_HANNA, steptobattlezone2
	waitmovement 0
	msgbox hannatext, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_AQUA_HIDEOUT_2, blabhannadefeattext
	end
	
blab1howard:
	msgbox blabpleasewelcomehoward, MSGBOX_DEFAULT	
	applymovement LOCALID_HOWARD, steptobattlezone2
	waitmovement 0
	msgbox howardtext, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_AQUA_HIDEOUT_3, blabhowarddefeattext
	end
	
blab1victory0:
	setvar VAR_UNUSED_0x40DC, 1
	msgbox blab1victory0text, MSGBOX_DEFAULT
	special HealPlayerParty
	buffernumberstring STR_VAR_1, 5
	setvar VAR_0x8004, 5
	special GiveFrontierBattlePoints
	msgbox won5RCtext
	closemessage
	warp MAP_BLABYRINTH_STAGING , 4, 3
	end

blab1victory1:
	setvar VAR_UNUSED_0x40DC, 2
	msgbox blab1victory1text, MSGBOX_DEFAULT
	special HealPlayerParty
	buffernumberstring STR_VAR_1, 5
	setvar VAR_0x8004, 5
	special GiveFrontierBattlePoints
	msgbox won5RCtext
	closemessage
	warp MAP_BLABYRINTH_STAGING , 4, 3
	end

blab1victory2:
	setvar VAR_UNUSED_0x40DC, 3
	msgbox blab1victory2text, MSGBOX_DEFAULT
	special HealPlayerParty
	buffernumberstring STR_VAR_1, 5
	setvar VAR_0x8004, 5
	special GiveFrontierBattlePoints
	msgbox won5RCtext
	closemessage
	warp MAP_BLABYRINTH_STAGING , 4, 3
	end
	
blab1victory3:
	setvar VAR_UNUSED_0x40DC, 4
	msgbox blab1victory3text, MSGBOX_DEFAULT
	special HealPlayerParty
	buffernumberstring STR_VAR_1, 5
	setvar VAR_0x8004, 5
	special GiveFrontierBattlePoints
	msgbox won5RCtext
	closemessage
	warp MAP_BLABYRINTH_STAGING , 4, 3
	end
	
blab1victory4:
	setvar VAR_UNUSED_0x40DC, 0
	msgbox blab1victory4text, MSGBOX_DEFAULT
	setflag FLAG_UNUSED_0x2B1
	buffernumberstring STR_VAR_1, 10
	setvar VAR_0x8004, 5
	special GiveFrontierBattlePoints
	msgbox won10RCtext
	closemessage
	warp MAP_BATTLE_LABYRINTH , 12, 8
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
	.string "The MAN MOUNTAIN!\p"
	.string "Tournament veteran...\p"
	.string "HIKER LAWRENCE!$"
	
blabpleasewelcomecolin:
	.string "And the next trainer.\p"
	.string "Fans of the OPEN know him well...\p"
	.string "The 32 year old man with a\n"
	.string "strange fixation on bug POKéMON..\p"
	.string "BUG MANIAC COLIN!$"
	
blabpleasewelcomenatalie:
	.string "And now the opponent.\p"
	.string "Top of her class at Rin Elementary.\p"
	.string "The youthful prodigy...\p"
	.string "LASS NATALIE!$"
	
blabpleasewelcomehanna:
	.string "And the opponent.\p"
	.string "Another newcomer to the OPEN,\n"
	.string "but unbeaten so far.\p"
	.string "The talented rookie...\p"
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
	.string "Please!\p"
	.string "Contain your boos!\p"
	.string "He's blown away all competition\n"
	.string "so far, without mercy.\p"
	.string "Can anyone stop him?\p"
	.string "Ladies and gentlemen, please hold\n"
	.string "your jeers for...\p"
	.string "RICH BOY HOWARD!$"

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
	face_left
	step_end
	
steptobattlezone2::
	set_visible
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end


	
blablawrencedefeattext:
	.string "Hohohoho, well played!$"
	
blabhannadefeattext:
	.string "Ahhhh, you're too good!$"
	
blabcolindefeattext:
	.string "M-m-my bugs!$"
	
blabnataliedefeattext:
	.string "Guess it's back to class for me...$"
	
blabhowarddefeattext:
	.string "WHAT?! HOW?!$"
	
lawrencetext:
	.string "Hohohoho, good luck my friend!$"

colintext:
	.string "You fool!\n"
	.string "You can never match my bugs!$"
	
natalietext:
	.string "I've been revising for this\n"
	.string "for weeks...$"

won5RCtext:
	.string "Won 5 RC!$"
	
	
won10RCtext:
	.string "Won 10 RC!$"