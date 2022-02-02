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

static inline void pack_true(uint8_t buf[static 1])
{
    buf[0] = first_byte(FMT_TRUE);
}

static inline void pack_false(uint8_t buf[static 1])
{
    buf[0] = first_byte(FMT_FALSE);
}

static inline void pack_bool(uint8_t buf[static 1], bool val)
{
    if (val)
        pack_true(buf);
    else
        pack_false(buf);
}

void pack_u8(uint8_t buf[static 1], unsigned val);
void pack_u16(uint8_t buf[static 1], unsigned val);
void pack_u32(uint8_t buf[static 1], unsigned val);
void pack_u64(uint8_t buf[static 1], unsigned long val);

#define pack_uint(buf, val)                                                    \
    _Generic((val), uint8_t                                                    \
             : pack_u8(buf, val), uint16_t                                     \
             : pack_u16(buf, val), uint32_t                                    \
             : pack_u32(buf, val), uint64_t                                    \
             : pack_u64(buf, val), unsigned long                               \
             : pack_u64(buf, val))

static inline void unpack_pfix_data(uint8_t buf[static 1]) {}

static inline void unpack_u8_data(uint8_t buf[static 1]) {}

static inline void unpack_u16_data(uint8_t buf[static 1])
{
    *((uint16_t *)buf) = big_to_host_endianness(*((uint16_t *)buf));
}

static inline void unpack_u32_data(uint8_t buf[static 1])
{
    *((uint32_t *)buf) = big_to_host_endianness(*((uint32_t *)buf));
}

static inline void unpack_u64_data(uint8_t buf[static 1])
{
    *((uint64_t *)buf) = big_to_host_endianness(*((uint64_t *)buf));
}

#endif
