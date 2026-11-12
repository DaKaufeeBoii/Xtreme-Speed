Kanto_CeruleanCity_Gym_MapScripts::
	.byte 0

Kanto_CeruleanCity_Gym_EventScript_Misty::
	lock
	faceplayer
	goto_if_set FLAG_BADGE_CASCADE_GET, Kanto_CeruleanCity_Gym_EventScript_LeaderDefeated
	cleartrainerflag TRAINER_KANTO_MISTY
	msgbox Kanto_CeruleanCity_Gym_Text_LeaderIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KANTO_MISTY, Kanto_CeruleanCity_Gym_Text_LeaderDefeat
	setflag FLAG_BADGE_CASCADE_GET
	playfanfare MUS_OBTAIN_BADGE
	message Kanto_CeruleanCity_Gym_Text_ReceivedBadge
	waitfanfare
	msgbox Kanto_CeruleanCity_Gym_Text_LeaderPost, MSGBOX_DEFAULT
	release
	end

Kanto_CeruleanCity_Gym_EventScript_LeaderDefeated::
	msgbox Kanto_CeruleanCity_Gym_Text_LeaderPost, MSGBOX_DEFAULT
	release
	end

Kanto_CeruleanCity_Gym_Text_LeaderIntro:
	.string "MISTY: Hi! I'm MISTY, the all-out offensive WATER trainer!\p"
	.string "Don't think you can breeze through just because you conquered HOENN!\p"
	.string "My WATER POKeMON are relentless!$"

Kanto_CeruleanCity_Gym_Text_LeaderDefeat:
	.string "MISTY: You really are tough! What an exhilarating match!$"

Kanto_CeruleanCity_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the\nCASCADE BADGE from MISTY!$"

Kanto_CeruleanCity_Gym_Text_LeaderPost:
	.string "MISTY: Here is the CASCADE BADGE! You earned every drop of it!$"

Kanto_CeruleanCity_Gym_EventScript_Diana::
	msgbox Kanto_CeruleanCity_Gym_EventScript_Diana_Text, MSGBOX_NPC
	end

Kanto_CeruleanCity_Gym_EventScript_Diana_Text:
		.string "You overwhelmed me!$"
Kanto_CeruleanCity_Gym_EventScript_GymGuy::
	msgbox Kanto_CeruleanCity_Gym_EventScript_GymGuy_Text, MSGBOX_NPC
	end

Kanto_CeruleanCity_Gym_EventScript_GymGuy_Text:
		.string "Yo!\n"
	.string "Champ in the making!\l"
	.string "Let me give you some advice!\l"
	.string "The LEADER, MISTY, is a pro who\n"
	.string "uses WATER-type POKeMON.\l"
	.string "You can drain all their water with\n"
	.string "GRASS-type POKeMON.\l"
	.string "Or, you might use ELECTRIC-type\n"
	.string "POKeMON and zap them!$"
Kanto_CeruleanCity_Gym_EventScript_GymStatue::
	msgbox Kanto_CeruleanCity_Gym_EventScript_GymStatue_Text, MSGBOX_NPC
	end

Kanto_CeruleanCity_Gym_EventScript_GymStatue_Text:
			.string "CERULEAN POKeMON GYM\n"
	.string "LEADER: MISTY\l"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}$"
Kanto_CeruleanCity_Gym_EventScript_Luis::
	msgbox Kanto_CeruleanCity_Gym_EventScript_Luis_Text, MSGBOX_NPC
	end

Kanto_CeruleanCity_Gym_EventScript_Luis_Text:
		.string "Yo!\n"
	.string "Champ in the making!\l"
	.string "Let me give you some advice!\l"
	.string "The LEADER, MISTY, is a pro who\n"
	.string "uses WATER-type POKeMON.\l"
	.string "You can drain all their water with\n"
	.string "GRASS-type POKeMON.\l"
	.string "Or, you might use ELECTRIC-type\n"
	.string "POKeMON and zap them!$"
