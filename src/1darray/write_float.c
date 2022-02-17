#include "lite_pack/1darray/write_float.h"
#include "1darray/pack_float.h"
#include "lite_pack/1darray/1darray.h"
#include "lite_pack/1darray/type.h"
#include "lite_pack/io/file.h"
#include "lite_pack/store_float.h"

void lip_write_1darray_f32(struct lip_file *io, unsigned size,
                           float const arr[])
{
    if (io->error) return;

    lip_write_1darray_size_type(io, size, LIP_1DARRAY_F32);
    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_f32_item(io, arr[i]);
}

void lip_write_1darray_f64(struct lip_file *io, unsigned size,
                           double const arr[])
{
    if (io->error) return;

    lip_write_1darray_size_type(io, size, LIP_1DARRAY_F64);
    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_f64_item(io, arr[i]);
}

void lip_write_1darray_f32_data(struct lip_file *io, unsigned size,
                                float const arr[])
{
    if (io->error) return;

    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_f32_item(io, arr[i]);
}

void lip_write_1darray_f64_data(struct lip_file *io, unsigned size,
                                double const arr[])
{
    if (io->error) return;

    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_f64_item(io, arr[i]);
}

void lip_write_1darray_f32_data_inplace(struct lip_file *io, unsigned size,
                                        float arr[])
{
    if (io->error) return;

    pack_1darray_f32_data_inplace((unsigned char *)arr, size);
    io->error = fwrite(arr, size * sizeof(float), 1, io->fp) != 1;
}

void lip_write_1darray_f64_data_inplace(struct lip_file *io, unsigned size,
                                        double arr[])
{
    if (io->error) return;

    pack_1darray_f64_data_inplace((unsigned char *)arr, size);
    io->error = fwrite(arr, size * sizeof(double), 1, io->fp) != 1;
}
