// ==============================================================================
// POKÉMON XTREME-SPEED: KANTO GEOGRAPHICAL CIRCUIT & STORYLINE
// "Operation Eclipse: The Rocket-Magma Syndicate & The Summit Champions"
// Parallel Post-Game Expedition with Detective Looker & Steven Stone
// ==============================================================================

KantoPostGame_EventScript_TryTriggerStory::
	goto_if_unset FLAG_SYS_GAME_CLEAR, KantoPostGame_EventScript_StoryNotReady
	goto_if_set FLAG_TEMP_5, KantoPostGame_EventScript_LookerBriefing
	setflag FLAG_TEMP_5
	goto KantoPostGame_EventScript_LookerBriefing

KantoPostGame_EventScript_StoryNotReady::
	msgbox KantoStory_Text_StoryNotReady, MSGBOX_DEFAULT
	release
	end

KantoPostGame_EventScript_LookerLiaisonNPC::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, KantoPostGame_EventScript_StoryNotReady
	goto_if_set FLAG_DEFEATED_DEOXYS, KantoPostGame_EventScript_StandardDepartureMenu
	goto KantoPostGame_EventScript_LookerBriefing

KantoPostGame_EventScript_StandardDepartureMenu::
	msgbox KantoPostGame_Text_DepartToKantoOperation, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KantoPostGame_EventScript_SailToVermilion
	msgbox KantoPostGame_Text_OperationPostponed, MSGBOX_DEFAULT
	release
	end

KantoPostGame_EventScript_SailToVermilion::
	msgbox KantoStory_Text_SailToVermilionConfirm, MSGBOX_DEFAULT
	closemessage
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_KANTO_SSANNE_EXTERIOR, 32, 7
	waitstate
	release
	end

KantoPostGame_EventScript_LookerBriefing::
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox KantoPostGame_Text_LookerBriefing, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox KantoPostGame_Text_StevenSpeech, MSGBOX_DEFAULT
	closemessage
	msgbox KantoPostGame_Text_DepartToKantoOperation, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KantoPostGame_EventScript_LaunchOperation
	msgbox KantoPostGame_Text_OperationPostponed, MSGBOX_DEFAULT
	release
	end

KantoPostGame_EventScript_LaunchOperation::
	msgbox KantoPostGame_Text_OperationUnderway, MSGBOX_DEFAULT
	closemessage
	goto_if_set FLAG_BIRCH_KANTO_NATIONAL_DEX, KantoPostGame_EventScript_SkipBirchDex
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	playfanfare MUS_OBTAIN_ITEM
	msgbox KantoPostGame_Text_BirchUpgradedDex, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_BIRCH_KANTO_NATIONAL_DEX
KantoPostGame_EventScript_SkipBirchDex:
	giveitem ITEM_AURORA_TICKET
	giveitem ITEM_MYSTIC_TICKET
	giveitem ITEM_OLD_SEA_MAP
	giveitem ITEM_EON_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	setflag FLAG_DEFEATED_DEOXYS
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_KANTO_SSANNE_EXTERIOR, 32, 7
	waitstate
	release
	end

// ==============================================================================
// 8TH GYM: VIRIDIAN CITY GYM - GYM LEADER BLUE (REPLACING GIOVANNI)
// ==============================================================================
KantoStory_EventScript_ViridianGymBlue::
	lock
	faceplayer
	goto_if_set FLAG_BADGE_EARTH_GET, KantoStory_EventScript_BlueDefeated
	cleartrainerflag TRAINER_BLUE
	msgbox KantoStory_Text_BlueIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLUE, KantoStory_Text_BlueDefeat
	setflag FLAG_BADGE_EARTH_GET
	setflag FLAG_DEFEATED_KANTO_BLUE
	playfanfare MUS_OBTAIN_BADGE
	message KantoStory_Text_ReceivedEarthBadge
	waitfanfare
	goto KantoStory_EventScript_BluePostBattleMenu

KantoStory_EventScript_BlueDefeated::
	msgbox KantoStory_Text_BlueRematchPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KantoStory_EventScript_BlueDoRematch
	goto KantoStory_EventScript_BluePostBattleMenu

KantoStory_EventScript_BlueDoRematch::
	cleartrainerflag TRAINER_BLUE
	msgbox KantoStory_Text_BlueRematchIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLUE, KantoStory_Text_BlueDefeat
	goto KantoStory_EventScript_BluePostBattleMenu

KantoStory_EventScript_BluePostBattleMenu::
	msgbox KantoStory_Text_BluePostBattle, MSGBOX_DEFAULT
	msgbox KantoStory_Text_ProceedToIndigo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KantoStory_EventScript_WarpToIndigoSummit
	release
	end

KantoStory_EventScript_WarpToIndigoSummit::
	msgbox KantoStory_Text_IndigoWarpConfirm, MSGBOX_DEFAULT
	closemessage
	warp MAP_KANTO_INDIGO_PLATEAU_EXTERIOR, 10, 10
	waitstate
	release
	end

// ==============================================================================
// INDIGO PLATEAU: KANTO LEAGUE SUMMIT - LEGENDARY CHAMPION RED
// ==============================================================================
KantoStory_EventScript_IndigoChampionRed::
	lockall
	faceplayer
	goto_if_set FLAG_DEFEATED_KANTO_RED, KantoStory_EventScript_RedPostVictory
	cleartrainerflag TRAINER_RED
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox KantoStory_Text_RedSilence, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_RED, KantoStory_Text_RedDefeat
	setflag FLAG_DEFEATED_KANTO_RED
	playfanfare MUS_VICTORY_LEAGUE
	msgbox KantoStory_Text_RedVictory, MSGBOX_DEFAULT
	waitfanfare
	msgbox KantoStory_Text_RedConclusion, MSGBOX_DEFAULT
	releaseall
	end

KantoStory_EventScript_RedPostVictory::
	msgbox KantoStory_Text_RedRematchPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KantoStory_EventScript_RedDoRematch
	msgbox KantoStory_Text_RedConclusion, MSGBOX_DEFAULT
	releaseall
	end

KantoStory_EventScript_RedDoRematch::
	cleartrainerflag TRAINER_RED
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox KantoStory_Text_RedSilence, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_RED, KantoStory_Text_RedDefeat
	msgbox KantoStory_Text_RedVictory, MSGBOX_DEFAULT
	releaseall
	end

// ==============================================================================
// TEXT AND STRINGS (STRICT GBA CHAR BOUNDS <= 31 CHARACTERS PER LINE)
// ==============================================================================
KantoStory_Text_StoryNotReady:
	.string "LOOKER: Greetings, Trainer.\n"
	.string "The sea route to Kanto is\l"
	.string "reserved for the Champion of\l"
	.string "the Hoenn Pokémon League.$"

KantoStory_Text_SailToVermilionConfirm:
	.string "PORT CAPTAIN: Anchors aweigh!\n"
	.string "Setting sail for VERMILION!\p"
	.string "The Kanto Gym Circuit begins\n"
	.string "with LT. SURGE in Vermilion!$"

KantoPostGame_Text_LookerBriefing:
	.string "LOOKER: Shh! Keep quiet.\p"
	.string "I am an investigator with the\n"
	.string "INTERNATIONAL POLICE.\l"
	.string "Code name: LOOKER!\p"
	.string "Exiled remnants of TEAM MAGMA\n"
	.string "and TEAM AQUA joined forces\l"
	.string "with TEAM ROCKET's cells:\l"
	.string "the 'ECLIPSE SYNDICATE'.\p"
	.string "They are targeting Kanto\n"
	.string "and the mythic EVENT ISLANDS!\p"
	.string "We are deploying to Kanto\n"
	.string "to intercept their cells!$"

KantoPostGame_Text_StevenSpeech:
	.string "STEVEN: Hello, {PLAYER}.\p"
	.string "I came investigating ancient\n"
	.string "cosmic meteorites when I saw\l"
	.string "the Syndicate mobilizing.\p"
	.string "In Kanto, BLUE took over the\n"
	.string "VIRIDIAN GYM, while RED reigns\l"
	.string "atop the INDIGO PLATEAU.\p"
	.string "Together with LOOKER, we will\n"
	.string "safeguard both regions!$"

KantoPostGame_Text_DepartToKantoOperation:
	.string "STEVEN: Are you prepared to set\n"
	.string "sail for VERMILION PORT?$"

KantoPostGame_Text_OperationPostponed:
	.string "STEVEN: Understood. Prepare\n"
	.string "your team and supplies.\l"
	.string "We await your signal.$"

KantoPostGame_Text_OperationUnderway:
	.string "LOOKER: Excellent! Take these\n"
	.string "official naval clearances:\l"
	.string "the AURORA and MYSTIC TICKETS,\l"
	.string "plus OLD SEA MAP & EON TICKET!\p"
	.string "STEVEN: Let's move out!\n"
	.string "To VERMILION CITY!$"

KantoPostGame_Text_BirchUpgradedDex:
	.string "PROF. BIRCH: Wait, {PLAYER}!\p"
	.string "Since you are voyaging across the\n"
	.string "sea to KANTO, your POKéDEX needs\l"
	.string "the NATIONAL MODE upgrade!\p"
	.string "{PLAYER}'s POKéDEX was upgraded to\n"
	.string "the NATIONAL POKéDEX!\p"
	.string "BIRCH: Best of luck in KANTO,\n"
	.string "Hoenn Champion!$"

KantoStory_Text_BlueIntro:
	.string "BLUE: Yo! You finally made it\n"
	.string "to VIRIDIAN CITY!\p"
	.string "Giovanni fled when his Rocket\n"
	.string "syndicate collapsed, so I took\l"
	.string "over as the GYM LEADER!\p"
	.string "I don't stick to one type.\n"
	.string "I battle to overwhelm you!\p"
	.string "Show me everything you've got\n"
	.string "from your Hoenn journey!$"

KantoStory_Text_BlueRematchPrompt:
	.string "BLUE: Yo {PLAYER}!\n"
	.string "Ready for another battle?$"

KantoStory_Text_BlueRematchIntro:
	.string "BLUE: That's the spirit!\n"
	.string "Let's see your full power!$"

KantoStory_Text_BlueDefeat:
	.string "BLUE: Whoa! You're really\n"
	.string "something special! I hate\l"
	.string "losing, but great match!$"

KantoStory_Text_ReceivedEarthBadge:
	.string "{PLAYER} received the\n"
	.string "EARTH BADGE from BLUE!$"

KantoStory_Text_BluePostBattle:
	.string "BLUE: You've conquered\n"
	.string "all 8 Kanto Gyms!\p"
	.string "With the EARTH BADGE,\n"
	.string "Route 22 is open.\l"
	.string "Head for INDIGO PLATEAU!\p"
	.string "Brace yourself, {PLAYER}...\n"
	.string "The Champion at the summit\l"
	.string "is a legend: RED!$"

KantoStory_Text_ProceedToIndigo:
	.string "BLUE: Would you like to head to\n"
	.string "the INDIGO SUMMIT right away?$"

KantoStory_Text_IndigoWarpConfirm:
	.string "BLUE: Good luck, {PLAYER}!\n"
	.string "Show RED what you can do!$"

KantoStory_Text_RedSilence:
	.string "RED: ... ... ...\p"
	.string "... ... ...\p"
	.string "... ... ...!$"

KantoStory_Text_RedRematchPrompt:
	.string "RED: ... ... ...?\n"
	.string "(RED nods, ready to battle.)$"

KantoStory_Text_RedDefeat:
	.string "RED: ...!$"

KantoStory_Text_RedVictory:
	.string "RED: ... ... ...!\p"
	.string "(RED gives a gentle smile and\n"
	.string "nods in deep respect.)\p"
	.string "{PLAYER} is recognized as the\n"
	.string "CHAMPION OF TWO REALMS!$"

KantoStory_Text_RedConclusion:
	.string "RED: ... (RED steps aside,\n"
	.string "welcoming {PLAYER} to the\l"
	.string "Pantheon of Legends.)\p"
	.string "The bond between HOENN and\n"
	.string "KANTO shines forever!$"
