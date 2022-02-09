#include "unpack_array.h"
#include "format.h"
#include "load_number.h"

unsigned lip_unpack_array_size(unsigned char const buf[static 1], unsigned *size)
{
    switch (lip_format(buf))
    {
    case LIP_FMT_FIXARRAY:
        *size = (unsigned)__lip_format_fix_value(buf[0]);
        return 1;
    case LIP_FMT_ARRAY_16:
        *size = __lip_load_num16(buf + 1).u;
        return 3;
    case LIP_FMT_ARRAY_32:
        *size = __lip_load_num32(buf + 1).u;
        return 5;
    }
    return 0;
}
