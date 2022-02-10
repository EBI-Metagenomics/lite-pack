#include "pack_ext.h"
#include "store_ext.h"

unsigned lip_pack_ext_size_type(unsigned char buf[], unsigned size,
                                uint8_t type)
{
    if (size == 1) return __lip_store_fixext1(buf, type);
    if (size == 2) return __lip_store_fixext2(buf, type);
    if (size == 4) return __lip_store_fixext4(buf, type);
    if (size == 8) return __lip_store_fixext8(buf, type);

    if (size <= 0xffU) return __lip_store_ext8(buf, (uint8_t)size, type);
    if (size <= 0xffffU) return __lip_store_ext16(buf, (uint16_t)size, type);
    return __lip_store_ext32(buf, size, type);
}
