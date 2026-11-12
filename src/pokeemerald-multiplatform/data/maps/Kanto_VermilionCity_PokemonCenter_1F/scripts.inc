Kanto_VermilionCity_PokemonCenter_1F_MapScripts::
	.byte 0

Kanto_VermilionCity_PokemonCenter_1F_EventScript_Hiker::
	msgbox Kanto_VermilionCity_PokemonCenter_1F_EventScript_Hiker_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_PokemonCenter_1F_EventScript_Hiker_Text:
		.string "Even if they are the same level,\n"
	.string "POKeMON can have very different\p"
	.string "stats and abilities.\l"
	.string "A POKeMON raised by a TRAINER is\n"
	.string "stronger than one in the wild.$"
Kanto_VermilionCity_PokemonCenter_1F_EventScript_Man::
	msgbox Kanto_VermilionCity_PokemonCenter_1F_EventScript_Man_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_PokemonCenter_1F_EventScript_Man_Text:
		.string "My POKeMON was poisoned!\n"
	.string "It fainted while we were walking!$"
Kanto_VermilionCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

Kanto_VermilionCity_PokemonCenter_1F_EventScript_PokemonJournalLtSurge::
	msgbox Kanto_VermilionCity_PokemonCenter_1F_EventScript_PokemonJournalLtSurge_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_PokemonCenter_1F_EventScript_PokemonJournalLtSurge_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_VermilionCity_PokemonCenter_1F_EventScript_VSSeekerWoman::
	msgbox Kanto_VermilionCity_PokemonCenter_1F_EventScript_VSSeekerWoman_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_PokemonCenter_1F_EventScript_VSSeekerWoman_Text:
		.string "First, you should restore your\n"
	.string "POKeMON to full health.$"
Kanto_VermilionCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox Kanto_VermilionCity_PokemonCenter_1F_EventScript_Youngster_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_PokemonCenter_1F_EventScript_Youngster_Text:
		.string "Oh. Come back when you want to\n"
	.string "hear my story!$"
