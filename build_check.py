import os

from cffi import FFI

ffi = FFI()
ffi.cdef("""
    size_t lip_pack_bool(unsigned char buffer[], bool data);
    size_t lip_pack_i8 (unsigned char buffer[], int8_t  data);
    size_t lip_pack_i16(unsigned char buffer[], int16_t data);
    size_t lip_pack_i32(unsigned char buffer[], int32_t data);
    size_t lip_pack_i64(unsigned char buffer[], int64_t data);
    size_t lip_pack_u8 (unsigned char buffer[], uint8_t  data);
    size_t lip_pack_u16(unsigned char buffer[], uint16_t data);
    size_t lip_pack_u32(unsigned char buffer[], uint32_t data);
    size_t lip_pack_u64(unsigned char buffer[], uint64_t data);
    size_t lip_pack_f32(unsigned char buffer[], float  data);
    size_t lip_pack_f64(unsigned char buffer[], double data);
    size_t lip_pack_string(unsigned char buffer[], uint32_t size);
    size_t lip_pack_array(unsigned char buffer[], uint32_t size);
    size_t lip_pack_map(unsigned char buffer[], uint32_t size);
    size_t lip_pack_ext(unsigned char buffer[], uint32_t size, uint8_t type);
    size_t lip_pack_bin(unsigned char buffer[], uint32_t size);

    size_t lip_unpack_bool(unsigned char const buffer[], bool *data);
    size_t lip_unpack_i8 (unsigned char const buffer[], int8_t  *data);
    size_t lip_unpack_i16(unsigned char const buffer[], int16_t *data);
    size_t lip_unpack_i32(unsigned char const buffer[], int32_t *data);
    size_t lip_unpack_i64(unsigned char const buffer[], int64_t *data);
    size_t lip_unpack_u8 (unsigned char const buffer[], uint8_t  *data);
    size_t lip_unpack_u16(unsigned char const buffer[], uint16_t *data);
    size_t lip_unpack_u32(unsigned char const buffer[], uint32_t *data);
    size_t lip_unpack_u64(unsigned char const buffer[], uint64_t *data);
    size_t lip_unpack_f32(unsigned char const buffer[], float  *data);
    size_t lip_unpack_f64(unsigned char const buffer[], double *data);
    size_t lip_unpack_string(unsigned char const buffer[], uint32_t *size);
    size_t lip_unpack_array(unsigned char const buffer[], uint32_t *size);
    size_t lip_unpack_map(unsigned char const buffer[], uint32_t *size);
    size_t lip_unpack_ext(unsigned char const buffer[], uint32_t *size, uint8_t *type);
    size_t lip_unpack_bin(unsigned char const buffer[], uint32_t *size);
""")

ffi.set_source(
    "_lite_pack_cffi",
    """
     #include "lite_pack.h"
""",
    extra_objects=[f"{os.path.dirname(os.path.realpath(__file__))}/liblite_pack.a"],
)

if __name__ == "__main__":
    ffi.compile(verbose=True)
