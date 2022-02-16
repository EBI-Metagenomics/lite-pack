#include "lite_pack/1darray/write_int.h"
#include "1darray/pack.h"
#include "lite_pack/1darray/1darray.h"
#include "lite_pack/1darray/write_int_item.h"
#include "lite_pack/io/file.h"
#include "lite_pack/store_int.h"

/* SIGNED */

void lip_write_1darray_i8(struct lip_io_file *io, unsigned size,
                          int8_t const arr[])
{
    if (io->error) return;

    lip_write_1darray_size_type(io, size, LIP_1DARRAY_INT8);
    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_i8_item(io, arr[i]);
}

void lip_write_1darray_i16(struct lip_io_file *io, unsigned size,
                           int16_t const arr[])
{
    if (io->error) return;

    lip_write_1darray_size_type(io, size, LIP_1DARRAY_INT16);
    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_i16_item(io, arr[i]);
}

void lip_write_1darray_i32(struct lip_io_file *io, unsigned size,
                           int32_t const arr[])
{
    if (io->error) return;

    lip_write_1darray_size_type(io, size, LIP_1DARRAY_INT32);
    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_i32_item(io, arr[i]);
}

void lip_write_1darray_i64(struct lip_io_file *io, unsigned size,
                           int64_t const arr[])
{
    if (io->error) return;

    lip_write_1darray_size_type(io, size, LIP_1DARRAY_INT64);
    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_i64_item(io, arr[i]);
}

/* UNSIGNED */

void lip_write_1darray_u8(struct lip_io_file *io, unsigned size,
                          uint8_t const arr[])
{
    if (io->error) return;

    lip_write_1darray_size_type(io, size, LIP_1DARRAY_UINT8);
    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_u8_item(io, arr[i]);
}

void lip_write_1darray_u16(struct lip_io_file *io, unsigned size,
                           uint16_t const arr[])
{
    if (io->error) return;

    lip_write_1darray_size_type(io, size, LIP_1DARRAY_UINT16);
    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_u16_item(io, arr[i]);
}

void lip_write_1darray_u32(struct lip_io_file *io, unsigned size,
                           uint32_t const arr[])
{
    if (io->error) return;

    lip_write_1darray_size_type(io, size, LIP_1DARRAY_UINT32);
    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_u32_item(io, arr[i]);
}

void lip_write_1darray_u64(struct lip_io_file *io, unsigned size,
                           uint64_t const arr[])
{
    if (io->error) return;

    lip_write_1darray_size_type(io, size, LIP_1DARRAY_UINT64);
    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_u64_item(io, arr[i]);
}
