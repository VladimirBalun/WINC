#ifndef WINC_UTILS_COLLECTION_LIST_H
#define WINC_UTILS_COLLECTION_LIST_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../debug.h"
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

// Private functions for working with list.
static void _make_empty_list(list_t list);
static list_iterator_t _allocate_memory_for_node();
static void _insert_first_node(list_t list, void* data);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // WINC_UTILS_COLLECTION_LIST_H
