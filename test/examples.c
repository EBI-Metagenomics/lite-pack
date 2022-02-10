#include "helper.h"
#include "lite_pack/lite_pack.h"

static unsigned char buf[1024] = {0};

static int test_example1_write(size_t *size)
{
    FILE *fp = fopen("example1.mp", "wb");

    unsigned char *ptr = buf;

    ptr += lip_pack_map_size(ptr, 2);

    ptr += lip_pack_str_size(ptr, 4);
    ptr += lip_pack_str_data(ptr, 4, "name");

    ptr += lip_pack_str_size(ptr, 12);
    ptr += lip_pack_str_data(ptr, 12, "Danilo Horta");

    ptr += lip_pack_str_size(ptr, 3);
    ptr += lip_pack_str_data(ptr, 3, "age");

    ptr += lip_pack_int(ptr, 36U);

    *size = fwrite(buf, 1, (size_t)(ptr - buf), fp);

    fclose(fp);

    return 0;
}

static int test_example1_read(size_t *size)
{
    FILE *fp = fopen("example1.mp", "rb");

    char str[256] = {0};
    unsigned char *ptr = buf;

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

static int test_example2_write(size_t *size)
{
    FILE *fp = fopen("example2.mp", "wb");

    unsigned char *ptr = buf;

    ptr += lip_pack_array_size(ptr, 2);

    ptr += lip_pack_array_size(ptr, 2);
    ptr += lip_pack_int(ptr, 0);
    ptr += lip_pack_int(ptr, 1);

    ptr += lip_pack_int(ptr, 2);
    ptr += lip_pack_int(ptr, 3);

    *size = fwrite(buf, 1, (size_t)(ptr - buf), fp);

    fclose(fp);

    return 0;
}

static int test_example2_read(size_t *size)
{
    FILE *fp = fopen("example2.mp", "rb");

    unsigned char *ptr = buf;

    fread(buf, 1, *size, fp);
    ptr = buf;

    unsigned sz = 0;
    ptr += lip_unpack_array_size(ptr, &sz);
    if (sz != 2) ERROR;

    ptr += lip_unpack_array_size(ptr, &sz);
    if (sz != 2) ERROR;

    int v = 0;

    ptr += lip_unpack_int(ptr, &v);
    if (v != 0) ERROR;

    ptr += lip_unpack_int(ptr, &v);
    if (v != 1) ERROR;

    ptr += lip_unpack_int(ptr, &v);
    if (v != 2) ERROR;

    ptr += lip_unpack_int(ptr, &v);
    if (v != 3) ERROR;

    if ((size_t)(ptr - buf) != *size) ERROR;

    fclose(fp);

    return 0;
}

static int test_example2(void)
{
    size_t size = 0;
    if (test_example2_write(&size)) ERROR;
    if (test_example2_read(&size)) ERROR;
    return 0;
}

int main(void) { return test_example1() | test_example2(); }
