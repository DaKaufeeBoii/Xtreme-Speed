Kanto_PalletTown_ProfessorOaksLab_MapScripts::
	.byte 0

Kanto_PalletTown_ProfessorOaksLab_EventScript_ProfOak::
	lock
	faceplayer
	goto_if_set FLAG_KANTO_RECEIVED_STARTER, Kanto_PalletTown_ProfessorOaksLab_EventScript_OakPost
	msgbox Kanto_PalletTown_ProfessorOaksLab_Text_OakWelcome, MSGBOX_DEFAULT
	release
	end

Kanto_PalletTown_ProfessorOaksLab_EventScript_BulbasaurBall::
	lock
	goto_if_set FLAG_KANTO_RECEIVED_STARTER, Kanto_PalletTown_ProfessorOaksLab_EventScript_AlreadyChosen
	msgbox Kanto_PalletTown_ProfessorOaksLab_Text_ChooseBulbasaur, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Kanto_PalletTown_ProfessorOaksLab_EventScript_GiveBulbasaur
	release
	end

Kanto_PalletTown_ProfessorOaksLab_EventScript_GiveBulbasaur::
	givemon SPECIES_BULBASAUR, 50, ITEM_MIRACLE_SEED
	playfanfare MUS_OBTAIN_ITEM
	message Kanto_PalletTown_ProfessorOaksLab_Text_ReceivedBulbasaur
	waitfanfare
	setflag FLAG_KANTO_RECEIVED_STARTER
	setflag FLAG_KANTO_HIDE_BULBASAUR_BALL
	removeobject VAR_LAST_TALKED
	msgbox Kanto_PalletTown_ProfessorOaksLab_Text_OakFarewell, MSGBOX_DEFAULT
	release
	end

Kanto_PalletTown_ProfessorOaksLab_EventScript_CharmanderBall::
	lock
	goto_if_set FLAG_KANTO_RECEIVED_STARTER, Kanto_PalletTown_ProfessorOaksLab_EventScript_AlreadyChosen
	msgbox Kanto_PalletTown_ProfessorOaksLab_Text_ChooseCharmander, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Kanto_PalletTown_ProfessorOaksLab_EventScript_GiveCharmander
	release
	end

Kanto_PalletTown_ProfessorOaksLab_EventScript_GiveCharmander::
	givemon SPECIES_CHARMANDER, 50, ITEM_CHARCOAL
	playfanfare MUS_OBTAIN_ITEM
	message Kanto_PalletTown_ProfessorOaksLab_Text_ReceivedCharmander
	waitfanfare
	setflag FLAG_KANTO_RECEIVED_STARTER
	setflag FLAG_KANTO_HIDE_CHARMANDER_BALL
	removeobject VAR_LAST_TALKED
	msgbox Kanto_PalletTown_ProfessorOaksLab_Text_OakFarewell, MSGBOX_DEFAULT
	release
	end

Kanto_PalletTown_ProfessorOaksLab_EventScript_SquirtleBall::
	lock
	goto_if_set FLAG_KANTO_RECEIVED_STARTER, Kanto_PalletTown_ProfessorOaksLab_EventScript_AlreadyChosen
	msgbox Kanto_PalletTown_ProfessorOaksLab_Text_ChooseSquirtle, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Kanto_PalletTown_ProfessorOaksLab_EventScript_GiveSquirtle
	release
	end

Kanto_PalletTown_ProfessorOaksLab_EventScript_GiveSquirtle::
	givemon SPECIES_SQUIRTLE, 50, ITEM_MYSTIC_WATER
	playfanfare MUS_OBTAIN_ITEM
	message Kanto_PalletTown_ProfessorOaksLab_Text_ReceivedSquirtle
	waitfanfare
	setflag FLAG_KANTO_RECEIVED_STARTER
	setflag FLAG_KANTO_HIDE_SQUIRTLE_BALL
	removeobject VAR_LAST_TALKED
	msgbox Kanto_PalletTown_ProfessorOaksLab_Text_OakFarewell, MSGBOX_DEFAULT
	release
	end

Kanto_PalletTown_ProfessorOaksLab_EventScript_AlreadyChosen::
	msgbox Kanto_PalletTown_ProfessorOaksLab_Text_AlreadyChosen, MSGBOX_DEFAULT
	release
	end

Kanto_PalletTown_ProfessorOaksLab_EventScript_OakPost::
	msgbox Kanto_PalletTown_ProfessorOaksLab_Text_OakPost, MSGBOX_DEFAULT
	release
	end

Kanto_PalletTown_ProfessorOaksLab_Text_OakWelcome:
	.string "OAK: Ah, {PLAYER}! Welcome to my\n"
	.string "laboratory in PALLET TOWN!\p"
	.string "Word of your victory in HOENN has\n"
	.string "spread throughout KANTO!\p"
	.string "Please inspect the balls on the desk\n"
	.string "and choose a KANTO partner!$"
Kanto_PalletTown_ProfessorOaksLab_Text_ChooseBulbasaur:
	.string "It contains the GRASS POKeMON\n"
	.string "BULBASAUR! Will you take it?$"
Kanto_PalletTown_ProfessorOaksLab_Text_ChooseCharmander:
	.string "It contains the FIRE POKeMON\n"
	.string "CHARMANDER! Will you take it?$"
Kanto_PalletTown_ProfessorOaksLab_Text_ChooseSquirtle:
	.string "It contains the WATER POKeMON\n"
	.string "SQUIRTLE! Will you take it?$"
Kanto_PalletTown_ProfessorOaksLab_Text_ReceivedBulbasaur:
	.string "{PLAYER} received BULBASAUR from\n"
	.string "PROFESSOR OAK!$"
Kanto_PalletTown_ProfessorOaksLab_Text_ReceivedCharmander:
	.string "{PLAYER} received CHARMANDER from\n"
	.string "PROFESSOR OAK!$"
Kanto_PalletTown_ProfessorOaksLab_Text_ReceivedSquirtle:
	.string "{PLAYER} received SQUIRTLE from\n"
	.string "PROFESSOR OAK!$"
Kanto_PalletTown_ProfessorOaksLab_Text_AlreadyChosen:
	.string "You have already chosen your\n"
	.string "companion from PROFESSOR OAK!$"
Kanto_PalletTown_ProfessorOaksLab_Text_OakFarewell:
	.string "OAK: Raise your new partner with\n"
	.string "love and care! Have a great journey!$"
Kanto_PalletTown_ProfessorOaksLab_Text_OakPost:
	.string "OAK: How is your KANTO adventure\n"
	.string "progressing? Keep aiming higher!$"
Kanto_PalletTown_ProfessorOaksLab_EventScript_Aide1::
	msgbox Kanto_PalletTown_ProfessorOaksLab_EventScript_Aide1_Text, MSGBOX_NPC
	end

Kanto_PalletTown_ProfessorOaksLab_EventScript_Aide1_Text:
		.string "Press START to open the MENU!$"
Kanto_PalletTown_ProfessorOaksLab_EventScript_Aide2::
	msgbox Kanto_PalletTown_ProfessorOaksLab_EventScript_Aide2_Text, MSGBOX_NPC
	end

Kanto_PalletTown_ProfessorOaksLab_EventScript_Aide2_Text:
		.string "Press START to open the MENU!$"
Kanto_PalletTown_ProfessorOaksLab_EventScript_Aide3::
	msgbox Kanto_PalletTown_ProfessorOaksLab_EventScript_Aide3_Text, MSGBOX_NPC
	end

Kanto_PalletTown_ProfessorOaksLab_EventScript_Aide3_Text:
		.string "Press START to open the MENU!$"
Kanto_PalletTown_ProfessorOaksLab_EventScript_Computer::
	msgbox Kanto_PalletTown_ProfessorOaksLab_EventScript_Computer_Text, MSGBOX_NPC
	end

Kanto_PalletTown_ProfessorOaksLab_EventScript_Computer_Text:
			.string "Press START to open the MENU!$"
Kanto_PalletTown_ProfessorOaksLab_EventScript_LeaveStarterSceneTrigger::
	end

Kanto_PalletTown_ProfessorOaksLab_EventScript_LeftSign::
	msgbox Kanto_PalletTown_ProfessorOaksLab_EventScript_LeftSign_Text, MSGBOX_SIGN
	end

Kanto_PalletTown_ProfessorOaksLab_EventScript_LeftSign_Text:
		.string "Press START to open the MENU!$"
Kanto_PalletTown_ProfessorOaksLab_EventScript_Pokedex::
	msgbox Kanto_PalletTown_ProfessorOaksLab_EventScript_Pokedex_Text, MSGBOX_NPC
	end

Kanto_PalletTown_ProfessorOaksLab_EventScript_Pokedex_Text:
			.string "Press START to open the MENU!$"
Kanto_PalletTown_ProfessorOaksLab_EventScript_RightSign::
	msgbox Kanto_PalletTown_ProfessorOaksLab_EventScript_RightSign_Text, MSGBOX_SIGN
	end

Kanto_PalletTown_ProfessorOaksLab_EventScript_RightSign_Text:
		.string "The SAVE option is on the MENU.\n"
	.string "Use it regularly.$"
Kanto_PalletTown_ProfessorOaksLab_EventScript_Rival::
	msgbox Kanto_PalletTown_ProfessorOaksLab_EventScript_Rival_Text, MSGBOX_NPC
	end

Kanto_PalletTown_ProfessorOaksLab_EventScript_Rival_Text:
		.string "{RIVAL}: My POKeMON looks a lot\n"
	.string "tougher than yours.$"
Kanto_PalletTown_ProfessorOaksLab_EventScript_RivalBattleTriggerLeft::
	end

Kanto_PalletTown_ProfessorOaksLab_EventScript_RivalBattleTriggerMid::
	end

Kanto_PalletTown_ProfessorOaksLab_EventScript_RivalBattleTriggerRight::
	end

