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

#include "winc/utils/collection/list.h"

typedef struct node_t node_t;

struct node_t
{
    node_t* next;
    node_t* prev;
    void*   data;
};

struct list_t
{
    node_t* head;
    node_t* tail;
    size_t  size;
};

list_t* init_list()
{
    list_t* list = winc_malloc(sizeof(list_t));
    _make_empty_list(list);
    return list;
}

void clear_list(list_t* list)
{
    node_t* iterator = list->tail;
    while (iterator != NULL)
    {
        node_t* del_node = iterator;
        iterator = iterator->prev;
        winc_free(del_node);
    }
    _make_empty_list(list);
}

void destroy_list(list_t* list)
{
    clear_list(list);
    winc_free(list);
}

void move_list(list_t* from_list, list_t* to_list)
{
    if (is_empty_list(from_list))
        return;

    if (!is_empty_list(to_list))
        clear_list(to_list);

    to_list->head = from_list->head;
    to_list->tail = from_list->tail;
    to_list->size = from_list->size;

    _make_empty_list(from_list);
}

void push_back_list(list_t* list, void* data)
{
    if (is_empty_list(list))
    {
        _insert_first_node(list, data);
    }
    else
    {
        node_t* new_node = winc_malloc(sizeof(node_t));
        new_node->data = data;
        new_node->prev = list->tail;
        new_node->next = NULL;
        list->tail->next = new_node;
        list->tail = list->tail->next;
    }

    list->size++;
}

void pop_back_list(list_t* list)
{
    if (is_empty_list(list))
        return;

    node_t* del_node = list->tail;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    list->size--;
    winc_free(del_node);
}

void push_front_list(list_t* list, void* data)
{
    if (is_empty_list(list))
    {
        _insert_first_node(list, data);
    }
    else
    {
        node_t* new_node = winc_malloc(sizeof(node_t));
        new_node->data = data;
        new_node->next = list->head;
        new_node->prev = NULL;
        list->head->prev = new_node;
        list->head = list->head->prev;
    }

    list->size++;
}

void pop_front_list(list_t* list)
{
    if (is_empty_list(list))
        return;

    node_t* del_node = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    list->size--;
    winc_free(del_node);
}

void add_sublist_to_list_to_end(list_t* list, list_t* sublist)
{
    if (is_empty_list(sublist))
        return;

    if (!is_empty_list(list))
    {
        list->tail->next = sublist->head;
        sublist->head->prev = list->tail;
        list->tail = sublist->tail;
        list->size += sublist->size;
    }
    else
    {
        move_list(sublist, list);
    }

    _make_empty_list(sublist);
}

void add_sublist_to_list_to_beginning(list_t* list, list_t* sublist)
{
    if (is_empty_list(sublist))
        return;

    if (!is_empty_list(list))
    {
        list->head->prev = sublist->tail;
        sublist->tail->next = list->head;
        list->head = sublist->head;
        list->size += sublist->size;
    }
    else
    {
        move_list(sublist, list);
    }

    _make_empty_list(sublist);
}

size_t get_size_list(const list_t* list)
{
    return list->size;
}

bool is_empty_list(const list_t* list)
{
    return list->size == 0;
}

bool is_contain_list(const list_t* list, const void* data)
{
    node_t* iterator = list->head;
    while (iterator)
    {
        if (iterator->data == data)
            return true;
        iterator = iterator->next;
    }

    return false;
}

void list_insert_after(list_t* list, list_iterator_t it, void* data)
{
    if (!it)
        return;

    if (it->next)
    {
        node_t* prev_node = it;
        node_t* next_node = it->next;
        _insert_between_nodes(prev_node, next_node, data);
    }
    else
    {
        push_back_list(list, data);
    }

    list->size++;
}

void list_insert_before(list_t* list, list_iterator_t it, void* data)
{
    if (!it)
        return;

    if (it->prev)
    {
        node_t* prev_node = it->prev;
        node_t* next_node = it;
        _insert_between_nodes(prev_node, next_node, data);
    }
    else
    {
        push_front_list(list, data);
    }

    list->size++;
}

void list_erase(list_t* list, list_iterator_t it)
{
    node_t* prev_node = it->prev;
    node_t* next_node = it->next;

    if (prev_node)
        prev_node->next = next_node;
    if (next_node)
        next_node->prev = prev_node;

    list->size++;
    winc_free(it);
}

list_iterator_t list_begin(list_t* list)
{
    return list->head;
}

list_iterator_t list_end(list_t* list)
{
    return list->tail;
}

bool list_has_next(const list_iterator_t it)
{
    return (it) ? (true) : (false);
}

bool list_has_prev(const list_iterator_t it)
{
    return (it) ? (true) : (false);
}

list_iterator_t list_next(list_iterator_t it)
{
    if (!it)
        return NULL;

    return it->next;
}

list_iterator_t list_prev(list_iterator_t it)
{
    if (!it)
        return NULL;

    return it->prev;
}

void* list_get(const list_iterator_t it)
{
    if (!it)
        return NULL;

    return it->data;
}

void* list_at(const list_t* list, int index)
{
    if ((index >= 0) && (index < list->size))
    {
        node_t* iterator = list->head;
        for (register int i = 0; i != index; i++)
            iterator = iterator->next;
        return iterator->data;
    }
    else if ((index < 0) && (abs(index) <= list->size))
    {
        node_t* iterator = list->tail;
        for (register int i = -1; i != index; i--)
            iterator = iterator->prev;
        return iterator->data;
    }

    return NULL;
}

void* list_back(const list_t* list)
{
    return list->tail->data;
}

void* list_front(const list_t* list)
{
    return list->head->data;
}

static void _make_empty_list(list_t* list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

static void _insert_between_nodes(list_iterator_t lnode, list_iterator_t rnode, void* data)
{
    node_t* new_node = winc_malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = rnode;
    new_node->prev = lnode;
    lnode->next = new_node;
    rnode->prev = new_node;
}

static void _insert_first_node(list_t* list, void* data)
{
    node_t* new_node = winc_malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    list->head = new_node;
    list->tail = new_node;
}
