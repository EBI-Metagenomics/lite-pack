#include "lite_pack/io/file.h"
#include "lite_pack/pack_map.h"

bool lip_write_map_size(struct lip_file *io, unsigned size)
{
    if (io->error) return false;

    unsigned sz = lip_pack_map_size(io->buf, size);
    return !(io->error = fwrite(io->buf, sz, 1, io->fp) != 1);
}
