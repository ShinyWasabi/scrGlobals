#pragma once
#include "../Types.hpp"
#include "../Shared.hpp"

#define NUM_PERSONAL_VEHICLES 607

enum class ePersonalVehicleFlags
{
    TRIGGER_SPAWN_TOGGLE = 0,
    DESTROYED = 1,
    HAS_INSURANCE = 2,
    UNK0 = 3,
    IMPOUNDED = 6,
    UNK1 = 10,
    SPAWN_AT_MORS_MUTUAL = 11,
    UNK2 = 16
};

struct MPSV_ENTRY
{
    scrValue NumberPlateTextIndex;                         // 0 (SET/GET_VEHICLE_NUMBER_PLATE_TEXT)
    scrTextLabel15 NumberPlateText;                        // 1
    scrValue Colours1;                                     // 5 (SET/GET_VEHICLE_COLOURS)
    scrValue Colours2;                                     // 6
    scrValue ExtraColours1;                                // 7 (SET/GET_VEHICLE_EXTRA_COLOURS)
    scrValue ExtraColours2;                                // 8
    scrArray<49> ModTypes;                                 // 9 (SET/GET_VEHICLE_MOD)
    scrArray<2> ModVariation;                              // 59 (GET_VEHICLE_MOD_VARIATION)
    scrValue TyreSmokeR;                                   // 62 (SET/GET_VEHICLE_TYRE_SMOKE_COLOR)
    scrValue TyreSmokeG;                                   // 63
    scrValue TyreSmokeB;                                   // 64
    scrValue WindowTint;                                   // 65 (SET/GET_VEHICLE_WINDOW_TINT)
    scrValue VehicleModel;                                 // 66
    scrValue Livery;                                       // 67 (SET/GET_VEHICLE_LIVERY)
    scrValue ConvertibleRoofState;                         // 68 (GET_CONVERTIBLE_ROOF_STATE)
    scrValue WheelType;                                    // 69 (SET/GET_VEHICLE_WHEEL_TYPE)
    scrValue DoorLockStatus;                               // 70 (GET_VEHICLE_DOOR_LOCK_STATUS)
    scrValue CustomPrimaryColourR;                         // 71 (SET/GET_VEHICLE_CUSTOM_PRIMARY_COLOUR)
    scrValue CustomPrimaryColourG;                         // 72
    scrValue CustomPrimaryColourB;                         // 73
    scrValue NeonColourR;                                  // 74 (SET/GET_VEHICLE_NEON_COLOUR)
    scrValue NeonColourG;                                  // 75
    scrValue NeonColourB;                                  // 76
    scrBitset<> Flags1;                                    // 77
    scrValue HornHash;                                     // 78 (OVERRIDE_VEH_HORN)
    scrValue HornSoundIndex;                               // 79 (SET/GET_VEHICLE_HORN_SOUND_INDEX)
    scrValue EnveffScale;                                  // 80 (SET/GET_VEHICLE_ENVEFF_SCALE)
    GAMER_HANDLE GamerHandle;                              // 81
    scrValue IsPersonalVehicle;                            // 94 (this actually seems to be an int)
    scrBitset<> Flags2;                                    // 95
    scrValue PersonalVehicleSlot;                          // 96 (DECOR_GET_INT(veParam0, "PV_Slot"))
    scrValue ExtraColour5;                                 // 97 (SET/GET_VEHICLE_EXTRA_COLOUR_5)
    scrValue Livery2;                                      // 98 (SET/GET_VEHICLE_LIVERY2)
    scrValue ExtraColour6;                                 // 99 (SET/GET_VEHICLE_EXTRA_COLOUR_6)
    scrValue PlayerIndex;                                  // 100
    scrValue ImportExportVehicle;                          // 101
    scrValue TyreType;                                     // 102
    scrBitset<> Flags3;                                    // 103 (flag 0 is set if the MLJ decor exists)
    scrBitset<ePersonalVehicleFlags> PersonalVehicleFlags; // 104
    scrValue ImpoundTime;                                  // 105 (MP_STAT_MPSV_IMPOUND_TIME)
    scrValue PremiumPaid;                                  // 106 (MP_STAT_MPSV_PREMIUM_PAID)
    scrTextLabel63 DestroyerName;                          // 107
    scrTextLabel63 PlayerRadioStationName;                 // 123 (GET_PLAYER_RADIO_STATION_NAME)
    scrValue PrimaryColour;                                // 139
    scrValue SecondaryColour;                              // 140
    scrValue PurchasePrice;                                // 141
    scrValue ObtainedTime;                                 // 142 (MP_STAT_MPSV_OBTAINED_TIME)
};
static_assert(SCR_SIZEOF(MPSV_ENTRY) == 143);

struct MPSV
{
    scrArray<NUM_PERSONAL_VEHICLES, MPSV_ENTRY> Entries;
};
static_assert(SCR_SIZEOF(MPSV) == 86802);