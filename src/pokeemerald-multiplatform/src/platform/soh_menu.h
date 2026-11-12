#ifndef GUARD_SOH_MENU_H
#define GUARD_SOH_MENU_H

#include "global.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Ship of Harkinian Engine Cheats & Enhancements
extern bool8 gCheatWalkThroughWalls;
extern bool8 gCheat100PercentCatch;
extern bool8 gEnhanceInstantText;
extern bool8 gEnhanceAutoRun;

void Soh_Init(void *sdlWindow, void *sdlRenderer);
void Soh_ToggleMenuBar(void);
bool Soh_IsMenuBarVisible(void);
void Soh_SetSpeed(double scale);

#ifdef __cplusplus
}
#endif

#endif // GUARD_SOH_MENU_H
