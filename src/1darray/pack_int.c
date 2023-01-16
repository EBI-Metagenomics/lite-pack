#include "1darray/pack_int.h"
#include "lip/store_int.h"

void pack_1darray_i8_data(unsigned char buf[], unsigned size,
                          int8_t const arr[])
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_i8(buf, arr[i]);
}

void pack_1darray_i16_data(unsigned char buf[], unsigned size,
                           int16_t const arr[])
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_i16(buf, arr[i]);
}

void pack_1darray_i32_data(unsigned char buf[], unsigned size,
                           int32_t const arr[])
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_i32(buf, arr[i]);
}

void pack_1darray_i64_data(unsigned char buf[], unsigned size,
                           int64_t const arr[])
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_i64(buf, arr[i]);
}

void pack_1darray_u8_data(unsigned char buf[], unsigned size,
                          uint8_t const arr[])
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_u8(buf, arr[i]);
}

void pack_1darray_u16_data(unsigned char buf[], unsigned size,
                           uint16_t const arr[])
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_u16(buf, arr[i]);
}

void pack_1darray_u32_data(unsigned char buf[], unsigned size,
                           uint32_t const arr[])
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_u32(buf, arr[i]);
}

void pack_1darray_u64_data(unsigned char buf[], unsigned size,
                           uint64_t const arr[])
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_u64(buf, arr[i]);
}
