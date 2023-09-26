#ifndef LIP_COMPILER_H
#define LIP_COMPILER_H

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

#ifndef static_assert
#define static_assert(expr, msg) _Static_assert(expr, msg)
#endif

static_assert(CHAR_BIT == 8, "8-bits char");
static_assert(sizeof(int) >= 4, ">=32-bits int");
static_assert(sizeof(long) >= 8, ">=64-bits long");
static_assert(UINT8_MAX >= 255, "uint8 max req.");
static_assert(UINT16_MAX >= 65535, "uint16 max req.");
static_assert(UINT32_MAX >= 4294967295U, "uint32 max req.");

static_assert(sizeof(float) == 4, "32-bits float");
static_assert(sizeof(double) == 8, "64-bits double");

/*
 * Add the pseudo keyword 'fallthrough' so case statement blocks
 * must end with any of these keywords:
 *   break;
 *   fallthrough;
 *   continue;
 *   goto <label>;
 *   return [expression];
 *
 * gcc:
 * https://gcc.gnu.org/onlinedocs/gcc/Statement-Attributes.html#Statement-Attributes
 */
#if __has_attribute(__fallthrough__)
#define fallthrough __attribute__((__fallthrough__))
#else
#define fallthrough                                                            \
    do                                                                         \
    {                                                                          \
    } while (0) /* fallthrough */
#endif

#if defined(__FLOAT_WORD_ORDER__) && defined(__BYTE_ORDER__)
// We check where possible that the float byte order matches the
// integer byte order. This is extremely unlikely to fail, but
// we check anyway just in case.
//
// (The static assert is placed in float/double encoders instead
// of here because our static assert fallback doesn't work at
// file scope)
//
// Source: MPack library <https://github.com/ludocode/mpack>
#define CHECK_FLOAT_ORDER()                                                    \
    static_assert(                                                             \
        __FLOAT_WORD_ORDER__ == __BYTE_ORDER__,                                \
        "float byte order does not match int byte order! float/double "        \
        "encoding is not properly implemented on this platform.")

#endif

#ifndef CHECK_FLOAT_ORDER
#define CHECK_FLOAT_ORDER()
#endif

CHECK_FLOAT_ORDER();

#ifndef __always_inline
#define __always_inline inline
#endif

__attribute__((unused)) static __always_inline bool
__lip_maybe_unused_bool(bool v)
{
    return v;
}

__attribute__((unused)) static __always_inline unsigned
__lip_maybe_unused_unsigned(unsigned v)
{
    return v;
}

__attribute__((unused)) __attribute__((const)) static __always_inline int
__lip_bug_on_reach(void)
{
    assert(0);
    return 0;
}

#endif
