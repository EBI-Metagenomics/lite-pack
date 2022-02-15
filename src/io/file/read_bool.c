#include "lite_pack/io/file.h"
#include "lite_pack/unpack_bool.h"

void lip_read_bool(struct lip_io_file *ctx, bool *val)
{
    if (ctx->error) return;

    unsigned char buf[1] = {0};

    ctx->error = fread(buf, 1, 1, ctx->fp) != 1;
    if (ctx->error) return;

    ctx->error = lip_unpack_bool(buf, val) == 0;
}
