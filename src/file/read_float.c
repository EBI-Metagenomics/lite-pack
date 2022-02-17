#include "lite_pack/file/file.h"
#include "lite_pack/format.h"
#include "lite_pack/stdio_unlocked.h"
#include "lite_pack/unpack_float.h"

bool __lip_read_f32(struct lip_file *file, float *val)
{
    if (file->error) return false;

    file->error = lip_fread(file->buf, 1, 1, file->fp) != 1;
    if (file->error) return false;

    if (lip_format(file->buf) != LIP_FMT_FLOAT_32)
    {
        file->error = true;
        return false;
    }

    file->error = lip_fread(file->buf + 1, 4, 1, file->fp) != 1;
    if (file->error) return false;

    return !(file->error = __lip_unpack_f32(file->buf, val) == 0);
}

bool __lip_read_f64(struct lip_file *file, double *val)
{
    if (file->error) return false;

    file->error = lip_fread(file->buf, 1, 1, file->fp) != 1;
    if (file->error) return false;

    unsigned sz = 0;
    if (lip_format(file->buf) == LIP_FMT_FLOAT_32)
    {
        sz = 4;
    }
    else if (lip_format(file->buf) == LIP_FMT_FLOAT_64)
    {
        sz = 8;
    }
    else
    {
        file->error = true;
        return false;
    }

    file->error = lip_fread(file->buf + 1, sz, 1, file->fp) != 1;
    if (file->error) return false;

    return !(file->error = __lip_unpack_f64(file->buf, val) == 0);
}
