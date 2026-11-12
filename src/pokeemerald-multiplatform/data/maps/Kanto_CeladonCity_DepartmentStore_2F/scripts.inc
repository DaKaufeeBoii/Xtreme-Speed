Kanto_CeladonCity_DepartmentStore_2F_MapScripts::
	.byte 0

Kanto_CeladonCity_DepartmentStore_2F_EventScript_ClerkItems::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Kanto_CeladonCity_DepartmentStore_2F_EventScript_ClerkItems_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Kanto_CeladonCity_DepartmentStore_2F_EventScript_ClerkItems_Items:
	.short ITEM_ULTRA_BALL
	.short ITEM_HYPER_POTION
	.short ITEM_MAX_POTION
	.short ITEM_FULL_RESTORE
	.short ITEM_REVIVE
	.short ITEM_FULL_HEAL
	.short ITEM_MAX_REPEL
	pokemartlistend

Kanto_CeladonCity_DepartmentStore_2F_EventScript_ClerkTMs::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Kanto_CeladonCity_DepartmentStore_2F_EventScript_ClerkTMs_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Kanto_CeladonCity_DepartmentStore_2F_EventScript_ClerkTMs_Items:
	.short ITEM_ULTRA_BALL
	.short ITEM_HYPER_POTION
	.short ITEM_MAX_POTION
	.short ITEM_FULL_RESTORE
	.short ITEM_REVIVE
	.short ITEM_FULL_HEAL
	.short ITEM_MAX_REPEL
	pokemartlistend

Kanto_CeladonCity_DepartmentStore_2F_EventScript_FloorSign::
	msgbox Kanto_CeladonCity_DepartmentStore_2F_EventScript_FloorSign_Text, MSGBOX_SIGN
	end

Kanto_CeladonCity_DepartmentStore_2F_EventScript_FloorSign_Text:
		.string "Hi, there!\n"
	.string "May I help you?$"
Kanto_CeladonCity_DepartmentStore_2F_EventScript_Lass::
	msgbox Kanto_CeladonCity_DepartmentStore_2F_EventScript_Lass_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_DepartmentStore_2F_EventScript_Lass_Text:
		.string "For long outings, you should buy\n"
	.string "REVIVE.$"
Kanto_CeladonCity_DepartmentStore_2F_EventScript_Woman::
	msgbox Kanto_CeladonCity_DepartmentStore_2F_EventScript_Woman_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_DepartmentStore_2F_EventScript_Woman_Text:
		.string "POKeMON JOURNAL\l"
	.string "Special Feature:\n"
	.string "MR. FUJI of POKeMON HOUSE!\l"
	.string "Editor: The shy MR. FUJI turned\n"
	.string "down our interview requests.\l"
	.string "He is a kindly man who is adored\n"
	.string "and respected in LAVENDER TOWN.$"
