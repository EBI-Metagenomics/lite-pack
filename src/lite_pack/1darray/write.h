#ifndef LIP_1DARRAY_WRITE_H
#define LIP_1DARRAY_WRITE_H

#include "lite_pack/export.h"
#include "lite_pack/1darray/write_float.h"
#include "lite_pack/1darray/write_float_inplace.h"
#include "lite_pack/1darray/write_int.h"
#include "lite_pack/1darray/write_int_inplace.h"
#include <stdint.h>

LIP_API void lip_write_1darray_size_type(struct lip_io_file *io,
                                         unsigned size, uint8_t type);
#define lip_write_1darray_int_data(io, sz, arr)                               \
    __lip_write_1darray_int_data(io, sz, arr)
#define lip_write_1darray_int_data_inplace(io, sz, arr)                       \
    __lip_write_1darray_int_data_inplace(io, sz, arr)
#define lip_write_1darray_float(io, sz, arr)                                  \
    __lip_write_1darray_float(io, sz, arr)
#define lip_write_1darray_float_inplace(io, sz, arr)                          \
    __lip_write_1darray_float_inplace(io, sz, arr)

#endif
