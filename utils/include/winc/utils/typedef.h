#ifndef WINC_UTILS_TYPEDEF_H
#define WINC_UTILS_TYPEDEF_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef int bool;
#define true  1
#define false 0

// Eroor exit statuses for SICO
#define SYSTEM_ERROR         -1
#define ASSERT_FAILED        -2
#define MEMORY_NOT_ALLOCATED -3

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // WINC_UTILS_TYPEDEF_H
