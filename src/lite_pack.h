#ifndef LITE_PACK_H
#define LITE_PACK_H

#include "compiler.h"
#include "first_byte.h"
#include "format.h"
#include "unpack.h"
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

static inline int lip_format(uint8_t buf[static 1])
{
    return format_parse(buf[0]);
}

static inline void lip_pack_true(uint8_t buf[static 1])
{
    buf[0] = first_byte(FMT_TRUE);
}

static inline void lip_pack_false(uint8_t buf[static 1])
{
    buf[0] = first_byte(FMT_FALSE);
}

static inline void lip_pack_bool(uint8_t buf[static 1], bool val)
{
    if (val)
        lip_pack_true(buf);
    else
        lip_pack_false(buf);
}

#define lip_pack_int(buf, val)                                                 \
    _Generic((val), uint8_t                                                    \
             : pack_u8(buf, val), uint16_t                                     \
             : pack_u16(buf, val), uint32_t                                    \
             : pack_u32(buf, val), uint64_t                                    \
             : pack_u64(buf, val), unsigned long                               \
             : pack_u64(buf, val))

#define lip_pack_float(buf, val)                                               \
    _Generic((val), float : pack_f32(buf, val), double : pack_f64(buf, val))

unsigned lip_unpack_uint(uint8_t buf[static 1]);

unsigned long lip_unpack_ulong(uint8_t buf[static 1]);

static inline float lip_unpack_float(uint8_t buf[static 1])
{
    if (format_parse(buf[0]) == FMT_FLOAT_32) return unpack_f32(buf + 1);
    BUG();
}

static inline double lip_unpack_double(uint8_t buf[static 1])
{
    if (format_parse(buf[0]) == FMT_FLOAT_64) return unpack_f64(buf + 1);
    BUG();
}

unsigned lip_unpack_uint_unsafe(uint8_t buf[static 1]);

#endif
