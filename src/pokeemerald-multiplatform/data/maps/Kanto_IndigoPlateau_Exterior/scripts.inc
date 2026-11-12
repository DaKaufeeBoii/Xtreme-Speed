Kanto_IndigoPlateau_Exterior_MapScripts::
	.byte 0

Kanto_IndigoPlateau_Exterior_EventScript_Red::
	lock
	faceplayer
	cleartrainerflag TRAINER_RED
	msgbox Kanto_IndigoPlateau_Exterior_Text_RedIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_RED, Kanto_IndigoPlateau_Exterior_Text_RedDefeat
	msgbox Kanto_IndigoPlateau_Exterior_Text_RedPost, MSGBOX_DEFAULT
	release
	end

Kanto_IndigoPlateau_Exterior_Text_RedIntro:
	.string "... ... ...\n"
	.string "... ... ...!$"
Kanto_IndigoPlateau_Exterior_Text_RedDefeat:
	.string "...!$"
Kanto_IndigoPlateau_Exterior_Text_RedPost:
	.string "... ... ...\n"
	.string "(RED nods with quiet respect.)$"
