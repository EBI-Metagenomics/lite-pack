#include "lite_pack/1darray/read.h"
#include "1darray/unpack.h"
#include "lite_pack/io/file.h"

void lip_read_1darray_size_type(struct lip_io_file *ctx, unsigned *size,
                                uint8_t *type)
{
    if (ctx->error) return;

    unsigned char buf[6] = {0};
    lip_read_ext_size_type(ctx, size, type);
    ctx->error = lip_unpack_1darray_size_type(buf, size, type) == 0;
}
