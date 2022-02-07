#include "lite_pack.h"
#include "lorem.h"
#include <float.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define array_size(arr) (sizeof(arr) / sizeof((arr)[0]))

#define clear(buf) memset(buf, 0, sizeof(buf))

#define ERROR                                                                  \
    do                                                                         \
    {                                                                          \
        fprintf(stderr, "\nFailure at %s:%d\n", __func__, __LINE__);           \
        exit(1);                                                               \
    } while (1);

static int test_bool(void)
{
    uint8_t buf[1] = {0};

    clear(buf);
    lip_pack_bool(buf, false);
    if (lip_format(buf) != LIP_FMT_FALSE) ERROR;
    if (lip_unpack_bool(buf) != false) ERROR;

    clear(buf);
    lip_pack_false(buf);
    if (lip_format(buf) != LIP_FMT_FALSE) ERROR;
    if (lip_unpack_bool(buf) != false) ERROR;

    clear(buf);
    lip_pack_bool(buf, true);
    if (lip_format(buf) != LIP_FMT_TRUE) ERROR;
    if (lip_unpack_bool(buf) != true) ERROR;

    clear(buf);
    lip_pack_true(buf);
    if (lip_format(buf) != LIP_FMT_TRUE) ERROR;
    if (lip_unpack_bool(buf) != true) ERROR;

    return 0;
}

static int positive_integer_check(uint8_t buf[9], unsigned v)
{
    if (v <= 127U)
    {
        if (lip_format(buf) != LIP_FMT_POSITIVE_FIXINT) ERROR;
        if (lip_unpack_uint(buf) != v) ERROR;
    }
    else if (v <= 255U)
    {
        if (lip_format(buf) != LIP_FMT_UINT_8) ERROR;
        if (lip_unpack_uint(buf) != v) ERROR;
    }
    else if (v <= 65535U)
    {
        if (lip_format(buf) != LIP_FMT_UINT_16) ERROR;
        if (lip_unpack_uint(buf) != v) ERROR;
    }
    else
    {
        if (lip_format(buf) != LIP_FMT_UINT_32) ERROR;
        if (lip_unpack_uint(buf) != v) ERROR;
    }
    return 0;
}

int i32_values[] = {
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

unsigned u32_values[] = {
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

static int test_uint(void)
{
    uint8_t buf[9] = {0};

    for (unsigned i = 0; i < array_size(u32_values); ++i)
    {
        unsigned v = u32_values[i];
        clear(buf);
        lip_pack_int(buf, v);
        if (positive_integer_check(buf, v)) ERROR;
    }

    return 0;
}

static int negative_integer_check(uint8_t buf[9], int v)
{
    if (v >= -32)
    {
        if (lip_format(buf) != LIP_FMT_NEGATIVE_FIXINT) ERROR;
        if (lip_unpack_int(buf) != v) ERROR;
    }
    else if (v >= INT8_MIN)
    {
        if (lip_format(buf) != LIP_FMT_INT_8) ERROR;
        if (lip_unpack_int(buf) != v) ERROR;
    }
    else if (v >= INT16_MIN)
    {
        if (lip_format(buf) != LIP_FMT_INT_16) ERROR;
        if (lip_unpack_int(buf) != v) ERROR;
    }
    else
    {
        if (lip_format(buf) != LIP_FMT_INT_32) ERROR;
        if (lip_unpack_int(buf) != v) ERROR;
    }
    return 0;
}

static int test_int(void)
{
    uint8_t buf[9] = {0};

    for (unsigned i = 0; i < array_size(u32_values); ++i)
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

static int test_ulong(void)
{
    uint8_t buf[17] = {0};

    unsigned long vals[] = {0UL,
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

    int formats[] = {LIP_FMT_POSITIVE_FIXINT, LIP_FMT_POSITIVE_FIXINT,
                     LIP_FMT_POSITIVE_FIXINT, LIP_FMT_UINT_8,
                     LIP_FMT_UINT_8,          LIP_FMT_UINT_16,
                     LIP_FMT_UINT_16,         LIP_FMT_UINT_32,
                     LIP_FMT_UINT_32,         LIP_FMT_UINT_64,
                     LIP_FMT_UINT_64};

    for (unsigned i = 0; i < array_size(vals); ++i)
    {
        clear(buf);
        lip_pack_int(buf, vals[i]);
        if (lip_format(buf) != formats[i]) ERROR;
        if (lip_unpack_ulong(buf) != vals[i]) ERROR;
    }

    return 0;
}

static int test_float(void)
{
    uint8_t buf[5] = {0};
    float vals[] = {-1.2f, -0.0f, +0.0f, 1.2f, FLT_MAX, FLT_MIN, FLT_EPSILON};

    for (unsigned i = 0; i < array_size(vals); ++i)
    {
        clear(buf);
        lip_pack_float(buf, vals[i]);
        if (lip_format(buf) != LIP_FMT_FLOAT_32) ERROR;
        if (lip_unpack_float(buf) != vals[i]) ERROR;
    }

    return 0;
}

static int test_double(void)
{
    uint8_t buf[9] = {0};
    double vals[] = {-1.2, -0.0, +0.0, 1.2, DBL_MAX, DBL_MIN, DBL_EPSILON};

    for (unsigned i = 0; i < array_size(vals); ++i)
    {
        clear(buf);
        lip_pack_float(buf, vals[i]);
        if (lip_format(buf) != LIP_FMT_FLOAT_64) ERROR;
        if (lip_unpack_double(buf) != vals[i]) ERROR;
    }

    return 0;
}

static int test_str(void)
{
    unsigned long buf_size = 0x10000UL + 6UL;
    unsigned long out_size = 0x10000UL + 1UL;
    uint8_t *buf = malloc(buf_size);
    if (!buf) exit(1);

    char *out = malloc(out_size);
    if (!out) exit(1);

    unsigned long lengths[] = {0, 0x1F, 0x20, 0xFF, 0x100, 0xFFFF, 0x10000UL};
    int formats[] = {
        LIP_FMT_FIXSTR, LIP_FMT_FIXSTR, LIP_FMT_STR_8,  LIP_FMT_STR_8,
        LIP_FMT_STR_16, LIP_FMT_STR_16, LIP_FMT_STR_32,
    };

    char const *str = 0;

    for (unsigned i = 0; i < array_size(lengths); ++i)
    {
        memset(buf, 0, buf_size);

        str = lorem_new(lengths[i]);
        lip_pack_str(buf, str);

        if (lip_format(buf) != formats[i]) goto error;
        if (strcmp(lip_unpack_str(buf, out), str)) goto error;

        free((void *)str);
    }

    free(buf);
    free(out);
    return 0;

error:
    free(buf);
    free(out);
    free((void *)str);
    ERROR;
}

static int test_map(void)
{
    uint8_t buf[17] = {0};

    unsigned lengths[] = {
        0, 15, 16, 65535, 65536, 4294967295,
    };

    int formats[] = {LIP_FMT_FIXMAP, LIP_FMT_FIXMAP, LIP_FMT_MAP_16,
                     LIP_FMT_MAP_16, LIP_FMT_MAP_32, LIP_FMT_MAP_32};

    for (unsigned i = 0; i < array_size(lengths); ++i)
    {
        clear(buf);
        lip_pack_map_head(buf, lengths[i]);
        if (lip_format(buf) != formats[i]) ERROR;
        if (lip_unpack_map_head(buf) != lengths[i]) ERROR;
    }

    return 0;
}

static int test_map_example1_write(size_t *size)
{
    FILE *fp = fopen("example1.mp", "wb");

    uint8_t buf[256] = {0};
    uint8_t *ptr = buf;

    ptr += lip_pack_map_head(ptr, 2);

    ptr += lip_pack_str(ptr, "name");
    ptr += lip_pack_str(ptr, "Danilo Horta");

    ptr += lip_pack_str(ptr, "age");
    ptr += lip_pack_int(ptr, 36U);

    *size = fwrite(buf, 1, (size_t)(ptr - buf), fp);

    fclose(fp);

    return 0;
}

static int test_map_example1_read(size_t *size)
{
    FILE *fp = fopen("example1.mp", "rb");

    uint8_t buf[256] = {0};
    char str[256] = {0};
    uint8_t *ptr = buf;

    fread(buf, 1, *size, fp);
    ptr = buf;

    if (lip_unpack_map_head(ptr) != 2) ERROR;
    ptr += lip_skip(ptr);

    if (strcmp(lip_unpack_str(ptr, str), "name")) ERROR;
    ptr += lip_skip(ptr);

    if (strcmp(lip_unpack_str(ptr, str), "Danilo Horta")) ERROR;
    ptr += lip_skip(ptr);

    if (strcmp(lip_unpack_str(ptr, str), "age")) ERROR;
    ptr += lip_skip(ptr);

    if (lip_unpack_uint(ptr) != 36) ERROR;
    ptr += lip_skip(ptr);

    if ((size_t)(ptr - buf) != *size) ERROR;

    fclose(fp);

    return 0;
}

static int test_map_example1(void)
{
    size_t size = 0;
    if (test_map_example1_write(&size)) ERROR;
    if (test_map_example1_read(&size)) ERROR;
    return 0;
}

int main(void)
{
    return test_map_example1() | test_bool() | test_map_example1() |
           test_bool() | test_uint() | test_ulong() | test_int() |
           test_float() | test_double() | test_str();
}
