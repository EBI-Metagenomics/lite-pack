#include "lite_pack/store_ext.h"
#include "first_byte.h"
#include "lite_pack/store_number.h"

unsigned __lip_store_fixext(unsigned char buf[], enum lip_format fmt,
                            uint8_t type)
{
    buf[0] = __lip_first_byte(fmt);
    return 1 + __lip_store_num8(buf + 1, __LIP_NUM8(type));
}

unsigned __lip_store_fixext_type(unsigned char buf[], enum lip_format fmt,
                                 uint8_t type)
{
    buf[0] = __lip_first_byte(fmt);
    return 1 + __lip_store_num8(buf + 1, __LIP_NUM8(type));
}

unsigned __lip_store_fixext1(unsigned char buf[], uint8_t type)
{
    return __lip_store_fixext(buf, LIP_FMT_FIXEXT_1, type);
}

unsigned __lip_store_fixext2(unsigned char buf[], uint8_t type)
{
    return __lip_store_fixext(buf, LIP_FMT_FIXEXT_2, type);
}

unsigned __lip_store_fixext4(unsigned char buf[], uint8_t type)
{
    return __lip_store_fixext(buf, LIP_FMT_FIXEXT_4, type);
}

unsigned __lip_store_fixext8(unsigned char buf[], uint8_t type)
{
    return __lip_store_fixext(buf, LIP_FMT_FIXEXT_8, type);
}

unsigned __lip_store_fixext16(unsigned char buf[], uint8_t type)
{
    return __lip_store_fixext(buf, LIP_FMT_FIXEXT_16, type);
}

unsigned __lip_store_ext8(unsigned char buf[], uint8_t size, uint8_t type)
{
    buf[0] = __lip_first_byte(LIP_FMT_EXT_8);
    unsigned sz = __lip_store_num8(buf + 1, __LIP_NUM8(size));
    return 1 + sz + __lip_store_num8(buf + 1 + sz, __LIP_NUM8(type));
}

unsigned __lip_store_ext16(unsigned char buf[], uint16_t size, uint8_t type)
{
    buf[0] = __lip_first_byte(LIP_FMT_EXT_16);
    unsigned sz = __lip_store_num16(buf + 1, __LIP_NUM16(size));
    return 1 + sz + __lip_store_num8(buf + 1 + sz, __LIP_NUM8(type));
}

unsigned __lip_store_ext32(unsigned char buf[], uint32_t size, uint8_t type)
{
    buf[0] = __lip_first_byte(LIP_FMT_EXT_32);
    unsigned sz = __lip_store_num32(buf + 1, __LIP_NUM32(size));
    return 1 + sz + __lip_store_num8(buf + 1 + sz, __LIP_NUM8(type));
}
