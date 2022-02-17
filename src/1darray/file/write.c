#include "1darray/pack.h"
#include "lite_pack/1darray/1darray.h"
#include "lite_pack/file/file.h"

void lip_write_1darray_size_type(struct lip_file *io, unsigned size,
                                 uint8_t type)
{
    if (io->error) return;

    unsigned sz = pack_1darray_size_type(io->buf, size, type);
    io->error = fwrite(io->buf, sz, 1, io->fp) != 1;
}
