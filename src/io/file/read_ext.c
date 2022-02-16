#include "lite_pack/format.h"
#include "lite_pack/io/file.h"
#include "lite_pack/unpack_ext.h"

bool lip_read_ext_size_type(struct lip_io_file *io, unsigned *size,
                            uint8_t *type)
{
    if (io->error) return false;

    io->error = fread(io->buf, 1, 1, io->fp) != 1;
    if (io->error) return false;

    unsigned sz = 1;
    switch (lip_format(io->buf))
    {
    case LIP_FMT_FIXEXT_16:
        fallthrough;
    case LIP_FMT_FIXEXT_8:
        fallthrough;
    case LIP_FMT_FIXEXT_4:
        fallthrough;
    case LIP_FMT_FIXEXT_2:
        fallthrough;
    case LIP_FMT_FIXEXT_1:
        fallthrough;

    case LIP_FMT_EXT_32:
        sz += 2;
        fallthrough;
    case LIP_FMT_EXT_16:
        sz += 1;
        fallthrough;
    case LIP_FMT_EXT_8:
        sz += 1;
        io->error = fread(io->buf + 1, sz, 1, io->fp) != 1;
        if (io->error) return false;
        break;

    default:
        io->error = true;
        return false;
    }

    return !(io->error = lip_unpack_ext_size_type(io->buf, size, type) == 0);
}
