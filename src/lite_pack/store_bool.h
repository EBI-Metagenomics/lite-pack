#ifndef LITE_PACK_STORE_BOOL
#define LITE_PACK_STORE_BOOL

#include "lite_pack/first_byte.h"
#include <stdbool.h>

static inline unsigned __lip_store_bool(unsigned char buf[], bool val)
{
    if (val)
        buf[0] = __lip_first_byte(LIP_FMT_TRUE);
    else
        buf[0] = __lip_first_byte(LIP_FMT_FALSE);
    return 1;
}

#endif
