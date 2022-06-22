#include "lite_pack/file/file.h"
#include "lite_pack/pack_float.h"

bool __lip_write_f32(struct lip_file *file, float val)
{
    if (file->error) return false;

    unsigned sz = lip_pack_f32(file->buf, val);
    return !(file->error = fwrite(file->buf, sz, 1, file->fp) != 1);
}

bool __lip_write_f64(struct lip_file *file, double val)
{
    if (file->error) return false;

    unsigned sz = lip_pack_f64(file->buf, val);
    return !(file->error = fwrite(file->buf, sz, 1, file->fp) != 1);
}
