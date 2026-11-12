Kanto_SafariZone_East_MapScripts::
	.byte 0

Kanto_SafariZone_East_EventScript_AreaSign::
	msgbox Kanto_SafariZone_East_EventScript_AreaSign_Text, MSGBOX_SIGN
	end

Kanto_SafariZone_East_EventScript_AreaSign_Text:
		.string "AREA 1\n"
	.string "WEST: CENTER AREA$"
Kanto_SafariZone_East_EventScript_ItemFullRestore::
	msgbox Kanto_SafariZone_East_EventScript_ItemFullRestore_Text, MSGBOX_DEFAULT
	release
	end

Kanto_SafariZone_East_EventScript_ItemFullRestore_Text:
	.string "Found a valuable item for your journey!$"
Kanto_SafariZone_East_EventScript_ItemLeafStone::
	msgbox Kanto_SafariZone_East_EventScript_ItemLeafStone_Text, MSGBOX_DEFAULT
	release
	end

Kanto_SafariZone_East_EventScript_ItemLeafStone_Text:
	.string "Found a valuable item for your journey!$"
Kanto_SafariZone_East_EventScript_ItemMaxPotion::
	msgbox Kanto_SafariZone_East_EventScript_ItemMaxPotion_Text, MSGBOX_DEFAULT
	release
	end

Kanto_SafariZone_East_EventScript_ItemMaxPotion_Text:
	.string "Found a valuable item for your journey!$"
Kanto_SafariZone_East_EventScript_ItemTM11::
	msgbox Kanto_SafariZone_East_EventScript_ItemTM11_Text, MSGBOX_DEFAULT
	release
	end

Kanto_SafariZone_East_EventScript_ItemTM11_Text:
	.string "Found a valuable item for your journey!$"
Kanto_SafariZone_East_EventScript_RestHouseSign::
	msgbox Kanto_SafariZone_East_EventScript_RestHouseSign_Text, MSGBOX_SIGN
	end

Kanto_SafariZone_East_EventScript_RestHouseSign_Text:
		.string "REST HOUSE$"
Kanto_SafariZone_East_EventScript_TrainerTips::
	msgbox Kanto_SafariZone_East_EventScript_TrainerTips_Text, MSGBOX_SIGN
	end

Kanto_SafariZone_East_EventScript_TrainerTips_Text:
		.string "TRAINER TIPS\l"
	.string "The remaining time declines only\n"
	.string "while you walk.$"
