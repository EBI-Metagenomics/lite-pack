#ifndef LOAD_BODY_H
#define LOAD_BODY_H

#include "compiler.h"
#include <stdint.h>
#include <string.h>

static inline union num8 __lip_load_num8_body(uint8_t const buf[static 1])
{
    union num8 num;
    memcpy(num.c, buf, 1);
    num.u = big_endian(num.u);
    return num;
}

static inline union num16 __lip_load_num16_body(uint8_t const buf[static 2])
{
    union num16 num;
    memcpy(num.c, buf, 2);
    num.u = big_endian(num.u);
    return num;
}

static inline union num32 __lip_load_num32_body(uint8_t const buf[static 4])
{
    union num32 num;
    memcpy(num.c, buf, 4);
    num.u = big_endian(num.u);
    return num;
}

static inline union num64 __lip_load_num64_body(uint8_t const buf[static 8])
{
    union num64 num;
    memcpy(num.c, buf, 8);
    num.u = big_endian(num.u);
    return num;
}

static inline char *__lip_load_str_body(uint8_t const buf[static 1],
                                        unsigned length, char str[static 1])
{
    memcpy(str, buf, length);
    str[length] = 0;
    return str;
}

#endif
