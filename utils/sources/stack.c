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

#include "winc/utils/collection/stack.h"

typedef struct node_t* node_t;

struct node_t
{
    node_t prev;
    void*  data;
};

struct stack_t
{
    node_t tail;
    size_t size;
};

stack_t init_stack()
{
    stack_t stack = MALLOC(sizeof(stack_t));
    _make_empty_stack(stack);
    return stack;
}

void clear_stack(stack_t stack)
{
    node_t iterator = stack->tail;
    while (!iterator)
    {
        node_t del_node = iterator;
        iterator = iterator->prev;
        FREE(del_node);
    }
    stack->size = 0;
}

void destroy_stack(stack_t stack)
{
    clear_stack(stack);
    FREE(stack);
}

void move_stack(stack_t from_stack, stack_t to_stack)
{
    if (is_empty_stack(from_stack))
        return;

    if (!is_empty_stack(to_stack))
        clear_stack(to_stack);

    to_stack->tail = from_stack->tail;
    to_stack->size = from_stack->size;

    _make_empty_stack(from_stack);
}

void push_stack(stack_t stack, void* data)
{
    if (is_empty_stack(stack))
    {
        node_t new_node = MALLOC(sizeof(node_t));
        new_node->data = data;
        new_node->prev = NULL;
        stack->tail = new_node;
    }
    else
    {
        node_t new_node = MALLOC(sizeof(node_t));
        new_node->data = data;
        new_node->prev = stack->tail;
        stack->tail = new_node;
    }
    stack->size++;
}

void pop_stack(stack_t stack)
{
    if (is_empty_stack(stack))
        return;

    node_t del_node = stack->tail;
    stack->tail = stack->tail->prev;
    stack->size--;
    FREE(del_node);
}

void* stack_top(stack_t stack)
{
    if (stack->tail)
        return stack->tail->data;
    else
        return NULL;
}

size_t get_size_stack(stack_t stack)
{
    return stack->size;
}

bool is_empty_stack(stack_t stack)
{
    return stack->size == 0;
}

static void _make_empty_stack(stack_t stack)
{
    stack->tail = NULL;
    stack->size = 0;
}
