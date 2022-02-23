#include "1darray/unpack.h"
#include "lite_pack/1darray/1darray.h"
#include "lite_pack/file/file.h"

bool lip_read_1darray_size_type(struct lip_file *file, unsigned *size,
                                uint8_t *type)
{
    if (file->error) return false;

    lip_read_ext_size_type(io, size, type);
    file->error = unpack_1darray_size_type(file->buf, size, type) == 0;
    return !file->error;
}
