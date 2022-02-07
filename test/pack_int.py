#!/usr/bin/env python3

import sys

import msgpack

input_filepath = sys.argv[1]
output_filepath = sys.argv[2]

values = []
for row in open(input_filepath, "r"):
    values.append(int(row.strip()))

with open(output_filepath, "wb") as file:
    msgpack.dump(values, file)
