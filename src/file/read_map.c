#include "lip/file/file.h"
#include "lip/format.h"
#include "lip/stdio_unlocked.h"
#include "lip/unpack_map.h"

bool lip_read_map_size(struct lip_file *file, unsigned *size)
{
    if (file->error) return false;

    file->error = lip_fread(file->buf, 1, 1, file->fp) != 1;
    if (file->error) return false;

    unsigned sz = 0;
    switch (lip_format(file->buf[0]))
    {
    case LIP_FMT_MAP_32:
        sz += 2;
        fallthrough;

    case LIP_FMT_MAP_16:
        sz += 2;
        file->error = lip_fread(file->buf + 1, sz, 1, file->fp) != 1;
        if (file->error) return false;
        fallthrough;

    case LIP_FMT_FIXMAP:
        break;

    default:
        file->error = true;
        return false;
    }

    return !(file->error = lip_unpack_map_size(file->buf, size) == 0);
}
