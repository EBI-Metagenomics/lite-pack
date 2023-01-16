#ifndef LIP_FILE_WRITE_CSTR_H
#define LIP_FILE_WRITE_CSTR_H

#include "lip/export.h"
#include <stdbool.h>

struct lip_file;

LIP_API bool lip_write_cstr(struct lip_file *file, char const str[]);

#endif
