#include "helper.h"
#include "lite_pack.h"

static int test_example1_write(size_t *size)
{
    FILE *fp = fopen("example1.mp", "wb");

    uint8_t buf[256] = {0};
    uint8_t *ptr = buf;

    ptr += lip_pack_map_head(ptr, 2);

    ptr += lip_pack_str(ptr, "name");
    ptr += lip_pack_str(ptr, "Danilo Horta");

    ptr += lip_pack_str(ptr, "age");
    ptr += lip_pack_int(ptr, 36U);

    *size = fwrite(buf, 1, (size_t)(ptr - buf), fp);

    fclose(fp);

    return 0;
}

static int test_example1_read(size_t *size)
{
    FILE *fp = fopen("example1.mp", "rb");

    uint8_t buf[256] = {0};
    char str[256] = {0};
    uint8_t *ptr = buf;

    fread(buf, 1, *size, fp);
    ptr = buf;

    if (lip_unpack_map_head(ptr) != 2) ERROR;
    ptr += lip_skip(ptr);

    if (strcmp(lip_unpack_str(ptr, str), "name")) ERROR;
    ptr += lip_skip(ptr);

    if (strcmp(lip_unpack_str(ptr, str), "Danilo Horta")) ERROR;
    ptr += lip_skip(ptr);

    if (strcmp(lip_unpack_str(ptr, str), "age")) ERROR;
    ptr += lip_skip(ptr);

    if (lip_unpack_uint(ptr) != 36) ERROR;
    ptr += lip_skip(ptr);

    if ((size_t)(ptr - buf) != *size) ERROR;

    fclose(fp);

    return 0;
}

static int test_example1(void)
{
    size_t size = 0;
    if (test_example1_write(&size)) ERROR;
    if (test_example1_read(&size)) ERROR;
    return 0;
}

int main(void) { return test_example1(); }
