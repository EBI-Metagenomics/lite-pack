#ifndef LIP_FILE_WRITE_EXT_H
#define LIP_FILE_WRITE_EXT_H

#include "lip/export.h"
#include <stdbool.h>
#include <stdint.h>

struct lip_file;

LIP_API bool lip_write_ext_size_type(struct lip_file *file, unsigned size,
                                     uint8_t type);

#endif
