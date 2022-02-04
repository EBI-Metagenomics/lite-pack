#ifndef LOAD_H
#define LOAD_H

#include "compiler.h"
#include "format.h"
#include "load_body.h"
#include "str.h"
#include <stdbool.h>
#include <string.h>

static inline bool __lip_load_bool(uint8_t const buf[static 1])
{
    return __lip_format(buf[0]) ^ LIP_FMT_FALSE;
}

static inline unsigned __lip_load_pfix_int(uint8_t const buf[static 1])
{
    return buf[0];
}

static inline int __lip_load_nfix_int(uint8_t const buf[static 1])
{
    return (int)buf[0];
}

static inline unsigned __lip_load_u8(uint8_t const buf[static 2])
{
    return buf[1];
}

static inline int __lip_load_i8(uint8_t const buf[static 2]) { return buf[1]; }

static inline unsigned __lip_load_u16(uint8_t const buf[static 3])
{
    return host_endian(*((uint16_t *)(buf + 1)));
}

static inline int __lip_load_i16(uint8_t const buf[static 3])
{
    return host_endian(*((int16_t *)(buf + 1)));
}

static inline unsigned __lip_load_u32(uint8_t const buf[static 5])
{
    return host_endian(*((uint32_t *)(buf + 1)));
}

static inline int __lip_load_i32(uint8_t const buf[static 5])
{
    return (int)host_endian(*((int32_t *)(buf + 1)));
}

static inline unsigned long __lip_load_u64(uint8_t const buf[static 9])
{
    return host_endian(*((uint64_t *)(buf + 1)));
}

static inline long __lip_load_i64(uint8_t const buf[static 9])
{
    return (long)host_endian(*((int64_t *)(buf + 1)));
}

static inline char *__lip_load_fix_str(uint8_t const buf[static 1],
                                       char str[static 1])
{
    return __lip_load_str_body(buf + 1, __lip_fix_str_length(buf), str);
}

static inline char *__lip_load_str8(uint8_t const buf[static 2],
                                    char str[static 1])
{
    return __lip_load_str_body(buf + 2, __lip_str8_length(buf), str);
}

static inline char *__lip_load_str16(uint8_t const buf[static 3],
                                     char str[static 1])
{
    return __lip_load_str_body(buf + 3, __lip_str16_length(buf), str);
}

static inline char *__lip_load_str32(uint8_t const buf[static 5],
                                     char str[static 1])
{
    return __lip_load_str_body(buf + 5, __lip_str32_length(buf), str);
}

static inline float __lip_load_f32(uint8_t const buf[static 5])
{
    return __lip_load_f32_body(buf + 1);
}

static inline double __lip_load_f64(uint8_t const buf[static 9])
{
    return __lip_load_f64_body(buf + 1);
}

#endif
