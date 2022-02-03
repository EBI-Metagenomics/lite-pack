#ifndef STORE_H
#define STORE_H

#include "compiler.h"
#include "first_byte.h"
#include "format.h"
#include "store_data.h"

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
                                                 uint8_t val)
{
    buf[0] = __lip_first_byte_fix(LIP_FMT_POSITIVE_FIXINT, val);
    return 1;
}

static inline unsigned long __lip_store_u8(uint8_t buf[static 2], unsigned val)
{
    buf[0] = __lip_first_byte(LIP_FMT_UINT_8);
    return __lip_store_u8_data(buf + 1, val) + 1;
}

static inline unsigned long __lip_store_u16(uint8_t buf[static 3], unsigned val)
{
    buf[0] = __lip_first_byte(LIP_FMT_UINT_16);
    return __lip_store_u16_data(buf + 1, val) + 1;
}

static inline unsigned long __lip_store_u32(uint8_t buf[static 5], unsigned val)
{
    buf[0] = __lip_first_byte(LIP_FMT_UINT_32);
    return __lip_store_u32_data(buf + 1, val) + 1;
}

static inline unsigned long __lip_store_u64(uint8_t buf[static 9],
                                            unsigned long val)
{
    buf[0] = __lip_first_byte(LIP_FMT_UINT_64);
    return __lip_store_u64_data(buf + 1, val) + 1;
}

static inline unsigned long __lip_store_fix_map_length(uint8_t buf[static 1],
                                                       unsigned length)
{
    buf[0] = __lip_first_byte_fix(LIP_FMT_FIXMAP, (int)length);
    return 1;
}

static inline unsigned long __lip_store_map16_length(uint8_t buf[static 3],
                                                     unsigned length)
{
    buf[0] = __lip_first_byte(LIP_FMT_MAP_16);
    return __lip_store_u16_data(buf + 1, length) + 1;
}

static inline unsigned long __lip_store_map32_length(uint8_t buf[static 5],
                                                     unsigned length)
{
    buf[0] = __lip_first_byte(LIP_FMT_MAP_32);
    return __lip_store_u32_data(buf + 1, length) + 1;
}

static inline unsigned long __lip_store_f32(uint8_t buf[static 5], float val)
{
    CHECK_FLOAT_ORDER();
    buf[0] = __lip_first_byte(LIP_FMT_FLOAT_32);
    return __lip_store_f32_data(buf + 1, val) + 1;
}

static inline unsigned long __lip_store_f64(uint8_t buf[static 9], double val)
{
    CHECK_FLOAT_ORDER();
    buf[0] = __lip_first_byte(LIP_FMT_FLOAT_64);
    return __lip_store_f64_data(buf + 1, val) + 1;
}

static inline unsigned long __lip_store_fix_str(uint8_t buf[static 2],
                                                unsigned length,
                                                char const val[static 1])
{
    buf[0] = __lip_first_byte_fix(LIP_FMT_FIXSTR, (int)length);
    return __lip_store_fix_str_data(buf + 1, length, val) + 1;
}

static inline unsigned long __lip_store_str8(uint8_t buf[static 3],
                                             unsigned length,
                                             char const val[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_STR_8);
    buf[1] = (uint8_t)length;
    return __lip_store_fix_str_data(buf + 2, length, val) + 2;
}

static inline unsigned long __lip_store_str16(uint8_t buf[static 4],
                                              unsigned length,
                                              char const val[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_STR_16);
    uint16_t len = big_endian((uint16_t)length);
    memcpy(buf + 1, &len, 2);
    return __lip_store_str16_data(buf + 3, length, val) + 3;
}

static inline unsigned long __lip_store_str32(uint8_t buf[static 6],
                                              unsigned length,
                                              char const val[static 1])
{
    buf[0] = __lip_first_byte(LIP_FMT_STR_32);
    uint32_t len = big_endian((uint32_t)length);
    memcpy(buf + 1, &len, 4);
    return __lip_store_str32_data(buf + 5, length, val) + 5;
}

#endif
