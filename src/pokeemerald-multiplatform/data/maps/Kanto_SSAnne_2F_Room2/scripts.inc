Kanto_SSAnne_2F_Room2_MapScripts::
	.byte 0

Kanto_SSAnne_2F_Room2_EventScript_Brooks::
	msgbox Kanto_SSAnne_2F_Room2_EventScript_Brooks_Text, MSGBOX_NPC
	end

Kanto_SSAnne_2F_Room2_EventScript_Brooks_Text:
		.string "Competing against the young keeps\n"
	.string "me youthful.$"
Kanto_SSAnne_2F_Room2_EventScript_Dale::
	msgbox Kanto_SSAnne_2F_Room2_EventScript_Dale_Text, MSGBOX_NPC
	end

Kanto_SSAnne_2F_Room2_EventScript_Dale_Text:
		.string "Check out what I fished up!$"
Kanto_SSAnne_2F_Room2_EventScript_ItemStardust::
	msgbox Kanto_SSAnne_2F_Room2_EventScript_ItemStardust_Text, MSGBOX_DEFAULT
	release
	end

Kanto_SSAnne_2F_Room2_EventScript_ItemStardust_Text:
	.string "Found a valuable item for your journey!$"
