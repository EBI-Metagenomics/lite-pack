#ifndef LIP_LOAD_BOOL_H
#define LIP_LOAD_BOOL_H

#include "lip/format.h"
#include <stdbool.h>

unsigned lip_load_bool(unsigned char const buf[], bool *val)
{
    *val = lip_format(buf[0]) ^ LIP_FMT_FALSE;
    return 1;
}

#endif
