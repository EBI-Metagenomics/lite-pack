#include "lite_pack/unpack_bool.h"
#include "lite_pack/format.h"
#include "lite_pack/load_bool.h"

unsigned lip_unpack_bool(unsigned char const buf[], bool *val)
{
    if (lip_format(buf[0]) == LIP_FMT_FALSE ||
        lip_format(buf[0]) == LIP_FMT_TRUE)
        return __lip_load_bool(buf, val);
    return 0;
}
