#include "lip/1darray/file/write_int.h"
#include "1darray/pack.h"
#include "lip/1darray/1darray.h"
#include "lip/1darray/file/write_int_item.h"
#include "lip/file/file.h"
#include "lip/store_int.h"

/* SIGNED */

bool lip_write_1darray_i8(struct lip_file *file, unsigned size,
                          int8_t const arr[])
{
    if (file->error) return false;

    lip_write_1darray_size_type(file, size, LIP_1DARRAY_INT8);
    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_i8_item(file, arr[i]);

    return !file->error;
}

bool lip_write_1darray_i16(struct lip_file *file, unsigned size,
                           int16_t const arr[])
{
    if (file->error) return false;

    lip_write_1darray_size_type(file, size, LIP_1DARRAY_INT16);
    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_i16_item(file, arr[i]);

    return !file->error;
}

bool lip_write_1darray_i32(struct lip_file *file, unsigned size,
                           int32_t const arr[])
{
    if (file->error) return false;

    lip_write_1darray_size_type(file, size, LIP_1DARRAY_INT32);
    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_i32_item(file, arr[i]);

    return !file->error;
}

bool lip_write_1darray_i64(struct lip_file *file, unsigned size,
                           int64_t const arr[])
{
    if (file->error) return false;

    lip_write_1darray_size_type(file, size, LIP_1DARRAY_INT64);
    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_i64_item(file, arr[i]);

    return !file->error;
}

/* UNSIGNED */

bool lip_write_1darray_u8(struct lip_file *file, unsigned size,
                          uint8_t const arr[])
{
    if (file->error) return false;

    lip_write_1darray_size_type(file, size, LIP_1DARRAY_UINT8);
    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_u8_item(file, arr[i]);

    return !file->error;
}

bool lip_write_1darray_u16(struct lip_file *file, unsigned size,
                           uint16_t const arr[])
{
    if (file->error) return false;

    lip_write_1darray_size_type(file, size, LIP_1DARRAY_UINT16);
    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_u16_item(file, arr[i]);

    return !file->error;
}

bool lip_write_1darray_u32(struct lip_file *file, unsigned size,
                           uint32_t const arr[])
{
    if (file->error) return false;

    lip_write_1darray_size_type(file, size, LIP_1DARRAY_UINT32);
    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_u32_item(file, arr[i]);

    return !file->error;
}

bool lip_write_1darray_u64(struct lip_file *file, unsigned size,
                           uint64_t const arr[])
{
    if (file->error) return false;

    lip_write_1darray_size_type(file, size, LIP_1DARRAY_UINT64);
    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_u64_item(file, arr[i]);

    return !file->error;
}
