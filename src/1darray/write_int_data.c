#include "lite_pack/1darray/write_int_data.h"
#include "1darray/pack.h"
#include "lite_pack/1darray/write_int_item.h"
#include "lite_pack/io/file.h"
#include "lite_pack/store_int.h"

/* SIGNED */

void lip_write_1darray_i8_data(struct lip_io_file *io, unsigned size,
                               int8_t const arr[])
{
    if (io->error) return;

    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_i8_item(io, arr[i]);
}

void lip_write_1darray_i16_data(struct lip_io_file *io, unsigned size,
                                int16_t const arr[])
{
    if (io->error) return;

    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_i16_item(io, arr[i]);
}

void lip_write_1darray_i32_data(struct lip_io_file *io, unsigned size,
                                int32_t const arr[])
{
    if (io->error) return;

    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_i32_item(io, arr[i]);
}

void lip_write_1darray_i64_data(struct lip_io_file *io, unsigned size,
                                int64_t const arr[])
{
    if (io->error) return;

    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_i64_item(io, arr[i]);
}

/* UNSIGNED */

void lip_write_1darray_u8_data(struct lip_io_file *io, unsigned size,
                               uint8_t const arr[])
{
    if (io->error) return;

    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_u8_item(io, arr[i]);
}

void lip_write_1darray_u16_data(struct lip_io_file *io, unsigned size,
                                uint16_t const arr[])
{
    if (io->error) return;

    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_u16_item(io, arr[i]);
}

void lip_write_1darray_u32_data(struct lip_io_file *io, unsigned size,
                                uint32_t const arr[])
{
    if (io->error) return;

    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_u32_item(io, arr[i]);
}

void lip_write_1darray_u64_data(struct lip_io_file *io, unsigned size,
                                uint64_t const arr[])
{
    if (io->error) return;

    for (unsigned i = 0; i < size; ++i)
        lip_write_1darray_u64_item(io, arr[i]);
}
