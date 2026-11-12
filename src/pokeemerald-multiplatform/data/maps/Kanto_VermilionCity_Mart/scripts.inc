Kanto_VermilionCity_Mart_MapScripts::
	.byte 0

Kanto_VermilionCity_Mart_EventScript_BaldingMan::
	msgbox Kanto_VermilionCity_Mart_EventScript_BaldingMan_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_Mart_EventScript_BaldingMan_Text:
		.string "Hi, there!\n"
	.string "May I help you?$"
Kanto_VermilionCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Kanto_VermilionCity_Mart_EventScript_Clerk_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Kanto_VermilionCity_Mart_EventScript_Clerk_Items:
	.short ITEM_ULTRA_BALL
	.short ITEM_HYPER_POTION
	.short ITEM_MAX_POTION
	.short ITEM_FULL_RESTORE
	.short ITEM_REVIVE
	.short ITEM_FULL_HEAL
	.short ITEM_MAX_REPEL
	pokemartlistend

Kanto_VermilionCity_Mart_EventScript_CooltrainerF::
	msgbox Kanto_VermilionCity_Mart_EventScript_CooltrainerF_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_Mart_EventScript_CooltrainerF_Text:
		.string "I think POKeMON can be good or\n"
	.string "bad. It depends on the TRAINER.$"
