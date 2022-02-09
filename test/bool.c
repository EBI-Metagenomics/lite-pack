#include "helper.h"
#include "lite_pack.h"

int main(void)
{
    unsigned char buf[1] = {0};
    bool v = 0;

    clear(buf);
    if (lip_pack_bool(buf, false) != 1) ERROR;
    if (lip_format(buf) != LIP_FMT_FALSE) ERROR;
    if (lip_unpack_bool(buf, &v) != 1) ERROR;
    if (v != false) ERROR;

    clear(buf);
    if (lip_pack_bool(buf, true) != 1) ERROR;
    if (lip_format(buf) != LIP_FMT_TRUE) ERROR;
    if (lip_unpack_bool(buf, &v) != 1) ERROR;
    if (v != true) ERROR;

    return 0;
}
