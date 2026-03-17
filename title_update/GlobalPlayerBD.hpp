#pragma once
#include "../Types.hpp"

enum class eFreemodeState
{
    NONE = 0,
    UNK_2 = 2,
    RUNNING = 4,
    CLOSING = 5,
    UNK_10 = 10,
    UNK_11 = 11
};

enum class eMissionType
{
    NONE,
    MISSION,
    HEIST,
    UNK_3,
    ADVERSARY_MODE,
    LAST_TEAM_STANDING,
    CAPTURE,
    HEIST_SETUP,
    UNK_8,  // FMMC_RSTAR_MCP
    UNKNOWN // everything else
};

enum class eAnimationBitset
{
    CASH_RAIN_ACTIVE = 12,
    CHAMPAGNE_SPRAY_ACTIVE = 13
};

enum class eBlipFlags
{
    // 0 is unused
    VISIBLE_ON_CUTSCENE = 1,
    FLASH_MINIMAP_DISPLAY = 2,
    FLASH_BLIP = 3,
    MICRO_LIGHT_OTR_ACTIVE = 4,
    SKIP_TUTORIAL_SESSION_CHECKS = 5,
    HIDE_ON_MINIMAP = 6,                     // needs testing
    HIDE_ON_MINIMAP_WHEN_INTERIOR = 7,       // needs testing
    HIDE_ON_MINIMAP_WHEN_BIG_MAP_ACTIVE = 9, // needs testing
    DONT_USE_PASSIVE_BLIP = 21,
    USE_RAMPAGE_BLIP = 24,
    HIDE_WHEN_FADING = 25
};

enum class eBlipType
{
    ON_FOOT,
    TANK,
    PLAYER_JET,
    PLAYER_PLANE,
    PLAYER_HELI,
    PLAYER_GUNCAR,
    PLAYER_BOAT,
    ROCKET_VOLTIC,
    TECHNICAL,
    RUINER_2000,
    DUNE_BUGGY,
    PHANTOM_WEDGE,
    ARMORED_BOXVILLE, // boxville5
    WASTELANDER,
    QUAD,
    APC,
    OPPRESSOR_MK_1,
    HALF_TRACK,
    DUNE_FAV,
    WEAPONIZED_TAMPA,
    AA_TRAILER,
    ALPHA_Z1,
    BOMBUSHKA,
    HAVOK,
    HOWARD,
    HUNTER,
    MICROLIGHT,
    MOGUL,
    MOLOTOK,
    NOKOTA,
    PYRO,
    ROGUE,
    STARLING,
    SEABREEZE,
    TULA,
    STROMBERG,
    DELUXO,
    THRUSTER,
    KHANJALI,
    RIOT_VAN,
    VOLATOL,
    BARRAGE,
    AKULA,
    CHERNOBOG,
    AVENGER,
    TURRETED_LIMO,
    SEA_SPARROW,
    CARACARA,
    PARTY_BUS,
    TERRORBYTE,
    MENACER,
    SCRAMJET,
    POUNDER_CUSTOM,
    MULE_CUSTOM,
    SPEEDO_CUSTOM,
    OPPRESSOR_MK_2,
    STRIKEFORCE,
    ARENA_BRUISER,
    ARENA_BRUTUS,
    ARENA_CERBERUS,
    ARENA_DEATHBIKE,
    ARENA_DOMINATOR,
    ARENA_IMPALER,
    ARENA_IMPERATOR,
    ARENA_ISSI,
    ARENA_SASQUATCH,
    ARENA_SCARAB,
    ARENA_SLAMVAN,
    ARENA_ZR380,
    MINI_SUB,
    SPARROW,
    FOLDING_WING_JET,
    GANG_BIKE,
    MILITARY_QUAD,
    SQUADDIE, // SQUADEE
    CAYO_DINGHY,
    WINKY,
    PATROL_BOAT,
    ANNIHILATOR,
    KART_RETRO,
    KART_MODERN,
    MILITARY_TRUCK,
    SUBMARINE,
    CHAMPION,
    BUFFALO_STX,
    DEITY, // why does this have a blip?
    JUBILEE,
    GRANGER_3600LX,
    PATRIOT_MILSPEC,
    ARMS_DEALING_AIR, // requires some flag to be set
    BRICKADE_6X6,
    RAIJU,
    CONADA2,
    STEAMER2,
    TOW_TRUCK,
};

enum class ePlayerStateFlags
{
    SCREEN_FADING_OUT = 0,
    SCREEN_FADED_OUT = 1,
    CINEMATIC_NEWS_CHANNEL_ACTIVE = 2,
    REPEATING_PREVIOUS_CHECKPOINT = 3,
    CAR_MOD_INTRO = 4,
    PLAYER_SWITCH_STATE_ASCENT = 5,
    PLAYER_SWITCH_STATE_IN_CLOUDS = 6,
    PLAYER_SWITCH_STATE_PAN = 7,
    PLAYER_SWITCH_STATE_DESCENT = 8,
    MODSHOP_ACTIVE = 9,
    MODSHOP_EXITING_VEHICLE = 10,
    SPECTATING = 28,
    BEAST_ACTIVE = 29,
    PLAYER_NOT_IN_SCTV = 30,
    PLAYER_IN_SCTV = 31
};

enum class ePlayerStateFlags2
{
    HAS_GTA_PLUS_MEMBERSHIP = 31
};

enum class eActivityFlags
{
    WATCHING_MOVIE = 0,
    IN_GANG_ATTACK = 1,
    IMPROMPTU_RACE = 2,
    CRATE_DROP = 4, // tf is this? "~s~A plane is on its way to drop a Crate ~HUD_COLOUR_GREEN~~BLIP_CRATEDROP~ ~s~which contains useful equipment. Be the first to collect it."
    DELIVERING_SIMEON_VEHICLE = 6,
    IN_LAP_DANCE = 7,
    HOLD_UP_TUTORIAL = 8,
    JOYRIDER = 9, // uh what is this?
    CAR_MOD_TUTORIAL = 10,
    MISSION_LAUNCHER = 11,
    LESTER_CUTSCENE_ACTIVE = 12,
    TREVOR_CUTSCENE_ACTIVE = 13,
    HEIST_INTRO = 14,
    PLANE_TAKEDOWN = 15,  // not sure what this is
    DISTRACT_COPS = 16,   // "Great. Thank you for your help. Now some horrible criminals are in jail for a crime they did commit and it's all your fault!!" ???
    DESTROY_VEHICLE = 17, // ???
    PARTAKING_IN_HOT_TARGET = 18,
    PARTAKING_IN_KILL_LIST = 19,
    TIME_TRIAL_STARTED = 21,
    PARTAKING_IN_CHECKPOINTS = 22,
    PARTAKING_IN_CHALLENGE = 23,
    PENNED_IN_ACTIVE = 24,
    RC_TIME_TRIAL_STARTED = 25,
    PARTAKING_IN_HOT_PROPERTY = 27,
    PARTAKING_IN_KING_OF_THE_CASTLE = 29,
    PARTAKING_IN_CRIMINAL_DAMAGE = 30,
    LOWRIDER_INTRO = 31
};

enum class eGamerTagFlags
{
    SHOW_PACKAGE_COUNT = 13,
    FADE_OUT_GAMER_TAG = 17,
    GANG_CEO = 19,
    GANG_BIKER = 20
}; // TODO!

enum class eOrbitalBitset
{
    ORBITAL_CANNON_ACTIVE = 0,
    WATCHING_MOVIE = 1, // not a typo, orbital cannon script needs this
    CUTSCENE_OR_INTERIOR = 2,
    TRANSACTION_PENDING = 3
};

enum class eArcadeGameBitset
{
    ARCADE_MACHINE_ACTIVATED = 0,
    LOVE_METER_ACTIVATED = 1,
    LOVE_METER_ANIMATION_GENDER_DECIDED = 2
};

enum class eOutOfSightFlags
{
    OUT_OF_SIGHT_ENABLED = 0,
    OUT_OF_SIGHT_ACTIVE = 1, // this controls whether you appear on radar or not
    HELP_DISPLAYED = 2,
    DAMAGED_PLAYER_OUTSIDE_ORGANIZATION = 3
};

enum class eSimpleInteriorIndex
{
    SIMPLE_INTERIOR_INVALID = -1,
    SIMPLE_INTERIOR_WAREHOUSE_1,
    SIMPLE_INTERIOR_WAREHOUSE_2,
    SIMPLE_INTERIOR_WAREHOUSE_3,
    SIMPLE_INTERIOR_WAREHOUSE_4,
    SIMPLE_INTERIOR_WAREHOUSE_5,
    SIMPLE_INTERIOR_WAREHOUSE_6,
    SIMPLE_INTERIOR_WAREHOUSE_7,
    SIMPLE_INTERIOR_WAREHOUSE_8,
    SIMPLE_INTERIOR_WAREHOUSE_9,
    SIMPLE_INTERIOR_WAREHOUSE_10,
    SIMPLE_INTERIOR_WAREHOUSE_11,
    SIMPLE_INTERIOR_WAREHOUSE_12,
    SIMPLE_INTERIOR_WAREHOUSE_13,
    SIMPLE_INTERIOR_WAREHOUSE_14,
    SIMPLE_INTERIOR_WAREHOUSE_15,
    SIMPLE_INTERIOR_WAREHOUSE_16,
    SIMPLE_INTERIOR_WAREHOUSE_17,
    SIMPLE_INTERIOR_WAREHOUSE_18,
    SIMPLE_INTERIOR_WAREHOUSE_19,
    SIMPLE_INTERIOR_WAREHOUSE_20,
    SIMPLE_INTERIOR_WAREHOUSE_21,
    SIMPLE_INTERIOR_WAREHOUSE_22,
    SIMPLE_INTERIOR_FACTORY_METH_1,
    SIMPLE_INTERIOR_FACTORY_WEED_1,
    SIMPLE_INTERIOR_FACTORY_CRACK_1,
    SIMPLE_INTERIOR_FACTORY_MONEY_1,
    SIMPLE_INTERIOR_FACTORY_DOCUMENTS_1,
    SIMPLE_INTERIOR_FACTORY_METH_2,
    SIMPLE_INTERIOR_FACTORY_WEED_2,
    SIMPLE_INTERIOR_FACTORY_CRACK_2,
    SIMPLE_INTERIOR_FACTORY_MONEY_2,
    SIMPLE_INTERIOR_FACTORY_DOCUMENTS_2,
    SIMPLE_INTERIOR_FACTORY_METH_3,
    SIMPLE_INTERIOR_FACTORY_WEED_3,
    SIMPLE_INTERIOR_FACTORY_CRACK_3,
    SIMPLE_INTERIOR_FACTORY_MONEY_3,
    SIMPLE_INTERIOR_FACTORY_DOCUMENTS_3,
    SIMPLE_INTERIOR_FACTORY_METH_4,
    SIMPLE_INTERIOR_FACTORY_WEED_4,
    SIMPLE_INTERIOR_FACTORY_CRACK_4,
    SIMPLE_INTERIOR_FACTORY_MONEY_4,
    SIMPLE_INTERIOR_FACTORY_DOCUMENTS_4,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_POLICE_STATION,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_MC_CLUBHOUSE,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_BANK_ROCKFORD,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_BANK_PILLBOX,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_BANK_ALTA,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_BANK_BURTON,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_BANK_PALETO,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_BANK_GRAND_SENORA,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_BANK_CHUMASH,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_ROCKCLUB,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_CHICKEN_FACTORY,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_CHICKEN_FACTORY_PART_2,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_CHICKEN_FACTORY_PART_3,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_CHICKEN_FACTORY_PART_4,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_FARMHOUSE,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_HEIST_YACHT,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_RECYCLING_PLANT,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_BIOLAB,
    SIMPLE_INTERIOR_IE_WAREHOUSE_1,
    SIMPLE_INTERIOR_IE_WAREHOUSE_2,
    SIMPLE_INTERIOR_IE_WAREHOUSE_3,
    SIMPLE_INTERIOR_IE_WAREHOUSE_4,
    SIMPLE_INTERIOR_IE_WAREHOUSE_5,
    SIMPLE_INTERIOR_IE_WAREHOUSE_6,
    SIMPLE_INTERIOR_IE_WAREHOUSE_7,
    SIMPLE_INTERIOR_IE_WAREHOUSE_8,
    SIMPLE_INTERIOR_IE_WAREHOUSE_9,
    SIMPLE_INTERIOR_IE_WAREHOUSE_10,
    SIMPLE_INTERIOR_BUNKER_1,
    SIMPLE_INTERIOR_BUNKER_2,
    SIMPLE_INTERIOR_BUNKER_3,
    SIMPLE_INTERIOR_BUNKER_4,
    SIMPLE_INTERIOR_BUNKER_5,
    SIMPLE_INTERIOR_BUNKER_6,
    SIMPLE_INTERIOR_BUNKER_7,
    SIMPLE_INTERIOR_BUNKER_9,
    SIMPLE_INTERIOR_BUNKER_10,
    SIMPLE_INTERIOR_BUNKER_11,
    SIMPLE_INTERIOR_BUNKER_12,
    SIMPLE_INTERIOR_ARMORY_TRUCK_1,
    SIMPLE_INTERIOR_CREATOR_TRAILER_1,
    SIMPLE_INTERIOR_HANGAR_1,
    SIMPLE_INTERIOR_HANGAR_2,
    SIMPLE_INTERIOR_HANGAR_3,
    SIMPLE_INTERIOR_HANGAR_4,
    SIMPLE_INTERIOR_HANGAR_5,
    SIMPLE_INTERIOR_ARMORY_AIRCRAFT_1,
    SIMPLE_INTERIOR_DEFUNCT_BASE_1,
    SIMPLE_INTERIOR_DEFUNCT_BASE_2,
    SIMPLE_INTERIOR_DEFUNCT_BASE_3,
    SIMPLE_INTERIOR_DEFUNCT_BASE_4,
    SIMPLE_INTERIOR_DEFUNCT_BASE_6,
    SIMPLE_INTERIOR_DEFUNCT_BASE_7,
    SIMPLE_INTERIOR_DEFUNCT_BASE_8,
    SIMPLE_INTERIOR_DEFUNCT_BASE_9,
    SIMPLE_INTERIOR_DEFUNCT_BASE_10,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_MEDIUM_GARAGE,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_LOWEND_STUDIO,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_MIDEND_APARTMENT,
    SIMPLE_INTERIOR_CREATOR_AIRCRAFT_1,
    SIMPLE_INTERIOR_HUB_LA_MESA,
    SIMPLE_INTERIOR_HUB_MISSION_ROW,
    SIMPLE_INTERIOR_HUB_STRAWBERRY_WAREHOUSE,
    SIMPLE_INTERIOR_HUB_WEST_VINEWOOD,
    SIMPLE_INTERIOR_HUB_CYPRESS_FLATS,
    SIMPLE_INTERIOR_HUB_LSIA_WAREHOUSE,
    SIMPLE_INTERIOR_HUB_ELYSIAN_ISLAND,
    SIMPLE_INTERIOR_HUB_DOWNTOWN_VINEWOOD,
    SIMPLE_INTERIOR_HUB_DEL_PERRO_BUILDING,
    SIMPLE_INTERIOR_HUB_VESPUCCI_CANALS,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_SHERIFF,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_SHERIFF2,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_UNION_DEPOSITORY_CARPARK,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_SIMEON_SHOWROOM,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_ABATTOIR,
    SIMPLE_INTERIOR_HACKER_TRUCK,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_JEWEL_STORE,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_LIFE_INVADER,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_DJ_YACHT,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_MELANOMA_GARAGE,
    SIMPLE_INTERIOR_ARENA_GARAGE_1,
    SIMPLE_INTERIOR_CASINO,
    SIMPLE_INTERIOR_CASINO_APT,
    SIMPLE_INTERIOR_CASINO_VAL_GARAGE,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_HAYES_AUTOS,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_METH_LAB,
    SIMPLE_INTERIOR_ARCADE_PALETO_BAY,
    SIMPLE_INTERIOR_ARCADE_GRAPESEED,
    SIMPLE_INTERIOR_ARCADE_DAVIS,
    SIMPLE_INTERIOR_ARCADE_WEST_VINEWOOD,
    SIMPLE_INTERIOR_ARCADE_ROCKFORD_HILLS,
    SIMPLE_INTERIOR_ARCADE_LA_MESA,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_FIB_BUILDING,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_BIOLAB_AND_TUNNEL,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_FOUNDRY,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_MAX_RENDA,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_AIRCRAFT_CARRIER,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_AIRCRAFT_CARRIER_PART_2,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_AIRCRAFT_CARRIER_PART_3,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_AIRCRAFT_CARRIER_PART_4,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_AIRCRAFT_CARRIER_PART_5,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_AIRCRAFT_CARRIER_PART_6,
    SIMPLE_INTERIOR_RESTRICTED_INTERIOR_OMEGA,
    SIMPLE_INTERIOR_SOLOMONS_OFFICE,
    SIMPLE_INTERIOR_CASINO_NIGHTCLUB,
    SIMPLE_INTERIOR_SUBMARINE,
    SIMPLE_INTERIOR_MUSIC_STUDIO,
    SIMPLE_INTERIOR_AUTO_SHOP_LA_MESA,
    SIMPLE_INTERIOR_AUTO_SHOP_STRAWBERRY,
    SIMPLE_INTERIOR_AUTO_SHOP_BURTON,
    SIMPLE_INTERIOR_AUTO_SHOP_RANCHO,
    SIMPLE_INTERIOR_AUTO_SHOP_MISSION_ROW,
    SIMPLE_INTERIOR_CAR_MEET,
    SIMPLE_INTERIOR_FIXER_HQ_HAWICK,
    SIMPLE_INTERIOR_FIXER_HQ_ROCKFORD,
    SIMPLE_INTERIOR_FIXER_HQ_SEOUL,
    SIMPLE_INTERIOR_FIXER_HQ_VESPUCCI,
    SIMPLE_INTERIOR_ACID_LAB,
    SIMPLE_INTERIOR_JUGGALO_HIDEOUT,
    SIMPLE_INTERIOR_MULTISTOREY_GARAGE,
    SIMPLE_INTERIOR_SALVAGE_YARD_PALETO_BAY,
    SIMPLE_INTERIOR_SALVAGE_YARD_SANDY_SHORES,
    SIMPLE_INTERIOR_SALVAGE_YARD_LA_PUERTA,
    SIMPLE_INTERIOR_SALVAGE_YARD_STRAWBERRY,
    SIMPLE_INTERIOR_SALVAGE_YARD_MURIETTA_HEIGHTS,
    SIMPLE_INTERIOR_BAIL_OFFICE_MISSION_ROW,
    SIMPLE_INTERIOR_BAIL_OFFICE_WEST_VINEWOOD,
    SIMPLE_INTERIOR_BAIL_OFFICE_DEL_PERRO,
    SIMPLE_INTERIOR_BAIL_OFFICE_DAVIS,
    SIMPLE_INTERIOR_BAIL_OFFICE_PALETO_BAY,
    SIMPLE_INTERIOR_HACKER_DEN,
    SIMPLE_INTERIOR_FIELD_HANGAR,
    SIMPLE_INTERIOR_SMALL_BUSINESS_CAR_WASH,
    SIMPLE_INTERIOR_SMALL_BUSINESS_WEED_SHOP,
    SIMPLE_INTERIOR_SMALL_BUSINESS_HELI_TOURS,
    SIMPLE_INTERIOR_MANSION_TONGVA_HILLS,
    SIMPLE_INTERIOR_MANSION_WEST_VINEWOOD,
    SIMPLE_INTERIOR_MANSION_EAST_VINEWOOD,
    SIMPLE_INTERIOR_SOCIAL_CLUB_GARAGE,
    SIMPLE_INTERIOR_VINEWOOD_PREMIUM_GARAGE,
    SIMPLE_INTERIOR_MAX
};

struct JOB_STATS
{
    scrValue Wins;
    scrValue Losses;
    scrValue Kills;
    scrValue Deaths;
    scrValue PAD_0004; // unused
};

struct JOB_BET
{
    scrValue PAD_0000; // TODO
    scrValue Amount;
};

struct MISSION_BETS
{
    scrValue Identifier; // a random integer between 100 and 10000000
    JOB_STATS Stats;
    scrArray<32, JOB_BET> PlacedBets;
    scrValue CancelBetting;
};
static_assert(SCR_SIZEOF(MISSION_BETS) == 72);

struct PLAYER_BLIP
{
    scrValue PAD_0000;
    scrValue NumPassengersInVehicle;
    scrBitset<eBlipFlags> BlipFlags;
    scrEnum<eBlipType> PlayerVehicleBlipType; // can be used to spoof your blip as a tank, oppressor etc
    scrValue IdleDurationUntilBlipIsVisible;
    scrValue BlipVisibleDuration;
    scrValue MissionInteriorIndex; // can be used to spoof blip position
    scrVector MissionInteriorBlipLocation;
    scrValue MissionInteriorBlipRotation;
    scrValue UnknownOverride; // can also be used to spoof position
    scrVector UnknownOverridePosition;
};
static_assert(SCR_SIZEOF(PLAYER_BLIP) == 15);

struct YACHT_APPEARANCE
{
    scrValue PAD_0000; // TODO
    scrValue PAD_0001;
    scrValue PAD_0002;
    scrValue PAD_0003;
    scrValue PAD_0004;
    scrTextLabel63 Name;
    scrValue NameHash;
};
static_assert(SCR_SIZEOF(YACHT_APPEARANCE) == 22);

struct YACHT_DATA
{
    scrValue HasYacht;
    scrVector Position;
    scrValue TravelStage;
    scrValue TravelInProgress;
    scrArray<7> VehicleNetIds;     // the heli and the boats that spawn near the yacht
    scrValue YachtIndexPlayerIsIn; // owned or unowned
    scrValue UnkYachtIndex;        // TODO
    scrValue YachtIndexPlayerIsInCouldBeDriving;
    scrArray<2> NearbyYachts;
    scrValue ClosestYachtIndex;
    scrValue TurbulenceState; // controls random camera shakes when on a yacht
    scrValue DefenseSetting;
    YACHT_APPEARANCE Appearance;
    scrValue RemoveClothingWhileInHotTub;
    scrValue MissionYachtOwnerHandleHash; // always -1 or NETWORK::NETWORK_HASH_FROM_PLAYER_HANDLE(PLAYER::PLAYER_ID())
    scrValue SpawnAccess;                 // "spawn access"?
    scrValue MissionYachtIndex;
};
static_assert(SCR_SIZEOF(YACHT_DATA) == 49);

struct SMPL_INTERIOR_DATA
{
    scrValue Flags; // TODO!!!
    scrValue Flags2;
    scrValue Flags3;
    scrValue Flags4;
    scrValue Flags5;
    scrValue Flags6;
    scrValue Flags7;
    scrValue Flags8; // added b3258
    scrEnum<eSimpleInteriorIndex> Index;
    scrValue InstanceId;
    scrValue AllowedGoons;
    scrValue Owner;
    scrValue VehicleOwner;
    scrVector SpecialVehicleSpawnPosition;
    scrValue SpecialVehicleSpawnHeading;
    scrValue EnteringSimpleInteriorIndex;
    scrValue SpecialVehicleSimpleInteriorIndex; // MOC, Terrorbyte etc
    scrEnum<eSimpleInteriorIndex> UnkSimpleInteriorIndex;
    scrEnum<eSimpleInteriorIndex> UnkSimpleInteriorIndex2;
    scrVector AvengerPosition;
    scrVector AvengerPosition2; // not sure how this is different from the field above
    scrValue AvengerHeading;
    scrValue MissionSpawnSimpleInteriorIndex;
    scrValue InteriorSubtype; // nightclub vs nightclub garage etc
};
static_assert(SCR_SIZEOF(SMPL_INTERIOR_DATA) == 30);

// yes there's a struct for leaving your clubhouse
struct LEAVE_CLUBHOUSE
{
    scrValue Active;
    scrValue Active2;
    scrValue Identifier;
    scrValue ExitLocation;
    scrArray<32> ParticipantHashes;
};
static_assert(SCR_SIZEOF(LEAVE_CLUBHOUSE) == 37);

struct ARCADE_GAME
{
    scrBitset<eArcadeGameBitset> Bits;
    scrValue CabinetIndex;
    scrValue PAD_0002;    // The only valid value is 0 so idk
    scrValue CabinetGame; // TODO
    scrValue GameStage;
};
static_assert(SCR_SIZEOF(ARCADE_GAME) == 5);

struct GlobalPlayerBDEntry
{
    scrEnum<eFreemodeState> FreemodeState;
    MP_SCRIPT_DATA CurrentScript;
    scrValue PAD_0022[11]; // unused
    scrValue PlayersVisible;
    scrValue PlayersTracked;
    scrBitset<eAnimationBitset> AnimationBitset;
    scrValue NumSuccessfulHoldups; // resets every 12 minutes
    scrValue PAD_0037;
    scrValue PersonalVehicleNetId;
    scrValue UnkVehicleNetId;
    scrValue UnkVehicleNetId2;
    scrArray<2> UnkVehicleNetIds;
    scrValue DeliveryMechanicNetId;
    scrValue DeliveryMechanicNetId2;
    scrValue SpawningVehicleLiveryIndex;
    scrValue SpawningVehiclePrimaryColor;
    scrValue SpawningVehicleSecondaryColor;
    scrValue AvengerNetId;
    scrValue DeliveryMechanicNetId3; // wtf is this?
    scrValue TerrorbyteNetId;        // or is it the MOC?
    scrValue SubmarineNetId;
    scrValue DinghyNetId;
    scrValue DeliveryMechanicNetId4; // another one...
    scrValue AcidLabNetId;
    scrValue DeliveryBikeNetId;
    scrValue BountyTransporterNetId; // added b3258
    scrValue FieldDusterNetId;       // added b3407
    scrValue MansionHeliNetId;       // added b3407
    scrValue PAD_0057;               // (@59 as of b3407)
    scrValue PAD_0058[15];           // confirmed these are not used by PC scripts
    PLAYER_BLIP PlayerBlip;
    scrValue NeedToPopulateSessionStartTime; // the session start time is unused
    scrValue PAD_0089[33];                   // TODO (@91 as of b3407) // 32 -> 33 (new field) b3407
    scrEnum<eMissionType> MissionType;
    scrValue SpawningVehicle;
    scrValue PAD_0123[3]; // confirmed these are not used by PC scripts
    MISSION_BETS MissionBets;
    scrValue RadarBlipVisibliltyMechanicEnabled;
    scrBitset<ePlayerStateFlags> PlayerStateFlags;
    scrBitset<ePlayerStateFlags2> PlayerStateFlags2; // TODO
    scrValue PlayerStateFlags3;                      // TODO
    scrValue CarMeetModShopSlotPreTakeover;
    scrValue CurrentCarMeetSlotOwnerIndex; // can be player or player's CEO/MC leader
    scrValue CarMeetModShopSlotPostTakeover;
    scrValue CarMeetModdingVehicleModel;
    scrValue CarMeetCurrentlySeatedVehicleOwner;
    scrVector PlayerPosition; // updates every two seconds, used by spectate
    scrValue OffRadarActive;
    scrValue PassengerOfVehicleWithOffRadarDriver;
    scrValue GoonOfBossWithOffRadar;
    scrValue RevealPlayersActive;
    scrValue RemoteWantedLevelPlayer; // cut content but still works
    scrValue RemoteWantedLevelAmount;
    scrValue RemoteWantedLevelRemovePlayer; // doesn't work at all
    scrValue UnkTeleportStage;
    scrBitset<eActivityFlags> ActivityFlags;
    scrValue NumReservedMissionPeds;
    scrValue NumReservedMissionVehicles;
    scrValue NumReservedMissionObjects;
    scrValue TransitionSessionState;       // TODO reverse enum
    scrVector TransitionReturningPosition; // TODO
    scrTextLabel23 TransitionContentIDToLaunch;
    scrValue RespawnState;
    scrValue LastRespawnTime;
    scrValue CollisionLoaded;
    scrValue CommitingSuicide;
    scrValue RespawningInVehicleAsDriver;
    scrValue RespawningInVehicle;
    scrValue PAD_0238; // this value is set but not read at all by any PC scripts
    scrBitset<eGamerTagFlags> GamerTagFlags;
    scrValue IsMale;
    scrValue ArmwrestlingLocationFlags;
    scrValue PAD_0242; // TODO
    scrValue GamerTagShowArrow;
    scrValue CarWashInProgress;
    scrValue CurrentInteriorIndex;
    scrValue CurrentShopIndex;  // things like clothing and tattoo stores
    scrValue CurrentStoreIndex; // the stores in the map which can be held up
    scrValue ShopActive;        // any shop
    scrValue InTaxi;
    scrValue Haircut; // @250 as of 1.67
    scrValue PrimaryHairColor;
    scrValue SecondaryHairColor;
    scrValue FriendlyPlayers; // bitset of player team relgroups that obtain a Respect relationship with player
    scrValue IsInvisible;
    scrValue InImpromptuDeathmatch;
    scrVector ImpromptuDeatmatchStartPosition;
    scrValue PAD_0569; // not read by scripts, impromptu DM related
    scrValue MissionLoseAnimType;
    scrValue MissionWinAnimType; // verify
    scrValue MissionCrewAnimType;
    scrValue RallyRaceAnim;
    scrValue IsRallyRace;
    scrValue JustGetsPulledOutWhenElectrocuted;
    scrValue HeistCutSelectionStage; // the only valid values seem to be 6 and 7
    scrValue IsBadsport;
    scrValue MentalState;
    scrValue IsRockstarDev; // dev dlc check and not the CNetGamePlayer flag so can be used to detect YimMenu
    scrValue ScreenFadedOut;
    scrValue TimeTrialActive;
    YACHT_DATA YachtData;
    SMPL_INTERIOR_DATA SimpleInteriorData;
    scrValue PAD_0350; // TODO
    scrValue PAD_0351; // unused vehicle/interior stuff
    scrValue BlipShownBitset;
    LEAVE_CLUBHOUSE LeaveClubhouse;    // @353 as of 1.67
    scrValue Friends;                  // bitset of players that are friends
    scrVector InteriorVehiclePosition; // for terrorbyte and MOC, used to fake player blip position on map
    scrValue InteriorVehicleHeading;
    scrVector AcidLabPosition; // not read by the scripts
    scrValue AcidLabHeading;
    scrValue VehicleTurretsActive;                       // bitset
    scrArray<4, scrVector> VehicleTurretsCameraPosition; // 3->4 in 1.67
    scrValue PAD_0416;                                   // TODO
    scrValue DozerDetected;                              // very shady stuff, anticheat?	       @414 as of 1.67
    scrArray<6> MissionTurretParticipants;
    scrValue PAD_0425; // some seat index
    scrValue MissionTurretSlot;
    scrBitset<eOrbitalBitset> OrbitalBitset;
    scrValue FacilityIntroCutsceneInProgress;
    scrValue FacilityIntroCutsceneStarted; // like above but is enabled 2 stages earlier
    scrValue PAD_0430;                     // todo
    scrValue BeingSolicitedByProstitute;   // why tf is this used by the orbital cannon?
    scrVector DronePosition;               // updates every second
    scrValue DroneHeading;                 // @432 as of 1.67
    scrValue OrbitalBitset2;               // ugh
    scrValue CurrentlyUsingArenaTrapIndex;
    scrValue CurrentlyUsingArenaTrapActivatedTime;
    ARCADE_GAME ArcadeGame;
    scrValue DancePartner;
    scrValue CayoPericoFlags;
    scrValue BeachPartyFlags;
    scrValue PAD_0477[10]; // I don't think we'll ever be able to figure out what this does
    scrValue ThreeCardPokerStyle;
    scrValue BlackjackStyle;
    scrBitset<eOutOfSightFlags> OutOfSightFlags;
    scrVector OutOfSightArea;
    scrValue AmmunationWeaponPartFlags;
    scrValue LastKilledBy; // @461 as of 1.67
    scrValue CanSpawnGunVan;
};
static_assert(SCR_SIZEOF(GlobalPlayerBDEntry) == 468);

struct GLOBAL_PLAYER_BD
{
    scrArray<32, GlobalPlayerBDEntry> Entries;
};
static_assert(SCR_SIZEOF(GLOBAL_PLAYER_BD) == 14977);