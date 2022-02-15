#include "lite_pack/io/file.h"
#include "lite_pack/pack_int.h"

/* SIGNED */

void __lip_write_i8(struct lip_io_file *io, int val)
{
    if (io->error) return;

    unsigned sz = __lip_pack_i8(io->buf, val);
    io->error = fwrite(io->buf, sz, 1, io->fp) != 1;
}

void __lip_write_i16(struct lip_io_file *io, int val)
{
    if (io->error) return;

    unsigned sz = __lip_pack_i16(io->buf, val);
    io->error = fwrite(io->buf, sz, 1, io->fp) != 1;
}

void __lip_write_i32(struct lip_io_file *io, int val)
{
    if (io->error) return;

    unsigned sz = __lip_pack_i32(io->buf, val);
    io->error = fwrite(io->buf, sz, 1, io->fp) != 1;
}

void __lip_write_i64(struct lip_io_file *io, long val)
{
    if (io->error) return;

    unsigned sz = __lip_pack_i64(io->buf, val);
    io->error = fwrite(io->buf, sz, 1, io->fp) != 1;
}

/* UNSIGNED */

void __lip_write_u8(struct lip_io_file *io, unsigned val)
{
    if (io->error) return;

    unsigned sz = __lip_pack_u8(io->buf, val);
    io->error = fwrite(io->buf, sz, 1, io->fp) != 1;
}

void __lip_write_u16(struct lip_io_file *io, unsigned val)
{
    if (io->error) return;

    unsigned sz = __lip_pack_u16(io->buf, val);
    io->error = fwrite(io->buf, sz, 1, io->fp) != 1;
}

void __lip_write_u32(struct lip_io_file *io, unsigned val)
{
    if (io->error) return;

    unsigned sz = __lip_pack_u32(io->buf, val);
    io->error = fwrite(io->buf, sz, 1, io->fp) != 1;
}

void __lip_write_u64(struct lip_io_file *io, unsigned long val)
{
    if (io->error) return;

    unsigned sz = __lip_pack_u64(io->buf, val);
    io->error = fwrite(io->buf, sz, 1, io->fp) != 1;
}
