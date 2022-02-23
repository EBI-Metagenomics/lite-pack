#include "1darray/unpack.h"
#include "lite_pack/1darray/1darray.h"
#include "lite_pack/file/file.h"

bool lip_read_1darray_size_type(struct lip_file *io, unsigned *size,
                                uint8_t *type)
{
    if (io->error) return false;

    lip_read_ext_size_type(io, size, type);
    io->error = unpack_1darray_size_type(io->buf, size, type) == 0;
    return !io->error;
}
