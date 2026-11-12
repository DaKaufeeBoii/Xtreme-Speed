Kanto_CinnabarIsland_Mart_MapScripts::
	.byte 0

Kanto_CinnabarIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Kanto_CinnabarIsland_Mart_EventScript_Clerk_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Kanto_CinnabarIsland_Mart_EventScript_Clerk_Items:
	.short ITEM_ULTRA_BALL
	.short ITEM_HYPER_POTION
	.short ITEM_MAX_POTION
	.short ITEM_FULL_RESTORE
	.short ITEM_REVIVE
	.short ITEM_FULL_HEAL
	.short ITEM_MAX_REPEL
	pokemartlistend

Kanto_CinnabarIsland_Mart_EventScript_Scientist::
	msgbox Kanto_CinnabarIsland_Mart_EventScript_Scientist_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Mart_EventScript_Scientist_Text:
		.string "It never hurts to have extra items.\n"
	.string "You never know what might happen.$"
Kanto_CinnabarIsland_Mart_EventScript_Woman::
	msgbox Kanto_CinnabarIsland_Mart_EventScript_Woman_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Mart_EventScript_Woman_Text:
		.string "It never hurts to have extra items.\n"
	.string "You never know what might happen.$"
