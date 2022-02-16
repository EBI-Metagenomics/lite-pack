#include "lite_pack/io/file.h"
#include "lite_pack/unpack_bool.h"

bool lip_read_bool(struct lip_io_file *io, bool *val)
{
    if (io->error) return false;

    io->error = fread(io->buf, 1, 1, io->fp) != 1;
    if (io->error) return false;

    return !(io->error = lip_unpack_bool(io->buf, val) == 0);
}
