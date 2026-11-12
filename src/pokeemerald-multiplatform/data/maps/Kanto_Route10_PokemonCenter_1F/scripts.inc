Kanto_Route10_PokemonCenter_1F_MapScripts::
	.byte 0

Kanto_Route10_PokemonCenter_1F_EventScript_Aide::
	msgbox Kanto_Route10_PokemonCenter_1F_EventScript_Aide_Text, MSGBOX_NPC
	end

Kanto_Route10_PokemonCenter_1F_EventScript_Aide_Text:
		.string "{PLAYER} received the EVERSTONE\n"
	.string "from the AIDE.$"
Kanto_Route10_PokemonCenter_1F_EventScript_FatMan::
	msgbox Kanto_Route10_PokemonCenter_1F_EventScript_FatMan_Text, MSGBOX_NPC
	end

Kanto_Route10_PokemonCenter_1F_EventScript_FatMan_Text:
		.string "The types of POKeMON match up\n"
	.string "differently with each other.\l"
	.string "Every type is stronger than some\n"
	.string "types and weaker than others.$"
Kanto_Route10_PokemonCenter_1F_EventScript_Gentleman::
	msgbox Kanto_Route10_PokemonCenter_1F_EventScript_Gentleman_Text, MSGBOX_NPC
	end

Kanto_Route10_PokemonCenter_1F_EventScript_Gentleman_Text:
		.string "The types of POKeMON match up\n"
	.string "differently with each other.\l"
	.string "Every type is stronger than some\n"
	.string "types and weaker than others.$"
Kanto_Route10_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

Kanto_Route10_PokemonCenter_1F_EventScript_Youngster::
	msgbox Kanto_Route10_PokemonCenter_1F_EventScript_Youngster_Text, MSGBOX_NPC
	end

Kanto_Route10_PokemonCenter_1F_EventScript_Youngster_Text:
		.string "I heard that ghosts haunt\n"
	.string "LAVENDER TOWN.$"
