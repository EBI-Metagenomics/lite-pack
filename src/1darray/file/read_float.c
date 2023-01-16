#include "lip/1darray/file/read_float.h"
#include "1darray/unpack_float.h"
#include "lip/file/file.h"
#include "lip/stdio_unlocked.h"

bool lip_read_1darray_f32_data(struct lip_file *file, unsigned size,
                               float arr[])
{
    if (file->error) return false;

    file->error = lip_fread(arr, size * sizeof(float), 1, file->fp) != 1;
    if (file->error) return false;

    unpack_1darray_f32_data_in((unsigned char *)arr, size);
    return !file->error;
}

bool lip_read_1darray_f64_data(struct lip_file *file, unsigned size,
                               double arr[])
{
    if (file->error) return false;

    file->error = lip_fread(arr, size * sizeof(double), 1, file->fp) != 1;
    if (file->error) return false;

    unpack_1darray_f64_data_in((unsigned char *)arr, size);
    return !file->error;
}
