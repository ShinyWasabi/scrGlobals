#pragma once
#include "Types.hpp"

#define NUM_CONTACTS 86

struct DATE
{
    scrValue Year;
    scrValue Month;
    scrValue Day;
    scrValue Hour;
    scrValue Minute;
    scrValue Second;
    scrValue Millisecond;
};
static_assert(SCR_SIZEOF(DATE) == 7);

struct TIMER
{
    scrValue Time;
    scrValue IsInitialized;
};
static_assert(SCR_SIZEOF(TIMER) == 2);

struct COLOR_3
{
    scrValue R;
    scrValue G;
    scrValue B;
};
static_assert(SCR_SIZEOF(COLOR_3) == 3);

struct GAMER_HANDLE
{
    scrValue Data1;
    scrValue Data2;
    scrValue Data3;
    scrValue Data4;
    scrValue Data5;
    scrValue Data6;
    scrValue Data7;
    scrValue Data8;
    scrValue Data9;
    scrValue Data10;
    scrValue Data11;
    scrValue Data12;
    scrValue Data13;
};
static_assert(SCR_SIZEOF(GAMER_HANDLE) == 13);

// names taken from GTA5_Enhanced.exe+0x2252260 (0F 84 7F 01 00 00 4C 8B 47 20 48 8D 15 -0x21) (SCRIPT_EVENT_FPOM)
struct MP_SCRIPT_DATA
{
    scrValue MissionIndex; // this is an enum
    scrValue Variation;
    scrValue Creator;
    scrTextLabel23 CloudFileName;
    scrValue SharedRegId;
    scrValue PAD_0005[6]; // not serialized in the metric
    scrValue InstanceId;
    scrValue UniqueId;
    scrValue BitSet;
    scrValue GenericInt;
    scrValue TruckBitSet;
};
static_assert(SCR_SIZEOF(MP_SCRIPT_DATA) == 21);