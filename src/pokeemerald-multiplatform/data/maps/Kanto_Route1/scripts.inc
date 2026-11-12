Kanto_Route1_MapScripts::
	.byte 0

Kanto_Route1_EventScript_Boy::
	msgbox Kanto_Route1_EventScript_Boy_Text, MSGBOX_NPC
	end

Kanto_Route1_EventScript_Boy_Text:
		.string "ROUTE 1\n"
	.string "PALLET TOWN - VIRIDIAN CITY$"
Kanto_Route1_EventScript_MartClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Kanto_Route1_EventScript_MartClerk_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Kanto_Route1_EventScript_MartClerk_Items:
	.short ITEM_ULTRA_BALL
	.short ITEM_HYPER_POTION
	.short ITEM_MAX_POTION
	.short ITEM_FULL_RESTORE
	.short ITEM_REVIVE
	.short ITEM_FULL_HEAL
	.short ITEM_MAX_REPEL
	pokemartlistend

Kanto_Route1_EventScript_RouteSign::
	msgbox Kanto_Route1_EventScript_RouteSign_Text, MSGBOX_SIGN
	end

Kanto_Route1_EventScript_RouteSign_Text:
		.string "ROUTE 1\n"
	.string "PALLET TOWN - VIRIDIAN CITY$"
