#include "lite_pack/unpack_map.h"
#include "lite_pack/format.h"
#include "lite_pack/load_number.h"

unsigned lip_unpack_map_size(unsigned char const buf[], unsigned *size)
{
    switch (lip_format(buf))
    {
    case LIP_FMT_FIXMAP:
        *size = (unsigned)__lip_format_fix_value(buf[0]);
        return 1;
    case LIP_FMT_MAP_16:
        *size = __lip_load_num16(buf + 1).u;
        return 3;
    case LIP_FMT_MAP_32:
        *size = __lip_load_num32(buf + 1).u;
        return 5;
    default:
        return 0;
    }
}
