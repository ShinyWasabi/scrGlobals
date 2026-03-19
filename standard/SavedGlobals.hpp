#pragma once
#include "../Types.hpp"

// All the names can be found in standard_global_reg

enum class eStripClubPlayer
{
    SAVED_STRIP_CLUB_MICHAEL,
    SAVED_STRIP_CLUB_FRANKLIN,
    SAVED_STRIP_CLUB_TREVOR,
    STRIP_CLUB_PLAYER_CHAR_MULTI_0,
    STRIP_CLUB_PLAYER_CHAR_MULTI_1,
    STRIP_CLUB_PLAYER_CHAR_MULTI_2,
    STRIP_CLUB_PLAYER_CHAR_MULTI_3,
    STRIP_CLUB_PLAYER_CHAR_MULTI_4,
    STRIP_CLUB_PLAYER_COUNT
};

enum class eBCStripper
{
    BC_STRIPPER_JULIET,
    BC_STRIPPER_NIKKI,
    BC_STRIPPER_CHASTITY,
    BC_STRIPPER_CHEETAH,
    BC_STRIPPER_SAPPHIRE,
    BC_STRIPPER_INFERNUS,
    BC_STRIPPER_FUFU,
    BC_STRIPPER_PEACH,
    BC_TAXI_LIZ,
    BC_HITCHER_GIRL,
    BC_STRIPPER_COUNT
};

enum class ePSC
{
    PSC_TAKEOFF,
    PSC_LANDING,
    PSC_INVERTED,
    PSC_KNIFING,
    PSC_FLYLOW,
    PSC_DARINGLANDING,
    PSC_LOOPTHELOOP,
    PSC_HELICOURSE,
    PSC_HELISPEEDRUN,
    PSC_PARACHUTEONTOTARGET,
    PSC_CHUTEONTOMOVINGTARG,
    PSC_PLANECOURSE,
    PSC_COUNT
};

enum class ePPComponentFlag
{
    AVAILABLE,
    ACQUIRED,
    NEW
};

struct HEIST_END_SCREEN_DATA_STRUCT
{
    scrValue PotentialTake;               // 0
    scrValue ActualTake;                  // 1
    scrArray<3> HeistEndScreenPlayerTake; // 2
    scrArray<3> HeistEndScreenPlayerPerc; // 6
    scrValue TimeTaken;                   // 10
    scrArray<5> HeistEndScreenCrewStatus; // 11
    scrArray<5> HeistEndScreenCrewTake;   // 17
};
static_assert(SCR_SIZEOF(HEIST_END_SCREEN_DATA_STRUCT) == 23);

struct CREW_ACTIVE_DATA_STRUCT
{
    scrValue Skill;  // 0
    scrValue StatsA; // 1
    scrValue StatsB; // 2
};
static_assert(SCR_SIZEOF(CREW_ACTIVE_DATA_STRUCT) == 3);

struct HEIST_DATA_STRUCT
{
    scrArray<5> HeistChoiceHelpDisplayedArray;                          // 0
    scrArray<5> HeistCrewHelpDisplayedArray;                            // 6
    scrArray<10, scrArray<5>> HeistSelectedCrewArray;                   // 12
    scrArray<14, CREW_ACTIVE_DATA_STRUCT> HeistCrewActiveDataArray;     // 73
    scrValue CrewUnlockedBitset;                                        // 116
    scrValue CrewUsedBitset;                                            // 117
    scrValue CrewDeadBitset;                                            // 118
    scrValue CrewDialogueBitset;                                        // 119
    scrArray<5> HeistDisplayGroupVisibleArray;                          // 120
    scrArray<5, HEIST_END_SCREEN_DATA_STRUCT> HeistEndScreenDataStruct; // 126
};
static_assert(SCR_SIZEOF(HEIST_DATA_STRUCT) == 242);

struct STRIP_CLUBS
{
    scrValue StripClubReputation; // 0
};
static_assert(SCR_SIZEOF(STRIP_CLUBS) == 1);

struct BOOTY_CALLS
{
    scrValue BootyCallLike;          // 0
    scrValue BootyCallPlayerDenials; // 1
    scrValue BootyCallSextsSent;     // 2
    scrValue BootyCallBCCBits;       // 3
    scrValue BootyCallActivated;     // 4
};
static_assert(SCR_SIZEOF(STRIP_CLUBS) == 4);

struct STRIP_CLUB_SAVED
{
    scrArray<1, STRIP_CLUBS> StripClubs;                                                // 0
    scrArray<static_cast<int>(eBCStripper::BC_STRIPPER_COUNT), BOOTY_CALLS> BootyCalls; // 2
};
static_assert(SCR_SIZEOF(STRIP_CLUB_SAVED) == 53);

struct CARMOD_DATA
{
    scrValue Processing;      // 0
    scrValue Ready;           // 1
    scrValue MessageSent;     // 2
    scrValue HoursToComplete; // 3
    scrValue Type;            // 4
};
static_assert(SCR_SIZEOF(STRIP_CLUB_SAVED) == 5);

struct SHOP_SAVED_DATA_STRUCT
{
    scrArray<65> ShopProperties;             // 0
    scrValue ShopDefaultDataSet;             // 66
    scrValue ShopTypesVisited;               // 67
    scrValue HairdoShopVisits;               // 68
    scrValue ClothesShopVisits;              // 69
    scrValue TattooShopVisits;               // 70
    scrValue CarmodShopVisits;               // 71
    scrValue GunShopVisits;                  // 72
    scrValue GunShopPostTrev2Dialogue;       // 73
    scrValue GunShopPostLamar1Dialogue;      // 74
    scrValue ClothesShopPostLester1Dialogue; // 75
    scrValue GunShopHelpCount;               // 76
    scrValue FirstModshopRepair;             // 77
    scrArray<3, CARMOD_DATA> CarmodData;     // 78
    scrArray<1225> ViewedMods;               // 94
    scrValue ContentVehicles;                // 1319
    scrValue ContentWeapons;                 // 1320
    scrValue ContentClothes;                 // 1321
    scrValue ContentHairdos;                 // 1322
    scrValue ContentTattoos;                 // 1323
    scrValue ContentGame;                    // 1324
    scrValue ShopBarberBlipHeliShown;        // 1325
    scrValue ShopArmourHelpShown;            // 1326
};
static_assert(SCR_SIZEOF(SHOP_SAVED_DATA_STRUCT) == 1327);

struct PILOT_SCHOOL_PLAYER_DATA
{
    scrValue ElapsedTime;         // 0
    scrValue LastElapsedTime;     // 1
    scrValue LandingDistance;     // 2
    scrValue LastLandingDistance; // 3
    scrValue Multiplier;          // 4
    scrValue CheckpointCount;     // 5
    scrValue FormationTimer;      // 6
    scrValue HasPassedLesson;     // 7
    scrValue Medal;               // 8
    scrValue LastMedal;           // 9
};
static_assert(SCR_SIZEOF(PILOT_SCHOOL_PLAYER_DATA) == 10);

struct PILOT_SCHOOL_SAVED
{
    scrArray<static_cast<int>(ePSC::PSC_COUNT), PILOT_SCHOOL_PLAYER_DATA> PilotSchoolPlayerData; // 0
};
static_assert(SCR_SIZEOF(PILOT_SCHOOL_SAVED) == 121);

struct RAMPAGE_PLAYER_DATA
{
    scrValue MedalIndex; // 0
    scrValue HighScore;  // 1
};
static_assert(SCR_SIZEOF(PILOT_SCHOOL_SAVED) == 2);

struct RAMPAGE_SAVED
{
    scrArray<5, RAMPAGE_PLAYER_DATA> RampagePlayerData; // 0
};
static_assert(SCR_SIZEOF(PILOT_SCHOOL_SAVED) == 11);

struct PP_COMPONENTS_DATA
{
    scrArray<3, scrBitset<ePPComponentFlag>> Head0;   // 0
    scrArray<3, scrBitset<ePPComponentFlag>> Beard0;  // 4
    scrArray<3, scrBitset<ePPComponentFlag>> Hair0;   // 8
    scrArray<3, scrBitset<ePPComponentFlag>> Torso0;  // 12
    scrArray<3, scrBitset<ePPComponentFlag>> Torso1;  // 16
    scrArray<3, scrBitset<ePPComponentFlag>> Torso2;  // 20
    scrArray<3, scrBitset<ePPComponentFlag>> Torso3;  // 24
    scrArray<3, scrBitset<ePPComponentFlag>> Torso4;  // 28
    scrArray<3, scrBitset<ePPComponentFlag>> Torso5;  // 32
    scrArray<3, scrBitset<ePPComponentFlag>> Torso6;  // 36
    scrArray<3, scrBitset<ePPComponentFlag>> Torso7;  // 40
    scrArray<3, scrBitset<ePPComponentFlag>> Torso8;  // 44
    scrArray<3, scrBitset<ePPComponentFlag>> Torso9;  // 48
    scrArray<3, scrBitset<ePPComponentFlag>> Legs0;   // 52
    scrArray<3, scrBitset<ePPComponentFlag>> Legs1;   // 56
    scrArray<3, scrBitset<ePPComponentFlag>> Legs2;   // 60
    scrArray<3, scrBitset<ePPComponentFlag>> Legs3;   // 64
    scrArray<3, scrBitset<ePPComponentFlag>> Hand0;   // 68
    scrArray<3, scrBitset<ePPComponentFlag>> Feet0;   // 72
    scrArray<3, scrBitset<ePPComponentFlag>> Feet1;   // 76
    scrArray<3, scrBitset<ePPComponentFlag>> Feet2;   // 80
    scrArray<3, scrBitset<ePPComponentFlag>> Feet3;   // 84
    scrArray<3, scrBitset<ePPComponentFlag>> Feet4;   // 88
    scrArray<3, scrBitset<ePPComponentFlag>> Teeth0;  // 92
    scrArray<3, scrBitset<ePPComponentFlag>> Spec0;   // 96
    scrArray<3, scrBitset<ePPComponentFlag>> Spec1;   // 100
    scrArray<3, scrBitset<ePPComponentFlag>> Spec2;   // 104
    scrArray<3, scrBitset<ePPComponentFlag>> Spec2_0; // 108
    scrArray<3, scrBitset<ePPComponentFlag>> Decl0;   // 112
    scrArray<3, scrBitset<ePPComponentFlag>> Decl1;   // 116
    scrArray<3, scrBitset<ePPComponentFlag>> Jbib0;   // 120
    scrArray<3, scrBitset<ePPComponentFlag>> Jbib1;   // 124
    scrArray<3, scrBitset<ePPComponentFlag>> Outf0;   // 128
    scrArray<3, scrBitset<ePPComponentFlag>> Outf1;   // 132
    scrArray<3, scrBitset<ePPComponentFlag>> Propg0;  // 136
    scrArray<3, scrBitset<ePPComponentFlag>> Prop0;   // 140
    scrArray<3, scrBitset<ePPComponentFlag>> Prop1;   // 144
    scrArray<3, scrBitset<ePPComponentFlag>> Prop2;   // 148
    scrArray<3, scrBitset<ePPComponentFlag>> Prop3;   // 152
    scrArray<3, scrBitset<ePPComponentFlag>> Prop4;   // 156
    scrArray<3, scrBitset<ePPComponentFlag>> Prop5;   // 160
};
static_assert(SCR_SIZEOF(PP_COMPONENTS_DATA) == 164);

struct PP_TATTOOS_DATA
{
    scrArray<4> UnlockedBitset; // 0
    scrArray<4> ViewedBitset;   // 5
    scrArray<4> CurrentBitset;  // 10
};
static_assert(SCR_SIZEOF(PP_TATTOOS_DATA) == 15);

struct PP_VARIATION_DATA
{
    scrArray<12> TextureVariation;  // 0
    scrArray<12> DrawableVariation; // 13
    scrArray<12> PaletteVariation;  // 26
    scrArray<9> PropIndex;          // 39
    scrArray<9> PropTexture;        // 49
    scrValue StoredHair;            // 59
    scrValue HairChangeItem;        // 60
    scrValue HairChangeType;        // 61
    scrValue StoredBeard;           // 62
    scrValue BeardChangeItem;       // 63
    scrValue BeardChangeType;       // 64
};
static_assert(SCR_SIZEOF(PP_VARIATION_DATA) == 65);

// TO-DO:
struct PP_INFO_DATA
{
    scrArray<3, PP_VARIATION_DATA> Variations; // 0
    scrArray<3> GolfTops;                      // 196
    scrArray<3> GolfPants;                     // 200
    scrArray<12, scrArray<3>> TrackedComps;    // 204
    scrArray<9, scrArray<3>> TrackedProps;     // 253
};
// static_assert(SCR_SIZEOF(PP_INFO_DATA) == 4324);

struct PLAYER_PED_DATA_STRUCT
{
    scrArray<3, PP_COMPONENTS_DATA> ComponentsArray; // 0
    scrArray<3, PP_TATTOOS_DATA> TattoosArray;       // 493
    PP_INFO_DATA PlayerPedInfoData;                  // 539
    scrValue FranklinOriginalOutfitID;               // 4863
    scrValue OverridePed;                            // 4864
    scrValue PlayerPedDataPatchBitset;               // 4865
};
// static_assert(SCR_SIZEOF(PLAYER_PED_DATA_STRUCT) == 4866);

// TO-DO:
struct SAVED_GLOBALS
{
    scrValue SaveVersion;                                                                                        // 0
    HEIST_DATA_STRUCT HeistDataStruct;                                                                           // 1
    scrArray<static_cast<int>(eStripClubPlayer::STRIP_CLUB_PLAYER_COUNT), STRIP_CLUB_SAVED> StripClubSavedArray; // 243
    SHOP_SAVED_DATA_STRUCT ShopSavedDataStruct;                                                                  // 668
    scrArray<3, PILOT_SCHOOL_SAVED> PilotSchoolSavedArray;                                                       // 1995
    RAMPAGE_SAVED RampageSaved;                                                                                  // 2359
    PLAYER_PED_DATA_STRUCT PlayerPedDataStruct;                                                                  // 2370
};
// static_assert(SCR_SIZEOF(SAVED_GLOBALS) == 38592);