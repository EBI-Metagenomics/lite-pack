#include "helper.h"
#include "lite_pack.h"

static unsigned const sizes[] = {0, 0x1F, 0x20, 0xFF, 0x100, 0xFFFF, 0x10000U};
static unsigned const pack_sizes[] = {
    1, 1, 2, 2, 3, 3, 5,
};

static int const formats[] = {
    LIP_FMT_FIXSTR, LIP_FMT_FIXSTR, LIP_FMT_STR_8,  LIP_FMT_STR_8,
    LIP_FMT_STR_16, LIP_FMT_STR_16, LIP_FMT_STR_32,
};

int main(void)
{
    unsigned long buf_size = 0x10000UL + 6UL;
    unsigned long out_size = 0x10000UL + 1UL;
    unsigned char *buf = malloc(buf_size);
    if (!buf) exit(1);

    char *out = malloc(out_size);
    if (!out) exit(1);

    char const *str = 0;

    for (unsigned i = 0; i < array_size(sizes); ++i)
    {
        memset(buf, 0, buf_size);

        str = lorem_new(sizes[i]);
        unsigned len = (unsigned)strlen(str);
        if (lip_pack_str_size(buf, len) != pack_sizes[i]) ERROR;
        if (lip_pack_str_data(buf + pack_sizes[i], len, str) != sizes[i]) ERROR;

        if (lip_format(buf) != formats[i]) ERROR;
        if (lip_unpack_str_size(buf, &len) != pack_sizes[i]) ERROR;
        if (len != sizes[i]) ERROR;
        if (lip_unpack_str_data(buf + pack_sizes[i], len, out) != sizes[i])
            ERROR;
        if (strncmp(out, str, len) != 0) ERROR;

        free((void *)str);
    }

    free(buf);
    free(out);
    return 0;
}
