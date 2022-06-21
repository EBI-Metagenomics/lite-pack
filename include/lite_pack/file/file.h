#ifndef LITE_PACK_FILE_FILE_H
#define LITE_PACK_FILE_FILE_H

#include "lite_pack/export.h"
#include "lite_pack/file/read_float.h"
#include "lite_pack/file/read_int.h"
#include "lite_pack/file/write_float.h"
#include "lite_pack/file/write_int.h"
#include <stdbool.h>
#include <stdio.h>

struct lip_file
{
    FILE *fp;
    unsigned char buf[9];
    bool error;
};

LIP_API void lip_file_init(struct lip_file *file, FILE *fp);

LIP_API FILE *lip_file_ptr(struct lip_file *file);

LIP_API bool lip_file_skip(struct lip_file *file);

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

/* C-STRING */

LIP_API bool lip_write_cstr(struct lip_file *file, char const str[]);
LIP_API bool lip_read_cstr(struct lip_file *file, unsigned size, char str[]);

#endif
