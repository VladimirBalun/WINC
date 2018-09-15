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

#ifndef WINC_UTILS_COLLECTION_LIST_H
#define WINC_UTILS_COLLECTION_LIST_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <math.h>

#include "../allocation.h"
#include "../typedef.h"

typedef struct list_t* list_t;
typedef struct node_t* list_iterator_t;

#define FOR_EACH_LIST(it, list) \
    for(list_iterator_t (it) = list_begin(list); list_has_next(it); (it) = list_next(it))

list_t init_list();
void clear_list(list_t list);
void destroy_list(list_t list);
void move_list(list_t from_list, list_t to_list);

void push_back_list(list_t list, void* data);
void pop_back_list(list_t list);
void push_front_list(list_t list, void* data);
void pop_front_list(list_t list);

void add_sublist_to_list_to_end(list_t list, list_t sublist);
void add_sublist_to_list_to_beginning(list_t list, list_t sublist);

size_t get_size_list(list_t list);
bool is_empty_list(list_t list);
bool is_contain_list(list_t list, const void* data);

void list_insert_after(list_t list, list_iterator_t it, void* data);
void list_insert_before(list_t list, list_iterator_t it, void* data);
void list_erase(list_t list, list_iterator_t it);

list_iterator_t list_begin(list_t list);
list_iterator_t list_end(list_t list);

bool list_has_next(list_iterator_t it);
bool list_has_prev(list_iterator_t it);

list_iterator_t list_next(list_iterator_t it);
list_iterator_t list_prev(list_iterator_t it);

void* list_get(list_iterator_t it);
void* list_at(list_t list, int index);
void* list_back(list_t list);
void* list_front(list_t list);

static void _make_empty_list(list_t list);
static void _insert_between_nodes(list_iterator_t lnode, list_iterator_t rnode, void* data);
static void _insert_first_node(list_t list, void* data);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // WINC_UTILS_COLLECTION_LIST_H
