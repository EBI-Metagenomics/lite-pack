#ifndef LIP_IO_FILE_WRITE_FLOAT_H
#define LIP_IO_FILE_WRITE_FLOAT_H

#include "lite_pack/export.h"

#define __lip_write_float(ctx, val)                                            \
    _Generic((val), float : __lip_write_f32, double : __lip_write_f64)(ctx, val)

struct lip_ctx_file;

LIP_API void __lip_write_f32(struct lip_ctx_file *ctx, float val);
LIP_API void __lip_write_f64(struct lip_ctx_file *ctx, double val);

#endif
