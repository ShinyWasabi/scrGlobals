#pragma once
#include "../Types.hpp"

struct DAILY_OBJECTIVES_STATE
{
    scrValue Completed;    // 0
    scrArray<3> Objective; // 1
};
static_assert(SCR_SIZEOF(DAILY_OBJECTIVES_STATE) == 5);