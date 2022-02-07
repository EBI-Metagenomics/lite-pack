#ifndef STORE_HEAD_H
#define STORE_HEAD_H

#include "compiler.h"
#include "first_byte.h"
#include "format.h"
#include "store_body.h"

static inline unsigned long __lip_store_u8_head(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_UINT_8);
    return 1;
}

static inline unsigned long __lip_store_i8_head(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_INT_8);
    return 1;
}

static inline unsigned long __lip_store_u16_head(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_UINT_16);
    return 1;
}

static inline unsigned long __lip_store_i16_head(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_INT_16);
    return 1;
}

static inline unsigned long __lip_store_u32_head(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_UINT_32);
    return 1;
}

static inline unsigned long __lip_store_i32_head(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_INT_32);
    return 1;
}

static inline unsigned long __lip_store_u64_head(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_UINT_64);
    return 1;
}

static inline unsigned long __lip_store_i64_head(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_INT_64);
    return 1;
}

static inline unsigned long __lip_store_fix_map_head(uint8_t buf[static 1],
                                                     unsigned length)
{
    buf[0] = __lip_first_byte_fix(LIP_FMT_FIXMAP, (int)length);
    return 1;
}

static inline unsigned long __lip_store_map16_head(uint8_t buf[static 3],
                                                   unsigned length)
{
    buf[0] = __lip_first_byte(LIP_FMT_MAP_16);
    return __lip_store_num16_body(buf + 1, NUM16(length)) + 1;
}

static inline unsigned long __lip_store_map32_head(uint8_t buf[static 5],
                                                   unsigned length)
{
    buf[0] = __lip_first_byte(LIP_FMT_MAP_32);
    return __lip_store_num32_body(buf + 1, NUM32(length)) + 1;
}

static inline unsigned long __lip_store_f32_head(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_FLOAT_32);
    return 1;
}

static inline unsigned long __lip_store_f64_head(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_FLOAT_64);
    return 1;
}

static inline unsigned long __lip_store_fix_str_head(uint8_t buf[static 1],
                                                     unsigned length)
{
    buf[0] = __lip_first_byte_fix(LIP_FMT_FIXSTR, (int)length);
    return 1;
}

static inline unsigned long __lip_store_str8_head(uint8_t buf[static 2],
                                                  unsigned length)
{
    buf[0] = __lip_first_byte(LIP_FMT_STR_8);
    return __lip_store_num8_body(buf + 1, NUM8(length)) + 1;
}

static inline unsigned long __lip_store_str16_head(uint8_t buf[static 3],
                                                   unsigned length)
{
    buf[0] = __lip_first_byte(LIP_FMT_STR_16);
    return __lip_store_num16_body(buf + 1, NUM16(length)) + 1;
}

static inline unsigned long __lip_store_str32_head(uint8_t buf[static 5],
                                                   unsigned length)
{
    buf[0] = __lip_first_byte(LIP_FMT_STR_32);
    return __lip_store_num32_body(buf + 1, NUM32(length)) + 1;
}

#endif
