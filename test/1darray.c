#include "lite_pack/1darray/1darray.h"
#include "helper.h"
#include "lite_pack/lite_pack.h"

static unsigned char buffer[1024 * 1024] = {0};

static int8_t const input_i8[] = {-2, 4};
static int8_t output_i8[array_size(input_i8)] = {0};

static int16_t const input_i16[] = {-2, 4};
static int16_t output_i16[array_size(input_i16)] = {0};

static int32_t const input_i32[] = {-2, 4};
static int32_t output_i32[array_size(input_i32)] = {0};

static int64_t const input_i64[] = {-2, 4};
static int64_t output_i64[array_size(input_i64)] = {0};

static uint8_t const input_u8[] = {0, 11, 31};
static uint8_t output_u8[array_size(input_u8)] = {0};

static uint16_t const input_u16[] = {0, 11, 31};
static uint16_t output_u16[array_size(input_u16)] = {0};

static uint32_t const input_u32[] = {0, 11, 31};
static uint32_t output_u32[array_size(input_u32)] = {0};

static uint64_t const input_u64[] = {0, 11, 31};
static uint64_t output_u64[array_size(input_u64)] = {0};

static float const input_f32[] = {-21.0f, 1.2f, 3.4f, 5.2f};
static float output_f32[array_size(input_f32)] = {0};

static double const input_f64[] = {-21.0, 1.2, 3.4, 5.2};
static double output_f64[array_size(input_f64)] = {0};

static void test_i8(unsigned n, int8_t const input[], int8_t output[],
                    uint8_t type)
{
    unsigned sz = lip_pack_1darray_size_type(buffer, n, type);
    if (sz == 0) ERROR;
    lip_pack_1darray_i8_data(buffer + sz, n, input);

    uint8_t t = 0;
    sz = lip_unpack_1darray_size_type(buffer, &n, &t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    lip_unpack_1darray_i8_data(buffer + sz, n, output);
    for (unsigned i = 0; i < n; ++i)
    {
        if (input[i] != output[i]) ERROR;
    }

    sz = lip_pack_1darray_size_type(buffer, n, t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    memcpy(output, input, sizeof(*input) * n);
    lip_pack_1darray_i8_data_inplace((unsigned char *)output, n);

    sz = lip_unpack_1darray_size_type(buffer, &n, &t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    lip_unpack_1darray_i8_data_inplace((unsigned char *)output, n);
    for (unsigned i = 0; i < n; ++i)
    {
        if (input[i] != output[i]) ERROR;
    }
}

static void test_i16(unsigned n, int16_t const input[], int16_t output[],
                     uint8_t type)
{
    unsigned sz = lip_pack_1darray_size_type(buffer, n, type);
    if (sz == 0) ERROR;
    lip_pack_1darray_i16_data(buffer + sz, n, input);

    uint8_t t = 0;
    sz = lip_unpack_1darray_size_type(buffer, &n, &t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    lip_unpack_1darray_i16_data(buffer + sz, n, output);
    for (unsigned i = 0; i < n; ++i)
    {
        if (input[i] != output[i]) ERROR;
    }

    sz = lip_pack_1darray_size_type(buffer, n, t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    memcpy(output, input, sizeof(*input) * n);
    lip_pack_1darray_i16_data_inplace((unsigned char *)output, n);

    sz = lip_unpack_1darray_size_type(buffer, &n, &t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    lip_unpack_1darray_i16_data_inplace((unsigned char *)output, n);
    for (unsigned i = 0; i < n; ++i)
    {
        if (input[i] != output[i]) ERROR;
    }
}

static void test_i32(unsigned n, int32_t const input[], int32_t output[],
                     uint8_t type)
{
    unsigned sz = lip_pack_1darray_size_type(buffer, n, type);
    if (sz == 0) ERROR;
    lip_pack_1darray_i32_data(buffer + sz, n, input);

    uint8_t t = 0;
    sz = lip_unpack_1darray_size_type(buffer, &n, &t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    lip_unpack_1darray_i32_data(buffer + sz, n, output);
    for (unsigned i = 0; i < n; ++i)
    {
        if (input[i] != output[i]) ERROR;
    }

    sz = lip_pack_1darray_size_type(buffer, n, t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    memcpy(output, input, sizeof(*input) * n);
    lip_pack_1darray_i32_data_inplace((unsigned char *)output, n);

    sz = lip_unpack_1darray_size_type(buffer, &n, &t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    lip_unpack_1darray_i32_data_inplace((unsigned char *)output, n);
    for (unsigned i = 0; i < n; ++i)
    {
        if (input[i] != output[i]) ERROR;
    }
}

static void test_i64(unsigned n, int64_t const input[], int64_t output[],
                     uint8_t type)
{
    unsigned sz = lip_pack_1darray_size_type(buffer, n, type);
    if (sz == 0) ERROR;
    lip_pack_1darray_i64_data(buffer + sz, n, input);

    uint8_t t = 0;
    sz = lip_unpack_1darray_size_type(buffer, &n, &t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    lip_unpack_1darray_i64_data(buffer + sz, n, output);
    for (unsigned i = 0; i < n; ++i)
    {
        if (input[i] != output[i]) ERROR;
    }

    sz = lip_pack_1darray_size_type(buffer, n, t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    memcpy(output, input, sizeof(*input) * n);
    lip_pack_1darray_i64_data_inplace((unsigned char *)output, n);

    sz = lip_unpack_1darray_size_type(buffer, &n, &t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    lip_unpack_1darray_i64_data_inplace((unsigned char *)output, n);
    for (unsigned i = 0; i < n; ++i)
    {
        if (input[i] != output[i]) ERROR;
    }
}

static void test_u8(unsigned n, uint8_t const input[], uint8_t output[],
                    uint8_t type)
{
    unsigned sz = lip_pack_1darray_size_type(buffer, n, type);
    if (sz == 0) ERROR;
    lip_pack_1darray_u8_data(buffer + sz, n, input);

    uint8_t t = 0;
    sz = lip_unpack_1darray_size_type(buffer, &n, &t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    lip_unpack_1darray_u8_data(buffer + sz, n, output);
    for (unsigned i = 0; i < n; ++i)
    {
        if (input[i] != output[i]) ERROR;
    }

    sz = lip_pack_1darray_size_type(buffer, n, t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    memcpy(output, input, sizeof(*input) * n);
    lip_pack_1darray_u8_data_inplace((unsigned char *)output, n);

    sz = lip_unpack_1darray_size_type(buffer, &n, &t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    lip_unpack_1darray_u8_data_inplace((unsigned char *)output, n);
    for (unsigned i = 0; i < n; ++i)
    {
        if (input[i] != output[i]) ERROR;
    }
}

static void test_u16(unsigned n, uint16_t const input[], uint16_t output[],
                     uint8_t type)
{
    unsigned sz = lip_pack_1darray_size_type(buffer, n, type);
    if (sz == 0) ERROR;
    lip_pack_1darray_u16_data(buffer + sz, n, input);

    uint8_t t = 0;
    sz = lip_unpack_1darray_size_type(buffer, &n, &t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    lip_unpack_1darray_u16_data(buffer + sz, n, output);
    for (unsigned i = 0; i < n; ++i)
    {
        if (input[i] != output[i]) ERROR;
    }

    sz = lip_pack_1darray_size_type(buffer, n, t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    memcpy(output, input, sizeof(*input) * n);
    lip_pack_1darray_u16_data_inplace((unsigned char *)output, n);

    sz = lip_unpack_1darray_size_type(buffer, &n, &t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    lip_unpack_1darray_u16_data_inplace((unsigned char *)output, n);
    for (unsigned i = 0; i < n; ++i)
    {
        if (input[i] != output[i]) ERROR;
    }
}

static void test_u32(unsigned n, uint32_t const input[], uint32_t output[],
                     uint8_t type)
{
    unsigned sz = lip_pack_1darray_size_type(buffer, n, type);
    if (sz == 0) ERROR;
    lip_pack_1darray_u32_data(buffer + sz, n, input);

    uint8_t t = 0;
    sz = lip_unpack_1darray_size_type(buffer, &n, &t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    lip_unpack_1darray_u32_data(buffer + sz, n, output);
    for (unsigned i = 0; i < n; ++i)
    {
        if (input[i] != output[i]) ERROR;
    }

    sz = lip_pack_1darray_size_type(buffer, n, t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    memcpy(output, input, sizeof(*input) * n);
    lip_pack_1darray_u32_data_inplace((unsigned char *)output, n);

    sz = lip_unpack_1darray_size_type(buffer, &n, &t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    lip_unpack_1darray_u32_data_inplace((unsigned char *)output, n);
    for (unsigned i = 0; i < n; ++i)
    {
        if (input[i] != output[i]) ERROR;
    }
}

static void test_u64(unsigned n, uint64_t const input[], uint64_t output[],
                     uint8_t type)
{
    unsigned sz = lip_pack_1darray_size_type(buffer, n, type);
    if (sz == 0) ERROR;
    lip_pack_1darray_u64_data(buffer + sz, n, input);

    uint8_t t = 0;
    sz = lip_unpack_1darray_size_type(buffer, &n, &t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    lip_unpack_1darray_u64_data(buffer + sz, n, output);
    for (unsigned i = 0; i < n; ++i)
    {
        if (input[i] != output[i]) ERROR;
    }

    sz = lip_pack_1darray_size_type(buffer, n, t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    memcpy(output, input, sizeof(*input) * n);
    lip_pack_1darray_u64_data_inplace((unsigned char *)output, n);

    sz = lip_unpack_1darray_size_type(buffer, &n, &t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    lip_unpack_1darray_u64_data_inplace((unsigned char *)output, n);
    for (unsigned i = 0; i < n; ++i)
    {
        if (input[i] != output[i]) ERROR;
    }
}

static void test_f32(unsigned n, float const input[], float output[],
                     uint8_t type)
{
    unsigned sz = lip_pack_1darray_size_type(buffer, n, type);
    if (sz == 0) ERROR;
    lip_pack_1darray_f32_data(buffer + sz, n, input);

    uint8_t t = 0;
    sz = lip_unpack_1darray_size_type(buffer, &n, &t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    lip_unpack_1darray_f32_data(buffer + sz, n, output);
    for (unsigned i = 0; i < n; ++i)
    {
        if (input[i] != output[i]) ERROR;
    }

    sz = lip_pack_1darray_size_type(buffer, n, t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    memcpy(output, input, sizeof(*input) * n);
    lip_pack_1darray_f32_data_inplace((unsigned char *)output, n);

    sz = lip_unpack_1darray_size_type(buffer, &n, &t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    lip_unpack_1darray_f32_data_inplace((unsigned char *)output, n);
    for (unsigned i = 0; i < n; ++i)
    {
        if (input[i] != output[i]) ERROR;
    }
}

static void test_f64(unsigned n, double const input[], double output[],
                     uint8_t type)
{
    unsigned sz = lip_pack_1darray_size_type(buffer, n, type);
    if (sz == 0) ERROR;
    lip_pack_1darray_f64_data(buffer + sz, n, input);

    uint8_t t = 0;
    sz = lip_unpack_1darray_size_type(buffer, &n, &t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    lip_unpack_1darray_f64_data(buffer + sz, n, output);
    for (unsigned i = 0; i < n; ++i)
    {
        if (input[i] != output[i]) ERROR;
    }

    sz = lip_pack_1darray_size_type(buffer, n, t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    memcpy(output, input, sizeof(*input) * n);
    lip_pack_1darray_f64_data_inplace((unsigned char *)output, n);

    sz = lip_unpack_1darray_size_type(buffer, &n, &t);
    if (sz == 0) ERROR;
    if (t != type) ERROR;
    lip_unpack_1darray_f64_data_inplace((unsigned char *)output, n);
    for (unsigned i = 0; i < n; ++i)
    {
        if (input[i] != output[i]) ERROR;
    }
}

int main(void)
{
    test_i8(array_size(input_i8), input_i8, output_i8, LIP_1DARRAY_INT8);
    test_i16(array_size(input_i16), input_i16, output_i16, LIP_1DARRAY_INT16);
    test_i32(array_size(input_i32), input_i32, output_i32, LIP_1DARRAY_INT32);
    test_i64(array_size(input_i64), input_i64, output_i64, LIP_1DARRAY_INT64);

    test_u8(array_size(input_u8), input_u8, output_u8, LIP_1DARRAY_UINT8);
    test_u16(array_size(input_u16), input_u16, output_u16, LIP_1DARRAY_UINT16);
    test_u32(array_size(input_u32), input_u32, output_u32, LIP_1DARRAY_UINT32);
    test_u64(array_size(input_u64), input_u64, output_u64, LIP_1DARRAY_UINT64);

    test_f32(array_size(input_f32), input_f32, output_f32, LIP_1DARRAY_F32);
    test_f64(array_size(input_f64), input_f64, output_f64, LIP_1DARRAY_F64);
    return 0;
}
