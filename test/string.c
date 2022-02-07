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

    unsigned long lengths[] = {0, 0x1F, 0x20, 0xFF, 0x100, 0xFFFF, 0x10000UL};
    int formats[] = {
        LIP_FMT_FIXSTR, LIP_FMT_FIXSTR, LIP_FMT_STR_8,  LIP_FMT_STR_8,
        LIP_FMT_STR_16, LIP_FMT_STR_16, LIP_FMT_STR_32,
    };

    char const *str = 0;

    for (unsigned i = 0; i < array_size(lengths); ++i)
    {
        memset(buf, 0, buf_size);

        str = lorem_new(lengths[i]);
        lip_pack_str(buf, str);

        if (lip_format(buf) != formats[i]) goto error;
        if (strcmp(lip_unpack_str(buf, out), str)) goto error;

        free((void *)str);
    }

    free(buf);
    free(out);
    return 0;

error:
    free(buf);
    free(out);
    free((void *)str);
    ERROR;
}
