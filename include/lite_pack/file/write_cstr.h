#ifndef LITE_PACK_FILE_WRITE_CSTR_H
#define LITE_PACK_FILE_WRITE_CSTR_H

#include "lite_pack/export.h"
#include <stdbool.h>

struct lip_file;

LIP_API bool lip_write_cstr(struct lip_file *file, char const str[]);

#endif
