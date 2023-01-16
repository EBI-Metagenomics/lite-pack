#include "lip/file/file.h"
#include "lip/pack_ext.h"

bool lip_write_ext_size_type(struct lip_file *file, unsigned size, uint8_t type)
{
    if (file->error) return false;

    unsigned sz = lip_pack_ext_size_type(file->buf, size, type);
    return !(file->error = fwrite(file->buf, sz, 1, file->fp) != 1);
}
