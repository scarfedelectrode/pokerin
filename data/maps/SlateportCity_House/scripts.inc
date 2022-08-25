SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "When checking your POKéMON's stats,\n"
	.string "press the L and R buttons on your\l"
	.string "POKéDEX to check IVs and EVs.$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "There are special berries which can\n"
	.string "increase the IVs of POKéMON.\p"
	.string "I think I saw some growing in the park.$"

