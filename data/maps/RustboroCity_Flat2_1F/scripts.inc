RustboroCity_Flat2_1F_MapScripts::
	.byte 0

RustboroCity_Flat2_1F_EventScript_OldWoman::
	msgbox RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere, MSGBOX_NPC
	end

RustboroCity_Flat2_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox RustboroCity_Flat2_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere:
	.string "RIN is a very diverse region.\p"
	.string "They say we have a wider variety of\n"
	.string "POKéMON than most other places.\p"

RustboroCity_Flat2_1F_Text_Skitty:
	.string "SKITTY: Gyaaaah!$"

