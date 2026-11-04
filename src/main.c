#include "modding.h"
#include "ultra64.h"
#include "recompconfig.h"
#include "recompdata.h"
#include "recompui.h"
#include "recompui_event_structs.h"
#include "rt64_extended_gbi.h"
#include "enums.h"
#include "common_structs.h"

extern void (*action_initiation_function_list[])(void);
void func_global_asm_806EE700(void);
extern Actor *gPlayerPointer;
void func_global_asm_806291B4(u8 arg0);

RECOMP_CALLBACK("*", recomp_on_init)
void fastWarpInit(void) {
    action_initiation_function_list[28] = func_global_asm_806EE700;
}

RECOMP_CALLBACK("*", dk64recomp_every_frame)
void fastWarpEveryFrame(void) {
    PlayerAdditionalActorData *PaaD;
    if (gPlayerPointer) {
        if (gPlayerPointer->control_state == 0x54) {
            if (gPlayerPointer->control_state_progress == 2) {
                func_global_asm_806291B4(3);
            }
            // Prevent shockwave making you small forever
            PaaD = gPlayerPointer->PaaD;
            if ((PaaD->unkC8 >= 0) && (PaaD->unkC8 < 5)) {
                PaaD->unkC8++;
                if (PaaD->unkC8 < 2) {
                    PaaD->unkC8++;
                }
            }
        }
    }
}