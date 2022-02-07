#ifndef STORE_H
#define STORE_H

#include "compiler.h"
#include "first_byte.h"
#include "format.h"
#include "store_body.h"
#include "store_head.h"

static inline unsigned long __lip_store_false(uint8_t buf[static 1])
{
    return __lip_store_head_false(buf);
}

static inline unsigned long __lip_store_true(uint8_t buf[static 1])
{
    return __lip_store_head_true(buf);
}

static inline unsigned long __lip_store_pfix_int(uint8_t buf[static 1],
                                                 unsigned val)
{
    return __lip_store_head_pfix_int(buf, val);
}

static inline unsigned long __lip_store_nfix_int(uint8_t buf[static 1], int val)
{
    return __lip_store_head_nfix_int(buf, val);
}

static inline unsigned long __lip_store_u8(uint8_t buf[static 2], unsigned val)
{
    return __lip_store_head_u8(buf) + __lip_store_body_num8(buf + 1, NUM8(val));
}

static inline unsigned long __lip_store_i8(uint8_t buf[static 2], int val)
{
    return __lip_store_head_i8(buf) + __lip_store_body_num8(buf + 1, NUM8(val));
}

static inline unsigned long __lip_store_u16(uint8_t buf[static 3], unsigned val)
{
    return __lip_store_head_u16(buf) +
           __lip_store_body_num16(buf + 1, NUM16(val));
}

static inline unsigned long __lip_store_i16(uint8_t buf[static 3], int val)
{
    return __lip_store_head_i16(buf) +
           __lip_store_body_num16(buf + 1, NUM16(val));
}

static inline unsigned long __lip_store_u32(uint8_t buf[static 5], unsigned val)
{
    return __lip_store_head_u32(buf) +
           __lip_store_body_num32(buf + 1, NUM32(val));
}

static inline unsigned long __lip_store_i32(uint8_t buf[static 5], int val)
{
    return __lip_store_head_i32(buf) +
           __lip_store_body_num32(buf + 1, NUM32(val));
}

static inline unsigned long __lip_store_u64(uint8_t buf[static 9],
                                            unsigned long val)
{
    return __lip_store_head_u64(buf) +
           __lip_store_body_num64(buf + 1, NUM64(val));
}

static inline unsigned long __lip_store_i64(uint8_t buf[static 9], long val)
{
    return __lip_store_head_i64(buf) +
           __lip_store_body_num64(buf + 1, NUM64(val));
}

static inline unsigned long __lip_store_f32(uint8_t buf[static 5], float val)
{
    return __lip_store_head_f32(buf) +
           __lip_store_body_num32(buf + 1, NUM32(val));
}

static inline unsigned long __lip_store_f64(uint8_t buf[static 9], double val)
{
    return __lip_store_head_f64(buf) +
           __lip_store_body_num64(buf + 1, NUM64(val));
}

static inline unsigned long __lip_store_fix_str(uint8_t buf[static 2],
                                                unsigned length,
                                                char const val[static 1])
{
    return __lip_store_head_fix_str(buf, length) +
           __lip_store_body_str(buf + 1, length, val);
}

static inline unsigned long __lip_store_str8(uint8_t buf[static 3],
                                             unsigned length,
                                             char const val[static 1])
{
    return __lip_store_head_str8(buf, length) +
           __lip_store_body_str(buf + 2, length, val);
}

static inline unsigned long __lip_store_str16(uint8_t buf[static 4],
                                              unsigned length,
                                              char const val[static 1])
{
    return __lip_store_head_str16(buf, length) +
           __lip_store_body_str(buf + 3, length, val);
}

static inline unsigned long __lip_store_str32(uint8_t buf[static 6],
                                              unsigned length,
                                              char const val[static 1])
{
    return __lip_store_head_str32(buf, length) +
           __lip_store_body_str(buf + 5, length, val);
}

#endif
