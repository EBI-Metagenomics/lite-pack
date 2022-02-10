#ifndef LIP_STORE_ARRAY_H
#define LIP_STORE_ARRAY_H

#include "lite_pack/first_byte.h"
#include "lite_pack/store_number.h"

static inline unsigned __lip_store_fixarray(unsigned char buf[], uint8_t size)
{
    buf[0] = __lip_first_byte_fix(LIP_FMT_FIXARRAY, size);
    return 1;
}

static inline unsigned __lip_store_array16(unsigned char buf[], uint16_t size)
{
    buf[0] = __lip_first_byte(LIP_FMT_ARRAY_16);
    return __lip_store_num16(buf + 1, __LIP_NUM16(size)) + 1;
}

static inline unsigned __lip_store_array32(unsigned char buf[], uint32_t size)
{
    buf[0] = __lip_first_byte(LIP_FMT_ARRAY_32);
    return __lip_store_num32(buf + 1, __LIP_NUM32(size)) + 1;
}

#endif
