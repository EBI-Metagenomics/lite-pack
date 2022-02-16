#include "lite_pack/io/file.h"
#include "lite_pack/pack_array.h"

bool lip_write_array_size(struct lip_io_file *io, unsigned size)
{
    if (io->error) return false;

    unsigned sz = lip_pack_array_size(io->buf, size);
    return !(io->error = fwrite(io->buf, sz, 1, io->fp) != 1);
}
