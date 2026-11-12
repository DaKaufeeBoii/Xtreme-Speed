SaffronCity_Gym_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_Leader::
	lock
	faceplayer
	goto_if_set FLAG_BADGE_MARSH_GET, SaffronCity_Gym_EventScript_Defeated
	cleartrainerflag TRAINER_KANTO_SABRINA
	msgbox SaffronCity_Gym_Text_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KANTO_SABRINA, SaffronCity_Gym_Text_Defeat
	setflag FLAG_BADGE_MARSH_GET
	setflag FLAG_DEFEATED_KANTO_SABRINA
	playfanfare MUS_OBTAIN_BADGE
	message SaffronCity_Gym_Text_ReceivedBadge
	waitfanfare
	msgbox SaffronCity_Gym_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

SaffronCity_Gym_EventScript_Defeated::
	msgbox SaffronCity_Gym_Text_RematchPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SaffronCity_Gym_EventScript_Rematch
	msgbox SaffronCity_Gym_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

SaffronCity_Gym_EventScript_Rematch::
	cleartrainerflag TRAINER_KANTO_SABRINA
	msgbox SaffronCity_Gym_Text_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KANTO_SABRINA, SaffronCity_Gym_Text_Defeat
	msgbox SaffronCity_Gym_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

SaffronCity_Gym_Text_Intro:
	.string "SABRINA: I had a psychic vision\n"
	.string "of your arrival.\p"
	.string "I do not like conflict, but my\n"
	.string "powers cannot be denied.\p"
	.string "Witness true psychic mastery!$"

SaffronCity_Gym_Text_Defeat:
	.string "SABRINA: I'm shocked!\n"
	.string "Your psychic bond is immense!$"

SaffronCity_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the\n"
	.string "MARSH BADGE from SABRINA!$"

SaffronCity_Gym_Text_PostBattle:
	.string "SABRINA: Keep pushing forward!\n"
	.string "You are an exceptional TRAINER!$"

SaffronCity_Gym_Text_RematchPrompt:
	.string "SABRINA: Welcome back, {PLAYER}!\n"
	.string "Would you like a rematch?$"
