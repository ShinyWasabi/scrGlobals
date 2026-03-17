#pragma once
#include "../Types.hpp"
#include "../Shared.hpp"

// All the names can be found in the startup script

struct MP_PROPERTY_SAVED
{
    scrValue TVOn;                              // 0
    scrValue TVChannelId;                       // 1
    scrValue PenthouseTVOn;                     // 2
    scrValue PenthouseTVChannelId;              // 3
    scrValue MediaRoomTVOn;                     // 4
    scrValue MediaRoomTVChannelId;              // 5
    scrArray<2> RadioOnId;                      // 6
    scrArray<2> RadioStationId;                 // 7
    scrValue GarageTVOn;                        // 12
    scrValue GarageTVChannelId;                 // 13
    scrValue GarageRadioOn;                     // 14
    scrValue GarageRadioStationId;              // 15
    scrValue NumberTimesSmoked;                 // 16
    scrValue NumberTimesDrank;                  // 17
    scrValue NumberTimesStrippers;              // 18
    scrValue NumberTimesSmokedSecond;           // 19
    scrValue NumberTimesDrankSecond;            // 20
    scrValue NumberTimesStrippersSecond;        // 21
    scrValue NumberTimesSmoked3;                // 22
    scrValue NumberTimesDrank3;                 // 23
    scrValue NumberTimesStrippers3;             // 24
    scrValue NumberTimesSmoked4;                // 25
    scrValue NumberTimesDrank4;                 // 26
    scrValue NumberTimesStrippers4;             // 27
    scrValue NumberTimesSmoked5;                // 28
    scrValue NumberTimesDrank5;                 // 29
    scrValue NumberTimesStrippers5;             // 30
    scrValue NumberTimesSmokedYatch;            // 31
    scrValue NumberTimesDrankYatch;             // 32
    scrValue NumberTimesStrippersYatch;         // 33
    scrValue DateLastCleanedApartment;          // 34
    scrValue ShowersTaken;                      // 35
    scrArray<22> PropDrinks;                    // 36
    scrArray<22> PropSmokes;                    // 59
    scrArray<22> PropStrippers;                 // 82
    scrArray<30, scrTextLabel63> PropNamedVehs; // 105
};
static_assert(SCR_SIZEOF(MP_PROPERTY_SAVED) == 586);

struct CAR_APP_ORDER
{
    // field 0 to 40 actually seems to be a struct (MISC::START_SAVE_STRUCT_WITH_SIZE(panParam0, 41, sParam1))
    scrValue Model;                  // 0
    scrValue ColourId1;              // 1
    scrValue ColourId2;              // 2
    scrValue Colour1Group;           // 3
    scrValue Colour2Group;           // 4
    scrValue WindowTint;             // 5
    scrValue TyreSmokeR;             // 6
    scrValue TyreSmokeG;             // 7
    scrValue TyreSmokeB;             // 8
    scrValue Engine;                 // 9
    scrValue Brakes;                 // 10
    scrValue Wheels;                 // 11
    scrValue WheelType;              // 12
    scrValue Exhaust;                // 13
    scrValue Suspension;             // 14
    scrValue Armour;                 // 15
    scrValue Horn;                   // 16
    scrValue Lights;                 // 17
    scrValue BulletProofTyres;       // 18
    scrValue Turbo;                  // 19
    scrValue TyreSmoke;              // 20
    scrTextLabel15 PlateText;        // 21
    scrValue PlateBack;              // 25
    scrValue UId;                    // 26
    scrValue Cost;                   // 27
    scrTextLabel15 PlateTextPending; // 28
    scrValue PlateBackPending;       // 32
    scrValue ProcessOrder;           // 33
    scrValue OrderForPlayerVehicle;  // 34
    scrValue OrderReceivedOnBoot;    // 35
    scrValue OrderPending;           // 36
    scrValue CheckPlateProfanity;    // 37
    scrValue SCProfanityFailed;      // 38
    scrValue SOrderFailedFunds;      // 39
    scrValue OrderPaidFor;           // 40
    scrArray<10> CarHidden;          // 41
    scrValue UpdateMods;             // 52
    scrValue MultiplayerDataWiped;   // 53
    scrValue DeleteCarData;          // 54
    scrValue CarAppPlateSet;         // 55
    scrTextLabel15 CarAppPlateText;  // 56
    scrValue CarAppPlateBack;        // 60
    scrValue OrderCount;             // 61
    scrValue OrderVehicle;           // 62
    scrArray<10> SavedVehSlot;       // 63
    scrArray<10> SavedVehPrio;       // 74
    scrValue LastUsed;               // 85
    scrValue NewUsed;                // 86
    scrValue SetupInit;              // 87
};
static_assert(SCR_SIZEOF(CAR_APP_ORDER) == 88);

struct DAILY_OBJECTIVES
{
    scrValue Objective; // 0
    scrValue Completed; // 1
    scrValue Initial;   // 2
};
static_assert(SCR_SIZEOF(DAILY_OBJECTIVES) == 3);

struct MP_GENERAL_SAVED
{
    scrValue CashGivenTotal;                        // 0
    scrValue CashGivenTime;                         // 1
    scrValue LastSavedCar;                          // 2
    scrValue CurrentPropValue;                      // 3
    scrValue WheelieTimer;                          // 4
    scrValue WheelieUpdates;                        // 5
    scrValue WheelieTime;                           // 6
    scrValue GrabTime;                              // 7
    scrValue LastSoldVehicleTime;                   // 8
    scrValue LastTimePlayed;                        // 9
    scrValue SaveCoupons;                           // 10
    scrValue NewVehPurchased;                       // 11
    scrValue LastBruciePillReminder;                // 12
    scrValue LastSecVanReminder;                    // 13
    scrValue LastBountyReminder;                    // 14
    scrValue LastParaReminder;                      // 15
    scrValue LastCrateDropReminder;                 // 16
    scrValue LastGangAttackReminder;                // 17
    scrValue LastImpExpReminder;                    // 18
    scrValue LastInsuranceReminder;                 // 19
    scrValue LastSurvivalReminder;                  // 20
    scrValue LastBikerBackupReminder;               // 21
    scrValue LastVagosBackupReminder;               // 22
    scrValue LastLesterVehReminder;                 // 23
    scrValue LastPersonalVehDeliveryReminder;       // 24
    scrValue LastPegasusVehicleReminder;            // 25
    scrValue LastMerryweatherReminder;              // 26
    scrValue LastLesterHelpReminder;                // 27
    scrValue LastLesterReqJobReminder;              // 28
    scrValue LastGeraldReqJobReminder;              // 29
    scrValue LastSimeonReqJobReminder;              // 30
    scrValue LastMartinReqJobReminder;              // 31
    scrValue LastRonReqJobReminder;                 // 32
    scrValue RecentlyPassedMissionBitset;           // 33
    scrValue RecentlyPassedMissionTime;             // 34
    scrValue LastImportExportDelTime;               // 35
    scrValue LastImportExportListTime;              // 36
    scrValue MyLastImportExportListDay;             // 37
    scrValue VehicleWebsiteReminderTime;            // 38
    scrValue DefaultClothesSet;                     // 39
    scrArray<6> Clothes;                            // 40
    scrArray<1224> Carmods;                         // 47
    scrValue LastCrewCharWasIn;                     // 1272
    scrValue StripperUnlockedBS;                    // 1273
    scrValue GeneralBS;                             // 1274
    scrValue CarsModifiedTimeStamp;                 // 1275
    scrArray<9> GolfLongestDriveHole;               // 1276
    scrArray<9> GolfLongestPuttHole;                // 1286
    scrValue GolfBestRound;                         // 1296
    scrValue GolfLongestDrive;                      // 1297
    scrValue GolfLongestPutt;                       // 1298
    scrValue ShareLJCashTotal;                      // 1299
    scrValue ShareLJCashTime;                       // 1300
    scrValue ReceiveLJCashTotal;                    // 1301
    scrValue ReceiveLJCashTime;                     // 1302
    scrValue LastAccProp;                           // 1303
    scrValue Multi1PropVal;                         // 1304
    scrArray<34> PropAryVal;                        // 1305
    scrValue LastAccSmplInt;                        // 1337
    scrValue KrPatchUpdate;                         // 1338
    scrArray<273> OutfitCompDraw;                   // 1339
    scrArray<273> OutfitCompTex;                    // 1613
    scrArray<210> OutfitPropID;                     // 1887
    scrArray<210> OutfitPropTex;                    // 2098
    scrArray<21> OutfitStored;                      // 2309
    scrArray<21> OutfitTatCrewA;                    // 2331
    scrArray<21> OutfitTatCrewB;                    // 2353
    scrArray<21> OutfitTatCrewC;                    // 2375
    scrArray<21> OutfitTatCrewD;                    // 2397
    scrArray<21> OutfitTatCrewE;                    // 2419
    scrArray<21> OutfitTatCrewF;                    // 2441
    scrArray<21, scrTextLabel31> OutfitName;        // 2463
    scrArray<21> OutfitShirt;                       // 2632
    scrArray<3, GAMER_HANDLE> LastJobGamer;         // 2654
    scrArray<918> DLCMods;                          // 2694
    scrArray<626> DLCSuperMods;                     // 3613
    scrValue DOCompletedObjectives;                 // 4240
    scrValue DOLoggedInToday;                       // 4241
    scrValue DOXValue;                              // 4242
    scrValue DOLastHistoryLength;                   // 4243
    scrValue DOLastResetTime;                       // 4244
    scrArray<3, DAILY_OBJECTIVES> DOObjectives;     // 4245
    scrArray<24> DOHistory;                         // 4255
    scrArray<3, scrTextLabel63> LastJobGamerName;   // 4280
    scrArray<10> BGSaveInt;                         // 4329
    scrArray<2> PropLib;                            // 4340
    scrArray<3, GAMER_HANDLE> LastGOGGamer;         // 4343
    scrArray<3, GAMER_HANDLE> LastGOJobGamer;       // 4383
    scrArray<3, scrTextLabel63> LastGOJobGamerName; // 4423
};
static_assert(SCR_SIZEOF(MP_GENERAL_SAVED) == 4475);

struct MP_BOUNTY_SAVED
{
    GAMER_HANDLE BountyGamer;                      // 0
    scrValue BountyTime;                           // 13
    scrValue BountyValue;                          // 14
    scrArray<16, GAMER_HANDLE> BountyGamerHandles; // 15
    scrArray<16> BountyTim;                        // 224
};
static_assert(SCR_SIZEOF(MP_BOUNTY_SAVED) == 241);

struct MP_ATM_SAVED
{
    scrValue MPATMCaret;                       // 0
    scrArray<16> MPATMLogVal;                  // 1
    scrArray<16, scrTextLabel23> MPATMLogScrs; // 18
    scrArray<16> MPATMLogAct;                  // 115
    scrArray<16> MPATMLogDat;                  // 132
    scrValue MPAnyVehBought;                   // 149
};
static_assert(SCR_SIZEOF(MP_ATM_SAVED) == 150);

struct MP_SCRIPT_SAVES_DATA
{
    scrArray<1> SaveDataIntScriptSaves;                    // 0
    scrArray<1> SaveDataFloatScriptSaves;                  // 2
    scrArray<1> SaveDataBoolScriptSaves;                   // 4
    scrArray<1, scrTextLabel31> SaveDataStringScriptSaves; // 6
    scrArray<1, scrVector> SaveDataVectorScriptSaves;      // 15
    scrArray<1, DATE> SaveDataDateScriptSaves;             // 19
};
static_assert(SCR_SIZEOF(MP_SCRIPT_SAVES_DATA) == 27);

struct SAVED_MP_GLOBALS_ENTRY
{
    // Are these two a struct? scrTextLabelASSIGN_STRING(&unk, "MP_BIG_ASS_VEHICLES", 24) -> MISC::START_SAVE_STRUCT_WITH_SIZE(panParam0, 7, sParam1)
    scrValue BAVTimestamp;                // 0
    scrArray<5> BAVFlags;                 // 1
    MP_PROPERTY_SAVED PropertySaved;      // 7
    CAR_APP_ORDER CarAppOrder;            // 593
    MP_GENERAL_SAVED GeneralSaved;        // 681
    MP_BOUNTY_SAVED BountySaved;          // 5156
    MP_ATM_SAVED ATMSaved;                // 5397
    MP_SCRIPT_SAVES_DATA ScriptSavesData; // 5547
};
static_assert(SCR_SIZEOF(SAVED_MP_GLOBALS_ENTRY) == 5574);

struct SAVED_MP_GLOBALS
{
    scrArray<1, SAVED_MP_GLOBALS_ENTRY> Entries;
};
static_assert(SCR_SIZEOF(SAVED_MP_GLOBALS) == 5575);