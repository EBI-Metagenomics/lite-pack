#ifndef LIP_STORE_BOOL
#define LIP_STORE_BOOL

#include "first_byte.h"
#include <stdbool.h>

static inline unsigned __lip_store_bool(unsigned char buf[static 1], bool val)
{
    if (val)
        buf[0] = __lip_first_byte(LIP_FMT_TRUE);
    else
        buf[0] = __lip_first_byte(LIP_FMT_FALSE);
    return 1;
}

#endif
