#ifndef LIP_STORE_STR_H
#define LIP_STORE_STR_H

#include "compiler.h"
#include "first_byte.h"
#include "format.h"
#include "store_number.h"

static inline unsigned __lip_store_fixstr(uint8_t buf[static 1], uint8_t size)
{
    buf[0] = __lip_first_byte_fix(LIP_FMT_FIXSTR, size);
    return 1;
}

static inline unsigned __lip_store_str8(uint8_t buf[static 2], uint8_t size)
{
    buf[0] = __lip_first_byte(LIP_FMT_STR_8);
    return lip_store_num8(buf + 1, NUM8(size)) + 1;
}

static inline unsigned __lip_store_str16(uint8_t buf[static 3], uint16_t size)
{
    buf[0] = __lip_first_byte(LIP_FMT_STR_16);
    return lip_store_num16(buf + 1, NUM16(size)) + 1;
}

static inline unsigned __lip_store_str32(uint8_t buf[static 5], uint32_t size)
{
    buf[0] = __lip_first_byte(LIP_FMT_STR_32);
    return lip_store_num32(buf + 1, NUM32(size)) + 1;
}

#endif
