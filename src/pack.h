#ifndef PACK_H
#define PACK_H

#include "compiler.h"
#include "store.h"
#include <stdbool.h>
#include <stdint.h>

#define __lip_pack_int(buf, val)                                               \
    _Generic((val), uint8_t                                                    \
             : __lip_pack_u8, uint16_t                                         \
             : __lip_pack_u16, uint32_t                                        \
             : __lip_pack_u32, uint64_t                                        \
             : __lip_pack_u64, unsigned long                                   \
             : __lip_pack_u64, int8_t                                          \
             : __lip_pack_i8, int16_t                                          \
             : __lip_pack_i16, int32_t                                         \
             : __lip_pack_i32, int64_t                                         \
             : __lip_pack_i64, long                                            \
             : __lip_pack_i64)(buf, val)

#define __lip_pack_float(buf, val)                                             \
    _Generic((val), float : __lip_pack_f32, double : __lip_pack_f64)(buf, val)

static inline unsigned long __lip_pack_false(uint8_t buf[static 1])
{
    return __lip_store_false(buf);
}

static inline unsigned long __lip_pack_true(uint8_t buf[static 1])
{
    return __lip_store_true(buf);
}

static inline unsigned long lip_pack_bool(uint8_t buf[static 1], bool val)
{
    if (val) return __lip_pack_true(buf);
    return __lip_pack_false(buf);
}

static inline unsigned long __lip_pack_u8(uint8_t buf[static 1], unsigned val)
{
    if (val <= 0x7fU) return __lip_store_pfix_int(buf, (uint8_t)val);
    return __lip_store_u8(buf, (uint8_t)val);
}

static inline unsigned long __lip_pack_u16(uint8_t buf[static 1], unsigned val)
{
    if (val <= 0xffU) return __lip_pack_u8(buf, val);
    return __lip_store_u16(buf, (uint16_t)val);
}

static inline unsigned long __lip_pack_u32(uint8_t buf[static 1], unsigned val)
{
    if (val <= 0xffU)
        return __lip_pack_u8(buf, val);
    else if (val <= 0xffffU)
        return __lip_pack_u16(buf, val);
    return __lip_store_u32(buf, (uint32_t)val);
}

static inline unsigned long __lip_pack_u64(uint8_t buf[static 1],
                                           unsigned long val)
{
    if (val <= 0xffUL)
        return __lip_pack_u8(buf, (unsigned)val);
    else if (val <= 0xffffUL)
        return __lip_pack_u16(buf, (unsigned)val);
    else if (val <= 0xffffffffUL)
        return __lip_pack_u32(buf, (unsigned)val);
    return __lip_store_u64(buf, (uint64_t)val);
}

static inline unsigned long __lip_pack_i8(uint8_t buf[static 1], int val)
{
    if (val >= 0) return __lip_pack_u8(buf, (unsigned)val);
    if (val >= -32) return __lip_store_nfix_int(buf, (int8_t)val);
    return __lip_store_i8(buf, (int8_t)val);
}

static inline unsigned long __lip_pack_i16(uint8_t buf[static 1], int val)
{
    if (val >= 0) return __lip_pack_u16(buf, (unsigned)val);
    if (val >= -32) return __lip_store_nfix_int(buf, (int8_t)val);
    if (val >= INT8_MIN) return __lip_store_i8(buf, (int8_t)val);
    return __lip_store_i16(buf, (int16_t)val);
}

static inline unsigned long __lip_pack_i32(uint8_t buf[static 1], int val)
{
    if (val >= 0) return __lip_pack_u32(buf, (unsigned)val);
    if (val >= -32) return __lip_store_nfix_int(buf, (int8_t)val);
    if (val >= INT8_MIN) return __lip_store_i8(buf, (int8_t)val);
    if (val >= INT16_MIN) return __lip_store_i16(buf, (int16_t)val);
    return __lip_store_i32(buf, (int32_t)val);
}

static inline unsigned long __lip_pack_i64(uint8_t buf[static 1], long val)
{
    if (val >= 0) return __lip_pack_u64(buf, (unsigned long)val);
    if (val >= -32) return __lip_store_nfix_int(buf, (int8_t)val);
    if (val >= INT8_MIN) return __lip_store_i8(buf, (int8_t)val);
    if (val >= INT16_MIN) return __lip_store_i16(buf, (int16_t)val);
    if (val >= INT32_MIN) return __lip_store_i32(buf, (int32_t)val);
    return __lip_store_i64(buf, (int64_t)val);
}

static inline unsigned long __lip_pack_f32(uint8_t buf[static 5], float val)
{
    return __lip_store_f32(buf, val);
}

static inline unsigned long __lip_pack_f64(uint8_t buf[static 9], double val)
{
    return __lip_store_f64(buf, val);
}

static inline unsigned lip_pack_str_size(uint8_t buf[static 1], unsigned size)
{
    if (size <= 0x1f)
        return __lip_store_head_fix_str(buf, (uint8_t)size);
    else if (size <= 0xff)
        return __lip_store_head_str8(buf, (uint8_t)size);
    else if (size <= 0xffff)
        return __lip_store_head_str16(buf, (uint16_t)size);
    return __lip_store_head_str32(buf, size);
}

static inline unsigned lip_pack_str_data(uint8_t buf[static 1], unsigned size,
                                         char const val[static 1])
{
    memcpy(buf, val, size);
    return size;
}

static inline unsigned long lip_pack_str(uint8_t buf[static 2],
                                         char const val[static 1])
{
    unsigned length = (unsigned)strlen(val);
    unsigned long offset = lip_pack_str_size(buf, length);
    return offset + lip_pack_str_data(buf + offset, length, val);
}

static inline unsigned lip_pack_array_size(uint8_t buf[static 1], unsigned size)
{
    if (size <= 0xf)
        return __lip_store_head_fix_array(buf, (uint8_t)size);
    else if (size <= 0xffff)
        return __lip_store_head_array16(buf, (uint16_t)size);
    return __lip_store_head_array32(buf, (uint32_t)size);
}

static inline unsigned lip_pack_map_size(uint8_t buf[static 1], unsigned size)
{
    if (size <= 0xf)
        return __lip_store_head_fix_map(buf, (uint8_t)size);
    else if (size <= 0xffff)
        return __lip_store_head_map16(buf, (uint16_t)size);
    return __lip_store_head_map32(buf, (uint32_t)size);
}

#endif
