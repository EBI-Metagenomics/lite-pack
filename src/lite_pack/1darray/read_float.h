#ifndef LIP_1DARRAY_READ_FLOAT_H
#define LIP_1DARRAY_READ_FLOAT_H

#include "lite_pack/export.h"
#include "lite_pack/io/file.h"
#include "lite_pack/load_float.h"
#include <stdint.h>

struct lip_io_file;

/* DATA */

#define __lip_read_1darray_float_data(io, sz, arr)                             \
    _Generic((*arr), float                                                     \
             : lip_read_1darray_f32_data, double                               \
             : lip_read_1darray_f64_data)(io, sz, arr)

LIP_API void lip_read_1darray_f32_data(struct lip_io_file *io, unsigned size,
                                       float arr[]);

LIP_API void lip_read_1darray_f64_data(struct lip_io_file *io, unsigned size,
                                       double arr[]);

/* ITEM */

#define __lip_read_1darray_float_item(io, val)                                 \
    _Generic((*val), float                                                     \
             : lip_read_1darray_f32_item, double                               \
             : lip_read_1darray_f64_item)(io, val)

static inline void lip_read_1darray_f32_item(struct lip_io_file *io, float *val)
{
    io->error |= fread(val, sizeof(float), 1, io->fp) != 1;
    io->error |= lip_load_f32((unsigned char *)val, val) == 0;
}

static inline void lip_read_1darray_f64_item(struct lip_io_file *io,
                                             double *val)
{
    io->error |= fread(val, sizeof(double), 1, io->fp) != 1;
    io->error |= lip_load_f64((unsigned char *)val, val) == 0;
}

#endif
