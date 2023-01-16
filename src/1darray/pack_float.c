#include "1darray/pack_float.h"
#include "lip/store_float.h"

void pack_1darray_f32_data(unsigned char buf[], unsigned size,
                           float const arr[])
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_f32(buf, arr[i]);
}

void pack_1darray_f32_data_in(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_f32_in(buf);
}

void pack_1darray_f64_data(unsigned char buf[], unsigned size,
                           double const arr[])
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_f64(buf, arr[i]);
}

void pack_1darray_f64_data_in(unsigned char buf[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        buf += lip_store_f64_in(buf);
}
