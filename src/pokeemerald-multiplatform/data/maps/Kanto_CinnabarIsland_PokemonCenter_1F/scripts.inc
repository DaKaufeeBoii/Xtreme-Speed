Kanto_CinnabarIsland_PokemonCenter_1F_MapScripts::
	.byte 0

Kanto_CinnabarIsland_PokemonCenter_1F_EventScript_Bill::
	msgbox Kanto_CinnabarIsland_PokemonCenter_1F_EventScript_Bill_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_PokemonCenter_1F_EventScript_Bill_Text:
		.string "BILL: Hey, you kept me waiting!\n"
	.string "Ready to set sail to ONE ISLAND?$"
Kanto_CinnabarIsland_PokemonCenter_1F_EventScript_CooltrainerF::
	msgbox Kanto_CinnabarIsland_PokemonCenter_1F_EventScript_CooltrainerF_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_PokemonCenter_1F_EventScript_CooltrainerF_Text:
		.string "POKeMON can still learn techniques\n"
	.string "after canceling evolution.\l"
	.string "Evolution can wait until new moves\n"
	.string "have been learned.$"
Kanto_CinnabarIsland_PokemonCenter_1F_EventScript_Gentleman::
	msgbox Kanto_CinnabarIsland_PokemonCenter_1F_EventScript_Gentleman_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_PokemonCenter_1F_EventScript_Gentleman_Text:
		.string "Do you have lots of friends?\l"
	.string "Linking up with the usual friends\n"
	.string "is fun, of course.\l"
	.string "But how about visiting the\n"
	.string "UNION ROOM every so often?\l"
	.string "Who knows, you may end up making\n"
	.string "new friends.\l"
	.string "I think it would be worth your time\n"
	.string "to check the UNION ROOM.$"
Kanto_CinnabarIsland_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

Kanto_CinnabarIsland_PokemonCenter_1F_EventScript_PokemonJournalMrFuji::
	msgbox Kanto_CinnabarIsland_PokemonCenter_1F_EventScript_PokemonJournalMrFuji_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_PokemonCenter_1F_EventScript_PokemonJournalMrFuji_Text:
			.string "POKeMON JOURNAL\l"
	.string "Special Feature:\n"
	.string "MR. FUJI of POKeMON HOUSE!\l"
	.string "Editor: The shy MR. FUJI turned\n"
	.string "down our interview requests.\l"
	.string "He is a kindly man who is adored\n"
	.string "and respected in LAVENDER TOWN.$"
Kanto_CinnabarIsland_PokemonCenter_1F_EventScript_Youngster::
	msgbox Kanto_CinnabarIsland_PokemonCenter_1F_EventScript_Youngster_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_PokemonCenter_1F_EventScript_Youngster_Text:
		.string "POKeMON can still learn techniques\n"
	.string "after canceling evolution.\l"
	.string "Evolution can wait until new moves\n"
	.string "have been learned.$"
