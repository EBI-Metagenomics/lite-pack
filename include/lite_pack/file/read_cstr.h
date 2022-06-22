#ifndef LITE_PACK_FILE_READ_CSTR_H
#define LITE_PACK_FILE_READ_CSTR_H

#include "lite_pack/export.h"
#include <stdbool.h>

struct lip_file;

LIP_API bool lip_read_cstr(struct lip_file *file, unsigned size, char str[]);

#endif
