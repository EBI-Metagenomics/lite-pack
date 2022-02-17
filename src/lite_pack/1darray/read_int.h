#ifndef LIP_1DARRAY_READ_INT_H
#define LIP_1DARRAY_READ_INT_H

#include "lite_pack/export.h"
#include "lite_pack/file/file.h"
#include "lite_pack/load_int.h"
#include <stdint.h>

struct lip_file;

/* DATA */

#define __lip_read_1darray_signed_data(i, s, a)                                \
    sizeof(*a) == 1   ? lip_read_1darray_i8_data(i, s, (int8_t *)(a))          \
    : sizeof(*a) == 2 ? lip_read_1darray_i16_data(i, s, (int16_t *)(a))        \
    : sizeof(*a) == 4 ? lip_read_1darray_i32_data(i, s, (int32_t *)(a))        \
    : sizeof(*a) == 8 ? lip_read_1darray_i64_data(i, s, (int64_t *)(a))        \
                      : 0

#define __lip_read_1darray_unsigned_data(i, s, a)                              \
    sizeof(*a) == 1   ? lip_read_1darray_u8_data(i, s, (uint8_t *)(a))         \
    : sizeof(*a) == 2 ? lip_read_1darray_u16_data(i, s, (uint16_t *)(a))       \
    : sizeof(*a) == 4 ? lip_read_1darray_u32_data(i, s, (uint32_t *)(a))       \
    : sizeof(*a) == 8 ? lip_read_1darray_u64_data(i, s, (uint64_t *)(a))       \
                      : 0U

#define __lip_read_1darray_int_data(i, s, a)                                   \
    _Generic((*a), signed char                                                 \
             : __lip_read_1darray_signed_data(i, s, a), signed short           \
             : __lip_read_1darray_signed_data(i, s, a), signed int             \
             : __lip_read_1darray_signed_data(i, s, a), signed long            \
             : __lip_read_1darray_signed_data(i, s, a), signed long long       \
             : __lip_read_1darray_signed_data(i, s, a), unsigned char          \
             : __lip_read_1darray_unsigned_data(i, s, a), unsigned short       \
             : __lip_read_1darray_unsigned_data(i, s, a), unsigned int         \
             : __lip_read_1darray_unsigned_data(i, s, a), unsigned long        \
             : __lip_read_1darray_unsigned_data(i, s, a), unsigned long long   \
             : __lip_read_1darray_unsigned_data(i, s, a))

/* SIGNED */

LIP_API void lip_read_1darray_i8_data(struct lip_file *io, unsigned size,
                                      int8_t arr[]);

LIP_API void lip_read_1darray_i16_data(struct lip_file *io, unsigned size,
                                       int16_t arr[]);

LIP_API void lip_read_1darray_i32_data(struct lip_file *io, unsigned size,
                                       int32_t arr[]);

LIP_API void lip_read_1darray_i64_data(struct lip_file *io, unsigned size,
                                       int64_t arr[]);

/* UNSIGNED */

LIP_API void lip_read_1darray_u8_data(struct lip_file *io, unsigned size,
                                      uint8_t arr[]);

LIP_API void lip_read_1darray_u16_data(struct lip_file *io, unsigned size,
                                       uint16_t arr[]);

LIP_API void lip_read_1darray_u32_data(struct lip_file *io, unsigned size,
                                       uint32_t arr[]);

LIP_API void lip_read_1darray_u64_data(struct lip_file *io, unsigned size,
                                       uint64_t arr[]);

/* ITEM */

#define __lip_read_1darray_signed_item(i, v)                                   \
    sizeof(*v) == 1   ? lip_read_1darray_i8_item(i, (int8_t *)(v))             \
    : sizeof(*v) == 2 ? lip_read_1darray_i16_item(i, (int16_t *)(v))           \
    : sizeof(*v) == 4 ? lip_read_1darray_i32_item(i, (int32_t *)(v))           \
    : sizeof(*v) == 8 ? lip_read_1darray_i64_item(i, (int64_t *)(v))           \
                      : 0

#define __lip_read_1darray_unsigned_item(i, v)                                 \
    sizeof(*v) == 1   ? lip_read_1darray_u8_item(i, (uint8_t *)(v))            \
    : sizeof(*v) == 2 ? lip_read_1darray_u16_item(i, (uint16_t *)(v))          \
    : sizeof(*v) == 4 ? lip_read_1darray_u32_item(i, (uint32_t *)(v))          \
    : sizeof(*v) == 8 ? lip_read_1darray_u64_item(i, (uint64_t *)(v))          \
                      : 0U

#define __lip_read_1darray_int_item(i, v)                                      \
    _Generic((*v), signed char                                                 \
             : __lip_read_1darray_signed_item(i, v), signed short              \
             : __lip_read_1darray_signed_item(i, v), signed int                \
             : __lip_read_1darray_signed_item(i, v), signed long               \
             : __lip_read_1darray_signed_item(i, v), signed long long          \
             : __lip_read_1darray_signed_item(i, v), unsigned char             \
             : __lip_read_1darray_unsigned_item(i, v), unsigned short          \
             : __lip_read_1darray_unsigned_item(i, v), unsigned int            \
             : __lip_read_1darray_unsigned_item(i, v), unsigned long           \
             : __lip_read_1darray_unsigned_item(i, v), unsigned long long      \
             : __lip_read_1darray_unsigned_item(i, v))

/* SIGNED */

static inline void lip_read_1darray_i8_item(struct lip_file *io, int8_t *val)
{
    io->error |= fread(val, sizeof(*val), 1, io->fp) != 1;
    io->error |= lip_load_i8((unsigned char *)val, val) == 0;
}

static inline void lip_read_1darray_i16_item(struct lip_file *io, int16_t *val)
{
    io->error |= fread(val, sizeof(*val), 1, io->fp) != 1;
    io->error |= lip_load_i16((unsigned char *)val, val) == 0;
}

static inline void lip_read_1darray_i32_item(struct lip_file *io, int32_t *val)
{
    io->error |= fread(val, sizeof(*val), 1, io->fp) != 1;
    io->error |= lip_load_i32((unsigned char *)val, val) == 0;
}

static inline void lip_read_1darray_i64_item(struct lip_file *io, int64_t *val)
{
    io->error |= fread(val, sizeof(*val), 1, io->fp) != 1;
    io->error |= lip_load_i64((unsigned char *)val, val) == 0;
}

/* UNSIGNED */

static inline void lip_read_1darray_u8_item(struct lip_file *io, uint8_t *val)
{
    io->error |= fread(val, sizeof(*val), 1, io->fp) != 1;
    io->error |= lip_load_u8((unsigned char *)val, val) == 0;
}

static inline void lip_read_1darray_u16_item(struct lip_file *io, uint16_t *val)
{
    io->error |= fread(val, sizeof(*val), 1, io->fp) != 1;
    io->error |= lip_load_u16((unsigned char *)val, val) == 0;
}

static inline void lip_read_1darray_u32_item(struct lip_file *io, uint32_t *val)
{
    io->error |= fread(val, sizeof(*val), 1, io->fp) != 1;
    io->error |= lip_load_u32((unsigned char *)val, val) == 0;
}

static inline void lip_read_1darray_u64_item(struct lip_file *io, uint64_t *val)
{
    io->error |= fread(val, sizeof(*val), 1, io->fp) != 1;
    io->error |= lip_load_u64((unsigned char *)val, val) == 0;
}

#endif
