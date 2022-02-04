#ifndef LOAD_BODY_H
#define LOAD_BODY_H

#include "compiler.h"
#include <stdint.h>
#include <string.h>

static inline char *__lip_load_str_body(uint8_t const buf[static 1],
                                        unsigned length, char str[static 1])
{
    memcpy(str, buf, length);
    str[length] = 0;
    return str;
}

static inline float __lip_load_f32_body(uint8_t const buf[static 4])
{
    union
    {
        float f;
        uint32_t u;
    } v;
    v.u = host_endian(*((uint32_t *)buf));
    return v.f;
}

static inline double __lip_load_f64_body(uint8_t const buf[static 8])
{
    union
    {
        double f;
        uint64_t u;
    } v;
    v.u = host_endian(*((uint64_t *)buf));
    return v.f;
}

#endif
