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

#ifndef WINC_UTILS_COLLECTION_PRIORITY_QUEUE_H
#define WINC_UTILS_COLLECTION_PRIORITY_QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../algorithm.h"
#include "../allocation.h"
#include "../typedef.h"

typedef struct priority_queue_t priority_queue_t;

priority_queue_t* init_priority_queuee(void (*comparator)(void*, void*));
void clear_priority_queue(priority_queue_t* priority_queue);
void destroy_priority_queue(priority_queue_t* priority_queue);
void move_priority_queue(priority_queue_t* from_priority_queue, priority_queue_t* to_priority_queue);

void push_priority_queue(priority_queue_t* priority_queue, void* data);
void pop_priority_queue(priority_queue_t* priority_queue);

void* priority_queue_front(const priority_queue_t* priority_queue);
size_t get_size_priority_queue(const priority_queue_t* priority_queue);
bool is_empty_priority_queue(const priority_queue_t* priority_queue);

static void _make_empty_priority_queue(priority_queue_t* priority_queue);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // WINC_UTILS_COLLECTION_PRIORITY_QUEUE_H
