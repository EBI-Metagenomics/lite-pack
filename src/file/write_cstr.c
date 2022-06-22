#include "lite_pack/file/file.h"
#include "lite_pack/file/write_str.h"
#include <limits.h>
#include <string.h>

bool lip_write_cstr(struct lip_file *file, char const str[])
{
    if (file->error) return false;

    size_t size = strlen(str);
    if (size > INT_MAX) return false;
    lip_write_str_size(file, (unsigned)size);
    return lip_write_str_data(file, (unsigned)size, str);
}
