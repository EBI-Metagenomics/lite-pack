#include "lite_pack/io/file.h"
#include "lite_pack/pack_map.h"

void lip_write_map_size(struct lip_io_file *io, unsigned size)
{
    if (io->error) return;

    unsigned sz = lip_pack_map_size(io->buf, size);
    io->error = fwrite(io->buf, sz, 1, io->fp) != 1;
}
