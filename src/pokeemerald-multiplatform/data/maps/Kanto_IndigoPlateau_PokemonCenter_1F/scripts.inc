Kanto_IndigoPlateau_PokemonCenter_1F_MapScripts::
	.byte 0

Kanto_IndigoPlateau_PokemonCenter_1F_EventScript_BlackBelt::
	msgbox Kanto_IndigoPlateau_PokemonCenter_1F_EventScript_BlackBelt_Text, MSGBOX_NPC
	end

Kanto_IndigoPlateau_PokemonCenter_1F_EventScript_BlackBelt_Text:
		.string "Play with POKeMON lots and live\n"
	.string "a long life!\l"
	.string "Take AGATHA, for example.\l"
	.string "She set a record for being the\n"
	.string "oldest-ever ELITE FOUR member.\l"
	.string "She spurs me to do bigger things.$"
Kanto_IndigoPlateau_PokemonCenter_1F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Kanto_IndigoPlateau_PokemonCenter_1F_EventScript_Clerk_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Kanto_IndigoPlateau_PokemonCenter_1F_EventScript_Clerk_Items:
	.short ITEM_ULTRA_BALL
	.short ITEM_HYPER_POTION
	.short ITEM_MAX_POTION
	.short ITEM_FULL_RESTORE
	.short ITEM_REVIVE
	.short ITEM_FULL_HEAL
	.short ITEM_MAX_REPEL
	pokemartlistend

Kanto_IndigoPlateau_PokemonCenter_1F_EventScript_CooltrainerM::
	msgbox Kanto_IndigoPlateau_PokemonCenter_1F_EventScript_CooltrainerM_Text, MSGBOX_NPC
	end

Kanto_IndigoPlateau_PokemonCenter_1F_EventScript_CooltrainerM_Text:
		.string "POKeMON JOURNAL\l"
	.string "Special Feature:\n"
	.string "MR. FUJI of POKeMON HOUSE!\l"
	.string "Editor: The shy MR. FUJI turned\n"
	.string "down our interview requests.\l"
	.string "He is a kindly man who is adored\n"
	.string "and respected in LAVENDER TOWN.$"
Kanto_IndigoPlateau_PokemonCenter_1F_EventScript_DoorGuard::
	msgbox Kanto_IndigoPlateau_PokemonCenter_1F_EventScript_DoorGuard_Text, MSGBOX_NPC
	end

Kanto_IndigoPlateau_PokemonCenter_1F_EventScript_DoorGuard_Text:
		.string "From here on, you face the\n"
	.string "ELITE FOUR one by one.\l"
	.string "If you win, a door opens to the\n"
	.string "next TRAINER. Good luck!$"
Kanto_IndigoPlateau_PokemonCenter_1F_EventScript_GymGuy::
	msgbox Kanto_IndigoPlateau_PokemonCenter_1F_EventScript_GymGuy_Text, MSGBOX_NPC
	end

Kanto_IndigoPlateau_PokemonCenter_1F_EventScript_GymGuy_Text:
		.string "Yo!\n"
	.string "Champ in the making!\l"
	.string "At the POKeMON LEAGUE, you will\n"
	.string "face the ELITE FOUR all in a row.\l"
	.string "If you lose, you have to start all\n"
	.string "over again!\l"
	.string "This is it!\n"
	.string "Go for it!$"
Kanto_IndigoPlateau_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

Kanto_IndigoPlateau_PokemonCenter_1F_EventScript_PokemonJournal::
	msgbox Kanto_IndigoPlateau_PokemonCenter_1F_EventScript_PokemonJournal_Text, MSGBOX_NPC
	end

Kanto_IndigoPlateau_PokemonCenter_1F_EventScript_PokemonJournal_Text:
			.string "POKeMON JOURNAL\l"
	.string "Special Feature:\n"
	.string "MR. FUJI of POKeMON HOUSE!\l"
	.string "Editor: The shy MR. FUJI turned\n"
	.string "down our interview requests.\l"
	.string "He is a kindly man who is adored\n"
	.string "and respected in LAVENDER TOWN.$"
