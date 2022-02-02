#ifndef LITE_PACK_H
#define LITE_PACK_H

#include "compiler.h"
#include "first_byte.h"
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

void pack_u8(uint8_t buf[static 1], unsigned val);
void pack_u16(uint8_t buf[static 1], unsigned val);
void pack_u32(uint8_t buf[static 1], unsigned val);
void pack_u64(uint8_t buf[static 1], unsigned long val);

#define lip_pack_int(buf, val)                                                 \
    _Generic((val), uint8_t                                                    \
             : pack_u8(buf, val), uint16_t                                     \
             : pack_u16(buf, val), uint32_t                                    \
             : pack_u32(buf, val), uint64_t                                    \
             : pack_u64(buf, val), unsigned long                               \
             : pack_u64(buf, val))

static inline void unpack_fix_uint(uint8_t buf[static 1]) {}

static inline void unpack_u8(uint8_t buf[static 1]) {}

static inline void unpack_u16(uint8_t buf[static 1])
{
    *((uint16_t *)buf) = big_to_host_endianness(*((uint16_t *)buf));
}

static inline void unpack_u32(uint8_t buf[static 1])
{
    *((uint32_t *)buf) = big_to_host_endianness(*((uint32_t *)buf));
}

static inline void unpack_u64(uint8_t buf[static 1])
{
    *((uint64_t *)buf) = big_to_host_endianness(*((uint64_t *)buf));
}

static inline unsigned lip_unpack_uint(uint8_t buf[static 1])
{
    if (lip_format(buf) == FMT_POSITIVE_FIXINT)
    {
        unpack_fix_uint(buf);
        return (uint8_t)buf[0];
    }
    else if (lip_format(buf) == FMT_UINT_8)
    {
        unpack_u8(buf);
        return (uint8_t)buf[1];
    }
    else if (lip_format(buf) == FMT_UINT_16)
    {
        unpack_u16(buf + 1);
        return *((uint16_t *)(buf + 1));
    }
    else if (lip_format(buf) == FMT_UINT_32)
    {
        unpack_u32(buf + 1);
        return *((uint32_t *)(buf + 1));
    }
    BUG();
}

#endif
