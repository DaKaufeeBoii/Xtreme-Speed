Kanto_LavenderTown_Mart_MapScripts::
	.byte 0

Kanto_LavenderTown_Mart_EventScript_BaldingMan::
	msgbox Kanto_LavenderTown_Mart_EventScript_BaldingMan_Text, MSGBOX_NPC
	end

Kanto_LavenderTown_Mart_EventScript_BaldingMan_Text:
		.string "Did you buy some REVIVES?\n"
	.string "They revive any fainted POKeMON!$"
Kanto_LavenderTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Kanto_LavenderTown_Mart_EventScript_Clerk_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Kanto_LavenderTown_Mart_EventScript_Clerk_Items:
	.short ITEM_ULTRA_BALL
	.short ITEM_HYPER_POTION
	.short ITEM_MAX_POTION
	.short ITEM_FULL_RESTORE
	.short ITEM_REVIVE
	.short ITEM_FULL_HEAL
	.short ITEM_MAX_REPEL
	pokemartlistend

Kanto_LavenderTown_Mart_EventScript_Rocker::
	msgbox Kanto_LavenderTown_Mart_EventScript_Rocker_Text, MSGBOX_NPC
	end

Kanto_LavenderTown_Mart_EventScript_Rocker_Text:
		.string "Did you buy some REVIVES?\n"
	.string "They revive any fainted POKeMON!$"
Kanto_LavenderTown_Mart_EventScript_Youngster::
	msgbox Kanto_LavenderTown_Mart_EventScript_Youngster_Text, MSGBOX_NPC
	end

Kanto_LavenderTown_Mart_EventScript_Youngster_Text:
		.string "Sometimes, a TRAINER duo will\n"
	.string "challenge you with two POKeMON\p"
	.string "at the same time.\l"
	.string "If that happens, you have to send\n"
	.string "out two POKeMON to battle, too.$"
