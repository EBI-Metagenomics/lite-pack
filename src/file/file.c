#include "lite_pack/file/file.h"

int lip_fseek(struct lip_file *file, int64_t offset, int whence)
{
    return fseeko(file->fp, offset, whence);
}

int64_t lip_ftell(struct lip_file *io) { return (int64_t)ftello(io->fp); }

void lip_rewind(struct lip_file *io) { rewind(io->fp); }
