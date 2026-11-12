Kanto_PewterCity_PokemonCenter_1F_MapScripts::
	.byte 0

Kanto_MysteryEventClub_EventScript_Woman::
	msgbox Kanto_MysteryEventClub_EventScript_Woman_Text, MSGBOX_NPC
	end

Kanto_MysteryEventClub_EventScript_Woman_Text:
		.string "Please tell me more about\n"
	.string "yourself next time!$"
Kanto_PewterCity_PokemonCenter_1F_EventScript_GBAKid1::
	msgbox Kanto_PewterCity_PokemonCenter_1F_EventScript_GBAKid1_Text, MSGBOX_NPC
	end

Kanto_PewterCity_PokemonCenter_1F_EventScript_GBAKid1_Text:
		.string "POKeMON learn new techniques as\n"
	.string "they grow.\l"
	.string "But some moves must be taught to\n"
	.string "them by people.$"
Kanto_PewterCity_PokemonCenter_1F_EventScript_GBAKid2::
	msgbox Kanto_PewterCity_PokemonCenter_1F_EventScript_GBAKid2_Text, MSGBOX_NPC
	end

Kanto_PewterCity_PokemonCenter_1F_EventScript_GBAKid2_Text:
		.string "POKeMON learn new techniques as\n"
	.string "they grow.\l"
	.string "But some moves must be taught to\n"
	.string "them by people.$"
Kanto_PewterCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox Kanto_PewterCity_PokemonCenter_1F_EventScript_Gentleman_Text, MSGBOX_NPC
	end

Kanto_PewterCity_PokemonCenter_1F_EventScript_Gentleman_Text:
		.string "JIGGLYPUFF: Puu pupuu!$"
Kanto_PewterCity_PokemonCenter_1F_EventScript_Jigglypuff::
	msgbox Kanto_PewterCity_PokemonCenter_1F_EventScript_Jigglypuff_Text, MSGBOX_NPC
	end

Kanto_PewterCity_PokemonCenter_1F_EventScript_Jigglypuff_Text:
		.string "JIGGLYPUFF: Puu pupuu!$"
Kanto_PewterCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

Kanto_PewterCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox Kanto_PewterCity_PokemonCenter_1F_EventScript_Youngster_Text, MSGBOX_NPC
	end

Kanto_PewterCity_PokemonCenter_1F_EventScript_Youngster_Text:
		.string "POKeMON learn new techniques as\n"
	.string "they grow.\l"
	.string "But some moves must be taught to\n"
	.string "them by people.$"
