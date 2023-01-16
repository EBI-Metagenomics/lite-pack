#include "lip/file/file.h"
#include "lip/pack_map.h"

bool lip_write_map_size(struct lip_file *file, unsigned size)
{
    if (file->error) return false;

    unsigned sz = lip_pack_map_size(file->buf, size);
    return !(file->error = fwrite(file->buf, sz, 1, file->fp) != 1);
}
