Kanto_Route25_SeaCottage_MapScripts::
	.byte 0

Kanto_Route25_SeaCottage_EventScript_Bill::
	msgbox Kanto_Route25_SeaCottage_EventScript_Bill_Text, MSGBOX_NPC
	end

Kanto_Route25_SeaCottage_EventScript_Bill_Text:
			.string "Wait till I get inside the\n"
	.string "TELEPORTER.\l"
	.string "When I do, go to my PC and run\n"
	.string "the Cell Separation System.$"
Kanto_Route25_SeaCottage_EventScript_Computer::
	msgbox Kanto_Route25_SeaCottage_EventScript_Computer_Text, MSGBOX_NPC
	end

Kanto_Route25_SeaCottage_EventScript_Computer_Text:
		.string "TELEPORTER is displayed on the PC\n"
	.string "monitor.$"
