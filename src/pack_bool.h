#ifndef LIP_PACK_BOOL
#define LIP_PACK_BOOL

#include "store_bool.h"
#include <stdint.h>

static inline unsigned lip_pack_bool(uint8_t buf[static 1], bool val)
{
    return __lip_store_bool(buf, val);
}

#endif
