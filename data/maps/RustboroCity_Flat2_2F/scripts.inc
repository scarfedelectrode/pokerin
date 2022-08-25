RustboroCity_Flat2_2F_MapScripts::
	.byte 0

RustboroCity_Flat2_2F_EventScript_OldMan::
	msgbox RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays, MSGBOX_NPC
	end

RustboroCity_Flat2_2F_EventScript_NinjaBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_PREMIER_BALL_RUSTBORO, RustboroCity_Flat2_2F_EventScript_GavePremierBall
	msgbox RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt, MSGBOX_DEFAULT
	giveitem ITEM_PREMIER_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_PREMIER_BALL_RUSTBORO
	release
	end

RustboroCity_Flat2_2F_EventScript_GavePremierBall::
	msgbox RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays:
	.string "Once upon a time, there was no \n"
	.string "ELDER COUNCIL.\p"
	.string "The people of RIN CITY decided what\n"
	.string "to do as a community...\p"
	.string "Or at least they tried to.\p"
	.string "Then there was a crisis involving\n"
	.string "legendary POKéMON.\p"
	.string "The main corporations of RIN each\n"
	.string "nominated someone to serve on an\l"
	.string "emergency council, with special\l"
	.string "temporary powers to combat the crisis.\p"
	.string "That was nearly 50 years ago.\p"
	.string "That council is now the ELDER COUNCIL.\p"
	.string "Temporary indeed.$"

RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt:
	.string "I found this item whilst playing in the\n"
	.string "park!\n"
	.string "But I can't use it, so you can have it.$"

RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo:
	.string "Grandad doesn't like the ELDER COUNCIL.\p"
	.string "But ssshhh!\p"
	.string "He could get in trouble if they find out.$"
