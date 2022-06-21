#include "first_byte.h"
#include <stdbool.h>

unsigned __lip_store_bool(unsigned char buf[], bool val)
{
    if (val)
        buf[0] = __lip_first_byte(LIP_FMT_TRUE);
    else
        buf[0] = __lip_first_byte(LIP_FMT_FALSE);
    return 1;
}
