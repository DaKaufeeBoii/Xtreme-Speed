EventScript_RepelWoreOff::
	lockall
	checkitem ITEM_REPEL, 1
	goto_if_eq VAR_RESULT, TRUE, EventScript_RepelWoreOff_HasRepel
	checkitem ITEM_SUPER_REPEL, 1
	goto_if_eq VAR_RESULT, TRUE, EventScript_RepelWoreOff_HasSuperRepel
	checkitem ITEM_MAX_REPEL, 1
	goto_if_eq VAR_RESULT, TRUE, EventScript_RepelWoreOff_HasMaxRepel
	msgbox Text_RepelWoreOff, MSGBOX_SIGN
	releaseall
	end

EventScript_RepelWoreOff_HasRepel::
	msgbox Text_RepelWoreOff_Prompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_RepelWoreOff_Decline
	removeitem ITEM_REPEL, 1
	setvar VAR_REPEL_STEP_COUNT, 100
	playse SE_REPEL
	msgbox Text_UsedAnotherRepel, MSGBOX_SIGN
	releaseall
	end

EventScript_RepelWoreOff_HasSuperRepel::
	msgbox Text_SuperRepelWoreOff_Prompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_RepelWoreOff_Decline
	removeitem ITEM_SUPER_REPEL, 1
	setvar VAR_REPEL_STEP_COUNT, 200
	playse SE_REPEL
	msgbox Text_UsedAnotherSuperRepel, MSGBOX_SIGN
	releaseall
	end

EventScript_RepelWoreOff_HasMaxRepel::
	msgbox Text_MaxRepelWoreOff_Prompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_RepelWoreOff_Decline
	removeitem ITEM_MAX_REPEL, 1
	setvar VAR_REPEL_STEP_COUNT, 250
	playse SE_REPEL
	msgbox Text_UsedAnotherMaxRepel, MSGBOX_SIGN
	releaseall
	end

EventScript_RepelWoreOff_Decline::
	releaseall
	end

Text_RepelWoreOff:
	.string "REPEL's effect wore off…$"

Text_RepelWoreOff_Prompt:
	.string "REPEL's effect wore off…\nUse another REPEL?$"

Text_SuperRepelWoreOff_Prompt:
	.string "SUPER REPEL's effect wore off…\nUse another SUPER REPEL?$"

Text_MaxRepelWoreOff_Prompt:
	.string "MAX REPEL's effect wore off…\nUse another MAX REPEL?$"

Text_UsedAnotherRepel:
	.string "{PLAYER} used a REPEL.$"

Text_UsedAnotherSuperRepel:
	.string "{PLAYER} used a SUPER REPEL.$"

Text_UsedAnotherMaxRepel:
	.string "{PLAYER} used a MAX REPEL.$"
