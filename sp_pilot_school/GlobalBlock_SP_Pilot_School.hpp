#pragma once
#include "../Types.hpp"

struct GLOBAL_BLOCK_SP_PILOT_SCHOOL
{
    scrValue PilotSchoolDummyData; // 3145728
    scrValue PAD_000001[262143];
};
static_assert(SCR_SIZEOF(GLOBAL_BLOCK_SP_PILOT_SCHOOL) == SCR_GLOBAL_BLOCK_SIZE);