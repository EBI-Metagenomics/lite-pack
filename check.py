import struct
from io import BytesIO
from random import Random

import msgpack
from _lite_pack_cffi import ffi, lib


def check_bool():
    buffer = ffi.new("unsigned char[]", 1)
    for x in [False, True]:
        lib.lip_pack_bool(buffer, x)
        assert msgpack.unpackb(ffi.buffer(buffer)) == x


def check_integer():
    buffer = ffi.new("unsigned char[]", 9)
    random = Random(91283)

    integer_functions = {
        8: {
            "unsigned": {"pack": lib.lip_pack_u8, "unpack": lib.lip_unpack_u8},
            "signed": {"pack": lib.lip_pack_i8, "unpack": lib.lip_unpack_i8},
        },
        16: {
            "unsigned": {"pack": lib.lip_pack_u16, "unpack": lib.lip_unpack_u16},
            "signed": {"pack": lib.lip_pack_i16, "unpack": lib.lip_unpack_i16},
        },
        32: {
            "unsigned": {"pack": lib.lip_pack_u32, "unpack": lib.lip_unpack_u32},
            "signed": {"pack": lib.lip_pack_i32, "unpack": lib.lip_unpack_i32},
        },
        64: {
            "unsigned": {"pack": lib.lip_pack_u64, "unpack": lib.lip_unpack_u64},
            "signed": {"pack": lib.lip_pack_i64, "unpack": lib.lip_unpack_i64},
        },
    }

    for _ in range(1000):
        widths = [8, 16, 32, 64]
        for width in widths:
            unsigned_max = (1 << width) - 1
            signed_min = -(1 << (width - 1))
            signed_max = (1 << (width - 1)) - 1

            x = random.randint(0, unsigned_max)
            sz = integer_functions[width]["unsigned"]["pack"](buffer, x)
            assert msgpack.unpackb(ffi.buffer(buffer)[:sz]) == x

            x = random.randint(signed_min, signed_max)
            sz = integer_functions[width]["signed"]["pack"](buffer, x)
            assert msgpack.unpackb(ffi.buffer(buffer)[:sz]) == x


def check_float():
    buffer = ffi.new("unsigned char[]", 9)
    random = Random(91283)
    for _ in range(1000):
        x = random.random()
        f = struct.unpack("f", struct.pack("f", x))[0]
        d = struct.unpack("d", struct.pack("d", x))[0]

        sz = lib.lip_pack_f32(buffer, f)
        assert msgpack.unpackb(ffi.buffer(buffer)[:sz]) == f

        sz = lib.lip_pack_f64(buffer, d)
        assert msgpack.unpackb(ffi.buffer(buffer)[:sz]) == d


def generate_lorem(length):
    paragraph = (
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod "
        "tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim "
        "veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea "
        "commodo consequat. Duis aute irure dolor in reprehenderit in voluptate "
        "velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint "
        "occaecat cupidatat non proident, sunt in culpa qui officia deserunt "
        "mollit anim id est laborum."
    )
    lorem = paragraph * (length // len(paragraph))
    lorem += paragraph[: length - len(lorem)]
    return lorem


def check_string():
    for length in [0, 0x1F, 0x20, 0xFF, 0x100, 0xFFFF, 0x10000]:
        buffer = ffi.new("unsigned char[]", length + 9)
        sz = lib.lip_pack_string(buffer, length)
        lorem = generate_lorem(length)
        lorem_buffer = ffi.from_buffer(lorem.encode())
        ffi.memmove(buffer + sz, lorem_buffer, length)
        assert msgpack.unpackb(ffi.buffer(buffer)[: sz + length]) == lorem


def check_array():
    buffer = ffi.new("unsigned char[]", 9)
    for x in [0, 15, 16, 65535, 65536, 4294967295]:
        sz = lib.lip_pack_array(buffer, x)
        buf = BytesIO(ffi.buffer(buffer)[:sz])
        unpacker = msgpack.Unpacker(buf)
        assert unpacker.read_array_header() == x


def check_map():
    buffer = ffi.new("unsigned char[]", 9)
    for x in [0, 15, 16, 65535, 65536, 4294967295]:
        sz = lib.lip_pack_map(buffer, x)
        buf = BytesIO(ffi.buffer(buffer)[:sz])
        unpacker = msgpack.Unpacker(buf)
        assert unpacker.read_map_header() == x


def check_bin():
    for length in [0, 0x1F, 0x20, 0xFF, 0x100, 0xFFFF, 0x10000]:
        buffer = ffi.new("unsigned char[]", length + 9)
        sz = lib.lip_pack_bin(buffer, length)
        lorem = generate_lorem(length)
        lorem_buffer = ffi.from_buffer(lorem.encode())
        ffi.memmove(buffer + sz, lorem_buffer, length)
        assert msgpack.unpackb(ffi.buffer(buffer)[: sz + length]) == lorem.encode()


def check_ext():
    for length in [0, 0x1F, 0x20, 0xFF, 0x100, 0xFFFF, 0x10000]:
        buffer = ffi.new("unsigned char[]", length + 9)
        sz = lib.lip_pack_ext(buffer, length, 33)
        lorem = generate_lorem(length)
        lorem_buffer = ffi.from_buffer(lorem.encode())
        ffi.memmove(buffer + sz, lorem_buffer, length)
        ext = msgpack.unpackb(ffi.buffer(buffer)[: sz + length])
        assert ext.code == 33
        assert ext.data == lorem.encode()


if __name__ == "__main__":
    check_bool()
    check_integer()
    check_float()
    check_string()
    check_array()
    check_map()
    check_bin()
    check_ext()
