CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2
SRC = lite_pack.c
HDR = lite_pack.h
OBJ = $(SRC:.c=.o)
LIB = liblite_pack.a
TEST_SRC = $(wildcard test_*.c)
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_TARGET = $(basename $(TEST_OBJ))

all: $(LIB)

$(LIB): $(OBJ)
	ar rcs $@ $<

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_TARGET): %: %.o $(LIB) $(HDR)
	$(CC) $(CFLAGS) $< -L. -llite_pack -o $@

check: $(TEST_TARGET)
	for test in $(TEST_TARGET); do ./$$test || exit 1; done

.PHONY: all clean check
clean:
	rm -f $(OBJ) $(LIB) $(TEST_OBJ) $(TEST_TARGET)
