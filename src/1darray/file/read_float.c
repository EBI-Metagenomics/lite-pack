#include "lite_pack/1darray/file/read_float.h"
#include "1darray/unpack_float.h"
#include "lite_pack/file/file.h"

void lip_read_1darray_f32_data(struct lip_file *io, unsigned size, float arr[])
{
    if (io->error) return;

    io->error = fread(arr, size * sizeof(float), 1, io->fp) != 1;
    if (io->error) return;

    unpack_1darray_f32_data_in((unsigned char *)arr, size);
}

void lip_read_1darray_f64_data(struct lip_file *io, unsigned size, double arr[])
{
    if (io->error) return;

    io->error = fread(arr, size * sizeof(double), 1, io->fp) != 1;
    if (io->error) return;

    unpack_1darray_f64_data_in((unsigned char *)arr, size);
}
