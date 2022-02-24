#include "helper.h"
#include "lite_pack/lite_pack.h"

static unsigned char ch = 0;

int main(void)
{
    for (int i = 0; i < 128; ++i)
    {
        ch = __lip_first_byte_fix(LIP_FMT_POSITIVE_FIXINT, i);
        if (lip_format(ch) != LIP_FMT_POSITIVE_FIXINT) ERROR;
        if (__lip_format_fix_value(ch) != i) ERROR;
    }

    for (int i = 0; i < 16; ++i)
    {
        ch = __lip_first_byte_fix(LIP_FMT_FIXMAP, i);
        if (lip_format(ch) != LIP_FMT_FIXMAP) ERROR;
        if (__lip_format_fix_value(ch) != i) ERROR;
    }

    for (int i = 0; i < 16; ++i)
    {
        ch = __lip_first_byte_fix(LIP_FMT_FIXARRAY, i);
        if (lip_format(ch) != LIP_FMT_FIXARRAY) ERROR;
        if (__lip_format_fix_value(ch) != i) ERROR;
    }

    for (int i = 0; i < 32; ++i)
    {
        ch = __lip_first_byte_fix(LIP_FMT_FIXSTR, i);
        if (lip_format(ch) != LIP_FMT_FIXSTR) ERROR;
        if (__lip_format_fix_value(ch) != i) ERROR;
    }

    for (int i = -32; i < 0; ++i)
    {
        ch = __lip_first_byte_fix(LIP_FMT_NEGATIVE_FIXINT, i);
        if (lip_format(ch) != LIP_FMT_NEGATIVE_FIXINT) ERROR;
        if (__lip_format_fix_value(ch) != i) ERROR;
    }

    return 0;
}
