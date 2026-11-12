CeladonCity_Gym_MapScripts::
	.byte 0

CeladonCity_Gym_EventScript_Leader::
	lock
	faceplayer
	goto_if_set FLAG_BADGE_RAINBOW_GET, CeladonCity_Gym_EventScript_Defeated
	cleartrainerflag TRAINER_KANTO_ERIKA
	msgbox CeladonCity_Gym_Text_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KANTO_ERIKA, CeladonCity_Gym_Text_Defeat
	setflag FLAG_BADGE_RAINBOW_GET
	setflag FLAG_DEFEATED_KANTO_ERIKA
	playfanfare MUS_OBTAIN_BADGE
	message CeladonCity_Gym_Text_ReceivedBadge
	waitfanfare
	msgbox CeladonCity_Gym_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

CeladonCity_Gym_EventScript_Defeated::
	msgbox CeladonCity_Gym_Text_RematchPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CeladonCity_Gym_EventScript_Rematch
	msgbox CeladonCity_Gym_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

CeladonCity_Gym_EventScript_Rematch::
	cleartrainerflag TRAINER_KANTO_ERIKA
	msgbox CeladonCity_Gym_Text_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KANTO_ERIKA, CeladonCity_Gym_Text_Defeat
	msgbox CeladonCity_Gym_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

CeladonCity_Gym_Text_Intro:
	.string "ERIKA: Hello... Lovely weather,\n"
	.string "isn't it? I am ERIKA.\p"
	.string "I am the LEADER of the\n"
	.string "CELADON GYM.\p"
	.string "My grass POKéMON are quite\n"
	.string "formidable! Shall we begin?$"

CeladonCity_Gym_Text_Defeat:
	.string "ERIKA: Oh! I concede defeat.\n"
	.string "You are remarkably strong.$"

CeladonCity_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the\n"
	.string "RAINBOW BADGE from ERIKA!$"

CeladonCity_Gym_Text_PostBattle:
	.string "ERIKA: Keep pushing forward!\n"
	.string "You are an exceptional TRAINER!$"

CeladonCity_Gym_Text_RematchPrompt:
	.string "ERIKA: Welcome back, {PLAYER}!\n"
	.string "Would you like a rematch?$"
