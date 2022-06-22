#include "first_byte.h"
#include "lite_pack/store_number.h"

unsigned lip_store_fixmap(unsigned char buf[], uint8_t size)
{
    buf[0] = __lip_first_byte_fix(LIP_FMT_FIXMAP, size);
    return 1;
}

unsigned lip_store_map16(unsigned char buf[], uint16_t size)
{
    buf[0] = __lip_first_byte(LIP_FMT_MAP_16);
    return __lip_store_num16(buf + 1, __LIP_NUM16(size)) + 1;
}

unsigned lip_store_map32(unsigned char buf[], uint32_t size)
{
    buf[0] = __lip_first_byte(LIP_FMT_MAP_32);
    return __lip_store_num32(buf + 1, __LIP_NUM32(size)) + 1;
}
