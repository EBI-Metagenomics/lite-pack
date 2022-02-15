#include "lite_pack/1darray/write.h"
#include "lite_pack/1darray/pack.h"
#include "lite_pack/io/file.h"

void lip_write_1darray_size_type(struct lip_ctx_file *ctx, unsigned size,
                                 uint8_t type)
{
    if (ctx->error) return;

    unsigned char buf[6] = {0};
    unsigned sz = lip_pack_1darray_size_type(buf, size, type);
    ctx->error = fwrite(buf, sz, 1, ctx->fp) != 1;
}
