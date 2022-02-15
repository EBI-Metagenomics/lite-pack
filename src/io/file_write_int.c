#include "lite_pack/io/file_write_int.h"
#include "lite_pack/io/file_ctx.h"
#include "lite_pack/pack_int.h"

/* SIGNED INTEGER */

void __lip_write_i8(struct lip_ctx_file *ctx, int val)
{
    if (ctx->error) return;

    unsigned char buf[2] = {0};
    unsigned sz = __lip_pack_i8(buf, val);
    ctx->error = fwrite(buf, sz, 1, ctx->fp) != 1;
}

void __lip_write_i16(struct lip_ctx_file *ctx, int val)
{
    if (ctx->error) return;

    unsigned char buf[3] = {0};
    unsigned sz = __lip_pack_i16(buf, val);
    ctx->error = fwrite(buf, sz, 1, ctx->fp) != 1;
}

void __lip_write_i32(struct lip_ctx_file *ctx, int val)
{
    if (ctx->error) return;

    unsigned char buf[5] = {0};
    unsigned sz = __lip_pack_i32(buf, val);
    ctx->error = fwrite(buf, sz, 1, ctx->fp) != 1;
}

void __lip_write_i64(struct lip_ctx_file *ctx, long val)
{
    if (ctx->error) return;

    unsigned char buf[9] = {0};
    unsigned sz = __lip_pack_i64(buf, val);
    ctx->error = fwrite(buf, sz, 1, ctx->fp) != 1;
}

/* UNSIGNED INTEGER */

void __lip_write_u8(struct lip_ctx_file *ctx, unsigned val)
{
    if (ctx->error) return;

    unsigned char buf[2] = {0};
    unsigned sz = __lip_pack_u8(buf, val);
    ctx->error = fwrite(buf, sz, 1, ctx->fp) != 1;
}

void __lip_write_u16(struct lip_ctx_file *ctx, unsigned val)
{
    if (ctx->error) return;

    unsigned char buf[3] = {0};
    unsigned sz = __lip_pack_u16(buf, val);
    ctx->error = fwrite(buf, sz, 1, ctx->fp) != 1;
}

void __lip_write_u32(struct lip_ctx_file *ctx, unsigned val)
{
    if (ctx->error) return;

    unsigned char buf[5] = {0};
    unsigned sz = __lip_pack_u32(buf, val);
    ctx->error = fwrite(buf, sz, 1, ctx->fp) != 1;
}

void __lip_write_u64(struct lip_ctx_file *ctx, unsigned long val)
{
    if (ctx->error) return;

    unsigned char buf[9] = {0};
    unsigned sz = __lip_pack_u64(buf, val);
    ctx->error = fwrite(buf, sz, 1, ctx->fp) != 1;
}
