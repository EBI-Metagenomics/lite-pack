#include "helper.h"
#include "lite_pack.h"

int main(void)
{
    unsigned long buf_size = 0x10000UL + 6UL;
    unsigned long out_size = 0x10000UL + 1UL;
    uint8_t *buf = malloc(buf_size);
    if (!buf) exit(1);

    char *out = malloc(out_size);
    if (!out) exit(1);

    unsigned lengths[] = {0, 0x1F, 0x20, 0xFF, 0x100, 0xFFFF, 0x10000U};
    int formats[] = {
        LIP_FMT_FIXSTR, LIP_FMT_FIXSTR, LIP_FMT_STR_8,  LIP_FMT_STR_8,
        LIP_FMT_STR_16, LIP_FMT_STR_16, LIP_FMT_STR_32,
    };
    unsigned sizes[] = {
        1, 1, 2, 2, 3, 3, 5,
    };

    char const *str = 0;

    for (unsigned i = 0; i < array_size(lengths); ++i)
    {
        memset(buf, 0, buf_size);

        str = lorem_new(lengths[i]);
        unsigned len = (unsigned)strlen(str);
        if (lip_pack_str_size(buf, len) != sizes[i]) ERROR;
        if (lip_pack_str_data(buf + sizes[i], len, str) != lengths[i]) ERROR;

        if (lip_format(buf) != formats[i]) ERROR;
        if (lip_unpack_str_size(buf, &len) != sizes[i]) ERROR;
        // if (strcmp(lip_unpack_str(buf, out), str)) goto error;

        free((void *)str);
    }

    free(buf);
    free(out);
    return 0;
}
