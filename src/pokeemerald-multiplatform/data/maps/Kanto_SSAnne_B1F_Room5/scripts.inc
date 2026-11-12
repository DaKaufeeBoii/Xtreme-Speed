Kanto_SSAnne_B1F_Room5_MapScripts::
	.byte 0

Kanto_SSAnne_B1F_Room5_EventScript_Boy::
	msgbox Kanto_SSAnne_B1F_Room5_EventScript_Boy_Text, MSGBOX_NPC
	end

Kanto_SSAnne_B1F_Room5_EventScript_Boy_Text:
		.string "My buddy MACHOKE is super strong!\l"
	.string "He has enough STRENGTH to move\n"
	.string "big rocks!$"
Kanto_SSAnne_B1F_Room5_EventScript_ItemSuperPotion::
	msgbox Kanto_SSAnne_B1F_Room5_EventScript_ItemSuperPotion_Text, MSGBOX_DEFAULT
	release
	end

Kanto_SSAnne_B1F_Room5_EventScript_ItemSuperPotion_Text:
	.string "Found a valuable item for your journey!$"
Kanto_SSAnne_B1F_Room5_EventScript_Machoke::
	msgbox Kanto_SSAnne_B1F_Room5_EventScript_Machoke_Text, MSGBOX_NPC
	end

Kanto_SSAnne_B1F_Room5_EventScript_Machoke_Text:
		.string "MACHOKE: Gwoh! Goggoh!$"
