#pragma once
#include "../Types.hpp"

struct GLOBAL_BLOCK_SP_DLC
{
    scrValue PAD_000000[262144];
};
static_assert(SCR_SIZEOF(GLOBAL_BLOCK_SP_DLC) == SCR_GLOBAL_BLOCK_SIZE);