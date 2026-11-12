FuchsiaCity_Gym_MapScripts::
	.byte 0

FuchsiaCity_Gym_EventScript_Leader::
	lock
	faceplayer
	goto_if_set FLAG_BADGE_SOUL_GET, FuchsiaCity_Gym_EventScript_Defeated
	cleartrainerflag TRAINER_KANTO_KOGA
	msgbox FuchsiaCity_Gym_Text_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KANTO_KOGA, FuchsiaCity_Gym_Text_Defeat
	setflag FLAG_BADGE_SOUL_GET
	setflag FLAG_DEFEATED_KANTO_KOGA
	playfanfare MUS_OBTAIN_BADGE
	message FuchsiaCity_Gym_Text_ReceivedBadge
	waitfanfare
	msgbox FuchsiaCity_Gym_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_Gym_EventScript_Defeated::
	msgbox FuchsiaCity_Gym_Text_RematchPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_Gym_EventScript_Rematch
	msgbox FuchsiaCity_Gym_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_Gym_EventScript_Rematch::
	cleartrainerflag TRAINER_KANTO_KOGA
	msgbox FuchsiaCity_Gym_Text_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KANTO_KOGA, FuchsiaCity_Gym_Text_Defeat
	msgbox FuchsiaCity_Gym_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_Gym_Text_Intro:
	.string "JANINE: Fwahahaha!\n"
	.string "I am JANINE, the Poisonous Ninja!\p"
	.string "My father KOGA taught me the sacred\n"
	.string "art of poison, shadows, and stealth!\p"
	.string "Can your Hoenn team pierce our\n"
	.string "toxic illusions?!$"

FuchsiaCity_Gym_Text_Defeat:
	.string "JANINE: Ah! My ninja techniques\n"
	.string "were shattered! What fierce power!$"

FuchsiaCity_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the\n"
	.string "SOUL BADGE from JANINE!$"

FuchsiaCity_Gym_Text_PostBattle:
	.string "JANINE: With the SOUL BADGE, you\n"
	.string "can SURF across open waters!\p"
	.string "Take Route 19 and Route 20 south\n"
	.string "to CINNABAR ISLAND!\p"
	.string "Beware the ocean currents!$"

FuchsiaCity_Gym_Text_RematchPrompt:
	.string "JANINE: Ready to test your reflexes\n"
	.string "against our ninjutsu once more?$"
