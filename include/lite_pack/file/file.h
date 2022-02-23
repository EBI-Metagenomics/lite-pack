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

static inline void lip_file_init(struct lip_file *file, FILE *fp)
{
    file->fp = fp;
    memset(file->buf, 0, 9);
    file->error = 0;
}

/* WRITE */

LIP_API bool lip_write_bool(struct lip_file *file, bool val);
#define lip_write_int(file, val) __lip_write_int(file, val)
#define lip_write_float(file, val) __lip_write_float(file, val)
LIP_API bool lip_write_array_size(struct lip_file *, unsigned size);
LIP_API bool lip_write_map_size(struct lip_file *, unsigned size);
LIP_API bool lip_write_str_size(struct lip_file *, unsigned size);
LIP_API bool lip_write_str_data(struct lip_file *, unsigned size,
                                char const str[]);
LIP_API bool lip_write_ext_size_type(struct lip_file *file, unsigned size,
                                     uint8_t type);

/* READ */

LIP_API bool lip_read_bool(struct lip_file *, bool *val);
#define lip_read_int(file, val) __lip_read_int(file, val)
#define lip_read_float(file, val) __lip_read_float(file, val)
LIP_API bool lip_read_array_size(struct lip_file *, unsigned *size);
LIP_API bool lip_read_map_size(struct lip_file *, unsigned *size);
LIP_API bool lip_read_str_size(struct lip_file *, unsigned *size);
LIP_API bool lip_read_str_data(struct lip_file *, unsigned size, char str[]);
LIP_API bool lip_read_ext_size_type(struct lip_file *, unsigned *size,
                                    uint8_t *type);

/* FILE OPERATIONS */

LIP_API int lip_fseek(struct lip_file *file, int64_t offset, int whence);
LIP_API int64_t lip_ftell(struct lip_file *file);
LIP_API void lip_rewind(struct lip_file *file);

/* C-STRING */

static inline bool lip_write_cstr(struct lip_file *file, char const str[])
{
    if (file->error) return false;

    size_t size = strlen(str);
    if (size > INT_MAX) return false;
    lip_write_str_size(file, (unsigned)size);
    return lip_write_str_data(file, (unsigned)size, str);
}

static inline bool lip_read_cstr(struct lip_file *file, unsigned size,
                                 char str[])
{
    if (file->error) return false;

    str[0] = 0;
    unsigned sz = 0;
    if (!lip_read_str_size(file, &sz)) return false;

    if (sz > size) return !(file->error = true);
    lip_read_str_data(file, sz, str);
    str[sz] = 0;
    return !file->error;
}

#endif
