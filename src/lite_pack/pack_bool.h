#ifndef LITE_PACK_PACK_BOOL
#define LITE_PACK_PACK_BOOL

#include "lite_pack/store_bool.h"
#include <stdint.h>

static inline unsigned lip_pack_bool(unsigned char buf[], bool val)
{
    return __lip_store_bool(buf, val);
}

#endif
