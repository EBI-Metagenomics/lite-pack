#ifndef PACK_H
#define PACK_H

#include "compiler.h"
#include "store.h"
#include <stdint.h>

static inline void __lip_pack_u8(uint8_t buf[static 1], unsigned val)
{
    if (val <= 0x7f)
        __lip_store_pfix(buf, val);
    else
        __lip_store_u8(buf, val);
}

static inline void __lip_pack_u16(uint8_t buf[static 1], unsigned val)
{
    if (val <= 0xff)
        __lip_pack_u8(buf, val);
    else
        __lip_store_u16(buf, val);
}

static inline void __lip_pack_u32(uint8_t buf[static 1], unsigned val)
{
    if (val <= 0xff)
        __lip_pack_u8(buf, (unsigned)val);
    else if (val <= 0xffff)
        __lip_pack_u16(buf, (unsigned)val);
    else
        __lip_store_u32(buf, val);
}

static inline void __lip_pack_u64(uint8_t buf[static 1], unsigned long val)
{
    if (val <= 0xff)
        __lip_pack_u8(buf, (unsigned)val);
    else if (val <= 0xffff)
        __lip_pack_u16(buf, (unsigned)val);
    else if (val <= 0xffffffff)
        __lip_pack_u32(buf, (unsigned)val);
    else
        __lip_store_u64(buf, val);
}

static inline void __lip_pack_f32(uint8_t buf[static 1], float val)
{
    __lip_store_f32(buf, val);
}

static inline void __lip_pack_f64(uint8_t buf[static 1], double val)
{
    __lip_store_f64(buf, val);
}

#endif
