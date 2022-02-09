#include "pack_str.h"
#include "store_str.h"

unsigned lip_pack_str_size(unsigned char buf[], unsigned size)
{
    if (size <= 0x1f)
        return __lip_store_fixstr(buf, (uint8_t)size);
    else if (size <= 0xff)
        return __lip_store_str8(buf, (uint8_t)size);
    else if (size <= 0xffff)
        return __lip_store_str16(buf, (uint16_t)size);
    return __lip_store_str32(buf, size);
}

unsigned lip_pack_str_data(unsigned char buf[], unsigned size,
                           char const val[])
{
    memcpy(buf, val, size);
    return size;
}

#if 0
unsigned long lip_pack_str(unsigned char buf[], char const val[])
{
    unsigned length = (unsigned)strlen(val);
    unsigned long offset = lip_pack_str_size(buf, length);
    return offset + lip_pack_str_data(buf + offset, length, val);
}
#endif
