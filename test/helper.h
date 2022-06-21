#ifndef HELPER_H
#define HELPER_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define array_size(arr) (sizeof(arr) / sizeof((arr)[0]))

#define clear(buf) memset(buf, 0, sizeof(buf))

#define ERROR                                                                  \
    do                                                                         \
    {                                                                          \
        fprintf(stderr, "\nFailure at %s:%d\n", __func__, __LINE__);           \
        exit(1);                                                               \
    } while (1);

bool are_files_equal(char const *, char const *);
char *lorem_new(size_t length);

#endif
