#ifndef UNPACK_H
#define UNPACK_H

#include "bug.h"
#include "compiler.h"
#include "first_byte.h"
#include "format.h"
#include "load.h"
#include <stdbool.h>

static inline bool lip_unpack_bool(uint8_t const buf[static 1])
{
    return __lip_load_bool(buf);
}

unsigned lip_unpack_uint(uint8_t const buf[static 1]);

unsigned long lip_unpack_ulong(uint8_t const buf[static 1]);

static inline float lip_unpack_float(uint8_t const buf[static 5])
{
    return __lip_load_num32_body(buf + 1).f;
}

static inline double lip_unpack_double(uint8_t const buf[static 9])
{
    return __lip_load_num64_body(buf + 1).d;
}

char *lip_unpack_str(uint8_t const buf[static 1], char str[static 1]);

unsigned lip_unpack_map_head(uint8_t const buf[static 1]);

#endif
