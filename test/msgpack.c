#include "lite_pack.h"
#include <stdint.h>
#include <string.h>

#define clear(buf) memset(buf, 0, sizeof(buf))

static int test_pack_bool(void)
{
    uint8_t buf[1] = {0};

    clear(buf);
    pack_bool(buf, false);
    if (buf[0] != (uint8_t)0xc2) return 1;

    clear(buf);
    pack_false(buf);
    if (buf[0] != (uint8_t)0xc2) return 1;

    clear(buf);
    pack_bool(buf, true);
    if (buf[0] != (uint8_t)0xc3) return 1;

    clear(buf);
    pack_true(buf);
    if (buf[0] != (uint8_t)0xc3) return 1;

    return 0;
}

static int test_pack_u8(void)
{
    uint8_t buf[2] = {0};

    for (unsigned i = 0; i <= 127; ++i)
    {
        clear(buf);
        pack_uint(buf, (uint8_t)i);
        if (buf[0] != (uint8_t)i) return 1;

        unpack_pfix_data(buf);
        if ((uint8_t)buf[0] != (uint8_t)i) return 1;
    }

    for (unsigned i = 128; i <= UINT8_MAX; ++i)
    {
        clear(buf);
        pack_uint(buf, (uint8_t)i);
        if (buf[0] != (uint8_t)0xcc) return 1;

        unpack_u8_data(buf + 1);
        if ((uint8_t)buf[1] != (uint8_t)i) return 1;
    }

    return 0;
}

static int test_pack_u16(void)
{
    uint8_t buf[18] = {0};

    for (unsigned i = 0; i <= 127; ++i)
    {
        clear(buf);
        pack_uint(buf, (uint8_t)i);
        if (buf[0] != (uint8_t)i) return 1;

        unpack_pfix_data(buf);
        if ((uint8_t)buf[0] != (uint8_t)i) return 1;
    }

    for (unsigned i = 128; i <= UINT8_MAX; ++i)
    {
        clear(buf);
        pack_uint(buf, (uint8_t)i);
        if (buf[0] != (uint8_t)0xcc) return 1;

        unpack_u8_data(buf);
        if ((uint8_t)buf[1] != (uint8_t)i) return 1;
    }

    for (unsigned i = 0; i <= 127; ++i)
    {
        clear(buf);
        pack_uint(buf, (uint16_t)i);
        if (buf[0] != (uint8_t)i) return 1;
    }

    for (unsigned i = 128; i <= UINT8_MAX; ++i)
    {
        clear(buf);
        pack_uint(buf, (uint16_t)i);
        if (buf[0] != (uint8_t)0xcc) return 1;

        unpack_u8_data(buf + 1);
        if (*((uint8_t *)(buf + 1)) != (uint16_t)i) return 1;
    }

    for (unsigned i = UINT8_MAX + 1; i <= UINT16_MAX; ++i)
    {
        clear(buf);
        pack_uint(buf, (uint16_t)i);
        if (buf[0] != (uint8_t)0xcd) return 1;

        unpack_u16_data(buf + 1);
        if (*((uint16_t *)(buf + 1)) != (uint16_t)i) return 1;
    }

    return 0;
}

int main(void) { return test_pack_bool() | test_pack_u8() | test_pack_u16(); }
