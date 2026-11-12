Kanto_FuchsiaCity_PokemonCenter_1F_MapScripts::
	.byte 0

Kanto_FuchsiaCity_PokemonCenter_1F_EventScript_CooltrainerF::
	msgbox Kanto_FuchsiaCity_PokemonCenter_1F_EventScript_CooltrainerF_Text, MSGBOX_NPC
	end

Kanto_FuchsiaCity_PokemonCenter_1F_EventScript_CooltrainerF_Text:
		.string "WARDEN: Hif fuff hefifoo!\l"
	.string "Ha lof ha feef ee hafahi ho.\n"
	.string "Heff hee fwee!$"
Kanto_FuchsiaCity_PokemonCenter_1F_EventScript_Man::
	msgbox Kanto_FuchsiaCity_PokemonCenter_1F_EventScript_Man_Text, MSGBOX_NPC
	end

Kanto_FuchsiaCity_PokemonCenter_1F_EventScript_Man_Text:
		.string "WARDEN: Hif fuff hefifoo!\l"
	.string "Ha lof ha feef ee hafahi ho.\n"
	.string "Heff hee fwee!$"
Kanto_FuchsiaCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

Kanto_FuchsiaCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox Kanto_FuchsiaCity_PokemonCenter_1F_EventScript_Youngster_Text, MSGBOX_NPC
	end

Kanto_FuchsiaCity_PokemonCenter_1F_EventScript_Youngster_Text:
		.string "WARDEN: Hif fuff hefifoo!\l"
	.string "Ha lof ha feef ee hafahi ho.\n"
	.string "Heff hee fwee!$"
