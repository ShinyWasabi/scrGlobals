#pragma once
#include "../Types.hpp"

struct GSBD_KICKING
{
    scrArray<32> KickedPlayers;
};
static_assert(SCR_SIZEOF(GSBD_KICKING) == 33);