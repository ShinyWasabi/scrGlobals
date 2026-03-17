#pragma once
#include "../Types.hpp"

struct WEEKLY_CHALLENGE_ENTRY
{
    scrValue ObjectiveId;            // 0
    scrValue CurrentObjective;       // 1
    scrValue ObjectiveCountOverride; // 2
    scrValue ObjectiveNotified;      // 3
    scrValue ObjectiveRewarded;      // 4
    scrValue UNK_0005;               // 5 (is this even actually used?)
};
static_assert(SCR_SIZEOF(WEEKLY_CHALLENGE_ENTRY) == 6);

struct WEEKLY_CHALLENGE
{
    scrArray<1, WEEKLY_CHALLENGE_ENTRY> Entries; // 0
    scrValue DateObjectiveSet;                   // 7
};
static_assert(SCR_SIZEOF(WEEKLY_CHALLENGE) == 8);