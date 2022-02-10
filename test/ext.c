#include "helper.h"
#include "lite_pack/lite_pack.h"

struct
{
    unsigned size;
    unsigned pack_sz;
    enum lip_format fmt;
} a[] = {

    {0, 3, LIP_FMT_EXT_8},      {1, 2, LIP_FMT_FIXEXT_1},
    {2, 2, LIP_FMT_FIXEXT_2},   {3, 3, LIP_FMT_EXT_8},
    {4, 2, LIP_FMT_FIXEXT_4},   {5, 3, LIP_FMT_EXT_8},
    {8, 2, LIP_FMT_FIXEXT_8},   {15, 3, LIP_FMT_EXT_8},
    {16, 2, LIP_FMT_FIXEXT_16}, {65535, 4, LIP_FMT_EXT_16},
    {65536, 6, LIP_FMT_EXT_32}, {4294967295, 6, LIP_FMT_EXT_32}};

static unsigned char buf[17] = {0};

int main(void)
{
    uint8_t type = 0;
    for (unsigned i = 0; i < array_size(a); ++i)
    {
        clear(buf);
        if (lip_pack_ext_size_type(buf, a[i].size, 33) != a[i].pack_sz) ERROR;
        if (lip_format(buf) != a[i].fmt) ERROR;
        unsigned size = 0;
        if (lip_unpack_ext_size_type(buf, &size, &type) != a[i].pack_sz) ERROR;
        if (type != 33) ERROR;
        if (size != a[i].size) ERROR;
    }

    return 0;
}
