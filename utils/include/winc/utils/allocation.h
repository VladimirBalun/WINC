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

#ifndef WINC_UTILS_ALLOCATION_H
#define WINC_UTILS_ALLOCATION_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdlib.h>
#include <string.h>

#include "debug.h"
#include "exit_statuses.h"

static inline void* winc_malloc(size_t size)
{
    void* ptr = malloc(size);
    if (!ptr)
    {
        ERROR_MSG("WINC: Memory wasn't allocated.");
        exit(MEMORY_NOT_ALLOCATED);
    }
    return ptr;
}

static inline void* winc_realloc(void* ptr, size_t size)
{
    ptr = realloc(ptr, size);
    if (!ptr)
    {
        ERROR_MSG("WINC: Memory wasn't reallocated.");
        exit(MEMORY_NOT_REALLOCATED);
    }
    return ptr;
}

static inline void winc_memcpy(void* destptr, void* srcptr, size_t size)
{
    if (!memcpy(destptr, srcptr, size))
    {
        ERROR_MSG("WINC: Memory wasn't copied.");
        exit(MEMORY_NOT_REALLOCATED);
    }
}

static inline void winc_free(void* ptr)
{
    free (ptr);
    ptr = NULL;
}

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // WINC_UTILS_ALLOCATION_H
