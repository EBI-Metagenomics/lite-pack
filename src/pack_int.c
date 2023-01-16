#include "lip/pack_int.h"

/* SIGNED INTEGER */

unsigned lip_pack_i8(unsigned char buf[], int val)
{
    if (val >= 0) return lip_pack_u8(buf, (unsigned)val);
    if (val >= -32) return lip_store_negative_fixint(buf, (int8_t)val);
    return lip_store_int8(buf, (int8_t)val);
}

unsigned lip_pack_i16(unsigned char buf[], int val)
{
    if (val >= 0) return lip_pack_u16(buf, (unsigned)val);
    if (val >= -32) return lip_store_negative_fixint(buf, (int8_t)val);
    if (val >= INT8_MIN) return lip_store_int8(buf, (int8_t)val);
    return lip_store_int16(buf, (int16_t)val);
}

unsigned lip_pack_i32(unsigned char buf[], int val)
{
    if (val >= 0) return lip_pack_u32(buf, (unsigned)val);
    if (val >= -32) return lip_store_negative_fixint(buf, (int8_t)val);
    if (val >= INT8_MIN) return lip_store_int8(buf, (int8_t)val);
    if (val >= INT16_MIN) return lip_store_int16(buf, (int16_t)val);
    return lip_store_int32(buf, (int32_t)val);
}

unsigned lip_pack_i64(unsigned char buf[], long val)
{
    if (val >= 0) return lip_pack_u64(buf, (unsigned long)val);
    if (val >= -32) return lip_store_negative_fixint(buf, (int8_t)val);
    if (val >= INT8_MIN) return lip_store_int8(buf, (int8_t)val);
    if (val >= INT16_MIN) return lip_store_int16(buf, (int16_t)val);
    if (val >= INT32_MIN) return lip_store_int32(buf, (int32_t)val);
    return lip_store_int64(buf, (int64_t)val);
}

/* UNSIGNED INTEGER */

unsigned lip_pack_u8(unsigned char buf[], unsigned val)
{
    if (val <= 0x7fU) return lip_store_positive_fixint(buf, (uint8_t)val);
    return lip_store_uint8(buf, (uint8_t)val);
}

unsigned lip_pack_u16(unsigned char buf[], unsigned val)
{
    if (val <= 0xffU) return lip_pack_u8(buf, val);
    return lip_store_uint16(buf, (uint16_t)val);
}

unsigned lip_pack_u32(unsigned char buf[], unsigned val)
{
    if (val <= 0xffU)
        return lip_pack_u8(buf, val);
    else if (val <= 0xffffU)
        return lip_pack_u16(buf, val);
    return lip_store_uint32(buf, (uint32_t)val);
}

unsigned lip_pack_u64(unsigned char buf[], unsigned long val)
{
    if (val <= 0xffUL)
        return lip_pack_u8(buf, (unsigned)val);
    else if (val <= 0xffffUL)
        return lip_pack_u16(buf, (unsigned)val);
    else if (val <= 0xffffffffUL)
        return lip_pack_u32(buf, (unsigned)val);
    return lip_store_uint64(buf, (uint64_t)val);
}
