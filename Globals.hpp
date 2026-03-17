#pragma once

struct GLOBAL_BLOCK_STANDARD;
struct GLOBAL_BLOCK_TUNABLES;
struct GLOBAL_BLOCK_PROFILER;
struct GLOBAL_BLOCK_UGC;
struct GLOBAL_BLOCK_UGC_2;
struct GLOBAL_BLOCK_MP_PROP;
struct GLOBAL_BLOCK_MP;
struct GLOBAL_BLOCK_MP_FM;
struct GLOBAL_BLOCK_SC_LB;
struct GLOBAL_BLOCK_MP_SAVE_GAME;
struct GLOBAL_BLOCK_TITLE_UPDATE;
struct GLOBAL_BLOCK_SP_DLC;
struct GLOBAL_BLOCK_SP_PILOT_SCHOOL;
struct GLOBAL_BLOCK_MP_PROP_SPECIAL;
struct GLOBAL_BLOCK_TITLE_UPDATE_2;
struct GLOBAL_BLOCK_FMMC_STRUCT;
struct GLOBAL_BLOCK_FMMC_STRUCT2;
struct GLOBAL_BLOCK_FMMC_STRUCT3;

struct SCR_GLOBALS
{
public:
    static void Init(long long** ptr)
    {
        scrGlobals = ptr;
    }

    static GLOBAL_BLOCK_STANDARD* GetGlobalBlock_Standard();               //  0, 0,       standard_global_init
    static GLOBAL_BLOCK_TUNABLES* GetGlobalBlock_Tunables();               //  1, 262144,  tunables_registration
    static GLOBAL_BLOCK_PROFILER* GetGlobalBlock_Profiler();               //  2, 524288,  profiler_registration (unused?)
    static GLOBAL_BLOCK_UGC* GetGlobalBlock_UGC();                         //  3, 786432,  ugc_global_registration
    static GLOBAL_BLOCK_UGC_2* GetGlobalBlock_UGC_2();                     //  4, 1048576, ugc_global_registration_2
    static GLOBAL_BLOCK_MP_PROP* GetGlobalBlock_MP_Prop();                 //  5, 1310720, mp_prop_global_block
    static GLOBAL_BLOCK_MP* GetGlobalBlock_MP();                           //  6, 1572864, mp_registration
    static GLOBAL_BLOCK_MP_FM* GetGlobalBlock_MP_FM();                     //  7, 1835008, mp_fm_registration
    static GLOBAL_BLOCK_SC_LB* GetGlobalBlock_SC_LB();                     //  8, 2097152, sc_lb_global_block
    static GLOBAL_BLOCK_MP_SAVE_GAME* GetGlobalBlock_MP_Save_Game();       //  9, 2359296, mp_save_game_global_block
    static GLOBAL_BLOCK_TITLE_UPDATE* GetGlobalBlock_Title_Update();       // 10, 2621440, title_update_registration
    static GLOBAL_BLOCK_SP_DLC* GetGlobalBlock_SP_DLC();                   // 11, 2883584, sp_dlc_registration
    static GLOBAL_BLOCK_SP_PILOT_SCHOOL* GetGlobalBlock_SP_Pilot_School(); // 12, 3145728, sp_pilotschool_reg
    // 13, 3407872, (unused)
    // 14, 3670016, (unused)
    // 15, 3932160, (unused)
    static GLOBAL_BLOCK_MP_PROP_SPECIAL* GetGlobalBlock_MP_Prop_Special(); // 16, 4194304, mp_prop_special_global_block
    static GLOBAL_BLOCK_TITLE_UPDATE_2* GetGlobalBlock_Title_Update_2();   // 17, 4456448, title_update_registration_2
    static GLOBAL_BLOCK_FMMC_STRUCT* GetGlobalBlock_FMMC_Struct();         // 18, 4718592, globals_fmmc_struct_registration
    static GLOBAL_BLOCK_FMMC_STRUCT2* GetGlobalBlock_FMMC_Struct2();       // 19, 4980736, globals_fmmcstruct2_registration
    static GLOBAL_BLOCK_FMMC_STRUCT3* GetGlobalBlock_FMMC_Struct3();       // 20, 5242880, globals_fmmcstruct3_registration

private:
    static inline long long** scrGlobals = nullptr;
};