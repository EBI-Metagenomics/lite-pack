#ifndef STORE_H
#define STORE_H

#include "compiler.h"
#include "first_byte.h"
#include "format.h"
#include "store_data.h"

static inline void __lip_store_pfix(uint8_t buf[static 1], uint8_t val)
{
    buf[0] = val;
}

static inline void __lip_store_u8(uint8_t buf[static 1], unsigned val)
{
    buf[0] = __lip_first_byte(FMT_UINT_8);
    store_u8_data(buf + 1, val);
}

static inline void __lip_store_u16(uint8_t buf[static 1], unsigned val)
{
    buf[0] = __lip_first_byte(FMT_UINT_16);
    store_u16_data(buf + 1, val);
}

static inline void __lip_store_u32(uint8_t buf[static 1], unsigned val)
{
    buf[0] = __lip_first_byte(FMT_UINT_32);
    store_u32_data(buf + 1, val);
}

static inline void __lip_store_u64(uint8_t buf[static 1], unsigned long val)
{
    buf[0] = __lip_first_byte(FMT_UINT_64);
    store_u64_data(buf + 1, val);
}

static inline void __lip_store_f32(uint8_t buf[static 1], float val)
{
    CHECK_FLOAT_ORDER();
    buf[0] = __lip_first_byte(FMT_FLOAT_32);
    store_f32_data(buf + 1, val);
}

static inline void __lip_store_f64(uint8_t buf[static 1], double val)
{
    CHECK_FLOAT_ORDER();
    buf[0] = __lip_first_byte(FMT_FLOAT_64);
    store_f64_data(buf + 1, val);
}

#endif
