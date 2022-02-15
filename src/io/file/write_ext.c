#include "lite_pack/io/file.h"
#include "lite_pack/pack_ext.h"

void lip_write_ext_size_type(struct lip_io_file *io, unsigned size,
                             uint8_t type)
{
    if (io->error) return;

    unsigned sz = lip_pack_ext_size_type(io->buf, size, type);
    io->error = fwrite(io->buf, sz, 1, io->fp) != 1;
}
