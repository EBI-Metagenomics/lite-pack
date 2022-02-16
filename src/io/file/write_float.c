#include "lite_pack/io/file.h"
#include "lite_pack/pack_float.h"

bool __lip_write_f32(struct lip_io_file *io, float val)
{
    if (io->error) return false;

    unsigned sz = __lip_pack_f32(io->buf, val);
    return !(io->error = fwrite(io->buf, sz, 1, io->fp) != 1);
}

bool __lip_write_f64(struct lip_io_file *io, double val)
{
    if (io->error) return false;

    unsigned sz = __lip_pack_f64(io->buf, val);
    return !(io->error = fwrite(io->buf, sz, 1, io->fp) != 1);
}
