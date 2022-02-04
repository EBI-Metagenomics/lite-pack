#ifndef STORE_H
#define STORE_H

#include "compiler.h"
#include "first_byte.h"
#include "format.h"
#include "store_body.h"
#include "store_head.h"

static inline unsigned long __lip_store_false(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_FALSE);
    return 1;
}

static inline unsigned long __lip_store_true(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_TRUE);
    return 1;
}

static inline unsigned long __lip_store_pfix_int(uint8_t buf[static 1],
                                                 unsigned val)
{
    buf[0] = __lip_first_byte_fix(LIP_FMT_POSITIVE_FIXINT, (int)val);
    return 1;
}

static inline unsigned long __lip_store_nfix_int(uint8_t buf[static 1], int val)
{
    buf[0] = __lip_first_byte_fix(LIP_FMT_NEGATIVE_FIXINT, val);
    return 1;
}

static inline unsigned long __lip_store_u8(uint8_t buf[static 2], unsigned val)
{
    return __lip_store_u8_head(buf) + __lip_store_u8_body(buf + 1, val);
}

static inline unsigned long __lip_store_i8(uint8_t buf[static 2], int val)
{
    return __lip_store_i8_head(buf) + __lip_store_i8_body(buf + 1, val);
}

static inline unsigned long __lip_store_u16(uint8_t buf[static 3], unsigned val)
{
    return __lip_store_u16_head(buf) + __lip_store_u16_body(buf + 1, val);
}

static inline unsigned long __lip_store_i16(uint8_t buf[static 3], int val)
{
    return __lip_store_i16_head(buf) + __lip_store_i16_body(buf + 1, val);
}

static inline unsigned long __lip_store_u32(uint8_t buf[static 5], unsigned val)
{
    return __lip_store_u32_head(buf) + __lip_store_u32_body(buf + 1, val);
}

static inline unsigned long __lip_store_i32(uint8_t buf[static 5], int val)
{
    return __lip_store_i32_head(buf) + __lip_store_i32_body(buf + 1, val);
}

static inline unsigned long __lip_store_u64(uint8_t buf[static 9],
                                            unsigned long val)
{
    return __lip_store_u64_head(buf) + __lip_store_u64_body(buf + 1, val);
}

static inline unsigned long __lip_store_i64(uint8_t buf[static 9], long val)
{
    return __lip_store_i64_head(buf) + __lip_store_i64_body(buf + 1, val);
}

static inline unsigned long __lip_store_f32(uint8_t buf[static 5], float val)
{
    return __lip_store_f32_head(buf) + __lip_store_f32_body(buf + 1, val);
}

static inline unsigned long __lip_store_f64(uint8_t buf[static 9], double val)
{
    return __lip_store_f64_head(buf) + __lip_store_f64_body(buf + 1, val);
}

static inline unsigned long __lip_store_fix_str(uint8_t buf[static 2],
                                                unsigned length,
                                                char const val[static 1])
{
    return __lip_store_fix_str_head(buf, length) +
           __lip_store_fix_str_body(buf + 1, length, val);
}

static inline unsigned long __lip_store_str8(uint8_t buf[static 3],
                                             unsigned length,
                                             char const val[static 1])
{
    return __lip_store_str8_head(buf, length) +
           __lip_store_str8_body(buf + 2, length, val);
}

static inline unsigned long __lip_store_str16(uint8_t buf[static 4],
                                              unsigned length,
                                              char const val[static 1])
{
    return __lip_store_str16_head(buf, length) +
           __lip_store_str16_body(buf + 3, length, val);
}

static inline unsigned long __lip_store_str32(uint8_t buf[static 6],
                                              unsigned length,
                                              char const val[static 1])
{
    return __lip_store_str32_head(buf, length) +
           __lip_store_str32_body(buf + 5, length, val);
}

#endif
