#include "lite_pack/format.h"
#include "lite_pack/io/file.h"
#include "lite_pack/unpack_map.h"

bool lip_read_map_size(struct lip_io_file *io, unsigned *size)
{
    if (io->error) return false;

    io->error = fread(io->buf, 1, 1, io->fp) != 1;
    if (io->error) return false;

    unsigned sz = 0;
    switch (lip_format(io->buf))
    {
    case LIP_FMT_MAP_32:
        sz += 2;
        fallthrough;

    case LIP_FMT_MAP_16:
        sz += 2;
        io->error = fread(io->buf + 1, sz, 1, io->fp) != 1;
        if (io->error) return false;
        fallthrough;

    case LIP_FMT_FIXMAP:
        break;

    default:
        io->error = true;
        return false;
    }

    return !(io->error = lip_unpack_map_size(io->buf, size) == 0);
}
