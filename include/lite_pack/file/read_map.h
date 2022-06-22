#ifndef LITE_PACK_FILE_READ_MAP_H
#define LITE_PACK_FILE_READ_MAP_H

#include "lite_pack/export.h"
#include <stdbool.h>

struct lip_file;

LIP_API bool lip_read_map_size(struct lip_file *, unsigned *size);

#endif
