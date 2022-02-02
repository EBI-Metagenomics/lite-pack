#include "lite_pack.h"
#include "unpack.h"

unsigned lip_unpack_uint(uint8_t buf[static 1])
{
    if (lip_format(buf) == FMT_POSITIVE_FIXINT)
    {
        return __lip_unpack_fix_uint(buf);
    }
    else if (lip_format(buf) == FMT_UINT_8)
    {
        return __lip_unpack_u8(buf + 1);
    }
    else if (lip_format(buf) == FMT_UINT_16)
    {
        return __lip_unpack_u16(buf + 1);
    }
    else if (lip_format(buf) == FMT_UINT_32)
    {
        return __lip_unpack_u32(buf + 1);
    }
    BUG();
}

unsigned long lip_unpack_ulong(uint8_t buf[static 1])
{
    if (lip_format(buf) == FMT_POSITIVE_FIXINT)
    {
        return __lip_unpack_fix_uint(buf);
    }
    else if (lip_format(buf) == FMT_UINT_8)
    {
        return __lip_unpack_u8(buf + 1);
    }
    else if (lip_format(buf) == FMT_UINT_16)
    {
        return __lip_unpack_u16(buf + 1);
    }
    else if (lip_format(buf) == FMT_UINT_32)
    {
        return __lip_unpack_u32(buf + 1);
    }
    else if (lip_format(buf) == FMT_UINT_64)
    {
        return __lip_unpack_u64(buf + 1);
    }
    BUG();
}
