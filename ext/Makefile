CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2
SRC = lite_pack_io.c
HDR = lite_pack_io.h
OBJ = $(SRC:.c=.o)
LIB = liblite_pack_io.a
PREFIX := /usr/local
TEST_SRC = $(wildcard test_*.c)
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_TARGET = $(basename $(TEST_OBJ))

all: $(LIB)

$(LIB): $(OBJ)
	ar rcs $@ $<

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_TARGET): %: %.o $(LIB) $(HDR)
	$(CC) $(CFLAGS) $< -L. -llite_pack_io -llite_pack -o $@

check: $(TEST_TARGET)
	for test in $(TEST_TARGET); do ./$$test || exit 1; done

install: $(LIB)
	@mkdir -p $(PREFIX)/lib $(PREFIX)/include
	install -m 0755 $(LIB) $(PREFIX)/lib/
	install -m 0644 $(HDR) $(PREFIX)/include/

.PHONY: all clean check
clean:
	rm -f $(OBJ) $(LIB) $(TEST_OBJ) $(TEST_TARGET)
