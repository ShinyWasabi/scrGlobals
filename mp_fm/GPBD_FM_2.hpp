#pragma once
#include "../Types.hpp"
#include "GSBD_RandomEvents.hpp" // for eRandomEvent

enum class eRaceRoundType
{
    NOT_SELECTED = -1,
    FINISH_FIRST,
    MOST_POINTS,
    FASTEST_TIME
};

enum class eRaceFinalRoundType
{
    NOT_SELECTED,
    HEAD_TO_HEAD
};

enum class eRandomEventClientState
{
    INACTIVE,
    TRIGGERING, // This is different than the server available state
    ACTIVE,
    CLEANUP
};

enum class eRandomEventClientFlags
{
    FORCE_LAUNCH
};

enum class eRandomEventClientInitState
{
    INITIALIZING,
    INITIALIZED
};

struct GANGOPS_DATA
{
    scrValue UNK_0000;                     // 0
    scrArray<4> PlayerIndexes;             // 1
    scrArray<4> PlayerRoles;               // 6
    scrArray<4> ArePlayersReady;           // 11
    scrArray<5> PlayerCuts;                // 16
    scrValue HighlightedPlayer;            // 22
    scrValue GangopsFlowMissionProgFlags;  // 23
    scrValue GangopsFMMissionProgFlags;    // 24
    scrValue GangopsFMMissionSkipFlags;    // 25
    scrValue GangopsHeistStatusFlags;      // 26
    scrValue Flags;                        // 27
    scrValue IsPlanningScreenReady;        // 28
    scrValue QuittedPlanningScreen;        // 29
    scrValue IsTutorialActive;             // 30
    scrArray<4> IsTutorialActiveForPlayer; // 31
    TIMER FinaleForceLaunchTimer;          // 36 (H2_FINALE_FORCE_LAUNCH_TIME)
    scrValue IsFinaleForceLaunched;        // 38 (if players don't click ready in 3 minutes)
};
static_assert(SCR_SIZEOF(GANGOPS_DATA) == 39);

struct RANDOM_EVENTS_CLIENT_EVENT_DATA
{
    scrEnum<eRandomEventClientState> State;              // 0
    scrArray<1, scrEnum<eRandomEventClientFlags>> Flags; // 1
};
static_assert(SCR_SIZEOF(RANDOM_EVENTS_CLIENT_EVENT_DATA) == 3);

struct RANDOM_EVENTS_CLIENT_DATA
{
    alignas(8) eRandomEventClientInitState InitState;                                                // 0
    scrArray<static_cast<int>(eRandomEvent::MAX_EVENTS), RANDOM_EVENTS_CLIENT_EVENT_DATA> EventData; // 1
    scrBitset<> IsParticipantInEventFlags;                                                           // 75
    scrValue UNK_0076;                                                                               // 76 (unused)
};
static_assert(SCR_SIZEOF(RANDOM_EVENTS_CLIENT_DATA) == 76);

struct HOCW_DATA
{
    scrValue PAD_0000[2];
    scrValue SafeCashValue; // 2
    scrValue PAD_0003[13];
};
static_assert(SCR_SIZEOF(HOCW_DATA) == 16);

struct SALVAGE_YARD_VEHICLE_SALE_DATA
{
    scrValue PAD_0000[27];
    HOCW_DATA HOWCData; // 27
    scrValue PAD_0043[9];
};
static_assert(SCR_SIZEOF(SALVAGE_YARD_VEHICLE_SALE_DATA) == 52);

struct GPBD_FM_2_ENTRY
{
    scrValue NumTeams;                                // 0
    scrValue NumRounds;                               // 1
    scrValue RoundsPlayed;                            // 2
    scrValue RoundScore;                              // 3
    scrValue CurrentTeam;                             // 4
    scrValue Flags;                                   // 5
    scrValue TotalScore;                              // 6
    scrValue TotalKills;                              // 7
    scrValue TotalDeaths;                             // 8
    scrValue RPEarned;                                // 9
    scrValue CashEarned;                              // 10
    scrValue PAD_0011[2];                             // 11
    scrValue APEarned;                                // 13
    scrValue Duration;                                // 14
    scrEnum<eRaceRoundType> RaceRoundType;            // 15
    scrEnum<eRaceFinalRoundType> RaceFinalRoundType;  // 16
    scrValue Flags2;                                  // 17
    scrValue Vote;                                    // 18
    scrValue NumVotes;                                // 19
    scrValue MaxVotes;                                // 20
    scrValue PlayerTeam;                              // 21
    scrValue PAD_0022[8];                             // 22 (mission stuff)
    scrValue TunableCloudCRC;                         // 30
    scrValue CatalogCloudCRC;                         // 31
    scrValue UNK_0032;                                // 32
    scrValue Flags3;                                  // 33
    scrValue UNK_0034;                                // 34
    scrValue HasVoted;                                // 35
    TIMER UNK_0036;                                   // 36
    TIMER UNK_0038;                                   // 38
    scrVector CoronaPosition;                         // 40
    GANGOPS_DATA GangopsData;                         // 43
    RANDOM_EVENTS_CLIENT_DATA RandomEventsClientData; // 82
    SALVAGE_YARD_VEHICLE_SALE_DATA SYVehSaleData;     // 158 added b889g9
    scrValue PAD_0210[105];
};
static_assert(SCR_SIZEOF(GPBD_FM_2_ENTRY) == 315);

struct GPBD_FM_2
{
    scrArray<32, GPBD_FM_2_ENTRY> Entries;
};
static_assert(SCR_SIZEOF(GPBD_FM_2) == 10081);