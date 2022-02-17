#ifndef LIP_1DARRAY_1DARRAY_H
#define LIP_1DARRAY_1DARRAY_H

#include "lite_pack/1darray/file/read_float.h"
#include "lite_pack/1darray/file/read_int.h"
#include "lite_pack/1darray/file/write_float.h"
#include "lite_pack/1darray/file/write_int.h"
#include "lite_pack/1darray/file/write_int_data.h"
#include "lite_pack/1darray/file/write_int_data_in.h"
#include "lite_pack/1darray/file/write_int_item.h"
#include "lite_pack/1darray/type.h"

/* READ */

LIP_API void lip_read_1darray_size_type(struct lip_file *, unsigned *size,
                                        uint8_t *type);
// lip_read_1darray_float_data(file, size, arr)
// lip_read_1darray_float_item(file, item)
// lip_read_1darray_int_data(file, size, arr)
// lip_read_1darray_int_item(file, item)

/* WRITE */

LIP_API void lip_write_1darray_size_type(struct lip_file *io, unsigned size,
                                         uint8_t type);
// lip_write_1darray_float(file, size, arr)
// lip_write_1darray_float_data(file, size, arr)
// lip_write_1darray_float_data_in(file, size, arr)
// lip_write_1darray_float_item(file, item)
// lip_write_1darray_int(file, size, arr)
// lip_write_1darray_int_data(file, size, arr)
// lip_write_1darray_int_data_in(file, size, arr)
// lip_write_1darray_int_item(file, item)

#endif
