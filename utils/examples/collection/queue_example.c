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

#include "winc/utils/collection/queue.h"

int main(int argc, char** argv)
{
    char* data1 = "Text1";
    char* data2 = "Text2";
    char* data3 = "Text3";

    queue_t* queue = init_queue();
    push_queue(queue, data3);
    push_queue(queue, data2);
    push_queue(queue, data1);

    printf("Size queue: %ld\n", get_size_queue(queue));
    while (!is_empty_queue(queue))
    {
        printf("Front element: %s\n", (char*) queue_front(queue));
        pop_queue(queue);
    }

    destroy_queue(queue);

    return EXIT_SUCCESS;
}
