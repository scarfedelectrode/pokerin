ForestMain_MapScripts::
	.byte 0

ForestMain_EventScript_Rick::
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end
	
FMain_eventscript_B1::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, FMAINTEXT_INTB1, FMAINTEXT_DEFB1
	msgbox FMAINTEXT_EXB1, MSGBOX_AUTOCLOSE
	end
	
FMain_eventscript_B2::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, FMAINTEXT_INTB2, FMAINTEXT_DEFB2
	msgbox FMAINTEXT_EXB2, MSGBOX_AUTOCLOSE
	end
	
FMain_eventscript_B3::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, FMAINTEXT_INTB3, FMAINTEXT_DEFB3
	msgbox FMAINTEXT_EXB3, MSGBOX_AUTOCLOSE
	end
	
FMain_eventscript_B4::
	trainerbattle_single TRAINER_GABRIELLE_1, FMAINTEXT_INTB4, FMAINTEXT_DEFB4
	msgbox FMAINTEXT_EXB4, MSGBOX_AUTOCLOSE
	end
	
FMain_eventscript_B5::
	trainerbattle_single TRAINER_GRUNT_PETALBURG_WOODS, FMAINTEXT_INTB5, FMAINTEXT_DEFB5
	msgbox FMAINTEXT_EXB5, MSGBOX_AUTOCLOSE
	end
	
FMain_eventscript_B6::
	trainerbattle_single TRAINER_MARCEL, FMAINTEXT_INTB6, FMAINTEXT_DEFB6
	msgbox FMAINTEXT_EXB6, MSGBOX_AUTOCLOSE
	end
	
FMain_eventscript_B7::
	trainerbattle_single TRAINER_ALBERTO, FMAINTEXT_INTB7, FMAINTEXT_DEFB7
	msgbox FMAINTEXT_EXB7, MSGBOX_AUTOCLOSE
	end
	
FMain_eventscript_B8::
	trainerbattle_single TRAINER_ED, FMAINTEXT_INTB8, FMAINTEXT_DEFB8
	msgbox FMAINTEXT_EXB8, MSGBOX_AUTOCLOSE
	end
	
FMain_eventscript_B9::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, FMAINTEXT_INTB9, FMAINTEXT_DEFB9
	msgbox FMAINTEXT_EXB9, MSGBOX_AUTOCLOSE
	end
	
rin_found_rin_crystals3::
	buffernumberstring STR_VAR_1, 3
	setvar VAR_0x8004, 3
	special GiveFrontierBattlePoints
	msgbox Forestmain_found_rin_crystals, MSGBOX_GETPOINTS
//	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
//	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end
	
rin_found_rin_crystals5::
	buffernumberstring STR_VAR_1, 5
	setvar VAR_0x8004, 5
	special GiveFrontierBattlePoints
	msgbox Forestmain_found_rin_crystals, MSGBOX_GETPOINTS
//	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
//	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end
	
rin_found_rin_crystals10::
	buffernumberstring STR_VAR_1, 10
	setvar VAR_0x8004, 10
	special GiveFrontierBattlePoints
	msgbox Forestmain_found_rin_crystals, MSGBOX_GETPOINTS
//	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
//	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end


Forestmain_found_rin_crystals:
	.string "{PLAYER} obtained\n"
	.string "{STR_VAR_1} RIN CRYSTALS.$"
	
FMAINTEXT_INTB1:
	.string "They say that each region of RIN\n"
	.string "contains a legendary POKéMON.$"
	
FMAINTEXT_DEFB1:
	.string "Shame I don't have one!$"
	
FMAINTEXT_EXB1:
	.string "I wonder if there are any around here...$"
	
FMAINTEXT_INTB2:
	.string "I want to become a GRANDMASTER.\p"
	.string "Can you help me?$"
	
FMAINTEXT_DEFB2:
	.string "Nice!$"
	
FMAINTEXT_EXB2:
	.string "You should try the BATTLE LABYRINTH.\p"
	.string "You'd do better than I did.$"
	
FMAINTEXT_INTB3:
	.string "I come to these woods to relax\n"
	.string "and meditate.$"
	
FMAINTEXT_DEFB3:
	.string "That's one way to meditate!$"
	
FMAINTEXT_EXB3:
	.string "You should take time to slow down\n"
	.string "and connect with nature.$"
	
FMAINTEXT_INTB4:
	.string "Have you seen any RIN CRYSTALS about?$"
	
FMAINTEXT_DEFB4:
	.string "Good battle!$"
	
FMAINTEXT_EXB4:
	.string "I want to buy a new TM for my bugs.$"
	
FMAINTEXT_INTB5:
	.string "My kid really wanted a BULBASAUR.\p"
	.string "Have you seen any?$"
	
FMAINTEXT_DEFB5:
	.string "Still looking!$"
	
FMAINTEXT_EXB5:
	.string "I'll find one sooner or later.$"
	
FMAINTEXT_INTB6:
	.string "Those crystals are mine!$"
	
FMAINTEXT_DEFB6:
	.string "OK!\n"
	.string "Maybe I can share.$"
	
FMAINTEXT_EXB6:
	.string "You can trade those RIN CRYSTALS\n"
	.string "for almost anything.$"
	
FMAINTEXT_INTB7:
	.string "CAWWW\n"
	.string "CAWWW.$"
	
FMAINTEXT_DEFB7:
	.string "You're not what I was calling!$"
	
FMAINTEXT_EXB7:
	.string "I'm trying to learn the cries of the\n"
	.string "local wildlife.$"
	
FMAINTEXT_INTB8:
	.string "What's your POKéMON's base stat total?$"
	
FMAINTEXT_DEFB8:
	.string "Muh EVs!$"
	
FMAINTEXT_EXB8:
	.string "POKéMON's not all about stats I suppose.\p"
	.string "Better to lose with your favourites.$"
	
FMAINTEXT_INTB9:
	.string "I'm studying GRASS POKéMON for a\n"
	.string "school project.$"
	
FMAINTEXT_DEFB9:
	.string "Too good!$"
	
FMAINTEXT_EXB9:
	.string "Did you go to the POKéMON school too?$"
	
fmaineventscriptscientist::
	lock
	faceplayer
	msgbox fmainscientisttext, MSGBOX_DEFAULT
	release
	end
	
fmainscientisttext:
	.string "Hi there.\p"
	.string "I'm researching these woods for\n"
	.string "PROFESSOR ASPEN.\p"
	.string "It seems these blue flowers are \n"
	.string "linked to RIN CRYSTALS somehow.\p"
	.string "Maybe I should follow them...$"
	
fmainboylostziggyscript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x029, fmainthankyouziggy
	goto_if_set FLAG_UNUSED_0x027, fmainhaveyoufoundziggy
	goto fmainlostmyziggy
	release
	end
	
fmainlostmyziggy:
	msgbox boylostziggytext, MSGBOX_DEFAULT
	setflag FLAG_UNUSED_0x027
	release
	end
	
boylostziggytext:
	.string "Please help me!\p"
	.string "My ZIGGY ran away!\p"
	.string "Some scientists from MOUNT EPHYRA said\n"
	.string "he was special.\p"
	.string "They asked if they could look after\n"
	.string "him for a while to do some tests.\p"
	.string "But when they came to collect him,\n"
	.string "he ran for the forest!\p"
	.string "Please help me find him.\p"
	.string "I love him and miss him so much.$"
	
fmainhaveyoufoundziggy:
	msgbox fmainhaveyoufoundziggytext, MSGBOX_DEFAULT
	goto_if_set FLAG_UNUSED_0x028, fmainfoundziggy
	release
	end
	
fmainhaveyoufoundziggytext:
	.string "Have you seen my Ziggy?$"
	
fmainfoundziggy:
	msgbox foundmyziggytext, MSGBOX_DEFAULT
	setvar VAR_0x8004, 10
	special GiveFrontierBattlePoints
	msgbox Forestmain_received_crystals, MSGBOX_GETPOINTS
	setflag FLAG_UNUSED_0x029
	release
	end
	
foundmyziggytext:
	.string "Oh, there he is!\p"
	.string "Thank you so much!\p"
	.string "I don't know what I would do\n"
	.string "without you, ZIGGY.\p"
	.string "You don't have to do anything with\n"
	.string "those scientists if you don't want to.\p"
	.string "I stumbled across these whilst\n"
	.string "looking for ZIGGY in the bushes.\p"
	.string "You deserve them for all you've done.$"
	
Forestmain_received_crystals:
	.string "Received 10 RIN CRYSTALS!$"
	
fmainthankyouziggy:
	lock
	faceplayer
	msgbox fmainthankyouziggytext, MSGBOX_DEFAULT
	release
	end
	
fmainthankyouziggytext:
	.string "Thank you again!$"

	
	