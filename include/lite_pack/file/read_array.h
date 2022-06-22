#ifndef LITE_PACK_FILE_READ_ARRAY_H
#define LITE_PACK_FILE_READ_ARRAY_H

#include "lite_pack/export.h"
#include <stdbool.h>

struct lip_file;

LIP_API bool lip_read_array_size(struct lip_file *, unsigned *size);

#endif
