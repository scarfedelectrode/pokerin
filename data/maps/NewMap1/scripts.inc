.set LOCALID_DAYCARE_MAN, 12

NewMap1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RinCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_OnTransition
	.byte 0
	
	
RinCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	end
	
BattleFrontier_ExchangeServiceCorner_EventScript_OddityClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_ODDITY_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_Oddities
	end


BattleFrontier_ExchangeServiceCorner_EventScript_Oddities::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_ODDITIES
//	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
//	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_FIRE_STONE
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_LEAF_STONE
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_MOON_STONE
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_THUNDER_STONE
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_WATER_STONE
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_PP_UP
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_EXP_SHARE
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_GO_GOGGLES
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_ACRO_BIKE
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_MACH_BIKE
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_SUPER_ROD
	case 11, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end
	
	
BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_SUPER_ROD::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_Oddities
	setvar VAR_0x8008, 10
	setvar VAR_0x8009, ITEM_SUPER_ROD
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end
	
BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_MACH_BIKE::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_Oddities
	setvar VAR_0x8008, 10
	setvar VAR_0x8009, ITEM_MACH_BIKE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end
	
BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_ACRO_BIKE::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_Oddities
	setvar VAR_0x8008, 10
	setvar VAR_0x8009, ITEM_ACRO_BIKE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end
	
BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_GO_GOGGLES::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_Oddities
	setvar VAR_0x8008, 10
	setvar VAR_0x8009, ITEM_GO_GOGGLES
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end
	
BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_EXP_SHARE::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_Oddities
	setvar VAR_0x8008, 10
	setvar VAR_0x8009, ITEM_EXP_SHARE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end
BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_PP_UP::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_Oddities
	setvar VAR_0x8008, 10
	setvar VAR_0x8009, ITEM_PP_MAX
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end
	
BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_THUNDER_STONE::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_Oddities
	setvar VAR_0x8008, 10
	setvar VAR_0x8009, ITEM_THUNDER_STONE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end
	
BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_MOON_STONE::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_Oddities
	setvar VAR_0x8008, 10
	setvar VAR_0x8009, ITEM_MOON_STONE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end
	
BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_LEAF_STONE::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_Oddities
	setvar VAR_0x8008, 10
	setvar VAR_0x8009, ITEM_LEAF_STONE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end
	
BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_WATER_STONE::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_Oddities
	setvar VAR_0x8008, 10
	setvar VAR_0x8009, ITEM_WATER_STONE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_FIRE_STONE::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_Oddities
	setvar VAR_0x8008, 10
	setvar VAR_0x8009, ITEM_FIRE_STONE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end
	
BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin:
	.string "Are you sure?$"
	
//Route101_EventScript_PreventExitSouth::
//	lockall
//	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
//	closemessage
//	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitSouth
//	waitmovement 0
//	releaseall
//	end
	
BattleFrontier_ExchangeServiceCorner_EventScript_TMHMClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_TMHM_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcometmhm
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	end


BattleFrontier_ExchangeServiceCorner_EventScript_TMHM::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_TMHM
//	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
//	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM01_FOCUS_PUNCH
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM02_DRAGON_CLAW
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM03_WATER_PULSE
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM04_CALM_MIND
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM05_ROAR
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM06_TOXIC
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM07_HAIL
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM08_BULK_UP
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM09_BULLET_SEED
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM10_HIDDEN_POWER
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM11_SUNNY_DAY
	case 11, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM12_TAUNT
	case 12, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM13_ICE_BEAM
	case 13, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM14_BLIZZARD
	case 14, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM15_HYPER_BEAM
	case 15, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM16_LIGHT_SCREEN
	case 16, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM17_PROTECT
	case 17, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM18_RAIN_DANCE
	case 18, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM19_GIGA_DRAIN
	case 19, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM20_SAFEGUARD
	case 20, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM21_FRUSTRATION
	case 21, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM22_SOLAR_BEAM
	case 22, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM23_IRON_TAIL
	case 23, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM24_THUNDERBOLT
	case 24, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM25_THUNDER
	case 25, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM26_EARTHQUAKE
	case 26, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM27_RETURN
	case 27, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM28_DIG
	case 28, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM29_PSYCHIC
	case 29, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM30_SHADOW_BALL
	case 30, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM31_BRICK_BREAK
	case 31, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM32_DOUBLE_TEAM
	case 32, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM33_REFLECT
	case 33, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM34_SHOCK_WAVE
	case 34, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM35_FLAMETHROWER
	case 35, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM36_SLUDGE_BOMB
	case 36, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM37_SANDSTORM
	case 37, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM38_FIRE_BLAST
	case 38, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM39_ROCK_TOMB
	case 39, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM40_AERIAL_ACE
	case 40, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM41_TORMENT
	case 41, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM42_FACADE
	case 42, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM43_SECRET_POWER
	case 43, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM44_REST
	case 44, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM45_ATTRACT
	case 45, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM46_THIEF
	case 46, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM47_STEEL_WING
	case 47, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM48_SKILL_SWAP
	case 48, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM49_SNATCH
	case 49, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM50_OVERHEAT
	case 50, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_ITEM_HM01_CUT
	case 51, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_HM02_FLY
	case 52, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_HM03_SURF
	case 53, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_HM04_STRENGTH
	case 54, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_HM05_FLASH
	case 55, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_HM06_ROCK_SMASH
	case 56, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_HM07_WATERFALL
	case 57, BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_HM08_DIVE
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end
	
BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM01_FOCUS_PUNCH::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM01_FOCUS_PUNCH
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM02_DRAGON_CLAW::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM02_DRAGON_CLAW
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM03_WATER_PULSE::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM03_WATER_PULSE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM04_CALM_MIND::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM04_CALM_MIND
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM05_ROAR::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM05_ROAR
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM06_TOXIC::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM06_TOXIC
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM07_HAIL::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM07_HAIL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM08_BULK_UP::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM08_BULK_UP
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM09_BULLET_SEED::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM09_BULLET_SEED
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM10_HIDDEN_POWER::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM10_HIDDEN_POWER
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM11_SUNNY_DAY::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM11_SUNNY_DAY
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM12_TAUNT::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM12_TAUNT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM13_ICE_BEAM::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM13_ICE_BEAM
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM14_BLIZZARD::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM14_BLIZZARD
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM15_HYPER_BEAM::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM15_HYPER_BEAM
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM16_LIGHT_SCREEN::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM16_LIGHT_SCREEN
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM17_PROTECT::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM17_PROTECT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM18_RAIN_DANCE::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM18_RAIN_DANCE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM19_GIGA_DRAIN::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM19_GIGA_DRAIN
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM20_SAFEGUARD::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM20_SAFEGUARD
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM21_FRUSTRATION::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM21_FRUSTRATION
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM22_SOLAR_BEAM::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM22_SOLAR_BEAM
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM23_IRON_TAIL::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM23_IRON_TAIL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM24_THUNDERBOLT::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM24_THUNDERBOLT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM25_THUNDER::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM25_THUNDER
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM26_EARTHQUAKE::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM26_EARTHQUAKE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM27_RETURN::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM27_RETURN
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM28_DIG::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM28_DIG
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM29_PSYCHIC::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM29_PSYCHIC
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM30_SHADOW_BALL::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM30_SHADOW_BALL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM31_BRICK_BREAK::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM31_BRICK_BREAK
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM32_DOUBLE_TEAM::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM32_DOUBLE_TEAM
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM33_REFLECT::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM33_REFLECT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM34_SHOCK_WAVE::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM34_SHOCK_WAVE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM35_FLAMETHROWER::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM35_FLAMETHROWER
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM36_SLUDGE_BOMB::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM36_SLUDGE_BOMB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM37_SANDSTORM::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM37_SANDSTORM
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM38_FIRE_BLAST::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM38_FIRE_BLAST
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM39_ROCK_TOMB::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM39_ROCK_TOMB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM40_AERIAL_ACE::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM40_AERIAL_ACE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM41_TORMENT::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM41_TORMENT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM42_FACADE::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM42_FACADE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM43_SECRET_POWER::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM43_SECRET_POWER
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM44_REST::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM44_REST
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM45_ATTRACT::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM45_ATTRACT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM46_THIEF::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM46_THIEF
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM47_STEEL_WING::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM47_STEEL_WING
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM48_SKILL_SWAP::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM48_SKILL_SWAP
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM49_SNATCH::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM49_SNATCH
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_TM50_OVERHEAT::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_TM50_OVERHEAT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_ITEM_HM01_CUT::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_HM01_CUT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_HM02_FLY::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_HM02_FLY
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_HM03_SURF::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_HM03_SURF
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_HM04_STRENGTH::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_HM04_STRENGTH
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_HM05_FLASH::	
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_HM05_FLASH
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_HM06_ROCK_SMASH::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_HM06_ROCK_SMASH
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_HM07_WATERFALL::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_HM07_WATERFALL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ITEM_HM08_DIVE::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_Confirm_Rin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_TMHM
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, ITEM_HM08_DIVE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end
	
BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcometmhm::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrizetmhm, MSGBOX_DEFAULT
	special ShowBattlePointsWindow
	return
	
RC_ACOLAWOODS_SIGN::
	msgbox ACOLAWOODS_Text_TownSign, MSGBOX_SIGN
	end
	
ACOLAWOODS_Text_TownSign:
	.string "ACOLA WOODS\p"
	.string "“An enchanted forest under\n"
	.string "a rainy sky.”$"

RC_THASSALO_SEA_SIGN::
	msgbox THASSALOSEA_Text_TownSign, MSGBOX_SIGN
	end
	
THASSALOSEA_Text_TownSign:
	.string "THASSALO SEA\p"
	.string "“RIN's gateway to the wider world.”$"
	
RC_THUNDERHILLS_SIGN::
	msgbox THUNDERHILLS_Text_TownSign, MSGBOX_SIGN
	end
	
THUNDERHILLS_Text_TownSign:
	.string "THUNDER HILLS\p"
	.string "“Thriving industry nestled within\n"
	.string "stormy highlands.”$"
	
RC_MESAROJA_SIGN::
	msgbox MESAROJA_Text_TownSign, MSGBOX_SIGN
	end
	
MESAROJA_Text_TownSign:
	.string "MESA ROJA\p"
	.string "“Cool, damp caves under\n"
	.string "sun scorched badlands.”$"
	
RC_IOPARANGE_SIGN::
	msgbox IOPARANGE_Text_TownSign, MSGBOX_SIGN
	end
	
IOPARANGE_Text_TownSign:
	.string "SKYPEAK MOUNTAIN RANGE\p"
	.string "“RIN's twin peaks, \n"
	.string "MOUNT IO and MOUNT CALISTO.”$"
	
RC_TOPANGAJUNGLE_SIGN::
	msgbox TOPANGAJUNGLE_Text_TownSign, MSGBOX_SIGN
	end
	
TOPANGAJUNGLE_Text_TownSign:
	.string "TOPANGA JUNGLE\p"
	.string "“Once a centre of ecological research,\n"
	.string "now reclaimed by nature itself.”$"
	
RC_DRIFTSEEDPLAINS_SIGN::
	msgbox DRIFTSEEDPLAINS_Text_TownSign, MSGBOX_SIGN
	end
	
DRIFTSEEDPLAINS_Text_TownSign:
	.string "DRIFTSEED PLAINS\p"
	.string "“The breadbasket of RIN.”$"
	
RC_MURKMIRESWAMP_SIGN::
	msgbox MURKMIRESWAMP_Text_TownSign, MSGBOX_SIGN
	end
	
MURKMIRESWAMP_Text_TownSign:
	.string "MURKMIRE SWAMP\p"
	.string "“Humidity, sludge and\n"
	.string "waste disposal.”$"
	
RC_ASPENLABS_SIGN::
	msgbox ASPENLABS_Text_TownSign, MSGBOX_SIGN
	end
	
ASPENLABS_Text_TownSign:
	.string "PROF. ASPEN'S LAB$"
	
RC_BATTLELABYRINTH_SIGN::
	msgbox BLAB_Text_TownSign, MSGBOX_SIGN
	end
	
BLAB_Text_TownSign:
	.string "BATTLE LABYRINTH\p"
	.string "Where the best trainers in RIN\n"
	.string "test their mettle.”$"
	
RC_CONTEST_SIGN::
	msgbox RCCONTEST_Text_TownSign, MSGBOX_SIGN
	end
	
RCCONTEST_Text_TownSign:
	.string "CONTEST HALL$"
	
RC_DEPSTORE_SIGN::
	msgbox DEPSTORE_Text_TownSign, MSGBOX_SIGN
	end
	
DEPSTORE_Text_TownSign:
	.string "RIN CITY DEPARTMENT STORE$"
	
RC_MARKET_SIGN::
	msgbox RCMARKET_Text_TownSign, MSGBOX_SIGN
	end
	
RCMARKET_Text_TownSign:
	.string "RIN CITY MARKETPLACE$"
	
RC_EVENTSCIPT_PEDESTRIAN1::
	msgbox RC_TEXT_PEDESTRIAN1, MSGBOX_NPC
	end

RC_EVENTSCIPT_PEDESTRIAN2::
	msgbox RC_TEXT_PEDESTRIAN2, MSGBOX_NPC
	end
	
RC_EVENTSCIPT_PEDESTRIAN3::
	msgbox RC_TEXT_PEDESTRIAN3, MSGBOX_NPC
	end
	
RC_EVENTSCIPT_PEDESTRIAN4::
	msgbox RC_TEXT_PEDESTRIAN4, MSGBOX_NPC
	end
	
RC_EVENTSCIPT_PEDESTRIAN5::
	msgbox RC_TEXT_PEDESTRIAN5, MSGBOX_NPC
	end
	
RC_EVENTSCIPT_PEDESTRIAN6::
	msgbox RC_TEXT_PEDESTRIAN6, MSGBOX_NPC
	end
	
RC_EVENTSCIPT_PEDESTRIAN7::
	msgbox RC_TEXT_PEDESTRIAN7, MSGBOX_NPC
	end
	
RC_EVENTSCIPT_guard1::
	msgbox RC_TEXT_guard1, MSGBOX_NPC
	end
	
RC_EVENTSCIPT_guard2::
	msgbox RC_TEXT_guard1, MSGBOX_NPC
	end

RC_TEXT_PEDESTRIAN1:
	.string "I'm on my way to the department store.\p"
	.string "If there's one thing we get right in\n"
	.string "RIN CITY, it's the shopping!$"

RC_TEXT_PEDESTRIAN2:
	.string "Oh, hi there.\p"
	.string "These berries are, uh, not entirely\n"
	.string "legal.\p"
	.string "I won't tell if you don't, though.$"
	
RC_TEXT_PEDESTRIAN3:
	.string "I went to MURKMIRE SWAMP to try and\n"
	.string "catch some new POKéMON.\p"
	.string "You can catch lots of cool POISON\n"
	.string "types there.\p"
	.string "I think they're drawn by the pollution.$"
	
RC_TEXT_PEDESTRIAN4:
	.string "LEFTOVERS, SUBSTITUTE, CALM MIND...\p"
	.string "Am I ready to compete yet?$"
	
RC_TEXT_PEDESTRIAN5:
	.string "My girl's competing over at the\n"
	.string "CONTEST HALL.\p"
	.string "She really loves that FURRET.$"
	
RC_TEXT_PEDESTRIAN6:
	.string "Me and my friend like to play\n"
	.string "over here in the grass.\p"
	.string "I want to play in the park, but\n"
	.string "mother says it's too dangerous.$"

RC_TEXT_PEDESTRIAN7:
	.string "Hey neighbour!\p"
	.string "I wish I was older like you, so I\n"
	.string "could get my own POKéMON.$"
	
RC_TEXT_guard1:
	.string "You may not pass.\p"
	.string "Only those who have proven themselves\n"
	.string "in the LABYRINTH may enter.$"
	
	