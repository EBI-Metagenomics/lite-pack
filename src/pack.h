#ifndef PACK_H
#define PACK_H

#include "compiler.h"
#include "store.h"
#include <stdbool.h>
#include <stdint.h>

static inline void lip_pack_true(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(FMT_TRUE);
}

static inline void lip_pack_false(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(FMT_FALSE);
}

static inline void lip_pack_bool(uint8_t buf[static 1], bool val)
{
    if (val)
        lip_pack_true(buf);
    else
        lip_pack_false(buf);
}

static inline void lip_pack_str(uint8_t buf[static 1], char const val[static 1])
{
    unsigned long length = strlen(val);
    if (length <= 0x1f)
        __lip_store_fix_str(buf, length, val);
    else if (length <= 0xff)
        __lip_store_str8(buf, length, val);
    else if (length <= 0xffff)
        __lip_store_str16(buf, length, val);
    else
        __lip_store_str32(buf, length, val);
}

static inline void __lip_pack_u8(uint8_t buf[static 1], unsigned val)
{
    if (val <= 0x7f)
        __lip_store_pfix_int(buf, val);
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
    else if (val <= 0xffffffffUL)
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
