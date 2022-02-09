#include "helper.h"
#include "lite_pack.h"

static unsigned char buf = 0;

int main(void)
{
    for (int i = 0; i < 128; ++i)
    {
        buf = __lip_first_byte_fix(LIP_FMT_POSITIVE_FIXINT, i);
        if (__lip_format(buf) != LIP_FMT_POSITIVE_FIXINT) ERROR;
        if (__lip_format_fix_value(buf) != i) ERROR;
    }

    for (int i = 0; i < 16; ++i)
    {
        buf = __lip_first_byte_fix(LIP_FMT_FIXMAP, i);
        if (__lip_format(buf) != LIP_FMT_FIXMAP) ERROR;
        if (__lip_format_fix_value(buf) != i) ERROR;
    }

    for (int i = 0; i < 16; ++i)
    {
        buf = __lip_first_byte_fix(LIP_FMT_FIXARRAY, i);
        if (__lip_format(buf) != LIP_FMT_FIXARRAY) ERROR;
        if (__lip_format_fix_value(buf) != i) ERROR;
    }

    for (int i = 0; i < 32; ++i)
    {
        buf = __lip_first_byte_fix(LIP_FMT_FIXSTR, i);
        if (__lip_format(buf) != LIP_FMT_FIXSTR) ERROR;
        if (__lip_format_fix_value(buf) != i) ERROR;
    }

    for (int i = -32; i < 0; ++i)
    {
        buf = __lip_first_byte_fix(LIP_FMT_NEGATIVE_FIXINT, i);
        if (__lip_format(buf) != LIP_FMT_NEGATIVE_FIXINT) ERROR;
        if (__lip_format_fix_value(buf) != i) ERROR;
    }

    return 0;
}
