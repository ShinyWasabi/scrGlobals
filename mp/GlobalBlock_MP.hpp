#pragma once
#include "../Types.hpp"
#include "DailyObjectivesState.hpp"
#include "MPSV.hpp"

struct GLOBAL_BLOCK_MP
{
    scrValue PAD_000000[1881];
    DAILY_OBJECTIVES_STATE DailyObjectivesState; // 1574745
    scrValue PAD_001886[9022];
    MPSV MPSVData; // 1583772
    scrValue PAD_097710[164434];
};
static_assert(SCR_SIZEOF(GLOBAL_BLOCK_MP) == SCR_GLOBAL_BLOCK_SIZE);