#ifndef STORE_H
#define STORE_H

#include "compiler.h"
#include "first_byte.h"
#include "format.h"
#include <string.h>

static inline void store_pfix(uint8_t buf[static 1], uint8_t val)
{
    buf[0] = val;
}

static inline void store_u8(uint8_t buf[static 1], unsigned val)
{
    buf[0] = first_byte(FMT_UINT_8);
    buf[1] = (uint8_t)val;
}

static inline void store_u16(uint8_t buf[static 1], unsigned val)
{
    buf[0] = first_byte(FMT_UINT_16);
    val = host_to_big_endianness((uint16_t)val);
    memcpy(buf + 1, &val, 2);
}

static inline void store_u32(uint8_t buf[static 1], unsigned val)
{
    buf[0] = first_byte(FMT_UINT_32);
    val = host_to_big_endianness((uint32_t)val);
    memcpy(buf + 1, &val, 4);
}

static inline void store_u64(uint8_t buf[static 1], uint64_t val)
{
    buf[0] = first_byte(FMT_UINT_64);
    val = host_to_big_endianness(val);
    memcpy(buf + 1, &val, 8);
}

#endif
