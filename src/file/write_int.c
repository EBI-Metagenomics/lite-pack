#include "lip/file/file.h"
#include "lip/pack_int.h"

/* SIGNED */

bool __lip_write_i8(struct lip_file *file, int val)
{
    if (file->error) return false;

    unsigned sz = lip_pack_i8(file->buf, val);
    return !(file->error = fwrite(file->buf, sz, 1, file->fp) != 1);
}

bool __lip_write_i16(struct lip_file *file, int val)
{
    if (file->error) return false;

    unsigned sz = lip_pack_i16(file->buf, val);
    return !(file->error = fwrite(file->buf, sz, 1, file->fp) != 1);
}

bool __lip_write_i32(struct lip_file *file, int val)
{
    if (file->error) return false;

    unsigned sz = lip_pack_i32(file->buf, val);
    return !(file->error = fwrite(file->buf, sz, 1, file->fp) != 1);
}

bool __lip_write_i64(struct lip_file *file, long val)
{
    if (file->error) return false;

    unsigned sz = lip_pack_i64(file->buf, val);
    return !(file->error = fwrite(file->buf, sz, 1, file->fp) != 1);
}

/* UNSIGNED */

bool __lip_write_u8(struct lip_file *file, unsigned val)
{
    if (file->error) return false;

    unsigned sz = lip_pack_u8(file->buf, val);
    return !(file->error = fwrite(file->buf, sz, 1, file->fp) != 1);
}

bool __lip_write_u16(struct lip_file *file, unsigned val)
{
    if (file->error) return false;

    unsigned sz = lip_pack_u16(file->buf, val);
    return !(file->error = fwrite(file->buf, sz, 1, file->fp) != 1);
}

bool __lip_write_u32(struct lip_file *file, unsigned val)
{
    if (file->error) return false;

    unsigned sz = lip_pack_u32(file->buf, val);
    return !(file->error = fwrite(file->buf, sz, 1, file->fp) != 1);
}

bool __lip_write_u64(struct lip_file *file, unsigned long val)
{
    if (file->error) return false;

    unsigned sz = lip_pack_u64(file->buf, val);
    return !(file->error = fwrite(file->buf, sz, 1, file->fp) != 1);
}
