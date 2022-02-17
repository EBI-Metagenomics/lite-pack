#include "lite_pack/format.h"
#include "lite_pack/io/file.h"
#include "lite_pack/unpack_str.h"

bool lip_read_str_size(struct lip_file *io, unsigned *size)
{
    if (io->error) return false;

    io->error = fread(io->buf, 1, 1, io->fp) != 1;
    if (io->error) return false;

    unsigned sz = 0;
    switch (lip_format(io->buf))
    {
    case LIP_FMT_STR_32:
        sz += 2;
        fallthrough;

    case LIP_FMT_STR_16:
        sz += 1;
        fallthrough;

    case LIP_FMT_STR_8:
        sz += 1;
        io->error = fread(io->buf + 1, sz, 1, io->fp) != 1;
        if (io->error) return false;
        fallthrough;

    case LIP_FMT_FIXSTR:
        break;

    default:
        io->error = true;
        return false;
    }

    return !(io->error = lip_unpack_str_size(io->buf, size) == 0);
}

bool lip_read_str_data(struct lip_file *io, unsigned size, char str[])
{
    if (io->error) return false;

    return !(io->error = fread(str, size, 1, io->fp) != 1);
}
