#ifndef UNPACK_H
#define UNPACK_H

#include "bug.h"
#include "compiler.h"
#include "format.h"

static inline void unpack_fix_uint_unsafe(uint8_t buf[static 1]) {}

static inline void unpack_u8_unsafe(uint8_t buf[static 1]) {}

static inline void unpack_u16_unsafe(uint8_t buf[static 1])
{
    *((uint16_t *)buf) = big_to_host_endian(*((uint16_t *)buf));
}

static inline void unpack_u32_unsafe(uint8_t buf[static 1])
{
    *((uint32_t *)buf) = big_to_host_endian(*((uint32_t *)buf));
}

static inline void unpack_u64_unsafe(uint8_t buf[static 1])
{
    *((uint64_t *)buf) = big_to_host_endian(*((uint64_t *)buf));
}

static inline unsigned unpack_fix_uint(uint8_t buf[static 1]) { return buf[0]; }

static inline unsigned unpack_u8(uint8_t buf[static 1]) { return buf[0]; }

static inline unsigned unpack_u16(uint8_t buf[static 1])
{
    return big_to_host_endian(*((uint16_t *)buf));
}

static inline unsigned unpack_u32(uint8_t buf[static 1])
{
    return big_to_host_endian(*((uint32_t *)buf));
}

static inline unsigned long unpack_u64(uint8_t buf[static 1])
{
    return big_to_host_endian(*((uint64_t *)buf));
}

float unpack_f32(uint8_t buf[static 1]);

double unpack_f64(uint8_t buf[static 1]);

#endif
