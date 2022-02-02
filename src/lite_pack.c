#include "lite_pack.h"
#include "unpack.h"

unsigned lip_unpack_uint(uint8_t buf[static 1])
{
    if (lip_format(buf) == FMT_POSITIVE_FIXINT)
    {
        return unpack_fix_uint(buf);
    }
    else if (lip_format(buf) == FMT_UINT_8)
    {
        return unpack_u8(buf + 1);
    }
    else if (lip_format(buf) == FMT_UINT_16)
    {
        return unpack_u16(buf + 1);
    }
    else if (lip_format(buf) == FMT_UINT_32)
    {
        return unpack_u32(buf + 1);
    }
    BUG();
}

unsigned long lip_unpack_ulong(uint8_t buf[static 1])
{
    if (lip_format(buf) == FMT_POSITIVE_FIXINT)
    {
        return unpack_fix_uint(buf);
    }
    else if (lip_format(buf) == FMT_UINT_8)
    {
        return unpack_u8(buf + 1);
    }
    else if (lip_format(buf) == FMT_UINT_16)
    {
        return unpack_u16(buf + 1);
    }
    else if (lip_format(buf) == FMT_UINT_32)
    {
        return unpack_u32(buf + 1);
    }
    else if (lip_format(buf) == FMT_UINT_64)
    {
        return unpack_u64(buf + 1);
    }
    BUG();
}

unsigned lip_unpack_uint_unsafe(uint8_t buf[static 1])
{
    if (lip_format(buf) == FMT_POSITIVE_FIXINT)
    {
        unpack_fix_uint_unsafe(buf);
        return (uint8_t)buf[0];
    }
    else if (lip_format(buf) == FMT_UINT_8)
    {
        unpack_u8_unsafe(buf);
        return (uint8_t)buf[1];
    }
    else if (lip_format(buf) == FMT_UINT_16)
    {
        unpack_u16_unsafe(buf + 1);
        return *((uint16_t *)(buf + 1));
    }
    else if (lip_format(buf) == FMT_UINT_32)
    {
        unpack_u32_unsafe(buf + 1);
        return *((uint32_t *)(buf + 1));
    }
    BUG();
}
