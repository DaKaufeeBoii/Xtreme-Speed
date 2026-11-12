Kanto_SSAnne_2F_Room4_MapScripts::
	.byte 0

Kanto_SSAnne_2F_Room4_EventScript_Dawn::
	msgbox Kanto_SSAnne_2F_Room4_EventScript_Dawn_Text, MSGBOX_NPC
	end

Kanto_SSAnne_2F_Room4_EventScript_Dawn_Text:
		.string "Take it easy!$"
Kanto_SSAnne_2F_Room4_EventScript_ItemXAttack::
	msgbox Kanto_SSAnne_2F_Room4_EventScript_ItemXAttack_Text, MSGBOX_DEFAULT
	release
	end

Kanto_SSAnne_2F_Room4_EventScript_ItemXAttack_Text:
	.string "Found a valuable item for your journey!$"
Kanto_SSAnne_2F_Room4_EventScript_Lamar::
	msgbox Kanto_SSAnne_2F_Room4_EventScript_Lamar_Text, MSGBOX_NPC
	end

Kanto_SSAnne_2F_Room4_EventScript_Lamar_Text:
		.string "Which do you find more worthy,\n"
	.string "a strong or a rare POKeMON?$"
