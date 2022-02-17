#ifndef LIP_1DARRAY_1DARRAY_H
#define LIP_1DARRAY_1DARRAY_H

#include "lite_pack/1darray/file/read_float.h"
#include "lite_pack/1darray/file/read_int.h"
#include "lite_pack/1darray/file/write_float.h"
#include "lite_pack/1darray/file/write_int.h"
#include "lite_pack/1darray/file/write_int_data.h"
#include "lite_pack/1darray/file/write_int_data_inplace.h"
#include "lite_pack/1darray/file/write_int_item.h"
#include "lite_pack/1darray/type.h"

/* READ */

LIP_API void lip_read_1darray_size_type(struct lip_file *io, unsigned *size,
                                        uint8_t *type);
#define lip_read_1darray_int_data(i, s, a) __lip_read_1darray_int_data(i, s, a)
#define lip_read_1darray_int_item(i, v) __lip_read_1darray_int_item(i, v)
#define lip_read_1darray_float_data(i, s, a)                                   \
    __lip_read_1darray_float_data(i, s, a)
#define lip_read_1darray_float_item(i, v) __lip_read_1darray_float_item(i, v)

/* WRITE */

#define lip_write_1darray_int(i, s, a) __lip_write_1darray_int(i, s, a)
#define lip_write_1darray_float(i, s, a) __lip_write_1darray_float(i, s, a)

LIP_API void lip_write_1darray_size_type(struct lip_file *io, unsigned size,
                                         uint8_t type);

#define lip_write_1darray_int_data(i, s, a)                                    \
    __lip_write_1darray_int_data(i, s, a)

#define lip_write_1darray_int_data_inplace(i, s, a)                            \
    __lip_write_1darray_int_data_inplace(i, s, a)

#define lip_write_1darray_int_item(i, v) __lip_write_1darray_int_item(i, v)
#define lip_write_1darray_float_data(i, s, a)                                  \
    __lip_write_1darray_float_data(i, s, a)

#define lip_write_1darray_float_data_inplace(i, s, a)                          \
    __lip_write_1darray_float_data_inplace(i, s, a)

#define lip_write_1darray_float_item(i, v) __lip_write_1darray_float_item(i, v)

#endif
