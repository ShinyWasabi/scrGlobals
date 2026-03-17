#pragma once
#include "../Types.hpp"
#include "GSBD_BlockB.hpp" // for DELIVERABLE_ID

enum class eDealerPremiumProducts
{
    COKE = 2,
    METH = 3,
    WEED = 4,
    ACID = 7
};

struct STREET_DEALER_DATA
{
    scrValue Location;                              // 0
    scrEnum<eDealerPremiumProducts> PremiumProduct; // 1 (https://github.com/ShinyWasabi/GTAO-Bot/blob/8394e090afa584938c8e9a63a55b22e2803a51e0/src/modules/street_dealers.js#L76)
    scrValue CokePrice;                             // 2
    scrValue MethPrice;                             // 3
    scrValue WeedPrice;                             // 4
    scrValue AcidPrice;                             // 5
    scrValue UNK_0006;                              // 6
};
static_assert(SCR_SIZEOF(STREET_DEALER_DATA) == 7);

struct STREET_DEALERS
{
    scrArray<3, STREET_DEALER_DATA> Dealers; // 0
    scrValue ClosestDealerLocation;          // 22
    scrValue ClosetsDealerIndex;             // 23
};
static_assert(SCR_SIZEOF(STREET_DEALERS) == 24);

struct DAILY_RESET_DATA
{
    TIMER Timer;              // 0
    scrValue ResetDurationMs; // 1 (86400000ms = 24 hours)
    scrValue Seed;            // 2
};
static_assert(SCR_SIZEOF(DAILY_RESET_DATA) == 4);

struct FREEMODE_DELIVERIES // too many structs with similar name
{
    scrValue Flags;             // 0
    scrValue TransactionStatus; // 1
    scrValue Blip;              // 2
    scrValue Type;              // 3 (this seems to be the same as DeliverableHash, at least for exotic exports)
    scrValue FMMCType;          // 4
    DELIVERABLE_ID Id;          // 5
    GAMER_HANDLE GamerHandle;   // 7
    TIMER Timer;                // 20
    scrValue DeliverableHash;   // 22
    scrValue Refresh;           // 23 (needs more testing)
};
static_assert(SCR_SIZEOF(FREEMODE_DELIVERIES) == 24);

struct FREEMODE_GENERAL
{
    scrValue PAD_0000[301];
    scrValue PersonalVehicleIndex; // 301
    scrValue PAD_0302[273];
    scrValue PersonalVehicleRequested; // 575
    scrValue PAD_0576[14];
    scrValue NodeDistanceCheck; // 590
    scrValue PAD_0591[48];
    scrValue RequestedPersonalVehicleId; // 639
    scrValue PAD_0640[2];
    scrValue Exec1Impound; // 642
    scrValue PAD_0643[4992];
    STREET_DEALERS StreetDealers; // 5635
    scrValue PAD_5659[107];
    DAILY_RESET_DATA DailyReset;    // 5766
    FREEMODE_DELIVERIES Deliveries; // 5770
    scrValue PAD_5794[280];
};
static_assert(SCR_SIZEOF(FREEMODE_GENERAL) == 6074);