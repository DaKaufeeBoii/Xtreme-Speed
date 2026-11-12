CeruleanCity_Gym_MapScripts::
	.byte 0

CeruleanCity_Gym_EventScript_Leader::
	lock
	faceplayer
	goto_if_set FLAG_BADGE_CASCADE_GET, CeruleanCity_Gym_EventScript_Defeated
	cleartrainerflag TRAINER_KANTO_MISTY
	msgbox CeruleanCity_Gym_Text_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KANTO_MISTY, CeruleanCity_Gym_Text_Defeat
	setflag FLAG_BADGE_CASCADE_GET
	setflag FLAG_DEFEATED_KANTO_MISTY
	playfanfare MUS_OBTAIN_BADGE
	message CeruleanCity_Gym_Text_ReceivedBadge
	waitfanfare
	msgbox CeruleanCity_Gym_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_EventScript_Defeated::
	msgbox CeruleanCity_Gym_Text_RematchPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CeruleanCity_Gym_EventScript_Rematch
	msgbox CeruleanCity_Gym_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_EventScript_Rematch::
	cleartrainerflag TRAINER_KANTO_MISTY
	msgbox CeruleanCity_Gym_Text_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KANTO_MISTY, CeruleanCity_Gym_Text_Defeat
	msgbox CeruleanCity_Gym_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_Text_Intro:
	.string "MISTY: Hi, you're a new face!\p"
	.string "Only trainers who can swim with\n"
	.string "water POKéMON can win here!\p"
	.string "Are you ready? Let's go!$"

CeruleanCity_Gym_Text_Defeat:
	.string "MISTY: Wow! You really are\n"
	.string "something special!$"

CeruleanCity_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the\n"
	.string "CASCADE BADGE from MISTY!$"

CeruleanCity_Gym_Text_PostBattle:
	.string "MISTY: Keep pushing forward!\n"
	.string "You are an exceptional TRAINER!$"

CeruleanCity_Gym_Text_RematchPrompt:
	.string "MISTY: Welcome back, {PLAYER}!\n"
	.string "Would you like a rematch?$"
