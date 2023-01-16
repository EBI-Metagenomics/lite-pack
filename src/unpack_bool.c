#include "lip/unpack_bool.h"
#include "lip/format.h"
#include "lip/load_bool.h"

unsigned lip_unpack_bool(unsigned char const buf[], bool *val)
{
    if (lip_format(buf[0]) == LIP_FMT_FALSE ||
        lip_format(buf[0]) == LIP_FMT_TRUE)
        return lip_load_bool(buf, val);
    return 0;
}
