SaffronCity_SilphCo_5F_MapScripts::
	.byte 0

SaffronCity_SilphCo_5F_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_SAFFRON_LOCKDOWN_CLEARED, SaffronCity_SilphCo_5F_EventScript_WallyCleared
	msgbox SaffronCity_SilphCo_5F_Text_WallyBriefing, MSGBOX_DEFAULT
	closemessage
	applymovement 2, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SaffronCity_SilphCo_5F_Text_TabithaChallenge, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_TABITHA_SILPH_CO, SaffronCity_SilphCo_5F_Text_TabithaDefeat
	applymovement 3, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SaffronCity_SilphCo_5F_Text_PetrelChallenge, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PETREL_SILPH_CO, SaffronCity_SilphCo_5F_Text_PetrelDefeat
	msgbox SaffronCity_SilphCo_5F_Text_SyndicateRetreat, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_SAFFRON_LOCKDOWN_CLEARED
	removeobject 2
	removeobject 3
	fadescreen FADE_FROM_BLACK
	msgbox SaffronCity_SilphCo_5F_Text_WallyVictory, MSGBOX_DEFAULT
	release
	end

SaffronCity_SilphCo_5F_EventScript_Tabitha::
	goto SaffronCity_SilphCo_5F_EventScript_Wally
	end

SaffronCity_SilphCo_5F_EventScript_Petrel::
	goto SaffronCity_SilphCo_5F_EventScript_Wally
	end

SaffronCity_SilphCo_5F_EventScript_WallyCleared::
	msgbox SaffronCity_SilphCo_5F_Text_WallyCleared, MSGBOX_DEFAULT
	release
	end

SaffronCity_SilphCo_5F_EventScript_President::
	lock
	faceplayer
	goto_if_set FLAG_SAFFRON_LOCKDOWN_CLEARED, SaffronCity_SilphCo_5F_EventScript_PresidentSaved
	msgbox SaffronCity_SilphCo_5F_Text_PresidentScared, MSGBOX_DEFAULT
	release
	end

SaffronCity_SilphCo_5F_EventScript_PresidentSaved::
	msgbox SaffronCity_SilphCo_5F_Text_PresidentThanks, MSGBOX_DEFAULT
	release
	end

SaffronCity_SilphCo_5F_Text_WallyBriefing:
	.string "WALLY: {PLAYER}! You made it!\p"
	.string "Team Magma and Team Rocket\n"
	.string "formed the 'ECLIPSE SYNDICATE'!\p"
	.string "They seized Silph Co to steal\n"
	.string "experimental Devon tech!\l"
	.string "Let's take them down together!$"

SaffronCity_SilphCo_5F_Text_TabithaChallenge:
	.string "TABITHA: You again, {PLAYER}!\n"
	.string "Our syndicate will forge a new\l"
	.string "order across Kanto! Out of the way!$"

SaffronCity_SilphCo_5F_Text_TabithaDefeat:
	.string "TABITHA: Unbelievable!\n"
	.string "The Hoenn Champion's power...$"

SaffronCity_SilphCo_5F_Text_PetrelChallenge:
	.string "PETREL: Don't relax yet!\n"
	.string "Team Rocket Executive PETREL\l"
	.string "will finish you off!$"

SaffronCity_SilphCo_5F_Text_PetrelDefeat:
	.string "PETREL: Aaargh! How did we\n"
	.string "get outmaneuvered?!$"

SaffronCity_SilphCo_5F_Text_SyndicateRetreat:
	.string "PETREL: The operation is\n"
	.string "compromised! TABITHA, retreat!$"

SaffronCity_SilphCo_5F_Text_WallyVictory:
	.string "WALLY: We did it, {PLAYER}!\n"
	.string "Silph Co is safe, and Saffron\l"
	.string "City's lockdown is broken!\p"
	.string "SABRINA's Gym is open now!\n"
	.string "I'll see you on the circuit!$"

SaffronCity_SilphCo_5F_Text_WallyCleared:
	.string "WALLY: SABRINA's Psychic team\n"
	.string "is formidable! Good luck!$"

SaffronCity_SilphCo_5F_Text_PresidentScared:
	.string "PRESIDENT: Eek! The Syndicate\n"
	.string "invaded our headquarters!$"

SaffronCity_SilphCo_5F_Text_PresidentThanks:
	.string "PRESIDENT: Thank you for saving\n"
	.string "Silph Co, Champion {PLAYER}!\p"
	.string "Our technology is safe once\n"
	.string "again thanks to your bravery!$"
