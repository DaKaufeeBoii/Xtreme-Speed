ViridianCity_Gym_MapScripts::
	.byte 0

ViridianCity_Gym_EventScript_GymGuide::
	msgbox ViridianCity_Gym_Text_GymGuide, MSGBOX_NPC
	end

ViridianCity_Gym_EventScript_LeftGymStatue::
	msgbox ViridianCity_Gym_Text_GymStatue, MSGBOX_SIGN
	end

ViridianCity_Gym_EventScript_RightGymStatue::
	msgbox ViridianCity_Gym_Text_GymStatue, MSGBOX_SIGN
	end

ViridianCity_Gym_Text_GymGuide:
	.string "GUIDE: Yo! Champ in making!\p"
	.string "This is the VIRIDIAN GYM!\n"
	.string "Leader BLUE uses a formidable\n"
	.string "all-around championship team!\p"
	.string "Good luck!$"

ViridianCity_Gym_Text_GymStatue:
	.string "VIRIDIAN CITY POKéMON GYM\n"
	.string "LEADER: BLUE\n"
	.string "CERTIFIED TRAINERS:\n"
	.string "RED, {PLAYER}$"
