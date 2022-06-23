#include "lite_pack/file/file.h"
#include "lite_pack/pack_array.h"

bool lip_write_array_size(struct lip_file *file, unsigned size)
{
    if (file->error) return false;

    unsigned sz = lip_pack_array_size(file->buf, size);
    return !(file->error = fwrite(file->buf, sz, 1, file->fp) * sz != sz);
}
