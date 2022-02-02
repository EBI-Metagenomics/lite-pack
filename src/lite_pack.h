#ifndef LITE_PACK_H
#define LITE_PACK_H

#include "compiler.h"
#include "first_byte.h"
#include "format.h"
#include "pack.h"
#include "unpack.h"
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

static inline int lip_format(uint8_t buf[static 1])
{
    return __lip_format(buf[0]);
}

static inline int lip_format_family(uint8_t buf[static 1])
{
    return __lip_format_family(buf[0]);
}

static inline void lip_pack_true(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(FMT_TRUE);
}

static inline void lip_pack_false(uint8_t buf[static 1])
{
    buf[0] = __lip_first_byte(FMT_FALSE);
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
             : __lip_pack_u8(buf, val), uint16_t                               \
             : __lip_pack_u16(buf, val), uint32_t                              \
             : __lip_pack_u32(buf, val), uint64_t                              \
             : __lip_pack_u64(buf, val), unsigned long                         \
             : __lip_pack_u64(buf, val))

#define lip_pack_float(buf, val)                                               \
    _Generic((val), float                                                      \
             : __lip_pack_f32(buf, val), double                                \
             : __lip_pack_f64(buf, val))

unsigned lip_unpack_uint(uint8_t buf[static 1]);

unsigned long lip_unpack_ulong(uint8_t buf[static 1]);

static inline float lip_unpack_float(uint8_t buf[static 1])
{
    if (__lip_format(buf[0]) == FMT_FLOAT_32) return __lip_unpack_f32(buf + 1);
    BUG();
}

static inline double lip_unpack_double(uint8_t buf[static 1])
{
    if (__lip_format(buf[0]) == FMT_FLOAT_64) return __lip_unpack_f64(buf + 1);
    BUG();
}

#endif
