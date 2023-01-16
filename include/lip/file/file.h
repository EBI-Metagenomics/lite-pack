#ifndef LIP_FILE_FILE_H
#define LIP_FILE_FILE_H

#include "lip/export.h"
#include <stdbool.h>
#include <stdio.h>

struct lip_file
{
    FILE *fp;
    unsigned char buf[9];
    bool error;
};

LIP_API void lip_file_init(struct lip_file *file, FILE *fp);
LIP_API FILE *lip_file_ptr(struct lip_file *file);
LIP_API bool lip_file_skip(struct lip_file *file);
LIP_API bool lip_file_error(struct lip_file const *file);

#endif
