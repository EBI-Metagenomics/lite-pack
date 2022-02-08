#ifndef LOAD_H
#define LOAD_H

#include "compiler.h"
#include "format.h"
#include "load_body.h"
#include "str.h"
#include <stdbool.h>
#include <string.h>

static inline unsigned __lip_load_bool(uint8_t const buf[static 1], bool *val)
{
    *val = __lip_format(buf[0]) ^ LIP_FMT_FALSE;
    return 1;
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

#endif
