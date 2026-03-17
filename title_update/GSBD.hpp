#pragma once
#include "../Types.hpp"
#include "GlobalPlayerBD.hpp" // for eFreemodeState

struct IMPOUND_VEHICLE_INFO
{
    scrValue ImpoundId;
    scrValue OccupiedCheckDone;
    scrValue EntityAreaHandle;
    scrValue TimeCreated;
};
static_assert(SCR_SIZEOF(IMPOUND_VEHICLE_INFO) == 4);

struct CEO_COLOR
{
    scrValue Owner;
    scrValue Color;
};
static_assert(SCR_SIZEOF(CEO_COLOR) == 2);

// I don't think this class has anything to do with ceo colors at all
struct CEO_COLORS
{
    scrArray<10> CeoColorIndices;
    scrArray<32> CeoColorIndices2;
    scrArray<10, CEO_COLOR> CeoColors;
    scrValue PAD_0065;
    scrValue PAD_0066[19];
    scrValue PAD_0085; // added b3095 ("Press ~INPUT_CONTEXT~ to contact Jamal and begin stealing bolt cutters for The Cargo Ship Robbery" mission variation)
};
static_assert(SCR_SIZEOF(CEO_COLORS) == 86);

struct SMPL_INTERIOR_DATA_SERVER
{
    scrValue PAD_0000; // unused
    scrArray<32> PlayerInteriorInstances;
    scrArray<32> PlayerInteriorIds; // used solely for telemetry
    scrValue PlayerInteriorCreationRequestBitset;
    scrArray<32> PlayerOwnerBitset;
    scrValue PlayerInteriorRemovalRequestBitset;
    scrArray<32> PlayerInteriorCreationTimes;
    scrArray<32> PlayerInteriorSimpleInteriorTypes;
    scrArray<32> PlayerInteriorIsOwnerless;
    scrArray<32> PlayerInteriorOwners;
    scrValue LastBroadcastTime; // added b889g9, unused
};
static_assert(SCR_SIZEOF(SMPL_INTERIOR_DATA_SERVER) == 235);

struct LEAVE_CLUBHOUSE_SERVER
{
    scrArray<32> Identifiers;
    scrArray<32> ExitLocations;
    scrArray<32> ExitLocationSlots;
};
static_assert(SCR_SIZEOF(LEAVE_CLUBHOUSE_SERVER) == 99);

struct IE_DELIVERY_INFO
{
    scrValue Player;
    scrValue VehicleModel;
    scrValue ContrabandOwner;
    scrValue TimeCreated;
    scrValue PAD_0004;
};
static_assert(SCR_SIZEOF(IE_DELIVERY_INFO) == 5);

struct GSBD
{
    scrEnum<eFreemodeState> FreemodeState;
    scrValue SessionToken; // time when freemode had started for the script host
    scrArray<32, IMPOUND_VEHICLE_INFO> ImpoundVehicleInfos;
    scrArray<32, scrVector> SpawnPositions;
    scrArray<32> SpawnPositionCreationTimes;
    scrArray<32> SpawnPositionsValid;
    scrArray<32> PAD_0294;
    scrArray<32> SpawnPositionTokens;
    scrValue SpawnPositionCounter;
    scrArray<32> RespawnVehicles;
    scrArray<32> RespawnVehicleSeats;
    scrArray<32> MorsMutualSpawnSlots;
    scrValue MorsMutualSpawnPlayersBitset;
    scrValue PAD_0461[353]; // TODO
    scrValue CopTimerOn;    // cut CnC content
    scrValue CrookTimerOn;
    scrValue PAD_0816; // always set to FALSE
    scrValue PAD_0817; // unused
    CEO_COLORS CeoColors;
    // SMPL_INTERIOR_DATA_SERVER SimpleInteriorData;
    LEAVE_CLUBHOUSE_SERVER LeaveClubhouse;
    scrArray<32, IE_DELIVERY_INFO> IEDeliveryInfos;
    scrValue PAD_1397;
    scrValue IAATurretCameraVehicleId; // used by DDH act 1
    scrValue PAD_1399[97];
    scrValue CayoPericoStrandedAnimalChoice;
};
static_assert(SCR_SIZEOF(GSBD) == 1264);