Kanto_CeladonCity_GameCorner_PrizeRoom_MapScripts::
	.byte 0

Kanto_CeladonCity_GameCorner_PrizeRoom_EventScript_BaldingMan::
	msgbox Kanto_CeladonCity_GameCorner_PrizeRoom_EventScript_BaldingMan_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_PrizeRoom_EventScript_BaldingMan_Text:
		.string "We exchange your COINS for prizes.$"
Kanto_CeladonCity_GameCorner_PrizeRoom_EventScript_OldMan::
	msgbox Kanto_CeladonCity_GameCorner_PrizeRoom_EventScript_OldMan_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_PrizeRoom_EventScript_OldMan_Text:
		.string "We exchange your COINS for prizes.$"
Kanto_CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkItems::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Kanto_CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkItems_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Kanto_CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkItems_Items:
	.short ITEM_ULTRA_BALL
	.short ITEM_HYPER_POTION
	.short ITEM_MAX_POTION
	.short ITEM_FULL_RESTORE
	.short ITEM_REVIVE
	.short ITEM_FULL_HEAL
	.short ITEM_MAX_REPEL
	pokemartlistend

Kanto_CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkMons::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Kanto_CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkMons_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Kanto_CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkMons_Items:
	.short ITEM_ULTRA_BALL
	.short ITEM_HYPER_POTION
	.short ITEM_MAX_POTION
	.short ITEM_FULL_RESTORE
	.short ITEM_REVIVE
	.short ITEM_FULL_HEAL
	.short ITEM_MAX_REPEL
	pokemartlistend

Kanto_CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkTMs::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Kanto_CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkTMs_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Kanto_CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkTMs_Items:
	.short ITEM_ULTRA_BALL
	.short ITEM_HYPER_POTION
	.short ITEM_MAX_POTION
	.short ITEM_FULL_RESTORE
	.short ITEM_REVIVE
	.short ITEM_FULL_HEAL
	.short ITEM_MAX_REPEL
	pokemartlistend

