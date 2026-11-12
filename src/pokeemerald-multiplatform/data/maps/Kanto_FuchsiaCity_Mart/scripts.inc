Kanto_FuchsiaCity_Mart_MapScripts::
	.byte 0

Kanto_FuchsiaCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Kanto_FuchsiaCity_Mart_EventScript_Clerk_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Kanto_FuchsiaCity_Mart_EventScript_Clerk_Items:
	.short ITEM_ULTRA_BALL
	.short ITEM_HYPER_POTION
	.short ITEM_MAX_POTION
	.short ITEM_FULL_RESTORE
	.short ITEM_REVIVE
	.short ITEM_FULL_HEAL
	.short ITEM_MAX_REPEL
	pokemartlistend

Kanto_FuchsiaCity_Mart_EventScript_CooltrainerF::
	msgbox Kanto_FuchsiaCity_Mart_EventScript_CooltrainerF_Text, MSGBOX_NPC
	end

Kanto_FuchsiaCity_Mart_EventScript_CooltrainerF_Text:
		.string "Did you try X SPEED?\n"
	.string "It speeds up a POKeMON in battle.$"
Kanto_FuchsiaCity_Mart_EventScript_Gentleman::
	msgbox Kanto_FuchsiaCity_Mart_EventScript_Gentleman_Text, MSGBOX_NPC
	end

Kanto_FuchsiaCity_Mart_EventScript_Gentleman_Text:
		.string "Hi, there!\n"
	.string "May I help you?$"
