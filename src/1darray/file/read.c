#include "1darray/unpack.h"
#include "lip/1darray/1darray.h"
#include "lip/file/read_ext.h"

bool lip_read_1darray_size_type(struct lip_file *file, unsigned *size,
                                enum lip_1darray_type *type)
{
    if (file->error) return false;

    unsigned sz = 0;
    uint8_t typ = 0;
    file->error = !lip_read_ext_size_type(file, &sz, &typ);
    if (file->error) return false;

    file->error = unpack_1darray_size_type(file->buf, size, type) == 0;
    return !file->error;
}
