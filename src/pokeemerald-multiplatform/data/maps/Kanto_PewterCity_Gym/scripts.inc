Kanto_PewterCity_Gym_MapScripts::
	.byte 0

Kanto_PewterCity_Gym_EventScript_Brock::
	lock
	faceplayer
	goto_if_set FLAG_BADGE_BOULDER_GET, Kanto_PewterCity_Gym_EventScript_LeaderDefeated
	cleartrainerflag TRAINER_KANTO_BROCK
	msgbox Kanto_PewterCity_Gym_Text_LeaderIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KANTO_BROCK, Kanto_PewterCity_Gym_Text_LeaderDefeat
	setflag FLAG_BADGE_BOULDER_GET
	playfanfare MUS_OBTAIN_BADGE
	message Kanto_PewterCity_Gym_Text_ReceivedBadge
	waitfanfare
	msgbox Kanto_PewterCity_Gym_Text_LeaderPost, MSGBOX_DEFAULT
	release
	end

Kanto_PewterCity_Gym_EventScript_LeaderDefeated::
	msgbox Kanto_PewterCity_Gym_Text_LeaderPost, MSGBOX_DEFAULT
	release
	end

Kanto_PewterCity_Gym_Text_LeaderIntro:
	.string "BROCK: I'm BROCK! The PEWTER GYM LEADER!\p"
	.string "My rock-hard willpower is poured into my POKeMON.\p"
	.string "Can you break through our ironclad defense?$"

Kanto_PewterCity_Gym_Text_LeaderDefeat:
	.string "BROCK: Impressive! You shattered our defense with ease.$"

Kanto_PewterCity_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the\nBOULDER BADGE from BROCK!$"

Kanto_PewterCity_Gym_Text_LeaderPost:
	.string "BROCK: Take the BOULDER BADGE! It symbolizes unbreakable determination.$"

Kanto_PewterCity_Gym_EventScript_GymGuy::
	msgbox Kanto_PewterCity_Gym_EventScript_GymGuy_Text, MSGBOX_NPC
	end

Kanto_PewterCity_Gym_EventScript_GymGuy_Text:
		.string "PEWTER POKeMON GYM\n"
	.string "LEADER: BROCK\l"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}$"
Kanto_PewterCity_Gym_EventScript_GymStatue::
	msgbox Kanto_PewterCity_Gym_EventScript_GymStatue_Text, MSGBOX_NPC
	end

Kanto_PewterCity_Gym_EventScript_GymStatue_Text:
			.string "PEWTER POKeMON GYM\n"
	.string "LEADER: BROCK\l"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}$"
Kanto_PewterCity_Gym_EventScript_Liam::
	msgbox Kanto_PewterCity_Gym_EventScript_Liam_Text, MSGBOX_NPC
	end

Kanto_PewterCity_Gym_EventScript_Liam_Text:
		.string "PEWTER POKeMON GYM\n"
	.string "LEADER: BROCK\l"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}$"
