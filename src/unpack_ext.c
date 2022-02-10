#include "unpack_ext.h"
#include "compiler.h"
#include "format.h"
#include "load_ext.h"

unsigned lip_unpack_ext_size_type(unsigned char const buf[], unsigned *size,
                                  uint8_t *type)
{
    enum lip_format fmt = lip_format(buf);
    *size = 1;
    switch (fmt)
    {
    case LIP_FMT_FIXEXT_16:
        *size <<= 1;
        fallthrough;
    case LIP_FMT_FIXEXT_8:
        *size <<= 1;
        fallthrough;
    case LIP_FMT_FIXEXT_4:
        *size <<= 1;
        fallthrough;
    case LIP_FMT_FIXEXT_2:
        *size <<= 1;
        fallthrough;
    case LIP_FMT_FIXEXT_1:
        return 1 + __lip_load_fixext(buf + 1, type);
    case LIP_FMT_EXT_8:
        return 1 + __lip_load_ext8(buf + 1, size, type);
    case LIP_FMT_EXT_16:
        return 1 + __lip_load_ext16(buf + 1, size, type);
    case LIP_FMT_EXT_32:
        return 1 + __lip_load_ext32(buf + 1, size, type);
    default:
        return 0;
    }
}
