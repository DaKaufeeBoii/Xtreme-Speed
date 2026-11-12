Seafoam_Submarine_MapScripts::
	.byte 0

Seafoam_Submarine_EventScript_Rival::
	lock
	faceplayer
	goto_if_set FLAG_SEAFOAM_SUBMARINE_CLEARED, Seafoam_Submarine_EventScript_RivalCleared
	msgbox Seafoam_Submarine_Text_RivalBriefing, MSGBOX_DEFAULT
	closemessage
	applymovement 2, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Seafoam_Submarine_Text_ArchieChallenge, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHIE_SEAFOAM, Seafoam_Submarine_Text_ArchieDefeat
	applymovement 3, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Seafoam_Submarine_Text_MattChallenge, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MATT_SEAFOAM, Seafoam_Submarine_Text_MattDefeat
	msgbox Seafoam_Submarine_Text_ArchieSurrender, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_SEAFOAM_SUBMARINE_CLEARED
	removeobject 2
	removeobject 3
	fadescreen FADE_FROM_BLACK
	msgbox Seafoam_Submarine_Text_RivalVictory, MSGBOX_DEFAULT
	release
	end

Seafoam_Submarine_EventScript_Archie::
	goto Seafoam_Submarine_EventScript_Rival
	end

Seafoam_Submarine_EventScript_Matt::
	goto Seafoam_Submarine_EventScript_Rival
	end

Seafoam_Submarine_EventScript_RivalCleared::
	msgbox Seafoam_Submarine_Text_RivalCleared, MSGBOX_DEFAULT
	release
	end

Seafoam_Submarine_Text_RivalBriefing:
	.string "RIVAL: {PLAYER}! You found\n"
	.string "the Syndicate flagship!\p"
	.string "ARCHIE has commandeered this\n"
	.string "submarine to whip up torrential\l"
	.string "swells across Route 20!\p"
	.string "Let's stop them together!$"

Seafoam_Submarine_Text_ArchieChallenge:
	.string "ARCHIE: Hoenn Champion {PLAYER}!\n"
	.string "The ocean's roar cannot be\l"
	.string "silenced! Prepare to drown!$"

Seafoam_Submarine_Text_ArchieDefeat:
	.string "ARCHIE: Gahah! The power of your\n"
	.string "bonds is undeniable!$"

Seafoam_Submarine_Text_MattChallenge:
	.string "MATT: I won't let our vision\n"
	.string "sink into the abyss!$"

Seafoam_Submarine_Text_MattDefeat:
	.string "MATT: Argh! We couldn't hold\n"
	.string "the tide against you!$"

Seafoam_Submarine_Text_ArchieSurrender:
	.string "ARCHIE: Powering down engines...\n"
	.string "The sea has calmed, {PLAYER}.\l"
	.string "You are truly a Champion!$"

Seafoam_Submarine_Text_RivalVictory:
	.string "RIVAL: We did it, {PLAYER}!\n"
	.string "The sea route to CINNABAR\l"
	.string "ISLAND is now completely safe!$"

Seafoam_Submarine_Text_RivalCleared:
	.string "RIVAL: BLAINE is waiting in the\n"
	.string "CINNABAR volcanic caverns!$"
