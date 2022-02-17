#include "lite_pack/file/file.h"
#include "lite_pack/format.h"
#include "lite_pack/unpack_array.h"

bool lip_read_array_size(struct lip_file *file, unsigned *size)
{
    if (file->error) return false;

    file->error = fread(file->buf, 1, 1, file->fp) != 1;
    if (file->error) return false;

    unsigned sz = 0;
    switch (lip_format(file->buf))
    {
    case LIP_FMT_ARRAY_32:
        sz += 2;
        fallthrough;

    case LIP_FMT_ARRAY_16:
        sz += 2;
        file->error = fread(file->buf + 1, sz, 1, file->fp) != 1;
        if (file->error) return false;
        fallthrough;

    case LIP_FMT_FIXARRAY:
        break;

    default:
        file->error = true;
        return false;
    }

    return !(file->error = lip_unpack_array_size(file->buf, size) == 0);
}
