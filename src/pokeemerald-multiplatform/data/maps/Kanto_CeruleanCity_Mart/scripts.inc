Kanto_CeruleanCity_Mart_MapScripts::
	.byte 0

Kanto_CeruleanCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Kanto_CeruleanCity_Mart_EventScript_Clerk_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Kanto_CeruleanCity_Mart_EventScript_Clerk_Items:
	.short ITEM_ULTRA_BALL
	.short ITEM_HYPER_POTION
	.short ITEM_MAX_POTION
	.short ITEM_FULL_RESTORE
	.short ITEM_REVIVE
	.short ITEM_FULL_HEAL
	.short ITEM_MAX_REPEL
	pokemartlistend

Kanto_CeruleanCity_Mart_EventScript_Woman::
	msgbox Kanto_CeruleanCity_Mart_EventScript_Woman_Text, MSGBOX_NPC
	end

Kanto_CeruleanCity_Mart_EventScript_Woman_Text:
		.string "Hi, there!\n"
	.string "May I help you?$"
Kanto_CeruleanCity_Mart_EventScript_Youngster::
	msgbox Kanto_CeruleanCity_Mart_EventScript_Youngster_Text, MSGBOX_NPC
	end

Kanto_CeruleanCity_Mart_EventScript_Youngster_Text:
		.string "Hi, there!\n"
	.string "May I help you?$"
