#include "helper.h"
#include "lite_pack.h"

unsigned const lengths[] = {
    0, 15, 16, 65535, 65536, 4294967295,
};

int const formats[] = {LIP_FMT_FIXMAP, LIP_FMT_FIXMAP, LIP_FMT_MAP_16,
                       LIP_FMT_MAP_16, LIP_FMT_MAP_32, LIP_FMT_MAP_32};

uint8_t buf[17] = {0};

int main(void)
{

    for (unsigned i = 0; i < array_size(lengths); ++i)
    {
        clear(buf);
        lip_pack_map_head(buf, lengths[i]);
        if (lip_format(buf) != formats[i]) ERROR;
        if (lip_unpack_map_head(buf) != lengths[i]) ERROR;
    }

    return 0;
}
