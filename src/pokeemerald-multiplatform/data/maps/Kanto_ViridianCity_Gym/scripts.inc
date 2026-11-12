Kanto_ViridianCity_Gym_MapScripts::
	.byte 0

Kanto_ViridianCity_Gym_EventScript_Giovanni::
	lock
	faceplayer
	goto_if_set FLAG_BADGE_EARTH_GET, Kanto_ViridianCity_Gym_EventScript_LeaderDefeated
	cleartrainerflag TRAINER_BLUE
	msgbox Kanto_ViridianCity_Gym_Text_LeaderIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLUE, Kanto_ViridianCity_Gym_Text_LeaderDefeat
	setflag FLAG_BADGE_EARTH_GET
	playfanfare MUS_OBTAIN_BADGE
	message Kanto_ViridianCity_Gym_Text_ReceivedBadge
	waitfanfare
	msgbox Kanto_ViridianCity_Gym_Text_LeaderPost, MSGBOX_DEFAULT
	release
	end

Kanto_ViridianCity_Gym_EventScript_LeaderDefeated::
	msgbox Kanto_ViridianCity_Gym_Text_LeaderPost, MSGBOX_DEFAULT
	release
	end

Kanto_ViridianCity_Gym_Text_LeaderIntro:
	.string "BLUE: Yo! {PLAYER}! So you finally made it all the way to VIRIDIAN!\p"
	.string "I took over this GYM after GIOVANNI fled.\p"
	.string "I don't specialize in a single type--I use whatever brings ultimate victory!\p"
	.string "Let's see what the HOENN CHAMPION is truly made of!$"

Kanto_ViridianCity_Gym_Text_LeaderDefeat:
	.string "BLUE: Unbelievable! You really are the greatest trainer in HOENN!$"

Kanto_ViridianCity_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the\nEARTH BADGE from BLUE!$"

Kanto_ViridianCity_Gym_Text_LeaderPost:
	.string "BLUE: Take the EARTH BADGE! With all 8 KANTO BADGES, the path to the INDIGO SUMMIT is open to you!$"

Kanto_ViridianCity_Gym_EventScript_Atsushi::
	msgbox Kanto_ViridianCity_Gym_EventScript_Atsushi_Text, MSGBOX_NPC
	end

Kanto_ViridianCity_Gym_EventScript_Atsushi_Text:
		.string "Wargh!$"
Kanto_ViridianCity_Gym_EventScript_Cole::
	msgbox Kanto_ViridianCity_Gym_EventScript_Cole_Text, MSGBOX_NPC
	end

Kanto_ViridianCity_Gym_EventScript_Cole_Text:
		.string "Your POKeMON will cower at the\n"
	.string "crack of my whip!$"
Kanto_ViridianCity_Gym_EventScript_GymGuy::
	msgbox Kanto_ViridianCity_Gym_EventScript_GymGuy_Text, MSGBOX_NPC
	end

Kanto_ViridianCity_Gym_EventScript_GymGuy_Text:
		.string "Blow me away! GIOVANNI was the\n"
	.string "GYM LEADER of VIRIDIAN?$"
Kanto_ViridianCity_Gym_EventScript_GymStatue::
	msgbox Kanto_ViridianCity_Gym_EventScript_GymStatue_Text, MSGBOX_NPC
	end

Kanto_ViridianCity_Gym_EventScript_GymStatue_Text:
			.string "VIRIDIAN POKeMON GYM\n"
	.string "LEADER: ?\l"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}$"
Kanto_ViridianCity_Gym_EventScript_Jason::
	msgbox Kanto_ViridianCity_Gym_EventScript_Jason_Text, MSGBOX_NPC
	end

Kanto_ViridianCity_Gym_EventScript_Jason_Text:
		.string "POKeMON and I, we make wonderful\n"
	.string "music together!$"
Kanto_ViridianCity_Gym_EventScript_Kiyo::
	msgbox Kanto_ViridianCity_Gym_EventScript_Kiyo_Text, MSGBOX_NPC
	end

Kanto_ViridianCity_Gym_EventScript_Kiyo_Text:
		.string "Karate is the ultimate form of\n"
	.string "martial arts!$"
Kanto_ViridianCity_Gym_EventScript_Samuel::
	msgbox Kanto_ViridianCity_Gym_EventScript_Samuel_Text, MSGBOX_NPC
	end

Kanto_ViridianCity_Gym_EventScript_Samuel_Text:
		.string "VIRIDIAN GYM was closed for a\n"
	.string "long time.\l"
	.string "But now, our LEADER is back!$"
Kanto_ViridianCity_Gym_EventScript_Takashi::
	msgbox Kanto_ViridianCity_Gym_EventScript_Takashi_Text, MSGBOX_NPC
	end

Kanto_ViridianCity_Gym_EventScript_Takashi_Text:
		.string "Ayah!$"
Kanto_ViridianCity_Gym_EventScript_Warren::
	msgbox Kanto_ViridianCity_Gym_EventScript_Warren_Text, MSGBOX_NPC
	end

Kanto_ViridianCity_Gym_EventScript_Warren_Text:
		.string "The truly talented win with style.$"
Kanto_ViridianCity_Gym_EventScript_Yuji::
	msgbox Kanto_ViridianCity_Gym_EventScript_Yuji_Text, MSGBOX_NPC
	end

Kanto_ViridianCity_Gym_EventScript_Yuji_Text:
		.string "Heh!\n"
	.string "You must be running out of steam\p"
	.string "by now!$"
