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
    if (lip_format(buf) == LIP_FMT_FALSE || lip_format(buf) == LIP_FMT_TRUE)
        return __lip_load_bool(buf);
    return 0;
}

static inline float lip_unpack_float(uint8_t const buf[static 5])
{
    if (lip_format(buf) == LIP_FMT_FLOAT_32)
        return __lip_load_num32_body(buf + 1).f;
    return 0;
}

static inline double lip_unpack_double(uint8_t const buf[static 9])
{
    switch (lip_format(buf))
    {
    case LIP_FMT_FLOAT_64:
        return __lip_load_num64_body(buf + 1).d;
    case LIP_FMT_FLOAT_32:
        return __lip_load_num32_body(buf + 1).f;
    }
    return 0;
}

#endif
