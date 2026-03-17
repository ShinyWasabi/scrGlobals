#pragma once
#include "../Types.hpp"
#include "SavedMPGlobals.hpp"

struct GLOBAL_BLOCK_MP_SAVE_GAME
{
    SAVED_MP_GLOBALS SavedMPGlobals; // 2359296
    scrValue PAD_005575[256569];
};
static_assert(SCR_SIZEOF(GLOBAL_BLOCK_MP_SAVE_GAME) == SCR_GLOBAL_BLOCK_SIZE);