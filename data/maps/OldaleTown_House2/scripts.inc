OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "MOUNT EPHYRA is strictly off limits\n"
	.string "for most people.\p"
	.string "I suppose the elders have enough to deal\n"
	.string "with without us common folk barging in.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Every winner of the RIN GRANDMASTER\n"
	.string "SERIES gets granted special access to\l"
	.string "MOUNT EPHYRA.\p"
	.string "They must get invited to join the ELDER\n"
	.string "COUNCIL or something, because they\l"
	.string "don't tend to come out again.$"