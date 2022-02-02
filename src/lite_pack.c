#include "lite_pack.h"
#include "store.h"
#include <string.h>

void pack_u8(uint8_t buf[static 1], uint8_t val)
{
    if (val <= 0x7f)
        store_pfix(buf, val);
    else
        store_u8(buf, val);
}

void pack_u16(uint8_t buf[static 1], uint16_t val)
{
    if (val <= 0xff)
        pack_u8(buf, (uint8_t)val);
    else
        store_u16(buf, val);
}

void pack_u32(uint8_t buf[static 1], uint32_t val)
{
    if (val <= 0xff)
        pack_u8(buf, (uint8_t)val);
    else if (val <= 0xffff)
        pack_u16(buf, (uint8_t)val);
    else
        store_u32(buf, val);
}
