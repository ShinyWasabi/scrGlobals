#pragma once
#include "../Types.hpp"

struct GLOBAL_BLOCK_TUNABLES
{
    scrValue PAD_000000[262144];
};
static_assert(SCR_SIZEOF(GLOBAL_BLOCK_TUNABLES) == SCR_GLOBAL_BLOCK_SIZE);