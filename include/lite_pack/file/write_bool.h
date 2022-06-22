#ifndef LITE_PACK_FILE_WRITE_BOOL_H
#define LITE_PACK_FILE_WRITE_BOOL_H

#include "lite_pack/export.h"
#include <stdbool.h>

struct lip_file;

LIP_API bool lip_write_bool(struct lip_file *file, bool val);

#endif
