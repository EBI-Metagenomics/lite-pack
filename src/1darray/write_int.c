#include "lite_pack/1darray/write_int.h"
#include "1darray/pack.h"
#include "lite_pack/io/file.h"
#include "lite_pack/store_int.h"

/* SIGNED */

void lip_write_1darray_i8_data(struct lip_ctx_file *ctx, unsigned size,
                               int8_t const arr[])
{
    if (ctx->error) return;

    unsigned char buf[sizeof(int8_t)] = {0};
    for (unsigned i = 0; i < size; ++i)
    {
        ctx->error |= lip_store_i8(buf, arr[i]) == 0;
        ctx->error |= fwrite(buf, sizeof(int8_t), 1, ctx->fp) != 1;
    }
}

void lip_write_1darray_i16_data(struct lip_ctx_file *ctx, unsigned size,
                                int16_t const arr[])
{
    if (ctx->error) return;

    unsigned char buf[sizeof(int16_t)] = {0};
    for (unsigned i = 0; i < size; ++i)
    {
        ctx->error |= lip_store_i16(buf, arr[i]) == 0;
        ctx->error |= fwrite(buf, sizeof(int16_t), 1, ctx->fp) != 1;
    }
}

void lip_write_1darray_i32_data(struct lip_ctx_file *ctx, unsigned size,
                                int32_t const arr[])
{
    if (ctx->error) return;

    unsigned char buf[sizeof(int32_t)] = {0};
    for (unsigned i = 0; i < size; ++i)
    {
        ctx->error |= lip_store_i32(buf, arr[i]) == 0;
        ctx->error |= fwrite(buf, sizeof(int32_t), 1, ctx->fp) != 1;
    }
}

void lip_write_1darray_i64_data(struct lip_ctx_file *ctx, unsigned size,
                                int64_t const arr[])
{
    if (ctx->error) return;

    unsigned char buf[sizeof(int64_t)] = {0};
    for (unsigned i = 0; i < size; ++i)
    {
        ctx->error |= lip_store_i64(buf, arr[i]) == 0;
        ctx->error |= fwrite(buf, sizeof(int64_t), 1, ctx->fp) != 1;
    }
}

/* UNSIGNED */

void lip_write_1darray_u8_data(struct lip_ctx_file *ctx, unsigned size,
                               uint8_t const arr[])
{
    if (ctx->error) return;

    unsigned char buf[sizeof(uint8_t)] = {0};
    for (unsigned i = 0; i < size; ++i)
    {
        ctx->error |= lip_store_u8(buf, arr[i]) == 0;
        ctx->error |= fwrite(buf, sizeof(uint8_t), 1, ctx->fp) != 1;
    }
}

void lip_write_1darray_u16_data(struct lip_ctx_file *ctx, unsigned size,
                                uint16_t const arr[])
{
    if (ctx->error) return;

    unsigned char buf[sizeof(uint16_t)] = {0};
    for (unsigned i = 0; i < size; ++i)
    {
        ctx->error |= lip_store_u16(buf, arr[i]) == 0;
        ctx->error |= fwrite(buf, sizeof(uint16_t), 1, ctx->fp) != 1;
    }
}

void lip_write_1darray_u32_data(struct lip_ctx_file *ctx, unsigned size,
                                uint32_t const arr[])
{
    if (ctx->error) return;

    unsigned char buf[sizeof(uint32_t)] = {0};
    for (unsigned i = 0; i < size; ++i)
    {
        ctx->error |= lip_store_u32(buf, arr[i]) == 0;
        ctx->error |= fwrite(buf, sizeof(uint32_t), 1, ctx->fp) != 1;
    }
}

void lip_write_1darray_u64_data(struct lip_ctx_file *ctx, unsigned size,
                                uint64_t const arr[])
{
    if (ctx->error) return;

    unsigned char buf[sizeof(uint64_t)] = {0};
    for (unsigned i = 0; i < size; ++i)
    {
        ctx->error |= lip_store_u64(buf, arr[i]) == 0;
        ctx->error |= fwrite(buf, sizeof(uint64_t), 1, ctx->fp) != 1;
    }
}
