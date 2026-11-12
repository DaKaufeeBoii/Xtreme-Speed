Kanto_SSAnne_Exterior_MapScripts::
	.byte 0

Kanto_SSAnne_Exterior_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox Kanto_SSAnne_Exterior_Text_FerryPrompt, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Kanto_SSAnne_Exterior_EventScript_BoardFerry
	msgbox Kanto_SSAnne_Exterior_Text_EnjoyKanto, MSGBOX_DEFAULT
	release
	end

Kanto_SSAnne_Exterior_EventScript_BoardFerry::
	msgbox Kanto_SSAnne_Exterior_Text_SettingSail, MSGBOX_DEFAULT
	closemessage
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

Kanto_SSAnne_Exterior_Text_FerryPrompt:
	.string "SAILOR: Welcome to the VERMILION PORT!\p"
	.string "Would you like to take the S.S. TIDAL\n"
	.string "back to the HOENN region?$"
Kanto_SSAnne_Exterior_Text_EnjoyKanto:
	.string "SAILOR: Bon voyage! Enjoy your time\n"
	.string "exploring KANTO!$"
Kanto_SSAnne_Exterior_Text_SettingSail:
	.string "SAILOR: Setting sail for SLATEPORT!\n"
	.string "All passengers aboard!$"
