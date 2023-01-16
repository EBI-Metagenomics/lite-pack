#ifndef LIP_FILE_READ_BOOL_H
#define LIP_FILE_READ_BOOL_H

#include "lip/export.h"
#include <stdbool.h>

struct lip_file;

LIP_API bool lip_read_bool(struct lip_file *, bool *val);

#endif
