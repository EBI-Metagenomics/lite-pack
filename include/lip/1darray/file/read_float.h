#ifndef LIP_1DARRAY_FILE_READ_FLOAT_H
#define LIP_1DARRAY_FILE_READ_FLOAT_H

#include "lip/export.h"
#include "lip/file/file.h"
#include "lip/load_float.h"
#include "lip/stdio_unlocked.h"
#include <stdint.h>

struct lip_file;

/* DATA */

#define lip_read_1darray_float_data(file, sz, arr)                             \
    _Generic((*arr), float                                                     \
             : lip_read_1darray_f32_data, double                               \
             : lip_read_1darray_f64_data)(file, sz, arr)

LIP_API bool lip_read_1darray_f32_data(struct lip_file *file, unsigned size,
                                       float arr[]);

LIP_API bool lip_read_1darray_f64_data(struct lip_file *file, unsigned size,
                                       double arr[]);

/* ITEM */

#define lip_read_1darray_float_item(file, item)                                \
    _Generic((*item), float                                                    \
             : lip_read_1darray_f32_item, double                               \
             : lip_read_1darray_f64_item)(file, item)

static inline bool lip_read_1darray_f32_item(struct lip_file *file, float *item)
{
    file->error |= lip_fread(item, sizeof(float), 1, file->fp) != 1;
    file->error |= lip_load_f32((unsigned char *)item, item) == 0;
    return !file->error;
}

static inline bool lip_read_1darray_f64_item(struct lip_file *file,
                                             double *item)
{
    file->error |= lip_fread(item, sizeof(double), 1, file->fp) != 1;
    file->error |= lip_load_f64((unsigned char *)item, item) == 0;
    return !file->error;
}

#endif
