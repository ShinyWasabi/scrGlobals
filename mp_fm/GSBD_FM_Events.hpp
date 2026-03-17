#pragma once
#include "../Types.hpp"

// TODO
struct GSBD_FM_EVENTS
{
    scrValue PAD_0000[8];
    scrValue AntiReplayValue1;
    scrValue AntiReplayValue2;
    scrValue PAD_0011[518];
};
static_assert(SCR_SIZEOF(GSBD_FM_EVENTS) == 528);