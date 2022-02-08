#include "helper.h"
#include "lite_pack.h"
#include <stdint.h>

static unsigned const u32_values[] = {
    0,          1,          2,          3,          4,          5,
    7,          8,          9,          15,         16,         17,
    31,         32,         33,         63,         64,         65,
    127,        128,        129,        255,        256,        257,
    511,        512,        513,        1023,       1024,       1025,
    2047,       2048,       2049,       4095,       4096,       4097,
    8191,       8192,       8193,       16383,      16384,      16385,
    32767,      32768,      32769,      65535,      65536,      65537,
    131071,     131072,     131073,     262143,     262144,     262145,
    524287,     524288,     524289,     1048575,    1048576,    1048577,
    2097151,    2097152,    2097153,    4194303,    4194304,    4194305,
    8388607,    8388608,    8388609,    16777215,   16777216,   16777217,
    33554431,   33554432,   33554433,   67108863,   67108864,   67108865,
    134217727,  134217728,  134217729,  268435455,  268435456,  268435457,
    536870911,  536870912,  536870913,  1073741823, 1073741824, 1073741825,
    2147483647, 2147483648, 2147483649, 4294967295};

static int const i32_values[] = {
    -2147483648, -2147483647, -1073741825, -1073741824, -1073741823, -536870913,
    -536870912,  -536870911,  -268435457,  -268435456,  -268435455,  -134217729,
    -134217728,  -134217727,  -67108865,   -67108864,   -67108863,   -33554433,
    -33554432,   -33554431,   -16777217,   -16777216,   -16777215,   -8388609,
    -8388608,    -8388607,    -4194305,    -4194304,    -4194303,    -2097153,
    -2097152,    -2097151,    -1048577,    -1048576,    -1048575,    -524289,
    -524288,     -524287,     -262145,     -262144,     -262143,     -131073,
    -131072,     -131071,     -65537,      -65536,      -65535,      -32769,
    -32768,      -32767,      -16385,      -16384,      -16383,      -8193,
    -8192,       -8191,       -4097,       -4096,       -4095,       -2049,
    -2048,       -2047,       -1025,       -1024,       -1023,       -513,
    -512,        -511,        -257,        -256,        -255,        -129,
    -128,        -127,        -65,         -64,         -63,         -33,
    -32,         -31,         -17,         -16,         -15,         -9,
    -8,          -7,          -5,          -4,          -3,          -2,
    -1,          0,           1,           2,           3,           4,
    5,           7,           8,           9,           15,          16,
    17,          31,          32,          33,          63,          64,
    65,          127,         128,         129,         255,         256,
    257,         511,         512,         513,         1023,        1024,
    1025,        2047,        2048,        2049,        4095,        4096,
    4097,        8191,        8192,        8193,        16383,       16384,
    16385,       32767,       32768,       32769,       65535,       65536,
    65537,       131071,      131072,      131073,      262143,      262144,
    262145,      524287,      524288,      524289,      1048575,     1048576,
    1048577,     2097151,     2097152,     2097153,     4194303,     4194304,
    4194305,     8388607,     8388608,     8388609,     16777215,    16777216,
    16777217,    33554431,    33554432,    33554433,    67108863,    67108864,
    67108865,    134217727,   134217728,   134217729,   268435455,   268435456,
    268435457,   536870911,   536870912,   536870913,   1073741823,  1073741824,
    1073741825,  2147483647,
};

static unsigned long const u64_values[] = {0UL,
                                           63UL,
                                           127UL,
                                           191UL,
                                           255UL,
                                           32895UL,
                                           65535UL,
                                           2147516415UL,
                                           4294967295UL,
                                           9223372039002259456UL,
                                           18446744073709551615UL};

static long const i64_values[] = {-9223372036854775807L,
                                  -4294967295L,
                                  -2147516415L,
                                  -65535L,
                                  -32895L,
                                  -255L,
                                  -191L,
                                  -127L,
                                  -63L,
                                  0L,
                                  63L,
                                  127L,
                                  191L,
                                  255L,
                                  32895L,
                                  65535L,
                                  2147516415L,
                                  4294967295L,
                                  9223372036854775807L};

static int positive_integer_check(uint8_t buf[9], unsigned long v)
{
    uint8_t u8 = 0;
    uint16_t u16 = 0;
    uint32_t u32 = 0;
    uint64_t u64 = 0;
    if (v <= 127U)
    {
        if (lip_format(buf) != LIP_FMT_POSITIVE_FIXINT) ERROR;
        if (lip_unpack_int(buf, &u8) != 1) ERROR;
        if (v != u8) ERROR;
    }
    else if (v <= 255U)
    {
        if (lip_format(buf) != LIP_FMT_UINT_8) ERROR;
        if (lip_unpack_int(buf, &u8) != 2) ERROR;
        if (v != u8) ERROR;
    }
    else if (v <= 65535U)
    {
        if (lip_format(buf) != LIP_FMT_UINT_16) ERROR;
        if (lip_unpack_int(buf, &u16) != 3) ERROR;
        if (v != u16) ERROR;
    }
    else if (v <= 4294967295U)
    {
        if (lip_format(buf) != LIP_FMT_UINT_32) ERROR;
        if (lip_unpack_int(buf, &u32) != 5) ERROR;
        if (v != u32) ERROR;
    }
    else
    {
        if (lip_format(buf) != LIP_FMT_UINT_64) ERROR;
        if (lip_unpack_int(buf, &u64) != 9) ERROR;
        if (v != u64) ERROR;
    }
    return 0;
}

static int negative_integer_check(uint8_t buf[9], long v)
{
    int8_t i8 = 0;
    int16_t i16 = 0;
    int32_t i32 = 0;
    int64_t i64 = 0;
    if (v >= -32)
    {
        if (lip_format(buf) != LIP_FMT_NEGATIVE_FIXINT) ERROR;
        if (lip_unpack_int(buf, &i8) != 1) ERROR;
        if (v != i8) ERROR;
    }
    else if (v >= INT8_MIN)
    {
        if (lip_format(buf) != LIP_FMT_INT_8) ERROR;
        if (lip_unpack_int(buf, &i8) != 2) ERROR;
        if (v != i8) ERROR;
    }
    else if (v >= INT16_MIN)
    {
        if (lip_format(buf) != LIP_FMT_INT_16) ERROR;
        if (lip_unpack_int(buf, &i16) != 3) ERROR;
        if (v != i16) ERROR;
    }
    else if (v >= INT32_MIN)
    {
        if (lip_format(buf) != LIP_FMT_INT_32) ERROR;
        if (lip_unpack_int(buf, &i32) != 5) ERROR;
        if (v != i32) ERROR;
    }
    else
    {
        if (lip_format(buf) != LIP_FMT_INT_64) ERROR;
        if (lip_unpack_int(buf, &i64) != 9) ERROR;
        if (v != i64) ERROR;
    }
    return 0;
}

static uint8_t buf[9] = {0};

static int test_u32(void)
{

    for (unsigned i = 0; i < array_size(u32_values); ++i)
    {
        unsigned v = u32_values[i];
        clear(buf);
        lip_pack_int(buf, v);
        if (positive_integer_check(buf, v)) ERROR;
    }

    return 0;
}

static int test_i32(void)
{
    for (unsigned i = 0; i < array_size(i32_values); ++i)
    {
        int v = i32_values[i];
        clear(buf);
        lip_pack_int(buf, v);

        if (v >= 0)
        {
            if (positive_integer_check(buf, (unsigned)v)) ERROR;
        }
        else
        {
            if (negative_integer_check(buf, v)) ERROR;
        }
    }

    return 0;
}

static int test_u64(void)
{

    for (unsigned i = 0; i < array_size(u64_values); ++i)
    {
        unsigned long v = u64_values[i];
        clear(buf);
        lip_pack_int(buf, v);
        if (positive_integer_check(buf, v)) ERROR;
    }

    return 0;
}

static int test_i64(void)
{
    for (unsigned i = 0; i < array_size(i64_values); ++i)
    {
        long v = i64_values[i];
        clear(buf);
        lip_pack_int(buf, v);

        if (v >= 0)
        {
            if (positive_integer_check(buf, (unsigned long)v)) ERROR;
        }
        else
        {
            if (negative_integer_check(buf, v)) ERROR;
        }
    }

    return 0;
}

int main(void) { return test_u32() | test_i32() | test_u64() | test_i64(); }
