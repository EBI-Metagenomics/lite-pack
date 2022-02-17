#ifndef LIP_1DARRAY_WRITE_FLOAT_H
#define LIP_1DARRAY_WRITE_FLOAT_H

#include "lite_pack/export.h"
#include "lite_pack/file/file.h"
#include "lite_pack/store_float.h"

struct lip_file;

/* SINGLE-CALL */

#define __lip_write_1darray_float(io, size, arr)                               \
    _Generic((*arr), float                                                     \
             : lip_write_1darray_f32, double                                   \
             : lip_write_1darray_f64)(io, size, arr)

LIP_API void lip_write_1darray_f32(struct lip_file *io, unsigned size,
                                   float const arr[]);

LIP_API void lip_write_1darray_f64(struct lip_file *io, unsigned size,
                                   double const arr[]);

/* DATA */

#define __lip_write_1darray_float_data(io, size, arr)                          \
    _Generic((*arr), float                                                     \
             : lip_write_1darray_f32_data, double                              \
             : lip_write_1darray_f64_data)(io, size, arr)

LIP_API void lip_write_1darray_f32_data(struct lip_file *io, unsigned size,
                                        float const arr[]);

LIP_API void lip_write_1darray_f64_data(struct lip_file *io, unsigned size,
                                        double const arr[]);

LIP_API void lip_write_1darray_f32_data_in(struct lip_file *io, unsigned size,
                                           float arr[]);

LIP_API void lip_write_1darray_f64_data_in(struct lip_file *io, unsigned size,
                                           double arr[]);

/* ITEM */

#define __lip_write_1darray_float_item(io, val)                                \
    _Generic((val), float                                                      \
             : lip_write_1darray_f32_item, double                              \
             : lip_write_1darray_f64_item)(io, val)

static inline void lip_write_1darray_f32_item(struct lip_file *io, float val)
{
    io->error |= lip_store_f32_in((unsigned char *)&val) == 0;
    io->error |= fwrite(&val, sizeof(val), 1, io->fp) != 1;
}

static inline void lip_write_1darray_f64_item(struct lip_file *io, double val)
{
    io->error |= lip_store_f64((unsigned char *)&val, val) == 0;
    io->error |= fwrite(&val, sizeof(val), 1, io->fp) != 1;
}

#endif
