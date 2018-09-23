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

#include "winc/utils/collection/queue.h"

#include <stdio.h>

typedef struct node_t node_t;

struct node_t
{
    node_t* next;
    void*   data;
};

struct queue_t
{
    node_t* head;
    size_t  size;
};

queue_t* init_queue()
{
    queue_t* queue = winc_malloc(sizeof(queue_t));
    _make_empty_queue(queue);
    return queue;
}

void clear_queue(queue_t* queue)
{
    node_t* iterator = queue->head;
    while (iterator)
    {
        node_t* del_node = iterator;
        iterator = iterator->next;
        winc_free(del_node);
    }
    _make_empty_queue(queue);
}

void destroy_queue(queue_t* queue)
{
    clear_queue(queue);
    winc_free(queue);
}

void move_queue(queue_t* from_queue, queue_t* to_queue)
{
    if (is_empty_queue(from_queue))
        return;

    if (!is_empty_queue(to_queue))
        clear_queue(to_queue);

    to_queue->head = from_queue->head;
    to_queue->size = from_queue->size;

    _make_empty_queue(from_queue);
}

void push_queue(queue_t* queue, void* data)
{
    if (is_empty_queue(queue))
    {
        node_t* new_node = winc_malloc(sizeof(node_t));
        new_node->data = data;
        new_node->next = NULL;
        queue->head = new_node;
    }
    else
    {
        node_t* new_node = winc_malloc(sizeof(node_t));
        new_node->data = data;
        new_node->next = queue->head;
        queue->head = new_node;
    }
    queue->size++;
}

void pop_queue(queue_t* queue)
{
    if (is_empty_queue(queue))
        return;

    node_t* del_node = queue->head;
    queue->head = queue->head->next;
    queue->size--;
    winc_free(del_node);
}

void* queue_front(const queue_t* queue)
{
    if (queue->head)
        return queue->head->data;
    else
        return NULL;
}

size_t get_size_queue(const queue_t* queue)
{
    return queue->size;
}

bool is_empty_queue(const queue_t* queue)
{
    return queue->size == 0;
}

static void _make_empty_queue(queue_t* queue)
{
    queue->head = NULL;
    queue->size = 0;
}
