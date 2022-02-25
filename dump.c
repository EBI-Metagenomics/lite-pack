#include "lite_pack/file/file.h"
#include "lite_pack/lite_pack.h"

#include <inttypes.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned char buf[BUFSIZ] = {0};
static int64_t last_file_position = 0;

static bool parse_object(struct lip_file *file, unsigned lvl);

void store_file_position(FILE *fp) { last_file_position = ftello(fp); }

static int fpeek(FILE *fp)
{
    int c = fgetc(fp);
    ungetc(c, fp);

    return c;
}

static void echo(unsigned lvl, char const *format, ...)
{
    va_list ap;
    va_start(ap, format);
    for (unsigned i = 0; i < lvl; ++i)
        printf("  ");
    vprintf(format, ap);
    printf("\n");
    va_end(ap);
}

static bool parse_nil(struct lip_file *file, unsigned lvl)
{
    (void)file;
    echo(lvl, "- format: nil");
    echo(lvl, "  data: nil");
    return true;
}

static bool parse_bool(struct lip_file *file, unsigned lvl)
{
    echo(lvl, "- format: bool");

    bool val = false;
    if (!lip_read_bool(file, &val)) return false;

    if (val)
        echo(lvl, "  data: true");
    else
        echo(lvl, "  data: false");

    return true;
}

static bool require_sign(enum lip_format fmt)
{
    return (fmt == LIP_FMT_POSITIVE_FIXINT || fmt == LIP_FMT_INT_8 ||
            fmt == LIP_FMT_INT_16 || fmt == LIP_FMT_INT_32 ||
            fmt == LIP_FMT_INT_64);
}

static bool parse_int(struct lip_file *file, unsigned lvl, enum lip_format fmt)
{
    if (fmt == LIP_FMT_POSITIVE_FIXINT)
        echo(lvl, "- format: positive_fixint");
    else if (fmt == LIP_FMT_UINT_8)
        echo(lvl, "- format: uint8");
    else if (fmt == LIP_FMT_UINT_16)
        echo(lvl, "- format: uin16");
    else if (fmt == LIP_FMT_UINT_32)
        echo(lvl, "- format: uint32");
    else if (fmt == LIP_FMT_UINT_64)
        echo(lvl, "- format: uint64");
    else if (fmt == LIP_FMT_NEGATIVE_FIXINT)
        echo(lvl, "- format: negative_fixint");
    else if (fmt == LIP_FMT_INT_8)
        echo(lvl, "- format: int8");
    else if (fmt == LIP_FMT_INT_16)
        echo(lvl, "- format: in16");
    else if (fmt == LIP_FMT_INT_32)
        echo(lvl, "- format: int32");
    else if (fmt == LIP_FMT_INT_64)
        echo(lvl, "- format: int64");
    else
        exit(EXIT_FAILURE);

    if (require_sign(fmt))
    {
        int64_t val = 0;
        if (!lip_read_int(file, &val)) return false;
        echo(lvl, "  data: %" PRId64, val);
    }
    else
    {
        uint64_t val = 0;
        if (!lip_read_int(file, &val)) return false;
        echo(lvl, "  data: %" PRIu64, val);
    }

    return true;
}

static bool parse_float(struct lip_file *file, unsigned lvl,
                        enum lip_format fmt)
{
    if (fmt == LIP_FMT_FLOAT_32)
        echo(lvl, "- format: float32");
    else if (fmt == LIP_FMT_FLOAT_64)
        echo(lvl, "- format: float64");
    else
        exit(EXIT_FAILURE);

    double val = 0;
    if (!lip_read_float(file, &val)) return false;
    echo(lvl, "  data: %f", val);

    return true;
}

static bool parse_str(struct lip_file *file, unsigned lvl, enum lip_format fmt)
{
    unsigned size = 0;
    if (!lip_read_str_size(file, &size)) return false;

    if (fmt == LIP_FMT_FIXSTR)
        echo(lvl, "- format: fixstr");
    else if (fmt == LIP_FMT_STR_8)
        echo(lvl, "- format: str8");
    else if (fmt == LIP_FMT_STR_16)
        echo(lvl, "- format: str16");
    else if (fmt == LIP_FMT_STR_32)
        echo(lvl, "- format: str32");
    else
        exit(EXIT_FAILURE);

    echo(lvl, "  size: %u", size);

    if (size > BUFSIZ)
    {
        unsigned remains = (unsigned)(size - BUFSIZ);
        if (!lip_read_str_data(file, BUFSIZ, (char *)buf)) return false;
        echo(lvl, "  data: %.*s...", BUFSIZ, (char *)buf);
        return !fseek(lip_file_ptr(file), remains, SEEK_CUR);
    }
    else
    {
        if (!lip_read_str_data(file, size, (char *)buf)) return false;
        echo(lvl, "  data: %.*s", size, (char *)buf);
    }

    return true;
}

// Not implemented yet
// static bool parse_bin(struct lip_file *file, unsigned lvl, enum lip_format
// fmt);

static bool parse_array(struct lip_file *file, unsigned lvl,
                        enum lip_format fmt)
{
    unsigned size = 0;
    if (!lip_read_array_size(file, &size)) return false;

    if (fmt == LIP_FMT_FIXARRAY)
        echo(lvl, "- format: fixarray");
    else if (fmt == LIP_FMT_ARRAY_16)
        echo(lvl, "- format: array16");
    else if (fmt == LIP_FMT_ARRAY_32)
        echo(lvl, "- format: array32");
    else
        exit(EXIT_FAILURE);

    echo(lvl, "  size: %u", size);

    echo(lvl, "  data:");
    for (unsigned i = 0; i < size; ++i)
    {
        if (!parse_object(file, lvl + 1)) return false;
    }

    return true;
}

static bool parse_map(struct lip_file *file, unsigned lvl, enum lip_format fmt)
{
    unsigned size = 0;
    if (!lip_read_map_size(file, &size)) return false;

    if (fmt == LIP_FMT_FIXMAP)
        echo(lvl, "- format: fixmap");
    else if (fmt == LIP_FMT_MAP_16)
        echo(lvl, "- format: map16");
    else if (fmt == LIP_FMT_MAP_32)
        echo(lvl, "- format: map32");
    else
        exit(EXIT_FAILURE);

    echo(lvl, "  size: %u", size);
    echo(lvl, "  data:");

    for (unsigned i = 0; i < size; ++i)
    {
        echo(lvl + 1, "- item:");

        echo(lvl + 2, "  key:");
        if (!parse_object(file, lvl + 3)) return false;

        echo(lvl + 2, "  value:");
        if (!parse_object(file, lvl + 3)) return false;
    }

    return true;
}

static bool parse_ext(struct lip_file *file, unsigned lvl, enum lip_format fmt)
{
    unsigned size = 0;
    uint8_t type = 0;
    if (!lip_read_ext_size_type(file, &size, &type)) return false;

    if (fmt == LIP_FMT_FIXEXT_1)
        echo(lvl, "- format: fixext1");
    else if (fmt == LIP_FMT_FIXEXT_2)
        echo(lvl, "- format: fixext2");
    else if (fmt == LIP_FMT_FIXEXT_4)
        echo(lvl, "- format: fixext4");
    else if (fmt == LIP_FMT_FIXEXT_8)
        echo(lvl, "- format: fixext8");
    else if (fmt == LIP_FMT_FIXEXT_16)
        echo(lvl, "- format: fixext16");
    else if (fmt == LIP_FMT_EXT_8)
        echo(lvl, "- format: ext8");
    else if (fmt == LIP_FMT_EXT_16)
        echo(lvl, "- format: ext16");
    else if (fmt == LIP_FMT_EXT_32)
        echo(lvl, "- format: ext32");
    else
        exit(EXIT_FAILURE);

    echo(lvl, "  size: %u", size);
    echo(lvl, "  type: %u", type);
    echo(lvl, "  data: < %u bytes >", size);

    if (fseek(lip_file_ptr(file), size, SEEK_CUR)) return false;

    return true;
}

static bool parse_object(struct lip_file *file, unsigned lvl)
{
    int ch = fpeek(lip_file_ptr(file));
    if (ch == EOF) return false;

    enum lip_format fmt = lip_format(ch);
    enum lip_format_family family = lip_format_family(fmt);

    bool ok = false;
    if (family == LIP_FMT_FAMILY_NIL)
    {
        ok = parse_nil(file, lvl);
    }
    else if (family == LIP_FMT_FAMILY_BOOL)
    {
        ok = parse_bool(file, lvl);
    }
    else if (family == LIP_FMT_FAMILY_INT)
    {
        ok = parse_int(file, lvl, fmt);
    }
    else if (family == LIP_FMT_FAMILY_FLOAT)
    {
        ok = parse_float(file, lvl, fmt);
    }
    else if (family == LIP_FMT_FAMILY_STR)
    {
        ok = parse_str(file, lvl, fmt);
    }
    else if (family == LIP_FMT_FAMILY_BIN)
    {
        // Not implemented yet
        assert(false);
    }
    else if (family == LIP_FMT_FAMILY_ARRAY)
    {
        ok = parse_array(file, lvl, fmt);
    }
    else if (family == LIP_FMT_FAMILY_MAP)
    {
        ok = parse_map(file, lvl, fmt);
    }
    else if (family == LIP_FMT_FAMILY_EXT)
    {
        ok = parse_ext(file, lvl, fmt);
    }
    return ok;
}

int main(void)
{
    // Usage: ./dump < db.dcp
    // FILE *fp = fopen("db.dcp", "rb");
    FILE *fp = stdin;

    struct lip_file file = {0};
    lip_file_init(&file, fp);

    echo(0, "---");
    while (true)
    {
        bool ok = parse_object(&file, 0);
        store_file_position(lip_file_ptr(&file));
        if (!ok)
        {
            if (feof(lip_file_ptr(&file))) return EXIT_SUCCESS;
            return EXIT_FAILURE;
        }
    }
    __builtin_unreachable();
}
