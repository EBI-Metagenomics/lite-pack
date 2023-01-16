#ifndef LIP_FILE_READ_OBJECT_H
#define LIP_FILE_READ_OBJECT_H

#include "lip/export.h"
#include <stdbool.h>

struct lip_file;
struct lip_object;

LIP_API bool lip_read_object(struct lip_file *file, struct lip_object *obj);

#endif
