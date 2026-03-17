#pragma once
#include "../Types.hpp"

struct GPBD_MISSION_NAME
{
    scrArray<32, scrTextLabel63> MissionNames;
};
static_assert(SCR_SIZEOF(GPBD_MISSION_NAME) == 513);