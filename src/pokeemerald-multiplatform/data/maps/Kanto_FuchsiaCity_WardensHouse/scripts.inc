Kanto_FuchsiaCity_WardensHouse_MapScripts::
	.byte 0

Kanto_FuchsiaCity_WardensHouse_EventScript_DisplaySign1::
	msgbox Kanto_FuchsiaCity_WardensHouse_EventScript_DisplaySign1_Text, MSGBOX_SIGN
	end

Kanto_FuchsiaCity_WardensHouse_EventScript_DisplaySign1_Text:
			.string "POKeMON photos and fossils are on\n"
	.string "display.$"
Kanto_FuchsiaCity_WardensHouse_EventScript_DisplaySign2::
	msgbox Kanto_FuchsiaCity_WardensHouse_EventScript_DisplaySign2_Text, MSGBOX_SIGN
	end

Kanto_FuchsiaCity_WardensHouse_EventScript_DisplaySign2_Text:
			.string "Old POKeMON merchandise is on\n"
	.string "display.$"
Kanto_FuchsiaCity_WardensHouse_EventScript_ItemRareCandy::
	msgbox Kanto_FuchsiaCity_WardensHouse_EventScript_ItemRareCandy_Text, MSGBOX_DEFAULT
	release
	end

Kanto_FuchsiaCity_WardensHouse_EventScript_ItemRareCandy_Text:
	.string "Found a valuable item for your journey!$"
Kanto_FuchsiaCity_WardensHouse_EventScript_PokemonJournalKoga::
	msgbox Kanto_FuchsiaCity_WardensHouse_EventScript_PokemonJournalKoga_Text, MSGBOX_NPC
	end

Kanto_FuchsiaCity_WardensHouse_EventScript_PokemonJournalKoga_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_FuchsiaCity_WardensHouse_EventScript_Warden::
	msgbox Kanto_FuchsiaCity_WardensHouse_EventScript_Warden_Text, MSGBOX_NPC
	end

Kanto_FuchsiaCity_WardensHouse_EventScript_Warden_Text:
		.string "WARDEN: Hif fuff hefifoo!\l"
	.string "Ha lof ha feef ee hafahi ho.\n"
	.string "Heff hee fwee!$"
