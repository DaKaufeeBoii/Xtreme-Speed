Kanto_CeladonCity_DepartmentStore_5F_MapScripts::
	.byte 0

Kanto_CeladonCity_DepartmentStore_5F_EventScript_ClerkVitamins::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Kanto_CeladonCity_DepartmentStore_5F_EventScript_ClerkVitamins_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Kanto_CeladonCity_DepartmentStore_5F_EventScript_ClerkVitamins_Items:
	.short ITEM_ULTRA_BALL
	.short ITEM_HYPER_POTION
	.short ITEM_MAX_POTION
	.short ITEM_FULL_RESTORE
	.short ITEM_REVIVE
	.short ITEM_FULL_HEAL
	.short ITEM_MAX_REPEL
	pokemartlistend

Kanto_CeladonCity_DepartmentStore_5F_EventScript_ClerkXItems::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Kanto_CeladonCity_DepartmentStore_5F_EventScript_ClerkXItems_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Kanto_CeladonCity_DepartmentStore_5F_EventScript_ClerkXItems_Items:
	.short ITEM_ULTRA_BALL
	.short ITEM_HYPER_POTION
	.short ITEM_MAX_POTION
	.short ITEM_FULL_RESTORE
	.short ITEM_REVIVE
	.short ITEM_FULL_HEAL
	.short ITEM_MAX_REPEL
	pokemartlistend

Kanto_CeladonCity_DepartmentStore_5F_EventScript_FloorSign::
	msgbox Kanto_CeladonCity_DepartmentStore_5F_EventScript_FloorSign_Text, MSGBOX_SIGN
	end

Kanto_CeladonCity_DepartmentStore_5F_EventScript_FloorSign_Text:
		.string "5F: DRUGSTORE$"
Kanto_CeladonCity_DepartmentStore_5F_EventScript_Gentleman::
	msgbox Kanto_CeladonCity_DepartmentStore_5F_EventScript_Gentleman_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_DepartmentStore_5F_EventScript_Gentleman_Text:
		.string "POKeMON stat enhancers can be\n"
	.string "bought only here.\l"
	.string "HP UP increases the base HP of a\n"
	.string "POKeMON.\l"
	.string "CALCIUM raises the base SP. ATK\n"
	.string "stat of one POKeMON.\l"
	.string "ZINC boosts the base SP. DEF stat\n"
	.string "of one POKeMON.\l"
	.string "CARBOS enhances the base SPEED\n"
	.string "stat.$"
Kanto_CeladonCity_DepartmentStore_5F_EventScript_Sailor::
	msgbox Kanto_CeladonCity_DepartmentStore_5F_EventScript_Sailor_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_DepartmentStore_5F_EventScript_Sailor_Text:
		.string "5F: DRUGSTORE$"
