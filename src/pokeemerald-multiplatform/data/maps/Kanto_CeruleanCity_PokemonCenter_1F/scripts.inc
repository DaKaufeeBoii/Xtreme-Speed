Kanto_CeruleanCity_PokemonCenter_1F_MapScripts::
	.byte 0

Kanto_CeruleanCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox Kanto_CeruleanCity_PokemonCenter_1F_EventScript_Gentleman_Text, MSGBOX_NPC
	end

Kanto_CeruleanCity_PokemonCenter_1F_EventScript_Gentleman_Text:
		.string "BILL has lots of POKeMON!\n"
	.string "He collects rare ones, too!$"
Kanto_CeruleanCity_PokemonCenter_1F_EventScript_Lass::
	msgbox Kanto_CeruleanCity_PokemonCenter_1F_EventScript_Lass_Text, MSGBOX_NPC
	end

Kanto_CeruleanCity_PokemonCenter_1F_EventScript_Lass_Text:
		.string "TM03 teaches WATER PULSE.\l"
	.string "Use it on an aquatic POKeMON!$"
Kanto_CeruleanCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

Kanto_CeruleanCity_PokemonCenter_1F_EventScript_PokemonJournalMisty::
	msgbox Kanto_CeruleanCity_PokemonCenter_1F_EventScript_PokemonJournalMisty_Text, MSGBOX_NPC
	end

Kanto_CeruleanCity_PokemonCenter_1F_EventScript_PokemonJournalMisty_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_CeruleanCity_PokemonCenter_1F_EventScript_Rocker::
	msgbox Kanto_CeruleanCity_PokemonCenter_1F_EventScript_Rocker_Text, MSGBOX_NPC
	end

Kanto_CeruleanCity_PokemonCenter_1F_EventScript_Rocker_Text:
		.string "BILL has lots of POKeMON!\n"
	.string "He collects rare ones, too!$"
Kanto_CeruleanCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox Kanto_CeruleanCity_PokemonCenter_1F_EventScript_Youngster_Text, MSGBOX_NPC
	end

Kanto_CeruleanCity_PokemonCenter_1F_EventScript_Youngster_Text:
		.string "BILL has lots of POKeMON!\n"
	.string "He collects rare ones, too!$"
