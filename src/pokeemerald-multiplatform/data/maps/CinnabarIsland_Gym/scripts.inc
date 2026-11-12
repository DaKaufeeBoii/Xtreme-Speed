CinnabarIsland_Gym_MapScripts::
	.byte 0

CinnabarIsland_Gym_EventScript_Leader::
	lock
	faceplayer
	goto_if_set FLAG_BADGE_VOLCANO_GET, CinnabarIsland_Gym_EventScript_Defeated
	cleartrainerflag TRAINER_KANTO_BLAINE
	msgbox CinnabarIsland_Gym_Text_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KANTO_BLAINE, CinnabarIsland_Gym_Text_Defeat
	setflag FLAG_BADGE_VOLCANO_GET
	setflag FLAG_DEFEATED_KANTO_BLAINE
	playfanfare MUS_OBTAIN_BADGE
	message CinnabarIsland_Gym_Text_ReceivedBadge
	waitfanfare
	msgbox CinnabarIsland_Gym_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_Gym_EventScript_Defeated::
	msgbox CinnabarIsland_Gym_Text_RematchPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CinnabarIsland_Gym_EventScript_Rematch
	msgbox CinnabarIsland_Gym_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_Gym_EventScript_Rematch::
	cleartrainerflag TRAINER_KANTO_BLAINE
	msgbox CinnabarIsland_Gym_Text_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KANTO_BLAINE, CinnabarIsland_Gym_Text_Defeat
	msgbox CinnabarIsland_Gym_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_Gym_Text_Intro:
	.string "BLAINE: Hah! I am BLAINE!\n"
	.string "Red-hot quiz master of CINNABAR!\p"
	.string "My fiery POKéMON incinerate all\n"
	.string "challengers!\p"
	.string "Burn, baby, burn!$"

CinnabarIsland_Gym_Text_Defeat:
	.string "BLAINE: I have burned out!\n"
	.string "You have earned my respect!$"

CinnabarIsland_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the\n"
	.string "VOLCANO BADGE from BLAINE!$"

CinnabarIsland_Gym_Text_PostBattle:
	.string "BLAINE: Outstanding, {PLAYER}!\p"
	.string "With the VOLCANO BADGE, you've\n"
	.string "conquered seven Kanto Gyms!\p"
	.string "Word from the north says BLUE has\n"
	.string "returned to VIRIDIAN CITY to reopen\l"
	.string "the eighth Gym!\p"
	.string "Go challenge him at VIRIDIAN GYM!$"

CinnabarIsland_Gym_Text_RematchPrompt:
	.string "BLAINE: Welcome back, {PLAYER}!\n"
	.string "Would you like a rematch?$"
