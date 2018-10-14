/*
 * Copyright 2018 Vladimir Balun
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

 /*!
 \file mutex.h
 \authors VladimirBalun
 \brief File for working with mutexes.
 */
#ifndef WINC_UTILS_MULTITHREADING_MUTEX_H
#define WINC_UTILS_MULTITHREADING_MUTEX_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "winc/utils/typedef.h"

#ifdef __unix__

    #include <pthread.h>
    typedef pthread_mutex_t mutex_t;

#elif defined(_WIN32) || defined(WIN32)

    #include <Windows.h>
    typedef HANDLE mutex_t;

#endif // __unix__ and WIN32

bool create_mutex(mutex_t* mutex);

bool destroy_mutex(mutex_t* mutex);

bool mutex_lock(mutex_t* mutex);

bool mutex_unlock(mutex_t* mutex);

bool mutex_try_lock(mutex_t* mutex);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // WINC_UTILS_MULTITHREADING_MUTEX_H
