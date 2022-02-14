#include "lite_pack/io/file_write_float.h"
#include "lite_pack/io/file_ctx.h"
#include "lite_pack/pack_float.h"

void __lip_write_f32(struct lip_ctx_file *ctx, float val)
{
    if (ctx->error) return;
    unsigned sz = __lip_pack_f32(ctx->buf, val);
    ctx->error = fwrite(ctx->buf, sz, 1, ctx->fp) != 1;
}

void __lip_write_f64(struct lip_ctx_file *ctx, double val)
{
    if (ctx->error) return;
    unsigned sz = __lip_pack_f64(ctx->buf, val);
    ctx->error = fwrite(ctx->buf, sz, 1, ctx->fp) != 1;
}
