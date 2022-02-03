#ifndef STORE_DATA_H
#define STORE_DATA_H

#include "compiler.h"
#include <stdint.h>
#include <string.h>

static inline void __lip_store_u8_data(uint8_t buf[static 1], unsigned val)
{
    val = big_endian((uint8_t)val);
    memcpy(buf, &val, 1);
}

static inline void __lip_store_u16_data(uint8_t buf[static 2], unsigned val)
{
    val = big_endian((uint16_t)val);
    memcpy(buf, &val, 2);
}

static inline void __lip_store_u32_data(uint8_t buf[static 4], unsigned val)
{
    val = big_endian((uint32_t)val);
    memcpy(buf, &val, 4);
}

static inline void __lip_store_u64_data(uint8_t buf[static 8],
                                        unsigned long val)
{
    val = big_endian((uint64_t)val);
    memcpy(buf, &val, 8);
}

static inline void __lip_store_f32_data(uint8_t buf[static 4], float val)
{
    union
    {
        float f;
        uint32_t u;
    } v;
    v.f = val;
    __lip_store_u32_data(buf, v.u);
}

static inline void __lip_store_f64_data(uint8_t buf[static 8], double val)
{
    union
    {
        double f;
        uint64_t u;
    } v;
    v.f = val;
    __lip_store_u64_data(buf, v.u);
}

static inline void __lip_store_fix_str_data(uint8_t buf[static 1],
                                            unsigned length,
                                            char const val[static 1])
{
    memcpy(buf, val, length);
}

static inline void __lip_store_str8_data(uint8_t buf[static 1], unsigned length,
                                         char const val[static 1])
{
    memcpy(buf, val, length);
}

static inline void __lip_store_str16_data(uint8_t buf[static 1],
                                          unsigned length,
                                          char const val[static 1])
{
    memcpy(buf, val, length);
}

static inline void __lip_store_str32_data(uint8_t buf[static 1],
                                          unsigned length,
                                          char const val[static 1])
{
    memcpy(buf, val, length);
}

#endif
