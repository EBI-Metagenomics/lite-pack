#ifndef LIP_FILE_READ_EXT_H
#define LIP_FILE_READ_EXT_H

#include "lip/export.h"
#include <stdbool.h>
#include <stdint.h>

struct lip_file;

LIP_API bool lip_read_ext_size_type(struct lip_file *, unsigned *size,
                                    uint8_t *type);

#endif
