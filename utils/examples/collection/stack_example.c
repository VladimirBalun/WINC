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

#include "winc/utils/collection/stack.h"

int main(int argc, char** argv)
{
    char* data1 = "Text1";
    char* data2 = "Text2";
    char* data3 = "Text3";

    stack_t* stack = init_stack();
    push_stack(stack, data3);
    push_stack(stack, data2);
    push_stack(stack, data1);

    printf("Size stack: %ld\n", get_size_stack(stack));
    while (!is_empty_stack(stack))
    {
        printf("Top element: %s\n", (char*) stack_top(stack));
        pop_stack(stack);
    }

    destroy_stack(stack);

    return EXIT_SUCCESS;
}
