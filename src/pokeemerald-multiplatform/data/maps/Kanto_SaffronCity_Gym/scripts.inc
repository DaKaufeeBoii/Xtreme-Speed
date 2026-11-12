Kanto_SaffronCity_Gym_MapScripts::
	.byte 0

Kanto_SaffronCity_Gym_EventScript_Sabrina::
	lock
	faceplayer
	goto_if_set FLAG_BADGE_MARSH_GET, Kanto_SaffronCity_Gym_EventScript_LeaderDefeated
	cleartrainerflag TRAINER_KANTO_SABRINA
	msgbox Kanto_SaffronCity_Gym_Text_LeaderIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KANTO_SABRINA, Kanto_SaffronCity_Gym_Text_LeaderDefeat
	setflag FLAG_BADGE_MARSH_GET
	playfanfare MUS_OBTAIN_BADGE
	message Kanto_SaffronCity_Gym_Text_ReceivedBadge
	waitfanfare
	msgbox Kanto_SaffronCity_Gym_Text_LeaderPost, MSGBOX_DEFAULT
	release
	end

Kanto_SaffronCity_Gym_EventScript_LeaderDefeated::
	msgbox Kanto_SaffronCity_Gym_Text_LeaderPost, MSGBOX_DEFAULT
	release
	end

Kanto_SaffronCity_Gym_Text_LeaderIntro:
	.string "SABRINA: I had a vision of your arrival from HOENN.\p"
	.string "My psychic powers transcend time and space.\p"
	.string "Let us see if your bond with your POKeMON can overcome telekinesis!$"

Kanto_SaffronCity_Gym_Text_LeaderDefeat:
	.string "SABRINA: Your spirit... It shines brighter than I foresaw.$"

Kanto_SaffronCity_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the\nMARSH BADGE from SABRINA!$"

Kanto_SaffronCity_Gym_Text_LeaderPost:
	.string "SABRINA: The MARSH BADGE is yours. A formidable destiny awaits you.$"

Kanto_SaffronCity_Gym_EventScript_Amanda::
	msgbox Kanto_SaffronCity_Gym_EventScript_Amanda_Text, MSGBOX_NPC
	end

Kanto_SaffronCity_Gym_EventScript_Amanda_Text:
		.string "SABRINA is far younger than I,\n"
	.string "but she has earned my respect.$"
Kanto_SaffronCity_Gym_EventScript_Cameron::
	msgbox Kanto_SaffronCity_Gym_EventScript_Cameron_Text, MSGBOX_NPC
	end

Kanto_SaffronCity_Gym_EventScript_Cameron_Text:
		.string "Ow!\n"
	.string "Down and out!$"
Kanto_SaffronCity_Gym_EventScript_GymGuy::
	msgbox Kanto_SaffronCity_Gym_EventScript_GymGuy_Text, MSGBOX_NPC
	end

Kanto_SaffronCity_Gym_EventScript_GymGuy_Text:
		.string "SAFFRON POKeMON GYM\n"
	.string "LEADER: SABRINA\l"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}$"
Kanto_SaffronCity_Gym_EventScript_GymStatue::
	msgbox Kanto_SaffronCity_Gym_EventScript_GymStatue_Text, MSGBOX_NPC
	end

Kanto_SaffronCity_Gym_EventScript_GymStatue_Text:
			.string "SAFFRON POKeMON GYM\n"
	.string "LEADER: SABRINA\l"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}$"
Kanto_SaffronCity_Gym_EventScript_Johan::
	msgbox Kanto_SaffronCity_Gym_EventScript_Johan_Text, MSGBOX_NPC
	end

Kanto_SaffronCity_Gym_EventScript_Johan_Text:
		.string "Does our unseen power scare you?$"
Kanto_SaffronCity_Gym_EventScript_Preston::
	msgbox Kanto_SaffronCity_Gym_EventScript_Preston_Text, MSGBOX_NPC
	end

Kanto_SaffronCity_Gym_EventScript_Preston_Text:
		.string "Arrrgh!$"
Kanto_SaffronCity_Gym_EventScript_Stacy::
	msgbox Kanto_SaffronCity_Gym_EventScript_Stacy_Text, MSGBOX_NPC
	end

Kanto_SaffronCity_Gym_EventScript_Stacy_Text:
		.string "POKeMON take on the appearance of\n"
	.string "their TRAINERS.\l"
	.string "Your POKeMON must be tough, then!$"
Kanto_SaffronCity_Gym_EventScript_Tasha::
	msgbox Kanto_SaffronCity_Gym_EventScript_Tasha_Text, MSGBOX_NPC
	end

Kanto_SaffronCity_Gym_EventScript_Tasha_Text:
		.string "You and I, our POKeMON shall\n"
	.string "battle!$"
Kanto_SaffronCity_Gym_EventScript_Tyron::
	msgbox Kanto_SaffronCity_Gym_EventScript_Tyron_Text, MSGBOX_NPC
	end

Kanto_SaffronCity_Gym_EventScript_Tyron_Text:
		.string "SABRINA just wiped out the KARATE\n"
	.string "MASTER next door.$"
