#pragma once
#include "../Types.hpp"
#include "AMC_playerBD.hpp"
#include "FreemodeGeneral.hpp"
#include "GSBD.hpp"
#include "GSBD_BlockB.hpp"
#include "GlobalPlayerBD.hpp"
#include "LauncherServerData.hpp"
#include "WeeklyChallenge.hpp"

struct GLOBAL_BLOCK_TITLE_UPDATE
{
    scrValue PAD_000000[27722];
    GSBD GSBD;               // 2649162
    GSBD_BlockB GSBD_BlockB; // 2650426
    scrValue PAD_031142[5712];
    GLOBAL_PLAYER_BD GlobalPlayerBD; // 2658294
    scrValue PAD_051831[26731];
    LAUNCHER_SERVER_DATA LauncherServerData; // 2700002
    AMC_PLAYER_BD AMC_playerBD;              // 2700188
    scrValue PAD_087069[23560];
    WEEKLY_CHALLENGE WeeklyChallenge; // 2732069
    scrValue PAD_110637[1061];
    FREEMODE_GENERAL FreemodeGeneral; // 2733138
    scrValue PAD_117772[144372];
};
static_assert(SCR_SIZEOF(GLOBAL_BLOCK_TITLE_UPDATE) == SCR_GLOBAL_BLOCK_SIZE);