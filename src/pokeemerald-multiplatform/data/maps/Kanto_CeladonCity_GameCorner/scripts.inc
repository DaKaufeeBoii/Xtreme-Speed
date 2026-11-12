Kanto_CeladonCity_GameCorner_MapScripts::
	.byte 0

Kanto_CeladonCity_GameCorner_EventScript_BaldingMan::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_BaldingMan_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_BaldingMan_Text:
		.string "I think these machines have\n"
	.string "different odds.$"
Kanto_CeladonCity_GameCorner_EventScript_CoinsClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Kanto_CeladonCity_GameCorner_EventScript_CoinsClerk_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Kanto_CeladonCity_GameCorner_EventScript_CoinsClerk_Items:
	.short ITEM_ULTRA_BALL
	.short ITEM_HYPER_POTION
	.short ITEM_MAX_POTION
	.short ITEM_FULL_RESTORE
	.short ITEM_REVIVE
	.short ITEM_FULL_HEAL
	.short ITEM_MAX_REPEL
	pokemartlistend

Kanto_CeladonCity_GameCorner_EventScript_Fisher::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_Fisher_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_Fisher_Text:
		.string "Kid, do you want to play?$"
Kanto_CeladonCity_GameCorner_EventScript_Gentleman::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_Gentleman_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_Gentleman_Text:
		.string "{PLAYER} received 20 COINS\n"
	.string "from the man.$"
Kanto_CeladonCity_GameCorner_EventScript_GymGuy::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_GymGuy_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_GymGuy_Text:
		.string "{PLAYER} received 20 COINS\n"
	.string "from the nice guy.$"
Kanto_CeladonCity_GameCorner_EventScript_InfoClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Kanto_CeladonCity_GameCorner_EventScript_InfoClerk_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Kanto_CeladonCity_GameCorner_EventScript_InfoClerk_Items:
	.short ITEM_ULTRA_BALL
	.short ITEM_HYPER_POTION
	.short ITEM_MAX_POTION
	.short ITEM_FULL_RESTORE
	.short ITEM_REVIVE
	.short ITEM_FULL_HEAL
	.short ITEM_MAX_REPEL
	pokemartlistend

Kanto_CeladonCity_GameCorner_EventScript_OldMan::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_OldMan_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_OldMan_Text:
		.string "{PLAYER} received 20 COINS\n"
	.string "from the nice guy.$"
Kanto_CeladonCity_GameCorner_EventScript_PhotoPrinter::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_PhotoPrinter_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_PhotoPrinter_Text:
		.string "Please choose the print type.$"
Kanto_CeladonCity_GameCorner_EventScript_Poster::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_Poster_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_Poster_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_CeladonCity_GameCorner_EventScript_RocketGrunt::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_RocketGrunt_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_RocketGrunt_Text:
		.string "Dang!$"
Kanto_CeladonCity_GameCorner_EventScript_Scientist::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_Scientist_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_Scientist_Text:
		.string "{PLAYER} received 20 COINS\n"
	.string "from the nice guy.$"
Kanto_CeladonCity_GameCorner_EventScript_SlotMachine0::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_SlotMachine0_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_SlotMachine0_Text:
		.string "A slot machine!\n"
	.string "Want to play?$"
Kanto_CeladonCity_GameCorner_EventScript_SlotMachine1::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_SlotMachine1_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_SlotMachine1_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_CeladonCity_GameCorner_EventScript_SlotMachine10::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_SlotMachine10_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_SlotMachine10_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_CeladonCity_GameCorner_EventScript_SlotMachine11::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_SlotMachine11_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_SlotMachine11_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_CeladonCity_GameCorner_EventScript_SlotMachine12::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_SlotMachine12_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_SlotMachine12_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_CeladonCity_GameCorner_EventScript_SlotMachine13::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_SlotMachine13_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_SlotMachine13_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_CeladonCity_GameCorner_EventScript_SlotMachine14::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_SlotMachine14_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_SlotMachine14_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_CeladonCity_GameCorner_EventScript_SlotMachine16::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_SlotMachine16_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_SlotMachine16_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_CeladonCity_GameCorner_EventScript_SlotMachine17::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_SlotMachine17_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_SlotMachine17_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_CeladonCity_GameCorner_EventScript_SlotMachine19::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_SlotMachine19_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_SlotMachine19_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_CeladonCity_GameCorner_EventScript_SlotMachine2::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_SlotMachine2_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_SlotMachine2_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_CeladonCity_GameCorner_EventScript_SlotMachine20::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_SlotMachine20_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_SlotMachine20_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_CeladonCity_GameCorner_EventScript_SlotMachine21::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_SlotMachine21_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_SlotMachine21_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_CeladonCity_GameCorner_EventScript_SlotMachine3::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_SlotMachine3_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_SlotMachine3_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_CeladonCity_GameCorner_EventScript_SlotMachine5::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_SlotMachine5_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_SlotMachine5_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_CeladonCity_GameCorner_EventScript_SlotMachine6::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_SlotMachine6_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_SlotMachine6_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_CeladonCity_GameCorner_EventScript_SlotMachine7::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_SlotMachine7_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_SlotMachine7_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_CeladonCity_GameCorner_EventScript_SlotMachine8::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_SlotMachine8_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_SlotMachine8_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_CeladonCity_GameCorner_EventScript_SlotMachine9::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_SlotMachine9_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_SlotMachine9_Text:
	.string "Hello! Exploring KANTO is full of wonderful discoveries!$"
Kanto_CeladonCity_GameCorner_EventScript_UnusableSlotMachine1::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_UnusableSlotMachine1_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_UnusableSlotMachine1_Text:
		.string "OUT OF ORDER\n"
	.string "This is broken.$"
Kanto_CeladonCity_GameCorner_EventScript_UnusableSlotMachine2::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_UnusableSlotMachine2_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_UnusableSlotMachine2_Text:
		.string "OUT TO LUNCH\n"
	.string "This is reserved.$"
Kanto_CeladonCity_GameCorner_EventScript_UnusableSlotMachine3::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_UnusableSlotMachine3_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_UnusableSlotMachine3_Text:
		.string "We exchange your COINS for prizes.$"
Kanto_CeladonCity_GameCorner_EventScript_Woman1::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_Woman1_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_Woman1_Text:
		.string "I think these machines have\n"
	.string "different odds.$"
Kanto_CeladonCity_GameCorner_EventScript_Woman2::
	msgbox Kanto_CeladonCity_GameCorner_EventScript_Woman2_Text, MSGBOX_NPC
	end

Kanto_CeladonCity_GameCorner_EventScript_Woman2_Text:
		.string "{PLAYER} received 20 COINS\n"
	.string "from the nice guy.$"
