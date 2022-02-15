#include "lite_pack/io/file.h"
#include "lite_pack/pack_str.h"

void lip_write_str_size(struct lip_io_file *ctx, unsigned size)
{
    if (ctx->error) return;

    unsigned char buf[5] = {0};
    unsigned sz = lip_pack_str_size(buf, size);
    ctx->error = fwrite(buf, sz, 1, ctx->fp) != 1;
}

void lip_write_str_data(struct lip_io_file *ctx, unsigned size,
                        char const val[])
{
    if (ctx->error) return;

    ctx->error = fwrite(val, size, 1, ctx->fp) != 1;
}
