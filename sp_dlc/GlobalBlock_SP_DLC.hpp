#pragma once
#include "../Types.hpp"

struct GLOBAL_BLOCK_SP_DLC
{
    scrValue LastSPMissionAfterCleanup; // 2883584 (flow_controller, PLAYER::GET_CAUSE_OF_MOST_RECENT_FORCE_CLEANUP() == 2)
    scrValue ShouldLoadAdditionalTexts; // 2883585
    scrValue LoadAdditionalTexts;       // 2883586 (gets set by ShouldLoadAdditionalTexts, loads text slot 6 and 7 in dialogue_handler)
    scrValue CurShopPedOutfitLocate;    // 2883587 (EXTRAMETADATA::GET_SHOP_PED_OUTFIT_LOCATE(iVar103.f_1))
    scrValue LastComponentHash;         // 2883588
    scrValue LastLockHash;              // 2883589 (CU_VAL_CLOTHES, CU_INDI_CLOTHES, CU_LOW_CLOTHES, etc.)
    scrValue PAD_000006;                // 2883590 (unused)
    scrArray<100> UnkFlags;             // 2883591 (flag 2 calls STREAMING::SET_SRL_FORCE_PRESTREAM(1))
    scrValue FakeSavedInt;              // 2883692 (MISC::REGISTER_INT_TO_SAVE(&Global_2883692, "aFakeSavedInt"))
    scrValue IsNormanDLCActive;         // 2883693 (cut content, referenced in scripts with SCRIPT::GET_NUMBER_OF_THREADS_RUNNING_THE_SCRIPT_WITH_THIS_HASH(joaat("MISSION_STAT_WATCHNRM")) > 0)
    scrValue IsCliffordDLCActive;       // 2883694 (cut content, referenced in scripts with SCRIPT::GET_NUMBER_OF_THREADS_RUNNING_THE_SCRIPT_WITH_THIS_HASH(joaat("MISSION_STAT_WATCHCLF")) > 0)
    scrValue PAD_000111[426];           // 111-536 unused
    scrValue PAD_000537[261607];
};
static_assert(SCR_SIZEOF(GLOBAL_BLOCK_SP_DLC) == SCR_GLOBAL_BLOCK_SIZE);