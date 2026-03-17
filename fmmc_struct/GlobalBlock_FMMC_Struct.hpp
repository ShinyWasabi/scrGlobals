#pragma once
#include "../Types.hpp"

struct GLOBAL_BLOCK_FMMC_STRUCT
{
    scrValue PAD_000000[262144];
};
static_assert(SCR_SIZEOF(GLOBAL_BLOCK_FMMC_STRUCT) == SCR_GLOBAL_BLOCK_SIZE);