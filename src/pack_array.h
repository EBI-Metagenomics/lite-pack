#ifndef LIP_PACK_ARRAY_H
#define LIP_PACK_ARRAY_H

#include "store_array.h"
#include <stdint.h>

static inline unsigned lip_pack_array_size(uint8_t buf[static 1], unsigned size)
{
    if (size <= 0xf)
        return __lip_store_fixarray(buf, (uint8_t)size);
    else if (size <= 0xffff)
        return __lip_store_array16(buf, (uint16_t)size);
    return __lip_store_array32(buf, (uint32_t)size);
}

#endif
