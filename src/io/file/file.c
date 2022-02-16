#include "lite_pack/io/file.h"

int lip_fseek(struct lip_io_file *io, int64_t offset, int whence)
{
    return fseeko(io->fp, offset, whence);
}

int64_t lip_ftell(struct lip_io_file *io) { return (int64_t)ftello(io->fp); }

void lip_rewind(struct lip_io_file *io) { rewind(io->fp); }
