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

#ifndef WINC_UTILS_COLLECTION_QUEUE_H
#define WINC_UTILS_COLLECTION_QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../allocation.h"
#include "../typedef.h"

typedef struct queue_t queue_t;

queue_t* init_queue();
void clear_queue(queue_t* queue);
void destroy_queue(queue_t* queue);
void move_queue(queue_t* from_queue, queue_t* to_queue);

void push_queue(queue_t* queue, void* data);
void pop_queue(queue_t* queue);

void* queue_front(const queue_t* queue);
size_t get_size_queue(const queue_t* queue);
bool is_empty_queue(const queue_t* queue);

static void _make_empty_queue(queue_t* queue);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // WINC_UTILS_COLLECTION_QUEUE_H
