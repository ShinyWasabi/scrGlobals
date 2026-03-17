#pragma once
#include "../Types.hpp"

enum class eHostScriptState
{
    INITIALIZING,
    RUNNING,
    PREPARING_TO_SHUT_DOWN,
    SHUTTING_DOWN
};

enum class eLauncherFlags
{
    RUN_IMMEDIATELY = 1
};

enum class eLauncherState
{
    EMPTY,
    FIND_SCRIPT,
    UNK_2, // unused
    PICK_MISSION_VARIATION,
    UNK_4,
    WAIT_FOR_ACK,
    START_SCRIPT,
    WAIT_FOR_TERMINATION,
    RESET
};

struct LAUNCHER_SCRIPT
{
    scrValue EventIndex;
    scrValue LauncherIndex; // this is the script index we want to set
    scrValue Probability;
    scrValue PAD_0003; // unused
    scrValue Terminated;
};
static_assert(SCR_SIZEOF(LAUNCHER_SCRIPT) == 5);

struct LAUNCHER_SERVER_DATA
{
    alignas(8) eHostScriptState HostState;
    scrBitset<eLauncherFlags> Flags;
    alignas(8) eLauncherState LauncherState;
    LAUNCHER_SCRIPT CurrentScript;
    scrArray<21, LAUNCHER_SCRIPT> QueuedScripts;
    scrArray<21> QueuedEvents;
    scrValue PAD_0136[41]; // unused
    TIMER CrateDropTimer;
    TIMER ScriptLaunchTimer;
    scrValue TimeToWaitForLaunch;
    scrValue CurrentEvent;
    scrValue ScriptParam1;
    scrValue ScriptParam2;
    scrValue ScriptParam3;
};
static_assert(SCR_SIZEOF(LAUNCHER_SERVER_DATA) == 186);