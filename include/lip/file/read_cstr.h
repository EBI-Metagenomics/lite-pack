#ifndef LIP_FILE_READ_CSTR_H
#define LIP_FILE_READ_CSTR_H

#include "lip/export.h"
#include <stdbool.h>

struct lip_file;

LIP_API bool lip_read_cstr(struct lip_file *file, unsigned size, char str[]);

#endif
