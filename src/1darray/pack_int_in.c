#include "1darray/pack_int_in.h"
#include "lite_pack/store_int.h"

void pack_1darray_i8_data_in(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_i8_in(buf);
}

void pack_1darray_i16_data_in(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_i16_in(buf);
}

void pack_1darray_i32_data_in(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_i32_in(buf);
}

void pack_1darray_i64_data_in(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_i64_in(buf);
}

void pack_1darray_u8_data_in(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_u8_in(buf);
}

void pack_1darray_u16_data_in(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_u16_in(buf);
}

void pack_1darray_u32_data_in(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_u32_in(buf);
}

void pack_1darray_u64_data_in(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_u64_in(buf);
}
