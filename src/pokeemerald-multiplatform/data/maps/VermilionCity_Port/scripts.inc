VermilionCity_Port_MapScripts::
	.byte 0

VermilionCity_Port_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox VermilionCity_Port_Text_ReturnToHoenn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VermilionCity_Port_EventScript_SailBackToHoenn
	msgbox VermilionCity_Port_Text_EnjoyKanto, MSGBOX_DEFAULT
	release
	end

VermilionCity_Port_EventScript_SailBackToHoenn::
	msgbox VermilionCity_Port_Text_SettingSailToHoenn, MSGBOX_DEFAULT
	closemessage
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

VermilionCity_Port_EventScript_Sailor1::
	msgbox VermilionCity_Port_Text_Sailor1, MSGBOX_NPC
	end

VermilionCity_Port_EventScript_Sailor2::
	msgbox VermilionCity_Port_Text_Sailor2, MSGBOX_NPC
	end

VermilionCity_Port_Text_ReturnToHoenn:
	.string "ATTENDANT: Welcome to the\n"
	.string "VERMILION CITY PORT in KANTO!\p"
	.string "Would you like to take the\n"
	.string "S.S. TIDAL back to HOENN?$"

VermilionCity_Port_Text_SettingSailToHoenn:
	.string "ATTENDANT: All aboard!\n"
	.string "Setting sail for SLATEPORT!$"

VermilionCity_Port_Text_EnjoyKanto:
	.string "ATTENDANT: Safe travels in the\n"
	.string "KANTO region, Champion!$"

VermilionCity_Port_Text_Sailor1:
	.string "SAILOR: You've crossed the sea\n"
	.string "from Hoenn!\p"
	.string "The Kanto Gym challenge is unlike\n"
	.string "anything you've seen.$"

VermilionCity_Port_Text_Sailor2:
	.string "SAILOR: Viridian Gym's Leader\n"
	.string "BLUE is waiting for the best!\l"
	.string "Show him what Hoenn can do!$"
