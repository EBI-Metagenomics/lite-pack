#ifndef LITE_PACK_1DARRAY_FILE_WRITE_INT_ITEM_H
#define LITE_PACK_1DARRAY_FILE_WRITE_INT_ITEM_H

#include "lite_pack/export.h"
#include "lite_pack/file/file.h"
#include "lite_pack/store_int.h"
#include <stdint.h>

struct lip_file;

#define __lip_write_1darray_signed_item(f, i)                                  \
    sizeof(typeof(i)) == 1   ? lip_write_1darray_i8_item(f, (int8_t)(i))       \
    : sizeof(typeof(i)) == 2 ? lip_write_1darray_i16_item(f, (int16_t)(i))     \
    : sizeof(typeof(i)) == 4 ? lip_write_1darray_i32_item(f, (int32_t)(i))     \
    : sizeof(typeof(i)) == 8 ? lip_write_1darray_i64_item(f, (int64_t)(i))     \
                             : 0

#define __lip_write_1darray_unsigned_item(f, i)                                \
    sizeof(typeof(i)) == 1   ? lip_write_1darray_u8_item(f, (uint8_t)(i))      \
    : sizeof(typeof(i)) == 2 ? lip_write_1darray_u16_item(f, (uint16_t)(i))    \
    : sizeof(typeof(i)) == 4 ? lip_write_1darray_u32_item(f, (uint32_t)(i))    \
    : sizeof(typeof(i)) == 8 ? lip_write_1darray_u64_item(f, (uint64_t)(i))    \
                             : 0U

#define lip_write_1darray_int_item(f, i)                                       \
    _Generic((i), signed char                                                  \
             : __lip_write_1darray_signed_item(f, i), signed short             \
             : __lip_write_1darray_signed_item(f, i), signed int               \
             : __lip_write_1darray_signed_item(f, i), signed long              \
             : __lip_write_1darray_signed_item(f, i), signed long long         \
             : __lip_write_1darray_signed_item(f, i), unsigned char            \
             : __lip_write_1darray_unsigned_item(f, i), unsigned short         \
             : __lip_write_1darray_unsigned_item(f, i), unsigned int           \
             : __lip_write_1darray_unsigned_item(f, i), unsigned long          \
             : __lip_write_1darray_unsigned_item(f, i), unsigned long long     \
             : __lip_write_1darray_unsigned_item(f, i))

/* SIGNED */

static inline bool lip_write_1darray_i8_item(struct lip_file *io, int8_t val)
{
    io->error |= lip_store_i8_in((unsigned char *)&val) == 0;
    io->error |= fwrite(&val, sizeof(int8_t), 1, io->fp) != 1;
    return !io->error;
}

static inline bool lip_write_1darray_i16_item(struct lip_file *io, int16_t val)
{
    io->error |= lip_store_i16_in((unsigned char *)&val) == 0;
    io->error |= fwrite(&val, sizeof(int16_t), 1, io->fp) != 1;
    return !io->error;
}

static inline bool lip_write_1darray_i32_item(struct lip_file *io, int32_t val)
{
    io->error |= lip_store_i32_in((unsigned char *)&val) == 0;
    io->error |= fwrite(&val, sizeof(int32_t), 1, io->fp) != 1;
    return !io->error;
}

static inline bool lip_write_1darray_i64_item(struct lip_file *io, int64_t val)
{
    io->error |= lip_store_i64_in((unsigned char *)&val) == 0;
    io->error |= fwrite(&val, sizeof(int64_t), 1, io->fp) != 1;
    return !io->error;
}

/* UNSIGNED */

static inline bool lip_write_1darray_u8_item(struct lip_file *io, uint8_t val)
{
    io->error |= lip_store_u8_in((unsigned char *)&val) == 0;
    io->error |= fwrite(&val, sizeof(uint8_t), 1, io->fp) != 1;
    return !io->error;
}

static inline bool lip_write_1darray_u16_item(struct lip_file *io, uint16_t val)
{
    io->error |= lip_store_u16_in((unsigned char *)&val) == 0;
    io->error |= fwrite(&val, sizeof(uint16_t), 1, io->fp) != 1;
    return !io->error;
}

static inline bool lip_write_1darray_u32_item(struct lip_file *io, uint32_t val)
{
    io->error |= lip_store_u32_in((unsigned char *)&val) == 0;
    io->error |= fwrite(&val, sizeof(uint32_t), 1, io->fp) != 1;
    return !io->error;
}

static inline bool lip_write_1darray_u64_item(struct lip_file *io, uint64_t val)
{
    io->error |= lip_store_u64_in((unsigned char *)&val) == 0;
    io->error |= fwrite(&val, sizeof(uint64_t), 1, io->fp) != 1;
    return !io->error;
}

#endif
