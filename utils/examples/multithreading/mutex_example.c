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

#include <stdio.h>
#include <stdlib.h>

#include <winc/utils/multithreading/mutex.h>

int main()
{
    mutex_t mutex;
    if (!create_mutex(&mutex))
    {
        fprintf(stderr, "Mutex wasn't created.\n");
        return EXIT_FAILURE;
    }

    if (mutex_try_lock(&mutex))
    {
        printf("Mutex was locked.\n");
        mutex_unlock(&mutex);
    }
    else
    {
        fprintf(stderr, "Mutex wasn't locked.\n");
    }

    mutex_lock(&mutex);
    if (mutex_try_lock(&mutex) == true)
        fprintf(stderr, "Mutex was locked.\n");
    else
        printf("Mutex wasn't locked.\n");
    mutex_unlock(&mutex);

    if (!destroy_mutex(&mutex))
    {
        fprintf(stderr, "Mutex wasn't destroyed.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
