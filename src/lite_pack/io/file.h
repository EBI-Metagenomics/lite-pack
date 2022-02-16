#ifndef LIP_IO_FILE_H
#define LIP_IO_FILE_H

#include "lite_pack/export.h"
#include "lite_pack/io/file/read_float.h"
#include "lite_pack/io/file/read_int.h"
#include "lite_pack/io/file/write_float.h"
#include "lite_pack/io/file/write_int.h"
#include <stdbool.h>
#include <stdio.h>

struct lip_io_file
{
    FILE *fp;
    unsigned char buf[9];
    bool error;
};

/* WRITE */

LIP_API bool lip_write_bool(struct lip_io_file *io, bool val);
#define lip_write_int(io, val) __lip_write_int(io, val)
#define lip_write_float(io, val) __lip_write_float(io, val)
LIP_API bool lip_write_array_size(struct lip_io_file *, unsigned size);
LIP_API bool lip_write_map_size(struct lip_io_file *, unsigned size);
LIP_API bool lip_write_str_size(struct lip_io_file *, unsigned size);
LIP_API bool lip_write_str_data(struct lip_io_file *, unsigned size,
                                char const str[]);
LIP_API bool lip_write_ext_size_type(struct lip_io_file *io, unsigned size,
                                     uint8_t type);

/* READ */

LIP_API bool lip_read_bool(struct lip_io_file *, bool *val);
#define lip_read_int(io, val) __lip_read_int(io, val)
#define lip_read_float(io, val) __lip_read_float(io, val)
LIP_API bool lip_read_array_size(struct lip_io_file *, unsigned *size);
LIP_API bool lip_read_map_size(struct lip_io_file *, unsigned *size);
LIP_API bool lip_read_str_size(struct lip_io_file *, unsigned *size);
LIP_API bool lip_read_str_data(struct lip_io_file *, unsigned size, char str[]);
LIP_API bool lip_read_ext_size_type(struct lip_io_file *, unsigned *size,
                                    uint8_t *type);

LIP_API int lip_fseek(struct lip_io_file *io, int64_t offset, int whence);
LIP_API int64_t lip_ftell(struct lip_io_file *io);
LIP_API void lip_rewind(struct lip_io_file *io);

#endif
