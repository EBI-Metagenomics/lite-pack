#ifndef LIP_PACK_MAP_H
#define LIP_PACK_MAP_H

#include "store_map.h"
#include <stdint.h>

static inline unsigned lip_pack_map_size(uint8_t buf[static 1], unsigned size)
{
    if (size <= 0xf)
        return __lip_store_fixmap(buf, (uint8_t)size);
    else if (size <= 0xffff)
        return __lip_store_map16(buf, (uint16_t)size);
    return __lip_store_map32(buf, (uint32_t)size);
}

#endif
