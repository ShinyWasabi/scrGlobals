#pragma once
#include "../Types.hpp"
#include "Tunables.hpp"
#include "TunablesGroupModifier.hpp"

struct GLOBAL_BLOCK_TUNABLES
{
    scrValue RefreshTunables;                      // 262144
    TUNABLES Tunables;                             // 262145
    TUNABLES_GROUP_MODIFIER TunablesGroupModifier; // 300131
    scrValue ShouldRunNetTunableCheck;             // 300178 (determines whether net_tunable_check should run, though this script is unused)
    scrValue AreTunablesInitialized;               // 300179
    scrValue AreTunablesInitialized2;              // 300180 (only used once in freemode for something related to car meet prize vehicle)
    scrValue PAD_038037[224107];
};
static_assert(SCR_SIZEOF(GLOBAL_BLOCK_TUNABLES) == SCR_GLOBAL_BLOCK_SIZE);