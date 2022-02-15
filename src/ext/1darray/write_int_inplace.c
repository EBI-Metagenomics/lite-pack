#include "lite_pack/ext/1darray/write_int_inplace.h"
#include "lite_pack/ext/1darray/pack.h"
#include "lite_pack/io/file.h"

/* SIGNED */

void lip_write_1darray_i8_data_inplace(struct lip_ctx_file *ctx, unsigned size,
                                       int8_t arr[])
{
    if (ctx->error) return;

    lip_pack_1darray_i8_data_inplace((unsigned char *)arr, size);
    ctx->error = fwrite(arr, size * sizeof(int8_t), 1, ctx->fp) != 1;
}

void lip_write_1darray_i16_data_inplace(struct lip_ctx_file *ctx, unsigned size,
                                        int16_t arr[])
{
    if (ctx->error) return;

    lip_pack_1darray_i16_data_inplace((unsigned char *)arr, size);
    ctx->error = fwrite(arr, size * sizeof(int16_t), 1, ctx->fp) != 1;
}

void lip_write_1darray_i32_data_inplace(struct lip_ctx_file *ctx, unsigned size,
                                        int32_t arr[])
{
    if (ctx->error) return;

    lip_pack_1darray_i32_data_inplace((unsigned char *)arr, size);
    ctx->error = fwrite(arr, size * sizeof(int32_t), 1, ctx->fp) != 1;
}

void lip_write_1darray_i64_data_inplace(struct lip_ctx_file *ctx, unsigned size,
                                        int64_t arr[])
{
    if (ctx->error) return;

    lip_pack_1darray_i64_data_inplace((unsigned char *)arr, size);
    ctx->error = fwrite(arr, size * sizeof(int64_t), 1, ctx->fp) != 1;
}

/* UNSIGNED */

void lip_write_1darray_u8_data_inplace(struct lip_ctx_file *ctx, unsigned size,
                                       uint8_t arr[])
{
    if (ctx->error) return;

    lip_pack_1darray_u8_data_inplace((unsigned char *)arr, size);
    ctx->error = fwrite(arr, size * sizeof(uint8_t), 1, ctx->fp) != 1;
}

void lip_write_1darray_u16_data_inplace(struct lip_ctx_file *ctx, unsigned size,
                                        uint16_t arr[])
{
    if (ctx->error) return;

    lip_pack_1darray_u16_data_inplace((unsigned char *)arr, size);
    ctx->error = fwrite(arr, size * sizeof(uint16_t), 1, ctx->fp) != 1;
}

void lip_write_1darray_u32_data_inplace(struct lip_ctx_file *ctx, unsigned size,
                                        uint32_t arr[])
{
    if (ctx->error) return;

    lip_pack_1darray_u32_data_inplace((unsigned char *)arr, size);
    ctx->error = fwrite(arr, size * sizeof(uint32_t), 1, ctx->fp) != 1;
}

void lip_write_1darray_u64_data_inplace(struct lip_ctx_file *ctx, unsigned size,
                                        uint64_t arr[])
{
    if (ctx->error) return;

    lip_pack_1darray_u64_data_inplace((unsigned char *)arr, size);
    ctx->error = fwrite(arr, size * sizeof(uint64_t), 1, ctx->fp) != 1;
}
