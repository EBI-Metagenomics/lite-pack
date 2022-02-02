#include "lite_pack.h"
#include "store.h"
#include <string.h>

void pack_u8(uint8_t buf[static 1], unsigned val)
{
    if (val <= 0x7f)
        store_pfix(buf, val);
    else
        store_u8(buf, val);
}

void pack_u16(uint8_t buf[static 1], unsigned val)
{
    if (val <= 0xff)
        pack_u8(buf, val);
    else
        store_u16(buf, val);
}

void pack_u32(uint8_t buf[static 1], unsigned val)
{
    if (val <= 0xff)
        pack_u8(buf, (unsigned)val);
    else if (val <= 0xffff)
        pack_u16(buf, (unsigned)val);
    else
        store_u32(buf, val);
}

void pack_u64(uint8_t buf[static 1], unsigned long val)
{
    if (val <= 0xff)
        pack_u8(buf, (unsigned)val);
    else if (val <= 0xffff)
        pack_u16(buf, (unsigned)val);
    else if (val <= 0xffffffff)
        pack_u32(buf, (unsigned)val);
    else
        store_u64(buf, val);
}
