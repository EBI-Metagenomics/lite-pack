#include "lite_pack/io/file.h"
#include "lite_pack/pack_bool.h"

void lip_write_bool(struct lip_io_file *io, bool val)
{
    if (io->error) return;

    unsigned sz = lip_pack_bool(io->buf, val);
    io->error = fwrite(io->buf, sz, 1, io->fp) != 1;
}
