# Lite Pack

A C library implementing the [MessagePack](https://msgpack.org) serialisation format.

## Description

There are a few exceptional alternative libraries listed at the end of this README.
However, I wanted greater control over the serialisation process, primarily for performance reasons.
In particular, I aimed to make it easier for users to implement their own [extension types](https://github.com/msgpack/msgpack/blob/master/spec.md#extension-types)
with zero-copy writing and reading (e.g., [homogeneous-typed arrays](https://github.com/msgpack/msgpack/pull/267)).

The CMP library, for example, has a long-standing [open issue](https://github.com/camgunz/cmp/issues/29)
on a related topic, but its API would require substantial modification to support this functionality.

## Getting Started

Add the files `lite_pack.c` `lite_pack.h` to your project and compile
using a C11-compatible compiler.

## Example

The example bellow packs an array of 3 values of the following types:
floating-point, integer, and boolean.

```c
#include "lite_pack.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  unsigned char buffer[16] = {0};
  unsigned char *pointer = buffer;

  pointer += lip_pack_array(pointer, 3);
  pointer += lip_pack_float(pointer, 3.14);
  pointer += lip_pack_int(pointer, 42);
  pointer += lip_pack_bool(pointer, true);

  printf("Number of bytes packed: %ld\n", pointer - buffer);

  pointer = buffer;

  uint32_t array_size = 0;
  float float_value = 0;
  int int_value = 0;
  bool bool_value = 0;

  pointer += lip_unpack_array(pointer, &array_size);
  pointer += lip_unpack_float(pointer, &float_value);
  pointer += lip_unpack_int(pointer, &int_value);
  pointer += lip_unpack_bool(pointer, &bool_value);

  printf("Number of bytes unpacked: %ld\n", pointer - buffer);
  printf("Array size: %u\n", array_size);
  printf("Float value: %f\n", float_value);
  printf("Int value: %d\n", int_value);
  printf("Bool value: %d\n", bool_value);

  return 0;
}
```

Running the compiled example on my machine outputs:

```
Number of bytes packed: 12
Number of bytes unpacked: 1
Array size: 3
Float value: 0.000000
Int value: 0
Bool value: 0
```

## Build, Check, and Install

```
make
make check
make install
```

## Help

If you encounter any issues, please consider raising a GitHub issue.

## Authors

- [@horta](https://github.com/horta)

## Version History

This project is currently in the alpha stage.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- [CMP](https://github.com/camgunz/cmp)
- [CWPack](https://github.com/clwi/CWPack)
- [MPack](https://github.com/ludocode/mpack)
- [msgpack](https://github.com/msgpack/msgpack-c)
