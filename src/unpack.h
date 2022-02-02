#ifndef UNPACK_H
#define UNPACK_H

#include "bug.h"
#include "compiler.h"
#include "format.h"

static inline unsigned __lip_unpack_fix_uint(uint8_t buf[static 1])
{
    return buf[0];
}

static inline unsigned __lip_unpack_u8(uint8_t buf[static 1]) { return buf[0]; }

static inline unsigned __lip_unpack_u16(uint8_t buf[static 1])
{
    return big_to_host_endian(*((uint16_t *)buf));
}

static inline unsigned __lip_unpack_u32(uint8_t buf[static 1])
{
    return big_to_host_endian(*((uint32_t *)buf));
}

static inline unsigned long __lip_unpack_u64(uint8_t buf[static 1])
{
    return big_to_host_endian(*((uint64_t *)buf));
}

float __lip_unpack_f32(uint8_t buf[static 1]);

double __lip_unpack_f64(uint8_t buf[static 1]);

#endif
