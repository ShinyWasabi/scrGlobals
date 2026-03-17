#pragma once
#include "../Types.hpp"

struct FIXER_SEC_CONTRACT_DATA
{
    scrValue Type;       // 0
    scrValue Difficulty; // 1
    scrValue Reward;     // 2
};
static_assert(SCR_SIZEOF(FIXER_SEC_CONTRACT_DATA) == 3);

struct FIXER_FLOW_DATA
{
    scrValue FixerGeneralFlags;                             // 0
    scrValue FixerCompletedFlags;                           // 1
    scrValue PayphoneBonusKillMethod;                       // 2
    scrValue FixerStoryFlags;                               // 3
    scrValue PAD_0004;                                      // 4, added b889g9
    scrValue PAD_0005;                                      // 5, added b889g9
    scrValue FixerStoryStrand;                              // 6
    scrValue FixerStoryCooldown;                            // 7
    scrValue FixerFlags;                                    // 8
    scrValue FixerShortTrips;                               // 9
    scrValue FixerCount;                                    // 10
    scrArray<6> FixerSecContractCompleted;                  // 11
    scrValue FixerEarnings;                                 // 18
    scrArray<3, FIXER_SEC_CONTRACT_DATA> FixerSecContracts; // 19
};
static_assert(SCR_SIZEOF(FIXER_FLOW_DATA) == 29);

struct ULP_FLOW_DATA
{
    scrValue ULPMissionCurrent;  // 0
    scrValue ULPMissionProgress; // 1
};
static_assert(SCR_SIZEOF(ULP_FLOW_DATA) == 2);

struct XM22_FLOW_DATA
{
    scrValue XM22Missions; // 0
    scrValue XM22Current;  // 1
    scrValue XM22Flow;     // 2
};
static_assert(SCR_SIZEOF(XM22_FLOW_DATA) == 3);

struct SUM23_AVOP_FLOW_DATA
{
    scrValue SUM23AvopCurrent;  // 0
    scrValue SUM23AvopProgress; // 1
    scrArray<3> Difficulties;   // 2
    scrArray<3> Rewards;        // 6
    scrValue DifficultyFlags;   // 10
};
static_assert(SCR_SIZEOF(SUM23_AVOP_FLOW_DATA) == 11);

struct SALV23_VEHICLE_DATA
{
    scrValue SALV23VehRob;   // 0
    scrValue SALV23VehModel; // 1
    scrValue SALV23VehMods;  // 2
    scrValue SALV23CanKeep;  // 3
    scrValue SALV23SaleVal;  // 4
    scrValue PAD_0005;       // 5
    scrValue SALV23VehSlot;  // 6
    scrValue SALV23VehWeek;  // 7
    scrValue PackedInt42101; // 8
    scrValue SALV23Disrupt;  // 9
};
static_assert(SCR_SIZEOF(SALV23_VEHICLE_DATA) == 10);

struct SALV23_FLOW_DATA
{
    scrValue SALV23GenFlags;            // 0
    scrValue SALV23FMProg;              // 1
    scrValue SALV23InstProg;            // 2
    scrValue PackedInt42102;            // 3
    scrValue SALV23ScopeFlags;          // 4
    scrArray<7> SALV23CFRCounts;        // 5
    scrArray<7> SALV23CFRCrewCounts2;   // 13, added b889g9
    SALV23_VEHICLE_DATA SALV23Vehicles; // 21
    scrArray<3> SALV23VehRobStatus;     // 31
    scrValue SALV23Flags;               // 35
    scrValue UNK_0036;                  // 36
};
static_assert(SCR_SIZEOF(SALV23_FLOW_DATA) == 37);

struct BOUNTY24_STD_DATA
{
    scrValue TargMis; // 0
    scrValue TargTar; // 1
    scrValue TargRwd; // 2
};
static_assert(SCR_SIZEOF(BOUNTY24_STD_DATA) == 3);

struct BOUNTY24_FLOW_DATA
{
    scrValue UNK_0000;                  // 0
    scrArray<3, BOUNTY24_STD_DATA> STD; // 1
};
static_assert(SCR_SIZEOF(BOUNTY24_FLOW_DATA) == 11);

struct HACKER24_FLOW_DATA
{
    scrValue Hacker24GenFlags;  // 0
    scrValue Hacker24InstFlags; // 1
    scrValue Hacker24ActiveRob; // 2
    scrValue UNK_0003;          // 3
    scrValue Hacker24Flags;     // 4
    scrValue UNK_0005;          // 5
    scrValue PAD_0006[8];       // 6 (unused?)
    scrValue PackedBool51273;   // 14
    scrValue PackedBool51274;   // 15
    scrValue PackedBool51275;   // 16
};
static_assert(SCR_SIZEOF(HACKER24_FLOW_DATA) == 17);

struct DRUG25_FLOW_DATA
{
    scrValue PAD_0000;             // 0, unused
    scrArray<3> DrugMissions;      // 1
    scrValue LastMissionCompleted; // 6
};
static_assert(SCR_SIZEOF(DRUG25_FLOW_DATA) == 6);

struct M25_FLOW_DATA
{
    scrValue M25GeneralBs;         // 0
    scrValue M25Flags;             // 1
    scrValue M25AviMissionCurrent; // 2
};
static_assert(SCR_SIZEOF(M25_FLOW_DATA) == 3);

struct GPBD_FLOW_ENTRY
{
    scrValue TunerFlowFlags;            // 0
    scrValue TunerGenFlags;             // 1
    scrValue TunerMisFlags;             // 2
    scrValue TunerCompFlags;            // 3
    scrValue TunerCurrent;              // 4
    scrValue TunerCount;                // 5
    scrValue TunerEarnings;             // 6
    scrArray<3> TunerRobberies;         // 7
    scrValue TunerJammerFlags;          // 11
    scrValue TunerElevatorPassFlags;    // 12
    scrValue TunerMethTankerFlags;      // 13
    scrValue TunerBunkerFlags;          // 14
    scrValue TunerBunkerTruckFlags;     // 15
    scrArray<8> TunerContractPosixes;   // 16
    scrBitset<> TunerCBVDeliveredFlags; // 25
    scrValue TunerCBVState;             // 26
    FIXER_FLOW_DATA FixerFlow;          // 27
    scrValue HasFixerUsbCollected;      // 56
    ULP_FLOW_DATA ULPFlow;              // 57
    XM22_FLOW_DATA XM22Flow;            // 59
    SUM23_AVOP_FLOW_DATA SUM23AvopFlow; // 62
    SALV23_FLOW_DATA SALV23Flow;        // 73
    BOUNTY24_FLOW_DATA Bounty24Flow;    // 110
    HACKER24_FLOW_DATA Hacker24Flow;    // 121
    DRUG25_FLOW_DATA Drug25Flow;        // 138, added b889g9
    M25_FLOW_DATA M25Flow;              // 145, added b1013.17g9
    scrValue HeistFlags;                // 148, added b1013.17g9
    scrValue UNK_0149;                  // 149, unused, added b1013.17g9
};
static_assert(SCR_SIZEOF(GPBD_FLOW_ENTRY) == 149);

struct GPBD_FLOW
{
    scrArray<32, GPBD_FLOW_ENTRY> Entries; // 0
};
static_assert(SCR_SIZEOF(GPBD_FLOW) == 4769);