#ifndef BUG_H
#define BUG_H

#include <assert.h>

#define __LIP_BUG()                                                            \
    do                                                                         \
    {                                                                          \
        assert(0);                                                             \
        __builtin_unreachable();                                               \
    } while (1)

#endif
