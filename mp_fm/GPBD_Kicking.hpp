#pragma once
#include "../Types.hpp"

struct GPBD_KICKING_ENTRY
{
    scrArray<32> KickVotes; // players you are voting to kick (array of bool)
    scrArray<32> KickWarningsShown;
    scrValue WillBeKickedSoon;
    scrArray<32> PlayersToBeKickedSoon;
};
static_assert(SCR_SIZEOF(GPBD_KICKING_ENTRY) == 100);

struct GPBD_KICKING
{
    scrArray<32, GPBD_KICKING_ENTRY> Entries;
};
static_assert(SCR_SIZEOF(GPBD_KICKING) == 3201);