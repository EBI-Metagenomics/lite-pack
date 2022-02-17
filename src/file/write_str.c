#include "lite_pack/file/file.h"
#include "lite_pack/pack_str.h"

bool lip_write_str_size(struct lip_file *file, unsigned size)
{
    if (file->error) return false;

    unsigned sz = lip_pack_str_size(file->buf, size);
    return !(file->error = fwrite(file->buf, sz, 1, file->fp) != 1);
}

bool lip_write_str_data(struct lip_file *file, unsigned size, char const str[])
{
    if (file->error) return false;

    return !(file->error = fwrite(str, size, 1, file->fp) != 1);
}
