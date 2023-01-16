#include "lip/file/file.h"
#include "lip/stdio_unlocked.h"
#include "lip/unpack_bool.h"

bool lip_read_bool(struct lip_file *file, bool *val)
{
    if (file->error) return false;

    file->error = lip_fread(file->buf, 1, 1, file->fp) != 1;
    if (file->error) return false;

    return !(file->error = lip_unpack_bool(file->buf, val) == 0);
}
