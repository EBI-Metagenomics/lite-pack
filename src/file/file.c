#include "lite_pack/file/file.h"

int lip_fseek(struct lip_file *file, int64_t offset, int whence)
{
    return fseeko(file->fp, offset, whence);
}

int64_t lip_ftell(struct lip_file *file) { return (int64_t)ftello(file->fp); }

void lip_rewind(struct lip_file *file) { rewind(file->fp); }
