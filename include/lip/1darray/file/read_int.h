#ifndef LIP_1DARRAY_FILE_READ_INT_H
#define LIP_1DARRAY_FILE_READ_INT_H

#include "lip/export.h"
#include "lip/file/file.h"
#include "lip/load_int.h"
#include "lip/stdio_unlocked.h"
#include <stdint.h>

struct lip_file;

/* DATA */

#define __lip_read_1darray_signed_data(f, s, a)                                \
    sizeof(*(a)) == 1   ? lip_read_1darray_i8_data(f, s, (int8_t *)(a))        \
    : sizeof(*(a)) == 2 ? lip_read_1darray_i16_data(f, s, (int16_t *)(a))      \
    : sizeof(*(a)) == 4 ? lip_read_1darray_i32_data(f, s, (int32_t *)(a))      \
    : sizeof(*(a)) == 8 ? lip_read_1darray_i64_data(f, s, (int64_t *)(a))      \
                        : 0

#define __lip_read_1darray_unsigned_data(f, s, a)                              \
    sizeof(*(a)) == 1   ? lip_read_1darray_u8_data(f, s, (uint8_t *)(a))       \
    : sizeof(*(a)) == 2 ? lip_read_1darray_u16_data(f, s, (uint16_t *)(a))     \
    : sizeof(*(a)) == 4 ? lip_read_1darray_u32_data(f, s, (uint32_t *)(a))     \
    : sizeof(*(a)) == 8 ? lip_read_1darray_u64_data(f, s, (uint64_t *)(a))     \
                        : 0U

#define lip_read_1darray_int_data(f, s, a)                                     \
    _Generic(*(a), signed char                                                 \
             : __lip_read_1darray_signed_data(f, s, a), signed short           \
             : __lip_read_1darray_signed_data(f, s, a), signed int             \
             : __lip_read_1darray_signed_data(f, s, a), signed long            \
             : __lip_read_1darray_signed_data(f, s, a), signed long long       \
             : __lip_read_1darray_signed_data(f, s, a), unsigned char          \
             : __lip_read_1darray_unsigned_data(f, s, a), unsigned short       \
             : __lip_read_1darray_unsigned_data(f, s, a), unsigned int         \
             : __lip_read_1darray_unsigned_data(f, s, a), unsigned long        \
             : __lip_read_1darray_unsigned_data(f, s, a), unsigned long long   \
             : __lip_read_1darray_unsigned_data(f, s, a))

/* SIGNED */

LIP_API bool lip_read_1darray_i8_data(struct lip_file *file, unsigned size,
                                      int8_t arr[]);

LIP_API bool lip_read_1darray_i16_data(struct lip_file *file, unsigned size,
                                       int16_t arr[]);

LIP_API bool lip_read_1darray_i32_data(struct lip_file *file, unsigned size,
                                       int32_t arr[]);

LIP_API bool lip_read_1darray_i64_data(struct lip_file *file, unsigned size,
                                       int64_t arr[]);

/* UNSIGNED */

LIP_API bool lip_read_1darray_u8_data(struct lip_file *file, unsigned size,
                                      uint8_t arr[]);

LIP_API bool lip_read_1darray_u16_data(struct lip_file *file, unsigned size,
                                       uint16_t arr[]);

LIP_API bool lip_read_1darray_u32_data(struct lip_file *file, unsigned size,
                                       uint32_t arr[]);

LIP_API bool lip_read_1darray_u64_data(struct lip_file *file, unsigned size,
                                       uint64_t arr[]);

/* ITEM */

#define __lip_read_1darray_signed_item(f, v)                                   \
    sizeof(*(v)) == 1   ? lip_read_1darray_i8_item(f, (int8_t *)(v))           \
    : sizeof(*(v)) == 2 ? lip_read_1darray_i16_item(f, (int16_t *)(v))         \
    : sizeof(*(v)) == 4 ? lip_read_1darray_i32_item(f, (int32_t *)(v))         \
    : sizeof(*(v)) == 8 ? lip_read_1darray_i64_item(f, (int64_t *)(v))         \
                        : 0

#define __lip_read_1darray_unsigned_item(f, v)                                 \
    sizeof(*(v)) == 1   ? lip_read_1darray_u8_item(f, (uint8_t *)(v))          \
    : sizeof(*(v)) == 2 ? lip_read_1darray_u16_item(f, (uint16_t *)(v))        \
    : sizeof(*(v)) == 4 ? lip_read_1darray_u32_item(f, (uint32_t *)(v))        \
    : sizeof(*(v)) == 8 ? lip_read_1darray_u64_item(f, (uint64_t *)(v))        \
                        : 0U

#define lip_read_1darray_int_item(f, v)                                        \
    _Generic(*(v), signed char                                                 \
             : __lip_read_1darray_signed_item(f, v), signed short              \
             : __lip_read_1darray_signed_item(f, v), signed int                \
             : __lip_read_1darray_signed_item(f, v), signed long               \
             : __lip_read_1darray_signed_item(f, v), signed long long          \
             : __lip_read_1darray_signed_item(f, v), unsigned char             \
             : __lip_read_1darray_unsigned_item(f, v), unsigned short          \
             : __lip_read_1darray_unsigned_item(f, v), unsigned int            \
             : __lip_read_1darray_unsigned_item(f, v), unsigned long           \
             : __lip_read_1darray_unsigned_item(f, v), unsigned long long      \
             : __lip_read_1darray_unsigned_item(f, v))

/* SIGNED */

static inline bool lip_read_1darray_i8_item(struct lip_file *file, int8_t *val)
{
    file->error |= lip_fread(val, sizeof(*val), 1, file->fp) != 1;
    file->error |= lip_load_i8((unsigned char *)val, val) == 0;
    return !file->error;
}

static inline bool lip_read_1darray_i16_item(struct lip_file *file,
                                             int16_t *val)
{
    file->error |= lip_fread(val, sizeof(*val), 1, file->fp) != 1;
    file->error |= lip_load_i16((unsigned char *)val, val) == 0;
    return !file->error;
}

static inline bool lip_read_1darray_i32_item(struct lip_file *file,
                                             int32_t *val)
{
    file->error |= lip_fread(val, sizeof(*val), 1, file->fp) != 1;
    file->error |= lip_load_i32((unsigned char *)val, val) == 0;
    return !file->error;
}

static inline bool lip_read_1darray_i64_item(struct lip_file *file,
                                             int64_t *val)
{
    file->error |= lip_fread(val, sizeof(*val), 1, file->fp) != 1;
    file->error |= lip_load_i64((unsigned char *)val, val) == 0;
    return !file->error;
}

/* UNSIGNED */

static inline bool lip_read_1darray_u8_item(struct lip_file *file, uint8_t *val)
{
    file->error |= lip_fread(val, sizeof(*val), 1, file->fp) != 1;
    file->error |= lip_load_u8((unsigned char *)val, val) == 0;
    return !file->error;
}

static inline bool lip_read_1darray_u16_item(struct lip_file *file,
                                             uint16_t *val)
{
    file->error |= lip_fread(val, sizeof(*val), 1, file->fp) != 1;
    file->error |= lip_load_u16((unsigned char *)val, val) == 0;
    return !file->error;
}

static inline bool lip_read_1darray_u32_item(struct lip_file *file,
                                             uint32_t *val)
{
    file->error |= lip_fread(val, sizeof(*val), 1, file->fp) != 1;
    file->error |= lip_load_u32((unsigned char *)val, val) == 0;
    return !file->error;
}

static inline bool lip_read_1darray_u64_item(struct lip_file *file,
                                             uint64_t *val)
{
    file->error |= lip_fread(val, sizeof(*val), 1, file->fp) != 1;
    file->error |= lip_load_u64((unsigned char *)val, val) == 0;
    return !file->error;
}

#endif
