#include "lite_pack/1darray/file/write_int_data_inplace.h"
#include "1darray/pack_int_inplace.h"
#include "lite_pack/file/file.h"

/* SIGNED */

void lip_write_1darray_i8_data_inplace(struct lip_file *io, unsigned size,
                                       int8_t arr[])
{
    if (io->error) return;

    pack_1darray_i8_data_inplace((unsigned char *)arr, size);
    io->error = fwrite(arr, size * sizeof(int8_t), 1, io->fp) != 1;
}

void lip_write_1darray_i16_data_inplace(struct lip_file *io, unsigned size,
                                        int16_t arr[])
{
    if (io->error) return;

    pack_1darray_i16_data_inplace((unsigned char *)arr, size);
    io->error = fwrite(arr, size * sizeof(int16_t), 1, io->fp) != 1;
}

void lip_write_1darray_i32_data_inplace(struct lip_file *io, unsigned size,
                                        int32_t arr[])
{
    if (io->error) return;

    pack_1darray_i32_data_inplace((unsigned char *)arr, size);
    io->error = fwrite(arr, size * sizeof(int32_t), 1, io->fp) != 1;
}

void lip_write_1darray_i64_data_inplace(struct lip_file *io, unsigned size,
                                        int64_t arr[])
{
    if (io->error) return;

    pack_1darray_i64_data_inplace((unsigned char *)arr, size);
    io->error = fwrite(arr, size * sizeof(int64_t), 1, io->fp) != 1;
}

/* UNSIGNED */

void lip_write_1darray_u8_data_inplace(struct lip_file *io, unsigned size,
                                       uint8_t arr[])
{
    if (io->error) return;

    pack_1darray_u8_data_inplace((unsigned char *)arr, size);
    io->error = fwrite(arr, size * sizeof(uint8_t), 1, io->fp) != 1;
}

void lip_write_1darray_u16_data_inplace(struct lip_file *io, unsigned size,
                                        uint16_t arr[])
{
    if (io->error) return;

    pack_1darray_u16_data_inplace((unsigned char *)arr, size);
    io->error = fwrite(arr, size * sizeof(uint16_t), 1, io->fp) != 1;
}

void lip_write_1darray_u32_data_inplace(struct lip_file *io, unsigned size,
                                        uint32_t arr[])
{
    if (io->error) return;

    pack_1darray_u32_data_inplace((unsigned char *)arr, size);
    io->error = fwrite(arr, size * sizeof(uint32_t), 1, io->fp) != 1;
}

void lip_write_1darray_u64_data_inplace(struct lip_file *io, unsigned size,
                                        uint64_t arr[])
{
    if (io->error) return;

    pack_1darray_u64_data_inplace((unsigned char *)arr, size);
    io->error = fwrite(arr, size * sizeof(uint64_t), 1, io->fp) != 1;
}
