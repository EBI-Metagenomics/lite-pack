#include "lite_pack/1darray/write.h"
#include "1darray/pack.h"
#include "lite_pack/io/file.h"

void lip_write_1darray_size_type(struct lip_io_file *io, unsigned size,
                                 uint8_t type)
{
    if (io->error) return;

    unsigned char buf[6] = {0};
    unsigned sz = lip_pack_1darray_size_type(buf, size, type);
    io->error = fwrite(buf, sz, 1, io->fp) != 1;
}
