#ifndef LIP_FILE_WRITE_ARRAY_H
#define LIP_FILE_WRITE_ARRAY_H

#include "lip/export.h"
#include <stdbool.h>

struct lip_file;

LIP_API bool lip_write_array_size(struct lip_file *, unsigned size);

#endif
