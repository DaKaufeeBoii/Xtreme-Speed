Kanto_SaffronCity_PokemonCenter_1F_MapScripts::
	.byte 0

Kanto_SaffronCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox Kanto_SaffronCity_PokemonCenter_1F_EventScript_Gentleman_Text, MSGBOX_NPC
	end

Kanto_SaffronCity_PokemonCenter_1F_EventScript_Gentleman_Text:
		.string "POKeMON growth rates differ from\n"
	.string "species to species.$"
Kanto_SaffronCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

Kanto_SaffronCity_PokemonCenter_1F_EventScript_PokemonJournalSabrina::
	msgbox Kanto_SaffronCity_PokemonCenter_1F_EventScript_PokemonJournalSabrina_Text, MSGBOX_NPC
	end

Kanto_SaffronCity_PokemonCenter_1F_EventScript_PokemonJournalSabrina_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_SaffronCity_PokemonCenter_1F_EventScript_Woman::
	msgbox Kanto_SaffronCity_PokemonCenter_1F_EventScript_Woman_Text, MSGBOX_NPC
	end

Kanto_SaffronCity_PokemonCenter_1F_EventScript_Woman_Text:
		.string "POKeMON growth rates differ from\n"
	.string "species to species.$"
Kanto_SaffronCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox Kanto_SaffronCity_PokemonCenter_1F_EventScript_Youngster_Text, MSGBOX_NPC
	end

Kanto_SaffronCity_PokemonCenter_1F_EventScript_Youngster_Text:
		.string "{PLAYER} received TM29\n"
	.string "from MR. PSYCHIC.$"
