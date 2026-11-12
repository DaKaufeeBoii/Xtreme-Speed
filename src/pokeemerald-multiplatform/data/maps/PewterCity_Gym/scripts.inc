PewterCity_Gym_MapScripts::
	.byte 0

PewterCity_Gym_EventScript_Leader::
	lock
	faceplayer
	goto_if_set FLAG_BADGE_BOULDER_GET, PewterCity_Gym_EventScript_Defeated
	cleartrainerflag TRAINER_KANTO_BROCK
	msgbox PewterCity_Gym_Text_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KANTO_BROCK, PewterCity_Gym_Text_Defeat
	setflag FLAG_BADGE_BOULDER_GET
	setflag FLAG_DEFEATED_KANTO_BROCK
	playfanfare MUS_OBTAIN_BADGE
	message PewterCity_Gym_Text_ReceivedBadge
	waitfanfare
	msgbox PewterCity_Gym_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_EventScript_Defeated::
	msgbox PewterCity_Gym_Text_RematchPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Gym_EventScript_Rematch
	msgbox PewterCity_Gym_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_EventScript_Rematch::
	cleartrainerflag TRAINER_KANTO_BROCK
	msgbox PewterCity_Gym_Text_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KANTO_BROCK, PewterCity_Gym_Text_Defeat
	msgbox PewterCity_Gym_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_Intro:
	.string "BROCK: I'm BROCK!\n"
	.string "I'm PEWTER's GYM LEADER!\p"
	.string "My rock-hard willpower is\n"
	.string "evident even in my POKéMON!\p"
	.string "Show me what you've got!$"

PewterCity_Gym_Text_Defeat:
	.string "BROCK: I took you for granted!\n"
	.string "Your power is real!$"

PewterCity_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the\n"
	.string "BOULDER BADGE from BROCK!$"

PewterCity_Gym_Text_PostBattle:
	.string "BROCK: Keep pushing forward!\n"
	.string "You are an exceptional TRAINER!$"

PewterCity_Gym_Text_RematchPrompt:
	.string "BROCK: Welcome back, {PLAYER}!\n"
	.string "Would you like a rematch?$"
