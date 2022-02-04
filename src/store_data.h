#ifndef STORE_DATA_H
#define STORE_DATA_H

#include "compiler.h"
#include <stdint.h>
#include <string.h>

static inline unsigned long __lip_store_u8_data(uint8_t buf[static 1],
                                                unsigned val)
{
    val = big_endian((uint8_t)val);
    memcpy(buf, &val, 1);
    return 1;
}

static inline unsigned long __lip_store_i8_data(uint8_t buf[static 1], int val)
{
    val = big_endian((int8_t)val);
    memcpy(buf, &val, 1);
    return 1;
}

static inline unsigned long __lip_store_u16_data(uint8_t buf[static 2],
                                                 unsigned val)
{
    val = big_endian((uint16_t)val);
    memcpy(buf, &val, 2);
    return 2;
}

static inline unsigned long __lip_store_i16_data(uint8_t buf[static 2], int val)
{
    val = big_endian((int16_t)val);
    memcpy(buf, &val, 2);
    return 2;
}

static inline unsigned long __lip_store_u32_data(uint8_t buf[static 4],
                                                 unsigned val)
{
    val = big_endian((uint32_t)val);
    memcpy(buf, &val, 4);
    return 4;
}

static inline unsigned long __lip_store_i32_data(uint8_t buf[static 4], int val)
{
    val = (int)big_endian((int32_t)val);
    memcpy(buf, &val, 4);
    return 4;
}

static inline unsigned long __lip_store_u64_data(uint8_t buf[static 8],
                                                 unsigned long val)
{
    val = big_endian((uint64_t)val);
    memcpy(buf, &val, 8);
    return 8;
}

static inline unsigned long __lip_store_i64_data(uint8_t buf[static 8],
                                                 long val)
{
    val = (long)big_endian((int64_t)val);
    memcpy(buf, &val, 8);
    return 8;
}

static inline unsigned long __lip_store_f32_data(uint8_t buf[static 4],
                                                 float val)
{
    union
    {
        float f;
        uint32_t u;
    } v;
    v.f = val;
    return __lip_store_u32_data(buf, v.u);
}

static inline unsigned long __lip_store_f64_data(uint8_t buf[static 8],
                                                 double val)
{
    union
    {
        double f;
        uint64_t u;
    } v;
    v.f = val;
    return __lip_store_u64_data(buf, v.u);
}

static inline unsigned long __lip_store_fix_str_body(uint8_t buf[static 1],
                                                     unsigned length,
                                                     char const val[static 1])
{
    memcpy(buf, val, length);
    return length;
}

static inline unsigned long __lip_store_str8_data(uint8_t buf[static 1],
                                                  unsigned length,
                                                  char const val[static 1])
{
    memcpy(buf, val, length);
    return length;
}

static inline unsigned long __lip_store_str16_data(uint8_t buf[static 1],
                                                   unsigned length,
                                                   char const val[static 1])
{
    memcpy(buf, val, length);
    return length;
}

static inline unsigned long __lip_store_str32_data(uint8_t buf[static 1],
                                                   unsigned length,
                                                   char const val[static 1])
{
    memcpy(buf, val, length);
    return length;
}

#endif
