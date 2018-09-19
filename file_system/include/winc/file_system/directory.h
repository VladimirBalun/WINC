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

#ifndef WINC_FILE_SYSTEM_DIRECTORY_H
#define WINC_FILE_SYSTEM_DIRECTORY_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "path.h"
#include "winc/utils/typedef.h"

bool create_dir(const char* dir_name);
bool remove_dir(const char* dir_name);
bool is_exist_dir(const char* dir_name);
bool rename_dir(const char* old_dir_name, const char* new_dir_name);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // WINC_FILE_SYSTEM_DIRECTORY_H
