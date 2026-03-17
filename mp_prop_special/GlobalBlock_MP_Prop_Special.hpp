#pragma once
#include "../Types.hpp"

struct GLOBAL_BLOCK_MP_PROP_SPECIAL
{
    scrValue PAD_000000[262144];
};
static_assert(SCR_SIZEOF(GLOBAL_BLOCK_MP_PROP_SPECIAL) == SCR_GLOBAL_BLOCK_SIZE);