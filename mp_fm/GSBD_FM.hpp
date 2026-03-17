#pragma once
#include "../Types.hpp"
#include "../Shared.hpp"

struct PLAYER_BOUNTY
{
    scrValue HasBounty;
    scrValue BountyAmount;
    scrValue PAD_0002; // unused
};
static_assert(SCR_SIZEOF(PLAYER_BOUNTY) == 3);

struct ACTIVE_CONTACT_SERVICE
{
    scrValue Id;
    scrValue Target;
    scrValue Bounty; // unknown usage
    scrValue Flags;
};
static_assert(SCR_SIZEOF(ACTIVE_CONTACT_SERVICE) == 4);

struct WEAPON_PICKUPS
{
    scrValue LastUnkWeaponPickupTime;
    scrValue LastMeleeWeaponPickupTime;
    scrValue LastProjectilePickupTime;
    scrValue LastGunPickupTime;
    scrArray<95> Indices; // size increased in b3095 (62 -> 95) // and in b3407 (95 -> 96) // one of PICKUP_WEAPON_VINTAGEPISTOL removed in b1013.17g9
    scrArray<95> Owners;
    scrValue SpawnCounter;
    scrValue AmmoCount;
};
static_assert(SCR_SIZEOF(WEAPON_PICKUPS) == 198);

struct BIKER_CONTRACTS_SERVER
{
    scrArray<3> ActiveContracts;
    scrArray<3> ContractCompleteCount;
    scrValue CompletedContractBitset;
    scrValue LastContractRefreshTime;
};
static_assert(SCR_SIZEOF(BIKER_CONTRACTS_SERVER) == 10);

struct GSBD_FM
{
    scrArray<2> ModelSwapBits;                  // 0
    scrValue PAD_0003;                          // unused
    scrArray<32, PLAYER_BOUNTY> PlayerBounties; // 4
    scrValue PAD_0101[5];                       // unused
    scrArray<2> MuggingPlayers;                 // 0 = mugger, 1 = merryweather mercs
    scrArray<2> MuggedPlayers;
    scrValue PAD_0112[4];  // unused
    scrArray<65> PAD_0116; // TODO b3407 (61 -> 62), 62 -> 65
    scrValue ShopProcessingBitset;
    scrArray<NUM_CONTACTS> ActiveContactServiceBitsets;
    scrArray<32, ACTIVE_CONTACT_SERVICE> ActiveContactServices;
    scrValue SpectatorTVWantedPlayer;
    scrValue SpectatorTVWantedClosing;
    scrValue SpectatorTVWantedActive;
    scrValue PAD_0390[2]; // not read by the scripts
    scrValue PAD_0392;    // TODO
    scrValue PAD_0393[6]; // TODO
    WEAPON_PICKUPS WeaponPickups;
    BIKER_CONTRACTS_SERVER BikerContracts;
    scrArray<32> DoubleActionCacheLocationRevealed;
    scrValue LastBroadcastTime; // added b889g9, unused
};
static_assert(SCR_SIZEOF(GSBD_FM) == 653);