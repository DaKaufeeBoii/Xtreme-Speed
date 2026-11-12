Kanto_CinnabarIsland_Gym_MapScripts::
	.byte 0

Kanto_CinnabarIsland_Gym_EventScript_Blaine::
	lock
	faceplayer
	goto_if_set FLAG_BADGE_VOLCANO_GET, Kanto_CinnabarIsland_Gym_EventScript_LeaderDefeated
	cleartrainerflag TRAINER_KANTO_BLAINE
	msgbox Kanto_CinnabarIsland_Gym_Text_LeaderIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KANTO_BLAINE, Kanto_CinnabarIsland_Gym_Text_LeaderDefeat
	setflag FLAG_BADGE_VOLCANO_GET
	playfanfare MUS_OBTAIN_BADGE
	message Kanto_CinnabarIsland_Gym_Text_ReceivedBadge
	waitfanfare
	msgbox Kanto_CinnabarIsland_Gym_Text_LeaderPost, MSGBOX_DEFAULT
	release
	end

Kanto_CinnabarIsland_Gym_EventScript_LeaderDefeated::
	msgbox Kanto_CinnabarIsland_Gym_Text_LeaderPost, MSGBOX_DEFAULT
	release
	end

Kanto_CinnabarIsland_Gym_Text_LeaderIntro:
	.string "BLAINE: Hah! I am BLAINE, the fiery quiz master!\p"
	.string "My fiery POKeMON incinerate all who lack resolve!\p"
	.string "You'd better have BURN HEAL ready!$"

Kanto_CinnabarIsland_Gym_Text_LeaderDefeat:
	.string "BLAINE: Burnt out! My flames were extinguished!$"

Kanto_CinnabarIsland_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the\nVOLCANO BADGE from BLAINE!$"

Kanto_CinnabarIsland_Gym_Text_LeaderPost:
	.string "BLAINE: You have proven your fiery passion! Take the VOLCANO BADGE!$"

Kanto_CinnabarIsland_Gym_EventScript_Avery::
	msgbox Kanto_CinnabarIsland_Gym_EventScript_Avery_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Gym_EventScript_Avery_Text:
		.string "Waah!\n"
	.string "My studies were insufficient!$"
Kanto_CinnabarIsland_Gym_EventScript_BlaineFujiPhoto::
	msgbox Kanto_CinnabarIsland_Gym_EventScript_BlaineFujiPhoto_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Gym_EventScript_BlaineFujiPhoto_Text:
		.string "POKeMON JOURNAL\l"
	.string "Special Feature: CINNABAR GYM\n"
	.string "LEADER BLAINE!\l"
	.string "BLAINE is said to remove his dark\n"
	.string "shades only when he is thinking up\p"
	.string "new quiz questions.$"
Kanto_CinnabarIsland_Gym_EventScript_Derek::
	msgbox Kanto_CinnabarIsland_Gym_EventScript_Derek_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Gym_EventScript_Derek_Text:
		.string "I know why BLAINE became a\n"
	.string "TRAINER.$"
Kanto_CinnabarIsland_Gym_EventScript_Dusty::
	msgbox Kanto_CinnabarIsland_Gym_EventScript_Dusty_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Gym_EventScript_Dusty_Text:
		.string "Yowza!\n"
	.string "Too hot!$"
Kanto_CinnabarIsland_Gym_EventScript_Erik::
	msgbox Kanto_CinnabarIsland_Gym_EventScript_Erik_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Gym_EventScript_Erik_Text:
		.string "Do you know how hot POKeMON fire\n"
	.string "breath can get?$"
Kanto_CinnabarIsland_Gym_EventScript_GymGuy::
	msgbox Kanto_CinnabarIsland_Gym_EventScript_GymGuy_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Gym_EventScript_GymGuy_Text:
		.string "{PLAYER}!\n"
	.string "You beat that firebrand!$"
Kanto_CinnabarIsland_Gym_EventScript_GymStatue::
	msgbox Kanto_CinnabarIsland_Gym_EventScript_GymStatue_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Gym_EventScript_GymStatue_Text:
			.string "CINNABAR POKeMON GYM\n"
	.string "LEADER: BLAINE\l"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}$"
Kanto_CinnabarIsland_Gym_EventScript_Quinn::
	msgbox Kanto_CinnabarIsland_Gym_EventScript_Quinn_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Gym_EventScript_Quinn_Text:
		.string "I was a thief, but I went straight\n"
	.string "as a TRAINER.$"
Kanto_CinnabarIsland_Gym_EventScript_Quiz1Left::
	msgbox Kanto_CinnabarIsland_Gym_EventScript_Quiz1Left_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Gym_EventScript_Quiz1Left_Text:
		.string "CATERPIE evolves into METAPOD?$"
Kanto_CinnabarIsland_Gym_EventScript_Quiz1Right::
	msgbox Kanto_CinnabarIsland_Gym_EventScript_Quiz1Right_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Gym_EventScript_Quiz1Right_Text:
		.string "CATERPIE evolves into METAPOD?$"
Kanto_CinnabarIsland_Gym_EventScript_Quiz2Left::
	msgbox Kanto_CinnabarIsland_Gym_EventScript_Quiz2Left_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Gym_EventScript_Quiz2Left_Text:
		.string "There are nine certified POKeMON\n"
	.string "LEAGUE BADGES?$"
Kanto_CinnabarIsland_Gym_EventScript_Quiz2Right::
	msgbox Kanto_CinnabarIsland_Gym_EventScript_Quiz2Right_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Gym_EventScript_Quiz2Right_Text:
		.string "There are nine certified POKeMON\n"
	.string "LEAGUE BADGES?$"
Kanto_CinnabarIsland_Gym_EventScript_Quiz3Left::
	msgbox Kanto_CinnabarIsland_Gym_EventScript_Quiz3Left_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Gym_EventScript_Quiz3Left_Text:
		.string "POLIWAG evolves three times?$"
Kanto_CinnabarIsland_Gym_EventScript_Quiz3Right::
	msgbox Kanto_CinnabarIsland_Gym_EventScript_Quiz3Right_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Gym_EventScript_Quiz3Right_Text:
		.string "POLIWAG evolves three times?$"
Kanto_CinnabarIsland_Gym_EventScript_Quiz4Left::
	msgbox Kanto_CinnabarIsland_Gym_EventScript_Quiz4Left_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Gym_EventScript_Quiz4Left_Text:
		.string "Are electric moves effective\n"
	.string "against GROUND-type POKeMON?$"
Kanto_CinnabarIsland_Gym_EventScript_Quiz4Right::
	msgbox Kanto_CinnabarIsland_Gym_EventScript_Quiz4Right_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Gym_EventScript_Quiz4Right_Text:
		.string "Are electric moves effective\n"
	.string "against GROUND-type POKeMON?$"
Kanto_CinnabarIsland_Gym_EventScript_Quiz5Left::
	msgbox Kanto_CinnabarIsland_Gym_EventScript_Quiz5Left_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Gym_EventScript_Quiz5Left_Text:
		.string "POKeMON of the same kind and level\n"
	.string "are not identical?$"
Kanto_CinnabarIsland_Gym_EventScript_Quiz5Right::
	msgbox Kanto_CinnabarIsland_Gym_EventScript_Quiz5Right_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Gym_EventScript_Quiz5Right_Text:
		.string "POKeMON of the same kind and level\n"
	.string "are not identical?$"
Kanto_CinnabarIsland_Gym_EventScript_Quiz6Left::
	msgbox Kanto_CinnabarIsland_Gym_EventScript_Quiz6Left_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Gym_EventScript_Quiz6Left_Text:
		.string "TM28 contains TOMBSTONY?$"
Kanto_CinnabarIsland_Gym_EventScript_Quiz6Right::
	msgbox Kanto_CinnabarIsland_Gym_EventScript_Quiz6Right_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Gym_EventScript_Quiz6Right_Text:
		.string "TM28 contains TOMBSTONY?$"
Kanto_CinnabarIsland_Gym_EventScript_Ramon::
	msgbox Kanto_CinnabarIsland_Gym_EventScript_Ramon_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Gym_EventScript_Ramon_Text:
		.string "I like using FIRE-type POKeMON.\n"
	.string "I just do.$"
Kanto_CinnabarIsland_Gym_EventScript_Zac::
	msgbox Kanto_CinnabarIsland_Gym_EventScript_Zac_Text, MSGBOX_NPC
	end

Kanto_CinnabarIsland_Gym_EventScript_Zac_Text:
		.string "Fire is weak against H2O.$"
