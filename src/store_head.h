#ifndef STORE_HEAD_H
#define STORE_HEAD_H

#include "compiler.h"
#include "first_byte.h"
#include "format.h"
#include "store_body.h"

static inline unsigned long __lip_store_head_false(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_FALSE);
    return 1;
}

static inline unsigned long __lip_store_head_true(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_TRUE);
    return 1;
}

static inline unsigned long __lip_store_head_pfix_int(uint8_t buf[static 1],
                                                      unsigned val)
{
    buf[0] = __lip_first_byte_fix(LIP_FMT_POSITIVE_FIXINT, (int)val);
    return 1;
}

static inline unsigned long __lip_store_head_nfix_int(uint8_t buf[static 1],
                                                      int val)
{
    buf[0] = __lip_first_byte_fix(LIP_FMT_NEGATIVE_FIXINT, val);
    return 1;
}

static inline unsigned long __lip_store_head_u8(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_UINT_8);
    return 1;
}

static inline unsigned long __lip_store_head_i8(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_INT_8);
    return 1;
}

static inline unsigned long __lip_store_head_u16(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_UINT_16);
    return 1;
}

static inline unsigned long __lip_store_head_i16(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_INT_16);
    return 1;
}

static inline unsigned long __lip_store_head_u32(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_UINT_32);
    return 1;
}

static inline unsigned long __lip_store_head_i32(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_INT_32);
    return 1;
}

static inline unsigned long __lip_store_head_u64(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_UINT_64);
    return 1;
}

static inline unsigned long __lip_store_head_i64(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_INT_64);
    return 1;
}

static inline unsigned long __lip_store_head_fix_array(uint8_t buf[static 1],
                                                       unsigned length)
{
    buf[0] = __lip_first_byte_fix(LIP_FMT_FIXARRAY, (int)length);
    return 1;
}

static inline unsigned long __lip_store_head_array16(uint8_t buf[static 3],
                                                     unsigned length)
{
    buf[0] = __lip_first_byte(LIP_FMT_ARRAY_16);
    return __lip_store_body_num16(buf + 1, NUM16(length)) + 1;
}

static inline unsigned long __lip_store_head_array32(uint8_t buf[static 5],
                                                     unsigned length)
{
    buf[0] = __lip_first_byte(LIP_FMT_ARRAY_32);
    return __lip_store_body_num32(buf + 1, NUM32(length)) + 1;
}

static inline unsigned long __lip_store_head_fix_map(uint8_t buf[static 1],
                                                     unsigned length)
{
    buf[0] = __lip_first_byte_fix(LIP_FMT_FIXMAP, (int)length);
    return 1;
}

static inline unsigned long __lip_store_head_map16(uint8_t buf[static 3],
                                                   unsigned length)
{
    buf[0] = __lip_first_byte(LIP_FMT_MAP_16);
    return __lip_store_body_num16(buf + 1, NUM16(length)) + 1;
}

static inline unsigned long __lip_store_head_map32(uint8_t buf[static 5],
                                                   unsigned length)
{
    buf[0] = __lip_first_byte(LIP_FMT_MAP_32);
    return __lip_store_body_num32(buf + 1, NUM32(length)) + 1;
}

static inline unsigned long __lip_store_head_f32(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_FLOAT_32);
    return 1;
}

static inline unsigned long __lip_store_head_f64(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_FLOAT_64);
    return 1;
}

static inline unsigned long __lip_store_head_fix_str(uint8_t buf[static 1],
                                                     unsigned length)
{
    buf[0] = __lip_first_byte_fix(LIP_FMT_FIXSTR, (int)length);
    return 1;
}

static inline unsigned long __lip_store_head_str8(uint8_t buf[static 2],
                                                  unsigned length)
{
    buf[0] = __lip_first_byte(LIP_FMT_STR_8);
    return __lip_store_body_num8(buf + 1, NUM8(length)) + 1;
}

static inline unsigned long __lip_store_head_str16(uint8_t buf[static 3],
                                                   unsigned length)
{
    buf[0] = __lip_first_byte(LIP_FMT_STR_16);
    return __lip_store_body_num16(buf + 1, NUM16(length)) + 1;
}

static inline unsigned long __lip_store_head_str32(uint8_t buf[static 5],
                                                   unsigned length)
{
    buf[0] = __lip_first_byte(LIP_FMT_STR_32);
    return __lip_store_body_num32(buf + 1, NUM32(length)) + 1;
}

#endif
