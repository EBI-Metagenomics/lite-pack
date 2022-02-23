#include "lite_pack/1darray/file/write_int_data.h"
#include "1darray/pack.h"
#include "lite_pack/1darray/file/write_int_item.h"
#include "lite_pack/file/file.h"
#include "lite_pack/store_int.h"

/* SIGNED */

bool lip_write_1darray_i8_data(struct lip_file *file, unsigned size,
                               int8_t const arr[])
{
    if (file->error) return false;

    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_i8_item(io, arr[i]);

    return !file->error;
}

bool lip_write_1darray_i16_data(struct lip_file *file, unsigned size,
                                int16_t const arr[])
{
    if (file->error) return false;

    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_i16_item(io, arr[i]);

    return !file->error;
}

bool lip_write_1darray_i32_data(struct lip_file *file, unsigned size,
                                int32_t const arr[])
{
    if (file->error) return false;

    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_i32_item(io, arr[i]);

    return !file->error;
}

bool lip_write_1darray_i64_data(struct lip_file *file, unsigned size,
                                int64_t const arr[])
{
    if (file->error) return false;

    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_i64_item(io, arr[i]);

    return !file->error;
}

/* UNSIGNED */

bool lip_write_1darray_u8_data(struct lip_file *file, unsigned size,
                               uint8_t const arr[])
{
    if (file->error) return false;

    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_u8_item(io, arr[i]);

    return !file->error;
}

bool lip_write_1darray_u16_data(struct lip_file *file, unsigned size,
                                uint16_t const arr[])
{
    if (file->error) return false;

    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_u16_item(io, arr[i]);

    return !file->error;
}

bool lip_write_1darray_u32_data(struct lip_file *file, unsigned size,
                                uint32_t const arr[])
{
    if (file->error) return false;

    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_u32_item(io, arr[i]);

    return !file->error;
}

bool lip_write_1darray_u64_data(struct lip_file *file, unsigned size,
                                uint64_t const arr[])
{
    if (file->error) return false;

    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_u64_item(io, arr[i]);

    return !file->error;
}
