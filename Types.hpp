#pragma once
#include <cstddef>
#include <type_traits>

#define SCR_GLOBAL_BLOCK_SIZE 262144
#define SCR_SIZEOF(x) (sizeof(x) / 8)
#define SCR_OFFSETOF(block, type, field) ((block) * SCR_GLOBAL_BLOCK_SIZE + (offsetof(type, field) / 8))

union scrValue
{
    int Int;
    unsigned int Uns;
    float Float;
    const char* String;
    scrValue* Reference;
    unsigned long long Any;
};

template <typename T>
struct scrEnum
{
    alignas(8) T Value;

    operator T() const
    {
        return Value;
    }

    scrEnum& operator=(T v)
    {
        Value = v;
        return *this;
    }

    static_assert(std::is_enum_v<T>);
};

template <int S>
struct scrTextLabel
{
    alignas(8) char Data[S];
    alignas(8) char Pad[S];

    operator char*()
    {
        return Data;
    }
};

using scrTextLabel7 = scrTextLabel<8>;
using scrTextLabel15 = scrTextLabel<16>;
using scrTextLabel23 = scrTextLabel<24>;
using scrTextLabel31 = scrTextLabel<32>;
using scrTextLabel63 = scrTextLabel<64>;

template <int S, typename T = scrValue>
struct scrArray
{
    alignas(8) int Size = S;
    alignas(8) T Data[S];

    T& operator[](int idx)
    {
        return Data[idx];
    }
};

template <typename T = int>
struct scrBitset
{
    alignas(8) int Value;

    bool IsSet(T val)
    {
        return Value & (1 << static_cast<int>(val));
    }

    void Set(T val)
    {
        Value |= (1 << static_cast<int>(val));
    }

    void Clear(T val)
    {
        Value &= ~(1 << static_cast<int>(val));
    }

    operator T() const
    {
        return Value;
    }

    scrBitset& operator=(T v)
    { 
        Value = static_cast<int>(v);
        return *this;
    }

    static_assert(std::is_integral_v<T> || std::is_enum_v<T>);
};

struct scrVector
{
    alignas(8) float x{};
    alignas(8) float y{};
    alignas(8) float z{};

    constexpr scrVector() :
        x(),
        y(),
        z()
    {
    }

    constexpr scrVector(float x, float y, float z) :
        x(x),
        y(y),
        z(z)
    {
    }

    operator bool() const
    {
        return this->x != 0.0f || this->y != 0.0f || this->z != 0.0f;
    }

    bool operator==(const scrVector& other) const
    {
        return this->x == other.x && this->y == other.y && this->z == other.z;
    }

    bool operator!=(const scrVector& other) const
    {
        return this->x != other.x || this->y != other.y || this->z != other.z;
    }

    scrVector operator+(const scrVector& other) const
    {
        scrVector vec;
        vec.x = this->x + other.x;
        vec.y = this->y + other.y;
        vec.z = this->z + other.z;
        return vec;
    }

    scrVector operator-(const scrVector& other) const
    {
        scrVector vec;
        vec.x = this->x - other.x;
        vec.y = this->y - other.y;
        vec.z = this->z - other.z;
        return vec;
    }

    scrVector operator*(const scrVector& other) const
    {
        scrVector vec;
        vec.x = this->x * other.x;
        vec.y = this->y * other.y;
        vec.z = this->z * other.z;
        return vec;
    }

    scrVector operator/(const scrVector& other) const
    {
        scrVector vec;
        vec.x = this->x / other.x;
        vec.y = this->y / other.y;
        vec.z = this->z / other.z;
        return vec;
    }
};