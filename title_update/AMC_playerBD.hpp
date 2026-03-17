#pragma once
#include "../Types.hpp"
#include "../Shared.hpp"

struct AMC_PLAYER_BD_ENTRY
{
    scrArray<NUM_CONTACTS, TIMER> UsedContactServicesTimer; // only index 2 (mugger) is actually used by the scripts. the rest is just a waste of bandwidth
    scrArray<NUM_CONTACTS> ContactServiceCooldowns;         // same as above
};
static_assert(SCR_SIZEOF(AMC_PLAYER_BD_ENTRY) == 260); // -> 251 in b812g9

struct AMC_PLAYER_BD
{
    scrArray<32, AMC_PLAYER_BD_ENTRY> Entries;
};
static_assert(SCR_SIZEOF(AMC_PLAYER_BD) == 8321);