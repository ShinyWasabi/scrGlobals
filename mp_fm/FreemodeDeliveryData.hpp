#pragma once
#include "../Types.hpp"
#include "../Shared.hpp"

struct DELIVERY_POS_DATA
{
    scrVector DeliveryPosition1; // 0
    scrVector DeliveryPosition2; // 3
};
static_assert(SCR_SIZEOF(DELIVERY_POS_DATA) == 6);

struct FREEMODE_DELIVERY_DATA
{
    scrValue DeliveryFlags;                            // 0
    scrArray<1008, DELIVERY_POS_DATA> DeliveryPosData; // 1
    scrValue DeliveryInVehicle;                        // 6050
    scrValue DeliveryNotInVehicle;                     // 6051
    TIMER DeliveryCooldown1;                           // 6052
    scrValue CooldownFrameCount1;                      // 6054
    TIMER DeliveryCooldown2;                           // 6055
    scrValue CooldownFrameCount2;                      // 6057
    scrValue PAD_6058[247];
};
static_assert(SCR_SIZEOF(FREEMODE_DELIVERY_DATA) == 6305);