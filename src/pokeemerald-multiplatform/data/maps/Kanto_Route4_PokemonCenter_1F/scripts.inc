Kanto_Route4_PokemonCenter_1F_MapScripts::
	.byte 0

Kanto_Route4_PokemonCenter_1F_EventScript_Boy::
	msgbox Kanto_Route4_PokemonCenter_1F_EventScript_Boy_Text, MSGBOX_NPC
	end

Kanto_Route4_PokemonCenter_1F_EventScript_Boy_Text:
	.string "I heard rumors of rare POKeMON living in the depths of CERULEAN CAVE!$"
Kanto_Route4_PokemonCenter_1F_EventScript_Gentleman::
	msgbox Kanto_Route4_PokemonCenter_1F_EventScript_Gentleman_Text, MSGBOX_NPC
	end

Kanto_Route4_PokemonCenter_1F_EventScript_Gentleman_Text:
	.string "A true gentleman treats his POKeMON with utmost dignity and grace.$"
Kanto_Route4_PokemonCenter_1F_EventScript_MagikarpSalesman::
	msgbox Kanto_Route4_PokemonCenter_1F_EventScript_MagikarpSalesman_Text, MSGBOX_NPC
	end

Kanto_Route4_PokemonCenter_1F_EventScript_MagikarpSalesman_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_Route4_PokemonCenter_1F_EventScript_Newspaper::
	msgbox Kanto_Route4_PokemonCenter_1F_EventScript_Newspaper_Text, MSGBOX_NPC
	end

Kanto_Route4_PokemonCenter_1F_EventScript_Newspaper_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_Route4_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

Kanto_Route4_PokemonCenter_1F_EventScript_Youngster::
	msgbox Kanto_Route4_PokemonCenter_1F_EventScript_Youngster_Text, MSGBOX_NPC
	end

Kanto_Route4_PokemonCenter_1F_EventScript_Youngster_Text:
	.string "My POKeMON and I practice running every day along the routes!$"
