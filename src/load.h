#ifndef LOAD_H
#define LOAD_H

#include "compiler.h"
#include "format.h"
#include "load_body.h"
#include <stdbool.h>
#include <string.h>

static inline unsigned __lip_load_bool(uint8_t const buf[static 1], bool *val)
{
    *val = __lip_format(buf[0]) ^ LIP_FMT_FALSE;
    return 1;
}

static inline union num8 __lip_load_num8(uint8_t const buf[static 1])
{
    union num8 num;
    memcpy(num.c, buf, sizeof(num));
    num.u = big_endian(num.u);
    return num;
}

static inline union num16 __lip_load_num16(uint8_t const buf[static 1])
{
    union num16 num;
    memcpy(num.c, buf, sizeof(num));
    num.u = big_endian(num.u);
    return num;
}

static inline union num32 __lip_load_num32(uint8_t const buf[static 1])
{
    union num32 num;
    memcpy(num.c, buf, sizeof(num));
    num.u = big_endian(num.u);
    return num;
}

static inline union num64 __lip_load_num64(uint8_t const buf[static 1])
{
    union num64 num;
    memcpy(num.c, buf, sizeof(num));
    num.u = big_endian(num.u);
    return num;
}

#if 0
static inline unsigned __lip_load_fix_str(uint8_t const buf[static 1],
                                          char str[static 1])
{
    return __lip_load_str_body(buf + 1, __lip_format_fix_value((uint8_t)buf[0]),
                               str);
}

static inline unsigned __lip_load_str8(uint8_t const buf[static 2],
                                       char str[static 1])
{
    return __lip_load_str_body(buf + 2, (unsigned)buf[1], str);
}

static inline unsigned __lip_load_str16(uint8_t const buf[static 3],
                                        char str[static 1])
{
    return __lip_load_str_body(buf + 3, __lip_str16_size(buf), str);
}

static inline unsigned __lip_load_str32(uint8_t const buf[static 5],
                                        char str[static 1])
{
    return __lip_load_str_body(buf + 5, __lip_str32_size(buf), str);
}
#endif

#endif
