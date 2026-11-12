CeladonCity_GameCorner_Hideout_MapScripts::
	.byte 0

CeladonCity_GameCorner_Hideout_EventScript_Matt::
	lock
	faceplayer
	msgbox CeladonCity_GameCorner_Hideout_Text_MattChallenge, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MATT_CELADON, CeladonCity_GameCorner_Hideout_Text_MattDefeat
	applymovement 2, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox CeladonCity_GameCorner_Hideout_Text_ProtonChallenge, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PROTON_CELADON, CeladonCity_GameCorner_Hideout_Text_ProtonDefeat
	msgbox CeladonCity_GameCorner_Hideout_Text_SyndicateRetreat, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_CELADON_RESERVOIR_CLEARED
	removeobject 1
	removeobject 2
	fadescreen FADE_FROM_BLACK
	msgbox CeladonCity_GameCorner_Hideout_Text_ReservoirRestored, MSGBOX_DEFAULT
	release
	end

CeladonCity_GameCorner_Hideout_EventScript_Proton::
	goto CeladonCity_GameCorner_Hideout_EventScript_Matt
	end

CeladonCity_GameCorner_Hideout_Text_MattChallenge:
	.string "MATT: Bwahaha! TEAM AQUA and\n"
	.string "TEAM ROCKET are siphoning\l"
	.string "the underground reservoirs!\p"
	.string "We'll flood CELADON and turn it\n"
	.string "into our coastal stronghold!$"

CeladonCity_GameCorner_Hideout_Text_MattDefeat:
	.string "MATT: Gaaah! You crushed my\n"
	.string "hydro assault!$"

CeladonCity_GameCorner_Hideout_Text_ProtonChallenge:
	.string "PROTON: Step aside, MATT!\n"
	.string "I am PROTON, the cruelty master\l"
	.string "of the ECLIPSE SYNDICATE!\l"
	.string "Prepare for obliteration!$"

CeladonCity_GameCorner_Hideout_Text_ProtonDefeat:
	.string "PROTON: This power... Is this\n"
	.string "the Hoenn Champion's strength?!$"

CeladonCity_GameCorner_Hideout_Text_SyndicateRetreat:
	.string "PROTON: The reservoir valves\n"
	.string "are locking down! Fall back!$"

CeladonCity_GameCorner_Hideout_Text_ReservoirRestored:
	.string "The reservoir valves have\n"
	.string "returned to normal operation!\p"
	.string "CELADON CITY is secure!\n"
	.string "ERIKA's Gym is now open!$"
