#include "lite_pack/format.h"
#include "lite_pack/io/file.h"
#include "lite_pack/unpack_int.h"

static inline unsigned int_size(enum lip_format fmt)
{
    unsigned sz = 0;
    switch (fmt)
    {
    case LIP_FMT_INT_64:
    case LIP_FMT_UINT_64:
        sz += 2;
        fallthrough;
    case LIP_FMT_INT_32:
    case LIP_FMT_UINT_32:
        sz += 2;
        fallthrough;
    case LIP_FMT_INT_16:
    case LIP_FMT_UINT_16:
        sz += 1;
        fallthrough;
    case LIP_FMT_INT_8:
    case LIP_FMT_UINT_8:
        sz += 1;
        fallthrough;
    default:
        return 0;
    }
}

static inline void read_int(struct lip_io_file *io, unsigned char buf[])
{
    io->error = fread(buf, 1, 1, io->fp) != 1;
    if (io->error) return;

    unsigned sz = 0;
    switch (lip_format(buf))
    {
    case LIP_FMT_INT_64:
    case LIP_FMT_UINT_64:
        sz += 4;
        fallthrough;

    case LIP_FMT_INT_32:
    case LIP_FMT_UINT_32:
        sz += 2;

        fallthrough;
    case LIP_FMT_INT_16:
    case LIP_FMT_UINT_16:
        sz += 1;
        fallthrough;

    case LIP_FMT_INT_8:
    case LIP_FMT_UINT_8:
        sz += 1;
        io->error = fread(buf + 1, sz, 1, io->fp) != 1;
        fallthrough;

    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        break;

    default:
        io->error = true;
    }
}

/* SIGNED */

bool __lip_read_i8(struct lip_io_file *io, int8_t *val)
{
    if (io->error) return false;

    read_int(io, io->buf);
    if (io->error) return false;

    return !(io->error = __lip_unpack_i8(io->buf, val) == 0);
}

bool __lip_read_i16(struct lip_io_file *io, int16_t *val)
{
    if (io->error) return false;

    read_int(io, io->buf);
    if (io->error) return false;

    return !(io->error = __lip_unpack_i16(io->buf, val) == 0);
}

bool __lip_read_i32(struct lip_io_file *io, int32_t *val)
{
    if (io->error) return false;

    read_int(io, io->buf);
    if (io->error) return false;

    return !(io->error = __lip_unpack_i32(io->buf, val) == 0);
}

bool __lip_read_i64(struct lip_io_file *io, int64_t *val)
{
    if (io->error) return false;

    read_int(io, io->buf);
    if (io->error) return false;

    return !(io->error = __lip_unpack_i64(io->buf, val) == 0);
}

/* UNSIGNED */

bool __lip_read_u8(struct lip_io_file *io, uint8_t *val)
{
    if (io->error) return false;

    read_int(io, io->buf);
    if (io->error) return false;

    return !(io->error = __lip_unpack_u8(io->buf, val) == 0);
}

bool __lip_read_u16(struct lip_io_file *io, uint16_t *val)
{
    if (io->error) return false;

    read_int(io, io->buf);
    if (io->error) return false;

    return !(io->error = __lip_unpack_u16(io->buf, val) == 0);
}

bool __lip_read_u32(struct lip_io_file *io, uint32_t *val)
{
    if (io->error) return false;

    read_int(io, io->buf);
    if (io->error) return false;

    return !(io->error = __lip_unpack_u32(io->buf, val) == 0);
}

bool __lip_read_u64(struct lip_io_file *io, uint64_t *val)
{
    if (io->error) return false;

    read_int(io, io->buf);
    if (io->error) return false;

    return !(io->error = __lip_unpack_u64(io->buf, val) == 0);
}
