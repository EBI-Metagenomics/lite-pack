#include "lite_pack/file/file.h"
#include "lite_pack/format.h"
#include "lite_pack/unpack_str.h"

bool lip_read_str_size(struct lip_file *file, unsigned *size)
{
    if (file->error) return false;

    file->error = fread(file->buf, 1, 1, file->fp) != 1;
    if (file->error) return false;

    unsigned sz = 0;
    switch (lip_format(file->buf))
    {
    case LIP_FMT_STR_32:
        sz += 2;
        fallthrough;

    case LIP_FMT_STR_16:
        sz += 1;
        fallthrough;

    case LIP_FMT_STR_8:
        sz += 1;
        file->error = fread(file->buf + 1, sz, 1, file->fp) != 1;
        if (file->error) return false;
        fallthrough;

    case LIP_FMT_FIXSTR:
        break;

    default:
        file->error = true;
        return false;
    }

    return !(file->error = lip_unpack_str_size(file->buf, size) == 0);
}

bool lip_read_str_data(struct lip_file *io, unsigned size, char str[])
{
    if (io->error) return false;

    return !(io->error = fread(str, size, 1, io->fp) != 1);
}
