Kanto_LavenderTown_PokemonCenter_1F_MapScripts::
	.byte 0

Kanto_LavenderTown_PokemonCenter_1F_EventScript_BaldingMan::
	msgbox Kanto_LavenderTown_PokemonCenter_1F_EventScript_BaldingMan_Text, MSGBOX_NPC
	end

Kanto_LavenderTown_PokemonCenter_1F_EventScript_BaldingMan_Text:
		.string "POKeMON JOURNAL\l"
	.string "Special Feature:\n"
	.string "MR. FUJI of POKeMON HOUSE!\l"
	.string "Editor: The shy MR. FUJI turned\n"
	.string "down our interview requests.\l"
	.string "He is a kindly man who is adored\n"
	.string "and respected in LAVENDER TOWN.$"
Kanto_LavenderTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox Kanto_LavenderTown_PokemonCenter_1F_EventScript_Gentleman_Text, MSGBOX_NPC
	end

Kanto_LavenderTown_PokemonCenter_1F_EventScript_Gentleman_Text:
		.string "TEAM ROCKET will do anything for\n"
	.string "the sake of money!\l"
	.string "There is no job too dirty, no deed\n"
	.string "too heinous, no crime too wicked!$"
Kanto_LavenderTown_PokemonCenter_1F_EventScript_Lass::
	msgbox Kanto_LavenderTown_PokemonCenter_1F_EventScript_Lass_Text, MSGBOX_NPC
	end

Kanto_LavenderTown_PokemonCenter_1F_EventScript_Lass_Text:
		.string "You know how the CUBONE species\n"
	.string "wears skulls, right?\l"
	.string "People will pay a lot for one.$"
Kanto_LavenderTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

Kanto_LavenderTown_PokemonCenter_1F_EventScript_Youngster::
	msgbox Kanto_LavenderTown_PokemonCenter_1F_EventScript_Youngster_Text, MSGBOX_NPC
	end

Kanto_LavenderTown_PokemonCenter_1F_EventScript_Youngster_Text:
		.string "You know how the CUBONE species\n"
	.string "wears skulls, right?\l"
	.string "People will pay a lot for one.$"
