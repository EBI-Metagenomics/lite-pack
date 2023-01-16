#ifndef LIP_API_H
#define LIP_API_H

/* clang-format off */
#ifdef LIP_STATIC_DEFINE
#  define LIP_API
#else
#  ifdef lip_EXPORTS /* We are building this library */
#    ifdef _WIN32
#      define LIP_API __declspec(dllexport)
#    else
#      define LIP_API __attribute__((visibility("default")))
#    endif
#  else /* We are using this library */
#    ifdef _WIN32
#      define LIP_API __declspec(dllimport)
#    else
#      define LIP_API __attribute__((visibility("default")))
#    endif
#  endif
#endif
/* clang-format on */

#endif
