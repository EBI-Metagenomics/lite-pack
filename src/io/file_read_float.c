#include "lite_pack/io/file_read_float.h"
#include "lite_pack/format.h"
#include "lite_pack/io/file_ctx.h"
#include "lite_pack/unpack_float.h"

void __lip_read_f32(struct lip_ctx_file *ctx, float *val)
{
    if (ctx->error) return;

    unsigned char buf[5] = {0};

    ctx->error = fread(buf, 1, 1, ctx->fp) != 1;
    if (ctx->error) return;

    if (lip_format(buf) != LIP_FMT_FLOAT_32)
    {
        ctx->error = true;
        return;
    }

    ctx->error = fread(buf + 1, 4, 1, ctx->fp) != 1;
    if (ctx->error) return;

    ctx->error = __lip_unpack_f32(buf, val) == 0;
}

void __lip_read_f64(struct lip_ctx_file *ctx, double *val)
{
    if (ctx->error) return;

    unsigned char buf[9] = {0};

    ctx->error = fread(buf, 1, 1, ctx->fp) != 1;
    if (ctx->error) return;

    unsigned sz = 0;
    if (lip_format(buf) == LIP_FMT_FLOAT_32)
    {
        sz = 4;
    }
    else if (lip_format(buf) == LIP_FMT_FLOAT_64)
    {
        sz = 8;
    }
    else
    {
        ctx->error = true;
        return;
    }

    ctx->error = fread(buf + 1, sz, 1, ctx->fp) != 1;
    if (ctx->error) return;

    ctx->error = __lip_unpack_f64(buf, val) == 0;
}
