#include "lite_pack/1darray/read_float.h"
#include "1darray/unpack_float.h"
#include "lite_pack/io/file.h"

void lip_read_1darray_f32_data(struct lip_ctx_file *ctx, unsigned size,
                               float arr[])
{
    if (ctx->error) return;

    ctx->error = fread(arr, size * sizeof(float), 1, ctx->fp) != 1;
    if (ctx->error) return;

    lip_unpack_1darray_f32_data_inplace((unsigned char *)arr, size);
}

void lip_read_1darray_f64_data(struct lip_ctx_file *ctx, unsigned size,
                               double arr[])
{
    if (ctx->error) return;

    ctx->error = fread(arr, size * sizeof(double), 1, ctx->fp) != 1;
    if (ctx->error) return;

    lip_unpack_1darray_f64_data_inplace((unsigned char *)arr, size);
}
