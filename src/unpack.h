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

static inline unsigned __lip_unpack_u16(uint8_t const buf[static 2])
{
    return host_endian(*((uint16_t *)buf));
}

static inline unsigned __lip_unpack_u32(uint8_t const buf[static 4])
{
    return host_endian(*((uint32_t *)buf));
}

static inline unsigned long __lip_unpack_u64(uint8_t const buf[static 8])
{
    return host_endian(*((uint64_t *)buf));
}

float __lip_unpack_f32_data(uint8_t const buf[static 4]);

double __lip_unpack_f64_data(uint8_t const buf[static 8]);

unsigned lip_unpack_uint(uint8_t const buf[static 1]);

unsigned long lip_unpack_ulong(uint8_t const buf[static 1]);

static inline float lip_unpack_float(uint8_t const buf[static 5])
{
    return __lip_unpack_f32_data(buf + 1);
}

static inline double lip_unpack_double(uint8_t const buf[static 9])
{
    return __lip_unpack_f64_data(buf + 1);
}

char *lip_unpack_str(uint8_t const buf[static 1], char str[static 1]);

static inline void __lip_unpack_fix_str(uint8_t const buf[static 2],
                                        char str[static 1])
{
    unsigned length = (unsigned)__lip_format_fix_value(buf[0]);
    memcpy(str, buf + 1, length);
    str[length] = 0;
}

static inline void __lip_unpack_str8(uint8_t const buf[static 2],
                                     char str[static 1])
{
    unsigned length = (unsigned)buf[0];
    memcpy(str, buf + 1, length);
    str[length] = 0;
}

static inline void __lip_unpack_str16(uint8_t const buf[static 3],
                                      char str[static 1])
{
    unsigned length = host_endian(*((uint16_t *)buf));
    memcpy(str, buf + 2, length);
    str[length] = 0;
}

static inline void __lip_unpack_str32(uint8_t const buf[static 5],
                                      char str[static 1])
{
    unsigned length = host_endian(*((uint32_t *)buf));
    memcpy(str, buf + 4, length);
    str[length] = 0;
}

#endif
