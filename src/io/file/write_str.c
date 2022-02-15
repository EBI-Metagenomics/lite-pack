#include "lite_pack/io/file.h"
#include "lite_pack/pack_str.h"

void lip_write_str_size(struct lip_io_file *io, unsigned size)
{
    if (io->error) return;

    unsigned sz = lip_pack_str_size(io->buf, size);
    io->error = fwrite(io->buf, sz, 1, io->fp) != 1;
}

void lip_write_str_data(struct lip_io_file *io, unsigned size, char const str[])
{
    if (io->error) return;

    io->error = fwrite(str, size, 1, io->fp) != 1;
}
