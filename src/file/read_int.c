#include "lite_pack/file/file.h"
#include "lite_pack/format.h"
#include "lite_pack/stdio_unlocked.h"
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

static inline void read_int(struct lip_file *file, unsigned char buf[])
{
    file->error = lip_fread(buf, 1, 1, file->fp) != 1;
    if (file->error) return;

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
        file->error = lip_fread(buf + 1, sz, 1, file->fp) != 1;
        fallthrough;

    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        break;

    default:
        file->error = true;
    }
}

/* SIGNED */

bool __lip_read_i8(struct lip_file *file, int8_t *val)
{
    if (file->error) return false;

    read_int(file, file->buf);
    if (file->error) return false;

    return !(file->error = __lip_unpack_i8(file->buf, val) == 0);
}

bool __lip_read_i16(struct lip_file *file, int16_t *val)
{
    if (file->error) return false;

    read_int(file, file->buf);
    if (file->error) return false;

    return !(file->error = __lip_unpack_i16(file->buf, val) == 0);
}

bool __lip_read_i32(struct lip_file *file, int32_t *val)
{
    if (file->error) return false;

    read_int(file, file->buf);
    if (file->error) return false;

    return !(file->error = __lip_unpack_i32(file->buf, val) == 0);
}

bool __lip_read_i64(struct lip_file *file, int64_t *val)
{
    if (file->error) return false;

    read_int(file, file->buf);
    if (file->error) return false;

    return !(file->error = __lip_unpack_i64(file->buf, val) == 0);
}

/* UNSIGNED */

bool __lip_read_u8(struct lip_file *file, uint8_t *val)
{
    if (file->error) return false;

    read_int(file, file->buf);
    if (file->error) return false;

    return !(file->error = __lip_unpack_u8(file->buf, val) == 0);
}

bool __lip_read_u16(struct lip_file *file, uint16_t *val)
{
    if (file->error) return false;

    read_int(file, file->buf);
    if (file->error) return false;

    return !(file->error = __lip_unpack_u16(file->buf, val) == 0);
}

bool __lip_read_u32(struct lip_file *file, uint32_t *val)
{
    if (file->error) return false;

    read_int(file, file->buf);
    if (file->error) return false;

    return !(file->error = __lip_unpack_u32(file->buf, val) == 0);
}

bool __lip_read_u64(struct lip_file *file, uint64_t *val)
{
    if (file->error) return false;

    read_int(file, file->buf);
    if (file->error) return false;

    return !(file->error = __lip_unpack_u64(file->buf, val) == 0);
}
