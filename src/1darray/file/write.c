#include "1darray/pack.h"
#include "lite_pack/1darray/1darray.h"
#include "lite_pack/file/file.h"

bool lip_write_1darray_size_type(struct lip_file *file, unsigned size,
                                 uint8_t type)
{
    if (file->error) return false;

    unsigned sz = pack_1darray_size_type(file->buf, size, type);
    file->error = fwrite(file->buf, sz, 1, file->fp) != 1;

    return !file->error;
}
