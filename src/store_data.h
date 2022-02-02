#ifndef STORE_DATA_H
#define STORE_DATA_H

#include "compiler.h"
#include <stdint.h>
#include <string.h>

static inline void store_u8_data(uint8_t buf[static 1], unsigned val)
{
    val = host_to_big_endian((uint8_t)val);
    memcpy(buf, &val, 1);
}

static inline void store_u16_data(uint8_t buf[static 1], unsigned val)
{
    val = host_to_big_endian((uint16_t)val);
    memcpy(buf, &val, 4);
}

static inline void store_u32_data(uint8_t buf[static 1], unsigned val)
{
    val = host_to_big_endian((uint32_t)val);
    memcpy(buf, &val, 4);
}

static inline void store_u64_data(uint8_t buf[static 1], unsigned long val)
{
    val = host_to_big_endian((uint64_t)val);
    memcpy(buf, &val, 8);
}

static inline void store_f32_data(uint8_t buf[static 1], float val)
{
    union
    {
        float f;
        uint32_t u;
    } v;
    v.f = val;
    store_u32_data(buf, v.u);
}

static inline void store_f64_data(uint8_t buf[static 1], double val)
{
    union
    {
        double f;
        uint64_t u;
    } v;
    v.f = val;
    store_u64_data(buf, v.u);
}

#endif
