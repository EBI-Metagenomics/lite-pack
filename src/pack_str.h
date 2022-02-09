#ifndef LIP_PACK_STR_H
#define LIP_PACK_STR_H

#include "store_str.h"
#include <stdint.h>

static inline unsigned lip_pack_str_size(uint8_t buf[static 1], unsigned size)
{
    if (size <= 0x1f)
        return __lip_store_fixstr(buf, (uint8_t)size);
    else if (size <= 0xff)
        return __lip_store_str8(buf, (uint8_t)size);
    else if (size <= 0xffff)
        return __lip_store_str16(buf, (uint16_t)size);
    return __lip_store_str32(buf, size);
}

static inline unsigned lip_pack_str_data(uint8_t buf[static 1], unsigned size,
                                         char const val[static 1])
{
    memcpy(buf, val, size);
    return size;
}

static inline unsigned long lip_pack_str(uint8_t buf[static 2],
                                         char const val[static 1])
{
    unsigned length = (unsigned)strlen(val);
    unsigned long offset = lip_pack_str_size(buf, length);
    return offset + lip_pack_str_data(buf + offset, length, val);
}

#endif
