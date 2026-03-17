#pragma once
#include "../Types.hpp"

// this is why your apartment generally takes years to load
struct GSBD_PROPERTY_INSTANCES
{
    scrArray<32, GAMER_HANDLE> PropertyOwners;
    scrValue PAD_0417[14]; // unused
    scrArray<32> PropertyOwnerInstances;
};
static_assert(SCR_SIZEOF(GSBD_PROPERTY_INSTANCES) == 464);