#ifndef LIP_FILE_WRITE_MAP_H
#define LIP_FILE_WRITE_MAP_H

#include "lip/export.h"
#include <stdbool.h>

struct lip_file;

LIP_API bool lip_write_map_size(struct lip_file *, unsigned size);

#endif
