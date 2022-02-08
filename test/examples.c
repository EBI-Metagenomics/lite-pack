#include "helper.h"
#include "lite_pack.h"

static int test_example1_write(size_t *size)
{
    FILE *fp = fopen("example1.mp", "wb");

    uint8_t buf[256] = {0};
    uint8_t *ptr = buf;

    ptr += lip_pack_map_size(ptr, 2);

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

    unsigned sz = 0;
    ptr += lip_unpack_map_size(ptr, &sz);
    if (sz != 2) ERROR;

    ptr += lip_unpack_str_size(ptr, &sz);
    if (sz != 4) ERROR;

    ptr += lip_unpack_str_data(ptr, sz, str);
    if (strncmp(str, "name", sz)) ERROR;

    ptr += lip_unpack_str_size(ptr, &sz);
    if (sz != 12) ERROR;

    ptr += lip_unpack_str_data(ptr, sz, str);
    if (strncmp(str, "Danilo Horta", sz)) ERROR;

    ptr += lip_unpack_str_size(ptr, &sz);
    if (sz != 3) ERROR;

    ptr += lip_unpack_str_data(ptr, sz, str);
    if (strncmp(str, "age", sz)) ERROR;

    unsigned age = 0;
    ptr += lip_unpack_int(ptr, &age);
    if (age != 36) ERROR;

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
