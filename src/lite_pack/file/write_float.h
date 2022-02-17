#ifndef LITE_PACK_FILE_WRITE_FLOAT_H
#define LITE_PACK_FILE_WRITE_FLOAT_H

#include "lite_pack/export.h"
#include <stdbool.h>

#define __lip_write_float(f, v)                                                \
    _Generic((v), float : __lip_write_f32, double : __lip_write_f64)(f, v)

struct lip_file;

LIP_API bool __lip_write_f32(struct lip_file *, float val);
LIP_API bool __lip_write_f64(struct lip_file *, double val);

#endif
