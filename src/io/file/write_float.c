#include "lite_pack/io/file.h"
#include "lite_pack/pack_float.h"

void __lip_write_f32(struct lip_io_file *ctx, float val)
{
    if (ctx->error) return;

    unsigned char buf[5] = {0};
    unsigned sz = __lip_pack_f32(buf, val);
    ctx->error = fwrite(buf, sz, 1, ctx->fp) != 1;
}

void __lip_write_f64(struct lip_io_file *ctx, double val)
{
    if (ctx->error) return;

    unsigned char buf[9] = {0};
    unsigned sz = __lip_pack_f64(buf, val);
    ctx->error = fwrite(buf, sz, 1, ctx->fp) != 1;
}
