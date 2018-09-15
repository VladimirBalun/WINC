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

#include "winc/utils/collection/list.h"

int main(int argc, char** argv)
{
    char* data1 = "Text1";
    char* data2 = "Text2";
    char* data3 = "Text3";

    list_t list1 = init_list();
    push_back_list(list1, data1);
    push_back_list(list1, data2);
    push_back_list(list1, data3);

    list_iterator_t iterator = list_end(list1);
    while (list_has_prev(iterator))
    {
        printf("Data in the first list: %s\n", (char*) list_get(iterator));
        iterator = list_prev(iterator);
    }

    printf("First element of the first list: %s\n", (char*) list_at(list1, 0));
    printf("Last element of the first list: %s\n", (char*) list_at(list1, -1));

    list_t list2 = init_list();
    move_list(list1, list2);

    printf("Size the first list after moving: %ld\n", get_size_list(list1));
    printf("Size the second list after moving: %ld\n", get_size_list(list2));
    
    iterator = list_begin(list2);
    while (list_has_next(iterator))
    {
        printf("Data in the second list: %s\n", (char*) list_get(iterator));
        iterator = list_next(iterator);
    }

    destroy_list(list1);
    destroy_list(list2);

    return EXIT_SUCCESS;
}
