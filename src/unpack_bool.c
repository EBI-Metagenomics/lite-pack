#include "unpack_bool.h"
#include "format.h"
#include "load_bool.h"

unsigned lip_unpack_bool(unsigned char const buf[], bool *val)
{
    if (lip_format(buf) == LIP_FMT_FALSE || lip_format(buf) == LIP_FMT_TRUE)
        return __lip_load_bool(buf, val);
    return 0;
}
