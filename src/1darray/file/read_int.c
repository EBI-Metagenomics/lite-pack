#include "lite_pack/1darray/file/read_int.h"
#include "1darray/unpack_int_in.h"
#include "lite_pack/file/file.h"
#include "lite_pack/stdio_unlocked.h"

/* SIGNED */

bool lip_read_1darray_i8_data(struct lip_file *file, unsigned size,
                              int8_t arr[])
{
    if (file->error) return false;

    file->error = lip_fread(arr, size * sizeof(int8_t), 1, file->fp) != 1;
    if (file->error) return false;

    unpack_1darray_i8_data_in((unsigned char *)arr, size);
    return !file->error;
}

bool lip_read_1darray_i16_data(struct lip_file *file, unsigned size,
                               int16_t arr[])
{
    if (file->error) return false;

    file->error = lip_fread(arr, size * sizeof(int16_t), 1, file->fp) != 1;
    if (file->error) return false;

    unpack_1darray_i16_data_in((unsigned char *)arr, size);
    return !file->error;
}

bool lip_read_1darray_i32_data(struct lip_file *file, unsigned size,
                               int32_t arr[])
{
    if (file->error) return false;

    file->error = lip_fread(arr, size * sizeof(int32_t), 1, file->fp) != 1;
    if (file->error) return false;

    unpack_1darray_i32_data_in((unsigned char *)arr, size);
    return !file->error;
}

bool lip_read_1darray_i64_data(struct lip_file *file, unsigned size,
                               int64_t arr[])
{
    if (file->error) return false;

    file->error = lip_fread(arr, size * sizeof(int64_t), 1, file->fp) != 1;
    if (file->error) return false;

    unpack_1darray_i64_data_in((unsigned char *)arr, size);
    return !file->error;
}

/* UNSIGNED */

bool lip_read_1darray_u8_data(struct lip_file *file, unsigned size,
                              uint8_t arr[])
{
    if (file->error) return false;

    file->error = lip_fread(arr, size * sizeof(uint8_t), 1, file->fp) != 1;
    if (file->error) return false;

    unpack_1darray_u8_data_in((unsigned char *)arr, size);
    return !file->error;
}

bool lip_read_1darray_u16_data(struct lip_file *file, unsigned size,
                               uint16_t arr[])
{
    if (file->error) return false;

    file->error = lip_fread(arr, size * sizeof(uint16_t), 1, file->fp) != 1;
    if (file->error) return false;

    unpack_1darray_u16_data_in((unsigned char *)arr, size);
    return !file->error;
}

bool lip_read_1darray_u32_data(struct lip_file *file, unsigned size,
                               uint32_t arr[])
{
    if (file->error) return false;

    file->error = lip_fread(arr, size * sizeof(uint32_t), 1, file->fp) != 1;
    if (file->error) return false;

    unpack_1darray_u32_data_in((unsigned char *)arr, size);
    return !file->error;
}

bool lip_read_1darray_u64_data(struct lip_file *file, unsigned size,
                               uint64_t arr[])
{
    if (file->error) return false;

    file->error = lip_fread(arr, size * sizeof(uint64_t), 1, file->fp) != 1;
    if (file->error) return false;

    unpack_1darray_u64_data_in((unsigned char *)arr, size);
    return !file->error;
}
