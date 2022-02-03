#ifndef STORE_H
#define STORE_H

#include "compiler.h"
#include "first_byte.h"
#include "format.h"
#include "store_data.h"

static inline void __lip_store_pfix_int(uint8_t buf[static 1], uint8_t val)
{
    buf[0] = val;
}

static inline void __lip_store_u8(uint8_t buf[static 1], unsigned val)
{
    buf[0] = __lip_first_byte(FMT_UINT_8);
    __lip_store_u8_data(buf + 1, val);
}

static inline void __lip_store_u16(uint8_t buf[static 1], unsigned val)
{
    buf[0] = __lip_first_byte(FMT_UINT_16);
    __lip_store_u16_data(buf + 1, val);
}

static inline void __lip_store_u32(uint8_t buf[static 1], unsigned val)
{
    buf[0] = __lip_first_byte(FMT_UINT_32);
    __lip_store_u32_data(buf + 1, val);
}

static inline void __lip_store_u64(uint8_t buf[static 1], unsigned long val)
{
    buf[0] = __lip_first_byte(FMT_UINT_64);
    __lip_store_u64_data(buf + 1, val);
}

static inline void __lip_store_f32(uint8_t buf[static 1], float val)
{
    CHECK_FLOAT_ORDER();
    buf[0] = __lip_first_byte(FMT_FLOAT_32);
    __lip_store_f32_data(buf + 1, val);
}

static inline void __lip_store_f64(uint8_t buf[static 1], double val)
{
    CHECK_FLOAT_ORDER();
    buf[0] = __lip_first_byte(FMT_FLOAT_64);
    __lip_store_f64_data(buf + 1, val);
}

static inline void __lip_store_fix_str(uint8_t buf[static 1],
                                       unsigned long length,
                                       char const val[static 1])
{
    buf[0] = __lip_first_byte_fix(FMT_FIXSTR, (int)length);
    __lip_store_fix_str_data(buf + 1, length, val);
}

static inline void __lip_store_str8(uint8_t buf[static 1], unsigned long length,
                                    char const val[static 1])
{
    buf[0] = __lip_first_byte(FMT_STR_8);
    buf[1] = (uint8_t)length;
    __lip_store_fix_str_data(buf + 2, length, val);
}

static inline void __lip_store_str16(uint8_t buf[static 1],
                                     unsigned long length,
                                     char const val[static 1])
{
    buf[0] = __lip_first_byte(FMT_STR_16);
    uint16_t len = big_endian((uint16_t)length);
    memcpy(buf + 1, &len, 2);
    __lip_store_str16_data(buf + 3, length, val);
}

static inline void __lip_store_str32(uint8_t buf[static 1],
                                     unsigned long length,
                                     char const val[static 1])
{
    buf[0] = __lip_first_byte(FMT_STR_32);
    uint32_t len = big_endian((uint32_t)length);
    memcpy(buf + 1, &len, 4);
    __lip_store_str32_data(buf + 5, length, val);
}

#endif
