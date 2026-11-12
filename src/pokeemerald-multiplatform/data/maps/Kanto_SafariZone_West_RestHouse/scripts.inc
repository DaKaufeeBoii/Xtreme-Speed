Kanto_SafariZone_West_RestHouse_MapScripts::
	.byte 0

Kanto_SafariZone_West_RestHouse_EventScript_CooltrainerF::
	msgbox Kanto_SafariZone_West_RestHouse_EventScript_CooltrainerF_Text, MSGBOX_NPC
	end

Kanto_SafariZone_West_RestHouse_EventScript_CooltrainerF_Text:
		.string "{PLAYER} received HM03\n"
	.string "from the attendant!$"
Kanto_SafariZone_West_RestHouse_EventScript_Man::
	msgbox Kanto_SafariZone_West_RestHouse_EventScript_Man_Text, MSGBOX_NPC
	end

Kanto_SafariZone_West_RestHouse_EventScript_Man_Text:
		.string "Using BAIT will make POKeMON more\n"
	.string "likely to stick around if they get\p"
	.string "busy eating.$"
Kanto_SafariZone_West_RestHouse_EventScript_Scientist::
	msgbox Kanto_SafariZone_West_RestHouse_EventScript_Scientist_Text, MSGBOX_NPC
	end

Kanto_SafariZone_West_RestHouse_EventScript_Scientist_Text:
		.string "{PLAYER} received HM03\n"
	.string "from the attendant!$"
