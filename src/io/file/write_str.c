#include "lite_pack/io/file.h"
#include "lite_pack/pack_str.h"

bool lip_write_str_size(struct lip_io_file *io, unsigned size)
{
    if (io->error) return false;

    unsigned sz = lip_pack_str_size(io->buf, size);
    return !(io->error = fwrite(io->buf, sz, 1, io->fp) != 1);
}

bool lip_write_str_data(struct lip_io_file *io, unsigned size, char const str[])
{
    if (io->error) return false;

    return !(io->error = fwrite(str, size, 1, io->fp) != 1);
}
