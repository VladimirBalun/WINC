#include <stdio.h>
#include <stdlib.h>

#include "winc/utils/multithreading/mutex.h"

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
        printf("Mutex wasn't locked.\n");
    }

    mutex_lock(&mutex);
    if (mutex_try_lock(&mutex) == true)
    {
        printf("Mutex was locked.\n");
    }
    else
    {
        printf("Mutex wasn't locked.\n");
    }

    mutex_unlock(&mutex);
    return EXIT_SUCCESS;
}
