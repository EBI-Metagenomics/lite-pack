#include "1darray/pack_float.h"
#include "lite_pack/store_float.h"

void lip_pack_1darray_f32_data(unsigned char buf[], unsigned size,
                               float const arr[])
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_f32(buf, arr[i]);
}

void lip_pack_1darray_f32_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_f32_inplace(buf);
}

void lip_pack_1darray_f64_data(unsigned char buf[], unsigned size,
                               double const arr[])
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_f64(buf, arr[i]);
}

void lip_pack_1darray_f64_data_inplace(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_f64_inplace(buf);
}
