Kanto_CeladonCity_PokemonCenter_1F_MapScripts::
	.byte 0

Kanto_CeladonCity_PokemonCenter_1F_EventScript_CooltrainerF::
	msgbox Kanto_CeladonCity_PokemonCenter_1F_EventScript_CooltrainerF_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_PokemonCenter_1F_EventScript_CooltrainerF_Text:
		.string "If I had a BIKE, I would go to\n"
	.string "CYCLING ROAD!$"
Kanto_CeladonCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox Kanto_CeladonCity_PokemonCenter_1F_EventScript_Gentleman_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_PokemonCenter_1F_EventScript_Gentleman_Text:
		.string "A POKe FLUTE awakens sleeping\n"
	.string "POKeMON. You know that.\l"
	.string "It does so with a sound that only\n"
	.string "they can hear.$"
Kanto_CeladonCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

Kanto_CeladonCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox Kanto_CeladonCity_PokemonCenter_1F_EventScript_Youngster_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_PokemonCenter_1F_EventScript_Youngster_Text:
		.string "If I had a BIKE, I would go to\n"
	.string "CYCLING ROAD!$"
