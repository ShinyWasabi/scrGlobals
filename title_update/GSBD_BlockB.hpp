#pragma once
#include "../Types.hpp"

enum class eDeliverableState
{
    INVALID = -1,
    INITIAL,
    DELIVERED
};

struct PLAYER_MISSION_INFO
{
    scrValue State;
    scrValue Index; // GSBD_MissionRequest index
};
static_assert(SCR_SIZEOF(PLAYER_MISSION_INFO) == 2);

struct CRATE_DROP
{
    scrValue PAD_0000;         // unused
    scrValue EnableCrateDrops; // tries to trigger strange last gen stuff unsuccessfully
    scrValue PAD_0003[2];      // unused
};
static_assert(SCR_SIZEOF(CRATE_DROP) == 4);

struct DELIVERABLE_ID
{
    scrValue Owner;
    scrValue Id; // "FMDeliverableID"
};
static_assert(SCR_SIZEOF(DELIVERABLE_ID) == 2);

struct DELIVERABLE_SCRIPT_INFO
{
    scrValue Hash;
    scrValue PAD_0001[2]; // unused
};
static_assert(SCR_SIZEOF(DELIVERABLE_SCRIPT_INFO) == 3);

struct UNK_0962
{
    scrValue PAD_0000;
    scrArray<18> PAD_0001;
    scrArray<18, DELIVERABLE_SCRIPT_INFO> PAD_0020;
};
static_assert(SCR_SIZEOF(UNK_0962) == 75);

struct DELIVERABLE
{
    scrEnum<eDeliverableState> State;
    DELIVERABLE_ID DeliverableId;
    scrValue Type;
    scrValue PAD_0004;               // this is always set to zero
    scrArray<5> DroppedOffLocations; // "activeDropOff is not the same as sctiptDropOff"
    DELIVERABLE_SCRIPT_INFO ScriptInfo;
    scrValue NumDropOffs;
};
static_assert(SCR_SIZEOF(DELIVERABLE) == 15);

// "FREEMODE_DELIVERY_SERVER_ADD_DELIVERABLE_ID" "_FREEMODE_DELIVERY_MAINTAIN_SERVER"
struct FREEMODE_DELIVERY
{
    scrValue Initialized;
    scrArray<64, DELIVERABLE> Deliverables;
    scrArray<10, UNK_0962> PAD_0962; // TODO
};
static_assert(SCR_SIZEOF(FREEMODE_DELIVERY) == 1713);

struct GLOBAL_CLUB_INFO
{
    scrValue PAD_0000[16];
};
static_assert(SCR_SIZEOF(GLOBAL_CLUB_INFO) == 16);

struct GSBD_BlockB
{
    scrValue MissionLauncherInitializedBitset;
    scrValue ScriptHost;
    scrValue PAD_0002;
    scrValue PAD_0003; // forces a team update thingy
    scrArray<32, PLAYER_MISSION_INFO> PlayerMissionInfos;
    scrValue HostMigrationCounter;
    scrValue PAD_0080[14]; // unused
    CRATE_DROP CrateDrop;
    scrValue PAD_0088[6];  // unused
    scrValue PAD_0094[33]; // ???
    scrValue PAD_0127[65]; // even more strange stuff (cut content?)
    scrArray<6> TurretCooldownTimers;
    FREEMODE_DELIVERY FreemodeDelivery;
    scrArray<3, GLOBAL_CLUB_INFO> GlobalClubInfos;
    scrArray<32> CarMeetModShopSlotIndices;
    scrArray<32> CarMeetModShopOccupiedGoons;
    scrArray<32, scrArray<3>> CarMeetModShopOccupiedVehicleSlots;
};
static_assert(SCR_SIZEOF(GSBD_BlockB) == 2156);