#pragma once
#include "../Types.hpp"

enum class eRandomEvent
{
    DRUG_VEHICLE,
    MOVIE_PROPS,
    GOLDEN_GUN,
    VEHICLE_LIST,
    SLASHER,
    PHANTOM_CAR,
    SIGHTSEEING,
    SMUGGLER_TRAIL,
    CERBERUS,
    SMUGGLER_PLANE,
    CRIME_SCENE,
    METAL_DETECTOR,
    CONVOY,
    ROBBERY,
    XMAS_MUGGER,
    BANK_SHOOTOUT,
    ARMOURED_TRUCK,
    POSSESSED_ANIMALS,
    GHOSTHUNT,
    XMAS_TRUCK,
    COMMUNITY_OUTREACH,
    GETAWAY_DRIVER,
    SURVIVAL_GROUPING,
    VALENTINE_CHEATER,

    MAX_EVENTS
};

enum class eRandomEventInitState
{
    INITIALIZING,
    INITIALIZED
};

enum class eRandomEventState
{
    INACTIVE,
    AVAILABLE,
    ACTIVE,
    CLEANUP
};

enum class eRandomEventFlags
{
    TRIGGERED_BY_CLIENT,
    FORCE_LAUNCH,
    UNK_2, // unused
    FORCE_CLEANUP
};

struct RANDOM_EVENTS_RESERVATION_DATA
{
    scrValue ReservedPeds;     // 0
    scrValue ReservedVehicles; // 1
    scrValue ReservedObjects;  // 2
};
static_assert(SCR_SIZEOF(RANDOM_EVENTS_RESERVATION_DATA) == 3);

struct RANDOM_EVENTS_DATA
{
    scrEnum<eRandomEventState> State;                // 0
    TIMER TimerState;                                // 1
    scrArray<1, scrBitset<eRandomEventFlags>> Flags; // 3
    scrValue Variation;                              // 5
    scrValue Subvariation;                           // 6
    RANDOM_EVENTS_RESERVATION_DATA ReservationData;  // 7
    scrVector TriggerPosition;                       // 10
    scrValue TriggerRange;                           // 13
    scrValue Retries;                                // 14
};
static_assert(SCR_SIZEOF(RANDOM_EVENTS_DATA) == 15);

struct RANDOM_EVENTS_VEHICLE_LIST_DATA
{
    scrValue Index;     // 0
    scrValue Variation; // 1
};
static_assert(SCR_SIZEOF(RANDOM_EVENTS_VEHICLE_LIST_DATA) == 2);

struct RANDOM_EVENTS_TARGET_DATA
{
    scrValue PhantomCarTarget;        // 0
    scrValue XMASMuggerTarget;        // 1
    scrValue CommunityOutreachTarget; // 2
};
static_assert(SCR_SIZEOF(RANDOM_EVENTS_TARGET_DATA) == 3);

struct GSBD_RANDOM_EVENTS
{
    scrEnum<eRandomEventInitState> InitState;                                           // 0
    scrArray<static_cast<int>(eRandomEvent::MAX_EVENTS), RANDOM_EVENTS_DATA> EventData; // 1
    RANDOM_EVENTS_VEHICLE_LIST_DATA VehicleListData;                                    // 362
    RANDOM_EVENTS_TARGET_DATA TargetData;                                               // 364
};
static_assert(SCR_SIZEOF(GSBD_RANDOM_EVENTS) == 367);