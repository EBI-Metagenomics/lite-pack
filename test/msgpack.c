#include "lite_pack.h"
#include <stdint.h>
#include <string.h>

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

static int test_pack_int_unpack_uint_unsafe(void)
{
    uint8_t buf[17] = {0};

    unsigned i = 0;
    do
    {
        clear(buf);
        lip_pack_int(buf, i);

        if (i <= 127U)
        {
            if (lip_format(buf) != FMT_POSITIVE_FIXINT) return 1;
            if (lip_unpack_uint_unsafe(buf) != i) return 1;
        }
        else if (i <= 255U)
        {
            if (lip_format(buf) != FMT_UINT_8) return 1;
            if (lip_unpack_uint_unsafe(buf) != i) return 1;
        }
        else if (i <= 65535U)
        {
            if (lip_format(buf) != FMT_UINT_16) return 1;
            if (lip_unpack_uint_unsafe(buf) != i) return 1;
        }
        else if (i <= 4294967295U)
        {
            if (lip_format(buf) != FMT_UINT_32) return 1;
            if (lip_unpack_uint_unsafe(buf) != i) return 1;
        }
        else
            break;

    } while (++i != 0);

    return 0;
}

static int test_pack_int_unpack_uint(void)
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

static int test_pack_int_unpack_ulong(void)
{
    uint8_t buf[17] = {0};

    unsigned long vals[11] = {0UL,
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

    int formats[11] = {
        FMT_POSITIVE_FIXINT, FMT_POSITIVE_FIXINT, FMT_POSITIVE_FIXINT,
        FMT_UINT_8,          FMT_UINT_8,          FMT_UINT_16,
        FMT_UINT_16,         FMT_UINT_32,         FMT_UINT_32,
        FMT_UINT_64,         FMT_UINT_64};

    for (unsigned i = 0; i < 11; ++i)
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
    float vals[4] = {-1.2f, -0.0f, +0.0f, 1.2f};

    for (unsigned i = 0; i < 4; ++i)
    {
        clear(buf);
        lip_pack_float(buf, vals[i]);
        if (lip_format(buf) != FMT_FLOAT_32) return 1;
        if (lip_unpack_float(buf) != vals[i]) return 1;
    }

    return 0;
}

int main(void)
{
    return test_pack_float();
    return test_pack_bool() | test_pack_int_unpack_uint_unsafe() |
           test_pack_int_unpack_uint() | test_pack_int_unpack_ulong();
}
