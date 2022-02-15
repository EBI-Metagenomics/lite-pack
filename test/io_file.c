#include "helper.h"
#include "lite_pack/io/file.h"
#include "lite_pack/lite_pack.h"

static void test_correct_usage()
{
    struct lip_io_file ctx = {0};

    ctx.fp = fopen(TMPDIR "/io_file.mp", "wb");
    lip_write_int(&ctx, 0);
    lip_write_int(&ctx, 39290);
    lip_write_array_size(&ctx, 2);
    lip_write_float(&ctx, 3.2f);
    lip_write_str_size(&ctx, 5);
    lip_write_str_data(&ctx, 5, "hello");
    if (ctx.error) ERROR;
    fclose(ctx.fp);

    ctx.fp = fopen(TMPDIR "/io_file.mp", "rb");
    int ival = 0;
    lip_read_int(&ctx, &ival);
    if (ival != 0) ERROR;
    lip_read_int(&ctx, &ival);
    if (ival != 39290) ERROR;
    unsigned uval = 0;
    lip_read_array_size(&ctx, &uval);
    if (uval != 2) ERROR;
    float fval = 0.f;
    lip_read_float(&ctx, &fval);
    if (fval != 3.2f) ERROR;
    lip_read_str_size(&ctx, &uval);
    if (uval != 5) ERROR;
    char hello[6] = {0};
    lip_read_str_data(&ctx, 5, hello);
    if (strncmp(hello, "hello", 5) != 0) ERROR;
    if (ctx.error) ERROR;
    fclose(ctx.fp);
}

static void test_incorrect_usage()
{
    struct lip_io_file ctx = {0};

    ctx.fp = fopen(TMPDIR "/io_file.mp", "wb");
    lip_write_int(&ctx, INT64_MAX);
    if (ctx.error) ERROR;
    fclose(ctx.fp);

    ctx.fp = fopen(TMPDIR "/io_file.mp", "rb");
    uint16_t x = 0;
    lip_read_int(&ctx, &x);
    if (!ctx.error) ERROR;
    fclose(ctx.fp);
}

int main(void)
{
    test_correct_usage();
    test_incorrect_usage();
    return 0;
}
