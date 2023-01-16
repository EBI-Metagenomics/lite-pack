#include "lip/file/file.h"
#include "fpeek.h"
#include "lip/file/read_array.h"
#include "lip/file/read_ext.h"
#include "lip/file/read_map.h"
#include "lip/format.h"
#include <string.h>

void lip_file_init(struct lip_file *file, FILE *fp)
{
    file->fp = fp;
    memset(file->buf, 0, 9);
    file->error = false;
}

FILE *lip_file_ptr(struct lip_file *file) { return file->fp; }

static inline bool skip_nil(struct lip_file *file)
{
    return !fseek(file->fp, 1, SEEK_CUR);
}

static inline bool skip_bool(struct lip_file *file)
{
    return !fseek(file->fp, 1, SEEK_CUR);
}

static inline bool skip_int(struct lip_file *file, enum lip_format fmt)
{
    unsigned sz = 0;
    switch (fmt)
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
        fallthrough;

    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        break;

    default:
        __builtin_unreachable();
    }

    return !fseek(file->fp, sz + 1, SEEK_CUR);
}

static inline bool skip_float(struct lip_file *file, enum lip_format fmt)
{
    unsigned sz = 0;
    if (fmt == LIP_FMT_FLOAT_32)
        sz = 4;
    else if (fmt == LIP_FMT_FLOAT_64)
        sz = 8;
    else
        __builtin_unreachable();

    return !fseek(file->fp, sz + 1, SEEK_CUR);
}

static inline bool skip_str(struct lip_file *file, enum lip_format fmt)
{
    unsigned sz = 0;
    switch (fmt)
    {
    case LIP_FMT_STR_32:
        sz += 2;
        fallthrough;

    case LIP_FMT_STR_16:
        sz += 1;
        fallthrough;

    case LIP_FMT_STR_8:
        sz += 1;
        fallthrough;

    case LIP_FMT_FIXSTR:
        break;

    default:
        __builtin_unreachable();
    }

    return !fseek(file->fp, sz + 1, SEEK_CUR);
}

static inline bool skip_bin(struct lip_file *file, enum lip_format fmt)
{
    (void)file;
    (void)fmt;
    // Not implemented yet
    assert(false);
    return true;
}

static inline bool skip_array(struct lip_file *file, enum lip_format fmt)
{
    (void)fmt;
    unsigned sz = 0;
    if (!lip_read_array_size(file, &sz)) return false;
    return !fseek(file->fp, sz, SEEK_CUR);
}

static inline bool skip_map(struct lip_file *file, enum lip_format fmt)
{
    (void)fmt;
    unsigned sz = 0;
    if (!lip_read_map_size(file, &sz)) return false;
    return !fseek(file->fp, sz, SEEK_CUR);
}

static inline bool skip_ext(struct lip_file *file, enum lip_format fmt)
{
    (void)fmt;
    unsigned sz = 0;
    uint8_t type = 0;
    if (!lip_read_ext_size_type(file, &sz, &type)) return false;
    return !fseek(file->fp, sz, SEEK_CUR);
}

static inline bool skip_never_used(struct lip_file *file, enum lip_format fmt)
{
    (void)fmt;
    return !fseek(file->fp, 1, SEEK_CUR);
}

bool lip_file_skip(struct lip_file *file)
{
    int first_byte = 0;
    if (!fpeek(file->fp, &first_byte)) return false;

    enum lip_format fmt = lip_format(first_byte);
    enum lip_format_family family = lip_format_family(fmt);

    if (family == LIP_FMT_FAMILY_NIL)
        return skip_nil(file);
    else if (family == LIP_FMT_FAMILY_BOOL)
        return skip_bool(file);
    else if (family == LIP_FMT_FAMILY_INT)
        return skip_int(file, fmt);
    else if (family == LIP_FMT_FAMILY_FLOAT)
        return skip_float(file, fmt);
    else if (family == LIP_FMT_FAMILY_STR)
        return skip_str(file, fmt);
    else if (family == LIP_FMT_FAMILY_BIN)
        return skip_bin(file, fmt);
    else if (family == LIP_FMT_FAMILY_ARRAY)
        return skip_array(file, fmt);
    else if (family == LIP_FMT_FAMILY_MAP)
        return skip_map(file, fmt);
    else if (family == LIP_FMT_FAMILY_EXT)
        return skip_ext(file, fmt);
    else if (family == LIP_FMT_FAMILY_NEVER_USED)
        return skip_never_used(file, fmt);

    __builtin_unreachable();
}

bool lip_file_error(struct lip_file const *file) { return file->error; }
