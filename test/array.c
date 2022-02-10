#include "helper.h"
#include "lite_pack.h"

static unsigned const sizes[] = {
    0, 15, 16, 65535, 65536, 4294967295,
};
static unsigned const pack_sizes[] = {1, 1, 3, 3, 5, 5};

static enum lip_format const formats[] = {LIP_FMT_FIXARRAY, LIP_FMT_FIXARRAY,
                                          LIP_FMT_ARRAY_16, LIP_FMT_ARRAY_16,
                                          LIP_FMT_ARRAY_32, LIP_FMT_ARRAY_32};

static unsigned char buf[17] = {0};

int main(void)
{
    for (unsigned i = 0; i < array_size(sizes); ++i)
    {
        clear(buf);
        if (lip_pack_array_size(buf, sizes[i]) != pack_sizes[i]) ERROR;
        if (lip_format(buf) != formats[i]) ERROR;
        unsigned size = 0;
        if (lip_unpack_array_size(buf, &size) != pack_sizes[i]) ERROR;
        if (size != sizes[i]) ERROR;
    }

    return 0;
}
