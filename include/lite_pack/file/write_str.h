#ifndef LITE_PACK_FILE_WRITE_STR_H
#define LITE_PACK_FILE_WRITE_STR_H

#include "lite_pack/export.h"
#include <stdbool.h>

struct lip_file;

LIP_API bool lip_write_str_size(struct lip_file *, unsigned size);
LIP_API bool lip_write_str_data(struct lip_file *, unsigned size,
                                char const str[]);

#endif
