#include "lite_pack/unpack_str.h"
#include "lite_pack/format.h"
#include "lite_pack/load_number.h"

unsigned lip_unpack_str_size(unsigned char const buf[], unsigned *size)
{
    switch (lip_format(buf[0]))
    {
    case LIP_FMT_FIXSTR:
        *size = (unsigned)__lip_format_fix_value(buf[0]);
        return 1;
    case LIP_FMT_STR_8:
        *size = __lip_load_num8(buf + 1).u;
        return 2;
    case LIP_FMT_STR_16:
        *size = __lip_load_num16(buf + 1).u;
        return 3;
    case LIP_FMT_STR_32:
        *size = __lip_load_num32(buf + 1).u;
        return 5;
    default:
        return 0;
    }
}

unsigned lip_unpack_str_data(unsigned char const buf[], unsigned size,
                             char str[])
{
    memcpy(str, buf, size);
    return size;
}
