#ifndef LIP_LOAD_BOOL_H
#define LIP_LOAD_BOOL_H

#include "format.h"
#include <stdbool.h>

static inline unsigned __lip_load_bool(uint8_t const buf[static 1], bool *val)
{
    *val = __lip_format(buf[0]) ^ LIP_FMT_FALSE;
    return 1;
}

#endif
