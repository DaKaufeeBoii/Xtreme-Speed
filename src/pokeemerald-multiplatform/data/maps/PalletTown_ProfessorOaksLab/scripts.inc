PalletTown_ProfessorOaksLab_MapScripts::
	.byte 0

PalletTown_ProfessorOaksLab_EventScript_Oak::
	lock
	faceplayer
	goto_if_set FLAG_OAK_STARTER_RECEIVED, PalletTown_ProfessorOaksLab_EventScript_OakAfterChoice
	goto_if_set FLAG_BADGE_BOULDER_GET, PalletTown_ProfessorOaksLab_EventScript_OakOfferStarters
	msgbox PalletTown_ProfessorOaksLab_Text_OakWelcome, MSGBOX_DEFAULT
	release
	end

PalletTown_ProfessorOaksLab_EventScript_OakOfferStarters::
	msgbox PalletTown_ProfessorOaksLab_Text_OakOfferStarters, MSGBOX_DEFAULT
	release
	end

PalletTown_ProfessorOaksLab_EventScript_OakAfterChoice::
	msgbox PalletTown_ProfessorOaksLab_Text_OakAfterChoice, MSGBOX_DEFAULT
	release
	end

PalletTown_ProfessorOaksLab_EventScript_Bulbasaur::
	lock
	goto_if_unset FLAG_BADGE_BOULDER_GET, PalletTown_ProfessorOaksLab_EventScript_BallNotYet
	showmonpic SPECIES_BULBASAUR, 10, 3
	msgbox PalletTown_ProfessorOaksLab_Text_ChooseBulbasaur, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PalletTown_ProfessorOaksLab_EventScript_GiveBulbasaur
	hidemonpic
	release
	end

PalletTown_ProfessorOaksLab_EventScript_GiveBulbasaur::
	givemon SPECIES_BULBASAUR, 50, ITEM_MIRACLE_SEED
	hidemonpic
	playfanfare MUS_OBTAIN_ITEM
	message PalletTown_ProfessorOaksLab_Text_ReceivedBulbasaur
	waitfanfare
	setflag FLAG_OAK_STARTER_RECEIVED
	removeobject 2
	msgbox PalletTown_ProfessorOaksLab_Text_TakeCareOfBulbasaur, MSGBOX_DEFAULT
	release
	end

PalletTown_ProfessorOaksLab_EventScript_Charmander::
	lock
	goto_if_unset FLAG_BADGE_BOULDER_GET, PalletTown_ProfessorOaksLab_EventScript_BallNotYet
	showmonpic SPECIES_CHARMANDER, 10, 3
	msgbox PalletTown_ProfessorOaksLab_Text_ChooseCharmander, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PalletTown_ProfessorOaksLab_EventScript_GiveCharmander
	hidemonpic
	release
	end

PalletTown_ProfessorOaksLab_EventScript_GiveCharmander::
	givemon SPECIES_CHARMANDER, 50, ITEM_CHARCOAL
	hidemonpic
	playfanfare MUS_OBTAIN_ITEM
	message PalletTown_ProfessorOaksLab_Text_ReceivedCharmander
	waitfanfare
	setflag FLAG_OAK_STARTER_RECEIVED
	removeobject 3
	msgbox PalletTown_ProfessorOaksLab_Text_TakeCareOfCharmander, MSGBOX_DEFAULT
	release
	end

PalletTown_ProfessorOaksLab_EventScript_Squirtle::
	lock
	goto_if_unset FLAG_BADGE_BOULDER_GET, PalletTown_ProfessorOaksLab_EventScript_BallNotYet
	showmonpic SPECIES_SQUIRTLE, 10, 3
	msgbox PalletTown_ProfessorOaksLab_Text_ChooseSquirtle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PalletTown_ProfessorOaksLab_EventScript_GiveSquirtle
	hidemonpic
	release
	end

PalletTown_ProfessorOaksLab_EventScript_GiveSquirtle::
	givemon SPECIES_SQUIRTLE, 50, ITEM_MYSTIC_WATER
	hidemonpic
	playfanfare MUS_OBTAIN_ITEM
	message PalletTown_ProfessorOaksLab_Text_ReceivedSquirtle
	waitfanfare
	setflag FLAG_OAK_STARTER_RECEIVED
	removeobject 4
	msgbox PalletTown_ProfessorOaksLab_Text_TakeCareOfSquirtle, MSGBOX_DEFAULT
	release
	end

PalletTown_ProfessorOaksLab_EventScript_BallNotYet::
	msgbox PalletTown_ProfessorOaksLab_Text_BallBelongsToOak, MSGBOX_DEFAULT
	release
	end

PalletTown_ProfessorOaksLab_EventScript_Aide::
	msgbox PalletTown_ProfessorOaksLab_Text_Aide, MSGBOX_NPC
	end

PalletTown_ProfessorOaksLab_Text_OakWelcome:
	.string "OAK: Ah, {PLAYER}!\n"
	.string "Welcome to PALLET TOWN!\p"
	.string "I hear you are conquering the\n"
	.string "Kanto Gym Circuit!\l"
	.string "Come visit me after you clear\l"
	.string "MT. MOON and PEWTER GYM!$"

PalletTown_ProfessorOaksLab_Text_OakOfferStarters:
	.string "OAK: Remarkable, {PLAYER}!\n"
	.string "You conquered MT. MOON and\l"
	.string "earned BROCK's BOULDER BADGE!\p"
	.string "To honor your achievements,\n"
	.string "I want you to have one of my\l"
	.string "prized Kanto Starters!\p"
	.string "Choose BULBASAUR, CHARMANDER,\n"
	.string "or SQUIRTLE from the table!$"

PalletTown_ProfessorOaksLab_Text_OakAfterChoice:
	.string "OAK: That POKéMON has great\n"
	.string "potential! Take good care of it\l"
	.string "as you challenge the south!$"

PalletTown_ProfessorOaksLab_Text_BallBelongsToOak:
	.string "It's a POKé BALL containing\n"
	.string "a rare Kanto POKéMON.\l"
	.string "It belongs to PROF. OAK.$"

PalletTown_ProfessorOaksLab_Text_ChooseBulbasaur:
	.string "It's the Grass-type POKéMON,\n"
	.string "BULBASAUR!\p"
	.string "Do you choose BULBASAUR?$"

PalletTown_ProfessorOaksLab_Text_ReceivedBulbasaur:
	.string "{PLAYER} received BULBASAUR\n"
	.string "from PROF. OAK!$"

PalletTown_ProfessorOaksLab_Text_TakeCareOfBulbasaur:
	.string "OAK: BULBASAUR is loyal and\n"
	.string "resilient. Treat it well!$"

PalletTown_ProfessorOaksLab_Text_ChooseCharmander:
	.string "It's the Fire-type POKéMON,\n"
	.string "CHARMANDER!\p"
	.string "Do you choose CHARMANDER?$"

PalletTown_ProfessorOaksLab_Text_ReceivedCharmander:
	.string "{PLAYER} received CHARMANDER\n"
	.string "from PROF. OAK!$"

PalletTown_ProfessorOaksLab_Text_TakeCareOfCharmander:
	.string "OAK: CHARMANDER's flame burns\n"
	.string "with courage! Treat it well!$"

PalletTown_ProfessorOaksLab_Text_ChooseSquirtle:
	.string "It's the Water-type POKéMON,\n"
	.string "SQUIRTLE!\p"
	.string "Do you choose SQUIRTLE?$"

PalletTown_ProfessorOaksLab_Text_ReceivedSquirtle:
	.string "{PLAYER} received SQUIRTLE\n"
	.string "from PROF. OAK!$"

PalletTown_ProfessorOaksLab_Text_TakeCareOfSquirtle:
	.string "OAK: SQUIRTLE has tremendous\n"
	.string "defensive power! Treat it well!$"

PalletTown_ProfessorOaksLab_Text_Aide:
	.string "I'm PROF. OAK's aide.\n"
	.string "He studies POKéMON ecology\l"
	.string "and evolutionary lines.$"
