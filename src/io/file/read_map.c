#include "lite_pack/format.h"
#include "lite_pack/io/file.h"
#include "lite_pack/unpack_map.h"

void lip_read_map_size(struct lip_io_file *io, unsigned *size)
{
    if (io->error) return;

    io->error = fread(io->buf, 1, 1, io->fp) != 1;
    if (io->error) return;

    unsigned sz = 0;
    switch (lip_format(io->buf))
    {
    case LIP_FMT_MAP_32:
        sz += 2;
        fallthrough;

    case LIP_FMT_MAP_16:
        sz += 2;
        io->error = fread(io->buf + 1, sz, 1, io->fp) != 1;
        if (io->error) return;
        fallthrough;

    case LIP_FMT_FIXMAP:
        break;

    default:
        io->error = true;
        return;
    }

    io->error = lip_unpack_map_size(io->buf, size) == 0;
}
