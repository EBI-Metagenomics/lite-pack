#include "lite_pack/io/file.h"
#include "lite_pack/pack_array.h"

void lip_write_array_size(struct lip_io_file *io, unsigned size)
{
    if (io->error) return;

    unsigned sz = lip_pack_array_size(io->buf, size);
    io->error = fwrite(io->buf, sz, 1, io->fp) != 1;
}
