MtMoon_DigSite_MapScripts::
	.byte 0

MtMoon_DigSite_EventScript_Maxie::
	lock
	faceplayer
	msgbox MtMoon_DigSite_Text_MaxieChallenge, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_MOON, MtMoon_DigSite_Text_MaxieDefeat
	applymovement 2, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MtMoon_DigSite_Text_ArcherChallenge, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHER_MT_MOON, MtMoon_DigSite_Text_ArcherDefeat
	msgbox MtMoon_DigSite_Text_SyndicateRetreat, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_MT_MOON_DIG_CLEARED
	removeobject 1
	removeobject 2
	fadescreen FADE_FROM_BLACK
	msgbox MtMoon_DigSite_Text_PassageCleared, MSGBOX_DEFAULT
	release
	end

MtMoon_DigSite_EventScript_Archer::
	goto MtMoon_DigSite_EventScript_Maxie
	end

MtMoon_DigSite_Text_MaxieChallenge:
	.string "MAXIE: So you followed us to\n"
	.string "the depths of MT. MOON!\p"
	.string "These cosmic meteorites carry\n"
	.string "the celestial energy required\l"
	.string "to expand the land!\p"
	.string "I will not let you interfere!$"

MtMoon_DigSite_Text_MaxieDefeat:
	.string "MAXIE: Even in Kanto, your\n"
	.string "conviction surpasses mine...$"

MtMoon_DigSite_Text_ArcherChallenge:
	.string "ARCHER: Quiet, MAXIE!\n"
	.string "I am ARCHER, Supreme Commander\l"
	.string "of TEAM ROCKET!\p"
	.string "We will not let our resurgence\n"
	.string "be halted by a meddling brat!$"

MtMoon_DigSite_Text_ArcherDefeat:
	.string "ARCHER: Blast it all! Such\n"
	.string "overwhelming power...$"

MtMoon_DigSite_Text_SyndicateRetreat:
	.string "ARCHER: Pull back! We must\n"
	.string "regroup at the offshore base!$"

MtMoon_DigSite_Text_PassageCleared:
	.string "The MT. MOON excavation site\n"
	.string "has been cleared!\p"
	.string "The mountain tunnel now opens\n"
	.string "west to PEWTER CITY!$"
