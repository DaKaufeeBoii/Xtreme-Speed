Kanto_Route2_MapScripts::
	.byte 0

Kanto_Route2_EventScript_DiglettsCaveSign::
	msgbox Kanto_Route2_EventScript_DiglettsCaveSign_Text, MSGBOX_SIGN
	end

Kanto_Route2_EventScript_DiglettsCaveSign_Text:
		.string "ROUTE 3\n"
	.string "MT. MOON AHEAD$"
Kanto_Route2_EventScript_ItemEther::
	msgbox Kanto_Route2_EventScript_ItemEther_Text, MSGBOX_DEFAULT
	release
	end

Kanto_Route2_EventScript_ItemEther_Text:
	.string "Found a valuable item for your journey!$"
Kanto_Route2_EventScript_ItemParalyzeHeal::
	msgbox Kanto_Route2_EventScript_ItemParalyzeHeal_Text, MSGBOX_DEFAULT
	release
	end

Kanto_Route2_EventScript_ItemParalyzeHeal_Text:
	.string "Found a valuable item for your journey!$"
Kanto_Route2_EventScript_RouteSign::
	msgbox Kanto_Route2_EventScript_RouteSign_Text, MSGBOX_SIGN
	end

Kanto_Route2_EventScript_RouteSign_Text:
		.string "ROUTE 2\n"
	.string "VIRIDIAN CITY - PEWTER CITY$"
