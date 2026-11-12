Kanto_PokemonTower_3F_MapScripts::
	.byte 0

Kanto_PokemonTower_3F_EventScript_Carly::
	msgbox Kanto_PokemonTower_3F_EventScript_Carly_Text, MSGBOX_NPC
	end

Kanto_PokemonTower_3F_EventScript_Carly_Text:
		.string "Hmm?\n"
	.string "What am I doing?$"
Kanto_PokemonTower_3F_EventScript_Hope::
	msgbox Kanto_PokemonTower_3F_EventScript_Hope_Text, MSGBOX_NPC
	end

Kanto_PokemonTower_3F_EventScript_Hope_Text:
		.string "The ghosts can be identified by\n"
	.string "the SILPH SCOPE.$"
Kanto_PokemonTower_3F_EventScript_ItemEscapeRope::
	msgbox Kanto_PokemonTower_3F_EventScript_ItemEscapeRope_Text, MSGBOX_DEFAULT
	release
	end

Kanto_PokemonTower_3F_EventScript_ItemEscapeRope_Text:
	.string "Found a valuable item for your journey!$"
Kanto_PokemonTower_3F_EventScript_Patricia::
	msgbox Kanto_PokemonTower_3F_EventScript_Patricia_Text, MSGBOX_NPC
	end

Kanto_PokemonTower_3F_EventScript_Patricia_Text:
		.string "Be gone!\n"
	.string "Malevolent spirit!$"
