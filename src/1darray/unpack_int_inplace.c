#include "1darray/unpack_int_inplace.h"
#include "lite_pack/load_int.h"

void unpack_1darray_i8_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_i8_inplace(buf);
}

void unpack_1darray_i16_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_i16_inplace(buf);
}

void unpack_1darray_i32_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_i32_inplace(buf);
}

void unpack_1darray_i64_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_i64_inplace(buf);
}

void unpack_1darray_u8_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_u8_inplace(buf);
}
void unpack_1darray_u16_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_u16_inplace(buf);
}

void unpack_1darray_u32_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_u32_inplace(buf);
}

void unpack_1darray_u64_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_u64_inplace(buf);
}
