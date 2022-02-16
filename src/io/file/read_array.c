#include "lite_pack/format.h"
#include "lite_pack/io/file.h"
#include "lite_pack/unpack_array.h"

bool lip_read_array_size(struct lip_io_file *io, unsigned *size)
{
    if (io->error) return false;

    io->error = fread(io->buf, 1, 1, io->fp) != 1;
    if (io->error) return false;

    unsigned sz = 0;
    switch (lip_format(io->buf))
    {
    case LIP_FMT_ARRAY_32:
        sz += 2;
        fallthrough;

    case LIP_FMT_ARRAY_16:
        sz += 2;
        io->error = fread(io->buf + 1, sz, 1, io->fp) != 1;
        if (io->error) return false;
        fallthrough;

    case LIP_FMT_FIXARRAY:
        break;

    default:
        io->error = true;
        return false;
    }

    return !(io->error = lip_unpack_array_size(io->buf, size) == 0);
}
