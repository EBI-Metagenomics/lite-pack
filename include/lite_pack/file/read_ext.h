#ifndef LITE_PACK_FILE_READ_EXT_H
#define LITE_PACK_FILE_READ_EXT_H

#include "lite_pack/export.h"
#include <stdbool.h>
#include <stdint.h>

struct lip_file;

LIP_API bool lip_read_ext_size_type(struct lip_file *, unsigned *size,
                                    uint8_t *type);

#endif
