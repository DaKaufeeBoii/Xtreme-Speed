Kanto_SafariZone_SecretHouse_MapScripts::
	.byte 0

Kanto_SafariZone_SecretHouse_EventScript_Attendant::
	msgbox Kanto_SafariZone_SecretHouse_EventScript_Attendant_Text, MSGBOX_NPC
	end

Kanto_SafariZone_SecretHouse_EventScript_Attendant_Text:
		.string "{PLAYER} received HM03\n"
	.string "from the attendant!$"
