Kanto_FuchsiaCity_Gym_MapScripts::
	.byte 0

Kanto_FuchsiaCity_Gym_EventScript_Koga::
	lock
	faceplayer
	goto_if_set FLAG_BADGE_SOUL_GET, Kanto_FuchsiaCity_Gym_EventScript_LeaderDefeated
	cleartrainerflag TRAINER_KANTO_KOGA
	msgbox Kanto_FuchsiaCity_Gym_Text_LeaderIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KANTO_KOGA, Kanto_FuchsiaCity_Gym_Text_LeaderDefeat
	setflag FLAG_BADGE_SOUL_GET
	playfanfare MUS_OBTAIN_BADGE
	message Kanto_FuchsiaCity_Gym_Text_ReceivedBadge
	waitfanfare
	msgbox Kanto_FuchsiaCity_Gym_Text_LeaderPost, MSGBOX_DEFAULT
	release
	end

Kanto_FuchsiaCity_Gym_EventScript_LeaderDefeated::
	msgbox Kanto_FuchsiaCity_Gym_Text_LeaderPost, MSGBOX_DEFAULT
	release
	end

Kanto_FuchsiaCity_Gym_Text_LeaderIntro:
	.string "JANINE: Fwahahaha! A challenger from afar!\p"
	.string "I have mastered the poisonous arts of the ninja clan!\p"
	.string "Step forward into our venomous web!$"

Kanto_FuchsiaCity_Gym_Text_LeaderDefeat:
	.string "JANINE: What?! My ninja arts were dismantled!$"

Kanto_FuchsiaCity_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the\nSOUL BADGE from JANINE!$"

Kanto_FuchsiaCity_Gym_Text_LeaderPost:
	.string "JANINE: You fought with true honor. Take the SOUL BADGE!$"

Kanto_FuchsiaCity_Gym_EventScript_Edgar::
	msgbox Kanto_FuchsiaCity_Gym_EventScript_Edgar_Text, MSGBOX_NPC
	end

Kanto_FuchsiaCity_Gym_EventScript_Edgar_Text:
		.string "I also study the way of the ninja\n"
	.string "with Master KOGA!\l"
	.string "Ninja have a long history of using\n"
	.string "animals!$"
Kanto_FuchsiaCity_Gym_EventScript_GymGuy::
	msgbox Kanto_FuchsiaCity_Gym_EventScript_GymGuy_Text, MSGBOX_NPC
	end

Kanto_FuchsiaCity_Gym_EventScript_GymGuy_Text:
		.string "FUCHSIA POKeMON GYM\n"
	.string "LEADER: KOGA\l"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}$"
Kanto_FuchsiaCity_Gym_EventScript_GymStatue::
	msgbox Kanto_FuchsiaCity_Gym_EventScript_GymStatue_Text, MSGBOX_NPC
	end

Kanto_FuchsiaCity_Gym_EventScript_GymStatue_Text:
			.string "FUCHSIA POKeMON GYM\n"
	.string "LEADER: KOGA\l"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}$"
Kanto_FuchsiaCity_Gym_EventScript_Kayden::
	msgbox Kanto_FuchsiaCity_Gym_EventScript_Kayden_Text, MSGBOX_NPC
	end

Kanto_FuchsiaCity_Gym_EventScript_Kayden_Text:
		.string "What?\n"
	.string "Extraordinary!$"
Kanto_FuchsiaCity_Gym_EventScript_Kirk::
	msgbox Kanto_FuchsiaCity_Gym_EventScript_Kirk_Text, MSGBOX_NPC
	end

Kanto_FuchsiaCity_Gym_EventScript_Kirk_Text:
		.string "I was a magician once upon a time.\l"
	.string "But I dreamt of becoming a ninja,\n"
	.string "so I joined this GYM.$"
Kanto_FuchsiaCity_Gym_EventScript_Nate::
	msgbox Kanto_FuchsiaCity_Gym_EventScript_Nate_Text, MSGBOX_NPC
	end

Kanto_FuchsiaCity_Gym_EventScript_Nate_Text:
		.string "You had me fooled!$"
Kanto_FuchsiaCity_Gym_EventScript_Phil::
	msgbox Kanto_FuchsiaCity_Gym_EventScript_Phil_Text, MSGBOX_NPC
	end

Kanto_FuchsiaCity_Gym_EventScript_Phil_Text:
		.string "Stop right there!\l"
	.string "The famed invisible walls of\n"
	.string "FUCHSIA GYM have you frustrated?$"
Kanto_FuchsiaCity_Gym_EventScript_Shawn::
	msgbox Kanto_FuchsiaCity_Gym_EventScript_Shawn_Text, MSGBOX_NPC
	end

Kanto_FuchsiaCity_Gym_EventScript_Shawn_Text:
		.string "Master KOGA comes from a long line\n"
	.string "of ninjas.\l"
	.string "What did you descend from?$"
