#include "1darray/pack_int_inplace.h"
#include "lite_pack/store_int.h"

void pack_1darray_i8_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_i8_inplace(buf);
}

void pack_1darray_i16_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_i16_inplace(buf);
}

void pack_1darray_i32_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_i32_inplace(buf);
}

void pack_1darray_i64_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_i64_inplace(buf);
}

void pack_1darray_u8_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_u8_inplace(buf);
}

void pack_1darray_u16_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_u16_inplace(buf);
}

void pack_1darray_u32_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_u32_inplace(buf);
}

void pack_1darray_u64_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_u64_inplace(buf);
}
