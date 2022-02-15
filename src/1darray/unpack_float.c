#include "1darray/unpack_float.h"
#include "lite_pack/load_float.h"

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
