#include "lite_pack.h"
#include "lorem.h"
#include <float.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define array_size(arr) (sizeof(arr) / sizeof((arr)[0]))

#define clear(buf) memset(buf, 0, sizeof(buf))

static int test_pack_bool(void)
{
    uint8_t buf[1] = {0};

    clear(buf);
    lip_pack_bool(buf, false);
    if (buf[0] != (uint8_t)0xc2) return 1;

    clear(buf);
    lip_pack_false(buf);
    if (buf[0] != (uint8_t)0xc2) return 1;

    clear(buf);
    lip_pack_bool(buf, true);
    if (buf[0] != (uint8_t)0xc3) return 1;

    clear(buf);
    lip_pack_true(buf);
    if (buf[0] != (uint8_t)0xc3) return 1;

    return 0;
}

static int test_uint(void)
{
    uint8_t buf[9] = {0};

    unsigned i = 0;
    do
    {
        clear(buf);
        lip_pack_int(buf, i);

        if (i <= 127U)
        {
            if (lip_format(buf) != FMT_POSITIVE_FIXINT) return 1;
            if (lip_unpack_uint(buf) != i) return 1;
        }
        else if (i <= 255U)
        {
            if (lip_format(buf) != FMT_UINT_8) return 1;
            if (lip_unpack_uint(buf) != i) return 1;
        }
        else if (i <= 65535U)
        {
            if (lip_format(buf) != FMT_UINT_16) return 1;
            if (lip_unpack_uint(buf) != i) return 1;
        }
        else if (i <= 4294967295U)
        {
            if (lip_format(buf) != FMT_UINT_32) return 1;
            if (lip_unpack_uint(buf) != i) return 1;
        }
        else
            break;

    } while (++i != 0);

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

    int formats[] = {
        FMT_POSITIVE_FIXINT, FMT_POSITIVE_FIXINT, FMT_POSITIVE_FIXINT,
        FMT_UINT_8,          FMT_UINT_8,          FMT_UINT_16,
        FMT_UINT_16,         FMT_UINT_32,         FMT_UINT_32,
        FMT_UINT_64,         FMT_UINT_64};

    for (unsigned i = 0; i < array_size(vals); ++i)
    {
        clear(buf);
        lip_pack_int(buf, vals[i]);
        if (lip_format(buf) != formats[i]) return 1;
        if (lip_unpack_ulong(buf) != vals[i]) return 1;
    }

    return 0;
}

static int test_pack_float(void)
{
    uint8_t buf[5] = {0};
    float vals[] = {-1.2f, -0.0f, +0.0f, 1.2f, FLT_MAX, FLT_MIN, FLT_EPSILON};

    for (unsigned i = 0; i < array_size(vals); ++i)
    {
        clear(buf);
        lip_pack_float(buf, vals[i]);
        if (lip_format(buf) != FMT_FLOAT_32) return 1;
        if (lip_unpack_float(buf) != vals[i]) return 1;
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
        if (lip_format(buf) != FMT_FLOAT_64) return 1;
        if (lip_unpack_double(buf) != vals[i]) return 1;
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

    unsigned long sizes[] = {0, 0x1F, 0x20, 0xFF, 0x100, 0xFFFF, 0x10000UL};
    int formats[] = {
        FMT_FIXSTR, FMT_FIXSTR, FMT_STR_8,  FMT_STR_8,
        FMT_STR_16, FMT_STR_16, FMT_STR_32,
    };

    char const *str = 0;

    for (unsigned i = 0; i < array_size(sizes); ++i)
    {
        memset(buf, 0, buf_size);

        str = lorem_new(sizes[i]);
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
    return 1;
}

int main(void)
{
    return test_pack_bool() | test_uint() | test_ulong() | test_pack_float() |
           test_double() | test_str();
}
