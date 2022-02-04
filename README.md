# Lite Pack

C library implementing the amazing [MessagePack](https://msgpack.org) serialisation format.

## Description

There are a few exceptional alternative libraries listed at the end of this README.
However, I wanted to have more control on how the serialisation is done mainly
for performance reasons.
In particular, I wanted to make it easy for the user to implement
its own [extension types](https://github.com/msgpack/msgpack/blob/master/spec.md#extension-types)
with zero-copy writing and reading
(Think about [homogeneous-typed arrays](https://github.com/msgpack/msgpack/pull/267).)
The excellent CMP library, for example, has an old [open issue](https://github.com/camgunz/cmp/issues/29)
on a related matter but its API would need to be heavily modified to allow it to happen.

## Getting Started

### Dependencies

- It currently works on MacOS and Linux and requires up-to-date compiler supporting C11 standard.

### Installing

- I recommend for now copying the files from the `src/` directory into your project.

### Build and test it

Clone it and enter the following commands:

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
make test
```

## Help

Please, consider raising an GitHub issue.

## Authors

- [@horta](https://github.com/horta)

## Version History

It is in alpha stage.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- [CMP](https://github.com/camgunz/cmp)
- [CWPack](https://github.com/clwi/CWPack)
- [MPack](https://github.com/ludocode/mpack)
- [msgpack](https://github.com/msgpack/msgpack-c)
