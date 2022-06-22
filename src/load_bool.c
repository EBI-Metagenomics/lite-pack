#ifndef LITE_PACK_LOAD_BOOL_H
#define LITE_PACK_LOAD_BOOL_H

#include "lite_pack/format.h"
#include <stdbool.h>

unsigned lip_load_bool(unsigned char const buf[], bool *val)
{
    *val = lip_format(buf[0]) ^ LIP_FMT_FALSE;
    return 1;
}

#endif
