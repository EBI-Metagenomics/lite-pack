#include "lite_pack/file/read_cstr.h"
#include "lite_pack/file/file.h"
#include "lite_pack/file/read_str.h"

bool lip_read_cstr(struct lip_file *file, unsigned size, char str[])
{
    if (file->error) return false;

    str[0] = 0;
    unsigned sz = 0;
    if (!lip_read_str_size(file, &sz)) return false;

    if (sz > size) return !(file->error = true);
    lip_read_str_data(file, sz, str);
    str[sz] = 0;
    return !file->error;
}
