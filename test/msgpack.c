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

static int test_pack_unsigned(void)
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

#if 0
static int test_pack_unsigned_long(void)
{
    uint8_t buf[18] = {0};

    for (unsigned long i = 0; i <= 127; ++i)
    {
        clear(buf);
        lip_pack_int(buf, i);

        if (lip_format(buf) != FMT_POSITIVE_FIXINT) return 1;

        unpack_pfix_data(buf);
        if ((uint8_t)buf[0] != (uint8_t)i) return 1;
    }

    for (unsigned long i = 128; i <= UINT8_MAX; ++i)
    {
        clear(buf);
        lip_pack_int(buf, i);

        if (lip_format(buf) != FMT_UINT_8) return 1;

        unpack_u8_data(buf);
        if ((uint8_t)buf[1] != (uint8_t)i) return 1;
    }

    for (unsigned long i = UINT8_MAX + 1; i <= UINT16_MAX; ++i)
    {
        clear(buf);
        lip_pack_int(buf, i);

        if (lip_format(buf) != FMT_UINT_16) return 1;

        unpack_u16_data(buf + 1);
        if (*((uint16_t *)(buf + 1)) != (uint16_t)i) return 1;
    }

    for (unsigned long i = UINT16_MAX + 1; i > UINT16_MAX && i <= UINT32_MAX;
         i += 256)
    {
        clear(buf);
        lip_pack_int(buf, i);

        if (lip_format(buf) != FMT_UINT_32) return 1;

        unpack_u32_data(buf + 1);
        if (*((uint32_t *)(buf + 1)) != (uint32_t)i) return 1;
    }

#if 0
    unsigned long i = UINT32_MAX;
    ++i;
    do
    {
        clear(buf);
        lip_pack_int(buf, i);

        if (lip_format(buf) != FMT_UINT_64) return 1;

        unpack_u64_data(buf + 1);
        if (*((uint64_t *)(buf + 1)) != (uint64_t)i) return 1;
    } while (++i != 0);
#endif

    return 0;
}
#endif

int main(void) { return test_pack_bool() | test_pack_unsigned(); }
