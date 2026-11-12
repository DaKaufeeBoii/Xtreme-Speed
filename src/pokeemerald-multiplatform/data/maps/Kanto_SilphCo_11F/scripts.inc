Kanto_SilphCo_11F_MapScripts::
	.byte 0

Kanto_SilphCo_11F_EventScript_Door::
	msgbox Kanto_SilphCo_11F_EventScript_Door_Text, MSGBOX_NPC
	end

Kanto_SilphCo_11F_EventScript_Door_Text:
					.string "Bingo!\n"
	.string "The CARD KEY opened the door!$"
Kanto_SilphCo_11F_EventScript_FloorSign::
	msgbox Kanto_SilphCo_11F_EventScript_FloorSign_Text, MSGBOX_SIGN
	end

Kanto_SilphCo_11F_EventScript_FloorSign_Text:
		.string "SILPH CO. HEAD OFFICE\n"
	.string "11F$"
Kanto_SilphCo_11F_EventScript_GiovanniTriggerLeft::
	end

Kanto_SilphCo_11F_EventScript_GiovanniTriggerRight::
	end

Kanto_SilphCo_11F_EventScript_Grunt1::
	msgbox Kanto_SilphCo_11F_EventScript_Grunt1_Text, MSGBOX_NPC
	end

Kanto_SilphCo_11F_EventScript_Grunt1_Text:
		.string "Halt! Do you have an appointment\n"
	.string "with my BOSS?$"
Kanto_SilphCo_11F_EventScript_Grunt2::
	msgbox Kanto_SilphCo_11F_EventScript_Grunt2_Text, MSGBOX_NPC
	end

Kanto_SilphCo_11F_EventScript_Grunt2_Text:
		.string "So, you want to see my BOSS?$"
Kanto_SilphCo_11F_EventScript_ItemZinc::
	msgbox Kanto_SilphCo_11F_EventScript_ItemZinc_Text, MSGBOX_DEFAULT
	release
	end

Kanto_SilphCo_11F_EventScript_ItemZinc_Text:
	.string "Found a valuable item for your journey!$"
Kanto_SilphCo_11F_EventScript_President::
	msgbox Kanto_SilphCo_11F_EventScript_President_Text, MSGBOX_NPC
	end

Kanto_SilphCo_11F_EventScript_President_Text:
		.string "{PLAYER} obtained a MASTER BALL\n"
	.string "from the PRESIDENT!$"
Kanto_SilphCo_11F_EventScript_Secretary::
	msgbox Kanto_SilphCo_11F_EventScript_Secretary_Text, MSGBOX_NPC
	end

Kanto_SilphCo_11F_EventScript_Secretary_Text:
		.string "SECRETARY: Thank you for rescuing\n"
	.string "all of us.\l"
	.string "We, from the PRESIDENT down,\n"
	.string "are indebted to you.$"
