Kanto_SafariZone_Center_MapScripts::
	.byte 0

Kanto_SafariZone_Center_EventScript_AreaSign::
	msgbox Kanto_SafariZone_Center_EventScript_AreaSign_Text, MSGBOX_SIGN
	end

Kanto_SafariZone_Center_EventScript_AreaSign_Text:
		.string "CENTER AREA$"
Kanto_SafariZone_Center_EventScript_ItemNugget::
	msgbox Kanto_SafariZone_Center_EventScript_ItemNugget_Text, MSGBOX_DEFAULT
	release
	end

Kanto_SafariZone_Center_EventScript_ItemNugget_Text:
	.string "Found a valuable item for your journey!$"
Kanto_SafariZone_Center_EventScript_RestHouseSign::
	msgbox Kanto_SafariZone_Center_EventScript_RestHouseSign_Text, MSGBOX_SIGN
	end

Kanto_SafariZone_Center_EventScript_RestHouseSign_Text:
		.string "REST HOUSE$"
Kanto_SafariZone_Center_EventScript_TrainerTips::
	msgbox Kanto_SafariZone_Center_EventScript_TrainerTips_Text, MSGBOX_SIGN
	end

Kanto_SafariZone_Center_EventScript_TrainerTips_Text:
		.string "TRAINER TIPS\l"
	.string "Press START to check\n"
	.string "remaining time.$"
