#include "1darray/unpack_int_in.h"
#include "lip/load_int.h"

void unpack_1darray_i8_data_in(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_i8_in(buf);
}

void unpack_1darray_i16_data_in(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_i16_in(buf);
}

void unpack_1darray_i32_data_in(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_i32_in(buf);
}

void unpack_1darray_i64_data_in(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_i64_in(buf);
}

void unpack_1darray_u8_data_in(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_u8_in(buf);
}
void unpack_1darray_u16_data_in(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_u16_in(buf);
}

void unpack_1darray_u32_data_in(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_u32_in(buf);
}

void unpack_1darray_u64_data_in(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_u64_in(buf);
}
