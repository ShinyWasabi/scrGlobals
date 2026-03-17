#include "Globals.hpp"
#include "fmmc_struct/GlobalBlock_FMMC_Struct.hpp"
#include "fmmc_struct2/GlobalBlock_FMMC_Struct2.hpp"
#include "fmmc_struct3/GlobalBlock_FMMC_Struct3.hpp"
#include "mp/GlobalBlock_MP.hpp"
#include "mp_fm/GlobalBlock_MP_FM.hpp"
#include "mp_prop/GlobalBlock_MP_Prop.hpp"
#include "mp_prop_special/GlobalBlock_MP_Prop_Special.hpp"
#include "mp_save_game/GlobalBlock_MP_Save_Game.hpp"
#include "profiler/GlobalBlock_Profiler.hpp"
#include "sc_lb/GlobalBlock_SC_LB.hpp"
#include "sp_dlc/GlobalBlock_SP_DLC.hpp"
#include "sp_pilot_school/GlobalBlock_SP_Pilot_School.hpp"
#include "standard/GlobalBlock_Standard.hpp"
#include "title_update/GlobalBlock_Title_Update.hpp"
#include "title_update_2/GlobalBlock_Title_Update_2.hpp"
#include "tunables/GlobalBlock_Tunables.hpp"
#include "ugc/GlobalBlock_UGC.hpp"
#include "ugc_2/GlobalBlock_UGC_2.hpp"

#define DEFINE_GLOBAL_BLOCK_ACCESSOR(type, name, block)    \
    type* SCR_GLOBALS::name()                              \
    {                                                      \
        return reinterpret_cast<type*>(scrGlobals[block]); \
    }

DEFINE_GLOBAL_BLOCK_ACCESSOR(GLOBAL_BLOCK_STANDARD, GetGlobalBlock_Standard, 0);
DEFINE_GLOBAL_BLOCK_ACCESSOR(GLOBAL_BLOCK_TUNABLES, GetGlobalBlock_Tunables, 1);
DEFINE_GLOBAL_BLOCK_ACCESSOR(GLOBAL_BLOCK_PROFILER, GetGlobalBlock_Profiler, 2);
DEFINE_GLOBAL_BLOCK_ACCESSOR(GLOBAL_BLOCK_UGC, GetGlobalBlock_UGC, 3);
DEFINE_GLOBAL_BLOCK_ACCESSOR(GLOBAL_BLOCK_UGC_2, GetGlobalBlock_UGC_2, 4);
DEFINE_GLOBAL_BLOCK_ACCESSOR(GLOBAL_BLOCK_MP_PROP, GetGlobalBlock_MP_Prop, 5);
DEFINE_GLOBAL_BLOCK_ACCESSOR(GLOBAL_BLOCK_MP, GetGlobalBlock_MP, 6);
DEFINE_GLOBAL_BLOCK_ACCESSOR(GLOBAL_BLOCK_MP_FM, GetGlobalBlock_MP_FM, 7);
DEFINE_GLOBAL_BLOCK_ACCESSOR(GLOBAL_BLOCK_SC_LB, GetGlobalBlock_SC_LB, 8);
DEFINE_GLOBAL_BLOCK_ACCESSOR(GLOBAL_BLOCK_MP_SAVE_GAME, GetGlobalBlock_MP_Save_Game, 9);
DEFINE_GLOBAL_BLOCK_ACCESSOR(GLOBAL_BLOCK_TITLE_UPDATE, GetGlobalBlock_Title_Update, 10);
DEFINE_GLOBAL_BLOCK_ACCESSOR(GLOBAL_BLOCK_SP_DLC, GetGlobalBlock_SP_DLC, 11);
DEFINE_GLOBAL_BLOCK_ACCESSOR(GLOBAL_BLOCK_SP_PILOT_SCHOOL, GetGlobalBlock_SP_Pilot_School, 12);
DEFINE_GLOBAL_BLOCK_ACCESSOR(GLOBAL_BLOCK_MP_PROP_SPECIAL, GetGlobalBlock_MP_Prop_Special, 16);
DEFINE_GLOBAL_BLOCK_ACCESSOR(GLOBAL_BLOCK_TITLE_UPDATE_2, GetGlobalBlock_Title_Update_2, 17);
DEFINE_GLOBAL_BLOCK_ACCESSOR(GLOBAL_BLOCK_FMMC_STRUCT, GetGlobalBlock_FMMC_Struct, 18);
DEFINE_GLOBAL_BLOCK_ACCESSOR(GLOBAL_BLOCK_FMMC_STRUCT2, GetGlobalBlock_FMMC_Struct2, 19);
DEFINE_GLOBAL_BLOCK_ACCESSOR(GLOBAL_BLOCK_FMMC_STRUCT3, GetGlobalBlock_FMMC_Struct3, 20);