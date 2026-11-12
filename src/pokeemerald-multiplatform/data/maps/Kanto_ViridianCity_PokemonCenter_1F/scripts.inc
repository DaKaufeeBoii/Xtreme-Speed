Kanto_ViridianCity_PokemonCenter_1F_MapScripts::
	.byte 0

Kanto_ViridianCity_PokemonCenter_1F_EventScript_Boy::
	msgbox Kanto_ViridianCity_PokemonCenter_1F_EventScript_Boy_Text, MSGBOX_NPC
	end

Kanto_ViridianCity_PokemonCenter_1F_EventScript_Boy_Text:
		.string "POKeMON CENTERS heal your tired,\n"
	.string "hurt, or fainted POKeMON.\l"
	.string "They make all POKeMON completely\n"
	.string "healthy.$"
Kanto_ViridianCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox Kanto_ViridianCity_PokemonCenter_1F_EventScript_Gentleman_Text, MSGBOX_NPC
	end

Kanto_ViridianCity_PokemonCenter_1F_EventScript_Gentleman_Text:
		.string "POKeMON CENTERS heal your tired,\n"
	.string "hurt, or fainted POKeMON.\l"
	.string "They make all POKeMON completely\n"
	.string "healthy.$"
Kanto_ViridianCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

Kanto_ViridianCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox Kanto_ViridianCity_PokemonCenter_1F_EventScript_Youngster_Text, MSGBOX_NPC
	end

Kanto_ViridianCity_PokemonCenter_1F_EventScript_Youngster_Text:
		.string "POKeMON CENTERS heal your tired,\n"
	.string "hurt, or fainted POKeMON.\l"
	.string "They make all POKeMON completely\n"
	.string "healthy.$"
