#ifndef PACK_H
#define PACK_H

#include "compiler.h"
#include "store.h"
#include <stdbool.h>
#include <stdint.h>

static inline void lip_pack_false(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_FALSE);
}

static inline void lip_pack_true(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_TRUE);
}

static inline void lip_pack_bool(uint8_t buf[static 1], bool val)
{
    if (val)
        lip_pack_true(buf);
    else
        lip_pack_false(buf);
}

static inline void __lip_pack_u8(uint8_t buf[static 1], unsigned val)
{
    if (val <= 0x7f)
        __lip_store_pfix_int(buf, (uint8_t)val);
    else
        __lip_store_u8(buf, val);
}

static inline void __lip_pack_u16(uint8_t buf[static 2], unsigned val)
{
    if (val <= 0xff)
        __lip_pack_u8(buf, val);
    else
        __lip_store_u16(buf, val);
}

static inline void __lip_pack_u32(uint8_t buf[static 2], unsigned val)
{
    if (val <= 0xff)
        __lip_pack_u8(buf, (unsigned)val);
    else if (val <= 0xffff)
        __lip_pack_u16(buf, (unsigned)val);
    else
        __lip_store_u32(buf, val);
}

static inline void __lip_pack_u64(uint8_t buf[static 2], unsigned long val)
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

static inline void __lip_pack_f32(uint8_t buf[static 5], float val)
{
    __lip_store_f32(buf, val);
}

static inline void __lip_pack_f64(uint8_t buf[static 9], double val)
{
    __lip_store_f64(buf, val);
}

static inline void lip_pack_str(uint8_t buf[static 2], char const val[static 1])
{
    unsigned length = (unsigned)strlen(val);
    if (length <= 0x1f)
        __lip_store_fix_str(buf, length, val);
    else if (length <= 0xff)
        __lip_store_str8(buf, length, val);
    else if (length <= 0xffff)
        __lip_store_str16(buf, length, val);
    else
        __lip_store_str32(buf, length, val);
}

static inline void lip_pack_map_length(uint8_t buf[static 1], unsigned length)
{
    if (length <= 0xf)
        __lip_store_fix_map_length(buf, length);
    else if (length <= 0xffff)
        __lip_store_map16_length(buf, length);
    else
        __lip_store_map32_length(buf, length);
}

#endif
