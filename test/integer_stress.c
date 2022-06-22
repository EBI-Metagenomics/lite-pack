#include "helper.h"
#include "lite_pack/lite_pack.h"

static unsigned char buf[9] = {0};

static int test_i8(void)
{
    if (lip_store_int8(buf, -1) != 2) ERROR;

    uint8_t u8 = 0;
    if (lip_unpack_int(buf, &u8) != 0) ERROR;

    uint16_t u16 = 0;
    if (lip_unpack_int(buf, &u16) != 0) ERROR;

    uint32_t u32 = 0;
    if (lip_unpack_int(buf, &u32) != 0) ERROR;

    uint64_t u64 = 0;
    if (lip_unpack_int(buf, &u64) != 0) ERROR;

    return 0;
}

static int test_i16(void)
{
    if (lip_store_int16(buf, -1) != 3) ERROR;

    uint8_t u8 = 0;
    if (lip_unpack_int(buf, &u8) != 0) ERROR;

    uint16_t u16 = 0;
    if (lip_unpack_int(buf, &u16) != 0) ERROR;

    uint32_t u32 = 0;
    if (lip_unpack_int(buf, &u32) != 0) ERROR;

    uint64_t u64 = 0;
    if (lip_unpack_int(buf, &u64) != 0) ERROR;

    return 0;
}

static int test_i32(void)
{
    if (lip_store_int32(buf, -1) != 5) ERROR;

    uint8_t u8 = 0;
    if (lip_unpack_int(buf, &u8) != 0) ERROR;

    uint16_t u16 = 0;
    if (lip_unpack_int(buf, &u16) != 0) ERROR;

    uint32_t u32 = 0;
    if (lip_unpack_int(buf, &u32) != 0) ERROR;

    uint64_t u64 = 0;
    if (lip_unpack_int(buf, &u64) != 0) ERROR;

    return 0;
}

static int test_i64(void)
{
    if (lip_store_int64(buf, -1) != 9) ERROR;

    uint8_t u8 = 0;
    if (lip_unpack_int(buf, &u8) != 0) ERROR;

    uint16_t u16 = 0;
    if (lip_unpack_int(buf, &u16) != 0) ERROR;

    uint32_t u32 = 0;
    if (lip_unpack_int(buf, &u32) != 0) ERROR;

    uint64_t u64 = 0;
    if (lip_unpack_int(buf, &u64) != 0) ERROR;

    return 0;
}

static int test_u8(void)
{
    if (lip_store_uint8(buf, UINT8_MAX) != 2) ERROR;

    int8_t i8 = 0;
    if (lip_unpack_int(buf, &i8) != 0) ERROR;

    int16_t i16 = 0;
    if (lip_unpack_int(buf, &i16) != 2) ERROR;
    if (i16 != UINT8_MAX) ERROR;

    int32_t i32 = 0;
    if (lip_unpack_int(buf, &i32) != 2) ERROR;
    if (i32 != UINT8_MAX) ERROR;

    int64_t i64 = 0;
    if (lip_unpack_int(buf, &i64) != 2) ERROR;
    if (i64 != UINT8_MAX) ERROR;

    return 0;
}

static int test_u16(void)
{
    if (lip_store_uint16(buf, UINT16_MAX) != 3) ERROR;

    int8_t i8 = 0;
    if (lip_unpack_int(buf, &i8) != 0) ERROR;

    int16_t i16 = 0;
    if (lip_unpack_int(buf, &i16) != 0) ERROR;

    int32_t i32 = 0;
    if (lip_unpack_int(buf, &i32) != 3) ERROR;
    if (i32 != UINT16_MAX) ERROR;

    int64_t i64 = 0;
    if (lip_unpack_int(buf, &i64) != 3) ERROR;
    if (i64 != UINT16_MAX) ERROR;

    return 0;
}

static int test_u32(void)
{
    if (lip_store_uint32(buf, UINT32_MAX) != 5) ERROR;

    int8_t i8 = 0;
    if (lip_unpack_int(buf, &i8) != 0) ERROR;

    int16_t i16 = 0;
    if (lip_unpack_int(buf, &i16) != 0) ERROR;

    int32_t i32 = 0;
    if (lip_unpack_int(buf, &i32) != 0) ERROR;

    int64_t i64 = 0;
    if (lip_unpack_int(buf, &i64) != 5) ERROR;
    if (i64 != UINT32_MAX) ERROR;

    return 0;
}

static int test_u64(void)
{
    if (lip_store_uint64(buf, UINT64_MAX) != 9) ERROR;

    int8_t i8 = 0;
    if (lip_unpack_int(buf, &i8) != 0) ERROR;

    int16_t i16 = 0;
    if (lip_unpack_int(buf, &i16) != 0) ERROR;

    int32_t i32 = 0;
    if (lip_unpack_int(buf, &i32) != 0) ERROR;

    int64_t i64 = 0;
    if (lip_unpack_int(buf, &i64) != 0) ERROR;

    return 0;
}

int main(void)
{
    return test_i8() | test_i16() | test_i32() | test_i64() | test_u8() |
           test_u16() | test_u32() | test_u64();
}
