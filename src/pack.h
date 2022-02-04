#ifndef PACK_H
#define PACK_H

#include "compiler.h"
#include "store.h"
#include <stdbool.h>
#include <stdint.h>

static inline unsigned long lip_pack_false(uint8_t buf[static 1])
{
    return __lip_store_false(buf);
}

static inline unsigned long lip_pack_true(uint8_t buf[static 1])
{
    return __lip_store_true(buf);
}

static inline unsigned long lip_pack_bool(uint8_t buf[static 1], bool val)
{
    if (val) return lip_pack_true(buf);
    return lip_pack_false(buf);
}

static inline unsigned long __lip_pack_u8(uint8_t buf[static 1], unsigned val)
{
    if (val <= 0x7f) return __lip_store_pfix_int(buf, (uint8_t)val);
    return __lip_store_u8(buf, val);
}

static inline unsigned long __lip_pack_u16(uint8_t buf[static 2], unsigned val)
{
    if (val <= 0xff) return __lip_pack_u8(buf, val);
    return __lip_store_u16(buf, val);
}

static inline unsigned long __lip_pack_u32(uint8_t buf[static 2], unsigned val)
{
    if (val <= 0xff)
        return __lip_pack_u8(buf, val);
    else if (val <= 0xffff)
        return __lip_pack_u16(buf, val);
    return __lip_store_u32(buf, val);
}

static inline unsigned long __lip_pack_u64(uint8_t buf[static 2],
                                           unsigned long val)
{
    if (val <= 0xff)
        return __lip_pack_u8(buf, (unsigned)val);
    else if (val <= 0xffff)
        return __lip_pack_u16(buf, (unsigned)val);
    else if (val <= 0xffffffff)
        return __lip_pack_u32(buf, (unsigned)val);
    return __lip_store_u64(buf, val);
}

static inline unsigned long __lip_pack_i8(uint8_t buf[static 1], int val)
{
    if (val >= 0) return __lip_pack_u8(buf, (unsigned)val);
    if (val >= -32) return __lip_store_nfix_int(buf, val);
    return __lip_store_i8(buf, val);
}

static inline unsigned long __lip_pack_i16(uint8_t buf[static 1], int val)
{
    if (val >= 0) return __lip_pack_u16(buf, (unsigned)val);
    if (val >= -32) return __lip_store_nfix_int(buf, val);
    if (val >= INT8_MIN) return __lip_store_i8(buf, val);
    return __lip_store_i16(buf, val);
}

static inline unsigned long __lip_pack_i32(uint8_t buf[static 1], int val)
{
    if (val >= 0) return __lip_pack_u32(buf, (unsigned)val);
    if (val >= -32) return __lip_store_nfix_int(buf, val);
    if (val >= INT8_MIN) return __lip_store_i8(buf, val);
    if (val >= INT16_MIN) return __lip_store_i16(buf, val);
    return __lip_store_i32(buf, val);
}

static inline unsigned long __lip_pack_i64(uint8_t buf[static 1], long val)
{
    if (val >= 0) return __lip_pack_u64(buf, (unsigned long)val);
    if (val >= -32) return __lip_store_nfix_int(buf, (int)val);
    if (val >= INT8_MIN) return __lip_store_i8(buf, (int)val);
    if (val >= INT16_MIN) return __lip_store_i16(buf, (int)val);
    if (val >= INT32_MIN) return __lip_store_i32(buf, (int)val);
    return __lip_store_i64(buf, val);
}

static inline unsigned long __lip_pack_f32(uint8_t buf[static 5], float val)
{
    return __lip_store_f32(buf, val);
}

static inline unsigned long __lip_pack_f64(uint8_t buf[static 9], double val)
{
    return __lip_store_f64(buf, val);
}

static inline unsigned long lip_pack_str(uint8_t buf[static 2],
                                         char const val[static 1])
{
    unsigned length = (unsigned)strlen(val);
    if (length <= 0x1f)
        return __lip_store_fix_str(buf, length, val);
    else if (length <= 0xff)
        return __lip_store_str8(buf, length, val);
    else if (length <= 0xffff)
        return __lip_store_str16(buf, length, val);
    return __lip_store_str32(buf, length, val);
}

static inline unsigned long lip_pack_map(uint8_t buf[static 1], unsigned length)
{
    if (length <= 0xf)
        return __lip_store_fix_map(buf, length);
    else if (length <= 0xffff)
        return __lip_store_map16(buf, length);
    return __lip_store_map32(buf, length);
}

#endif
