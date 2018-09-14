#ifndef WINC_UTILS_MULTITHREADING_MUTEX_H
#define WINC_UTILS_MULTITHREADING_MUTEX_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdio.h>
#include <stdlib.h>

#include "../debug.h"
#include "../typedef.h"

#ifdef __unix__

    #include <pthread.h>
    typedef pthread_mutex_t mutex_t;

#elif defined(_WIN32) || defined(WIN32)

    #include <Windows.h>
    typedef HANDLE mutex_t;

#endif // __unix__ and WIN32

bool create_mutex(mutex_t* mutex);
bool destroy_mutex(mutex_t* mutex);

void mutex_lock(mutex_t* mutex);
void mutex_unlock(mutex_t* mutex);
bool mutex_try_lock(mutex_t* mutex);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // WINC_UTILS_MULTITHREADING_MUTEX_H
