Kanto_ViridianCity_Mart_MapScripts::
	.byte 0

Kanto_ViridianCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Kanto_ViridianCity_Mart_EventScript_Clerk_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Kanto_ViridianCity_Mart_EventScript_Clerk_Items:
	.short ITEM_ULTRA_BALL
	.short ITEM_HYPER_POTION
	.short ITEM_MAX_POTION
	.short ITEM_FULL_RESTORE
	.short ITEM_REVIVE
	.short ITEM_FULL_HEAL
	.short ITEM_MAX_REPEL
	pokemartlistend

Kanto_ViridianCity_Mart_EventScript_Woman::
	msgbox Kanto_ViridianCity_Mart_EventScript_Woman_Text, MSGBOX_NPC
	end

Kanto_ViridianCity_Mart_EventScript_Woman_Text:
		.string "POKeMON CENTERS heal your tired,\n"
	.string "hurt, or fainted POKeMON.\l"
	.string "They make all POKeMON completely\n"
	.string "healthy.$"
Kanto_ViridianCity_Mart_EventScript_Youngster::
	msgbox Kanto_ViridianCity_Mart_EventScript_Youngster_Text, MSGBOX_NPC
	end

Kanto_ViridianCity_Mart_EventScript_Youngster_Text:
		.string "POKeMON CENTERS heal your tired,\n"
	.string "hurt, or fainted POKeMON.\l"
	.string "They make all POKeMON completely\n"
	.string "healthy.$"
