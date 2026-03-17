#pragma once
#include "../Types.hpp"
#include "FreemodeDeliveryData.hpp"
#include "GPBD_FM.hpp"
#include "GPBD_FM_2.hpp"
#include "GPBD_FM_3.hpp"
#include "GPBD_Flow.hpp"
#include "GPBD_Kicking.hpp"
#include "GPBD_MissionName.hpp"
#include "GSBD_FM.hpp"
#include "GSBD_FM_Events.hpp"
#include "GSBD_Kicking.hpp"
#include "GSBD_PropertyInstances.hpp"
#include "GSBD_RandomEvents.hpp"

struct GLOBAL_BLOCK_MP_FM
{
    scrValue PAD_000000[551];
    GSBD_FM GSBD_Freemode; // 1835559
    scrValue PAD_001204[9087];
    GPBD_FM GPBD_Freemode;              // 1845299
    GPBD_MISSION_NAME GPBD_MissionName; // 1873556
    GPBD_KICKING GPBD_Kicking;          // 1874069
    GSBD_KICKING GSBD_Kicking;          // 1877270
    scrValue PAD_042295[4962];
    GSBD_RANDOM_EVENTS GSBD_RandomEvents; // 1882265
    scrValue PAD_047624[85];
    GPBD_FM_2 GPBD_Freemode_2; // 1882717
    GPBD_FM_3 GPBD_Freemode_3; // 1892798
    scrValue PAD_077471[10271];
    GSBD_FM_EVENTS GSBD_FM_Events; // 1922750
    scrValue PAD_088270[20641];
    GSBD_PROPERTY_INSTANCES GSBD_PropertyInstances; // 1943919
    scrValue PAD_109375[13019];
    FREEMODE_DELIVERY_DATA FreemodeDeliveryData; // 1957402
    scrValue PAD_128699[20754];
    GPBD_FLOW GPBD_Flow; // 1984461
    scrValue PAD_154222[107922];
};
static_assert(SCR_SIZEOF(GLOBAL_BLOCK_MP_FM) == SCR_GLOBAL_BLOCK_SIZE);