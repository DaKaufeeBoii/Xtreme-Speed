Kanto_SeafoamIslands_B4F_MapScripts::
	.byte 0

Kanto_SeafoamIslands_B4F_EventScript_Articuno::
	msgbox Kanto_SeafoamIslands_B4F_EventScript_Articuno_Text, MSGBOX_NPC
	end

Kanto_SeafoamIslands_B4F_EventScript_Articuno_Text:
		.string "Gyaoo!$"
Kanto_SeafoamIslands_B4F_EventScript_BoulderHintSign::
	msgbox Kanto_SeafoamIslands_B4F_EventScript_BoulderHintSign_Text, MSGBOX_SIGN
	end

Kanto_SeafoamIslands_B4F_EventScript_BoulderHintSign_Text:
		.string "Hint: Boulders might change the\n"
	.string "flow of water.$"
Kanto_SeafoamIslands_B4F_EventScript_FastCurrentSign::
	msgbox Kanto_SeafoamIslands_B4F_EventScript_FastCurrentSign_Text, MSGBOX_SIGN
	end

Kanto_SeafoamIslands_B4F_EventScript_FastCurrentSign_Text:
		.string "DANGER\n"
	.string "Fast current!$"
Kanto_SeafoamIslands_B4F_EventScript_ItemUltraBall::
	msgbox Kanto_SeafoamIslands_B4F_EventScript_ItemUltraBall_Text, MSGBOX_DEFAULT
	release
	end

Kanto_SeafoamIslands_B4F_EventScript_ItemUltraBall_Text:
	.string "Found a valuable item for your journey!$"
Kanto_SeafoamIslands_B4F_EventScript_UpwardCurrent::
	msgbox Kanto_SeafoamIslands_B4F_EventScript_UpwardCurrent_Text, MSGBOX_NPC
	end

Kanto_SeafoamIslands_B4F_EventScript_UpwardCurrent_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
