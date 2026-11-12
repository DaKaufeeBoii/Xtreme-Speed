Kanto_VermilionCity_Gym_MapScripts::
	.byte 0

Kanto_VermilionCity_Gym_EventScript_LtSurge::
	lock
	faceplayer
	goto_if_set FLAG_BADGE_THUNDER_GET, Kanto_VermilionCity_Gym_EventScript_LeaderDefeated
	cleartrainerflag TRAINER_KANTO_SURGE
	msgbox Kanto_VermilionCity_Gym_Text_LeaderIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KANTO_SURGE, Kanto_VermilionCity_Gym_Text_LeaderDefeat
	setflag FLAG_BADGE_THUNDER_GET
	playfanfare MUS_OBTAIN_BADGE
	message Kanto_VermilionCity_Gym_Text_ReceivedBadge
	waitfanfare
	msgbox Kanto_VermilionCity_Gym_Text_LeaderPost, MSGBOX_DEFAULT
	release
	end

Kanto_VermilionCity_Gym_EventScript_LeaderDefeated::
	msgbox Kanto_VermilionCity_Gym_Text_LeaderPost, MSGBOX_DEFAULT
	release
	end

Kanto_VermilionCity_Gym_Text_LeaderIntro:
	.string "SURGE: Hey, kid! What do you think you're doing here?\p"
	.string "My electric POKeMON zapped my enemies in the war!\p"
	.string "Prepare for a shock!$"

Kanto_VermilionCity_Gym_Text_LeaderDefeat:
	.string "SURGE: Whoa! You're the real deal, kid! Shocking!$"

Kanto_VermilionCity_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the\nTHUNDER BADGE from LT. SURGE!$"

Kanto_VermilionCity_Gym_Text_LeaderPost:
	.string "LT. SURGE: Keep pushing forward! You are an exceptional TRAINER!$"

Kanto_VermilionCity_Gym_EventScript_Baily::
	msgbox Kanto_VermilionCity_Gym_EventScript_Baily_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_Gym_EventScript_Baily_Text:
		.string "Fried!$"
Kanto_VermilionCity_Gym_EventScript_Dwayne::
	msgbox Kanto_VermilionCity_Gym_EventScript_Dwayne_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_Gym_EventScript_Dwayne_Text:
		.string "Wow!\n"
	.string "Surprised me!$"
Kanto_VermilionCity_Gym_EventScript_GymGuy::
	msgbox Kanto_VermilionCity_Gym_EventScript_GymGuy_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_Gym_EventScript_GymGuy_Text:
		.string "Whew!\n"
	.string "That match was electric!$"
Kanto_VermilionCity_Gym_EventScript_GymStatue::
	msgbox Kanto_VermilionCity_Gym_EventScript_GymStatue_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_Gym_EventScript_GymStatue_Text:
			.string "VERMILION POKeMON GYM\n"
	.string "LEADER: LT. SURGE\l"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}$"
Kanto_VermilionCity_Gym_EventScript_TrashCan1::
	msgbox Kanto_VermilionCity_Gym_EventScript_TrashCan1_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_Gym_EventScript_TrashCan1_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_VermilionCity_Gym_EventScript_TrashCan10::
	msgbox Kanto_VermilionCity_Gym_EventScript_TrashCan10_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_Gym_EventScript_TrashCan10_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_VermilionCity_Gym_EventScript_TrashCan11::
	msgbox Kanto_VermilionCity_Gym_EventScript_TrashCan11_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_Gym_EventScript_TrashCan11_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_VermilionCity_Gym_EventScript_TrashCan12::
	msgbox Kanto_VermilionCity_Gym_EventScript_TrashCan12_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_Gym_EventScript_TrashCan12_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_VermilionCity_Gym_EventScript_TrashCan13::
	msgbox Kanto_VermilionCity_Gym_EventScript_TrashCan13_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_Gym_EventScript_TrashCan13_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_VermilionCity_Gym_EventScript_TrashCan14::
	msgbox Kanto_VermilionCity_Gym_EventScript_TrashCan14_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_Gym_EventScript_TrashCan14_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_VermilionCity_Gym_EventScript_TrashCan15::
	msgbox Kanto_VermilionCity_Gym_EventScript_TrashCan15_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_Gym_EventScript_TrashCan15_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_VermilionCity_Gym_EventScript_TrashCan2::
	msgbox Kanto_VermilionCity_Gym_EventScript_TrashCan2_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_Gym_EventScript_TrashCan2_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_VermilionCity_Gym_EventScript_TrashCan3::
	msgbox Kanto_VermilionCity_Gym_EventScript_TrashCan3_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_Gym_EventScript_TrashCan3_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_VermilionCity_Gym_EventScript_TrashCan4::
	msgbox Kanto_VermilionCity_Gym_EventScript_TrashCan4_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_Gym_EventScript_TrashCan4_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_VermilionCity_Gym_EventScript_TrashCan5::
	msgbox Kanto_VermilionCity_Gym_EventScript_TrashCan5_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_Gym_EventScript_TrashCan5_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_VermilionCity_Gym_EventScript_TrashCan6::
	msgbox Kanto_VermilionCity_Gym_EventScript_TrashCan6_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_Gym_EventScript_TrashCan6_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_VermilionCity_Gym_EventScript_TrashCan7::
	msgbox Kanto_VermilionCity_Gym_EventScript_TrashCan7_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_Gym_EventScript_TrashCan7_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_VermilionCity_Gym_EventScript_TrashCan8::
	msgbox Kanto_VermilionCity_Gym_EventScript_TrashCan8_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_Gym_EventScript_TrashCan8_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_VermilionCity_Gym_EventScript_TrashCan9::
	msgbox Kanto_VermilionCity_Gym_EventScript_TrashCan9_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_Gym_EventScript_TrashCan9_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_VermilionCity_Gym_EventScript_Tucker::
	msgbox Kanto_VermilionCity_Gym_EventScript_Tucker_Text, MSGBOX_NPC
	end

Kanto_VermilionCity_Gym_EventScript_Tucker_Text:
		.string "When I was in the Army, LT. SURGE\n"
	.string "was my strict CO.\l"
	.string "He was a hard taskmaster.$"
