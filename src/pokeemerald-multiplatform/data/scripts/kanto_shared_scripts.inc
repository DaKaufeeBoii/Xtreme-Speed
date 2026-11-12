// ==============================================================================
// Kanto Shared Event Scripts
// ==============================================================================

	.align 2

Kanto_EventScript_CutTree::
	goto EventScript_CutTree

Kanto_EventScript_RockSmash::
	goto EventScript_RockSmash

Kanto_EventScript_StrengthBoulder::
	goto EventScript_StrengthBoulder

Kanto_Common_EventScript_UnionRoomAttendant::
	msgbox Kanto_Common_Text_UnionRoom, MSGBOX_NPC
	end

Kanto_Common_EventScript_WirelessClubAttendant::
	msgbox Kanto_Common_Text_WirelessClub, MSGBOX_NPC
	end

Kanto_Common_EventScript_DirectCornerAttendant::
	msgbox Kanto_Common_Text_DirectCorner, MSGBOX_NPC
	end

Kanto_CableClub_EventScript_MysteryGiftMan::
	msgbox Kanto_Common_Text_MysteryGiftMan, MSGBOX_NPC
	end

Kanto_CeruleanCity_BikeShop_EventScript_Bicycle::
	msgbox Kanto_Text_CeruleanBicycle, MSGBOX_SIGN
	end

Kanto_EventScript_SetExitingCyclingRoad::
	end

Kanto_EventScript_SetEnteringCyclingRoad::
	end

// Legacy Gym Leader Script Aliases
PewterCity_Gym_EventScript_Leader::
	goto Kanto_PewterCity_Gym_EventScript_Brock

CeruleanCity_Gym_EventScript_Leader::
	goto Kanto_CeruleanCity_Gym_EventScript_Misty

VermilionCity_Gym_EventScript_Leader::
	goto Kanto_VermilionCity_Gym_EventScript_LtSurge

CeladonCity_Gym_EventScript_Leader::
	goto Kanto_CeladonCity_Gym_EventScript_Erika

FuchsiaCity_Gym_EventScript_Leader::
	goto Kanto_FuchsiaCity_Gym_EventScript_Koga

SaffronCity_Gym_EventScript_Leader::
	goto Kanto_SaffronCity_Gym_EventScript_Sabrina

CinnabarIsland_Gym_EventScript_Leader::
	goto Kanto_CinnabarIsland_Gym_EventScript_Blaine

ViridianCity_Gym_EventScript_Leader::
	goto Kanto_ViridianCity_Gym_EventScript_Giovanni

Kanto_Common_Text_UnionRoom:
	.string "Welcome to the POKéMON WIRELESS CLUB\n"
	.string "UNION ROOM!$"

Kanto_Common_Text_WirelessClub:
	.string "Welcome to the WIRELESS CLUB!$"

Kanto_Common_Text_DirectCorner:
	.string "Welcome to the DIRECT CORNER!$"

Kanto_Common_Text_MysteryGiftMan:
	.string "I deliver special MYSTERY GIFTS from\n"
	.string "distant events!$"

Kanto_Text_CeruleanBicycle:
	.string "A brand new gleaming BICYCLE!\p"
	.string "The price tag reads:\n"
	.string "1,000,000! Too expensive!$"
