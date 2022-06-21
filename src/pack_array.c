#include "lite_pack/pack_array.h"
#include "first_byte.h"
#include "lite_pack/store_number.h"

static inline unsigned __lip_store_fixarray(unsigned char buf[], uint8_t size)
{
    buf[0] = __lip_first_byte_fix(LIP_FMT_FIXARRAY, size);
    return 1;
}

static inline unsigned __lip_store_array16(unsigned char buf[], uint16_t size)
{
    buf[0] = __lip_first_byte(LIP_FMT_ARRAY_16);
    return __lip_store_num16(buf + 1, __LIP_NUM16(size)) + 1;
}

static inline unsigned __lip_store_array32(unsigned char buf[], uint32_t size)
{
    buf[0] = __lip_first_byte(LIP_FMT_ARRAY_32);
    return __lip_store_num32(buf + 1, __LIP_NUM32(size)) + 1;
}

unsigned lip_pack_array_size(unsigned char buf[], unsigned size)
{
    if (size <= 0xf)
        return __lip_store_fixarray(buf, (uint8_t)size);
    else if (size <= 0xffff)
        return __lip_store_array16(buf, (uint16_t)size);
    return __lip_store_array32(buf, (uint32_t)size);
}
