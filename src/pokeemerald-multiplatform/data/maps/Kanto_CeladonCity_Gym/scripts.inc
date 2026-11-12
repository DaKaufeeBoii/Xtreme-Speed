Kanto_CeladonCity_Gym_MapScripts::
	.byte 0

Kanto_CeladonCity_Gym_EventScript_Erika::
	lock
	faceplayer
	goto_if_set FLAG_BADGE_RAINBOW_GET, Kanto_CeladonCity_Gym_EventScript_LeaderDefeated
	cleartrainerflag TRAINER_KANTO_ERIKA
	msgbox Kanto_CeladonCity_Gym_Text_LeaderIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KANTO_ERIKA, Kanto_CeladonCity_Gym_Text_LeaderDefeat
	setflag FLAG_BADGE_RAINBOW_GET
	playfanfare MUS_OBTAIN_BADGE
	message Kanto_CeladonCity_Gym_Text_ReceivedBadge
	waitfanfare
	msgbox Kanto_CeladonCity_Gym_Text_LeaderPost, MSGBOX_DEFAULT
	release
	end

Kanto_CeladonCity_Gym_EventScript_LeaderDefeated::
	msgbox Kanto_CeladonCity_Gym_Text_LeaderPost, MSGBOX_DEFAULT
	release
	end

Kanto_CeladonCity_Gym_Text_LeaderIntro:
	.string "ERIKA: Hello... Lovely weather, isn't it?\p"
	.string "I am ERIKA, the LEADER of CELADON GYM.\p"
	.string "Allow me to share the quiet beauty of GRASS-type POKeMON with you.$"

Kanto_CeladonCity_Gym_Text_LeaderDefeat:
	.string "ERIKA: Oh my... You have completely swept away my defense.$"

Kanto_CeladonCity_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the\nRAINBOW BADGE from ERIKA!$"

Kanto_CeladonCity_Gym_Text_LeaderPost:
	.string "ERIKA: Please accept the RAINBOW BADGE. May your heart remain pure.$"

Kanto_CeladonCity_Gym_EventScript_Bridget::
	msgbox Kanto_CeladonCity_Gym_EventScript_Bridget_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_Gym_EventScript_Bridget_Text:
		.string "Oh, welcome.\n"
	.string "I was getting bored.$"
Kanto_CeladonCity_Gym_EventScript_GymStatue::
	msgbox Kanto_CeladonCity_Gym_EventScript_GymStatue_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_Gym_EventScript_GymStatue_Text:
			.string "CELADON POKeMON GYM\n"
	.string "LEADER: ERIKA\l"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}$"
Kanto_CeladonCity_Gym_EventScript_Kay::
	msgbox Kanto_CeladonCity_Gym_EventScript_Kay_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_Gym_EventScript_Kay_Text:
		.string "I should tell you about this GYM.\l"
	.string "Only real ladies are allowed in\n"
	.string "here!$"
Kanto_CeladonCity_Gym_EventScript_Lisa::
	msgbox Kanto_CeladonCity_Gym_EventScript_Lisa_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_Gym_EventScript_Lisa_Text:
		.string "Oh!\n"
	.string "You!$"
Kanto_CeladonCity_Gym_EventScript_Lori::
	msgbox Kanto_CeladonCity_Gym_EventScript_Lori_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_Gym_EventScript_Lori_Text:
		.string "Pleased to meet you.\n"
	.string "My hobby is POKeMON training.$"
Kanto_CeladonCity_Gym_EventScript_Mary::
	msgbox Kanto_CeladonCity_Gym_EventScript_Mary_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_Gym_EventScript_Mary_Text:
		.string "Oh!\n"
	.string "Beaten!$"
Kanto_CeladonCity_Gym_EventScript_Tamia::
	msgbox Kanto_CeladonCity_Gym_EventScript_Tamia_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_Gym_EventScript_Tamia_Text:
		.string "We only use GRASS-type POKeMON at\n"
	.string "our GYM.\l"
	.string "Why? We also use them for making\n"
	.string "flower arrangements!$"
Kanto_CeladonCity_Gym_EventScript_Tina::
	msgbox Kanto_CeladonCity_Gym_EventScript_Tina_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_Gym_EventScript_Tina_Text:
		.string "Oh, welcome.\n"
	.string "I was getting bored.$"
