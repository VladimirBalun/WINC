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

#ifndef WINC_FILE_SYSTEM_FILE_H
#define WINC_FILE_SYSTEM_FILE_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "winc/utils/allocation.h"
#include "winc/utils/typedef.h"

bool create_file(const char* file_name);
bool remove_file(const char* file_name);
bool copy_file(const char* from_file_name, const char* to_file_name);
bool move_file(const char* file_name, const char* new_file_name);
bool rename_file(const char* old_file_name, const char* new_file_name);

bool create_sym_link(const char *file_name, const char *link_name);
bool create_hard_link(const char *file_name, const char *link_name);

char* read_file(const char* file_name);
void rewrite_file(const char* file_name, const char* data);
void append_to_file(const char* file_name, const char* data);

bool is_exist_file(const char* file_name);
long int get_file_size(const char* file_name);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // WINC_FILE_SYSTEM_FILE_H
