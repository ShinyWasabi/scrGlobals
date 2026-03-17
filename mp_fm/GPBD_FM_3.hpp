#pragma once
#include "../Types.hpp"

enum class eActivityType
{
    HEIST_PREP = 233,
    GUNRUNNING = 180,
    SIGHTSEER = 142,
    HEAD_HUNTER = 166,
    BUY_SPECIAL_CARGO = 167,
    SELL_SPECIAL_CARGO = 168,
    DEFEND_SPECIAL_CARGO = 169,
    STEAL_VEHICLE = 178,
    EXPORT_VEHICLE = 188,
    GUNRUNNING_2 = 225,
    GUNRUNNING_SELL = 226,
    GUNRUNNING_DEFEND = 227,
    BIKER_SELL = 190,
    BIKER_DEFEND = 191,
    BUSINESS_RESUPPLY = 192,
    SURVIVAL = 3,
    DARTS = 14,
    ARM_WRESTLING = 15,
    GANG_ATTACK = 6,
    PILOT_SCHOOL = 122,
    GOLF = 11,
    SHOOTING_RANGE = 13,
    TENNIS = 12,
    BASE_JUMP = 8,
    DEATHMATCH = 1,
    IMPROMPTU_DEATHMATCH = 5,
    MISSION = 0,
    RACE = 2,
    EXECUTIVE_DEATHMATCH = 148,
    MARKED_FOR_DEATH = 151,
    PIRACY_PREVENTION = 152,
    MOST_WANTED = 153,
    ASSET_RECOVERY = 157,
    HOSTILE_TAKEOVER = 159,
    POINT_2_POINT = 162,
    AMPHIBIOUS_ASSAULT = 216,
    VELOCITY = 219,
    GUNS_FOR_HIRE = 185,
    BY_THE_POUND = 182,
    RIPPING_IT_UP = 194,
    RACE_TO_POINT = 189,
    HIT_AND_RIDE = 193,
    CRIMINAL_MISCHIEF = 205,
    WEAPON_OF_CHOICE = 186,
    FRAGILE_GOODS = 207,
    TORCHED = 208,
    OUTRIDER = 209,
    WHEELIE_RIDER = 210,
    POW = 183,
    EXECUTIVE_SEARCH = 199,
    STAND_YOUR_GROUND = 201,
    AUTO_BUYOUT = 163,
    DUE_DILIGENCE = 160,
    MARKET_MANIPULATION = 154,
    COURIER_SERVICE = 155,
    SKYDIVE = 267
};

enum class eBossGoonFlags
{
    ONE_ON_ONE_DM = 4,
    JOIN_SUCCESS = 7,
    JOIN_FAIL = 8,
    SPECTATING = 24
};

enum class eGoonInviteType
{
    DEBUG,
    NEARBY,
    FRIENDS,
    CREW,
    INDIVIDUAL,
    LOOKING_FOR_WORK
};

enum class eBossVehicleState
{
    NONE,
    SPAWNED,
    DESTROYED = 3
};

enum class eMCRole
{
    PROSPECT = -1,
    VICE_PRESIDENT,
    ROAD_CAPTAIN,
    SERGEANT_IN_ARMS,
    ENFORCER
};

enum class eClubhouseActivity
{
    NONE = -1,
    DARTS,
    ARM_WRESTLING
};

struct MC_STYLE
{
    scrValue Enabled;
    scrValue BossOutfitType;
    scrValue GoonOutfitType;
    scrArray<7> GoonOutfitIndices; // one outfit for each goon
    scrArray<7> GoonOutfitIndicesOverride;
    scrValue PAD_0019;
    scrValue HeadgearEnabled;
    scrValue EmblemEnabled;
};
static_assert(SCR_SIZEOF(MC_STYLE) == 22);

struct VEHICLE_EXPORT
{
    scrArray<4> SellingVehicleIndices;
    scrValue PAD_0005; // this is set to zero in all export scripts and never read
};
static_assert(SCR_SIZEOF(VEHICLE_EXPORT) == 6);

struct HANGAR_CARGO
{
    scrValue PAD_0000; // unused?
    scrArray<20> DeliverableTypes;
    scrValue CargoType;
};
static_assert(SCR_SIZEOF(HANGAR_CARGO) == 23);

struct CASINO_HEIST_PREP
{
    scrValue PrepIndex;
    scrValue SupportCrewMemberIndex; // only set on preps 1 through 3
    scrValue LoadoutIndex;           // only set on prep 1 and 2
};
static_assert(SCR_SIZEOF(CASINO_HEIST_PREP) == 3);

struct LEAVE_IN_HELI
{
    scrValue Flags;
    scrValue Owner;
    scrValue SeatIndex;
};
static_assert(SCR_SIZEOF(LEAVE_IN_HELI) == 3);

struct BOSS_GOON
{
    scrValue Boss; // leader of CEO/MC
    scrValue TimeBecameBoss;
    scrValue TimeBecameGoon;
    scrValue LastPayTime;
    scrBitset<eBossGoonFlags> Flags;
    scrValue Flags2; // TODO
    scrValue Flags3; // TODO
    scrValue Flags4; // added b3717
    scrValue TotalBossGoonTime;
    scrArray<2> BossGoonUUID;
    scrArray<8> Goons;
    scrValue GoonsRequestingJoin; // bitset
    scrValue PayGrade;
    scrValue InvitesByBosses; // bitset
    scrValue TransitionBossPersistanceStage;
    scrValue EndBeingGoonReason;
    scrValue PAD_0025; // TODO
    scrValue JoiningBoss;
    scrEnum<eGoonInviteType> JoinedInviteType;
    scrValue NumBossDeathsSinceLastPay;
    scrVector PAD_0029; // TODO
    scrEnum<eActivityType> UnkActivity;
    scrEnum<eActivityType> CurrentActivity;
    scrValue JoustTarget;
    scrValue ExecutiveDeathmatchTarget;
    MP_SCRIPT_DATA ActiveScript;
    scrValue PAD_0057;
    scrValue PAD_0058;
    scrEnum<eBossVehicleState> BossVehicleState;
    scrValue BossVehicleSpawnState;
    scrValue PlayerInsideBossVehicle;
    scrValue BossVehicleModel;
    TIMER LastBossVehicleSpawnTimer;
    TIMER BossVehicleInvincibleTimer;
    scrVector BossVehicleSpawnedPosition;
    scrValue BossVehicleHudColor;
    scrTextLabel15 BossVehicleTextLabel;
    scrValue BossVehicleNetId;
    MC_STYLE MCStyle;
    scrValue PAD_0098[3]; // unused
    scrValue FriendlyFireDisabledPlayers;
    scrValue PiracyPreventionYachtIndex; // not used by the scripts
    scrValue BossGoonMissionLaunchState;
    scrValue ColorSlot;
    scrTextLabel63 MCName;
    scrValue Language; // can be used to get the system language of player
    scrValue SpawnableBossVehicles;
    scrValue AutoBuyoutDeliveryLocationIndex;
    scrValue AutoBuyoutDeliveryLocationSubIndex;
    scrValue PAD_0125;                          // unused
    scrArray<8, scrVector> PAD_0126;            // TODO
    scrArray<8, scrVector> ContrabandPositions; // positions of cargo used to notify players to destroy them when they get near
    scrValue ContrabandPickupModel;
    scrValue StealingContrabandVehiclePlayerIndex;
    scrValue PAD_0178; // TODO
    scrValue ContrabandPickupModel2;
    scrValue DestroyedCargo;
    scrValue VIPGameplayDisabledTimer; // @181 as of 1.67
    scrValue SettingUpBusiness;
    scrValue PAD_0183[4]; // TODO some unknown contraband struct
    VEHICLE_EXPORT VehicleExport;
    scrValue PAD_0193[12];            // TODO
    scrArray<9> ActiveFreemodeEvents; // force thunder, size 7 -> 8 b3258 8 -> 9 b3407
    scrValue PAD_0212[22];            // I'm not even going to bother with this one
    HANGAR_CARGO HangarCargo;
    scrValue PAD_0236[23]; // not going to bother with this one either
    scrArray<20> CasinoDeliverables;
    scrValue CasinoLimoDestination;
    scrValue CasinoLimoActive;
    scrValue CasinoLuxuryCarActive;
    scrValue CasinoLuxuryCarModel;
    scrValue PAD_0309; // added b3717
    CASINO_HEIST_PREP CasinoHeistPrep;
    scrValue CayoPrepIndex;
    scrValue CompanySUVDestination;
    scrValue CompanySUVActive;
    scrArray<8> ContrabandIndices;     // type of selling cargo
    scrArray<10> VehicleExportIndices; // not sure what this is
    scrValue VehicleExportMissionType; // valid range is 2000 to 2010, 2000 = 0, 2001 = 1 etc
    scrArray<4> VehicleExportSellingIndices;
    scrValue PAD_0337;            // TODO
    scrTextLabel63 GangName;      // CEO Name
    scrTextLabel63 ClubhouseName; // cut content?
    scrValue SourcingContrabandType;
    scrValue FragileGoodsMissionType;
    scrValue SalvageMissionType;
    scrValue DoomsdayPrepIndex;
    scrValue VehicleExportIndex; // another one...
    scrValue PAD_0375;           // unused
    scrValue BunkerSourceIndex;  // check gb_gunrunning func_1540
    scrArray<8> BunkerCargoIndices;
    scrValue PAD_0386[5];
    scrValue PAD_0391[2];      // unused
    scrValue PAD_0393[15];     // smuggler data
    scrValue LastBossWorkTime; // seconds since epoch
    scrValue PAD_0409[19];
    scrValue IsMC;
    scrEnum<eMCRole> MCRole; // applies to goons only, boss is always the MC president
    scrValue FormationFlyingAssist;
    scrValue PAD_0431; // always set to zero and not read
    scrValue MCFormationActive;
    scrValue MCFormationHelpShown;
    TIMER MCFormationHealthBonusTimer;
    TIMER MCFormationLastHealthBonusTimer;
    TIMER MCFormationBreakTimer;
    scrValue PAD_0440; // unused
    scrValue MCFormationAssist;
    scrValue MCRidingStyleRelaxed;
    scrValue PAD_0443;       // set from a tunable
    scrValue PAD_0444;       // set from a tunable
    scrValue PAD_0445[16];   // somewhat unused, a few fields are accessed in the business battle script
    scrValue ClothingValue;  // total value of equipped clothing used by criminal damage
    scrValue Adversary;      // for common adversary calculations?
    scrValue ContrabandType; // unknown HASH_ENUM
    scrValue HitAndRideGangType;
    scrValue IsMC2;
    scrValue BossGoonVersion;
    scrValue MCTotalContributionPoints;
    scrValue MCContributionPoints;
    scrValue FavoriteBikeStyle; // not read by the scripts
    scrValue GreatestFormationTimeIndex;
    scrValue FormationTime;
    scrValue RidingFavoriteMotorcycle;
    scrValue ContrabandSellLocation;
    scrValue BusinessBattleType;
    scrValue PAD_0475;
    scrValue NightclubMissionIndex;
    scrValue NightclubDefendMissionIndex;
    scrValue PAD_0478[18]; // TODO
    scrValue PAD_0501;     // added b3717
    scrValue PAD_0502;     // added b3717
    scrValue DoubleActionCacheLocationRevealed;
};
static_assert(SCR_SIZEOF(BOSS_GOON) == 504);

struct MC_STATS
{
    scrValue FormationTime0;
    scrValue FormationTime1;
    scrValue FormationTime2;
    scrValue FormationTime3;
    scrValue MembersMarkedForDeath;
    scrValue MCKills;
    scrValue MCDeaths;
    scrValue RivalPresidentKills;
    scrValue RivalCEOAndVIPKills;
    scrValue MeleeKills;
    scrValue ClubhouseContractsComplete;
    scrValue ClubhouseContractEarnings;
    scrValue ClubworkCompleted;
    scrValue ClubChallengesCompleted;
    scrValue MemberChallengesCompleted;
};
static_assert(SCR_SIZEOF(MC_STATS) == 15);

struct GBPD_FM_3_ENTRY
{
    scrEnum<eActivityType> CurrentActivity;         // enum is outdated
    scrValue Flags;                                 // TODO
    scrEnum<eActivityType> CurrentFreemodeActivity; // subset of CurrentActivity
    scrValue SeatingFlags;
    scrVector CurrentFreemodeActivityObjectivePosition;
    scrValue VehiclesNearbyActivityObjective; // only used by challenges and checkpoints
    scrValue PassiveMode;
    scrValue TimeTrialActive; // verify
    BOSS_GOON BossGoon;
    scrValue PAD_507[3];                         // unused
    scrValue ScriptEventReplayProtectionCounter; // "uniqueId"
    TIMER CoronaForcedLaunchTimer;
    LEAVE_IN_HELI LeaveInHeli;
    scrValue OfficeDesktopFlags; // bit 0 -> login, bit 1 -> map
    scrValue PAD_514[8];         // some IE stuff, most of it is unused
    scrValue IlluminatedClothingState;
    scrValue MatchHistoryId1; // used for telemetry
    scrValue MatchHistoryId2;
    scrEnum<eClubhouseActivity> ClubhouseActivity;
    scrValue ClubhouseFont;
    scrValue ClubhouseColor;
    scrValue ClubhouseEmblem;
    scrValue ClubhouseHideSignage;
    scrValue PAD_0533[2]; // facility exit
    scrValue PAD_0535[6]; // no clue what this is
    MC_STATS MCStats;
    scrValue PAD_0556[29];
    scrValue ForcedWeapon;
    scrValue HangarCargoMissionLocationIndex;
    scrVector AvengerPosition;
    scrVector TerrorbytePosition;
    scrVector AcidLabPosition;
    scrValue DeliveringExportVehicleOwner;
    scrValue PAD_0597[2];  // TODO
    scrValue BountyAmount; // values above 10000 will prevent payout
    scrValue BountyPlacedBy;
    scrValue PAD_0601;                       // unused, set to -1 by business_battles_sell and never read
    scrValue CurrentlyUsingArenaTurretIndex; // works similar to the vars found in GlobalPlayerBD
    scrValue CurrentlyUsingArenaTurretActivatedTime;
    scrValue CasinoStoryProgress;
    scrValue CasinoFlowProgress;
    scrArray<1> DailyObjectiveFlags; // @607 as of 1.67
};
static_assert(SCR_SIZEOF(GBPD_FM_3_ENTRY) == 615);

struct GPBD_FM_3
{
    scrArray<32, GBPD_FM_3_ENTRY> Entries;
};
static_assert(SCR_SIZEOF(GPBD_FM_3) == 19681);