#include "lite_pack/1darray/1darray.h"

void lip_unpack_1darray_i8_data(unsigned char const buf[], unsigned size,
                                int8_t arr[])
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_i8(buf, arr++);
}

void lip_unpack_1darray_i8_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_i8_inplace(buf);
}

void lip_unpack_1darray_i16_data(unsigned char const buf[], unsigned size,
                                 int16_t arr[])
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_i16(buf, arr++);
}

void lip_unpack_1darray_i16_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_i16_inplace(buf);
}

void lip_unpack_1darray_i32_data(unsigned char const buf[], unsigned size,
                                 int32_t arr[])
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_i32(buf, arr++);
}

void lip_unpack_1darray_i32_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_i32_inplace(buf);
}

void lip_unpack_1darray_i64_data(unsigned char const buf[], unsigned size,
                                 int64_t arr[])
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_i64(buf, arr++);
}

void lip_unpack_1darray_i64_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_i64_inplace(buf);
}

void lip_unpack_1darray_u8_data(unsigned char const buf[], unsigned size,
                                uint8_t arr[])
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_u8(buf, arr++);
}

void lip_unpack_1darray_u8_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_u8_inplace(buf);
}
void lip_unpack_1darray_u16_data(unsigned char const buf[], unsigned size,
                                 uint16_t arr[])
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_u16(buf, arr++);
}

void lip_unpack_1darray_u16_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_u16_inplace(buf);
}

void lip_unpack_1darray_u32_data(unsigned char const buf[], unsigned size,
                                 uint32_t arr[])
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_u32(buf, arr++);
}

void lip_unpack_1darray_u32_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_u32_inplace(buf);
}

void lip_unpack_1darray_u64_data(unsigned char const buf[], unsigned size,
                                 uint64_t arr[])
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_u64(buf, arr++);
}

void lip_unpack_1darray_u64_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_u64_inplace(buf);
}

void lip_unpack_1darray_f32_data(unsigned char const buf[], unsigned size,
                                 float arr[])
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_f32(buf, arr++);
}

void lip_unpack_1darray_f32_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_f32_inplace(buf);
}

void lip_unpack_1darray_f64_data(unsigned char const buf[], unsigned size,
                                 double arr[])
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_f64(buf, arr++);
}

void lip_unpack_1darray_f64_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_load_f64_inplace(buf);
}
