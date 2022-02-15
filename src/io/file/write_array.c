#include "lite_pack/io/file.h"
#include "lite_pack/pack_array.h"

void lip_write_array_size(struct lip_io_file *ctx, unsigned size)
{
    if (ctx->error) return;

    unsigned char buf[5] = {0};
    unsigned sz = lip_pack_array_size(buf, size);
    ctx->error = fwrite(buf, sz, 1, ctx->fp) != 1;
}
