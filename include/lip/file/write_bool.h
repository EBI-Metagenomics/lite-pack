#ifndef LIP_FILE_WRITE_BOOL_H
#define LIP_FILE_WRITE_BOOL_H

#include "lip/export.h"
#include <stdbool.h>

struct lip_file;

LIP_API bool lip_write_bool(struct lip_file *file, bool val);

#endif
