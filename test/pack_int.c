#include "helper.h"
#include "lite_pack.h"

#define ROW_SIZE 128
#define MAX_NUM_VALUES 256

static uint8_t buf[1024 * 128] = {0};
static long long values[MAX_NUM_VALUES];
static unsigned nvalues = 0;

static int read_int_values(char const *input)
{
    FILE *fp = fopen(input, "r");
    if (!fp) ERROR;

    char buffer[ROW_SIZE] = {0};

    nvalues = 0;
    while (fgets(buffer, ROW_SIZE, fp))
    {
        values[nvalues] = atoll(buffer);
        ++nvalues;
        if (nvalues >= MAX_NUM_VALUES) ERROR;
    }

    fclose(fp);
    return 0;
}

static int write_int_values(char const *output)
{
    uint8_t *ptr = buf;
    ptr += lip_pack_array_size(ptr, nvalues);

    for (unsigned i = 0; i < nvalues; ++i)
    {
        ptr += lip_pack_int(ptr, values[i]);
    }

    FILE *fp = fopen(output, "wb");
    if (!fp) ERROR;
    if (fwrite(buf, (unsigned)(ptr - buf), 1, fp) != 1) ERROR;
    fclose(fp);
    return 0;
}

int main(void)
{
    if (read_int_values(ASSETS "/u32.txt")) ERROR;
    if (write_int_values(TMPDIR "/u32_c.mp")) ERROR;
    if (!are_files_equal(TMPDIR "/u32_c.mp", TMPDIR "/u32_py.mp")) ERROR;

    if (read_int_values(ASSETS "/i32.txt")) ERROR;
    if (write_int_values(TMPDIR "/i32_c.mp")) ERROR;
    if (!are_files_equal(TMPDIR "/i32_c.mp", TMPDIR "/i32_py.mp")) ERROR;

    if (read_int_values(ASSETS "/u64.txt")) ERROR;
    if (write_int_values(TMPDIR "/u64_c.mp")) ERROR;
    if (!are_files_equal(TMPDIR "/u64_c.mp", TMPDIR "/u64_py.mp")) ERROR;

    if (read_int_values(ASSETS "/i64.txt")) ERROR;
    if (write_int_values(TMPDIR "/i64_c.mp")) ERROR;
    if (!are_files_equal(TMPDIR "/i64_c.mp", TMPDIR "/i64_py.mp")) ERROR;
    return 0;
}
