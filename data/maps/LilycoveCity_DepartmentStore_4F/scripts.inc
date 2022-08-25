LilycoveCity_DepartmentStore_4F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_4F_EventScript_Gentleman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Woman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Youngster::
	msgbox LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs:
	.2byte ITEM_POMEG_BERRY
	.2byte ITEM_KELPSY_BERRY
	.2byte ITEM_QUALOT_BERRY
	.2byte ITEM_HONDEW_BERRY
	.2byte ITEM_GREPA_BERRY
	.2byte ITEM_TAMATO_BERRY
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_4F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs:
	.2byte ITEM_RAZZ_BERRY
	.2byte ITEM_BLUK_BERRY
	.2byte ITEM_NANAB_BERRY
	.2byte ITEM_WEPEAR_BERRY
	.2byte ITEM_PINAP_BERRY
	.2byte ITEM_CORNN_BERRY
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM:
	.string "Something's different in Rin's soil.\p"
	.string "Some berries have different effects\n"
	.string "here$"

LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs:
	.string "Some berries reduce a POKéMON's IVs.\p"
	.string "Some reduce its EVs.\p"
	.string "And some increase its IVs...\p"
	.string "I can never keep track of them all.$"

LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves:
	.string "The ELDER COUNCIL banned the use of IV\n"
	.string "increasing berries.\p"
	.string "You can't buy them anymore.\p"
	.string "Between you and me though, you can\n"
	.string "often find them growing wild anyway.\p"
	.string "...\p"
	.string "The ELDER COUNCIL...\p"
	.string "Imagine banning a plant.$"