#include "helper.h"
#include "lite_pack.h"

unsigned const sizes[] = {
    0, 15, 16, 65535, 65536, 4294967295,
};
unsigned const pack_sizes[] = {1, 1, 3, 3, 5, 5};

int const formats[] = {LIP_FMT_FIXMAP, LIP_FMT_FIXMAP, LIP_FMT_MAP_16,
                       LIP_FMT_MAP_16, LIP_FMT_MAP_32, LIP_FMT_MAP_32};

uint8_t buf[17] = {0};

int main(void)
{
    for (unsigned i = 0; i < array_size(sizes); ++i)
    {
        clear(buf);
        if (lip_pack_map_size(buf, sizes[i]) != pack_sizes[i]) ERROR;
        if (lip_format(buf) != formats[i]) ERROR;
        unsigned size = 0;
        if (lip_unpack_map_size(buf, &size) != pack_sizes[i]) ERROR;
        if (size != sizes[i]) ERROR;
    }

    return 0;
}
