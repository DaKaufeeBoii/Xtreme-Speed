Kanto_CeladonCity_DepartmentStore_4F_MapScripts::
	.byte 0

Kanto_CeladonCity_DepartmentStore_4F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Kanto_CeladonCity_DepartmentStore_4F_EventScript_Clerk_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Kanto_CeladonCity_DepartmentStore_4F_EventScript_Clerk_Items:
	.short ITEM_ULTRA_BALL
	.short ITEM_HYPER_POTION
	.short ITEM_MAX_POTION
	.short ITEM_FULL_RESTORE
	.short ITEM_REVIVE
	.short ITEM_FULL_HEAL
	.short ITEM_MAX_REPEL
	pokemartlistend

Kanto_CeladonCity_DepartmentStore_4F_EventScript_FloorSign::
	msgbox Kanto_CeladonCity_DepartmentStore_4F_EventScript_FloorSign_Text, MSGBOX_SIGN
	end

Kanto_CeladonCity_DepartmentStore_4F_EventScript_FloorSign_Text:
		.string "Express yourself with gifts!\n"
	.string "4F: WISE MAN GIFTS\l"
	.string "Evolution Special!\n"
	.string "Element STONES on sale now!$"
Kanto_CeladonCity_DepartmentStore_4F_EventScript_Man::
	msgbox Kanto_CeladonCity_DepartmentStore_4F_EventScript_Man_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_DepartmentStore_4F_EventScript_Man_Text:
		.string "I heard something useful.\l"
	.string "If a wild POKeMON appears, you can\n"
	.string "distract it with a POKe DOLL.\l"
	.string "You can run away while the wild\n"
	.string "POKeMON is distracted.$"
Kanto_CeladonCity_DepartmentStore_4F_EventScript_Youngster::
	msgbox Kanto_CeladonCity_DepartmentStore_4F_EventScript_Youngster_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_DepartmentStore_4F_EventScript_Youngster_Text:
		.string "I heard something useful.\l"
	.string "If a wild POKeMON appears, you can\n"
	.string "distract it with a POKe DOLL.\l"
	.string "You can run away while the wild\n"
	.string "POKeMON is distracted.$"
