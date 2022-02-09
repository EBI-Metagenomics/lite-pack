#ifndef LIP_STORE_MAP_H
#define LIP_STORE_MAP_H

#include "compiler.h"
#include "first_byte.h"
#include "format.h"
#include "store_number.h"

static inline unsigned __lip_store_fixmap(uint8_t buf[static 1], uint8_t size)
{
    buf[0] = __lip_first_byte_fix(LIP_FMT_FIXMAP, size);
    return 1;
}

static inline unsigned __lip_store_map16(uint8_t buf[static 3], uint16_t size)
{
    buf[0] = __lip_first_byte(LIP_FMT_MAP_16);
    return lip_store_num16(buf + 1, __LIP_NUM16(size)) + 1;
}

static inline unsigned __lip_store_map32(uint8_t buf[static 5], uint32_t size)
{
    buf[0] = __lip_first_byte(LIP_FMT_MAP_32);
    return lip_store_num32(buf + 1, __LIP_NUM32(size)) + 1;
}

#endif
