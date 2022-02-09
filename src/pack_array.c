#include "pack_array.h"
#include "store_array.h"

unsigned lip_pack_array_size(unsigned char buf[], unsigned size)
{
    if (size <= 0xf)
        return __lip_store_fixarray(buf, (uint8_t)size);
    else if (size <= 0xffff)
        return __lip_store_array16(buf, (uint16_t)size);
    return __lip_store_array32(buf, (uint32_t)size);
}
