#include "lite_pack/file/file.h"
#include "lite_pack/format.h"
#include "lite_pack/stdio_unlocked.h"
#include "lite_pack/unpack_ext.h"

bool lip_read_ext_size_type(struct lip_file *file, unsigned *size,
                            uint8_t *type)
{
    if (file->error) return false;

    file->error = lip_fread(file->buf, 1, 1, file->fp) != 1;
    if (file->error) return false;

    unsigned sz = 1;
    switch (lip_format(file->buf[0]))
    {
    case LIP_FMT_EXT_32:
        sz += 2;
        fallthrough;
    case LIP_FMT_EXT_16:
        sz += 1;
        fallthrough;
    case LIP_FMT_EXT_8:
        sz += 1;
        fallthrough;

    case LIP_FMT_FIXEXT_16:
        fallthrough;
    case LIP_FMT_FIXEXT_8:
        fallthrough;
    case LIP_FMT_FIXEXT_4:
        fallthrough;
    case LIP_FMT_FIXEXT_2:
        fallthrough;
    case LIP_FMT_FIXEXT_1:
        file->error = lip_fread(file->buf + 1, sz, 1, file->fp) != 1;
        if (file->error) return false;
        break;

    default:
        file->error = true;
        return false;
    }

    return !(file->error =
                 lip_unpack_ext_size_type(file->buf, size, type) == 0);
}
