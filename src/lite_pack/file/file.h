#ifndef LITE_PACK_FILE_FILE_H
#define LITE_PACK_FILE_FILE_H

#include "lite_pack/export.h"
#include "lite_pack/file/read_float.h"
#include "lite_pack/file/read_int.h"
#include "lite_pack/file/write_float.h"
#include "lite_pack/file/write_int.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

struct lip_file
{
    FILE *fp;
    unsigned char buf[9];
    bool error;
};

/* WRITE */

LIP_API bool lip_write_bool(struct lip_file *io, bool val);
#define lip_write_int(io, val) __lip_write_int(io, val)
#define lip_write_float(io, val) __lip_write_float(io, val)
LIP_API bool lip_write_array_size(struct lip_file *, unsigned size);
LIP_API bool lip_write_map_size(struct lip_file *, unsigned size);
LIP_API bool lip_write_str_size(struct lip_file *, unsigned size);
LIP_API bool lip_write_str_data(struct lip_file *, unsigned size,
                                char const str[]);
LIP_API bool lip_write_ext_size_type(struct lip_file *io, unsigned size,
                                     uint8_t type);

/* READ */

LIP_API bool lip_read_bool(struct lip_file *, bool *val);
#define lip_read_int(io, val) __lip_read_int(io, val)
#define lip_read_float(io, val) __lip_read_float(io, val)
LIP_API bool lip_read_array_size(struct lip_file *, unsigned *size);
LIP_API bool lip_read_map_size(struct lip_file *, unsigned *size);
LIP_API bool lip_read_str_size(struct lip_file *, unsigned *size);
LIP_API bool lip_read_str_data(struct lip_file *, unsigned size, char str[]);
LIP_API bool lip_read_ext_size_type(struct lip_file *, unsigned *size,
                                    uint8_t *type);

/* FILE OPERATIONS */

LIP_API int lip_fseek(struct lip_file *io, int64_t offset, int whence);
LIP_API int64_t lip_ftell(struct lip_file *io);
LIP_API void lip_rewind(struct lip_file *io);

/* C-STRING */

static inline bool lip_write_cstr(struct lip_file *io, char const str[])
{
    if (io->error) return false;

    size_t size = strlen(str);
    if (size > INT_MAX) return false;
    lip_write_str_size(io, (unsigned)size);
    return lip_write_str_data(io, (unsigned)size, str);
}

static inline bool lip_read_cstr(struct lip_file *io, unsigned size, char str[])
{
    if (io->error) return false;

    str[0] = 0;
    unsigned sz = 0;
    if (!lip_read_str_size(io, &sz)) return false;

    if (sz > size) return !(io->error = true);
    lip_read_str_data(io, sz, str);
    str[sz] = 0;
    return !io->error;
}

#endif
