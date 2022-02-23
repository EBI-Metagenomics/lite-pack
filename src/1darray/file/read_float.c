#include "lite_pack/1darray/file/read_float.h"
#include "1darray/unpack_float.h"
#include "lite_pack/file/file.h"
#include "lite_pack/stdio_unlocked.h"

bool lip_read_1darray_f32_data(struct lip_file *io, unsigned size, float arr[])
{
    if (io->error) return false;

    io->error = lip_fread(arr, size * sizeof(float), 1, io->fp) != 1;
    if (io->error) return false;

    unpack_1darray_f32_data_in((unsigned char *)arr, size);
    return !io->error;
}

bool lip_read_1darray_f64_data(struct lip_file *io, unsigned size, double arr[])
{
    if (io->error) return false;

    io->error = lip_fread(arr, size * sizeof(double), 1, io->fp) != 1;
    if (io->error) return false;

    unpack_1darray_f64_data_in((unsigned char *)arr, size);
    return !io->error;
}
