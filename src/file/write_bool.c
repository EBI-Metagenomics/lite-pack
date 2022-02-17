#include "lite_pack/file/file.h"
#include "lite_pack/pack_bool.h"

bool lip_write_bool(struct lip_file *file, bool val)
{
    if (file->error) return false;

    unsigned sz = lip_pack_bool(file->buf, val);
    return !(file->error = fwrite(file->buf, sz, 1, file->fp) != 1);
}
