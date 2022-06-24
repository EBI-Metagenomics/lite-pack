#ifndef LITE_PACK_FILE_WRITE_OBJECT_H
#define LITE_PACK_FILE_WRITE_OBJECT_H

#include "lite_pack/export.h"
#include <stdbool.h>

struct lip_file;
struct lip_object;

LIP_API bool lip_write_object(struct lip_file *file,
                              struct lip_object const *obj);

#endif
