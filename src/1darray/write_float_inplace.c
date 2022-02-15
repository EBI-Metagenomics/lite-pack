#include "lite_pack/1darray/write_float_inplace.h"
#include "lite_pack/1darray/pack.h"
#include "lite_pack/io/file.h"

void lip_write_1darray_f32_data_inplace(struct lip_ctx_file *ctx, unsigned size,
                                        float arr[])
{
    if (ctx->error) return;

    lip_pack_1darray_f32_data_inplace((unsigned char *)arr, size);
    ctx->error = fwrite(arr, size * sizeof(float), 1, ctx->fp) != 1;
}

void lip_write_1darray_f64_data_inplace(struct lip_ctx_file *ctx, unsigned size,
                                        double arr[])
{
    if (ctx->error) return;

    lip_pack_1darray_f64_data_inplace((unsigned char *)arr, size);
    ctx->error = fwrite(arr, size * sizeof(double), 1, ctx->fp) != 1;
}
