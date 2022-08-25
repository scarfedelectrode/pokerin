WoodlandBurrow_MapScripts::
	.byte 0


wburrowfoundziggyscript::
	lock
	faceplayer
	msgbox wburrowfoundziggytext, MSGBOX_DEFAULT
	msgbox wburrowreceivedziggytext, MSGBOX_DEFAULT
	setflag FLAG_UNUSED_0x028
	removeobject VAR_LAST_TALKED
	release
	end

wburrowfoundziggytext:
	.string "The ZIGZAGOON stares intently into\n"
	.string "your eyes for a moment then, suddenly,\l"
	.string "leaps straight into your backpack.$"



wburrowreceivedziggytext:
	.string "Received ZIGGY!$"