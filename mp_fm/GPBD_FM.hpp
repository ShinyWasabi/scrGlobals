#pragma once
#include "../Types.hpp"

#define NUM_PROPERTY_INTERIORS 36 // (30 -> 31) b3095, (31 -> 32) b3258, (32 -> 33) b3407, (33 -> 36) b3717

enum class eMissionDataFlags
{
    MISSION_LAUNCHED = 0,
    JOB_DOWNLOADED = 2,
    STARTING_JOB = 3,
    REQUESTING_SCRIPT = 4,
    LAUNCHED_SCRIPT = 6,         // should be set if MISSION_LAUNCHED is set
    AUTO_START_ON_PROXIMITY = 7, // used by gang attack
    NJVS_QUICK_MATCH = 8,
    VOTE_LIKED = 10,
    VOTE_DISLIKED = 11,
    NO_VOTE = 25
}; // TODO

enum class eTutorialBitset
{
    IN_TUTORIAL_RACE = 0,
    TUTORIAL_RACE_ACTIVE = 2,
    SHOW_CREDITS = 4,
    NEED_FREE_VEHICLE = 6
};

enum class eGangCallServices
{
    MUGGER = 0,
    MERCENARY = 1
};

enum class eVehicleSelectionState
{
    NONE,
    SELECTING,
    SELECTED
};

enum class eStatState
{
    NONE,
    LETHARGIC,
    OUT_OF_SHAPE,
    HEALTHY,
    ATHLETE,
    TRI_ATHLETE,
    UNTRAINED,
    SPRAY_AND_PRAY,
    POLICE_TRAINING,
    MILITARY_TRAINING,
    DEAD_EYE,
    FRAGILE,
    WEAK,
    AVERAGE,
    TOUGH,
    BODYBUILDER,
    CLUMSY,
    LOUD,
    SNEAKY,
    HUNTER,
    NINJA,
    DANGEROUS,
    RC_PILOT,
    COMMERCIAL_PILOT,
    FIGHTER_PILOT,
    ACE,
    UNLICENSED,
    SUNDAY_DRIVER,
    COMMUTER,
    STREET_RACER,
    PRO_RACER,
    NORMAL,
    UNSTABLE,
    DERANGED,
    MANIAC,
    PSYCHOPATH,
    DRUNK
};

enum class ePropertyInteriorFlags
{
    OWNER_OF_INTERIOR = 0,
    VISITOR_OF_INTERIOR = 1, // mutually exclusive with above flag
    CONCEAL_WHEN_DEAD = 12,
    RENOVATING_PROPERTY = 19,
    PREVIEWING_DECOR = 20,
    RENOVATING_CLUBHOUSE = 21,
    USING_YACHT_RM_BATH1 = 22,
    USING_YACHT_RM_BATH3 = 23,
    USING_YACHT_RM_WEE_BATHROOM = 25,
    GUN_LOCKER_OPEN = 27,
    OFFICE_SAFE_OPEN = 28,
    OFFICE_ASSISTANT_MALE = 29
};

enum class eInteriorStyleFlags
{
    GUN_LOCKER_SHOW_PUMP_SHOTGUN = 0,
    GUN_LOCKER_SHOW_MICRO_SMG = 1,
    GUN_LOCKER_SHOW_C4 = 2, // proximity or sticky
    GUN_LOCKER_SHOW_GRENADE = 3,
    GUN_LOCKER_SHOW_COMBAT_MG = 4,
    GUN_LOCKER_SHOW_MARKSMAN_RIFLE = 5,
    PURCHASED_SNACKS = 6,
    PURCHASED_INTERIOR_RENOVATIONS = 7,
    FORCE_OFFICE_ASSISTANT_SPAWN = 8,
    ASSISTANT_ANIMATION_OVER = 9,
    CHANGE_INTERIOR_DECOR_OFFICE_HELP_SHOWN = 11,
    CHANGE_INTERIOR_DECOR_APARTMENT_HELP_SHOWN = 12,
    OWNS_OFFICE_BEDROOM = 13,
    OWNS_CLUBHOUSE_BIKE_SHOP = 16,
    OWNS_OFFICE_GUN_LOCKER = 17,
    OWNS_CLUBHOUSE_WALLS = 18, // ???
    OWNS_CLUBHOUSE_FURNISHINGS = 19,
    OWNS_CLUBHOUSE_DECORS = 20
};

enum class eBusinessHubProductIndex
{
    CARGO,
    WEAPONS,
    COCAINE,
    METH,
    WEED,
    FORGED_DOCUMENTS,
    COUNTERFEIT_CASH
};

struct PLAYLIST_DATA
{
    scrValue Host;
    scrValue Flags;
    scrValue PAD_0002;
    scrValue CurrentMission;
    scrValue TotalMissions;
    scrValue PAD_0006;
};
static_assert(SCR_SIZEOF(PLAYLIST_DATA) == 6);

// local copy can be found at Global_2680247
struct JOB_SETTINGS
{
    scrArray<31> Settings; // indices vary based on job type. take a look at func_8988 in fmmc_launcher if you wish to change them
    scrValue NumPlayers;   // verify
    scrValue PAD_0033;
    scrValue SpawnSimpleInteriorIndex;
    scrValue PAD_0035; // unused
    scrValue MatchmakingOpen;
    scrValue ContentHash;
};
static_assert(SCR_SIZEOF(JOB_SETTINGS) == 38);

struct VEHICLE_SELECTION
{
    scrValue Active;
    scrValue Active2;
    scrValue PAD_0002; // set to host by fmmc but not read at all
    scrValue VehicleModel;
    scrValue CreatorIndex;
    scrEnum<eVehicleSelectionState> State;
    scrValue PrimaryColor;
    COLOR_3 CustomPrimaryColor;
    COLOR_3 CustomSecondaryColor;
    scrValue Partner; // for rally races?
    GAMER_HANDLE PartnerHandle;
    scrValue PreferredRole; // target assault races
    scrValue PAD_0028;      // TODO
    scrValue ControlType;   // 1 = kb&m 2 = controller
    scrValue BettingFlags;
    scrValue Team;
    scrValue Flags;
    scrValue JoinedMembers; // bitset of joined transition members set by the host
    scrValue AdversaryOutfitIndex;
    scrEnum<eStatState> StatState; // see func_9142 in fmmc_launcher, shown to other players
    scrValue CashWager;            // shown to other players...
    scrValue PAD_0037[2];          // TODO
    scrValue PAD_0039;             // TODO random integer between 1 and 11
};
static_assert(SCR_SIZEOF(VEHICLE_SELECTION) == 40);

struct STRIKE_TEAM
{
    scrValue Target;
    TIMER Cooldown;
    scrValue CancelStrikeTeam; // read but not written to
    scrValue Level;
};
static_assert(SCR_SIZEOF(STRIKE_TEAM) == 5);

struct PLAYER_STATS
{
    scrValue Team;
    scrValue RP;
    scrValue CrewRP;
    scrValue WalletBalance;
    scrValue HeistBonus;
    scrValue GlobalRP;
    scrValue Rank;
    scrTextLabel31 CrewTitle;
    scrValue TotalRacesWon;
    scrValue TotalRacesLost;
    scrValue TimesFinishRaceAsTop3;
    scrValue TimesFinishRaceLast;
    scrValue TimesRaceBestLap;
    scrValue TotalDeathmatchesWon;
    scrValue TotalDeathmatchesLost;
    scrValue TotalTeamDeathmatchesWon;
    scrValue TotalTeamDeathmatchesLost;
    scrValue Shots;
    scrValue Hits;
    scrValue KdRatio;
    scrValue DropoutRate;
    scrValue KillsOnPlayers;
    scrValue DeathsByPlayers;
    scrValue TotalFinishDeathmatchAsTop3;
    scrValue TotalFinishDeathmatchLast;
    scrValue DartsTotalWins;
    scrValue DartsTotalMatches;
    scrValue ArmwrestlingTotalWins;
    scrValue ArmwrestlingTotalMatches;
    scrValue TennisMatchesWon;
    scrValue TennisMatchesLost;
    scrValue BaseJumpWins;
    scrValue BaseJumpLosses;
    scrValue GolfWins;
    scrValue GolfLosses;
    scrValue ShootingRangeWins;
    scrValue ShootingRangeLosses;
    scrValue ShootingAbility;
    scrValue MissionWins;
    scrValue TotalMissionsPlayed;
    scrValue SurvivalWins;
    scrValue TotalSurvivalsPlayed;
    scrValue PAD_0049; // TODO
    scrValue MissionsCreated;
    scrValue CommunicationRestrictions;
    scrValue CanSpectate;
    scrValue MostFavoriteStation;
    scrValue ProstitutesFrequented;
    scrValue LapDancesBought;
    scrValue Money;
    scrValue WeaponAccuracy;
    scrValue FavoriteVehicle;
    scrValue FavoriteWeapon;
};
static_assert(SCR_SIZEOF(PLAYER_STATS) == 60);

struct EXEC_WAREHOUSE_INFO
{
    scrValue Index;
    scrValue Stock;
    scrValue PAD_0002; // unused
};
static_assert(SCR_SIZEOF(EXEC_WAREHOUSE_INFO) == 3);

struct IE_WAREHOUSE_DATA
{
    scrValue Index;
    scrValue NumVehicles;
    scrArray<40> Vehicles;
    scrValue PAD_0043; // set to zero and not read
    scrValue OwnedWarehouseVariation;
};
static_assert(SCR_SIZEOF(IE_WAREHOUSE_DATA) == 45);

struct FACTORY_INFO
{
    scrValue Index;
    scrValue TotalProduct;
    scrValue TotalSupplies;
    scrValue TotalSupplies2; // TODO: what's the difference?
    scrValue PAD_0004;
    scrValue EquipmentUpgrades;
    scrValue Running;
    scrValue SetupDone;
    scrValue PAD_0008;
    scrValue Research; // valid only for factory index 5 (bunker)
    scrValue StaffState;
    scrValue ProductValue;        // untested
    scrValue StaffAssignmentType; // valid only for factory index 5 (bunker) 0 = manufacturing, 1 = research, 2 = both
};
static_assert(SCR_SIZEOF(FACTORY_INFO) == 13);

struct HANGAR_DATA
{
    scrValue Index;
    scrValue AppearanceBitset;
    scrValue PAD_0002; // unused
    scrValue TotalContraband;
    scrValue PAD_0004; // unused, a function tries to set it to something but is never called with the right parameters. it isn't read either
    scrValue SetupDone;
};
static_assert(SCR_SIZEOF(HANGAR_DATA) == 6);

// facility
struct DEFUNCT_BASE_DATA
{
    scrValue Index;
    scrValue AppearanceBitset;
    scrValue AppearanceBitset2;
    scrValue ObtainedAwards;
    scrValue PAD_0004; // unused, a function tries to set it to something but is never called with the right parameters. it isn't read either
    scrValue PAD_0005;
    scrValue TotalContraband; // wat
};
static_assert(SCR_SIZEOF(DEFUNCT_BASE_DATA) == 7);

// nightclub
struct BUSINESS_HUB_DATA
{
    scrValue Index;
    scrValue TotalContraband;     // not read by the scripts
    scrValue ProducingBusinesses; // bitset
    scrValue ProducingFactories;  // bitset
    scrValue Upgrades;
    scrValue PAD_0005;
    scrValue PAD_0006;                                            // not read by the scripts
    scrValue SetupBitset;                                         // includes owned DJs
    scrArray<8, scrEnum<eBusinessHubProductIndex>> ProductStocks; // see eBusinessHubProductIndex
    scrArray<16> PAD_0017;                                        // have no clue what this is
    scrArray<8> TotalSoldProduct;
};
static_assert(SCR_SIZEOF(BUSINESS_HUB_DATA) == 43);

// also the nightclub? strange
struct NIGHTCLUB_DATA
{
    scrValue Index; // same as BusinessHubData::Index
    scrValue AppearanceBitset;
    scrValue AppearanceBitset2;
    scrValue AccessSettings; // TODO: figure out how this works
    scrValue Popularity;     // 0.0 to 1.0
    scrValue SafeCashValue;
    scrValue EntryCost; // can be set to any arbitrary value
    scrValue CroudVariation;
    scrValue DanceAwardProgress;  // "Gold Dancer trophy unlocked."
    scrValue DanceAward2Progress; // "Gold Battler trophy unlocked."
    TIMER DJMusicChangeTimer;
};
static_assert(SCR_SIZEOF(NIGHTCLUB_DATA) == 12);

struct ARENA_GARAGE_DATA
{
    scrValue Index; // always one for obvious reasons
    scrValue OwnedGarageFloorLevel;
    scrValue AppearanceBitset;
    scrValue AppearanceBitset2;
    scrValue InteriorTypeA;
    scrValue InteriorTypeB;
    scrValue SpectatingIndex;
    scrValue SpectatingType;
    scrValue PAD_0008; // unused
};
static_assert(SCR_SIZEOF(ARENA_GARAGE_DATA) == 9);

struct INSIDE_TRACK
{
    scrTextLabel63 PlayerName;
    scrValue BetHorseID;
    scrValue BetChips;
};
static_assert(SCR_SIZEOF(INSIDE_TRACK) == 18);

// casino penthouse
struct CASINO_APARTMENT_DATA
{
    scrValue Index;    // always one for obvious reasons
    scrValue PAD_0001; // unused
    scrValue AppearanceBitset;
    scrValue AppearanceBitset2;
    scrValue PAD_0005[2];
    INSIDE_TRACK InsideTrack;
};
static_assert(SCR_SIZEOF(CASINO_APARTMENT_DATA) == 24);

struct ARCADE_DATA
{
    scrValue Index;
    scrValue AppearanceBitset;
    scrValue AppearanceBitset2;
    scrValue AppearanceBitset3;
    scrValue UNK_0004;
    scrValue SafeCashValue;
};
static_assert(SCR_SIZEOF(ARCADE_DATA) == 6);

struct ARCADE_MACHINES
{
    scrValue OrderedMachinesBitset;
    scrValue ArrivedMachinesBitset;
};
static_assert(SCR_SIZEOF(ARCADE_MACHINES) == 2);

struct SUBMARINE_DATA
{
    scrValue AppearanceBitset;
    scrValue Model; // not read by the scripts, always set to HASH("kosatka")
    scrValue Color; // "PACKED_MP_INT_KOSATKA_COLOUR"
    scrValue Flag;  // "PACKED_MP_INT_KOSATKA_FLAG"
    scrValue LastGuidedMissileUseTime;
    scrValue PAD_0005; // unused
};
static_assert(SCR_SIZEOF(SUBMARINE_DATA) == 6);

struct AUTOSHOP_DATA
{
    scrValue Index;
    scrValue AccessSetting;
    scrValue AppearanceBitset;
    scrValue AppearanceBitset2;
    scrValue PAD_0004;
    scrArray<2> ModdingVehicles; // VEHICLE_INDEX, not NETWORK_INDEX
};
static_assert(SCR_SIZEOF(AUTOSHOP_DATA) == 8);

// LS car meet
struct CAR_CLUB_DATA
{
    scrValue Flags;
    scrValue Reputation;
    scrValue ReputationLevel;
    scrValue TestTrackAccess; // unused?
};
static_assert(SCR_SIZEOF(CAR_CLUB_DATA) == 4);

// agency
struct FIXER_HQ_DATA
{
    scrValue Index;
    scrValue AppearanceBitset;
    scrValue SafeCashValue;
};
static_assert(SCR_SIZEOF(FIXER_HQ_DATA) == 3);

// eclipse blvd garage
struct MULTI_STOREY_GARAGE_DATA
{
    scrValue Index; // always one for obvious reasons
    scrValue AppearanceBitset;
    scrValue AppearanceBitset2;
    scrArray<2> GarageTints;
};
static_assert(SCR_SIZEOF(MULTI_STOREY_GARAGE_DATA) == 6);

struct SALVAGE_YARD_DATA
{
    scrValue Index;
    scrValue PAD_0001;
    scrValue AppearanceBitset;
    scrValue TowTruckColor;
    scrValue TowTruckType; // TODO
    scrValue VehicleRobVehicleIndex;
    scrValue TotalEarnings;
};
static_assert(SCR_SIZEOF(SALVAGE_YARD_DATA) == 7);

struct BAIL_SHOP_DATA
{
    scrValue Index;
    scrValue StyleFlags;
    scrValue SafeCashValue;
    scrValue PAD_0001[9]; // a field was removed in b3407
};
static_assert(SCR_SIZEOF(BAIL_SHOP_DATA) == 12);

struct HACKER_DEN_DATA
{
    scrValue Index; // always one for obvious reasons
    scrValue Flags;
    scrValue SafeCashValue;
};
static_assert(SCR_SIZEOF(HACKER_DEN_DATA) == 3);

struct FIELD_HANGAR_DATA
{
    scrValue Index;
    scrValue Flags;
};
static_assert(SCR_SIZEOF(FIELD_HANGAR_DATA) == 2);

struct PROPERTY_DATA
{
    scrArray<NUM_PROPERTY_INTERIORS> PropertyIds;
    scrBitset<ePropertyInteriorFlags> Flags; // I really don't want to indent everything again
    scrValue RingingPlayers;                 // bitset of players requesting entry into property
    scrValue Index;                          // the value you pass to the send to apartment TSE
    scrValue Instance;
    scrValue ExteriorIndex;
    scrValue ExteriorOwner;
    scrArray<32> RingingPlayersState; // 0 = ringing, 1 = accepted, 2 = denied
    GAMER_HANDLE OwnerHandle;         // can be used to bypass RID spoofing when player is inside interior
    scrArray<NUM_PROPERTY_INTERIORS> EclipseTheme;
    scrValue ApartmentType; // normal vs stilt vs eclipse
    scrValue OwnerInstance; // same as Instance in most cases
    scrArray<5, EXEC_WAREHOUSE_INFO> ExecutiveWarehouseInfos;
    scrValue OfficeSafeMoneyMultiplier;
    scrBitset<eInteriorStyleFlags> StyleFlags;
    scrValue PAD_0134; // unused
    scrValue AssistantGreetingChoice;
    scrValue AssistantDialogBitset;
    scrValue AssistantDialogBitset2;
    scrValue LifetimeCargoMissionsComplete; // used for trophy type
    scrValue CasinoChipsMultiplier;
    scrValue AssistantDialogBitset3;
    scrValue AssistantDialogBitset4;
    scrValue AssistantDialogBitset5;
    scrValue AssistantDialogBitset6; // do we REALLY need 6 bitsets for assistant dialog?
    IE_WAREHOUSE_DATA IEWarehouseData;
    scrValue Garage1DataBitset;
    scrValue Garage2DataBitset;
    scrValue Garage3DataBitset;
    scrValue ModshopDataBitset;
    scrArray<7, FACTORY_INFO> FactoryInfos;
    scrValue TotalBunkerResearch; // (@291 b889g9)
    scrValue CurrentBunkerResearchProgress;
    // scrValue BunkerDecorVariation; REMOVED b889g9
    scrValue MOCBitset;
    scrValue MOCColor;    // bitset for some reason
    scrValue PAD_0290[2]; // unused
    scrValue GunShopFlags;
    HANGAR_DATA HangarData;
    scrValue PAD_0299;
    DEFUNCT_BASE_DATA DefunctBaseData;
    scrValue AvengerInteriorDecorFlags; // "PACKED_MP_INT_ARMORY_AIRCRAFT_INTERIOR_v0"
    scrValue PAD_0308[2];               // one field removed here b889g9
    BUSINESS_HUB_DATA BusinessHubData;
    NIGHTCLUB_DATA NightclubData;
    scrValue PAD_0365;
    scrValue TerrorbyteDesign;
    scrValue PAD_0367;
    scrValue AcidLabRadio;
    scrValue TerrorbyteRadio;
    scrValue NanoDroneCooldown;
    scrValue HostOfInteriorScript;
    ARENA_GARAGE_DATA ArenaGarageData;
    scrValue ArcadeJukeboxStation; // for simple interior type 17
    scrValue JukeboxFavoritePlaylist;
    scrValue ClubhouseBarCashAmount;
    scrValue DefaultJukeboxStation;
    scrValue FreakshopJukeboxStation;
    scrValue PAD_0386; // TODO
    scrValue MOCModel; // used by the bunker script to detect exits with MOC
    scrValue PAD_0388; // unused
    scrValue TerrorbyteModel;
    scrArray<7> PAD_0390; // some property interior stuff
    scrValue PAD_0398[4];
    scrValue OfficeGarageModdingVehicleSlot;
    scrValue CurrentOfficeGarageFloor;
    CASINO_APARTMENT_DATA CasinoApartmentData; // @405 as of 1.67
    ARCADE_DATA ArcadeData;
    ARCADE_MACHINES ArcadeMachines;
    scrArray<41> ArcadeMachineSlots;
    scrValue PAD_0478; // TODO
    SUBMARINE_DATA SubmarineData;
    AUTOSHOP_DATA AutoShopData;
    SALVAGE_YARD_DATA SalvageYardData;
    scrArray<2> AutoShopArcadeMachineSlots;
    CAR_CLUB_DATA CarClubData;
    FIXER_HQ_DATA FixerHQData;
    scrValue PAD_0503; // not read by the scripts
    scrValue PAD_0504;
    scrValue CurrentlyModdingVehicleFixerHQ;
    MULTI_STOREY_GARAGE_DATA MultiStoreyGarageData; // @507 as of 1.67
    scrValue FreakshopBits;                         // 0: has weapon workshop, 1: radio enabled
    scrValue VinewoodGarageBits;                    // added b812g9, 0 seems to indicate a cutscene
    BAIL_SHOP_DATA BailShopData;
    HACKER_DEN_DATA HackerDenData;
    FIELD_HANGAR_DATA FieldHangarData;
};
static_assert(SCR_SIZEOF(PROPERTY_DATA) == 549);

struct BIKER_CONTRACTS
{
    scrArray<4> ActiveContractMissions;
    scrValue SelectedContractMission;
    scrValue Enabled;
};
static_assert(SCR_SIZEOF(BIKER_CONTRACTS) == 7);

// rewritten b811g9 to integrate GTA+ stuff
struct NIGHTCLUB_SALE
{
    scrValue BuyerIndex;                            // 0
    scrValue NumSoldItems;                          // 1
    scrValue SaleAmount;                            // 2
    scrValue SaleAmountWithMembershipModifiers;     // 3
    scrValue TotalSaleAmountWithMembershipModifers; // 4
    scrValue TotalSaleAmount;                       // 5
    scrValue UnkSaleAmount;                         // 6 some kind of partial sum over certain goods, never read
    scrValue BuyerIndex2;                           // 7 min(BuyerIndex, 3)
};
static_assert(SCR_SIZEOF(NIGHTCLUB_SALE) == 8);

struct ARENA_WAR_DATA
{
    scrValue PointsTier;
    scrValue SkillLevel;
    scrValue TrinketBitset; // MP_STAT_ARN_BS_TRINKET_SAVED
};
static_assert(SCR_SIZEOF(ARENA_WAR_DATA) == 3);

struct GPBD_FM_ENTRY
{
    scrValue CurrentActivity;
    scrValue MissionScriptInstance;
    scrValue PAD_0002; // TODO
    scrValue NumFreeSpectatorSlots;
    scrValue NumPlayersInTransition; // not really
    scrValue NJVSVoteState;          // voting screen shown after a mission ends
    scrValue NJVSVoteContentBitset;
    scrValue NJVSChoiceMade;
    scrValue NJVSLeaveState; // network error or quit
    scrValue JobPoints;      // can be spoofed to change the "JP" value in the player list
    scrValue NextHost;       // transfer transition host when joining next job
    PLAYLIST_DATA PlaylistData;
    scrTextLabel63 JobName;
    scrArray<2> ActiveGunRange; // this should have really been an enum lol
    MP_SCRIPT_DATA MissionScriptData;
    scrValue PAD_0057; // added b3258, some mission thing
    JOB_SETTINGS JobSettings;
    scrValue FMMCLauncherState;
    VEHICLE_SELECTION VehicleSelection;
    scrValue JobStartCloudTime; // this is a struct but too lazy to create one
    scrValue ContentHash;
    scrValue PAD_0138; // unused
    scrBitset<eTutorialBitset> TutorialBitset;
    scrBitset<eGangCallServices> GangCallRequestedServices;
    scrValue GangCallTarget; // can be used to send muggers/hit squad
    scrBitset<eGangCallServices> GangCallSentServices;
    scrValue TutorialBitset2; // @144 as of b889g9
    scrTextLabel23 PlayingContentUsedId;
    scrTextLabel23 MatchId;
    // scrValue PAD_0156[8];         // unused (REMOVED b889g9)
    scrTextLabel63 DisplayJobName; // as shown in the playerlist? (@157 b889g9)
    STRIKE_TEAM StrikeTeam;
    scrValue PAD_0185[7]; // pad
    scrValue FMMCState;
    scrValue PAD_0193; // TODO
    scrValue KillStreak;
    scrValue NumSuicides;      // deducts RP reward in missions
    scrValue DeathmatchBounty; // "You have been deducted $~1~ for being idle for too long, and you now have a bounty placed on you."
    scrValue CollectedBounty;
    scrValue AliveDeathmatchPlayers;
    scrValue WantedLevelFlags;
    scrArray<2> PAD_0201;
    scrValue HairdoShopIndex;
    scrValue PAD_0204;
    PLAYER_STATS PlayerStats;
    scrValue PAD_265;
    scrValue Mood;
    PROPERTY_DATA PropertyData; // @260 as of b889g9
    scrValue PAD_0779[4];       // TODO
    scrValue PAD_0783[12];      // no clue what it does but it looks rather interesting
    scrValue AssistedKillFlags;
    scrValue UnkNetworkId;
    scrValue SpawningUnkVehicle;
    scrValue MeltdownComplete; // yes, the singleplayer mission "Meltdown" (michael4)
    scrValue UNK_0799;
    scrValue GangAttackTarget; // triggers unique dialog from some phone NPCs
    scrValue ActivePVSlot;
    scrValue SpectatingPlayer;
    scrValue PAD_0803;
    scrArray<3> ActiveAmbientWeaponPickups; // size 2 -> 3 b3095
    scrArray<6> OfficeMapMarkers;
    scrValue OfficeLargestMoneyThresholdIndex;
    scrArray<2> EnabledOfficeCashPiles;
    scrArray<2> EnabledClubhouseCashPiles;
    BIKER_CONTRACTS BikerContracts;
    scrValue CasinoWonBitset; // can be used to tamper with the casino PA system
    scrValue PAD_0829[2];
    scrValue CameraPositionOverriden;
    scrVector OverrideCameraPosition;
    scrValue PAD_0835;
    scrValue HeliRappelFlags;
    scrValue PAD_0837; // some more aircraft flags
    scrValue RespawningToPreviousCheckpoint;
    NIGHTCLUB_SALE NightclubSale; // @874 as of b812g9
    scrValue SeatingIndex;
    ARENA_WAR_DATA ArenaWarData; // @883 as of b812g9
    // scrValue PAD_0861[2]; removed b889g9
    scrValue ApartmentEnterFlags;
    // scrVector AvengerMissionStartPosition; removed b889g9
};
static_assert(SCR_SIZEOF(GPBD_FM_ENTRY) == 883);

struct GPBD_FM
{
    scrArray<32, GPBD_FM_ENTRY> Entries;
};
static_assert(SCR_SIZEOF(GPBD_FM) == 28257);