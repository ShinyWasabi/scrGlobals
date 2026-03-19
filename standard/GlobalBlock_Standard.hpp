#pragma once
#include "../Types.hpp"
#include "SavedGlobals.hpp"

struct GLOBAL_BLOCK_STANDARD
{
    scrValue PAD_000000[114930];
    SAVED_GLOBALS SavedGlobals; // 114931
};
// static_assert(SCR_SIZEOF(GLOBAL_BLOCK_STANDARD) == SCR_GLOBAL_BLOCK_SIZE);