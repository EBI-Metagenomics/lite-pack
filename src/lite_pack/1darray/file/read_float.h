#ifndef LIP_1DARRAY_READ_FLOAT_H
#define LIP_1DARRAY_READ_FLOAT_H

#include "lite_pack/export.h"
#include "lite_pack/file/file.h"
#include "lite_pack/load_float.h"
#include <stdint.h>

struct lip_file;

/* DATA */

#define __lip_read_1darray_float_data(file, sz, arr)                           \
    _Generic((*arr), float                                                     \
             : lip_read_1darray_f32_data, double                               \
             : lip_read_1darray_f64_data)(file, sz, arr)

LIP_API void lip_read_1darray_f32_data(struct lip_file *file, unsigned size,
                                       float arr[]);

LIP_API void lip_read_1darray_f64_data(struct lip_file *file, unsigned size,
                                       double arr[]);

/* ITEM */

#define __lip_read_1darray_float_item(file, val)                               \
    _Generic((*val), float                                                     \
             : lip_read_1darray_f32_item, double                               \
             : lip_read_1darray_f64_item)(file, val)

static inline void lip_read_1darray_f32_item(struct lip_file *file, float *val)
{
    file->error |= fread(val, sizeof(float), 1, file->fp) != 1;
    file->error |= lip_load_f32((unsigned char *)val, val) == 0;
}

static inline void lip_read_1darray_f64_item(struct lip_file *file, double *val)
{
    file->error |= fread(val, sizeof(double), 1, file->fp) != 1;
    file->error |= lip_load_f64((unsigned char *)val, val) == 0;
}

#endif
