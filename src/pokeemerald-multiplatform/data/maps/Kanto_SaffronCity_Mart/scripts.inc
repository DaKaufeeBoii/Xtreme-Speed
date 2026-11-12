Kanto_SaffronCity_Mart_MapScripts::
	.byte 0

Kanto_SaffronCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Kanto_SaffronCity_Mart_EventScript_Clerk_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Kanto_SaffronCity_Mart_EventScript_Clerk_Items:
	.short ITEM_ULTRA_BALL
	.short ITEM_HYPER_POTION
	.short ITEM_MAX_POTION
	.short ITEM_FULL_RESTORE
	.short ITEM_REVIVE
	.short ITEM_FULL_HEAL
	.short ITEM_MAX_REPEL
	pokemartlistend

Kanto_SaffronCity_Mart_EventScript_Lass::
	msgbox Kanto_SaffronCity_Mart_EventScript_Lass_Text, MSGBOX_NPC
	end

Kanto_SaffronCity_Mart_EventScript_Lass_Text:
		.string "REVIVE is costly, but it revives\n"
	.string "fainted POKeMON!$"
Kanto_SaffronCity_Mart_EventScript_Youngster::
	msgbox Kanto_SaffronCity_Mart_EventScript_Youngster_Text, MSGBOX_NPC
	end

Kanto_SaffronCity_Mart_EventScript_Youngster_Text:
		.string "MAX REPEL keeps weaker POKeMON\n"
	.string "from appearing.\l"
	.string "MAX REPEL stays effective longer\n"
	.string "than SUPER REPEL.$"
