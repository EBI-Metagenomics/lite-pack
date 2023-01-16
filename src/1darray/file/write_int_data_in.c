#include "lip/1darray/file/write_int_data_in.h"
#include "1darray/pack_int_in.h"
#include "lip/file/file.h"

/* SIGNED */

bool lip_write_1darray_i8_data_in(struct lip_file *file, unsigned size,
                                  int8_t arr[])
{
    if (file->error) return false;

    pack_1darray_i8_data_in((unsigned char *)arr, size);
    file->error = fwrite(arr, size * sizeof(int8_t), 1, file->fp) != 1;

    return !file->error;
}

bool lip_write_1darray_i16_data_in(struct lip_file *file, unsigned size,
                                   int16_t arr[])
{
    if (file->error) return false;

    pack_1darray_i16_data_in((unsigned char *)arr, size);
    file->error = fwrite(arr, size * sizeof(int16_t), 1, file->fp) != 1;

    return !file->error;
}

bool lip_write_1darray_i32_data_in(struct lip_file *file, unsigned size,
                                   int32_t arr[])
{
    if (file->error) return false;

    pack_1darray_i32_data_in((unsigned char *)arr, size);
    file->error = fwrite(arr, size * sizeof(int32_t), 1, file->fp) != 1;

    return !file->error;
}

bool lip_write_1darray_i64_data_in(struct lip_file *file, unsigned size,
                                   int64_t arr[])
{
    if (file->error) return false;

    pack_1darray_i64_data_in((unsigned char *)arr, size);
    file->error = fwrite(arr, size * sizeof(int64_t), 1, file->fp) != 1;

    return !file->error;
}

/* UNSIGNED */

bool lip_write_1darray_u8_data_in(struct lip_file *file, unsigned size,
                                  uint8_t arr[])
{
    if (file->error) return false;

    pack_1darray_u8_data_in((unsigned char *)arr, size);
    file->error = fwrite(arr, size * sizeof(uint8_t), 1, file->fp) != 1;

    return !file->error;
}

bool lip_write_1darray_u16_data_in(struct lip_file *file, unsigned size,
                                   uint16_t arr[])
{
    if (file->error) return false;

    pack_1darray_u16_data_in((unsigned char *)arr, size);
    file->error = fwrite(arr, size * sizeof(uint16_t), 1, file->fp) != 1;

    return !file->error;
}

bool lip_write_1darray_u32_data_in(struct lip_file *file, unsigned size,
                                   uint32_t arr[])
{
    if (file->error) return false;

    pack_1darray_u32_data_in((unsigned char *)arr, size);
    file->error = fwrite(arr, size * sizeof(uint32_t), 1, file->fp) != 1;

    return !file->error;
}

bool lip_write_1darray_u64_data_in(struct lip_file *file, unsigned size,
                                   uint64_t arr[])
{
    if (file->error) return false;

    pack_1darray_u64_data_in((unsigned char *)arr, size);
    file->error = fwrite(arr, size * sizeof(uint64_t), 1, file->fp) != 1;

    return !file->error;
}
