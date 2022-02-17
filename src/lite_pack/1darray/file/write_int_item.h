#ifndef LIP_1DARRAY_WRITE_INT_ITEM_H
#define LIP_1DARRAY_WRITE_INT_ITEM_H

#include "lite_pack/export.h"
#include "lite_pack/file/file.h"
#include "lite_pack/store_int.h"
#include <stdint.h>

struct lip_file;

#define __lip_write_1darray_signed_item(i, v)                                  \
    sizeof(typeof(v)) == 1   ? lip_write_1darray_i8_item(i, (int8_t)(v))       \
    : sizeof(typeof(v)) == 2 ? lip_write_1darray_i16_item(i, (int16_t)(v))     \
    : sizeof(typeof(v)) == 4 ? lip_write_1darray_i32_item(i, (int32_t)(v))     \
    : sizeof(typeof(v)) == 8 ? lip_write_1darray_i64_item(i, (int64_t)(v))     \
                             : 0

#define __lip_write_1darray_unsigned_item(i, v)                                \
    sizeof(typeof(v)) == 1   ? lip_write_1darray_u8_item(i, (uint8_t)(v))      \
    : sizeof(typeof(v)) == 2 ? lip_write_1darray_u16_item(i, (uint16_t)(v))    \
    : sizeof(typeof(v)) == 4 ? lip_write_1darray_u32_item(i, (uint32_t)(v))    \
    : sizeof(typeof(v)) == 8 ? lip_write_1darray_u64_item(i, (uint64_t)(v))    \
                             : 0U

#define __lip_write_1darray_int_item_typed(i, v)                               \
    _Generic((v), signed char                                                  \
             : __lip_write_1darray_signed_item(i, v), signed short             \
             : __lip_write_1darray_signed_item(i, v), signed int               \
             : __lip_write_1darray_signed_item(i, v), signed long              \
             : __lip_write_1darray_signed_item(i, v), signed long long         \
             : __lip_write_1darray_signed_item(i, v), unsigned char            \
             : __lip_write_1darray_unsigned_item(i, v), unsigned short         \
             : __lip_write_1darray_unsigned_item(i, v), unsigned int           \
             : __lip_write_1darray_unsigned_item(i, v), unsigned long          \
             : __lip_write_1darray_unsigned_item(i, v), unsigned long long     \
             : __lip_write_1darray_unsigned_item(i, v))

#define __lip_write_1darray_int_item(i, v)                                     \
    __lip_write_1darray_int_item_typed(i, (v))

/* SIGNED */

static inline void lip_write_1darray_i8_item(struct lip_file *io, int8_t val)
{
    io->error |= lip_store_i8_in((unsigned char *)&val) == 0;
    io->error |= fwrite(&val, sizeof(int8_t), 1, io->fp) != 1;
}

static inline void lip_write_1darray_i16_item(struct lip_file *io, int16_t val)
{
    io->error |= lip_store_i16_in((unsigned char *)&val) == 0;
    io->error |= fwrite(&val, sizeof(int16_t), 1, io->fp) != 1;
}

static inline void lip_write_1darray_i32_item(struct lip_file *io, int32_t val)
{
    io->error |= lip_store_i32_in((unsigned char *)&val) == 0;
    io->error |= fwrite(&val, sizeof(int32_t), 1, io->fp) != 1;
}

static inline void lip_write_1darray_i64_item(struct lip_file *io, int64_t val)
{
    io->error |= lip_store_i64_in((unsigned char *)&val) == 0;
    io->error |= fwrite(&val, sizeof(int64_t), 1, io->fp) != 1;
}

/* UNSIGNED */

static inline void lip_write_1darray_u8_item(struct lip_file *io, uint8_t val)
{
    io->error |= lip_store_u8_in((unsigned char *)&val) == 0;
    io->error |= fwrite(&val, sizeof(uint8_t), 1, io->fp) != 1;
}

static inline void lip_write_1darray_u16_item(struct lip_file *io, uint16_t val)
{
    io->error |= lip_store_u16_in((unsigned char *)&val) == 0;
    io->error |= fwrite(&val, sizeof(uint16_t), 1, io->fp) != 1;
}

static inline void lip_write_1darray_u32_item(struct lip_file *io, uint32_t val)
{
    io->error |= lip_store_u32_in((unsigned char *)&val) == 0;
    io->error |= fwrite(&val, sizeof(uint32_t), 1, io->fp) != 1;
}

static inline void lip_write_1darray_u64_item(struct lip_file *io, uint64_t val)
{
    io->error |= lip_store_u64_in((unsigned char *)&val) == 0;
    io->error |= fwrite(&val, sizeof(uint64_t), 1, io->fp) != 1;
}

#endif
