#pragma once
#include "../Types.hpp"

struct GLOBAL_BLOCK_UGC
{
    scrValue PAD_000000[262144];
};
static_assert(SCR_SIZEOF(GLOBAL_BLOCK_UGC) == SCR_GLOBAL_BLOCK_SIZE);