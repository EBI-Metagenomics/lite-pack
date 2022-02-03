#ifndef LOAD_H
#define LOAD_H

#include "compiler.h"
#include "format.h"
#include <string.h>

static inline unsigned __lip_load_pfix_int(uint8_t const buf[static 1])
{
    return buf[0];
}

static inline unsigned __lip_load_u8(uint8_t const buf[static 2])
{
    return buf[1];
}

static inline unsigned __lip_load_u16(uint8_t const buf[static 3])
{
    return host_endian(*((uint16_t *)(buf + 1)));
}

static inline unsigned __lip_load_u32(uint8_t const buf[static 5])
{
    return host_endian(*((uint32_t *)(buf + 1)));
}

static inline unsigned long __lip_load_u64(uint8_t const buf[static 9])
{
    return host_endian(*((uint64_t *)(buf + 1)));
}

static inline void __lip_load_fix_str(uint8_t const buf[static 1],
                                      char str[static 1])
{
    unsigned length = (unsigned)__lip_format_fix_value(buf[0]);
    memcpy(str, buf + 1, length);
    str[length] = 0;
}

static inline void __lip_load_str8(uint8_t const buf[static 2],
                                   char str[static 1])
{
    unsigned length = (unsigned)buf[1];
    memcpy(str, buf + 2, length);
    str[length] = 0;
}

static inline void __lip_load_str16(uint8_t const buf[static 3],
                                    char str[static 1])
{
    unsigned length = host_endian(*((uint16_t *)(buf + 1)));
    memcpy(str, buf + 3, length);
    str[length] = 0;
}

static inline void __lip_load_str32(uint8_t const buf[static 5],
                                    char str[static 1])
{
    unsigned length = host_endian(*((uint32_t *)(buf + 1)));
    memcpy(str, buf + 5, length);
    str[length] = 0;
}

float __lip_load_f32_data(uint8_t const buf[static 4]);
double __lip_load_f64_data(uint8_t const buf[static 8]);

static inline float __lip_load_f32(uint8_t const buf[static 5])
{
    return __lip_load_f32_data(buf + 1);
}

static inline double __lip_load_f64(uint8_t const buf[static 9])
{
    return __lip_load_f64_data(buf + 1);
}

#endif
