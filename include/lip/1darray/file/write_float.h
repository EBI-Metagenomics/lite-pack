#ifndef LIP_1DARRAY_FILE_WRITE_FLOAT_H
#define LIP_1DARRAY_FILE_WRITE_FLOAT_H

#include "lip/export.h"
#include "lip/file/file.h"
#include "lip/store_float.h"

struct lip_file;

/* SINGLE-CALL */

#define lip_write_1darray_float(file, size, arr)                               \
    _Generic((*arr), float                                                     \
             : lip_write_1darray_f32, double                                   \
             : lip_write_1darray_f64)(file, size, arr)

LIP_API bool lip_write_1darray_f32(struct lip_file *file, unsigned size,
                                   float const arr[]);

LIP_API bool lip_write_1darray_f64(struct lip_file *file, unsigned size,
                                   double const arr[]);

/* DATA */

#define lip_write_1darray_float_data(file, size, arr)                          \
    _Generic((*arr), float                                                     \
             : lip_write_1darray_f32_data, double                              \
             : lip_write_1darray_f64_data)(file, size, arr)

LIP_API bool lip_write_1darray_f32_data(struct lip_file *file, unsigned size,
                                        float const arr[]);

LIP_API bool lip_write_1darray_f64_data(struct lip_file *file, unsigned size,
                                        double const arr[]);

#define lip_write_1darray_float_data_in(file, size, arr)                       \
    _Generic((*arr), float                                                     \
             : lip_write_1darray_f32_data_in, double                           \
             : lip_write_1darray_f64_data_in)(file, size, arr)

LIP_API bool lip_write_1darray_f32_data_in(struct lip_file *file, unsigned size,
                                           float arr[]);

LIP_API bool lip_write_1darray_f64_data_in(struct lip_file *file, unsigned size,
                                           double arr[]);

/* ITEM */

#define lip_write_1darray_float_item(file, item)                               \
    _Generic((item), float                                                     \
             : lip_write_1darray_f32_item, double                              \
             : lip_write_1darray_f64_item)(file, item)

static inline bool lip_write_1darray_f32_item(struct lip_file *file, float item)
{
    file->error |= lip_store_f32_in((unsigned char *)&item) == 0;
    file->error |= fwrite(&item, sizeof(item), 1, file->fp) != 1;
    return !file->error;
}

static inline bool lip_write_1darray_f64_item(struct lip_file *file,
                                              double item)
{
    file->error |= lip_store_f64((unsigned char *)&item, item) == 0;
    file->error |= fwrite(&item, sizeof(item), 1, file->fp) != 1;
    return !file->error;
}

#endif
