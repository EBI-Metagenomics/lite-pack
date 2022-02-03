#ifndef UNPACK_H
#define UNPACK_H

#include "bug.h"
#include "compiler.h"
#include "first_byte.h"
#include "format.h"
#include <string.h>

static inline unsigned __lip_unpack_fix_uint(uint8_t const buf[static 1])
{
    return buf[0];
}

static inline unsigned __lip_unpack_u8(uint8_t const buf[static 1])
{
    return buf[0];
}

static inline unsigned __lip_unpack_u16(uint8_t const buf[static 1])
{
    return host_endian(*((uint16_t *)buf));
}

static inline unsigned __lip_unpack_u32(uint8_t const buf[static 1])
{
    return host_endian(*((uint32_t *)buf));
}

static inline unsigned long __lip_unpack_u64(uint8_t const buf[static 1])
{
    return host_endian(*((uint64_t *)buf));
}

float __lip_unpack_f32(uint8_t const buf[static 1]);

double __lip_unpack_f64(uint8_t const buf[static 1]);

unsigned lip_unpack_uint(uint8_t const buf[static 1]);

unsigned long lip_unpack_ulong(uint8_t const buf[static 1]);

static inline float lip_unpack_float(uint8_t const buf[static 1])
{
    if (__lip_format(buf[0]) == FMT_FLOAT_32) return __lip_unpack_f32(buf + 1);
    BUG();
}

static inline double lip_unpack_double(uint8_t const buf[static 1])
{
    if (__lip_format(buf[0]) == FMT_FLOAT_64) return __lip_unpack_f64(buf + 1);
    BUG();
}

void lip_unpack_str(uint8_t const buf[static 1], char str[static 1]);

static inline void __lip_unpack_fix_str(uint8_t const buf[static 1],
                                        char str[static 1])
{
    int length = __lip_format_fix_value(buf[0]);
    memcpy(str, buf + 1, length);
    str[length] = 0;
}

#endif
