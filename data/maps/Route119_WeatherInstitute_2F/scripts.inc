.set LOCALID_GRUNT_1, 1
.set LOCALID_GRUNT_2, 2
.set LOCALID_SHELLY, 3
.set LOCALID_SCIENTIST, 5
.set LOCALID_GRUNT_3, 7
.set LOCALID_GRUNT_4, 8

#define FLAG_RIN_STARTER_GIVEN    0x20 // Unused Flag



Route119_WeatherInstitute_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_2F_OnTransition
	.byte 0

Route119_WeatherInstitute_2F_OnTransition:
	setflag FLAG_UNUSED_0x026
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone
	call_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear
	end

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere::
	setobjectxyperm LOCALID_SCIENTIST, 1, 6
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone::
	setobjectxyperm LOCALID_SCIENTIST, 4, 6
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear::
	setobjectxyperm LOCALID_SCIENTIST, 2, 2
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_UP
	return

Route119_WeatherInstitute_2F_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_5, Route119_WeatherInstitute_2F_Text_Grunt5Intro, Route119_WeatherInstitute_2F_Text_Grunt5Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_2, Route119_WeatherInstitute_2F_Text_Grunt2Intro, Route119_WeatherInstitute_2F_Text_Grunt2Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_3, Route119_WeatherInstitute_2F_Text_Grunt3Intro, Route119_WeatherInstitute_2F_Text_Grunt3Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_WEATHER_INSTITUTE, Route119_WeatherInstitute_2F_Text_ShellyIntro, Route119_WeatherInstitute_2F_Text_ShellyDefeat, Route119_WeatherInstitute_2F_EventScript_ShellyDefeated
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_ShellyDefeated::
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_DEFAULT
	closemessage
	addobject LOCALID_GRUNT_3
	applymovement LOCALID_GRUNT_3, Route119_WeatherInstitute_2F_Movement_GruntApproachShelly
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SHELLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SHELLY, Common_Movement_Delay48
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre, MSGBOX_DEFAULT
	closemessage
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_SHELLY
	removeobject LOCALID_GRUNT_4
	removeobject LOCALID_GRUNT_3
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_SCIENTIST, Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer
	waitmovement 0
	copyobjectxytoperm LOCALID_SCIENTIST
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastform::
	msgbox Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_CASTFORM
	givemon SPECIES_CASTFORM, 25, ITEM_MYSTIC_WATER
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	end

Route119_WeatherInstitute_2F_EventScript_SendCastformToPC::
	call Common_EventScript_TransferredToPC
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CASTFORM
	return

Route119_WeatherInstitute_2F_EventScript_ExplainCastform::
	msgbox Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_CASTFORM
	release
	end

Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather::
	goto_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather
	msgbox Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather::
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather  @ Both defeated
	call_if_unset FLAG_TEMP_2, Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather
	specialvar VAR_RESULT, GetAbnormalWeatherMapNameAndType
	goto_if_eq VAR_RESULT, 1, Route119_WeatherInstitute_2F_EventScript_KyogreWeather
	msgbox Route119_WeatherInstitute_2F_Text_GroudonWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_KyogreWeather::
	msgbox Route119_WeatherInstitute_2F_Text_KyogreWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather::
	special CreateAbnormalWeatherEvent
	setflag FLAG_TEMP_2
	return

Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather::
	msgbox Route119_WeatherInstitute_2F_Text_NoAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_Movement_GruntApproachShelly:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	ride_water_current_up
	walk_in_place_faster_down
	step_end

Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition:
	slide_down
	walk_in_place_faster_left
	step_end

Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer:
	walk_right
	walk_right
	walk_right
	step_end

Route119_WeatherInstitute_2F_EventScript_WeatherScientist::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_Text_Grunt2Intro:
	.string "The INSTITUTE created a type of\n"
	.string "POKéMON that has something to do with\l"
	.string "the weather. We're here to take them!$"

Route119_WeatherInstitute_2F_Text_Grunt2Defeat:
	.string "Our plan's being spoiled by a kid?$"

Route119_WeatherInstitute_2F_Text_Grunt2PostBattle:
	.string "If the POKéMON they made here can\n"
	.string "control the weather freely, then we of\l"
	.string "TEAM AQUA definitely need it!$"

Route119_WeatherInstitute_2F_Text_Grunt3Intro:
	.string "We're TEAM AQUA!\n"
	.string "We appear wherever anything rare is\l"
	.string "found!$"

Route119_WeatherInstitute_2F_Text_Grunt3Defeat:
	.string "You got me!$"

Route119_WeatherInstitute_2F_Text_Grunt3PostBattle:
	.string "You don't have any idea what we of\n"
	.string "TEAM AQUA are working towards!\l"
	.string "You stay out of our way!$"

Route119_WeatherInstitute_2F_Text_Grunt5Intro:
	.string "Don't tell me you're looking for that\n"
	.string "weather POKéMON, too?\p"
	.string "That's a no-no!\n"
	.string "We were here to get it first!$"

Route119_WeatherInstitute_2F_Text_Grunt5Defeat:
	.string "Oh, will you look at my POKéMON?$"

Route119_WeatherInstitute_2F_Text_Grunt5PostBattle:
	.string "Humph, so what?\n"
	.string "What we want…\p"
	.string "What we really want isn't here…\n"
	.string "Ihihihihi…$"

Route119_WeatherInstitute_2F_Text_ShellyIntro:
	.string "Ahahahaha!\p"
	.string "You're going to meddle in TEAM AQUA's\n"
	.string "affairs?\p"
	.string "You're either absolutely fearless,\n"
	.string "simply ignorant, or both!\p"
	.string "You're so cute, you're disgusting!\n"
	.string "I'll put you down, kiddy!$"

Route119_WeatherInstitute_2F_Text_ShellyDefeat:
	.string "Ahahahaha!\n"
	.string "You're disgustingly strong!$"

Route119_WeatherInstitute_2F_Text_ShellyPostBattle:
	.string "It's bad enough to have TEAM MAGMA\n"
	.string "blunder about, but now there's you!\p"
	.string "What makes you want to sniff around\n"
	.string "in our business, anyway?$"

Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy:
	.string "We have a situation here!\p"
	.string "A TEAM MAGMA mob just passed\n"
	.string "the WEATHER INSTITUTE.\p"
	.string "They appear to be headed for\n"
	.string "MT. PYRE!$"

Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre:
	.string "What?!\p"
	.string "We can't waste any more time here!\n"
	.string "We have to hurry to MT. PYRE, too!\p"
	.string "Ahahahaha!\n"
	.string "TEAM MAGMA, just you wait!$"

Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon:
	.string "Thanks!\n"
	.string "Thanks to you, we're safe!\p"
	.string "It might be an odd way of thanking you,\n"
	.string "but take this POKéMON.$"

@ Unused
Route119_WeatherInstitute_2F_Text_NoRoomForPokemon:
	.string "Hm? You don't seem to have any room\n"
	.string "for this POKéMON.$"

Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform:
	.string "{PLAYER} received CASTFORM!$"

Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather:
	.string "That POKéMON changes shape according\n"
	.string "to the weather conditions.\p"
	.string "There're plenty of them in the\n"
	.string "INSTITUTE--go ahead and take it.$"

Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous:
	.string "I've been researching rain for many\n"
	.string "years, but it's ridiculous to think that\l"
	.string "humans can freely change the weather.$"

Route119_WeatherInstitute_2F_Text_GroudonWeather:
	.string "I track weather patterns over\n"
	.string "the HOENN region.\p"
	.string "Presently, a drought has been recorded\n"
	.string "in {STR_VAR_1}.\p"
	.string "Could that mean, somewhere near\n"
	.string "{STR_VAR_1}…$"

Route119_WeatherInstitute_2F_Text_KyogreWeather:
	.string "I track weather patterns over\n"
	.string "the HOENN region.\p"
	.string "Presently, heavy rainfall has been\n"
	.string "recorded over {STR_VAR_1}.\p"
	.string "Could that mean, somewhere near\n"
	.string "{STR_VAR_1}…$"

Route119_WeatherInstitute_2F_Text_NoAbnormalWeather:
	.string "Abnormal weather conditions are\n"
	.string "no longer being reported.\p"
	.string "The occasional rainfall is a blessing,\n"
	.string "really.$"

Rin_Choose_Pkmn::
	lock
	faceplayer
	goto_if_set FLAG_RIN_STARTER_GIVEN, Rin_MessageEvent_Starter_Given
	msgbox Rin_lab_frustrated_assistant, MSGBOX_NPC
	message Rin_Please_Choose_Text
	waitmessage
	goto Rin_Lab_Choose_Starter_Script
	end
	
Rin_MessageEvent_Starter_Given::
	msgbox Rin_Starter_Given_Text, MSGBOX_NPC
	end
	
Rin_Starter_Given_Text:
	.string "Good luck with your adventure!$"
	
Rin_Please_Choose_Text:
	.string "Please choose a POKéMON.$"
	
Rin_Lab_Choose_Starter_Script::
	setvar VAR_0x8009, 0
	setvar VAR_0x8004, SCROLL_MULTI_RIN_STARTER
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, Rin_Starter_Chosen_ABRA
	case 1, Rin_Starter_Chosen_ARON
	case 2, Rin_Starter_Chosen_BAGON
	case 3, Rin_Starter_Chosen_BELDUM
	case 4, Rin_Starter_Chosen_BELLSPROUT
	case 5, Rin_Starter_Chosen_BULBASAUR
	case 6, Rin_Starter_Chosen_CATERPIE
	case 7, Rin_Starter_Chosen_CHARMANDER
	case 8, Rin_Starter_Chosen_CHIKORITA
	case 9, Rin_Starter_Chosen_CYNDAQUIL
	case 10, Rin_Starter_Chosen_DRATINI
	case 11, Rin_Starter_Chosen_EEVEE
	case 12, Rin_Starter_Chosen_GASTLY
	case 13, Rin_Starter_Chosen_GEODUDE
	case 14, Rin_Starter_Chosen_HORSEA
	case 15, Rin_Starter_Chosen_LARVITAR
	case 16, Rin_Starter_Chosen_LOTAD
	case 17, Rin_Starter_Chosen_MAREEP
	case 18, Rin_Starter_Chosen_MUDKIP
	case 19, Rin_Starter_Chosen_NIDORAN_M
	case 20, Rin_Starter_Chosen_NIDORAN_F
	case 21, Rin_Starter_Chosen_ODDISH
	case 22, Rin_Starter_Chosen_PIDGEY
	case 23, Rin_Starter_Chosen_POLIWAG
	case 24, Rin_Starter_Chosen_RALTS
	case 25, Rin_Starter_Chosen_SEEDOT
	case 26, Rin_Starter_Chosen_SLAKOTH
	case 27, Rin_Starter_Chosen_SLOWPOKE
	case 28, Rin_Starter_Chosen_SPHEAL
	case 29, Rin_Starter_Chosen_SQUIRTLE
	case 30, Rin_Starter_Chosen_TORCHIC
	case 31, Rin_Starter_Chosen_TOTODILE
	case 32, Rin_Starter_Chosen_TRAPINCH
	case 33, Rin_Starter_Chosen_TREECKO
	case 34, Rin_Starter_Chosen_WEEDLE
	case 35, Rin_Starter_Chosen_WHISMUR
	case 36, Rin_Starter_Chosen_WURMPLE
	case 37, Rin_Starter_Chosen_ZUBAT
	case 38, Rin_Starter_Cancelled
	case MULTI_B_PRESSED, Rin_Starter_Cancelled
	end

Rin_Starter_Chosen_BULBASAUR::
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	givemon SPECIES_BULBASAUR, 5, ITEM_NONE 
	setflag FLAG_SYS_POKEMON_GET   
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare	
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end

Rin_Starter_Chosen_SQUIRTLE::
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	givemon SPECIES_SQUIRTLE, 5, ITEM_NONE
	setflag FLAG_SYS_POKEMON_GET   
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare	
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end

Rin_Starter_Chosen_CHARMANDER::
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	givemon SPECIES_CHARMANDER, 5, ITEM_NONE  
	setflag FLAG_SYS_POKEMON_GET   
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end

Rin_Starter_Chosen_CHIKORITA::
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	givemon SPECIES_CHIKORITA, 5, ITEM_NONE  
	setflag FLAG_SYS_POKEMON_GET   
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end

Rin_Starter_Chosen_TOTODILE::
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	givemon SPECIES_TOTODILE, 5, ITEM_NONE  
	setflag FLAG_SYS_POKEMON_GET   
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end

Rin_Starter_Chosen_CYNDAQUIL::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_CYNDAQUIL, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_ABRA::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_ABRA, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_ARON::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_ARON, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_BAGON::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_BAGON, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_BELDUM::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_BELDUM, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_BELLSPROUT::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_BELLSPROUT, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_CATERPIE::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_CATERPIE, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_DRATINI::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_DRATINI, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_EEVEE::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_EEVEE, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_GASTLY::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_GASTLY, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_GEODUDE::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_GEODUDE, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_HORSEA::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_HORSEA, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_LARVITAR::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_LARVITAR, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_LOTAD::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_LOTAD, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_MAREEP::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_MAREEP, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_MUDKIP::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_MUDKIP, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_NIDORAN_F::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_NIDORAN_F, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_NIDORAN_M::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_NIDORAN_M, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_ODDISH::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_ODDISH, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end

Rin_Starter_Chosen_PIDGEY::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_PIDGEY, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_POLIWAG::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_POLIWAG, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_RALTS::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_RALTS, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_SEEDOT::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_SEEDOT, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_SLAKOTH::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_SLAKOTH, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_SLOWPOKE::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_SLOWPOKE, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_SPHEAL::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_SPHEAL, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_TORCHIC::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_TORCHIC, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_TRAPINCH::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_TRAPINCH, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end

Rin_Starter_Chosen_TREECKO::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_TREECKO, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_WEEDLE::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_WEEDLE, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_WHISMUR::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_WHISMUR, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end

Rin_Starter_Chosen_WURMPLE::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_WURMPLE, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
Rin_Starter_Chosen_ZUBAT::	
	msgbox Rin_Starter_You_Sure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Rin_Starter_Cancelled
	setflag FLAG_SYS_POKEMON_GET   
	givemon SPECIES_ZUBAT, 5, ITEM_NONE  
	playfanfare MUS_OBTAIN_ITEM 
	waitfanfare
	msgbox Rin_Poke_Is_Yours, MSGBOX_DEFAULT
	setflag FLAG_RIN_STARTER_GIVEN
	setvar VAR_UNUSED_0x40FA, 2
	goto rinspawnfollowerpokescript
	end
	
rinspawnfollowerpokescript:
	addobject 2
	setfollower 2, 0x7E
	updatefollowerpokemongraphic
//	msgbox rin_called_properly_text, MSGBOX_DEFAULT
	releaseall
	end

//rin_called_properly_text:
//	.string "The follower script was called successfully$"

Rin_Starter_Cancelled::
	release
	end

Rin_Poke_Is_Yours:
	.string "Received the POKéMON!$"
	
Rin_Starter_You_Sure:
	.string "Are you sure?$"
	
Rin_aspen_starter_spiel:
	.string "Ah, hello there!\p"
	.string "You must be {PLAYER}, is it?\n"
	.string "It's your birthday today?\p"
	.string "I expect you've come here for your\n"
	.string "POKéMON, then.\p"
	.string "The POKéMON for new trainers are\n"
	.string "stored upstairs.\p"
	.string "My assistant will be able to help.\n"
	.string "Come see me once you've chosen.$"

Rin_aspen_lab_script::
	goto_if_set FLAG_RIN_STARTER_GIVEN, Aspen_lab_orientation_script
	msgbox Rin_aspen_starter_spiel, MSGBOX_NPC
	end
	
Aspen_lab_orientation_script:
		msgbox Rin_aspen_orientation_spiel, MSGBOX_NPC
		end

Rin_aspen_orientation_spiel:
	.string "Made a new friend, I see!\p"
	.string "If you're anything like the others,\n"
	.string "you'll be wanting to set off\l"
	.string "into the wilderness.\p"
	.string "Most new trainers focus on\n"
	.string "trying to collect RIN CRYSTALS.\p"
	.string "That's what we research here.\p"
	.string "They have a million applications,\n"
	.string "and are only found in this region.\p"
	.string "I'm sure you know that already, though.\p"
	.string "Here we have all the samples we need,\n"
	.string "but people around town will trade\l"
	.string "you for them.$"
	
Rin_lab_frustrated_assistant:
	.string "Arghh, Prof. Aspen has had me up\n"
	.string "here for 3 days sorting this.\p"
	.string "Every box you sort has another box\n"
	.string "underneath it.\p"
	.string "Oh, you're a new trainer?\p"
	.string "Lucky for you, I just found this\n"
	.string "box of POKéBALLS.\p"
	.string "Take a look...$"