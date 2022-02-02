#ifndef LITE_PACK_H
#define LITE_PACK_H

#include "compiler.h"
#include "first_byte.h"
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

#define TAG_PFIX 0x00
#define TAG_FALSE 0xc2
#define TAG_TRUE 0xc3
#define TAG_U8 0xcc
#define TAG_U16 0xcd
#define TAG_U32 0xce
#define TAG_U64 0xcf
#define TAG_I8 0xd0
#define TAG_I16 0xd1
#define TAG_I32 0xd2
#define TAG_I64 0xd3
#define TAG_NFIX 0xe0

#define TAG_PFIX_BITS 1
#define TAG_FALSE_BITS 8
#define TAG_TRUE_BITS 8
#define TAG_U8_BITS 8
#define TAG_U16_BITS 8
#define TAG_U32_BITS 8
#define TAG_U64_BITS 8
#define TAG_I8_BITS 8
#define TAG_I16_BITS 8
#define TAG_I32_BITS 8
#define TAG_I64_BITS 8
#define TAG_NFIX_BITS 3

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

void pack_u8(uint8_t buf[static 1], uint8_t val);
void pack_u16(uint8_t buf[static 1], uint16_t val);
void pack_u32(uint8_t buf[static 1], uint32_t val);

#define pack_uint(buf, val)                                                    \
    _Generic((val), uint8_t                                                    \
             : pack_u8(buf, val), uint16_t                                     \
             : pack_u16(buf, val), uint32_t                                    \
             : pack_u32(buf, val))

static inline void unpack_pfix_data(uint8_t buf[static 1]) {}

static inline void unpack_u8_data(uint8_t buf[static 1]) {}

static inline void unpack_u16_data(uint8_t buf[static 1])
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

#endif
