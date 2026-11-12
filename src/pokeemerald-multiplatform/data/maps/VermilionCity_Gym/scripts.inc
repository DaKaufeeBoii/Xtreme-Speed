VermilionCity_Gym_MapScripts::
	.byte 0

VermilionCity_Gym_EventScript_Leader::
	lock
	faceplayer
	goto_if_set FLAG_BADGE_THUNDER_GET, VermilionCity_Gym_EventScript_Defeated
	cleartrainerflag TRAINER_KANTO_SURGE
	msgbox VermilionCity_Gym_Text_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KANTO_SURGE, VermilionCity_Gym_Text_Defeat
	setflag FLAG_BADGE_THUNDER_GET
	setflag FLAG_DEFEATED_KANTO_SURGE
	playfanfare MUS_OBTAIN_BADGE
	message VermilionCity_Gym_Text_ReceivedBadge
	waitfanfare
	msgbox VermilionCity_Gym_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

VermilionCity_Gym_EventScript_Defeated::
	msgbox VermilionCity_Gym_Text_RematchPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VermilionCity_Gym_EventScript_Rematch
	msgbox VermilionCity_Gym_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

VermilionCity_Gym_EventScript_Rematch::
	cleartrainerflag TRAINER_KANTO_SURGE
	msgbox VermilionCity_Gym_Text_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KANTO_SURGE, VermilionCity_Gym_Text_Defeat
	msgbox VermilionCity_Gym_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

VermilionCity_Gym_Text_Intro:
	.string "SURGE: Hey, kid! What do you\n"
	.string "think you're doing here?\p"
	.string "My electric POKéMON zapped my\n"
	.string "enemies in the war!\p"
	.string "Prepare for a shock!$"

VermilionCity_Gym_Text_Defeat:
	.string "SURGE: Whoa! You're the real\n"
	.string "deal, kid! Shocking!$"

VermilionCity_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the\n"
	.string "THUNDER BADGE from LT. SURGE!$"

VermilionCity_Gym_Text_PostBattle:
	.string "LT. SURGE: Keep pushing forward!\n"
	.string "You are an exceptional TRAINER!$"

VermilionCity_Gym_Text_RematchPrompt:
	.string "LT. SURGE: Welcome back, {PLAYER}!\n"
	.string "Would you like a rematch?$"
